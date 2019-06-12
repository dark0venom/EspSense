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

#line 2 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
/*
**  Originally written by Steven M. Bellovin <smb@research.att.com> while
**  at the University of North Carolina at Chapel Hill.  Later tweaked by
**  a couple of people on Usenet.  Completely overhauled by Rich $alz
**  <rsalz@bbn.com> and Jim Berets <jberets@bbn.com> in August, 1990;
**
**  This grammar has 10 shift/reduce conflicts.
**
**  This code is in the public domain and has no copyright.
**
**  Picked up from CVS and slightly cleaned up by to WARNS=5 level by
**  Poul-Henning Kamp <phk@FreeBSD.org>
**
** $FreeBSD$
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>

#include "libfifolog.h"

#define yylex getdate_yylex
#define yyerror getdate_yyerror

static int yylex(void);
static int yyerror(const char *);

#define EPOCH		1970
#define HOUR(x)		((time_t)(x) * 60)
#define SECSPERDAY	(24L * 60L * 60L)


/*
**  An entry in the lexical lookup table.
*/
typedef struct _TABLE {
    const char	*name;
    int		type;
    time_t	value;
} TABLE;


/*
**  Daylight-savings mode:  on, off, or not yet known.
*/
typedef enum _DSTMODE {
    DSToff, DSTon, DSTmaybe
} DSTMODE;

/*
**  Meridian:  am, pm, or 24-hour style.
*/
typedef enum _MERIDIAN {
    MERam, MERpm, MER24
} MERIDIAN;


