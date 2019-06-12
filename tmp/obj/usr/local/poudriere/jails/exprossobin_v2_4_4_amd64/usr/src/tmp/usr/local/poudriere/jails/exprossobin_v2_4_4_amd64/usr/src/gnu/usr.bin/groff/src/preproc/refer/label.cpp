/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170201

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 23 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"

#include "refer.h"
#include "refid.h"
#include "ref.h"
#include "token.h"

int yylex();
void yyerror(const char *);
int yyparse();

static const char *format_serial(char c, int n);

struct label_info {
  int start;
  int length;
  int count;
  int total;
  label_info(const string &);
};

label_info *lookup_label(const string &label);

struct expression {
  enum {
    /* Does the tentative label depend on the reference?*/
    CONTAINS_VARIABLE = 01, 
    CONTAINS_STAR = 02,
    CONTAINS_FORMAT = 04,
    CONTAINS_AT = 010
  };
  virtual ~expression() { }
  virtual void evaluate(int, const reference &, string &,
			substring_position &) = 0;
  virtual unsigned analyze() { return 0; }
};

class at_expr : public expression {
public:
  at_expr() { }
  void evaluate(int, const reference &, string &, substring_position &);
  unsigned analyze() { return CONTAINS_VARIABLE|CONTAINS_AT; }
};

class format_expr : public expression {
  char type;
  int width;
  int first_number;
public:
  format_expr(char c, int w = 0, int f = 1)
    : type(c), width(w), first_number(f) { }
  void evaluate(int, const reference &, string &, substring_position &);
  unsigned analyze() { return CONTAINS_FORMAT; }
};

class field_expr : public expression {
  int number;
  char name;
public:
  field_expr(char nm, int num) : number(num), name(nm) { }
  void evaluate(int, const reference &, string &, substring_position &);
  unsigned analyze() { return CONTAINS_VARIABLE; }
};

class literal_expr : public expression {
  string s;
public:
  literal_expr(const char *ptr, int len) : s(ptr, len) { }
  void evaluate(int, const reference &, string &, substring_position &);
};

class unary_expr : public expression {
protected:
  expression *expr;
public:
  unary_expr(expression *e) : expr(e) { }
  ~unary_expr() { delete expr; }
  void evaluate(int, const reference &, string &, substring_position &) = 0;
  unsigned analyze() { return expr ? expr->analyze() : 0; }
};

/* This caches the analysis of an expression.*/

class analyzed_expr : public unary_expr {
  unsigned flags;
public:
  analyzed_expr(expression *);
  void evaluate(int, const reference &, string &, substring_position &);
  unsigned analyze() { return flags; }
};

class star_expr : public unary_expr {
public:
  star_expr(expression *e) : unary_expr(e) { }
  void evaluate(int, const reference &, string &, substring_position &);
  unsigned analyze() {
    return ((expr ? (expr->analyze() & ~CONTAINS_VARIABLE) : 0)
	    | CONTAINS_STAR);
  }
};

typedef void map_func(const char *, const char *, string &);

class map_expr : public unary_expr {
  map_func *func;
public:
  map_expr(expression *e, map_func *f) : unary_expr(e), func(f) { }
  void evaluate(int, const reference &, string &, substring_position &);
};
  
typedef const char *extractor_func(const char *, const char *, const char **);

class extractor_expr : public unary_expr {
  int part;
  extractor_func *func;
public:
  enum { BEFORE = +1, MATCH = 0, AFTER = -1 };
  extractor_expr(expression *e, extractor_func *f, int pt)
    : unary_expr(e), part(pt), func(f) { }
  void evaluate(int, const reference &, string &, substring_position &);
};

class truncate_expr : public unary_expr {
  int n;
public:
  truncate_expr(expression *e, int i) : unary_expr(e), n(i) { } 
  void evaluate(int, const reference &, string &, substring_position &);
};

class separator_expr : public unary_expr {
public:
  separator_expr(expression *e) : unary_expr(e) { }
  void evaluate(int, const reference &, string &, substring_position &);
};

class binary_expr : public expression {
protected:
  expression *expr1;
  expression *expr2;
public:
  binary_expr(expression *e1, expression *e2) : expr1(e1), expr2(e2) { }
  ~binary_expr() { delete expr1; delete expr2; }
  void evaluate(int, const reference &, string &, substring_position &) = 0;
  unsigned analyze() {
    return (expr1 ? expr1->analyze() : 0) | (expr2 ? expr2->analyze() : 0);
  }
};

class alternative_expr : public binary_expr {
public:
  alternative_expr(expression *e1, expression *e2) : binary_expr(e1, e2) { }
  void evaluate(int, const reference &, string &, substring_position &);
};

class list_expr : public binary_expr {
public:
  list_expr(expression *e1, expression *e2) : binary_expr(e1, e2) { }
  void evaluate(int, const reference &, string &, substring_position &);
};

class substitute_expr : public binary_expr {
public:
  substitute_expr(expression *e1, expression *e2) : binary_expr(e1, e2) { }
  void evaluate(int, const reference &, string &, substring_position &);
};

