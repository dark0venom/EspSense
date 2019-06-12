/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170430

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 21 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
#include <stdio.h>
#include <inttypes.h>

#include "dtc.h"
#include "srcpos.h"

YYLTYPE yylloc;

extern int yylex(void);
extern void yyerror(char const *s);
#define ERROR(loc, ...) \
	do { \
		srcpos_error((loc), "Error", __VA_ARGS__); \
		treesource_error = true; \
	} while (0)

extern struct dt_info *parser_output;
extern bool treesource_error;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 41 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
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
#line 67 "dtc-parser.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    3,    3,    4,    4,    6,    6,    5,    5,   11,
   11,   11,   11,   11,   12,   10,   10,    9,    9,    9,
    9,    1,    1,    1,    1,    1,    1,    1,    2,    2,
    2,    7,    7,    7,    7,    7,   15,   15,   15,   28,
   27,   27,   26,   26,   25,   25,   24,   24,   23,   23,
   22,   22,   21,   21,   21,   20,   20,   20,   20,   20,
   19,   19,   19,   18,   18,   18,   17,   17,   17,   17,
   16,   16,   16,   16,    8,    8,    8,   14,   14,   14,
   13,   13,   13,
};
static const YYINT yylen[] = {                            2,
    3,    2,    4,    1,    2,    0,    2,    4,    2,    2,
    3,    4,    3,    4,    5,    0,    2,    4,    2,    3,
    2,    2,    3,    4,    2,    9,    5,    2,    0,    2,
    2,    3,    1,    2,    2,    2,    1,    1,    3,    1,
    1,    5,    1,    3,    1,    3,    1,    3,    1,    3,
    1,    3,    1,    3,    3,    1,    3,    3,    3,    3,
    3,    3,    1,    3,    3,    1,    3,    3,    3,    1,
    1,    2,    2,    2,    0,    2,    2,    0,    2,    2,
    2,    3,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    5,    0,    0,    0,    0,
    0,   37,   38,    0,    0,    9,    7,    0,    0,    3,
    0,    0,    0,   71,   70,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   40,    0,    0,   16,   10,
    0,    0,    0,    0,   72,   73,   74,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   39,    8,    0,    0,
    0,   13,   11,   68,   67,   69,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   17,    0,    0,   14,
   12,    0,    0,    0,   19,   29,   81,   21,   83,   80,
   79,    0,   42,   20,   82,    0,    0,   15,   28,   18,
   30,    0,   22,   31,   25,    0,   75,   33,    0,    0,
    0,    0,   36,   35,   23,   34,   32,    0,   76,   77,
   24,    0,   27,    0,    0,    0,   26,
};
static const YYINT yydgoto[] = {                          2,
  116,  117,    3,    4,    9,   10,  129,  132,   97,   69,
   19,   40,   98,   99,   24,   25,   26,   27,   28,   29,
   30,   31,   32,   33,   34,   35,   36,   37,
};
static const YYINT yysindex[] = {                      -225,
  -19,    0, -225, -248, -215,    0,  -37, -248, -248,    9,
    4,    0,    0,  -33,  -37,    0,    0,  -64,  -45,    0,
  -33,  -33,  -33,    0,    0,  -21,  -30, -241,  -56, -180,
   23,  -28,  -53, -175,  -58,    0,   58,   52,    0,    0,
 -163, -159,  -64,  -64,    0,    0,    0,  -33,  -33,  -33,
  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
  -33,  -33,  -33,  -33,  -33,  -33,    0,    0,  -59,   65,
  -64,    0,    0,    0,    0,    0,  -21,  -21,  -30,  -30,
 -241, -241, -241, -241,  -56,  -56, -180,   23,  -28,  -53,
 -175,   77, -132, -122,   15,  -59,    0,  -59,   31,    0,
    0,  -33,  101,  108,    0,    0,    0,    0,    0,    0,
    0,  109,    0,    0,    0,  -35,   50,    0,    0,    0,
    0, -103,    0,    0,    0,  131,    0,    0,  -39,  113,
  -99,  -85,    0,    0,    0,    0,    0,   -3,    0,    0,
    0,  -37,    0,  128,  -37,  138,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    2,  133,   56,    0,    0,    0,  133,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  182,    0,
    0,    0,    0,    0,    0,  -16,    7,   57,   71,  347,
  319,  142,  -24,   -5,  -27,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   59,    0,
    0,    0,    0,    0,    0,    0,   -8,   19,   34,   42,
   84,   92,   99,  136,  329,  333,  356,  354,  163,   10,
  112,    0,    0,    0,    0,    0,    0,   59,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,  184,  177,  179,    0,    0,   25,    0,
    0,  221,   94,  103,    3,  410,   55,   73,   32,  104,
  141,  130,  134,  139,  148,    0,  116,  149,
};
#define YYTABLESIZE 623
static const YYINT yytable[] = {                         23,
   14,   44,   14,   58,   66,   57,   14,  141,  121,   15,
    7,   21,   51,   41,   52,   50,   45,   38,   53,   54,
   49,   66,  135,  120,   66,   48,   66,    8,   66,   64,
   41,    1,   64,   45,   64,   43,   64,  143,   45,    5,
  142,   66,   11,   66,   63,   66,   66,   63,    4,   64,
   46,   64,   43,   64,   64,   18,   65,   43,   39,   65,
   61,   65,   20,   65,   63,   62,   63,   46,   63,   63,
   63,   61,   46,  105,   61,  106,   65,   66,   65,   62,
   65,   65,   62,   59,   60,   64,   81,   82,   83,   84,
   64,   61,   22,   61,   56,   61,   61,   56,   67,   62,
   63,   62,    2,   62,   62,   77,   78,   66,   53,  128,
   68,   53,   65,   70,   56,   64,   56,   71,   56,   56,
  108,   59,  110,  100,   59,   79,   80,   61,   53,   60,
   63,  136,   60,   53,  102,   62,   58,   39,  103,   58,
  127,   59,   65,   59,  144,   59,   59,  146,  104,   60,
   56,   60,   44,   60,   60,  112,   58,   61,   58,  114,
   58,   58,   85,   86,   53,   62,  115,  118,  130,   44,
  131,  145,  137,   57,   44,  138,   57,   59,  147,    6,
   56,    1,   47,   78,   16,   60,    6,   17,  139,  109,
  140,   88,   58,   57,   53,   57,   89,   57,   57,   47,
  111,   87,   90,   48,   47,   55,   56,   59,   65,   93,
   94,   95,   91,    0,   92,   60,   96,  113,    0,    0,
   48,    0,   58,    0,   41,   48,    0,    0,    0,   57,
   42,   43,   12,   13,   12,   13,  133,  134,   12,   13,
  119,   45,   45,   66,   66,   66,   66,   66,   66,   66,
   66,   64,   64,   64,   64,   64,   64,   64,   64,   57,
    4,   43,    0,   72,   73,   47,   63,   63,   63,   63,
   63,   63,   63,   63,    0,   46,   46,    4,   65,   65,
   65,   65,   65,   65,   65,   65,   48,    0,    0,    0,
    0,  101,    0,   61,   61,   61,   61,   61,   61,   61,
   61,   62,   62,   62,   62,   62,   62,   62,   62,    0,
    0,    0,    2,    0,    2,  107,    0,  122,   56,   56,
   56,   56,   56,   56,  123,  124,  125,  126,    0,    0,
    0,    2,    0,    0,   53,   53,   53,   53,    0,    0,
    0,    0,    0,    0,    0,   59,   59,   59,   59,   59,
   59,    0,    0,   60,   60,   60,   60,   60,   60,   49,
   58,   58,   58,   58,   58,   58,   54,    0,    0,   54,
   55,    0,    0,   55,    0,    0,   49,    0,   44,    0,
    0,   49,    0,    0,   51,    0,   54,   51,    0,    0,
   55,   54,    0,   52,   50,   55,   52,   57,   57,   57,
   57,   57,   57,    0,   51,    0,    0,   47,   47,   51,
    0,   50,   49,   52,    0,    0,   50,    0,   52,    0,
    0,    0,   54,    0,    0,    0,   55,    0,   48,   48,
   45,   46,   47,    0,    0,    0,    0,    0,    0,    0,
   51,    0,   49,    0,    0,    0,    0,   50,    0,   52,
    0,    0,   54,    0,    0,    0,   55,   74,   75,   76,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   51,    0,    0,    0,    0,    0,    0,   50,    0,   52,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   49,   49,    0,    0,    0,    0,
    0,    0,   54,   54,   54,   54,   55,   55,   55,   55,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   51,   51,    0,    0,    0,    0,    0,   50,
   50,   52,   52,
};
static const YYINT yycheck[] = {                         33,
   40,   47,   40,   60,   63,   62,   40,   93,   44,    7,
  259,   45,   43,   41,   45,   37,   41,   15,  260,  261,
   42,   38,   62,   59,   41,   47,   43,  276,   45,   38,
   58,  257,   41,   58,   43,   41,   45,   41,   63,   59,
   44,   58,  258,   60,   38,   62,   63,   41,   47,   58,
   41,   60,   58,   62,   63,   47,   38,   63,  123,   41,
   38,   43,   59,   45,   58,   94,   60,   58,   62,   63,
  124,   38,   63,   59,   41,   61,   58,   94,   60,   38,
   62,   63,   41,  264,  265,   94,   55,   56,   57,   58,
  266,   58,  126,   60,   38,   62,   63,   41,   41,   58,
   94,   60,   47,   62,   63,   51,   52,  124,   38,   60,
   59,   41,   94,  277,   58,  124,   60,  277,   62,   63,
   96,   38,   98,   59,   41,   53,   54,   94,   58,   38,
  124,  129,   41,   63,   58,   94,   38,  123,  271,   41,
   91,   58,  124,   60,  142,   62,   63,  145,  271,   58,
   94,   60,   41,   62,   63,  125,   58,  124,   60,   59,
   62,   63,   59,   60,   94,  124,   59,   59,  272,   58,
   40,   44,   60,   38,   63,  275,   41,   94,   41,   47,
  124,    0,   41,  125,    8,   94,    3,    9,  274,   96,
  276,   62,   94,   58,  124,   60,   63,   62,   63,   58,
   98,   61,   64,   41,   63,  262,  263,  124,  267,  269,
  270,  271,   65,   -1,   66,  124,  276,  102,   -1,   -1,
   58,   -1,  124,   -1,  270,   63,   -1,   -1,   -1,   94,
  276,  277,  272,  273,  272,  273,  276,  277,  272,  273,
  276,  266,  267,  260,  261,  262,  263,  264,  265,  266,
  267,  260,  261,  262,  263,  264,  265,  266,  267,  124,
  259,  267,   -1,   43,   44,  124,  260,  261,  262,  263,
  264,  265,  266,  267,   -1,  266,  267,  276,  260,  261,
  262,  263,  264,  265,  266,  267,  124,   -1,   -1,   -1,
   -1,   71,   -1,  260,  261,  262,  263,  264,  265,  266,
  267,  260,  261,  262,  263,  264,  265,  266,  267,   -1,
   -1,   -1,  257,   -1,  259,   95,   -1,  268,  262,  263,
  264,  265,  266,  267,  275,  276,  277,  278,   -1,   -1,
   -1,  276,   -1,   -1,  264,  265,  266,  267,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,  266,
  267,   -1,   -1,  262,  263,  264,  265,  266,  267,   41,
  262,  263,  264,  265,  266,  267,   38,   -1,   -1,   41,
   38,   -1,   -1,   41,   -1,   -1,   58,   -1,  267,   -1,
   -1,   63,   -1,   -1,   38,   -1,   58,   41,   -1,   -1,
   58,   63,   -1,   38,   41,   63,   41,  262,  263,  264,
  265,  266,  267,   -1,   58,   -1,   -1,  266,  267,   63,
   -1,   58,   94,   58,   -1,   -1,   63,   -1,   63,   -1,
   -1,   -1,   94,   -1,   -1,   -1,   94,   -1,  266,  267,
   21,   22,   23,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   94,   -1,  124,   -1,   -1,   -1,   -1,   94,   -1,   94,
   -1,   -1,  124,   -1,   -1,   -1,  124,   48,   49,   50,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  124,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,  124,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  266,  267,   -1,   -1,   -1,   -1,
   -1,   -1,  264,  265,  266,  267,  264,  265,  266,  267,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  266,  267,   -1,   -1,   -1,   -1,   -1,  266,
  267,  266,  267,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 278
#define YYUNDFTOKEN 309
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,
0,0,0,0,0,"':'","';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"DT_V1","DT_PLUGIN",
"DT_MEMRESERVE","DT_LSHIFT","DT_RSHIFT","DT_LE","DT_GE","DT_EQ","DT_NE",
"DT_AND","DT_OR","DT_BITS","DT_DEL_PROP","DT_DEL_NODE","DT_PROPNODENAME",
"DT_LITERAL","DT_CHAR_LITERAL","DT_BYTE","DT_STRING","DT_LABEL","DT_REF",
"DT_INCBIN",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : sourcefile",
"sourcefile : headers memreserves devicetree",
"header : DT_V1 ';'",
"header : DT_V1 ';' DT_PLUGIN ';'",
"headers : header",
"headers : header headers",
"memreserves :",
"memreserves : memreserve memreserves",
"memreserve : DT_MEMRESERVE integer_prim integer_prim ';'",
"memreserve : DT_LABEL memreserve",
"devicetree : '/' nodedef",
"devicetree : devicetree '/' nodedef",
"devicetree : devicetree DT_LABEL DT_REF nodedef",
"devicetree : devicetree DT_REF nodedef",
"devicetree : devicetree DT_DEL_NODE DT_REF ';'",
"nodedef : '{' proplist subnodes '}' ';'",
"proplist :",
"proplist : proplist propdef",
"propdef : DT_PROPNODENAME '=' propdata ';'",
"propdef : DT_PROPNODENAME ';'",
"propdef : DT_DEL_PROP DT_PROPNODENAME ';'",
"propdef : DT_LABEL propdef",
"propdata : propdataprefix DT_STRING",
"propdata : propdataprefix arrayprefix '>'",
"propdata : propdataprefix '[' bytestring ']'",
"propdata : propdataprefix DT_REF",
"propdata : propdataprefix DT_INCBIN '(' DT_STRING ',' integer_prim ',' integer_prim ')'",
"propdata : propdataprefix DT_INCBIN '(' DT_STRING ')'",
"propdata : propdata DT_LABEL",
"propdataprefix :",
"propdataprefix : propdata ','",
"propdataprefix : propdataprefix DT_LABEL",
"arrayprefix : DT_BITS DT_LITERAL '<'",
"arrayprefix : '<'",
"arrayprefix : arrayprefix integer_prim",
"arrayprefix : arrayprefix DT_REF",
"arrayprefix : arrayprefix DT_LABEL",
"integer_prim : DT_LITERAL",
"integer_prim : DT_CHAR_LITERAL",
"integer_prim : '(' integer_expr ')'",
"integer_expr : integer_trinary",
"integer_trinary : integer_or",
"integer_trinary : integer_or '?' integer_expr ':' integer_trinary",
"integer_or : integer_and",
"integer_or : integer_or DT_OR integer_and",
"integer_and : integer_bitor",
"integer_and : integer_and DT_AND integer_bitor",
"integer_bitor : integer_bitxor",
"integer_bitor : integer_bitor '|' integer_bitxor",
"integer_bitxor : integer_bitand",
"integer_bitxor : integer_bitxor '^' integer_bitand",
"integer_bitand : integer_eq",
"integer_bitand : integer_bitand '&' integer_eq",
"integer_eq : integer_rela",
"integer_eq : integer_eq DT_EQ integer_rela",
"integer_eq : integer_eq DT_NE integer_rela",
"integer_rela : integer_shift",
"integer_rela : integer_rela '<' integer_shift",
"integer_rela : integer_rela '>' integer_shift",
"integer_rela : integer_rela DT_LE integer_shift",
"integer_rela : integer_rela DT_GE integer_shift",
"integer_shift : integer_shift DT_LSHIFT integer_add",
"integer_shift : integer_shift DT_RSHIFT integer_add",
"integer_shift : integer_add",
"integer_add : integer_add '+' integer_mul",
"integer_add : integer_add '-' integer_mul",
"integer_add : integer_mul",
"integer_mul : integer_mul '*' integer_unary",
"integer_mul : integer_mul '/' integer_unary",
"integer_mul : integer_mul '%' integer_unary",
"integer_mul : integer_unary",
"integer_unary : integer_prim",
"integer_unary : '-' integer_unary",
"integer_unary : '~' integer_unary",
"integer_unary : '!' integer_unary",
"bytestring :",
"bytestring : bytestring DT_BYTE",
"bytestring : bytestring DT_LABEL",
"subnodes :",
"subnodes : subnode subnodes",
"subnodes : subnode propdef",
"subnode : DT_PROPNODENAME nodedef",
"subnode : DT_DEL_NODE DT_PROPNODENAME ';'",
"subnode : DT_LABEL subnode",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 517 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"

void yyerror(char const *s)
{
	ERROR(&yylloc, "%s", s);
}
#line 490 "dtc-parser.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 112 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			parser_output = build_dt_info(yystack.l_mark[-2].flags, yystack.l_mark[-1].re, yystack.l_mark[0].node,
			                              guess_boot_cpuid(yystack.l_mark[0].node));
		}
