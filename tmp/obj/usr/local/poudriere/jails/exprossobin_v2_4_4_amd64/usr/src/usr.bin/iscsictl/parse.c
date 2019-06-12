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

#line 2 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
/*-
 * SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * Copyright (c) 2012 The FreeBSD Foundation
 * All rights reserved.
 *
 * This software was developed by Edward Tomasz Napierala under sponsorship
 * from the FreeBSD Foundation.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#include <sys/queue.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <libxo/xo.h>

#include "iscsictl.h"

extern FILE *yyin;
extern char *yytext;
extern int lineno;

static struct conf *conf;
static struct target *target;

extern void	yyerror(const char *);
extern int	yylex(void);
extern void	yyrestart(FILE *);

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 66 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
typedef union
{
	char *str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 91 "y.tab.c"

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

#define AUTH_METHOD 257
#define ENABLE 258
#define HEADER_DIGEST 259
#define DATA_DIGEST 260
#define TARGET_NAME 261
#define TARGET_ADDRESS 262
#define INITIATOR_NAME 263
#define INITIATOR_ADDRESS 264
#define INITIATOR_ALIAS 265
#define USER 266
#define SECRET 267
#define MUTUAL_USER 268
#define MUTUAL_SECRET 269
#define SEMICOLON 270
#define SESSION_TYPE 271
#define PROTOCOL 272
#define OFFLOAD 273
#define IGNORED 274
#define EQUALS 275
#define OPENING_BRACKET 276
#define CLOSING_BRACKET 277
#define STR 278
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    2,    2,    2,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    4,    5,    6,    7,    8,    9,   10,
   11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
};
static const YYINT yylen[] = {                            2,
    0,    2,    4,    0,    2,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    2,    4,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    3,    0,    7,    8,    9,   10,   11,   12,
   13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
   23,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,   33,
   37,   34,   35,   24,   25,   26,   27,   28,   29,   30,
   31,   32,   36,   39,   38,   40,
};
static const YYINT yydgoto[] = {                          1,
    3,    5,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,
};
static const YYINT yysindex[] = {                         0,
 -265, -258,    0,    0, -257, -256, -241, -235, -233, -232,
 -231, -230, -229, -228, -227, -226, -225, -224, -223, -222,
 -221, -220,    0, -214,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -239, -219, -218, -217, -216, -215, -213, -212, -211,
 -210, -209, -208, -207, -206, -205, -204, -203,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -236,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 75
static const YYINT yytable[] = {                          6,
    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
   17,   18,    2,   19,   20,   21,   22,    4,   42,   23,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
    5,    5,    5,   43,    5,    5,    5,    5,   60,   44,
    5,   45,   46,   47,   48,   49,   50,   51,   52,   53,
   54,   55,   56,   57,   58,   59,    0,    0,   61,   62,
   63,   64,   65,    0,   66,   67,   68,   69,   70,   71,
   72,   73,   74,   75,   76,
};
static const YYINT yycheck[] = {                        257,
  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  268,  269,  278,  271,  272,  273,  274,  276,  275,  277,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,
  267,  268,  269,  275,  271,  272,  273,  274,  278,  275,
  277,  275,  275,  275,  275,  275,  275,  275,  275,  275,
  275,  275,  275,  275,  275,  270,   -1,   -1,  278,  278,
  278,  278,  278,   -1,  278,  278,  278,  278,  278,  278,
  278,  278,  278,  278,  278,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 278
#define YYUNDFTOKEN 301
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"AUTH_METHOD","ENABLE",
"HEADER_DIGEST","DATA_DIGEST","TARGET_NAME","TARGET_ADDRESS","INITIATOR_NAME",
"INITIATOR_ADDRESS","INITIATOR_ALIAS","USER","SECRET","MUTUAL_USER",
"MUTUAL_SECRET","SEMICOLON","SESSION_TYPE","PROTOCOL","OFFLOAD","IGNORED",
"EQUALS","OPENING_BRACKET","CLOSING_BRACKET","STR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : targets",
"targets :",
"targets : targets target",
"target : STR OPENING_BRACKET target_entries CLOSING_BRACKET",
"target_entries :",
"target_entries : target_entries target_entry",
"target_entries : target_entries target_entry SEMICOLON",
"target_entry : target_name",
"target_entry : target_address",
"target_entry : initiator_name",
"target_entry : initiator_address",
"target_entry : initiator_alias",
"target_entry : user",
"target_entry : secret",
"target_entry : mutual_user",
"target_entry : mutual_secret",
"target_entry : auth_method",
"target_entry : header_digest",
"target_entry : data_digest",
"target_entry : session_type",
"target_entry : enable",
"target_entry : offload",
"target_entry : protocol",
"target_entry : ignored",
"target_name : TARGET_NAME EQUALS STR",
"target_address : TARGET_ADDRESS EQUALS STR",
"initiator_name : INITIATOR_NAME EQUALS STR",
"initiator_address : INITIATOR_ADDRESS EQUALS STR",
"initiator_alias : INITIATOR_ALIAS EQUALS STR",
"user : USER EQUALS STR",
"secret : SECRET EQUALS STR",
"mutual_user : MUTUAL_USER EQUALS STR",
"mutual_secret : MUTUAL_SECRET EQUALS STR",
"auth_method : AUTH_METHOD EQUALS STR",
"header_digest : HEADER_DIGEST EQUALS STR",
"data_digest : DATA_DIGEST EQUALS STR",
"session_type : SESSION_TYPE EQUALS STR",
"enable : ENABLE EQUALS STR",
"offload : OFFLOAD EQUALS STR",
"protocol : PROTOCOL EQUALS STR",
"ignored : IGNORED EQUALS STR",

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
#line 300 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"

void
yyerror(const char *str)
{

	xo_errx(1, "error in configuration file at line %d near '%s': %s",
	    lineno, yytext, str);
}

static void
check_perms(const char *path)
{
	struct stat sb;
	int error;

	error = stat(path, &sb);
	if (error != 0) {
		xo_warn("stat");
		return;
	}
	if (sb.st_mode & S_IWOTH) {
		xo_warnx("%s is world-writable", path);
	} else if (sb.st_mode & S_IROTH) {
		xo_warnx("%s is world-readable", path);
	} else if (sb.st_mode & S_IXOTH) {
		/*
		 * Ok, this one doesn't matter, but still do it,
		 * just for consistency.
		 */
		xo_warnx("%s is world-executable", path);
	}

	/*
	 * XXX: Should we also check for owner != 0?
	 */
}