class ternary_expr : public expression {
protected:
  expression *expr1;
  expression *expr2;
  expression *expr3;
public:
  ternary_expr(expression *e1, expression *e2, expression *e3)
    : expr1(e1), expr2(e2), expr3(e3) { }
  ~ternary_expr() { delete expr1; delete expr2; delete expr3; }
  void evaluate(int, const reference &, string &, substring_position &) = 0;
  unsigned analyze() {
    return ((expr1 ? expr1->analyze() : 0)
	    | (expr2 ? expr2->analyze() : 0)
	    | (expr3 ? expr3->analyze() : 0));
  }
};

class conditional_expr : public ternary_expr {
public:
  conditional_expr(expression *e1, expression *e2, expression *e3)
    : ternary_expr(e1, e2, e3) { }
  void evaluate(int, const reference &, string &, substring_position &);
};

static expression *parsed_label = 0;
static expression *parsed_date_label = 0;
static expression *parsed_short_label = 0;

static expression *parse_result;

string literals;

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 222 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
typedef union {
  int num;
  expression *expr;
  struct { int ndigits; int val; } dig;
  struct { int start; int len; } str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 233 "y.tab.c"

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

#define TOKEN_LETTER 257
#define TOKEN_LITERAL 258
#define TOKEN_DIGIT 259
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    6,    6,    2,    2,    2,    3,    3,
    5,    5,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    9,    9,    7,    7,    8,    8,
   10,   10,   10,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    0,    1,    1,    3,    3,    1,    2,
    1,    3,    1,    1,    1,    2,    2,    2,    5,    3,
    3,    2,    3,    3,    0,    1,    1,    2,    1,    2,
    0,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,   14,   13,    0,    0,    0,    0,    5,    0,    0,
    0,    0,    1,   27,    0,   17,   29,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   22,    0,   28,
   30,   23,   24,    0,    0,    0,   32,   33,    0,    0,
    0,    0,    0,    0,    3,    0,   19,
};
static const YYINT yydgoto[] = {                          7,
    8,    9,   10,   11,   12,   13,   15,   18,   47,   39,
};
static const YYINT yysindex[] = {                       -32,
 -257,    0,    0, -240,  -32,  -32,    0,    0,  -18,  -32,
  -36, -114,    0,    0, -246,    0,    0, -241,  -14,  -39,
  -32,  -32,  -32, -114,  -21, -257, -257,    0,  -32,    0,
    0,    0,    0,  -25,  -32,  -32,    0,    0, -223, -246,
 -246,  -36,  -32, -257,    0, -246,    0,
};
static const YYINT yyrindex[] = {                        35,
    1,    0,    0,    0,   -5,   -4,    0,    0,   14,  208,
  159,  224,    0,    0,   11,    0,    0,   40,    0,    0,
    2,    0,    0,  253, -220,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  263,  281,    0,    0,    0,   50,
  105,  214,    0,  115,    0,  149,    0,
};
static const YYINT yygindex[] = {                         0,
   19,    0,    7,   37,  -10,   10,  -23,    0,    0,    0,
};
#define YYTABLESIZE 511
static const YYINT yytable[] = {                         24,
   15,   14,   40,   41,    4,   28,   26,    5,   27,   25,
   16,   29,   30,    2,   19,   20,   16,   31,   17,   23,
   46,   37,   33,   38,   24,   24,   32,    6,   35,   36,
   34,    3,   43,   44,    4,    4,   31,   15,   15,   18,
   15,   15,   15,   15,   21,   15,   15,   16,   16,   20,
   16,   16,   16,   16,    2,   16,   16,    4,   15,    4,
   15,   45,   15,   15,   15,   42,    0,    0,   16,    0,
   16,    2,   16,   16,   16,    2,   18,   18,    0,   18,
   18,   18,   18,    0,   18,   18,   20,   20,    0,   20,
   20,   20,   20,    0,   20,   20,    0,   18,    0,   18,
    0,   18,   18,   18,   21,   22,    0,   20,    0,   20,
    0,   20,   20,   20,   25,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   15,    0,   15,    0,    0,    0,
    0,    0,    0,    0,   16,    0,   16,    0,    0,    0,
    0,   21,   21,    0,   21,   21,   21,   21,   26,   21,
   21,   25,   25,    0,   25,   25,   25,   25,   11,   25,
   25,    0,   21,   18,   21,   18,   21,   21,   21,    0,
    0,    0,   25,   20,   25,   20,   25,   25,   25,    0,
    0,    0,    0,    0,    0,   26,   26,    0,   26,   26,
   26,   26,    0,   26,   26,   11,   11,    0,   11,   11,
    0,    0,    0,    0,    0,    0,   26,    6,   26,    0,
   26,   26,   26,   12,    0,    0,   11,    0,   11,    0,
   11,   11,   11,    9,    1,    2,    0,    0,   21,    0,
   21,    0,    0,    0,    0,    0,    0,    0,   25,    0,
   25,    0,    0,    0,    0,    6,    0,    0,    6,    0,
   12,   12,   10,   12,   12,    0,    0,   15,   15,    0,
    9,    9,    7,    9,    9,    6,    0,   16,   16,    6,
    6,   12,   26,   12,   26,   12,   12,   12,    0,    0,
    8,    9,   11,    9,   11,    9,    9,    9,    0,   10,
   10,    0,   10,   10,    0,    0,   18,   18,    0,    0,
    7,    0,    0,    7,    0,    0,   20,   20,    0,    0,
   10,    0,   10,    0,   10,   10,   10,    0,    8,    0,
    7,    8,    0,    0,    7,    7,    0,    0,    0,    0,
    0,    6,    0,    0,    0,    0,    0,   12,    8,   12,
    0,    0,    8,    8,    0,    0,    0,    9,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   21,   21,    0,    0,    0,    0,    0,    0,    0,
    0,   25,   25,    0,    0,    0,   10,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    7,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    8,   26,   26,    0,    0,    0,
    0,    0,    0,    0,    0,   11,   11,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   12,   12,    0,    0,    0,    0,    0,    0,    0,    0,
    9,    9,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   10,
   10,
};
static const YYINT yycheck[] = {                         10,
    0,  259,   26,   27,   37,   42,   43,   40,   45,   46,
    0,  126,  259,    0,    5,    6,  257,  259,  259,   38,
   44,   43,   62,   45,   35,   36,   41,   60,   22,   23,
   21,   64,   58,  257,    0,   41,  257,   37,   38,    0,
   40,   41,   42,   43,   63,   45,   46,   37,   38,    0,
   40,   41,   42,   43,   41,   45,   46,   62,   58,   58,
   60,   43,   62,   63,   64,   29,   -1,   -1,   58,   -1,
   60,   58,   62,   63,   64,   62,   37,   38,   -1,   40,
   41,   42,   43,   -1,   45,   46,   37,   38,   -1,   40,
   41,   42,   43,   -1,   45,   46,   -1,   58,   -1,   60,
   -1,   62,   63,   64,    0,  124,   -1,   58,   -1,   60,
   -1,   62,   63,   64,    0,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  124,   -1,  126,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  124,   -1,  126,   -1,   -1,   -1,
   -1,   37,   38,   -1,   40,   41,   42,   43,    0,   45,
   46,   37,   38,   -1,   40,   41,   42,   43,    0,   45,
   46,   -1,   58,  124,   60,  126,   62,   63,   64,   -1,
   -1,   -1,   58,  124,   60,  126,   62,   63,   64,   -1,
   -1,   -1,   -1,   -1,   -1,   37,   38,   -1,   40,   41,
   42,   43,   -1,   45,   46,   37,   38,   -1,   40,   41,
   -1,   -1,   -1,   -1,   -1,   -1,   58,    0,   60,   -1,
   62,   63,   64,    0,   -1,   -1,   58,   -1,   60,   -1,
   62,   63,   64,    0,  257,  258,   -1,   -1,  124,   -1,
  126,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,
  126,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,
   37,   38,    0,   40,   41,   -1,   -1,  257,  258,   -1,
   37,   38,    0,   40,   41,   58,   -1,  257,  258,   62,
   63,   58,  124,   60,  126,   62,   63,   64,   -1,   -1,
    0,   58,  124,   60,  126,   62,   63,   64,   -1,   37,
   38,   -1,   40,   41,   -1,   -1,  257,  258,   -1,   -1,
   38,   -1,   -1,   41,   -1,   -1,  257,  258,   -1,   -1,
   58,   -1,   60,   -1,   62,   63,   64,   -1,   38,   -1,
   58,   41,   -1,   -1,   62,   63,   -1,   -1,   -1,   -1,
   -1,  124,   -1,   -1,   -1,   -1,   -1,  124,   58,  126,
   -1,   -1,   62,   63,   -1,   -1,   -1,  124,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  257,  258,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  257,  258,   -1,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  124,  257,  258,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  257,  258,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  257,  258,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  258,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 259
#define YYUNDFTOKEN 272
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'","'.'",0,0,0,0,0,0,0,0,0,0,0,
"':'",0,"'<'",0,"'>'","'?'","'@'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,
"'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,"TOKEN_LETTER","TOKEN_LITERAL","TOKEN_DIGIT",0,0,0,0,
0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : expr",
"expr : optional_conditional",
"conditional : alternative",
"conditional : alternative '?' optional_conditional ':' conditional",
"optional_conditional :",
"optional_conditional : conditional",
"alternative : list",
"alternative : alternative '|' list",
"alternative : alternative '&' list",
"list : substitute",
"list : list substitute",
"substitute : string",
"substitute : substitute '~' string",
"string : '@'",
"string : TOKEN_LITERAL",
"string : TOKEN_LETTER",
"string : TOKEN_LETTER number",
"string : '%' TOKEN_LETTER",
"string : '%' digits",
"string : string '.' flag TOKEN_LETTER optional_number",
"string : string '+' number",
"string : string '-' number",
"string : string '*'",
"string : '(' optional_conditional ')'",
"string : '<' optional_conditional '>'",
"optional_number :",
"optional_number : number",
"number : TOKEN_DIGIT",
"number : number TOKEN_DIGIT",
"digits : TOKEN_DIGIT",
"digits : digits TOKEN_DIGIT",
"flag :",
"flag : '+'",
"flag : '-'",

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
#line 398 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"

/* bison defines const to be empty unless __STDC__ is defined, which it
isn't under cfront */

#ifdef const
#undef const
#endif

const char *spec_ptr;
const char *spec_end;
const char *spec_cur;

static char uppercase_array[] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
  'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
  'Y', 'Z',
};
  