break;
case 2:
#line 120 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.flags = DTSF_V1;
		}
break;
case 3:
#line 124 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.flags = DTSF_V1 | DTSF_PLUGIN;
		}
break;
case 5:
#line 132 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			if (yystack.l_mark[0].flags != yystack.l_mark[-1].flags)
				ERROR(&yylloc, "Header flags don't match earlier ones");
			yyval.flags = yystack.l_mark[-1].flags;
		}
break;
case 6:
#line 141 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.re = NULL;
		}
break;
case 7:
#line 145 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.re = chain_reserve_entry(yystack.l_mark[-1].re, yystack.l_mark[0].re);
		}
break;
case 8:
#line 152 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.re = build_reserve_entry(yystack.l_mark[-2].integer, yystack.l_mark[-1].integer);
		}
break;
case 9:
#line 156 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			add_label(&yystack.l_mark[0].re->labels, yystack.l_mark[-1].labelref);
			yyval.re = yystack.l_mark[0].re;
		}
break;
case 10:
#line 164 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.node = name_node(yystack.l_mark[0].node, "");
		}
break;
case 11:
#line 168 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.node = merge_nodes(yystack.l_mark[-2].node, yystack.l_mark[0].node);
		}
break;
case 12:
#line 173 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			struct node *target = get_node_by_ref(yystack.l_mark[-3].node, yystack.l_mark[-1].labelref);

			if (target) {
				add_label(&target->labels, yystack.l_mark[-2].labelref);
				merge_nodes(target, yystack.l_mark[0].node);
			} else
				ERROR(&yylloc, "Label or path %s not found", yystack.l_mark[-1].labelref);
			yyval.node = yystack.l_mark[-3].node;
		}
