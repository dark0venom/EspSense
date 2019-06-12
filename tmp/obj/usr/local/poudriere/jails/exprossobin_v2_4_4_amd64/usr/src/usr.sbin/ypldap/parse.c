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

#line 28 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
#include <sys/types.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/queue.h>
#include <sys/tree.h>
#include <sys/socket.h>
#include <sys/stat.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <event.h>
#include <fcntl.h>
#include <limits.h>
#include <netdb.h>
#include <pwd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>

#include "ypldap.h"

TAILQ_HEAD(files, file)		 files = TAILQ_HEAD_INITIALIZER(files);
static struct file {
	TAILQ_ENTRY(file)	 entry;
	FILE			*stream;
	char			*name;
	int			 lineno;
	int			 errors;
} *file, *topfile;
struct file	*pushfile(const char *, int);
int		 popfile(void);
int		 check_file_secrecy(int, const char *);
int		 yyparse(void);
int		 yylex(void);
int		 yyerror(const char *, ...)
    __attribute__((__format__ (printf, 1, 2)))
    __attribute__((__nonnull__ (1)));
int		 kw_cmp(const void *, const void *);
int		 lookup(char *);
int		 lgetc(int);
int		 lungetc(int);
int		 findeol(void);

TAILQ_HEAD(symhead, sym)	 symhead = TAILQ_HEAD_INITIALIZER(symhead);
struct sym {
	TAILQ_ENTRY(sym)	 entry;
	int			 used;
	int			 persist;
	char			*nam;
	char			*val;
};
int		 symset(const char *, const char *, int);
char		*symget(const char *);

struct env		*conf = NULL;
struct idm		*idm = NULL;
static int		 errors = 0;

typedef struct {
	union {
		int64_t		 number;
		char		*string;
	} v;
	int lineno;
} YYSTYPE;

#line 95 "parse.c"

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