static char lowercase_array[] = {
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
  'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
  'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
  'y', 'z',
};

int yylex()
{
  while (spec_ptr < spec_end && csspace(*spec_ptr))
    spec_ptr++;
  spec_cur = spec_ptr;
  if (spec_ptr >= spec_end)
    return 0;
  unsigned char c = *spec_ptr++;
  if (csalpha(c)) {
    yylval.num = c;
    return TOKEN_LETTER;
  }
  if (csdigit(c)) {
    yylval.num = c - '0';
    return TOKEN_DIGIT;
  }
  if (c == '\'') {
    yylval.str.start = literals.length();
    for (; spec_ptr < spec_end; spec_ptr++) {
      if (*spec_ptr == '\'') {
	if (++spec_ptr < spec_end && *spec_ptr == '\'')
	  literals += '\'';
	else {
	  yylval.str.len = literals.length() - yylval.str.start;
	  return TOKEN_LITERAL;
	}
      }
      else
	literals += *spec_ptr;
    }
    yylval.str.len = literals.length() - yylval.str.start;
    return TOKEN_LITERAL;
  }
  return c;
}

int set_label_spec(const char *label_spec)
{
  spec_cur = spec_ptr = label_spec;
  spec_end = strchr(label_spec, '\0');
  literals.clear();
  if (yyparse())
    return 0;
  delete parsed_label;
  parsed_label = parse_result;
  return 1;
}

