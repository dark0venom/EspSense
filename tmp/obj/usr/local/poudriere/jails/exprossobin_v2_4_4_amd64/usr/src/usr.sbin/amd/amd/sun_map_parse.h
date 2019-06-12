#define NEWLINE 257
#define COMMENT 258
#define WSPACE 259
#define WORD 260
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  char strval[2048];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE sun_map_lval;