struct conf *
conf_new_from_file(const char *path)
{
	int error;

	conf = conf_new();
	target = target_new(conf);

	yyin = fopen(path, "r");
	if (yyin == NULL)
		xo_err(1, "unable to open configuration file %s", path);
	check_perms(path);
	lineno = 1;
	yyrestart(yyin);
	error = yyparse();
	assert(error == 0);
	fclose(yyin);

	assert(target->t_nickname == NULL);
	target_delete(target);

	conf_verify(conf);

	return (conf);
}
#line 384 "y.tab.c"

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
case 3:
#line 81 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target_find(conf, yystack.l_mark[-3].str) != NULL)
			xo_errx(1, "duplicated target %s", yystack.l_mark[-3].str);
		target->t_nickname = yystack.l_mark[-3].str;
		target = target_new(conf);
	}
break;
case 24:
#line 133 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_name != NULL)
			xo_errx(1, "duplicated TargetName at line %d", lineno);
		target->t_name = yystack.l_mark[0].str;
	}
break;
case 25:
#line 141 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_address != NULL)
			xo_errx(1, "duplicated TargetAddress at line %d", lineno);
		target->t_address = yystack.l_mark[0].str;
	}
break;
case 26:
#line 149 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_initiator_name != NULL)
			xo_errx(1, "duplicated InitiatorName at line %d", lineno);
		target->t_initiator_name = yystack.l_mark[0].str;
	}
break;
case 27:
#line 157 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_initiator_address != NULL)
			xo_errx(1, "duplicated InitiatorAddress at line %d", lineno);
		target->t_initiator_address = yystack.l_mark[0].str;
	}
break;
case 28:
#line 165 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_initiator_alias != NULL)
			xo_errx(1, "duplicated InitiatorAlias at line %d", lineno);
		target->t_initiator_alias = yystack.l_mark[0].str;
	}
break;
case 29:
#line 173 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_user != NULL)
			xo_errx(1, "duplicated chapIName at line %d", lineno);
		target->t_user = yystack.l_mark[0].str;
	}
break;
case 30:
#line 181 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_secret != NULL)
			xo_errx(1, "duplicated chapSecret at line %d", lineno);
		target->t_secret = yystack.l_mark[0].str;
	}