#define SERVER 257
#define FILTER 258
#define ATTRIBUTE 259
#define BASEDN 260
#define BINDDN 261
#define GROUPDN 262
#define BINDCRED 263
#define MAPS 264
#define CHANGE 265
#define DOMAIN 266
#define PROVIDE 267
#define USER 268
#define GROUP 269
#define TO 270
#define EXPIRE 271
#define HOME 272
#define SHELL 273
#define GECOS 274
#define UID 275
#define GID 276
#define INTERVAL 277
#define PASSWD 278
#define NAME 279
#define FIXED 280
#define LIST 281
#define GROUPNAME 282
#define GROUPPASSWD 283
#define GROUPGID 284
#define MAP 285
#define INCLUDE 286
#define DIRECTORY 287
#define CLASS 288
#define PORT 289
#define ERROR 290
#define GROUPMEMBERS 291
#define STRING 292
#define NUMBER 293
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,    0,    8,    9,    9,
    4,    5,    3,    3,    1,    1,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
   10,   10,   10,   10,   10,   10,   10,   10,   11,    6,
    7,    7,    7,   12,   12,
};
static const YYINT yylen[] = {                            2,
    0,    2,    3,    3,    3,    3,    3,    2,    2,    0,
    2,    3,    0,    2,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    2,    2,    2,    2,    3,    5,    4,    5,    0,    8,
    2,    2,    3,    3,    2,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0,    2,    0,
    0,    0,    0,    7,   42,    0,   41,   11,    0,    0,
    3,    4,    5,    6,   43,    0,   39,   12,   14,    0,
    0,    0,    0,    9,    0,    0,    0,    0,    0,   15,
   16,    0,    0,    0,    0,    0,   22,   23,   25,   26,
   24,   19,   20,   18,   17,   27,   28,   29,   21,   30,
    0,   33,   31,   34,   32,    0,    0,    0,   45,   40,
    0,    0,    0,    0,   35,    0,   44,    0,   37,    0,
    8,   36,   38,
};
static const YYINT yydgoto[] = {                          1,
   44,   61,   27,   10,   11,   12,   13,   77,   33,   45,
   30,   46,
};
static const YYINT yysindex[] = {                         0,
  -10,   -5, -285, -277, -275, -273, -269,  -37,    0,   15,
   18,   31,   32,    0,    0, -249,    0,    0, -245, -244,
    0,    0,    0,    0,    0, -242,    0,    0,    0,  -76,
   43,   43, -229,    0, -262, -237, -234, -233, -232,    0,
    0, -198, -262, -196,   43, -124,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -201,    0,    0,    0,    0, -262, -200, -227,    0,    0,
   56, -203, -223, -202,    0,   43,    0, -222,    0, -221,
    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -51,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -224, -119,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -119,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -119,    0,    0,    0,    0,
    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  -39,    0,    0,    0,    0,    0,    0,  -30,   27,
    0,    0,
};
#define YYTABLESIZE 282
static const YYINT yytable[] = {                          9,
   70,   34,   47,   67,   14,   10,   15,   16,   48,   49,
   50,   51,   52,   53,   69,   54,   55,   17,   18,   56,
   57,   58,   19,   20,   21,   59,   73,   22,   60,   35,
   36,   37,   38,   39,   10,   10,   10,   10,   10,   40,
   23,   24,   25,   26,   10,   81,   31,   28,   41,   29,
   42,   43,   32,   10,   62,   10,   10,   63,   64,   65,
   66,   68,   72,   74,   75,   76,   78,   80,   79,   82,
   83,   13,   71,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   35,   36,   37,   38,   39,   10,
   10,   10,   10,   10,   40,    0,    0,    0,    0,   10,
    0,    0,    0,   41,    0,   42,   43,    0,   10,    0,
   10,   10,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    2,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    3,    4,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    5,    0,    0,    0,
    0,    0,    0,    0,    0,    6,    7,    0,    0,    0,
    0,    8,
};
static const YYINT yycheck[] = {                         10,
  125,   32,  265,   43,   10,  125,  292,  285,  271,  272,
  273,  274,  275,  276,   45,  278,  279,  293,  292,  282,
  283,  284,  292,   61,   10,  288,   66,   10,  291,  259,
  260,  261,  262,  263,  259,  260,  261,  262,  263,  269,
   10,   10,  292,  289,  269,   76,  123,  292,  278,  292,
  280,  281,   10,  278,  292,  280,  281,  292,  292,  292,
  259,  258,  264,  264,  292,   10,  270,  270,  292,  292,
  292,  123,   46,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  259,  260,  261,  262,  263,  259,
  260,  261,  262,  263,  269,   -1,   -1,   -1,   -1,  269,
   -1,   -1,   -1,  278,   -1,  280,  281,   -1,  278,   -1,
  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  266,  267,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  277,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  286,  287,   -1,   -1,   -1,
   -1,  292,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 293
#define YYUNDFTOKEN 308
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'='",0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SERVER",
"FILTER","ATTRIBUTE","BASEDN","BINDDN","GROUPDN","BINDCRED","MAPS","CHANGE",
"DOMAIN","PROVIDE","USER","GROUP","TO","EXPIRE","HOME","SHELL","GECOS","UID",
"GID","INTERVAL","PASSWD","NAME","FIXED","LIST","GROUPNAME","GROUPPASSWD",
"GROUPGID","MAP","INCLUDE","DIRECTORY","CLASS","PORT","ERROR","GROUPMEMBERS",
"STRING","NUMBER",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : grammar",
"grammar :",
"grammar : grammar '\\n'",
"grammar : grammar include '\\n'",
"grammar : grammar varset '\\n'",
"grammar : grammar directory '\\n'",
"grammar : grammar main '\\n'",
"grammar : grammar error '\\n'",
"nl : '\\n' optnl",
"optnl : '\\n' optnl",
"optnl :",
"include : INCLUDE STRING",
"varset : STRING '=' STRING",
"port :",
"port : PORT STRING",
"opcode : GROUP",
"opcode : PASSWD",
"attribute : NAME",
"attribute : PASSWD",
"attribute : UID",
"attribute : GID",
"attribute : CLASS",
"attribute : CHANGE",
"attribute : EXPIRE",
"attribute : GECOS",
"attribute : HOME",
"attribute : SHELL",
"attribute : GROUPNAME",
"attribute : GROUPPASSWD",
"attribute : GROUPGID",
"attribute : GROUPMEMBERS",
"diropt : BINDDN STRING",
"diropt : BINDCRED STRING",
"diropt : BASEDN STRING",
"diropt : GROUPDN STRING",
"diropt : opcode FILTER STRING",
"diropt : ATTRIBUTE attribute MAPS TO STRING",
"diropt : FIXED ATTRIBUTE attribute STRING",
"diropt : LIST attribute MAPS TO STRING",
"$$1 :",
"directory : DIRECTORY STRING port $$1 '{' optnl diropts '}'",
"main : INTERVAL NUMBER",
"main : DOMAIN STRING",
"main : PROVIDE MAP STRING",
"diropts : diropts diropt nl",
"diropts : diropt optnl",

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
#line 336 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"

struct keywords {
	const char	*k_name;
	int		 k_val;
};

int
yyerror(const char *fmt, ...)
{
	va_list		 ap;
	char		*msg;

	file->errors++;
	va_start(ap, fmt);
	if (vasprintf(&msg, fmt, ap) == -1)
		fatalx("yyerror vasprintf");
	va_end(ap);
	logit(LOG_CRIT, "%s:%d: %s", file->name, yylval.lineno, msg);
	free(msg);
	return (0);
}

int
kw_cmp(const void *k, const void *e)
{
	return (strcmp(k, ((const struct keywords *)e)->k_name));
}

int
lookup(char *s)
{
	/* this has to be sorted always */
	static const struct keywords keywords[] = {
		{ "attribute",		ATTRIBUTE },
		{ "basedn",		BASEDN },
		{ "bindcred",		BINDCRED },
		{ "binddn",		BINDDN },
		{ "change",		CHANGE },
		{ "class",		CLASS },
		{ "directory",		DIRECTORY },
		{ "domain",		DOMAIN },
		{ "expire",		EXPIRE },
		{ "filter",		FILTER },
		{ "fixed",		FIXED },
		{ "gecos",		GECOS },
		{ "gid",		GID },
		{ "group",		GROUP },
		{ "groupdn",		GROUPDN },
		{ "groupgid",		GROUPGID },
		{ "groupmembers",	GROUPMEMBERS },
		{ "groupname",		GROUPNAME },
		{ "grouppasswd",	GROUPPASSWD },
		{ "home",		HOME },
		{ "include",		INCLUDE },
		{ "interval",		INTERVAL },
		{ "list",		LIST },
		{ "map",		MAP },
		{ "maps",		MAPS },
		{ "name",		NAME },
		{ "passwd",		PASSWD },
		{ "port",		PORT },
		{ "provide",		PROVIDE },
		{ "server",		SERVER },
		{ "shell",		SHELL },
		{ "to",			TO },
		{ "uid",		UID },
		{ "user",		USER },
	};
	const struct keywords	*p;

	p = bsearch(s, keywords, sizeof(keywords)/sizeof(keywords[0]),
	    sizeof(keywords[0]), kw_cmp);

	if (p)
		return (p->k_val);
	else
		return (STRING);
}

#define MAXPUSHBACK	128

u_char	*parsebuf;
int	 parseindex;
u_char	 pushback_buffer[MAXPUSHBACK];
int	 pushback_index = 0;

int
lgetc(int quotec)
{
	int		c, next;

	if (parsebuf) {
		/* Read character from the parsebuffer instead of input. */
		if (parseindex >= 0) {
			c = parsebuf[parseindex++];
			if (c != '\0')
				return (c);
			parsebuf = NULL;
		} else
			parseindex++;
	}

	if (pushback_index)
		return (pushback_buffer[--pushback_index]);

	if (quotec) {
		if ((c = getc(file->stream)) == EOF) {
			yyerror("reached end of file while parsing "
			    "quoted string");
			if (file == topfile || popfile() == EOF)
				return (EOF);
			return (quotec);
		}
		return (c);
	}

	while ((c = getc(file->stream)) == '\\') {
		next = getc(file->stream);
		if (next != '\n') {
			c = next;
			break;
		}
		yylval.lineno = file->lineno;
		file->lineno++;
	}

	while (c == EOF) {
		if (file == topfile || popfile() == EOF)
			return (EOF);
		c = getc(file->stream);
	}
	return (c);
}

int
lungetc(int c)
{
	if (c == EOF)
		return (EOF);
	if (parsebuf) {
		parseindex--;
		if (parseindex >= 0)
			return (c);
	}
	if (pushback_index < MAXPUSHBACK-1)
		return (pushback_buffer[pushback_index++] = c);
	else
		return (EOF);
}

int
findeol(void)
{
	int	c;

	parsebuf = NULL;

	/* skip to either EOF or the first real EOL */
	while (1) {
		if (pushback_index)
			c = pushback_buffer[--pushback_index];
		else
			c = lgetc(0);
		if (c == '\n') {
			file->lineno++;
			break;
		}
		if (c == EOF)
			break;
	}
	return (ERROR);
}

int
yylex(void)
{
	u_char	 buf[8096];
	u_char	*p, *val;
	int	 quotec, next, c;
	int	 token;

top:
	p = buf;
	while ((c = lgetc(0)) == ' ' || c == '\t')
		; /* nothing */

	yylval.lineno = file->lineno;
	if (c == '#')
		while ((c = lgetc(0)) != '\n' && c != EOF)
			; /* nothing */
	if (c == '$' && parsebuf == NULL) {
		while (1) {
			if ((c = lgetc(0)) == EOF)
				return (0);

			if (p + 1 >= buf + sizeof(buf) - 1) {
				yyerror("string too long");
				return (findeol());
			}
			if (isalnum(c) || c == '_') {
				*p++ = c;
				continue;
			}
			*p = '\0';
			lungetc(c);
			break;
		}
		val = symget(buf);
		if (val == NULL) {
			yyerror("macro '%s' not defined", buf);
			return (findeol());
		}
		parsebuf = val;
		parseindex = 0;
		goto top;
	}

	switch (c) {
	case '\'':
	case '"':
		quotec = c;
		while (1) {
			if ((c = lgetc(quotec)) == EOF)
				return (0);
			if (c == '\n') {
				file->lineno++;
				continue;
			} else if (c == '\\') {
				if ((next = lgetc(quotec)) == EOF)
					return (0);
				if (next == quotec || c == ' ' || c == '\t')
					c = next;
				else if (next == '\n') {
					file->lineno++;
					continue;
				} else
					lungetc(next);
			} else if (c == quotec) {
				*p = '\0';
				break;
			} else if (c == '\0') {
				yyerror("syntax error");
				return (findeol());
			}
			if (p + 1 >= buf + sizeof(buf) - 1) {
				yyerror("string too long");
				return (findeol());
			}
			*p++ = c;
		}
		yylval.v.string = strdup(buf);
		if (yylval.v.string == NULL)
			err(1, "yylex: strdup");
		return (STRING);
	}

#define allowed_to_end_number(x) \
	(isspace(x) || x == ')' || x ==',' || x == '/' || x == '}' || x == '=')

	if (c == '-' || isdigit(c)) {
		do {
			*p++ = c;
			if ((unsigned)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && isdigit(c));
		lungetc(c);
		if (p == buf + 1 && buf[0] == '-')
			goto nodigits;
		if (c == EOF || allowed_to_end_number(c)) {
			const char *errstr = NULL;

			*p = '\0';
			yylval.v.number = strtonum(buf, LLONG_MIN,
			    LLONG_MAX, &errstr);
			if (errstr) {
				yyerror("\"%s\" invalid number: %s",
				    buf, errstr);
				return (findeol());
			}
			return (NUMBER);
		} else {
nodigits:
			while (p > buf + 1)
				lungetc(*--p);
			c = *--p;
			if (c == '-')
				return (c);
		}
	}

#define allowed_in_string(x) \
	(isalnum(x) || (ispunct(x) && x != '(' && x != ')' && \
	x != '{' && x != '}' && x != '<' && x != '>' && \
	x != '!' && x != '=' && x != '#' && \
	x != ','))

	if (isalnum(c) || c == ':' || c == '_') {
		do {
			*p++ = c;
			if ((unsigned)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && (allowed_in_string(c)));
		lungetc(c);
		*p = '\0';
		if ((token = lookup(buf)) == STRING)
			if ((yylval.v.string = strdup(buf)) == NULL)
				err(1, "yylex: strdup");
		return (token);
	}
	if (c == '\n') {
		yylval.lineno = file->lineno;
		file->lineno++;
	}
	if (c == EOF)
		return (0);
	return (c);
}

int
check_file_secrecy(int fd, const char *fname)
{
	struct stat	st;

	if (fstat(fd, &st)) {
		log_warn("cannot stat %s", fname);
		return (-1);
	}
	if (st.st_uid != 0 && st.st_uid != getuid()) {
		log_warnx("%s: owner not root or current user", fname);
		return (-1);
	}
	if (st.st_mode & (S_IWGRP | S_IXGRP | S_IRWXO)) {
		log_warnx("%s: group writable or world read/writable", fname);
		return (-1);
	}
	return (0);
}

struct file *
pushfile(const char *name, int secret)
{
	struct file	*nfile;

	if ((nfile = calloc(1, sizeof(struct file))) == NULL) {
		log_warn("malloc");
		return (NULL);
	}
	if ((nfile->name = strdup(name)) == NULL) {
		log_warn("malloc");
		free(nfile);
		return (NULL);
	}
	if ((nfile->stream = fopen(nfile->name, "r")) == NULL) {
		log_warn("%s", nfile->name);
		free(nfile->name);
		free(nfile);
		return (NULL);
	} else if (secret &&
	    check_file_secrecy(fileno(nfile->stream), nfile->name)) {
		fclose(nfile->stream);
		free(nfile->name);
		free(nfile);
		return (NULL);
	}
	nfile->lineno = 1;
	TAILQ_INSERT_TAIL(&files, nfile, entry);
	return (nfile);
}

int
popfile(void)
{
	struct file	*prev;

	if ((prev = TAILQ_PREV(file, files, entry)) != NULL)
		prev->errors += file->errors;

	TAILQ_REMOVE(&files, file, entry);
	fclose(file->stream);
	free(file->name);
	free(file);
	file = prev;
	return (file ? 0 : EOF);
}

int
parse_config(struct env *x_conf, const char *filename, int opts)
{
	struct sym	*sym, *next;

	conf = x_conf;
	bzero(conf, sizeof(*conf));

	TAILQ_INIT(&conf->sc_idms);
	conf->sc_conf_tv.tv_sec = DEFAULT_INTERVAL;
	conf->sc_conf_tv.tv_usec = 0;

	errors = 0;

	if ((file = pushfile(filename, 1)) == NULL) {
		return (-1);
	}
	topfile = file;

	/*
	 * parse configuration
	 */
	setservent(1);
	yyparse();
	endservent();
	errors = file->errors;
	popfile();

	/* Free macros and check which have not been used. */
	for (sym = TAILQ_FIRST(&symhead); sym != NULL; sym = next) {
		next = TAILQ_NEXT(sym, entry);
		if ((opts & YPLDAP_OPT_VERBOSE) && !sym->used)
			fprintf(stderr, "warning: macro '%s' not "
			    "used\n", sym->nam);
		if (!sym->persist) {
			free(sym->nam);
			free(sym->val);
			TAILQ_REMOVE(&symhead, sym, entry);
			free(sym);
		}
	}

	if (errors) {
		return (-1);
	}

	return (0);
}

int
symset(const char *nam, const char *val, int persist)
{
	struct sym	*sym;

	for (sym = TAILQ_FIRST(&symhead); sym && strcmp(nam, sym->nam);
	    sym = TAILQ_NEXT(sym, entry))
		;	/* nothing */

	if (sym != NULL) {
		if (sym->persist == 1)
			return (0);
		else {
			free(sym->nam);
			free(sym->val);
			TAILQ_REMOVE(&symhead, sym, entry);
			free(sym);
		}
	}
	if ((sym = calloc(1, sizeof(*sym))) == NULL)
		return (-1);

	sym->nam = strdup(nam);
	if (sym->nam == NULL) {
		free(sym);
		return (-1);
	}
	sym->val = strdup(val);
	if (sym->val == NULL) {
		free(sym->nam);
		free(sym);
		return (-1);
	}
	sym->used = 0;
	sym->persist = persist;
	TAILQ_INSERT_TAIL(&symhead, sym, entry);
	return (0);
}

int
cmdline_symset(char *s)
{
	char	*sym, *val;
	int	ret;
	size_t	len;

	if ((val = strrchr(s, '=')) == NULL)
		return (-1);

	len = strlen(s) - strlen(val) + 1;
	if ((sym = malloc(len)) == NULL)
		errx(1, "cmdline_symset: malloc");

	(void)strlcpy(sym, s, len);

	ret = symset(sym, val + 1, 1);
	free(sym);

	return (ret);
}

char *
symget(const char *nam)
{
	struct sym	*sym;

	TAILQ_FOREACH(sym, &symhead, entry)
		if (strcmp(nam, sym->nam) == 0) {
			sym->used = 1;
			return (sym->val);
		}
	return (NULL);
}
#line 904 "parse.c"

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
case 7:
#line 120 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ file->errors++; }
break;
case 11:
#line 131 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{
			struct file	*nfile;

			if ((nfile = pushfile(yystack.l_mark[0].v.string, 0)) == NULL) {
				yyerror("failed to include file %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);

			file = nfile;
			lungetc('\n');
		}
break;
case 12:
#line 146 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{
			char *s = yystack.l_mark[-2].v.string;
			while (*s++) {
				if (isspace((unsigned char) *s)) {
					yyerror("macro name cannot contain "
					  "whitespace");
					YYERROR;
				}
			}
			if (symset(yystack.l_mark[-2].v.string, yystack.l_mark[0].v.string, 0) == -1)
				fatal("cannot store variable");
			free(yystack.l_mark[-2].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 13:
#line 162 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.string = NULL; }
break;
case 14:
#line 163 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.string = yystack.l_mark[0].v.string; }
break;
case 15:
#line 166 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 0; }
break;
case 16:
#line 167 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 1; }
break;
case 17:
#line 171 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 0; }
break;
case 18:
#line 172 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 1; }
break;
case 19:
#line 173 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 2; }
break;
case 20:
#line 174 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 3; }
break;
case 21:
#line 175 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 4; }
break;
case 22:
#line 176 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 5; }
break;
case 23:
#line 177 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 6; }
break;
case 24:
#line 178 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 7; }
break;
case 25:
#line 179 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 8; }
break;
case 26:
#line 180 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 9; }
break;
case 27:
#line 181 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 10; }
break;
case 28:
#line 182 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 11; }
break;
case 29:
#line 183 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 12; }
break;
case 30:
#line 184 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{ yyval.v.number = 13; }
break;
case 31:
#line 187 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{
			idm->idm_flags |= F_NEEDAUTH;
			if (strlcpy(idm->idm_binddn, yystack.l_mark[0].v.string,
			    sizeof(idm->idm_binddn)) >=
			    sizeof(idm->idm_binddn)) {
				yyerror("directory binddn truncated");
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 32:
#line 198 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{
			idm->idm_flags |= F_NEEDAUTH;
			if (strlcpy(idm->idm_bindcred, yystack.l_mark[0].v.string,
			    sizeof(idm->idm_bindcred)) >=
			    sizeof(idm->idm_bindcred)) {
				yyerror("directory bindcred truncated");
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 33:
#line 209 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{
			if (strlcpy(idm->idm_basedn, yystack.l_mark[0].v.string,
			    sizeof(idm->idm_basedn)) >=
			    sizeof(idm->idm_basedn)) {
				yyerror("directory basedn truncated");
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 34:
#line 219 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{
			if(strlcpy(idm->idm_groupdn, yystack.l_mark[0].v.string,
			    sizeof(idm->idm_groupdn)) >=
			    sizeof(idm->idm_groupdn)) {
				yyerror("directory groupdn truncated");
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 35:
#line 229 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{
			if (strlcpy(idm->idm_filters[yystack.l_mark[-2].v.number], yystack.l_mark[0].v.string,
			    sizeof(idm->idm_filters[yystack.l_mark[-2].v.number])) >=
			    sizeof(idm->idm_filters[yystack.l_mark[-2].v.number])) {
				yyerror("filter truncated");
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 36:
#line 239 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{
			if (strlcpy(idm->idm_attrs[yystack.l_mark[-3].v.number], yystack.l_mark[0].v.string,
			    sizeof(idm->idm_attrs[yystack.l_mark[-3].v.number])) >=
			    sizeof(idm->idm_attrs[yystack.l_mark[-3].v.number])) {
				yyerror("attribute truncated");
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 37:
#line 249 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{
			if (strlcpy(idm->idm_attrs[yystack.l_mark[-1].v.number], yystack.l_mark[0].v.string,
			    sizeof(idm->idm_attrs[yystack.l_mark[-1].v.number])) >=
			    sizeof(idm->idm_attrs[yystack.l_mark[-1].v.number])) {
				yyerror("attribute truncated");
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			idm->idm_flags |= F_FIXED_ATTR(yystack.l_mark[-1].v.number);
			free(yystack.l_mark[0].v.string);
		}
break;
case 38:
#line 260 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{
			if (strlcpy(idm->idm_attrs[yystack.l_mark[-3].v.number], yystack.l_mark[0].v.string,
			    sizeof(idm->idm_attrs[yystack.l_mark[-3].v.number])) >=
			    sizeof(idm->idm_attrs[yystack.l_mark[-3].v.number])) {
				yyerror("attribute truncated");
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			idm->idm_list |= F_LIST(yystack.l_mark[-3].v.number);
			free(yystack.l_mark[0].v.string);
		}
break;
case 39:
#line 273 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{
			if ((idm = calloc(1, sizeof(*idm))) == NULL)
				fatal(NULL);
			idm->idm_id = conf->sc_maxid++;

			if (strlcpy(idm->idm_name, yystack.l_mark[-1].v.string,
			    sizeof(idm->idm_name)) >=
			    sizeof(idm->idm_name)) {
				yyerror("attribute truncated");
				free(yystack.l_mark[-1].v.string);
				YYERROR;
			}

			free(yystack.l_mark[-1].v.string);
		}
break;
case 40:
#line 287 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{
			TAILQ_INSERT_TAIL(&conf->sc_idms, idm, idm_entry);
			idm = NULL;
		}
break;
case 41:
#line 293 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{
			conf->sc_conf_tv.tv_sec = yystack.l_mark[0].v.number;
			conf->sc_conf_tv.tv_usec = 0;
		}
break;
case 42:
#line 297 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{
			if (strlcpy(conf->sc_domainname, yystack.l_mark[0].v.string,
			    sizeof(conf->sc_domainname)) >=
			    sizeof(conf->sc_domainname)) {
				yyerror("domainname truncated");
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 43:
#line 307 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/usr.sbin/ypldap/parse.y"
	{
			if (strcmp(yystack.l_mark[0].v.string, "passwd.byname") == 0)
				conf->sc_flags |= YPMAP_PASSWD_BYNAME;
			else if (strcmp(yystack.l_mark[0].v.string, "passwd.byuid") == 0)
				conf->sc_flags |= YPMAP_PASSWD_BYUID;
			else if (strcmp(yystack.l_mark[0].v.string, "master.passwd.byname") == 0)
				conf->sc_flags |= YPMAP_MASTER_PASSWD_BYNAME;
			else if (strcmp(yystack.l_mark[0].v.string, "master.passwd.byuid") == 0)
				conf->sc_flags |= YPMAP_MASTER_PASSWD_BYUID;
			else if (strcmp(yystack.l_mark[0].v.string, "group.byname") == 0)
				conf->sc_flags |= YPMAP_GROUP_BYNAME;
			else if (strcmp(yystack.l_mark[0].v.string, "group.bygid") == 0)
				conf->sc_flags |= YPMAP_GROUP_BYGID;
			else if (strcmp(yystack.l_mark[0].v.string, "netid.byname") == 0)
				conf->sc_flags |= YPMAP_NETID_BYNAME;
			else {
				yyerror("unsupported map type: %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
#line 1390 "parse.c"
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