/*
**  Global variables.  We could get rid of most of these by using a good
**  union as the yacc stack.  (This routine was originally written before
**  yacc had the %union construct.)  Maybe someday; right now we only use
**  the %union very rarely.
*/
static char	*yyInput;
static DSTMODE	yyDSTmode;
static time_t	yyDayOrdinal;
static time_t	yyDayNumber;
static int	yyHaveDate;
static int	yyHaveDay;
static int	yyHaveRel;
static int	yyHaveTime;
static int	yyHaveZone;
static time_t	yyTimezone;
static time_t	yyDay;
static time_t	yyHour;
static time_t	yyMinutes;
static time_t	yyMonth;
static time_t	yySeconds;
static time_t	yyYear;
static MERIDIAN	yyMeridian;
static time_t	yyRelMonth;
static time_t	yyRelSeconds;

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 91 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
typedef union {
    time_t		Number;
    enum _MERIDIAN	Meridian;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 121 "getdate.c"

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

#define tAGO 257
#define tDAY 258
#define tDAYZONE 259
#define tID 260
#define tMERIDIAN 261
#define tMINUTE_UNIT 262
#define tMONTH 263
#define tMONTH_UNIT 264
#define tSEC_UNIT 265
#define tSNUMBER 266
#define tUNUMBER 267
#define tZONE 268
#define tDST 269
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    2,    2,    2,    2,    2,    2,    2,    8,
    3,    3,    3,    3,    3,    4,    4,    4,    6,    6,
    6,    5,    5,    5,    5,    5,    5,    5,    5,    7,
    7,   10,   10,   10,   10,   10,   10,   10,   10,   10,
    9,    1,    1,
};
static const YYINT yylen[] = {                            2,
    0,    2,    1,    1,    1,    1,    1,    1,    1,   11,
    2,    4,    4,    6,    6,    1,    1,    2,    1,    2,
    2,    3,    5,    3,    3,    2,    4,    2,    3,    2,
    1,    2,    2,    1,    2,    2,    1,    2,    2,    1,
    1,    0,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,   17,   34,    0,   40,   37,    0,    0,    0,
    2,    3,    4,    5,    6,    7,    8,    9,    0,   20,
    0,   33,   38,   35,   21,   11,   32,    0,   39,   36,
    0,    0,    0,    0,   18,   30,    0,   25,   29,   24,
    0,    0,    0,   27,    0,   43,   13,    0,   12,    0,
    0,    0,   23,    0,   15,   14,    0,    0,    0,    0,
   10,
};
static const YYINT yydgoto[] = {                          1,
   49,   11,   12,   13,   14,   15,   16,   17,   18,   19,
};
static const YYINT yysindex[] = {                         0,
 -238,  -37,    0,    0, -252,    0,    0, -254,  -44, -256,
    0,    0,    0,    0,    0,    0,    0,    0, -241,    0,
  -27,    0,    0,    0,    0,    0,    0, -261,    0,    0,
 -248, -245, -236, -235,    0,    0, -234,    0,    0,    0,
  -11,  -58,  -28,    0, -231,    0,    0, -230,    0, -229,
   -7, -257,    0, -227,    0,    0,   -5, -225,   -3, -223,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    1,    0,    0,    0,    0,    0,    0,   69,   12,
    0,    0,    0,    0,    0,    0,    0,    0,   23,    0,
   34,    0,    0,    0,    0,    0,    0,   67,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   56,   45,    0,    0,    0,    0,    0,    0,    0,
    0,   56,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
   -6,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 337
static const YYINT yytable[] = {                         48,
   19,   32,   34,   46,   38,   39,   20,   22,   55,   23,
   24,   16,   35,   33,   21,   36,   37,   40,   50,    2,
    3,   41,   31,    4,    5,    6,    7,    8,    9,   10,
   42,   43,   44,   26,   45,   51,   52,   53,   54,   57,
   58,   59,   60,   61,   22,   56,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   42,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   28,    0,   41,    0,
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
    0,    0,   46,    0,    0,    0,    0,   47,    0,    0,
    0,    0,    0,   25,    0,    0,   26,   27,   28,   29,
   30,   31,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   19,   19,
    0,    0,   19,   19,   19,   19,   19,   19,   19,   16,
   16,    0,    0,   16,   16,   16,   16,   16,   16,   16,
   31,   31,    0,    0,   31,   31,   31,   31,   31,   31,
   31,   26,   26,    0,    0,   26,   26,   26,   26,   26,
   26,   26,   22,   22,    0,    0,   22,   22,   22,   22,
   22,   22,   22,   42,   42,    0,    0,   42,   42,   42,
   42,    0,   42,   42,   28,   28,    0,   41,   28,   28,
   28,   28,    0,    0,   28,   41,   41,
};
static const YYINT yycheck[] = {                         58,
    0,   46,   47,  261,  266,  267,   44,  262,  266,  264,
  265,    0,  269,   58,  267,  257,   44,  266,   47,  258,
  259,  267,    0,  262,  263,  264,  265,  266,  267,  268,
  267,  267,  267,    0,   46,  267,  267,  267,   46,  267,
   46,  267,   46,  267,    0,   52,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,    0,   -1,
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
   -1,   -1,  261,   -1,   -1,   -1,   -1,  266,   -1,   -1,
   -1,   -1,   -1,  258,   -1,   -1,  261,  262,  263,  264,
  265,  266,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  258,  259,
   -1,   -1,  262,  263,  264,  265,  266,  267,  268,  258,
  259,   -1,   -1,  262,  263,  264,  265,  266,  267,  268,
  258,  259,   -1,   -1,  262,  263,  264,  265,  266,  267,
  268,  258,  259,   -1,   -1,  262,  263,  264,  265,  266,
  267,  268,  258,  259,   -1,   -1,  262,  263,  264,  265,
  266,  267,  268,  258,  259,   -1,   -1,  262,  263,  264,
  265,   -1,  267,  268,  258,  259,   -1,  259,  262,  263,
  264,  265,   -1,   -1,  268,  267,  268,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 269
#define YYUNDFTOKEN 282
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"','",0,"'.'","'/'",0,0,0,0,0,0,0,0,0,0,"':'",0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tAGO","tDAY",
"tDAYZONE","tID","tMERIDIAN","tMINUTE_UNIT","tMONTH","tMONTH_UNIT","tSEC_UNIT",
"tSNUMBER","tUNUMBER","tZONE","tDST",0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : spec",
"spec :",
"spec : spec item",
"item : time",
"item : zone",
"item : date",
"item : day",
"item : rel",
"item : cvsstamp",
"item : number",
"cvsstamp : tUNUMBER '.' tUNUMBER '.' tUNUMBER '.' tUNUMBER '.' tUNUMBER '.' tUNUMBER",
"time : tUNUMBER tMERIDIAN",
"time : tUNUMBER ':' tUNUMBER o_merid",
"time : tUNUMBER ':' tUNUMBER tSNUMBER",
"time : tUNUMBER ':' tUNUMBER ':' tUNUMBER o_merid",
"time : tUNUMBER ':' tUNUMBER ':' tUNUMBER tSNUMBER",
"zone : tZONE",
"zone : tDAYZONE",
"zone : tZONE tDST",
"day : tDAY",
"day : tDAY ','",
"day : tUNUMBER tDAY",
"date : tUNUMBER '/' tUNUMBER",
"date : tUNUMBER '/' tUNUMBER '/' tUNUMBER",
"date : tUNUMBER tSNUMBER tSNUMBER",
"date : tUNUMBER tMONTH tSNUMBER",
"date : tMONTH tUNUMBER",
"date : tMONTH tUNUMBER ',' tUNUMBER",
"date : tUNUMBER tMONTH",
"date : tUNUMBER tMONTH tUNUMBER",
"rel : relunit tAGO",
"rel : relunit",
"relunit : tUNUMBER tMINUTE_UNIT",
"relunit : tSNUMBER tMINUTE_UNIT",
"relunit : tMINUTE_UNIT",
"relunit : tSNUMBER tSEC_UNIT",
"relunit : tUNUMBER tSEC_UNIT",
"relunit : tSEC_UNIT",
"relunit : tSNUMBER tMONTH_UNIT",
"relunit : tUNUMBER tMONTH_UNIT",
"relunit : tMONTH_UNIT",
"number : tUNUMBER",
"o_merid :",
"o_merid : tMERIDIAN",

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
#line 328 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"

/* Month and day table. */
static TABLE const MonthDayTable[] = {
    { "january",	tMONTH,  1 },
    { "february",	tMONTH,  2 },
    { "march",		tMONTH,  3 },
    { "april",		tMONTH,  4 },
    { "may",		tMONTH,  5 },
    { "june",		tMONTH,  6 },
    { "july",		tMONTH,  7 },
    { "august",		tMONTH,  8 },
    { "september",	tMONTH,  9 },
    { "sept",		tMONTH,  9 },
    { "october",	tMONTH, 10 },
    { "november",	tMONTH, 11 },
    { "december",	tMONTH, 12 },
    { "sunday",		tDAY, 0 },
    { "monday",		tDAY, 1 },
    { "tuesday",	tDAY, 2 },
    { "tues",		tDAY, 2 },
    { "wednesday",	tDAY, 3 },
    { "wednes",		tDAY, 3 },
    { "thursday",	tDAY, 4 },
    { "thur",		tDAY, 4 },
    { "thurs",		tDAY, 4 },
    { "friday",		tDAY, 5 },
    { "saturday",	tDAY, 6 },
    { NULL,		0,    0 }
};

/* Time units table. */
static TABLE const UnitsTable[] = {
    { "year",		tMONTH_UNIT,	12 },
    { "month",		tMONTH_UNIT,	1 },
    { "fortnight",	tMINUTE_UNIT,	14 * 24 * 60 },
    { "week",		tMINUTE_UNIT,	7 * 24 * 60 },
    { "day",		tMINUTE_UNIT,	1 * 24 * 60 },
    { "hour",		tMINUTE_UNIT,	60 },
    { "minute",		tMINUTE_UNIT,	1 },
    { "min",		tMINUTE_UNIT,	1 },
    { "second",		tSEC_UNIT,	1 },
    { "sec",		tSEC_UNIT,	1 },
    { NULL,		0,		0 }
};

/* Assorted relative-time words. */
static TABLE const OtherTable[] = {
    { "tomorrow",	tMINUTE_UNIT,	1 * 24 * 60 },
    { "yesterday",	tMINUTE_UNIT,	-1 * 24 * 60 },
    { "today",		tMINUTE_UNIT,	0 },
    { "now",		tMINUTE_UNIT,	0 },
    { "last",		tUNUMBER,	-1 },
    { "this",		tMINUTE_UNIT,	0 },
    { "next",		tUNUMBER,	2 },
    { "first",		tUNUMBER,	1 },
/*  { "second",		tUNUMBER,	2 }, */
    { "third",		tUNUMBER,	3 },
    { "fourth",		tUNUMBER,	4 },
    { "fifth",		tUNUMBER,	5 },
    { "sixth",		tUNUMBER,	6 },
    { "seventh",	tUNUMBER,	7 },
    { "eighth",		tUNUMBER,	8 },
    { "ninth",		tUNUMBER,	9 },
    { "tenth",		tUNUMBER,	10 },
    { "eleventh",	tUNUMBER,	11 },
    { "twelfth",	tUNUMBER,	12 },
    { "ago",		tAGO,		1 },
    { NULL,		0,		0 }
};

/* The timezone table. */
/* Some of these are commented out because a time_t can't store a float. */
static TABLE const TimezoneTable[] = {
    { "gmt",	tZONE,     HOUR( 0) },	/* Greenwich Mean */
    { "ut",	tZONE,     HOUR( 0) },	/* Universal (Coordinated) */
    { "utc",	tZONE,     HOUR( 0) },
    { "wet",	tZONE,     HOUR( 0) },	/* Western European */
    { "bst",	tDAYZONE,  HOUR( 0) },	/* British Summer */
    { "wat",	tZONE,     HOUR( 1) },	/* West Africa */
    { "at",	tZONE,     HOUR( 2) },	/* Azores */
#if	0
    /* For completeness.  BST is also British Summer, and GST is
     * also Guam Standard. */
    { "bst",	tZONE,     HOUR( 3) },	/* Brazil Standard */
    { "gst",	tZONE,     HOUR( 3) },	/* Greenland Standard */
#endif
#if 0
    { "nft",	tZONE,     HOUR(3.5) },	/* Newfoundland */
    { "nst",	tZONE,     HOUR(3.5) },	/* Newfoundland Standard */
    { "ndt",	tDAYZONE,  HOUR(3.5) },	/* Newfoundland Daylight */
#endif
    { "ast",	tZONE,     HOUR( 4) },	/* Atlantic Standard */
    { "adt",	tDAYZONE,  HOUR( 4) },	/* Atlantic Daylight */
    { "est",	tZONE,     HOUR( 5) },	/* Eastern Standard */
    { "edt",	tDAYZONE,  HOUR( 5) },	/* Eastern Daylight */
    { "cst",	tZONE,     HOUR( 6) },	/* Central Standard */
    { "cdt",	tDAYZONE,  HOUR( 6) },	/* Central Daylight */
    { "mst",	tZONE,     HOUR( 7) },	/* Mountain Standard */
    { "mdt",	tDAYZONE,  HOUR( 7) },	/* Mountain Daylight */
    { "pst",	tZONE,     HOUR( 8) },	/* Pacific Standard */
    { "pdt",	tDAYZONE,  HOUR( 8) },	/* Pacific Daylight */
    { "yst",	tZONE,     HOUR( 9) },	/* Yukon Standard */
    { "ydt",	tDAYZONE,  HOUR( 9) },	/* Yukon Daylight */
    { "hst",	tZONE,     HOUR(10) },	/* Hawaii Standard */
    { "hdt",	tDAYZONE,  HOUR(10) },	/* Hawaii Daylight */
    { "cat",	tZONE,     HOUR(10) },	/* Central Alaska */
    { "ahst",	tZONE,     HOUR(10) },	/* Alaska-Hawaii Standard */
    { "nt",	tZONE,     HOUR(11) },	/* Nome */
    { "idlw",	tZONE,     HOUR(12) },	/* International Date Line West */
    { "cet",	tZONE,     -HOUR(1) },	/* Central European */
    { "met",	tZONE,     -HOUR(1) },	/* Middle European */
    { "mewt",	tZONE,     -HOUR(1) },	/* Middle European Winter */
    { "mest",	tDAYZONE,  -HOUR(1) },	/* Middle European Summer */
    { "swt",	tZONE,     -HOUR(1) },	/* Swedish Winter */
    { "sst",	tDAYZONE,  -HOUR(1) },	/* Swedish Summer */
    { "fwt",	tZONE,     -HOUR(1) },	/* French Winter */
    { "fst",	tDAYZONE,  -HOUR(1) },	/* French Summer */
    { "eet",	tZONE,     -HOUR(2) },	/* Eastern Europe, USSR Zone 1 */
    { "bt",	tZONE,     -HOUR(3) },	/* Baghdad, USSR Zone 2 */
#if 0
    { "it",	tZONE,     -HOUR(3.5) },/* Iran */
#endif
    { "zp4",	tZONE,     -HOUR(4) },	/* USSR Zone 3 */
    { "zp5",	tZONE,     -HOUR(5) },	/* USSR Zone 4 */
#if 0
    { "ist",	tZONE,     -HOUR(5.5) },/* Indian Standard */
#endif
    { "zp6",	tZONE,     -HOUR(6) },	/* USSR Zone 5 */
#if	0
    /* For completeness.  NST is also Newfoundland Stanard, and SST is
     * also Swedish Summer. */
    { "nst",	tZONE,     -HOUR(6.5) },/* North Sumatra */
    { "sst",	tZONE,     -HOUR(7) },	/* South Sumatra, USSR Zone 6 */
#endif	/* 0 */
    { "wast",	tZONE,     -HOUR(7) },	/* West Australian Standard */
    { "wadt",	tDAYZONE,  -HOUR(7) },	/* West Australian Daylight */
#if 0
    { "jt",	tZONE,     -HOUR(7.5) },/* Java (3pm in Cronusland!) */
#endif
    { "cct",	tZONE,     -HOUR(8) },	/* China Coast, USSR Zone 7 */
    { "jst",	tZONE,     -HOUR(9) },	/* Japan Standard, USSR Zone 8 */
#if 0
    { "cast",	tZONE,     -HOUR(9.5) },/* Central Australian Standard */
    { "cadt",	tDAYZONE,  -HOUR(9.5) },/* Central Australian Daylight */
#endif
    { "east",	tZONE,     -HOUR(10) },	/* Eastern Australian Standard */
    { "eadt",	tDAYZONE,  -HOUR(10) },	/* Eastern Australian Daylight */
    { "gst",	tZONE,     -HOUR(10) },	/* Guam Standard, USSR Zone 9 */
    { "nzt",	tZONE,     -HOUR(12) },	/* New Zealand */
    { "nzst",	tZONE,     -HOUR(12) },	/* New Zealand Standard */
    { "nzdt",	tDAYZONE,  -HOUR(12) },	/* New Zealand Daylight */
    { "idle",	tZONE,     -HOUR(12) },	/* International Date Line East */
    {  NULL,	0,	   0 }
};

/* Military timezone table. */
static TABLE const MilitaryTable[] = {
    { "a",	tZONE,	HOUR(  1) },
    { "b",	tZONE,	HOUR(  2) },
    { "c",	tZONE,	HOUR(  3) },
    { "d",	tZONE,	HOUR(  4) },
    { "e",	tZONE,	HOUR(  5) },
    { "f",	tZONE,	HOUR(  6) },
    { "g",	tZONE,	HOUR(  7) },
    { "h",	tZONE,	HOUR(  8) },
    { "i",	tZONE,	HOUR(  9) },
    { "k",	tZONE,	HOUR( 10) },
    { "l",	tZONE,	HOUR( 11) },
    { "m",	tZONE,	HOUR( 12) },
    { "n",	tZONE,	HOUR(- 1) },
    { "o",	tZONE,	HOUR(- 2) },
    { "p",	tZONE,	HOUR(- 3) },
    { "q",	tZONE,	HOUR(- 4) },
    { "r",	tZONE,	HOUR(- 5) },
    { "s",	tZONE,	HOUR(- 6) },
    { "t",	tZONE,	HOUR(- 7) },
    { "u",	tZONE,	HOUR(- 8) },
    { "v",	tZONE,	HOUR(- 9) },
    { "w",	tZONE,	HOUR(-10) },
    { "x",	tZONE,	HOUR(-11) },
    { "y",	tZONE,	HOUR(-12) },
    { "z",	tZONE,	HOUR(  0) },
    { NULL,	0,  0 }
};




/* ARGSUSED */
static int
yyerror(const char *s __unused)
{
  return 0;
}


static time_t
ToSeconds(time_t Hours, time_t Minutes, time_t Seconds, MERIDIAN Meridian)
{
    if (Minutes < 0 || Minutes > 59 || Seconds < 0 || Seconds > 59)
	return -1;
    switch (Meridian) {
    case MER24:
	if (Hours < 0 || Hours > 23)
	    return -1;
	return (Hours * 60L + Minutes) * 60L + Seconds;
    case MERam:
	if (Hours < 1 || Hours > 12)
	    return -1;
	if (Hours == 12)
	    Hours = 0;
	return (Hours * 60L + Minutes) * 60L + Seconds;
    case MERpm:
	if (Hours < 1 || Hours > 12)
	    return -1;
	if (Hours == 12)
	    Hours = 0;
	return ((Hours + 12) * 60L + Minutes) * 60L + Seconds;
    default:
	abort ();
    }
    /* NOTREACHED */
}


/* Year is either
   * A negative number, which means to use its absolute value (why?)
   * A number from 0 to 99, which means a year from 1900 to 1999, or
   * The actual year (>=100).  */
static time_t
Convert(time_t Month, time_t Day, time_t Year,
    time_t Hours, time_t Minutes, time_t Seconds,
    MERIDIAN Meridian, DSTMODE DSTmode)
{
    static int DaysInMonth[12] = {
	31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    time_t	tod;
    time_t	Julian;
    int		i;
    struct tm   *ltm;

    if (Year < 0)
	Year = -Year;
    if (Year < 69)
	Year += 2000;
    else if (Year < 100)
	Year += 1900;
    DaysInMonth[1] = Year % 4 == 0 && (Year % 100 != 0 || Year % 400 == 0)
		    ? 29 : 28;
    /* Checking for 2038 bogusly assumes that time_t is 32 bits.  But
       I'm too lazy to try to check for time_t overflow in another way.  */
    if (Year < EPOCH || Year > 2038
     || Month < 1 || Month > 12
     /* Lint fluff:  "conversion from long may lose accuracy" */
     || Day < 1 || Day > DaysInMonth[(int)--Month])
	/* FIXME:
	 * It would be nice to set a global error string here.
	 * "February 30 is not a valid date" is much more informative than
	 * "Can't parse date/time: 100 months" when the user input was
	 * "100 months" and addition resolved that to February 30, for
	 * example.  See rcs2-7 in src/sanity.sh for more. */
	return -1;

    for (Julian = Day - 1, i = 0; i < Month; i++)
	Julian += DaysInMonth[i];
    for (i = EPOCH; i < Year; i++)
	Julian += 365 + (i % 4 == 0);
    Julian *= SECSPERDAY;
    Julian += yyTimezone * 60L;
    if ((tod = ToSeconds(Hours, Minutes, Seconds, Meridian)) < 0)
	return -1;
    Julian += tod;
    ltm = localtime(&Julian);
fprintf(stderr, "DST %d TZ %s %d\n", DSTmode, ltm->tm_zone, ltm->tm_isdst);
    if (DSTmode == DSTon
     || (DSTmode == DSTmaybe && localtime(&Julian)->tm_isdst))
	Julian -= 60 * 60;
    return Julian;
}


static time_t
DSTcorrect(time_t Start, time_t Future)
{
    time_t	StartDay;
    time_t	FutureDay;

    StartDay = (localtime(&Start)->tm_hour + 1) % 24;
    FutureDay = (localtime(&Future)->tm_hour + 1) % 24;
    return (Future - Start) + (StartDay - FutureDay) * 60L * 60L;
}


static time_t
RelativeDate(time_t Start, time_t DayOrdinal, time_t DayNumber)
{
    struct tm	*tm;
    time_t	now;

    now = Start;
    tm = localtime(&now);
    now += SECSPERDAY * ((DayNumber - tm->tm_wday + 7) % 7);
    now += 7 * SECSPERDAY * (DayOrdinal <= 0 ? DayOrdinal : DayOrdinal - 1);
    return DSTcorrect(Start, now);
}


static time_t
RelativeMonth(time_t Start, time_t RelMonth)
{
    struct tm	*tm;
    time_t	Month;
    time_t	Year;

    if (RelMonth == 0)
	return 0;
    tm = localtime(&Start);
    Month = 12 * (tm->tm_year + 1900) + tm->tm_mon + RelMonth;
    Year = Month / 12;
    Month = Month % 12 + 1;
    return DSTcorrect(Start,
	    Convert(Month, (time_t)tm->tm_mday, Year,
		(time_t)tm->tm_hour, (time_t)tm->tm_min, (time_t)tm->tm_sec,
		MER24, DSTmaybe));
}


static int
LookupWord(char *buff)
{
    char	*p;
    char	*q;
    const TABLE	*tp;
    int			i;
    int			abbrev;

    /* Make it lowercase. */
    for (p = buff; *p; p++)
	if (isupper(*p))
	    *p = tolower(*p);

    if (strcmp(buff, "am") == 0 || strcmp(buff, "a.m.") == 0) {
	yylval.Meridian = MERam;
	return tMERIDIAN;
    }
    if (strcmp(buff, "pm") == 0 || strcmp(buff, "p.m.") == 0) {
	yylval.Meridian = MERpm;
	return tMERIDIAN;
    }

    /* See if we have an abbreviation for a month. */
    if (strlen(buff) == 3)
	abbrev = 1;
    else if (strlen(buff) == 4 && buff[3] == '.') {
	abbrev = 1;
	buff[3] = '\0';
    }
    else
	abbrev = 0;

    for (tp = MonthDayTable; tp->name; tp++) {
	if (abbrev) {
	    if (strncmp(buff, tp->name, 3) == 0) {
		yylval.Number = tp->value;
		return tp->type;
	    }
	}
	else if (strcmp(buff, tp->name) == 0) {
	    yylval.Number = tp->value;
	    return tp->type;
	}
    }

    for (tp = TimezoneTable; tp->name; tp++)
	if (strcmp(buff, tp->name) == 0) {
	    yylval.Number = tp->value;
	    return tp->type;
	}

    if (strcmp(buff, "dst") == 0) 
	return tDST;

    for (tp = UnitsTable; tp->name; tp++)
	if (strcmp(buff, tp->name) == 0) {
	    yylval.Number = tp->value;
	    return tp->type;
	}

    /* Strip off any plural and try the units table again. */
    i = strlen(buff) - 1;
    if (buff[i] == 's') {
	buff[i] = '\0';
	for (tp = UnitsTable; tp->name; tp++)
	    if (strcmp(buff, tp->name) == 0) {
		yylval.Number = tp->value;
		return tp->type;
	    }
	buff[i] = 's';		/* Put back for "this" in OtherTable. */
    }

    for (tp = OtherTable; tp->name; tp++)
	if (strcmp(buff, tp->name) == 0) {
	    yylval.Number = tp->value;
	    return tp->type;
	}

    /* Military timezones. */
    if (buff[1] == '\0' && isalpha(*buff)) {
	for (tp = MilitaryTable; tp->name; tp++)
	    if (strcmp(buff, tp->name) == 0) {
		yylval.Number = tp->value;
		return tp->type;
	    }
    }

    /* Drop out any periods and try the timezone table again. */
    for (i = 0, p = q = buff; *q; q++)
	if (*q != '.')
	    *p++ = *q;
	else
	    i++;
    *p = '\0';
    if (i)
	for (tp = TimezoneTable; tp->name; tp++)
	    if (strcmp(buff, tp->name) == 0) {
		yylval.Number = tp->value;
		return tp->type;
	    }

    return tID;
}


static int
yylex(void)
{
    char	c;
    char	*p;
    char		buff[20];
    int			Count;
    int			sign;

    for ( ; ; ) {
	while (isspace(*yyInput))
	    yyInput++;

	if (isdigit(c = *yyInput) || c == '-' || c == '+') {
	    if (c == '-' || c == '+') {
		sign = c == '-' ? -1 : 1;
		if (!isdigit(*++yyInput))
		    /* skip the '-' sign */
		    continue;
	    }
	    else
		sign = 0;
	    for (yylval.Number = 0; isdigit(c = *yyInput++); )
		yylval.Number = 10 * yylval.Number + c - '0';
	    yyInput--;
	    if (sign < 0)
		yylval.Number = -yylval.Number;
	    return sign ? tSNUMBER : tUNUMBER;
	}
	if (isalpha(c)) {
	    for (p = buff; isalpha(c = *yyInput++) || c == '.'; )
		if (p < &buff[sizeof buff - 1])
		    *p++ = c;
	    *p = '\0';
	    yyInput--;
	    return LookupWord(buff);
	}
	if (c != '(')
	    return *yyInput++;
	Count = 0;
	do {
	    c = *yyInput++;
	    if (c == '\0')
		return c;
	    if (c == '(')
		Count++;
	    else if (c == ')')
		Count--;
	} while (Count > 0);
    }
}

#define TM_YEAR_ORIGIN 1900

time_t
get_date(char *p)
{
    struct tm		*tm, gmt;
    time_t		Start;
    time_t		tod;
    time_t nowtime;
    struct tm *gmt_ptr;

    yyInput = p;

    (void)time (&nowtime);

    gmt_ptr = gmtime (&nowtime);
    if (gmt_ptr != NULL)
    {
	/* Make a copy, in case localtime modifies *tm (I think
	   that comment now applies to *gmt_ptr, but I am too
	   lazy to dig into how gmtime and locatime allocate the
	   structures they return pointers to).  */
	gmt = *gmt_ptr;
    }

    if (! (tm = localtime (&nowtime)))
	return -1;

    tm = localtime(&nowtime);
    yyYear = tm->tm_year + 1900;
    yyMonth = tm->tm_mon + 1;
    yyDay = tm->tm_mday;
    yyTimezone = tm->tm_gmtoff;
    yyDSTmode = DSTmaybe;
    yyHour = 0;
    yyMinutes = 0;
    yySeconds = 0;
    yyMeridian = MER24;
    yyRelSeconds = 0;
    yyRelMonth = 0;
    yyHaveDate = 0;
    yyHaveDay = 0;
    yyHaveRel = 0;
    yyHaveTime = 0;
    yyHaveZone = 0;

    if (yyparse()
     || yyHaveTime > 1 || yyHaveZone > 1 || yyHaveDate > 1 || yyHaveDay > 1)
	return -1;

    if (yyHaveDate || yyHaveTime || yyHaveDay) {
	Start = Convert(yyMonth, yyDay, yyYear, yyHour, yyMinutes, yySeconds,
		    yyMeridian, yyDSTmode);
	if (Start < 0)
	    return -1;
    }
    else {
	Start = nowtime;
	if (!yyHaveRel)
	    Start -= ((tm->tm_hour * 60L + tm->tm_min) * 60L) + tm->tm_sec;
    }

    Start += yyRelSeconds;
    Start += RelativeMonth(Start, yyRelMonth);

    if (yyHaveDay && !yyHaveDate) {
	tod = RelativeDate(Start, yyDayOrdinal, yyDayNumber);
	Start += tod;
    }

    /* Have to do *something* with a legitimate -1 so it's distinguishable
     * from the error return value.  (Alternately could set errno on error.) */
    return Start == -1 ? 0 : Start;
}
#line 952 "getdate.c"

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
#line 109 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyHaveTime++;
	}
break;
case 4:
#line 112 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyHaveZone++;
	}
break;
case 5:
#line 115 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyHaveDate++;
	}