break;
case 31:
#line 189 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_mutual_user != NULL)
			xo_errx(1, "duplicated tgtChapName at line %d", lineno);
		target->t_mutual_user = yystack.l_mark[0].str;
	}
break;
case 32:
#line 197 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_mutual_secret != NULL)
			xo_errx(1, "duplicated tgtChapSecret at line %d", lineno);
		target->t_mutual_secret = yystack.l_mark[0].str;
	}
break;
case 33:
#line 205 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_auth_method != AUTH_METHOD_UNSPECIFIED)
			xo_errx(1, "duplicated AuthMethod at line %d", lineno);
		if (strcasecmp(yystack.l_mark[0].str, "none") == 0)
			target->t_auth_method = AUTH_METHOD_NONE;
		else if (strcasecmp(yystack.l_mark[0].str, "chap") == 0)
			target->t_auth_method = AUTH_METHOD_CHAP;
		else
			xo_errx(1, "invalid AuthMethod at line %d; "
			    "must be either \"none\" or \"CHAP\"", lineno);
	}
break;
case 34:
#line 219 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_header_digest != DIGEST_UNSPECIFIED)
			xo_errx(1, "duplicated HeaderDigest at line %d", lineno);
		if (strcasecmp(yystack.l_mark[0].str, "none") == 0)
			target->t_header_digest = DIGEST_NONE;
		else if (strcasecmp(yystack.l_mark[0].str, "CRC32C") == 0)
			target->t_header_digest = DIGEST_CRC32C;
		else
			xo_errx(1, "invalid HeaderDigest at line %d; "
			    "must be either \"none\" or \"CRC32C\"", lineno);
	}
break;
case 35:
#line 233 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_data_digest != DIGEST_UNSPECIFIED)
			xo_errx(1, "duplicated DataDigest at line %d", lineno);
		if (strcasecmp(yystack.l_mark[0].str, "none") == 0)
			target->t_data_digest = DIGEST_NONE;
		else if (strcasecmp(yystack.l_mark[0].str, "CRC32C") == 0)
			target->t_data_digest = DIGEST_CRC32C;
		else
			xo_errx(1, "invalid DataDigest at line %d; "
			    "must be either \"none\" or \"CRC32C\"", lineno);
	}
break;
case 36:
#line 247 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_session_type != SESSION_TYPE_UNSPECIFIED)
			xo_errx(1, "duplicated SessionType at line %d", lineno);
		if (strcasecmp(yystack.l_mark[0].str, "normal") == 0)
			target->t_session_type = SESSION_TYPE_NORMAL;
		else if (strcasecmp(yystack.l_mark[0].str, "discovery") == 0)
			target->t_session_type = SESSION_TYPE_DISCOVERY;
		else
			xo_errx(1, "invalid SessionType at line %d; "
			    "must be either \"normal\" or \"discovery\"", lineno);
	}
break;
case 37:
#line 261 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_enable != ENABLE_UNSPECIFIED)
			xo_errx(1, "duplicated enable at line %d", lineno);
		target->t_enable = parse_enable(yystack.l_mark[0].str);
		if (target->t_enable == ENABLE_UNSPECIFIED)
			xo_errx(1, "invalid enable at line %d; "
			    "must be either \"on\" or \"off\"", lineno);
	}
break;
case 38:
#line 272 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_offload != NULL)
			xo_errx(1, "duplicated offload at line %d", lineno);
		target->t_offload = yystack.l_mark[0].str;
	}
break;
case 39:
#line 280 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		if (target->t_protocol != PROTOCOL_UNSPECIFIED)
			xo_errx(1, "duplicated protocol at line %d", lineno);
		if (strcasecmp(yystack.l_mark[0].str, "iscsi") == 0)
			target->t_protocol = PROTOCOL_ISCSI;
		else if (strcasecmp(yystack.l_mark[0].str, "iser") == 0)
			target->t_protocol = PROTOCOL_ISER;
		else
			xo_errx(1, "invalid protocol at line %d; "
			    "must be either \"iscsi\" or \"iser\"", lineno);
	}
break;
case 40:
#line 294 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.bin/iscsictl/parse.y"
	{
		xo_warnx("obsolete statement ignored at line %d", lineno);
	}
break;
#line 759 "y.tab.c"
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