int set_date_label_spec(const char *label_spec)
{
  spec_cur = spec_ptr = label_spec;
  spec_end = strchr(label_spec, '\0');
  literals.clear();
  if (yyparse())
    return 0;
  delete parsed_date_label;
  parsed_date_label = parse_result;
  return 1;
}

int set_short_label_spec(const char *label_spec)
{
  spec_cur = spec_ptr = label_spec;
  spec_end = strchr(label_spec, '\0');
  literals.clear();
  if (yyparse())
    return 0;
  delete parsed_short_label;
  parsed_short_label = parse_result;
  return 1;
}

void yyerror(const char *message)
{
  if (spec_cur < spec_end)
    command_error("label specification %1 before `%2'", message, spec_cur);
  else
    command_error("label specification %1 at end of string",
		  message, spec_cur);
}

void at_expr::evaluate(int tentative, const reference &ref,
		       string &result, substring_position &)
{
  if (tentative)
    ref.canonicalize_authors(result);
  else {
    const char *end, *start = ref.get_authors(&end);
    if (start)
      result.append(start, end - start);
  }
}

void format_expr::evaluate(int tentative, const reference &ref,
			   string &result, substring_position &)
{
  if (tentative)
    return;
  const label_info *lp = ref.get_label_ptr();
  int num = lp == 0 ? ref.get_number() : lp->count;
  if (type != '0')
    result += format_serial(type, num + 1);
  else {
    const char *ptr = i_to_a(num + first_number);
    int pad = width - strlen(ptr);
    while (--pad >= 0)
      result += '0';
    result += ptr;
  }
}

static const char *format_serial(char c, int n)
{
  assert(n > 0);
  static char buf[128]; // more than enough.
  switch (c) {
  case 'i':
  case 'I':
    {
      char *p = buf;
      // troff uses z and w to represent 10000 and 5000 in Roman
      // numerals; I can find no historical basis for this usage
      const char *s = c == 'i' ? "zwmdclxvi" : "ZWMDCLXVI";
      if (n >= 40000)
	return i_to_a(n);
      while (n >= 10000) {
	*p++ = s[0];
	n -= 10000;
      }
      for (int i = 1000; i > 0; i /= 10, s += 2) {
	int m = n/i;
	n -= m*i;
	switch (m) {
	case 3:
	  *p++ = s[2];
	  /* falls through */
	case 2:
	  *p++ = s[2];
	  /* falls through */
	case 1:
	  *p++ = s[2];
	  break;
	case 4:
	  *p++ = s[2];
	  *p++ = s[1];
	  break;
	case 8:
	  *p++ = s[1];
	  *p++ = s[2];
	  *p++ = s[2];
	  *p++ = s[2];
	  break;
	case 7:
	  *p++ = s[1];
	  *p++ = s[2];
	  *p++ = s[2];
	  break;
	case 6:
	  *p++ = s[1];
	  *p++ = s[2];
	  break;
	case 5:
	  *p++ = s[1];
	  break;
	case 9:
	  *p++ = s[2];
	  *p++ = s[0];
	}
      }
      *p = 0;
      break;
    }
  case 'a':
  case 'A':
    {
      char *p = buf;
      // this is derived from troff/reg.c
      while (n > 0) {
	int d = n % 26;
	if (d == 0)
	  d = 26;
	n -= d;
	n /= 26;
	*p++ = c == 'a' ? lowercase_array[d - 1] :
			       uppercase_array[d - 1];
      }
      *p-- = 0;
      // Reverse it.
      char *q = buf;
      while (q < p) {
	char temp = *q;
	*q = *p;
	*p = temp;
	--p;
	++q;
      }
      break;
    }
  default:
    assert(0);
  }
  return buf;
}

void field_expr::evaluate(int, const reference &ref,
			  string &result, substring_position &)
{
  const char *end;
  const char *start = ref.get_field(name, &end);
  if (start) {
    start = nth_field(number, start, &end);
    if (start)
      result.append(start, end - start);
  }
}