break;
case 6:
#line 118 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyHaveDay++;
	}
break;
case 7:
#line 121 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyHaveRel++;
	}
break;
case 8:
#line 124 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyHaveTime++;
	    yyHaveDate++;
	    yyHaveZone++;
	}
break;
case 10:
#line 132 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyYear = yystack.l_mark[-10].Number;
	    if (yyYear < 100) yyYear += 1900;
	    yyMonth = yystack.l_mark[-8].Number;
	    yyDay = yystack.l_mark[-6].Number;
	    yyHour = yystack.l_mark[-4].Number;
	    yyMinutes = yystack.l_mark[-2].Number;
	    yySeconds = yystack.l_mark[0].Number;
	    yyDSTmode = DSToff;
	    yyTimezone = 0;
	}
break;
case 11:
#line 145 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyHour = yystack.l_mark[-1].Number;
	    yyMinutes = 0;
	    yySeconds = 0;
	    yyMeridian = yystack.l_mark[0].Meridian;
	}
break;
case 12:
#line 151 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyHour = yystack.l_mark[-3].Number;
	    yyMinutes = yystack.l_mark[-1].Number;
	    yySeconds = 0;
	    yyMeridian = yystack.l_mark[0].Meridian;
	}
break;
case 13:
#line 157 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyHour = yystack.l_mark[-3].Number;
	    yyMinutes = yystack.l_mark[-1].Number;
	    yyMeridian = MER24;
	    yyDSTmode = DSToff;
	    yyTimezone = - (yystack.l_mark[0].Number % 100 + (yystack.l_mark[0].Number / 100) * 60);
	}