break;
case 13:
#line 184 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			struct node *target = get_node_by_ref(yystack.l_mark[-2].node, yystack.l_mark[-1].labelref);

			if (target)
				merge_nodes(target, yystack.l_mark[0].node);
			else
				ERROR(&yylloc, "Label or path %s not found", yystack.l_mark[-1].labelref);
			yyval.node = yystack.l_mark[-2].node;
		}
break;
case 14:
#line 194 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			struct node *target = get_node_by_ref(yystack.l_mark[-3].node, yystack.l_mark[-1].labelref);

			if (target)
				delete_node(target);
			else
				ERROR(&yylloc, "Label or path %s not found", yystack.l_mark[-1].labelref);


			yyval.node = yystack.l_mark[-3].node;
		}
break;
case 15:
#line 209 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.node = build_node(yystack.l_mark[-3].proplist, yystack.l_mark[-2].nodelist);
		}
break;
case 16:
#line 216 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.proplist = NULL;
		}
break;
case 17:
#line 220 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.proplist = chain_property(yystack.l_mark[0].prop, yystack.l_mark[-1].proplist);
		}
break;
case 18:
#line 227 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.prop = build_property(yystack.l_mark[-3].propnodename, yystack.l_mark[-1].data);
		}
break;
case 19:
#line 231 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.prop = build_property(yystack.l_mark[-1].propnodename, empty_data);
		}
