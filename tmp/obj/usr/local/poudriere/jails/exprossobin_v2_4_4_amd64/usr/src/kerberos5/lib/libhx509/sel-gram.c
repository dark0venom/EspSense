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

#line 35 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <hx_locl.h>


#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 45 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
typedef union {
    char *string;
    struct hx_expr *expr;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 42 "sel-gram.c"

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

#define kw_TRUE 257
#define kw_FALSE 258
#define kw_AND 259
#define kw_OR 260
#define kw_IN 261
#define kw_TAILMATCH 262
#define NUMBER 263
#define STRING 264
#define IDENTIFIER 265
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,    1,    1,    1,    1,    4,    4,
    2,    2,    2,    2,    2,    3,    3,    3,    3,    5,
    6,    7,    8,    9,    9,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    2,    3,    3,    3,    1,    1,    3,
    4,    4,    3,    5,    3,    1,    1,    1,    1,    1,
    1,    4,    4,    3,    1,
};
static const YYINT yydefred[] = {                         0,
    2,    3,   20,   21,    0,    0,    0,    0,    0,    0,
    8,    0,   16,   17,   18,   19,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    7,    0,
    0,    0,    0,    0,   15,   13,    0,    0,    0,   22,
    0,   23,    0,   12,   11,   10,   24,   14,
};
static const YYINT yydgoto[] = {                          9,
   10,   11,   12,   28,   13,   14,   15,   16,   31,
};
static const YYINT yysindex[] = {                       -33,
    0,    0,    0,    0,  -23,  -33,  -33, -105,    0, -247,
    0,  -28,    0,    0,    0,    0,  -36, -247,  -39, -244,
  -33,  -33,  -26,  -36,  -38,  -37,  -22,  -16,    0,  -19,
  -97, -247, -247,  -36,    0,    0,  -36,  -36,  -36,    0,
 -244,    0,   -9,    0,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   36,
    0,    0,    0,    0,    0,    0,    0,    3,    0,    0,
    0,    0,    0,    0,    0,    0,   -4,    0,    0,  -87,
    0,    6,    8,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   13,    0,   -8,  -24,    0,    0,    0,   16,   -1,
};
#define YYTABLESIZE 234
static const YYINT yytable[] = {                          6,
    8,   29,    4,    8,   25,    5,    7,    6,   27,   43,
    8,   21,   22,   34,   46,   36,   17,   20,   18,   19,
   30,   39,   37,   38,   40,   27,   41,   42,   44,   45,
   27,   48,   26,   32,   33,    1,    9,   25,   35,   47,
    0,    0,    0,    4,    0,    0,    5,    0,    6,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   21,
   22,    0,    0,    1,    2,    0,    3,    4,    5,    3,
    4,    5,   23,   24,
};
static const YYINT yycheck[] = {                         33,
   37,   41,    0,   37,   33,    0,   40,    0,   17,   34,
   37,  259,  260,   40,   39,   24,   40,  123,    6,    7,
  265,   44,   61,   61,   41,   34,   46,  125,   37,   38,
   39,   41,   61,   21,   22,    0,   41,  125,   23,   41,
   -1,   -1,   -1,   41,   -1,   -1,   41,   -1,   41,   -1,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,
  260,   -1,   -1,  257,  258,   -1,  263,  264,  265,  263,
  264,  265,  261,  262,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 265
#define YYUNDFTOKEN 277
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'",0,0,"'('","')'",0,0,"','",0,"'.'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"kw_TRUE","kw_FALSE","kw_AND","kw_OR","kw_IN","kw_TAILMATCH","NUMBER",
"STRING","IDENTIFIER",0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : expr",
"expr : kw_TRUE",
"expr : kw_FALSE",
"expr : '!' expr",
"expr : expr kw_AND expr",
"expr : expr kw_OR expr",
"expr : '(' expr ')'",
"expr : comp",
"words : word",
"words : word ',' words",
"comp : word '=' '=' word",
"comp : word '!' '=' word",
"comp : word kw_TAILMATCH word",
"comp : word kw_IN '(' words ')'",
"comp : word kw_IN variable",
"word : number",
"word : string",
"word : function",
"word : variable",
"number : NUMBER",
"string : STRING",
"function : IDENTIFIER '(' words ')'",
"variable : '%' '{' variables '}'",
"variables : IDENTIFIER '.' variables",
"variables : IDENTIFIER",

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
#line 73 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ _hx509_expr_input.expr = yystack.l_mark[0].expr; }
break;
case 2:
#line 75 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = _hx509_make_expr(op_TRUE, NULL, NULL); }
break;
case 3:
#line 76 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = _hx509_make_expr(op_FALSE, NULL, NULL); }
break;
case 4:
#line 77 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = _hx509_make_expr(op_NOT, yystack.l_mark[0].expr, NULL); }
break;
case 5:
#line 78 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = _hx509_make_expr(op_AND, yystack.l_mark[-2].expr, yystack.l_mark[0].expr); }
break;
case 6:
#line 79 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = _hx509_make_expr(op_OR, yystack.l_mark[-2].expr, yystack.l_mark[0].expr); }
break;
case 7:
#line 80 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = yystack.l_mark[-1].expr; }
break;
case 8:
#line 81 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = _hx509_make_expr(op_COMP, yystack.l_mark[0].expr, NULL); }
break;
case 9:
#line 84 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = _hx509_make_expr(expr_WORDS, yystack.l_mark[0].expr, NULL); }
break;
case 10:
#line 85 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = _hx509_make_expr(expr_WORDS, yystack.l_mark[-2].expr, yystack.l_mark[0].expr); }
break;
case 11:
#line 88 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = _hx509_make_expr(comp_EQ, yystack.l_mark[-3].expr, yystack.l_mark[0].expr); }
break;
case 12:
#line 89 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = _hx509_make_expr(comp_NE, yystack.l_mark[-3].expr, yystack.l_mark[0].expr); }
break;
case 13:
#line 90 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = _hx509_make_expr(comp_TAILEQ, yystack.l_mark[-2].expr, yystack.l_mark[0].expr); }
break;
case 14:
#line 91 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = _hx509_make_expr(comp_IN, yystack.l_mark[-4].expr, yystack.l_mark[-1].expr); }
break;
case 15:
#line 92 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = _hx509_make_expr(comp_IN, yystack.l_mark[-2].expr, yystack.l_mark[0].expr); }
break;
case 16:
#line 95 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = yystack.l_mark[0].expr; }
break;
case 17:
#line 96 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = yystack.l_mark[0].expr; }
break;
case 18:
#line 97 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = yystack.l_mark[0].expr; }
break;
case 19:
#line 98 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = yystack.l_mark[0].expr; }
break;
case 20:
#line 101 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = _hx509_make_expr(expr_NUMBER, yystack.l_mark[0].string, NULL); }
break;
case 21:
#line 102 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = _hx509_make_expr(expr_STRING, yystack.l_mark[0].string, NULL); }
break;
case 22:
#line 104 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{
			yyval.expr = _hx509_make_expr(expr_FUNCTION, yystack.l_mark[-3].string, yystack.l_mark[-1].expr); }
break;
case 23:
#line 107 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{ yyval.expr = yystack.l_mark[-1].expr; }
break;
case 24:
#line 110 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{
			yyval.expr = _hx509_make_expr(expr_VAR, yystack.l_mark[-2].string, yystack.l_mark[0].expr); }
break;
case 25:
#line 112 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/sel-gram.y"
	{
			yyval.expr = _hx509_make_expr(expr_VAR, yystack.l_mark[0].string, NULL); }
break;
#line 561 "sel-gram.c"
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