void literal_expr::evaluate(int, const reference &,
			    string &result, substring_position &)
{
  result += s;
}

analyzed_expr::analyzed_expr(expression *e)
: unary_expr(e), flags(e ? e->analyze() : 0)
{
}

void analyzed_expr::evaluate(int tentative, const reference &ref,
			     string &result, substring_position &pos)
{
  if (expr)
    expr->evaluate(tentative, ref, result, pos);
}

void star_expr::evaluate(int tentative, const reference &ref,
			 string &result, substring_position &pos)
{
  const label_info *lp = ref.get_label_ptr();
  if (!tentative
      && (lp == 0 || lp->total > 1)
      && expr)
    expr->evaluate(tentative, ref, result, pos);
}

void separator_expr::evaluate(int tentative, const reference &ref,
			      string &result, substring_position &pos)
{
  int start_length = result.length();
  int is_first = pos.start < 0;
  if (expr)
    expr->evaluate(tentative, ref, result, pos);
  if (is_first) {
    pos.start = start_length;
    pos.length = result.length() - start_length;
  }
}

void map_expr::evaluate(int tentative, const reference &ref,
			string &result, substring_position &)
{
  if (expr) {
    string temp;
    substring_position temp_pos;
    expr->evaluate(tentative, ref, temp, temp_pos);
    (*func)(temp.contents(), temp.contents() + temp.length(), result);
  }
}

void extractor_expr::evaluate(int tentative, const reference &ref,
			      string &result, substring_position &)
{
  if (expr) {
    string temp;
    substring_position temp_pos;
    expr->evaluate(tentative, ref, temp, temp_pos);
    const char *end, *start = (*func)(temp.contents(),
				      temp.contents() + temp.length(),
				      &end);
    switch (part) {
    case BEFORE:
      if (start)
	result.append(temp.contents(), start - temp.contents());
      else
	result += temp;
      break;
    case MATCH:
      if (start)
	result.append(start, end - start);
      break;
    case AFTER:
      if (start)
	result.append(end, temp.contents() + temp.length() - end);
      break;
    default:
      assert(0);
    }
  }
}

static void first_part(int len, const char *ptr, const char *end,
			  string &result)
{
  for (;;) {
    const char *token_start = ptr;
    if (!get_token(&ptr, end))
      break;
    const token_info *ti = lookup_token(token_start, ptr);
    int counts = ti->sortify_non_empty(token_start, ptr);
    if (counts && --len < 0)
      break;
    if (counts || ti->is_accent())
      result.append(token_start, ptr - token_start);
  }
}

static void last_part(int len, const char *ptr, const char *end,
		      string &result)
{
  const char *start = ptr;
  int count = 0;
  for (;;) {
    const char *token_start = ptr;
    if (!get_token(&ptr, end))
      break;
    const token_info *ti = lookup_token(token_start, ptr);
    if (ti->sortify_non_empty(token_start, ptr))
      count++;
  }
  ptr = start;
  int skip = count - len;
  if (skip > 0) {
    for (;;) {
      const char *token_start = ptr;
      if (!get_token(&ptr, end))
	assert(0);
      const token_info *ti = lookup_token(token_start, ptr);
      if (ti->sortify_non_empty(token_start, ptr) && --skip < 0) {
	ptr = token_start;
	break;
      }
    }
  }
  first_part(len, ptr, end, result);
}

void truncate_expr::evaluate(int tentative, const reference &ref,
			     string &result, substring_position &)
{
  if (expr) {
    string temp;
    substring_position temp_pos;
    expr->evaluate(tentative, ref, temp, temp_pos);
    const char *start = temp.contents();
    const char *end = start + temp.length();
    if (n > 0)
      first_part(n, start, end, result);
    else if (n < 0)
      last_part(-n, start, end, result);
  }
}

void alternative_expr::evaluate(int tentative, const reference &ref,
				string &result, substring_position &pos)
{
  int start_length = result.length();
  if (expr1)
    expr1->evaluate(tentative, ref, result, pos);
  if (result.length() == start_length && expr2)
    expr2->evaluate(tentative, ref, result, pos);
}

void list_expr::evaluate(int tentative, const reference &ref,
			 string &result, substring_position &pos)
{
  if (expr1)
    expr1->evaluate(tentative, ref, result, pos);
  if (expr2)
    expr2->evaluate(tentative, ref, result, pos);
}

void substitute_expr::evaluate(int tentative, const reference &ref,
			       string &result, substring_position &pos)
{
  int start_length = result.length();
  if (expr1)
    expr1->evaluate(tentative, ref, result, pos);
  if (result.length() > start_length && result[result.length() - 1] == '-') {
    // ought to see if pos covers the -
    result.set_length(result.length() - 1);
    if (expr2)
      expr2->evaluate(tentative, ref, result, pos);
  }
}

void conditional_expr::evaluate(int tentative, const reference &ref,
				string &result, substring_position &pos)
{
  string temp;
  substring_position temp_pos;
  if (expr1)
    expr1->evaluate(tentative, ref, temp, temp_pos);
  if (temp.length() > 0) {
    if (expr2)
      expr2->evaluate(tentative, ref, result, pos);
  }
  else {
    if (expr3)
      expr3->evaluate(tentative, ref, result, pos);
  }
}