break;
case 14:
#line 164 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyHour = yystack.l_mark[-5].Number;
	    yyMinutes = yystack.l_mark[-3].Number;
	    yySeconds = yystack.l_mark[-1].Number;
	    yyMeridian = yystack.l_mark[0].Meridian;
	}
break;
case 15:
#line 170 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyHour = yystack.l_mark[-5].Number;
	    yyMinutes = yystack.l_mark[-3].Number;
	    yySeconds = yystack.l_mark[-1].Number;
	    yyMeridian = MER24;
	    yyDSTmode = DSToff;
	    yyTimezone = - (yystack.l_mark[0].Number % 100 + (yystack.l_mark[0].Number / 100) * 60);
	}
break;
case 16:
#line 180 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyTimezone = yystack.l_mark[0].Number;
	    yyDSTmode = DSToff;
	}
break;
case 17:
#line 184 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyTimezone = yystack.l_mark[0].Number;
	    yyDSTmode = DSTon;
	}
break;
case 18:
#line 189 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyTimezone = yystack.l_mark[-1].Number;
	    yyDSTmode = DSTon;
	}
break;
case 19:
#line 195 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyDayOrdinal = 1;
	    yyDayNumber = yystack.l_mark[0].Number;
	}
break;
case 20:
#line 199 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyDayOrdinal = 1;
	    yyDayNumber = yystack.l_mark[-1].Number;
	}
