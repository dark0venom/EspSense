#define DT_V1 257
#define DT_PLUGIN 258
#define DT_MEMRESERVE 259
#define DT_LSHIFT 260
#define DT_RSHIFT 261
#define DT_LE 262
#define DT_GE 263
#define DT_EQ 264
#define DT_NE 265
#define DT_AND 266
#define DT_OR 267
#define DT_BITS 268
#define DT_DEL_PROP 269
#define DT_DEL_NODE 270
#define DT_PROPNODENAME 271
#define DT_LITERAL 272
#define DT_CHAR_LITERAL 273
#define DT_BYTE 274
#define DT_STRING 275
#define DT_LABEL 276
#define DT_REF 277
#define DT_INCBIN 278
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char *propnodename;
	char *labelref;
	uint8_t byte;
	struct data data;

	struct {
		struct data	data;
		int		bits;
	} array;

	struct property *prop;
	struct property *proplist;
	struct node *node;
	struct node *nodelist;
	struct reserve_info *re;
	uint64_t integer;
	unsigned int flags;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