void reference::pre_compute_label()
{
  if (parsed_label != 0
      && (parsed_label->analyze() & expression::CONTAINS_VARIABLE)) {
    label.clear();
    substring_position temp_pos;
    parsed_label->evaluate(1, *this, label, temp_pos);
    label_ptr = lookup_label(label);
  }
}

void reference::compute_label()
{
  label.clear();
  if (parsed_label)
    parsed_label->evaluate(0, *this, label, separator_pos);
  if (short_label_flag && parsed_short_label)
    parsed_short_label->evaluate(0, *this, short_label, short_separator_pos);
  if (date_as_label) {
    string new_date;
    if (parsed_date_label) {
      substring_position temp_pos;
      parsed_date_label->evaluate(0, *this, new_date, temp_pos);
    }
    set_date(new_date);
  }
  if (label_ptr)
    label_ptr->count += 1;
}

void reference::immediate_compute_label()
{
  if (label_ptr)
    label_ptr->total = 2;	// force use of disambiguator
  compute_label();
}

int reference::merge_labels(reference **v, int n, label_type type,
			    string &result)
{
  if (abbreviate_label_ranges)
    return merge_labels_by_number(v, n, type, result);
  else
    return merge_labels_by_parts(v, n, type, result);
}

int reference::merge_labels_by_number(reference **v, int n, label_type type,
				      string &result)
{
  if (n <= 1)
    return 0;
  int num = get_number();
  // Only merge three or more labels.
  if (v[0]->get_number() != num + 1
      || v[1]->get_number() != num + 2)
    return 0;
  int i;
  for (i = 2; i < n; i++)
    if (v[i]->get_number() != num + i + 1)
      break;
  result = get_label(type);
  result += label_range_indicator;
  result += v[i - 1]->get_label(type);
  return i;
}

const substring_position &reference::get_separator_pos(label_type type) const
{
  if (type == SHORT_LABEL && short_label_flag)
    return short_separator_pos;
  else
    return separator_pos;
}

const string &reference::get_label(label_type type) const
{
  if (type == SHORT_LABEL && short_label_flag)
    return short_label; 
  else
    return label;
}

int reference::merge_labels_by_parts(reference **v, int n, label_type type,
				     string &result)
{
  if (n <= 0)
    return 0;
  const string &lb = get_label(type);
  const substring_position &sp = get_separator_pos(type);
  if (sp.start < 0
      || sp.start != v[0]->get_separator_pos(type).start 
      || memcmp(lb.contents(), v[0]->get_label(type).contents(),
		sp.start) != 0)
    return 0;
  result = lb;
  int i = 0;
  do {
    result += separate_label_second_parts;
    const substring_position &s = v[i]->get_separator_pos(type);
    int sep_end_pos = s.start + s.length;
    result.append(v[i]->get_label(type).contents() + sep_end_pos,
		  v[i]->get_label(type).length() - sep_end_pos);
  } while (++i < n
	   && sp.start == v[i]->get_separator_pos(type).start
	   && memcmp(lb.contents(), v[i]->get_label(type).contents(),
		     sp.start) == 0);
  return i;
}

string label_pool;

label_info::label_info(const string &s)
: start(label_pool.length()), length(s.length()), count(0), total(1)
{
  label_pool += s;
}

static label_info **label_table = 0;
static int label_table_size = 0;
static int label_table_used = 0;

label_info *lookup_label(const string &label)
{
  if (label_table == 0) {
    label_table = new label_info *[17];
    label_table_size = 17;
    for (int i = 0; i < 17; i++)
      label_table[i] = 0;
  }
  unsigned h = hash_string(label.contents(), label.length()) % label_table_size;
  label_info **ptr;
  for (ptr = label_table + h;
       *ptr != 0;
       (ptr == label_table)
       ? (ptr = label_table + label_table_size - 1)
       : ptr--)
    if ((*ptr)->length == label.length()
	&& memcmp(label_pool.contents() + (*ptr)->start, label.contents(),
		  label.length()) == 0) {
      (*ptr)->total += 1;
      return *ptr;
    }
  label_info *result = *ptr = new label_info(label);
  if (++label_table_used * 2 > label_table_size) {
    // Rehash the table.
    label_info **old_table = label_table;
    int old_size = label_table_size;
    label_table_size = next_size(label_table_size);
    label_table = new label_info *[label_table_size];
    int i;
    for (i = 0; i < label_table_size; i++)
      label_table[i] = 0;
    for (i = 0; i < old_size; i++)
      if (old_table[i]) {
	h = hash_string(label_pool.contents() + old_table[i]->start,
			old_table[i]->length);
	label_info **p;
	for (p = label_table + (h % label_table_size);
	     *p != 0;
	     (p == label_table)
	     ? (p = label_table + label_table_size - 1)
	     : --p)
	    ;
	*p = old_table[i];
	}
    a_delete old_table;
  }
  return result;
}

void clear_labels()
{
  for (int i = 0; i < label_table_size; i++) {
    delete label_table[i];
    label_table[i] = 0;
  }
  label_table_used = 0;
  label_pool.clear();
}

static void consider_authors(reference **start, reference **end, int i);