break;
case 21:
#line 203 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyDayOrdinal = yystack.l_mark[-1].Number;
	    yyDayNumber = yystack.l_mark[0].Number;
	}
break;
case 22:
#line 209 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyMonth = yystack.l_mark[-2].Number;
	    yyDay = yystack.l_mark[0].Number;
	}
break;
case 23:
#line 213 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    if (yystack.l_mark[-4].Number >= 100) {
		yyYear = yystack.l_mark[-4].Number;
		yyMonth = yystack.l_mark[-2].Number;
		yyDay = yystack.l_mark[0].Number;
	    } else {
		yyMonth = yystack.l_mark[-4].Number;
		yyDay = yystack.l_mark[-2].Number;
		yyYear = yystack.l_mark[0].Number;
	    }
	}
break;
case 24:
#line 224 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    /* ISO 8601 format.  yyyy-mm-dd.  */
	    yyYear = yystack.l_mark[-2].Number;
	    yyMonth = -yystack.l_mark[-1].Number;
	    yyDay = -yystack.l_mark[0].Number;
	}
break;
case 25:
#line 230 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    /* e.g. 17-JUN-1992.  */
	    yyDay = yystack.l_mark[-2].Number;
	    yyMonth = yystack.l_mark[-1].Number;
	    yyYear = -yystack.l_mark[0].Number;
	}