break;
case 20:
#line 235 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.prop = build_property_delete(yystack.l_mark[-1].propnodename);
		}
break;
case 21:
#line 239 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			add_label(&yystack.l_mark[0].prop->labels, yystack.l_mark[-1].labelref);
			yyval.prop = yystack.l_mark[0].prop;
		}
break;
case 22:
#line 247 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_merge(yystack.l_mark[-1].data, yystack.l_mark[0].data);
		}
break;
case 23:
#line 251 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_merge(yystack.l_mark[-2].data, yystack.l_mark[-1].array.data);
		}
break;
case 24:
#line 255 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_merge(yystack.l_mark[-3].data, yystack.l_mark[-1].data);
		}
break;
case 25:
#line 259 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_add_marker(yystack.l_mark[-1].data, REF_PATH, yystack.l_mark[0].labelref);
		}
break;
case 26:
#line 263 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			FILE *f = srcfile_relative_open(yystack.l_mark[-5].data.val, NULL);
			struct data d;

			if (yystack.l_mark[-3].integer != 0)
				if (fseek(f, yystack.l_mark[-3].integer, SEEK_SET) != 0)
					die("Couldn't seek to offset %llu in \"%s\": %s",
					    (unsigned long long)yystack.l_mark[-3].integer, yystack.l_mark[-5].data.val,
					    strerror(errno));

			d = data_copy_file(f, yystack.l_mark[-1].integer);

			yyval.data = data_merge(yystack.l_mark[-8].data, d);
			fclose(f);
		}