void compute_labels(reference **v, int n)
{
  if (parsed_label
      && (parsed_label->analyze() & expression::CONTAINS_AT)
      && sort_fields.length() >= 2
      && sort_fields[0] == 'A'
      && sort_fields[1] == '+')
    consider_authors(v, v + n, 0);
  for (int i = 0; i < n; i++)
    v[i]->compute_label();
}


/* A reference with a list of authors <A0,A1,...,AN> _needs_ author i
where 0 <= i <= N if there exists a reference with a list of authors
<B0,B1,...,BM> such that <A0,A1,...,AN> != <B0,B1,...,BM> and M >= i
and Aj = Bj for 0 <= j < i. In this case if we can't say ``A0,
A1,...,A(i-1) et al'' because this would match both <A0,A1,...,AN> and
<B0,B1,...,BM>.  If a reference needs author i we only have to call
need_author(j) for some j >= i such that the reference also needs
author j. */

/* This function handles 2 tasks:
determine which authors are needed (cannot be elided with et al.);
determine which authors can have only last names in the labels.

References >= start and < end have the same first i author names.
Also they're sorted by A+. */

static void consider_authors(reference **start, reference **end, int i)
{
  if (start >= end)
    return;
  reference **p = start;
  if (i >= (*p)->get_nauthors()) {
    for (++p; p < end && i >= (*p)->get_nauthors(); p++)
      ;
    if (p < end && i > 0) {
      // If we have an author list <A B C> and an author list <A B C D>,
      // then both lists need C.
      for (reference **q = start; q < end; q++)
	(*q)->need_author(i - 1);
    }
    start = p;
  }
  while (p < end) {
    reference **last_name_start = p;
    reference **name_start = p;
    for (++p;
	 p < end && i < (*p)->get_nauthors()
	 && same_author_last_name(**last_name_start, **p, i);
	 p++) {
      if (!same_author_name(**name_start, **p, i)) {
	consider_authors(name_start, p, i + 1);
	name_start = p;
      }
    }
    consider_authors(name_start, p, i + 1);
    if (last_name_start == name_start) {
      for (reference **q = last_name_start; q < p; q++)
	(*q)->set_last_name_unambiguous(i);
    }
    // If we have an author list <A B C D> and <A B C E>, then the lists
    // need author D and E respectively.
    if (name_start > start || p < end) {
      for (reference **q = last_name_start; q < p; q++)
	(*q)->need_author(i);
    }
  }
}

int same_author_last_name(const reference &r1, const reference &r2, int n)
{
  const char *ae1;
  const char *as1 = r1.get_sort_field(0, n, 0, &ae1);
  const char *ae2;
  const char *as2 = r2.get_sort_field(0, n, 0, &ae2);
  if (!as1 && !as2) return 1;	// they are the same
  if (!as1 || !as2) return 0;
  return ae1 - as1 == ae2 - as2 && memcmp(as1, as2, ae1 - as1) == 0;
}

int same_author_name(const reference &r1, const reference &r2, int n)
{
  const char *ae1;
  const char *as1 = r1.get_sort_field(0, n, -1, &ae1);
  const char *ae2;
  const char *as2 = r2.get_sort_field(0, n, -1, &ae2);
  if (!as1 && !as2) return 1;	// they are the same
  if (!as1 || !as2) return 0;
  return ae1 - as1 == ae2 - as2 && memcmp(as1, as2, ae1 - as1) == 0;
}


void int_set::set(int i)
{
  assert(i >= 0);
  int bytei = i >> 3;
  if (bytei >= v.length()) {
    int old_length = v.length();
    v.set_length(bytei + 1);
    for (int j = old_length; j <= bytei; j++)
      v[j] = 0;
  }
  v[bytei] |= 1 << (i & 7);
}

int int_set::get(int i) const
{
  assert(i >= 0);
  int bytei = i >> 3;
  return bytei >= v.length() ? 0 : (v[bytei] & (1 << (i & 7))) != 0;
}

void reference::set_last_name_unambiguous(int i)
{
  last_name_unambiguous.set(i);
}

void reference::need_author(int n)
{
  if (n > last_needed_author)
    last_needed_author = n;
}

const char *reference::get_authors(const char **end) const
{
  if (!computed_authors) {
    ((reference *)this)->computed_authors = 1;
    string &result = ((reference *)this)->authors;
    int na = get_nauthors();
    result.clear();
    for (int i = 0; i < na; i++) {
      if (last_name_unambiguous.get(i)) {
	const char *e, *start = get_author_last_name(i, &e);
	assert(start != 0);
	result.append(start, e - start);
      }
      else {
	const char *e, *start = get_author(i, &e);
	assert(start != 0);
	result.append(start, e - start);
      }
      if (i == last_needed_author
	  && et_al.length() > 0
	  && et_al_min_elide > 0
	  && last_needed_author + et_al_min_elide < na
	  && na >= et_al_min_total) {
	result += et_al;
	break;
      }
      if (i < na - 1) {
	if (na == 2)
	  result += join_authors_exactly_two;
	else if (i < na - 2)
	  result += join_authors_default;
	else
	  result += join_authors_last_two;
      }
    }
  }
  const char *start = authors.contents();
  *end = start + authors.length();
  return start;
}