break;
case 26:
#line 236 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyMonth = yystack.l_mark[-1].Number;
	    yyDay = yystack.l_mark[0].Number;
	}
break;
case 27:
#line 240 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyMonth = yystack.l_mark[-3].Number;
	    yyDay = yystack.l_mark[-2].Number;
	    yyYear = yystack.l_mark[0].Number;
	}
break;
case 28:
#line 245 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyMonth = yystack.l_mark[0].Number;
	    yyDay = yystack.l_mark[-1].Number;
	}
break;
case 29:
#line 249 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyMonth = yystack.l_mark[-1].Number;
	    yyDay = yystack.l_mark[-2].Number;
	    yyYear = yystack.l_mark[0].Number;
	}
break;
case 30:
#line 256 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyRelSeconds = -yyRelSeconds;
	    yyRelMonth = -yyRelMonth;
	}
break;
case 32:
#line 263 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyRelSeconds += yystack.l_mark[-1].Number * yystack.l_mark[0].Number * 60L;
	}
break;
case 33:
#line 266 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyRelSeconds += yystack.l_mark[-1].Number * yystack.l_mark[0].Number * 60L;
	}
break;
case 34:
#line 269 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyRelSeconds += yystack.l_mark[0].Number * 60L;
	}
break;
case 35:
#line 272 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyRelSeconds += yystack.l_mark[-1].Number;
	}
