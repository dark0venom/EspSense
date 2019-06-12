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

#ifndef yyparse
#define yyparse    sun_map_parse
#endif /* yyparse */

#ifndef yylex
#define yylex      sun_map_lex
#endif /* yylex */

#ifndef yyerror
#define yyerror    sun_map_error
#endif /* yyerror */

#ifndef yychar
#define yychar     sun_map_char
#endif /* yychar */

#ifndef yyval
#define yyval      sun_map_val
#endif /* yyval */

#ifndef yylval
#define yylval     sun_map_lval
#endif /* yylval */

#ifndef yydebug
#define yydebug    sun_map_debug
#endif /* yydebug */

#ifndef yynerrs
#define yynerrs    sun_map_nerrs
#endif /* yynerrs */

#ifndef yyerrflag
#define yyerrflag  sun_map_errflag
#endif /* yyerrflag */

#ifndef yylhs
#define yylhs      sun_map_lhs
#endif /* yylhs */

#ifndef yylen
#define yylen      sun_map_len
#endif /* yylen */

#ifndef yydefred
#define yydefred   sun_map_defred
#endif /* yydefred */

#ifndef yydgoto
#define yydgoto    sun_map_dgoto
#endif /* yydgoto */

#ifndef yysindex
#define yysindex   sun_map_sindex
#endif /* yysindex */

#ifndef yyrindex
#define yyrindex   sun_map_rindex
#endif /* yyrindex */

#ifndef yygindex
#define yygindex   sun_map_gindex
#endif /* yygindex */

#ifndef yytable
#define yytable    sun_map_table
#endif /* yytable */

#ifndef yycheck
#define yycheck    sun_map_check
#endif /* yycheck */

#ifndef yyname
#define yyname     sun_map_name
#endif /* yyname */

#ifndef yyrule
#define yyrule     sun_map_rule
#endif /* yyrule */
#define YYPREFIX "sun_map_"

#define YYPURE 0

#line 2 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/amd/amd/../../../contrib/amd/amd/sun_map_parse.y"
/*
 * Copyright (c) 1997-2014 Erez Zadok
 * Copyright (c) 2005 Daniel P. Ottavio
 * Copyright (c) 1990 Jan-Simon Pendry
 * Copyright (c) 1990 Imperial College of Science, Technology & Medicine
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Jan-Simon Pendry at Imperial College, London.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *
 * File: am-utils/amd/sun_map_parse.y
 *
 */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif /* HAVE_CONFIG_H */
#include <am_defs.h>
#include <amd.h>
#include <sun_map.h>


#define SUN_FSTYPE_STR  "fstype="


extern int sun_map_lex(void);
extern int sun_map_error(const char *);
extern void sun_map_tok_setbuff(const char *);
extern int sun_map_parse(void);

struct sun_entry *sun_map_parse_read(const char *);

static struct sun_list *sun_entry_list = NULL;
static struct sun_list *sun_opt_list = NULL;
static struct sun_list *sun_host_list = NULL;
static struct sun_list *sun_location_list = NULL;
static struct sun_list *mountpt_list = NULL;
static char *tmpFsType = NULL;


/*
 * Each get* function returns a pointer to the corresponding global
 * list structure.  If the structure is NULL than a new instance is
 * returned.
 */