break;
case 27:
#line 279 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			FILE *f = srcfile_relative_open(yystack.l_mark[-1].data.val, NULL);
			struct data d = empty_data;

			d = data_copy_file(f, -1);

			yyval.data = data_merge(yystack.l_mark[-4].data, d);
			fclose(f);
		}
break;
case 28:
#line 289 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_add_marker(yystack.l_mark[-1].data, LABEL, yystack.l_mark[0].labelref);
		}
break;
case 29:
#line 296 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = empty_data;
		}
break;
case 30:
#line 300 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = yystack.l_mark[-1].data;
		}
break;
case 31:
#line 304 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_add_marker(yystack.l_mark[-1].data, LABEL, yystack.l_mark[0].labelref);
		}
break;
case 32:
#line 311 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			unsigned long long bits;

			bits = yystack.l_mark[-1].integer;

			if ((bits !=  8) && (bits != 16) &&
			    (bits != 32) && (bits != 64)) {
				ERROR(&yylloc, "Array elements must be"
				      " 8, 16, 32 or 64-bits");
				bits = 32;
			}

			yyval.array.data = empty_data;
			yyval.array.bits = bits;
		}
break;
case 33:
#line 327 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.array.data = empty_data;
			yyval.array.bits = 32;
		}
break;
case 34:
#line 332 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			if (yystack.l_mark[-1].array.bits < 64) {
				uint64_t mask = (1ULL << yystack.l_mark[-1].array.bits) - 1;
				/*
				 * Bits above mask must either be all zero
				 * (positive within range of mask) or all one
				 * (negative and sign-extended). The second
				 * condition is true if when we set all bits
				 * within the mask to one (i.e. | in the
				 * mask), all bits are one.
				 */
				if ((yystack.l_mark[0].integer > mask) && ((yystack.l_mark[0].integer | mask) != -1ULL))
					ERROR(&yylloc, "Value out of range for"
					      " %d-bit array element", yystack.l_mark[-1].array.bits);
			}

			yyval.array.data = data_append_integer(yystack.l_mark[-1].array.data, yystack.l_mark[0].integer, yystack.l_mark[-1].array.bits);
		}