break;
case 36:
#line 275 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyRelSeconds += yystack.l_mark[-1].Number;
	}
break;
case 37:
#line 278 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyRelSeconds++;
	}
break;
case 38:
#line 281 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyRelMonth += yystack.l_mark[-1].Number * yystack.l_mark[0].Number;
	}
break;
case 39:
#line 284 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyRelMonth += yystack.l_mark[-1].Number * yystack.l_mark[0].Number;
	}
break;
case 40:
#line 287 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyRelMonth += yystack.l_mark[0].Number;
	}
break;
case 41:
#line 292 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    if (yyHaveTime && yyHaveDate && !yyHaveRel)
		yyYear = yystack.l_mark[0].Number;
	    else {
		if(yystack.l_mark[0].Number>10000) {
		    yyHaveDate++;
		    yyDay= (yystack.l_mark[0].Number)%100;
		    yyMonth= (yystack.l_mark[0].Number/100)%100;
		    yyYear = yystack.l_mark[0].Number/10000;
		}
		else {
		    yyHaveTime++;
		    if (yystack.l_mark[0].Number < 100) {
			yyHour = yystack.l_mark[0].Number;
			yyMinutes = 0;
		    }
		    else {
		    	yyHour = yystack.l_mark[0].Number / 100;
		    	yyMinutes = yystack.l_mark[0].Number % 100;
		    }
		    yySeconds = 0;
		    yyMeridian = MER24;
	        }
	    }
	}
break;
case 42:
#line 319 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyval.Meridian = MER24;
	}
break;
case 43:
#line 322 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/fifolog/lib/getdate.y"
	{
	    yyval.Meridian = yystack.l_mark[0].Meridian;
	}
break;
#line 1463 "getdate.c"
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