static struct sun_list *get_sun_opt_list(void);
static struct sun_list *get_sun_host_list(void);
static struct sun_list *get_sun_location_list(void);
static struct sun_list *get_mountpt_list(void);
static struct sun_list *get_sun_entry_list(void);

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 81 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/amd/amd/../../../contrib/amd/amd/sun_map_parse.y"
typedef union {
  char strval[2048];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 190 "sun_map_parse.c"

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

#define NEWLINE 257
#define COMMENT 258
#define WSPACE 259
#define WORD 260
#define YYERRCODE 256
typedef int YYINT;
static const YYINT sun_map_lhs[] = {                     -1,
    0,    1,    1,    3,    3,    3,    2,    2,    4,    4,
    4,    4,    7,    7,    8,    8,    5,    5,    9,    9,
   10,   10,   11,   11,   12,    6,    6,   13,
};
static const YYINT sun_map_len[] = {                      2,
    1,    2,    1,    1,    2,    3,    1,    2,    1,    4,
    1,    4,    1,    3,    3,    6,    1,    3,    3,    2,
    1,    3,    1,    2,    3,    1,    3,    1,
};
static const YYINT sun_map_defred[] = {                   0,
    0,    0,    0,    0,    0,    1,    0,    3,    0,    9,
   11,    0,    0,    0,    0,    8,    0,    0,   24,   28,
    0,    0,   20,    2,    0,    0,    0,    0,    0,    0,
    0,   15,    0,    0,    0,    6,    0,   14,   18,   19,
   22,    0,   25,   10,   12,   27,    0,   16,
};
static const YYINT sun_map_dgoto[] = {                    5,
    6,    7,    8,    9,   10,   21,   11,   12,   13,   14,
   15,   19,   22,
};
static const YYINT sun_map_sindex[] = {                 -39,
 -244,  -40, -243, -234,    0,    0,  -38,    0, -244,    0,
    0, -232, -231,  -28,  -13,    0,  -37, -228,    0,    0,
 -226,  -10,    0,    0,  -38, -225,  -54, -224, -223,   -2,
 -243,    0,   -1,  -53, -243,    0, -218,    0,    0,    0,
    0, -217,    0,    0,    0,    0,  -54,    0,
};
static const YYINT sun_map_rindex[] = {                   0,
    1,  -34,    0,    0,    0,    0,    0,    0,   43,    0,
    0,    2,    3,    0,  -14,    0,    0,    0,    0,    0,
    0, -232,    0,    0,   45,    0,    0,    0,    0,  -34,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT sun_map_gindex[] = {                   0,
    0,   13,    4,    0,   -9,  -19,  -11,    0,   -8,   18,
    0,    0,    0,
};
#define YYTABLESIZE 261
static const YYINT sun_map_table[] = {                   18,
    7,   13,   17,    4,    4,    3,    3,   31,   32,   23,
   24,   42,    1,   16,   38,   46,   20,   39,    4,    4,
    4,   25,   45,   23,   44,   23,   26,   27,   36,   28,
   29,   33,   34,   35,   37,   40,   30,   18,   48,   43,
   17,   47,    4,   21,    5,    7,   41,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    7,    0,
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
    0,    0,    0,    0,    0,   30,    2,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    1,   17,    0,
    2,    2,   30,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   13,   17,
    7,
};
static const YYINT sun_map_check[] = {                   40,
    0,    0,    0,   58,   58,   45,   45,   45,   17,   44,
    7,   31,  257,    1,   26,   35,  260,   27,   58,   58,
   58,    9,   34,   58,   34,  260,  259,  259,   25,   58,
   44,  260,  259,   44,  260,  260,  260,   40,   47,   41,
  259,  259,    0,   58,    0,   45,   29,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   58,   -1,
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
   -1,   -1,   -1,   -1,   -1,  260,  260,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  259,   -1,
  260,  260,  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  257,
  260,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 260
#define YYUNDFTOKEN 276
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const sun_map_name[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','","'-'",0,0,0,0,0,0,0,0,0,0,0,0,"':'",0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NEWLINE",
"COMMENT","WSPACE","WORD",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const sun_map_rule[] = {
"$accept : amap",
"amap : file",
"file : new_lines entries",
"file : entries",
"entries : entry",
"entries : entry new_lines",
"entries : entry new_lines entries",
"new_lines : NEWLINE",
"new_lines : NEWLINE new_lines",
"entry : locations",
"entry : '-' options WSPACE locations",
"entry : mountpoints",
"entry : '-' options WSPACE mountpoints",
"mountpoints : mountpoint",
"mountpoints : mountpoint WSPACE mountpoints",
"mountpoint : WORD WSPACE location",
"mountpoint : WORD WSPACE '-' options WSPACE location",
"locations : location",
"locations : location WSPACE locations",
"location : hosts ':' WORD",
"location : ':' WORD",
"hosts : host",
"hosts : host ',' hosts",
"host : WORD",
"host : WORD weight",
"weight : '(' WORD ')'",
"options : option",
"options : option ',' options",
"option : WORD",

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
#line 404 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/amd/amd/../../../contrib/amd/amd/sun_map_parse.y"

/*
 * Parse 'map_data' which is assumed to be a Sun-syle map.  If
 * successful a sun_entry is returned.
 *
 * The parser is designed to parse map entries with out the keys.  For
 * example the entry:
 *
 * usr -ro pluto:/usr/local
 *
 * should be passed to the parser as:
 *
 * -ro pluto:/usr/local
 *
 * The reason for this is that the Amd info services already strip off
 * the key when they read map info.
 */
struct sun_entry *
sun_map_parse_read(const char *map_data)
{
  struct sun_entry *retval = NULL;

  /* pass map_data to lex */
  sun_map_tok_setbuff(map_data);

  /* call yacc */
  sun_map_parse();

  if (sun_entry_list != NULL) {
    /* return the first Sun entry in the list */
    retval = (struct sun_entry*)sun_entry_list->first;
    sun_entry_list = NULL;
  }
  else {
    plog(XLOG_ERROR, "Sun map parser did not produce data structs.");
  }

  return retval;
}


static struct sun_list *
get_sun_entry_list(void)
{
  if (sun_entry_list == NULL) {
    sun_entry_list = CALLOC(struct sun_list);
  }
  return sun_entry_list;
}


static struct sun_list *
get_mountpt_list(void)
{
  if (mountpt_list == NULL) {
    mountpt_list = CALLOC(struct sun_list);
  }
  return mountpt_list;
}


static struct sun_list *
get_sun_location_list(void)
{
  if (sun_location_list == NULL) {
    sun_location_list = CALLOC(struct sun_list);
  }
  return sun_location_list;
}


static struct sun_list *
get_sun_host_list(void)
{
  if (sun_host_list == NULL) {
    sun_host_list = CALLOC(struct sun_list);
  }
  return sun_host_list;
}


static struct sun_list *
get_sun_opt_list(void)
{
  if (sun_opt_list == NULL) {
    sun_opt_list = CALLOC(struct sun_list);
  }
  return sun_opt_list;
}
#line 503 "sun_map_parse.c"

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
case 9:
#line 106 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/amd/amd/../../../contrib/amd/amd/sun_map_parse.y"
	{

  struct sun_list *list;
  struct sun_entry *entry;

  /* allocate an entry */
  entry = CALLOC(struct sun_entry);

  /*
   * Assign the global location list to this entry and reset the
   * global pointer.  Reseting the global pointer will create a new
   * list instance next time get_sun_location_list() is called.
   */
  list = get_sun_location_list();
  entry->location_list = (struct sun_location *)list->first;
  sun_location_list = NULL;

   /* Add this entry to the entry list. */
  sun_list_add(get_sun_entry_list(), (qelem *)entry);
}
break;
case 10:
#line 127 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/amd/amd/../../../contrib/amd/amd/sun_map_parse.y"
	{

  struct sun_list *list;
  struct sun_entry *entry;

  entry = CALLOC(struct sun_entry);

  /* An fstype may have been defined in the 'options'. */
  if (tmpFsType != NULL) {
    entry->fstype = tmpFsType;
    tmpFsType = NULL;
  }

  /*
   * Assign the global location list to this entry and reset the
   * global pointer.  Reseting the global pointer will create a new
   * list instance next time get_sun_location_list() is called.
   */
  list = get_sun_location_list();
  entry->location_list = (struct sun_location *)list->first;
  sun_location_list = NULL;

  /*
   * Assign the global opt list to this entry and reset the global
   * pointer.  Reseting the global pointer will create a new list
   * instance next time get_sun_opt_list() is called.
   */
  list = get_sun_opt_list();
  entry->opt_list = (struct sun_opt *)list->first;
  sun_opt_list = NULL;

  /* Add this entry to the entry list. */
  sun_list_add(get_sun_entry_list(), (qelem *)entry);
}
break;
case 11:
#line 162 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/amd/amd/../../../contrib/amd/amd/sun_map_parse.y"
	{

  struct sun_list *list;
  struct sun_entry *entry;

  /* allocate an entry */
  entry = CALLOC(struct sun_entry);

  /*
   * Assign the global mountpt list to this entry and reset the global
   * pointer.  Reseting the global pointer will create a new list
   * instance next time get_mountpt_list() is called.
   */
  list = get_mountpt_list();
  entry->mountpt_list = (struct sun_mountpt *)list->first;
  mountpt_list = NULL;

  /* Add this entry to the entry list. */
  sun_list_add(get_sun_entry_list(), (qelem *)entry);
}
break;
case 12:
#line 183 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/amd/amd/../../../contrib/amd/amd/sun_map_parse.y"
	{

  struct sun_list *list;
  struct sun_entry *entry;

  /* allocate an entry */
  entry = CALLOC(struct sun_entry);

  /* An fstype may have been defined in the 'options'. */
  if (tmpFsType != NULL) {
    entry->fstype = tmpFsType;
    tmpFsType = NULL;
  }

  /*
   * Assign the global mountpt list to this entry and reset the global
   * pointer.  Reseting the global pointer will create a new list
   * instance next time get_mountpt_list() is called.
   */
  list = get_mountpt_list();
  entry->mountpt_list = (struct sun_mountpt *)list->first;
  mountpt_list = NULL;

  /*
   * Assign the global opt list to this entry and reset the global
   * pointer.  Reseting the global pointer will create a new list
   * instance next time get_sun_opt_list() is called.
   */
  list = get_sun_opt_list();
  entry->opt_list = (struct sun_opt *)list->first;
  sun_opt_list = NULL;

  /* Add this entry to the entry list. */
  sun_list_add(get_sun_entry_list(), (qelem *)entry);
}
break;
case 15:
#line 224 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/amd/amd/../../../contrib/amd/amd/sun_map_parse.y"
	{

  struct sun_list *list;
  struct sun_mountpt *mountpt;

  /* allocate a mountpt */
  mountpt = CALLOC(struct sun_mountpt);

  /*
   * Assign the global loaction list to this entry and reset the
   * global pointer.  Reseting the global pointer will create a new
   * list instance next time get_sun_location_list() is called.
   */
  list = get_sun_location_list();
  mountpt->location_list = (struct sun_location *)list->first;
  sun_location_list = NULL;

  mountpt->path = xstrdup(yystack.l_mark[-2].strval);

  /* Add this mountpt to the mountpt list. */
  sun_list_add(get_mountpt_list(), (qelem *)mountpt);
}
break;
case 16:
#line 247 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/amd/amd/../../../contrib/amd/amd/sun_map_parse.y"
	{

  struct sun_list *list;
  struct sun_mountpt *mountpt;

  /* allocate a mountpt */
  mountpt = CALLOC(struct sun_mountpt);

  /* An fstype may have been defined in the 'options'. */
  if (tmpFsType != NULL) {
    mountpt->fstype = tmpFsType;
    tmpFsType = NULL;
  }

  /*
   * Assign the global location list to this entry and reset the
   * global pointer.  Reseting the global pointer will create a new
   * list instance next time get_sun_location_list() is called.
   */
  list = get_sun_location_list();
  mountpt->location_list = (struct sun_location *)list->first;
  sun_location_list = NULL;

  /*
   * Assign the global opt list to this entry and reset the global
   * pointer.  Reseting the global pointer will create a new list
   * instance next time get_sun_opt_list() is called.
   */
  list = get_sun_opt_list();
  mountpt->opt_list = (struct sun_opt *)list->first;
  sun_opt_list = NULL;

  mountpt->path = xstrdup(yystack.l_mark[-5].strval);

  /* Add this mountpt to the mountpt list. */
  sun_list_add(get_mountpt_list(), (qelem *)mountpt);
}
break;
case 19:
#line 290 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/amd/amd/../../../contrib/amd/amd/sun_map_parse.y"
	{

  struct sun_list *list;
  struct sun_location *location;

  /* allocate a new location */
  location = CALLOC(struct sun_location);

  /*
   * Assign the global opt list to this entry and reset the global
   * pointer.  Reseting the global pointer will create a new list
   * instance next time get_sun_opt_list() is called.
   */
  list = get_sun_host_list();
  location->host_list = (struct sun_host *)list->first;
  sun_host_list = NULL;

  location->path = xstrdup(yystack.l_mark[0].strval);

  /* Add this location to the location list. */
  sun_list_add(get_sun_location_list(), (qelem *)location);
}
break;
case 20:
#line 313 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/amd/amd/../../../contrib/amd/amd/sun_map_parse.y"
	{

  struct sun_location *location;

  /* allocate a new location */
  location = CALLOC(struct sun_location);

  location->path = xstrdup(yystack.l_mark[0].strval);

  /* Add this location to the location list. */
  sun_list_add(get_sun_location_list(), (qelem *)location);
}
break;
case 23:
#line 331 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/amd/amd/../../../contrib/amd/amd/sun_map_parse.y"
	{

  /* allocate a new host */
  struct sun_host *host = CALLOC(struct sun_host);

  host->name = xstrdup(yystack.l_mark[0].strval);

  /* Add this host to the host list. */
  sun_list_add(get_sun_host_list(),(qelem *)host);
}
break;
case 24:
#line 342 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/amd/amd/../../../contrib/amd/amd/sun_map_parse.y"
	{

  /*
   * It is assumed that the host for this rule was allocated by the
   * 'weight' rule and assigned to be the last host item on the host
   * list.
   */
  struct sun_host *host = (struct sun_host *)sun_host_list->last;

  host->name = xstrdup(yystack.l_mark[-1].strval);
}
break;
case 25:
#line 355 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/amd/amd/../../../contrib/amd/amd/sun_map_parse.y"
	{

  int val;
  /* allocate a new host */
  struct sun_host *host = CALLOC(struct sun_host);

  val = atoi(yystack.l_mark[-1].strval);

  host->weight = val;

  /* Add this host to the host list. */
  sun_list_add(get_sun_host_list(), (qelem *)host);
}
break;
case 28:
#line 374 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/amd/amd/../../../contrib/amd/amd/sun_map_parse.y"
	{

  char *type;

  /* check if this is an fstype option */
  if ((type = strstr(yystack.l_mark[0].strval,SUN_FSTYPE_STR)) != NULL) {
    /* parse out the fs type from the Sun fstype keyword  */
    if ((type = type + strlen(SUN_FSTYPE_STR)) != NULL) {
      /*
       * This global fstype str will be assigned to the current being
       * parsed later in the parsing.
       */
      tmpFsType = xstrdup(type);
    }
  }
  else {
    /*
     * If it is not an fstype option allocate an opt struct and assign
     * the value.
     */
    struct sun_opt *opt = CALLOC(struct sun_opt);
    opt->str = xstrdup(yystack.l_mark[0].strval);
    /* Add this opt to the opt list. */
    sun_list_add(get_sun_opt_list(), (qelem *)opt);
  }
}
break;
#line 1000 "sun_map_parse.c"
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