break;
case 35:
#line 351 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			uint64_t val = ~0ULL >> (64 - yystack.l_mark[-1].array.bits);

			if (yystack.l_mark[-1].array.bits == 32)
				yystack.l_mark[-1].array.data = data_add_marker(yystack.l_mark[-1].array.data,
							  REF_PHANDLE,
							  yystack.l_mark[0].labelref);
			else
				ERROR(&yylloc, "References are only allowed in "
					    "arrays with 32-bit elements.");

			yyval.array.data = data_append_integer(yystack.l_mark[-1].array.data, val, yystack.l_mark[-1].array.bits);
		}
break;
case 36:
#line 365 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.array.data = data_add_marker(yystack.l_mark[-1].array.data, LABEL, yystack.l_mark[0].labelref);
		}
break;
case 39:
#line 374 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.integer = yystack.l_mark[-1].integer;
		}
break;
case 42:
#line 385 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-4].integer ? yystack.l_mark[-2].integer : yystack.l_mark[0].integer; }
break;
case 44:
#line 390 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer || yystack.l_mark[0].integer; }
break;
case 46:
#line 395 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer && yystack.l_mark[0].integer; }
break;
case 48:
#line 400 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer | yystack.l_mark[0].integer; }
break;
case 50:
#line 405 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer ^ yystack.l_mark[0].integer; }
break;
case 52:
#line 410 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer & yystack.l_mark[0].integer; }
break;
case 54:
#line 415 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer == yystack.l_mark[0].integer; }
break;
case 55:
#line 416 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer != yystack.l_mark[0].integer; }
break;
case 57:
#line 421 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer < yystack.l_mark[0].integer; }
break;
case 58:
#line 422 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer > yystack.l_mark[0].integer; }
break;
case 59:
#line 423 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer <= yystack.l_mark[0].integer; }
break;
case 60:
#line 424 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer >= yystack.l_mark[0].integer; }
break;
case 61:
#line 428 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer << yystack.l_mark[0].integer; }
break;
case 62:
#line 429 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer >> yystack.l_mark[0].integer; }
break;
case 64:
#line 434 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer + yystack.l_mark[0].integer; }
break;
case 65:
#line 435 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer - yystack.l_mark[0].integer; }
break;
case 67:
#line 440 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer * yystack.l_mark[0].integer; }
break;
case 68:
#line 442 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			if (yystack.l_mark[0].integer != 0) {
				yyval.integer = yystack.l_mark[-2].integer / yystack.l_mark[0].integer;
			} else {
				ERROR(&yylloc, "Division by zero");
				yyval.integer = 0;
			}
		}
