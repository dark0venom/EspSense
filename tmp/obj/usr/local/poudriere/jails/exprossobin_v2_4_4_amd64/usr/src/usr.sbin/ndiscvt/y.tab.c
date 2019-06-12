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

#line 2 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
/*
 * Copyright (c) 2003
 *	Bill Paul <wpaul@windriver.com>.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by Bill Paul.
 * 4. Neither the name of the author nor the names of any co-contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <stdio.h>
#include <sys/types.h>
#include <sys/queue.h>

#include "inf.h"

extern int yylex (void);
extern void yyerror(const char *);
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 52 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
typedef union {
	char *str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 76 "y.tab.c"

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

#define EQUALS 257
#define COMMA 258
#define EOL 259
#define SECTION 260
#define STRING 261
#define WORD 262
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    1,    2,    2,    2,    2,    2,    3,
    3,    3,    3,    3,    3,    3,    4,    4,    4,    4,
    4,    4,
};
static const YYINT yylen[] = {                            2,
    1,    0,    1,    2,    2,    4,    4,    2,    1,    1,
    1,    3,    3,    2,    1,    0,    1,    1,    3,    3,
    2,    1,
};
static const YYINT yydefred[] = {                         0,
    9,    0,    0,    0,    0,    3,    5,    0,    0,    8,
    4,    0,    0,    0,    0,    0,    0,    0,    0,   14,
    0,    0,    6,   21,    0,    0,    7,   13,   12,   20,
   19,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,   15,   19,
};
static const YYINT yysindex[] = {                      -246,
    0, -251, -240,    0, -246,    0,    0, -257, -255,    0,
    0, -257, -243, -238, -237, -255, -235, -234, -233,    0,
 -257, -257,    0,    0, -255, -255,    0,    0,    0,    0,
    0,
};
static const YYINT yyrindex[] = {                        21,
    0,    0,    0,    0,   25,    0,    0, -232,    0,    0,
    0, -231, -230, -229,    0, -228, -227, -226,    0,    0,
 -232, -232,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
    0,   29,  -12,  -14,
};
#define YYTABLESIZE 34
static const YYINT yytable[] = {                         20,
   12,   24,   16,   13,   14,   17,   18,    7,   28,   29,
   30,   31,    1,    2,   21,    3,    8,    9,   10,   22,
    2,   23,   25,   26,    1,   27,   16,   15,   11,   10,
   22,   18,   17,   11,
};
static const YYINT yycheck[] = {                         12,
  258,   16,  258,  261,  262,  261,  262,  259,   21,   22,
   25,   26,  259,  260,  258,  262,  257,  258,  259,  258,
    0,  259,  258,  258,    0,  259,  259,  259,  259,  259,
  259,  259,  259,    5,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 262
#define YYUNDFTOKEN 269
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"EQUALS","COMMA","EOL","SECTION",
"STRING","WORD",0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : inf_file",
"inf_file : inf_list",
"inf_file :",
"inf_list : inf",
"inf_list : inf_list inf",
"inf : SECTION EOL",
"inf : WORD EQUALS assign EOL",
"inf : WORD COMMA regkey EOL",
"inf : WORD EOL",
"inf : EOL",
"assign : WORD",
"assign : STRING",
"assign : WORD COMMA assign",
"assign : STRING COMMA assign",
"assign : COMMA assign",
"assign : COMMA",
"assign :",
"regkey : WORD",
"regkey : STRING",
"regkey : WORD COMMA regkey",
"regkey : STRING COMMA regkey",
"regkey : COMMA regkey",
"regkey : COMMA",

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
case 5:
#line 70 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ section_add(yystack.l_mark[-1].str); }
break;
case 6:
#line 72 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ assign_add(yystack.l_mark[-3].str); }
break;
case 7:
#line 74 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ regkey_add(yystack.l_mark[-3].str); }
break;
case 8:
#line 76 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ define_add(yystack.l_mark[-1].str); }
break;
case 10:
#line 82 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ push_word(yystack.l_mark[0].str); }
break;
case 11:
#line 84 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ push_word(yystack.l_mark[0].str); }
break;
case 12:
#line 86 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ push_word(yystack.l_mark[-2].str); }
break;
case 13:
#line 88 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ push_word(yystack.l_mark[-2].str); }
break;
case 14:
#line 90 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ push_word(NULL); }
break;
case 15:
#line 92 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ push_word(NULL); }
break;
case 17:
#line 98 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ push_word(yystack.l_mark[0].str); }
break;
case 18:
#line 100 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ push_word(yystack.l_mark[0].str); }
break;
case 19:
#line 102 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ push_word(yystack.l_mark[-2].str); }
break;
case 20:
#line 104 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ push_word(yystack.l_mark[-2].str); }
break;
case 21:
#line 106 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ push_word(NULL); }
break;
case 22:
#line 108 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ndiscvt/inf-parse.y"
	{ push_word(NULL); }
break;
#line 506 "y.tab.c"
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
