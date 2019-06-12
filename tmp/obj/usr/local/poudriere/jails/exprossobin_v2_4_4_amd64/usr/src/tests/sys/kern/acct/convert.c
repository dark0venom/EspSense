/* FLOAT_CONVERSION_START (Regression testing; don't remove this line.) */

/* Convert timevals and longs into IEEE-754 bit patterns. */

/* Mantissa mask (MSB is implied, so subtract 1). */
#define MANT_MASK ((1 << (FLT_MANT_DIG - 1)) - 1)

/*
 * We calculate integer values to a precision of approximately
 * 28 bits.
 * This is high-enough precision to fill the 24 float bits
 * and low-enough to avoid overflowing the 32 int bits.
 */
#define CALC_BITS 28

/* log_2(1000000). */
#define LOG2_1M 20

/*
 * Convert the elements of a timeval into a 32-bit word holding
 * the bits of a IEEE-754 float.
 * The float value represents the timeval's value in microsecond units.
 */
static uint32_t
encode_timeval(struct timeval tv)
{
	int log2_s;
	int val, exponent;	/* Unnormalized value and exponentonent */
	int norm_exponent;	/* Normalized exponentonent */
	int shift;

	/*
	 * First calculate value and exponentonent to about CALC_BITS precision.
	 * Note that the following conditionals have been ordered so that
	 * the most common cases appear first.
	 */
	if (tv.tv_sec == 0) {
		if (tv.tv_usec == 0)
			return (0);
		exponent = 0;
		val = tv.tv_usec;
	} else {
		/*
		 * Calculate the value to a precision of approximately
		 * CALC_BITS.
		 */
		log2_s = fls(tv.tv_sec) - 1;
		if (log2_s + LOG2_1M < CALC_BITS) {
			exponent = 0;
			val = 1000000 * tv.tv_sec + tv.tv_usec;
		} else {
			exponent = log2_s + LOG2_1M - CALC_BITS;
			val = (unsigned int)(((uint64_t)1000000 * tv.tv_sec +
			    tv.tv_usec) >> exponent);
		}
	}
	/* Now normalize and pack the value into an IEEE-754 float. */
	norm_exponent = fls(val) - 1;
	shift = FLT_MANT_DIG - norm_exponent - 1;
#ifdef ACCT_DEBUG
	printf("val=%d exponent=%d shift=%d log2(val)=%d\n",
	    val, exponent, shift, norm_exponent);
	printf("exponent=%x mant=%x\n", FLT_MAX_EXP - 1 + exponent + norm_exponent,
	    ((shift > 0 ? (val << shift) : (val >> -shift)) & MANT_MASK));
#endif
	return (((FLT_MAX_EXP - 1 + exponent + norm_exponent) << (FLT_MANT_DIG - 1)) |
	    ((shift > 0 ? val << shift : val >> -shift) & MANT_MASK));
}

/*
 * Convert a non-negative long value into the bit pattern of
 * an IEEE-754 float value.
 */
static uint32_t
encode_long(long val)
{
	int norm_exponent;	/* Normalized exponentonent */
	int shift;

	if (val == 0)
		return (0);
	if (val < 0) {
		syslog(LOG_NOTICE,
		    "encode_long: negative value %ld in accounting record\n",
		    val);
		val = LONG_MAX;
	}
	norm_exponent = fls(val) - 1;
	shift = FLT_MANT_DIG - norm_exponent - 1;
#ifdef ACCT_DEBUG
	printf("val=%d shift=%d log2(val)=%d\n",
	    val, shift, norm_exponent);
	printf("exponent=%x mant=%x\n", FLT_MAX_EXP - 1 + exponent + norm_exponent,
	    ((shift > 0 ? (val << shift) : (val >> -shift)) & MANT_MASK));
#endif
	return (((FLT_MAX_EXP - 1 + norm_exponent) << (FLT_MANT_DIG - 1)) |
	    ((shift > 0 ? val << shift : val >> -shift) & MANT_MASK));
}

/* FLOAT_CONVERSION_END (Regression testing; don't remove this line.) */