int reference::get_nauthors() const
{
  if (nauthors < 0) {
    const char *dummy;
    int na;
    for (na = 0; get_author(na, &dummy) != 0; na++)
      ;
    ((reference *)this)->nauthors = na;
  }
  return nauthors;
}
#line 1308 "y.tab.c"

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
#line 251 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ parse_result = (yystack.l_mark[0].expr ? new analyzed_expr(yystack.l_mark[0].expr) : 0); }
break;
case 2:
#line 256 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = yystack.l_mark[0].expr; }
break;
case 3:
#line 258 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = new conditional_expr(yystack.l_mark[-4].expr, yystack.l_mark[-2].expr, yystack.l_mark[0].expr); }
break;
case 4:
#line 263 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = 0; }
break;
case 5:
#line 265 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = yystack.l_mark[0].expr; }
break;
case 6:
#line 270 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = yystack.l_mark[0].expr; }
break;
case 7:
#line 272 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = new alternative_expr(yystack.l_mark[-2].expr, yystack.l_mark[0].expr); }
break;
case 8:
#line 274 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = new conditional_expr(yystack.l_mark[-2].expr, yystack.l_mark[0].expr, 0); }
break;
case 9:
#line 279 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = yystack.l_mark[0].expr; }
break;
case 10:
#line 281 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = new list_expr(yystack.l_mark[-1].expr, yystack.l_mark[0].expr); }
break;
case 11:
#line 286 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = yystack.l_mark[0].expr; }
break;
case 12:
#line 288 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = new substitute_expr(yystack.l_mark[-2].expr, yystack.l_mark[0].expr); }
break;
case 13:
#line 293 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = new at_expr; }
break;
case 14:
#line 295 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{
		  yyval.expr = new literal_expr(literals.contents() + yystack.l_mark[0].str.start,
					yystack.l_mark[0].str.len);
		}
break;
case 15:
#line 300 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = new field_expr(yystack.l_mark[0].num, 0); }
break;
case 16:
#line 302 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = new field_expr(yystack.l_mark[-1].num, yystack.l_mark[0].num - 1); }
break;
case 17:
#line 304 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{
		  switch (yystack.l_mark[0].num) {
		  case 'I':
		  case 'i':
		  case 'A':
		  case 'a':
		    yyval.expr = new format_expr(yystack.l_mark[0].num);
		    break;
		  default:
		    command_error("unrecognized format `%1'", char(yystack.l_mark[0].num));
		    yyval.expr = new format_expr('a');
		    break;
		  }
		}
break;
case 18:
#line 320 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{
		  yyval.expr = new format_expr('0', yystack.l_mark[0].dig.ndigits, yystack.l_mark[0].dig.val);
		}
break;
case 19:
#line 324 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{
		  switch (yystack.l_mark[-1].num) {
		  case 'l':
		    yyval.expr = new map_expr(yystack.l_mark[-4].expr, lowercase);
		    break;
		  case 'u':
		    yyval.expr = new map_expr(yystack.l_mark[-4].expr, uppercase);
		    break;
		  case 'c':
		    yyval.expr = new map_expr(yystack.l_mark[-4].expr, capitalize);
		    break;
		  case 'r':
		    yyval.expr = new map_expr(yystack.l_mark[-4].expr, reverse_name);
		    break;
		  case 'a':
		    yyval.expr = new map_expr(yystack.l_mark[-4].expr, abbreviate_name);
		    break;
		  case 'y':
		    yyval.expr = new extractor_expr(yystack.l_mark[-4].expr, find_year, yystack.l_mark[-2].num);
		    break;
		  case 'n':
		    yyval.expr = new extractor_expr(yystack.l_mark[-4].expr, find_last_name, yystack.l_mark[-2].num);
		    break;
		  default:
		    yyval.expr = yystack.l_mark[-4].expr;
		    command_error("unknown function `%1'", char(yystack.l_mark[-1].num));
		    break;
		  }
		}
break;
case 20:
#line 355 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = new truncate_expr(yystack.l_mark[-2].expr, yystack.l_mark[0].num); }
break;
case 21:
#line 357 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = new truncate_expr(yystack.l_mark[-2].expr, -yystack.l_mark[0].num); }
break;
case 22:
#line 359 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = new star_expr(yystack.l_mark[-1].expr); }
break;
case 23:
#line 361 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = yystack.l_mark[-1].expr; }
break;
case 24:
#line 363 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.expr = new separator_expr(yystack.l_mark[-1].expr); }
break;
case 25:
#line 368 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.num = -1; }
break;
case 26:
#line 370 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.num = yystack.l_mark[0].num; }
break;
case 27:
#line 375 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.num = yystack.l_mark[0].num; }
break;
case 28:
#line 377 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.num = yystack.l_mark[-1].num*10 + yystack.l_mark[0].num; }
break;
case 29:
#line 382 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.dig.ndigits = 1; yyval.dig.val = yystack.l_mark[0].num; }
break;
case 30:
#line 384 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.dig.ndigits = yystack.l_mark[-1].dig.ndigits + 1; yyval.dig.val = yystack.l_mark[-1].dig.val*10 + yystack.l_mark[0].num; }
break;
case 31:
#line 390 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.num = 0; }
break;
case 32:
#line 392 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.num = 1; }
break;
case 33:
#line 394 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/gnu/usr.bin/groff/src/preproc/refer/../../../../../../contrib/groff/src/preproc/refer/label.y"
	{ yyval.num = -1; }
break;
#line 1685 "y.tab.c"
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