break;
case 69:
#line 451 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			if (yystack.l_mark[0].integer != 0) {
				yyval.integer = yystack.l_mark[-2].integer % yystack.l_mark[0].integer;
			} else {
				ERROR(&yylloc, "Division by zero");
				yyval.integer = 0;
			}
		}
break;
case 72:
#line 464 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = -yystack.l_mark[0].integer; }
break;
case 73:
#line 465 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = ~yystack.l_mark[0].integer; }
break;
case 74:
#line 466 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = !yystack.l_mark[0].integer; }
break;
case 75:
#line 471 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = empty_data;
		}
break;
case 76:
#line 475 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_append_byte(yystack.l_mark[-1].data, yystack.l_mark[0].byte);
		}
break;
case 77:
#line 479 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_add_marker(yystack.l_mark[-1].data, LABEL, yystack.l_mark[0].labelref);
		}
break;
case 78:
#line 486 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.nodelist = NULL;
		}
break;
case 79:
#line 490 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.nodelist = chain_node(yystack.l_mark[-1].node, yystack.l_mark[0].nodelist);
		}
break;
case 80:
#line 494 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			ERROR(&yylloc, "Properties must precede subnodes");
			YYERROR;
		}
break;
case 81:
#line 502 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.node = name_node(yystack.l_mark[0].node, yystack.l_mark[-1].propnodename);
		}
break;
case 82:
#line 506 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.node = name_node(build_node_delete(), yystack.l_mark[-1].propnodename);
		}
break;
case 83:
#line 510 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			add_label(&yystack.l_mark[0].node->labels, yystack.l_mark[-1].labelref);
			yyval.node = yystack.l_mark[0].node;
		}
break;
#line 1145 "dtc-parser.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
