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

#line 32 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#ifdef __FreeBSD__
#include <sys/sysctl.h>
#endif
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/icmp6.h>
#include <net/pfvar.h>
#include <arpa/inet.h>
#include <net/altq/altq.h>
#include <net/altq/altq_cbq.h>
#include <net/altq/altq_codel.h>
#include <net/altq/altq_priq.h>
#include <net/altq/altq_hfsc.h>
#include <net/altq/altq_fairq.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <err.h>
#include <limits.h>
#include <pwd.h>
#include <grp.h>
#include <md5.h>

#include "pfctl_parser.h"
#include "pfctl.h"

static struct pfctl	*pf = NULL;
static int		 debug = 0;
static int		 rulestate = 0;
static u_int16_t	 returnicmpdefault =
			    (ICMP_UNREACH << 8) | ICMP_UNREACH_PORT;
static u_int16_t	 returnicmp6default =
			    (ICMP6_DST_UNREACH << 8) | ICMP6_DST_UNREACH_NOPORT;
static int		 blockpolicy = PFRULE_DROP;
static int		 require_order = 1;
static int		 default_statelock;

TAILQ_HEAD(files, file)		 files = TAILQ_HEAD_INITIALIZER(files);
static struct file {
	TAILQ_ENTRY(file)	 entry;
	FILE			*stream;
	char			*name;
	int			 lineno;
	int			 errors;
} *file;
struct file	*pushfile(const char *, int);
int		 popfile(void);
int		 check_file_secrecy(int, const char *);
int		 yyparse(void);
int		 yylex(void);
int		 yyerror(const char *, ...);
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

int		 atoul(char *, u_long *);

enum {
	PFCTL_STATE_NONE,
	PFCTL_STATE_OPTION,
	PFCTL_STATE_SCRUB,
	PFCTL_STATE_QUEUE,
	PFCTL_STATE_NAT,
	PFCTL_STATE_FILTER
};

struct node_proto {
	u_int8_t		 proto;
	struct node_proto	*next;
	struct node_proto	*tail;
};

struct node_port {
	u_int16_t		 port[2];
	u_int8_t		 op;
	struct node_port	*next;
	struct node_port	*tail;
};

struct node_uid {
	uid_t			 uid[2];
	u_int8_t		 op;
	struct node_uid		*next;
	struct node_uid		*tail;
};

struct node_gid {
	gid_t			 gid[2];
	u_int8_t		 op;
	struct node_gid		*next;
	struct node_gid		*tail;
};

struct node_icmp {
	u_int8_t		 code;
	u_int8_t		 type;
	u_int8_t		 proto;
	struct node_icmp	*next;
	struct node_icmp	*tail;
};

enum	{ PF_STATE_OPT_MAX, PF_STATE_OPT_NOSYNC, PF_STATE_OPT_SRCTRACK,
	    PF_STATE_OPT_MAX_SRC_STATES, PF_STATE_OPT_MAX_SRC_CONN,
	    PF_STATE_OPT_MAX_SRC_CONN_RATE, PF_STATE_OPT_MAX_SRC_NODES,
	    PF_STATE_OPT_OVERLOAD, PF_STATE_OPT_STATELOCK,
	    PF_STATE_OPT_TIMEOUT, PF_STATE_OPT_SLOPPY, };

enum	{ PF_SRCTRACK_NONE, PF_SRCTRACK, PF_SRCTRACK_GLOBAL, PF_SRCTRACK_RULE };

struct node_state_opt {
	int			 type;
	union {
		u_int32_t	 max_states;
		u_int32_t	 max_src_states;
		u_int32_t	 max_src_conn;
		struct {
			u_int32_t	limit;
			u_int32_t	seconds;
		}		 max_src_conn_rate;
		struct {
			u_int8_t	flush;
			char		tblname[PF_TABLE_NAME_SIZE];
		}		 overload;
		u_int32_t	 max_src_nodes;
		u_int8_t	 src_track;
		u_int32_t	 statelock;
		struct {
			int		number;
			u_int32_t	seconds;
		}		 timeout;
	}			 data;
	struct node_state_opt	*next;
	struct node_state_opt	*tail;
};

struct peer {
	struct node_host	*host;
	struct node_port	*port;
};

struct node_queue {
	char			 queue[PF_QNAME_SIZE];
	char			 parent[PF_QNAME_SIZE];
	char			 ifname[IFNAMSIZ];
	int			 scheduler;
	struct node_queue	*next;
	struct node_queue	*tail;
}	*queues = NULL;

struct node_qassign {
	char		*qname;
	char		*pqname;
};

struct filter_opts {
	int			 marker;
#define FOM_FLAGS	0x01
#define FOM_ICMP	0x02
#define FOM_TOS		0x04
#define FOM_KEEP	0x08
#define FOM_SRCTRACK	0x10
#define FOM_DSCP	0x20
#define FOM_SETPRIO	0x0400
#define FOM_PRIO	0x2000
	struct node_uid		*uid;
	struct node_gid		*gid;
	struct {
		u_int8_t	 b1;
		u_int8_t	 b2;
		u_int16_t	 w;
		u_int16_t	 w2;
	} flags;
	struct node_icmp	*icmpspec;
	u_int32_t		 tos;
	u_int32_t		 dscp;
	u_int32_t		 prob;
	u_int32_t		 tracker;
	struct {
		int			 action;
		struct node_state_opt	*options;
	} keep;
	int			 fragment;
	int			 allowopts;
	char			*label;
	char 			*schedule;
	struct node_qassign	 queues;
	char			*tag;
	char			*match_tag;
	u_int8_t		 match_tag_not;
	u_int32_t		 dnpipe;
	u_int32_t		 pdnpipe;
	u_int32_t		 free_flags;
	u_int			 rtableid;
	u_int8_t		 prio;
	u_int8_t		 set_prio[2];
	struct {
		struct node_host	*addr;
		u_int16_t		port;
	}			 divert;
} filter_opts;

struct antispoof_opts {
	char			*label;
	u_int32_t		 tracker;
	u_int			 rtableid;
} antispoof_opts;

struct scrub_opts {
	int			 marker;
#define SOM_MINTTL	0x01
#define SOM_MAXMSS	0x02
#define SOM_FRAGCACHE	0x04
#define SOM_SETTOS	0x08
	int			 nodf;
	int			 minttl;
	int			 maxmss;
	int			 settos;
	int			 fragcache;
	int			 randomid;
	int			 reassemble_tcp;
	char			*match_tag;
	u_int8_t		 match_tag_not;
	u_int			 rtableid;
} scrub_opts;

struct queue_opts {
	int			marker;
#define QOM_BWSPEC	0x01
#define QOM_SCHEDULER	0x02
#define QOM_PRIORITY	0x04
#define QOM_TBRSIZE	0x08
#define QOM_QLIMIT	0x10
	struct node_queue_bw	queue_bwspec;
	struct node_queue_opt	scheduler;
	int			priority;
	int			tbrsize;
	int			qlimit;
} queue_opts;

struct table_opts {
	int			flags;
	int			init_addr;
	struct node_tinithead	init_nodes;
} table_opts;

struct pool_opts {
	int			 marker;
#define POM_TYPE		0x01
#define POM_STICKYADDRESS	0x02
	u_int8_t		 opts;
	int			 type;
	int			 staticport;
	struct pf_poolhashkey	*key;

} pool_opts;

struct codel_opts	 codel_opts;
struct node_hfsc_opts	 hfsc_opts;
struct node_fairq_opts	 fairq_opts;
struct node_state_opt	*keep_state_defaults = NULL;

int		 disallow_table(struct node_host *, const char *);
int		 disallow_urpf_failed(struct node_host *, const char *);
int		 disallow_alias(struct node_host *, const char *);
int		 rule_consistent(struct pf_rule *, int);
int		 filter_consistent(struct pf_rule *, int);
int		 nat_consistent(struct pf_rule *);
int		 rdr_consistent(struct pf_rule *);
int		 process_tabledef(char *, struct table_opts *);
void		 expand_label_str(char *, size_t, const char *, const char *);
void		 expand_label_if(const char *, char *, size_t, const char *);
void		 expand_label_addr(const char *, char *, size_t, u_int8_t,
		    struct node_host *);
void		 expand_label_port(const char *, char *, size_t,
		    struct node_port *);
void		 expand_label_proto(const char *, char *, size_t, u_int8_t);
void		 expand_label_nr(const char *, char *, size_t);
void		 expand_label(char *, size_t, const char *, u_int8_t,
		    struct node_host *, struct node_port *, struct node_host *,
		    struct node_port *, u_int8_t);
void		 expand_rule(struct pf_rule *, struct node_if *,
		    struct node_host *, struct node_proto *, struct node_os *,
		    struct node_host *, struct node_port *, struct node_host *,
		    struct node_port *, struct node_uid *, struct node_gid *,
		    struct node_icmp *, const char *);
int		 expand_altq(struct pf_altq *, struct node_if *,
		    struct node_queue *, struct node_queue_bw bwspec,
		    struct node_queue_opt *);
int		 expand_queue(struct pf_altq *, struct node_if *,
		    struct node_queue *, struct node_queue_bw,
		    struct node_queue_opt *);
int		 expand_skip_interface(struct node_if *);

int	 check_rulestate(int);
int	 getservice(char *);
int	 rule_label(struct pf_rule *, char *);
int	 rule_schedule(struct pf_rule *, char *);
int	 rt_tableid_max(void);

void	 mv_rules(struct pf_ruleset *, struct pf_ruleset *);
void	 decide_address_family(struct node_host *, sa_family_t *);
void	 remove_invalid_hosts(struct node_host **, sa_family_t *);
int	 invalid_redirect(struct node_host *, sa_family_t);
u_int16_t parseicmpspec(char *, sa_family_t);
int	 kw_casecmp(const void *, const void *);
int	 map_tos(char *string, int *);

TAILQ_HEAD(loadanchorshead, loadanchors)
    loadanchorshead = TAILQ_HEAD_INITIALIZER(loadanchorshead);

struct loadanchors {
	TAILQ_ENTRY(loadanchors)	 entries;
	char				*anchorname;
	char				*filename;
};

typedef struct {
	union {
		int64_t			 number;
		double			 probability;
		int			 i;
		char			*string;
		u_int			 rtableid;
		struct {
			u_int8_t	 b1;
			u_int8_t	 b2;
			u_int16_t	 w;
			u_int16_t	 w2;
		}			 b;
		struct range {
			int		 a;
			int		 b;
			int		 t;
		}			 range;
		struct node_if		*interface;
		struct node_proto	*proto;
		struct node_icmp	*icmp;
		struct node_host	*host;
		struct node_os		*os;
		struct node_port	*port;
		struct node_uid		*uid;
		struct node_gid		*gid;
		struct node_state_opt	*state_opt;
		struct peer		 peer;
		struct {
			struct peer	 src, dst;
			struct node_os	*src_os;
		}			 fromto;
		struct {
			struct node_host	*host;
			u_int8_t		 rt;
			u_int8_t		 pool_opts;
			sa_family_t		 af;
			struct pf_poolhashkey	*key;
		}			 route;
		struct redirection {
			struct node_host	*host;
			struct range		 rport;
		}			*redirection;
		struct {
			int			 action;
			struct node_state_opt	*options;
		}			 keep_state;
		struct {
			u_int8_t	 log;
			u_int8_t	 logif;
			u_int8_t	 quick;
		}			 logquick;
		struct {
			int		 neg;
			char		*name;
		}			 tagged;
		struct pf_poolhashkey	*hashkey;
		struct node_queue	*queue;
		struct node_queue_opt	 queue_options;
		struct node_queue_bw	 queue_bwspec;
		struct node_qassign	 qassign;
		struct filter_opts	 filter_opts;
		struct antispoof_opts	 antispoof_opts;
		struct queue_opts	 queue_opts;
		struct scrub_opts	 scrub_opts;
		struct table_opts	 table_opts;
		struct pool_opts	 pool_opts;
		struct node_hfsc_opts	 hfsc_opts;
		struct node_fairq_opts	 fairq_opts;
		struct codel_opts	 codel_opts;
	} v;
	int lineno;
} YYSTYPE;

#define PPORT_RANGE	1
#define PPORT_STAR	2
int	parseport(char *, struct range *r, int);

#define DYNIF_MULTIADDR(addr) ((addr).type == PF_ADDR_DYNIFTL && \
	(!((addr).iflags & PFI_AFLAG_NOALIAS) ||		 \
	!isdigit((addr).v.ifname[strlen((addr).v.ifname)-1])))

#line 449 "parse.c"

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

#define PASS 257
#define BLOCK 258
#define MATCH 259
#define SCRUB 260
#define RETURN 261
#define IN 262
#define OS 263
#define OUT 264
#define LOG 265
#define QUICK 266
#define ON 267
#define FROM 268
#define TO 269
#define FLAGS 270
#define RETURNRST 271
#define RETURNICMP 272
#define RETURNICMP6 273
#define PROTO 274
#define INET 275
#define INET6 276
#define ALL 277
#define ANY 278
#define ICMPTYPE 279
#define ICMP6TYPE 280
#define CODE 281
#define KEEP 282
#define MODULATE 283
#define STATE 284
#define PORT 285
#define RDR 286
#define NAT 287
#define BINAT 288
#define ARROW 289
#define NODF 290
#define MINTTL 291
#define ERROR 292
#define ALLOWOPTS 293
#define FASTROUTE 294
#define FILENAME 295
#define ROUTETO 296
#define DUPTO 297
#define REPLYTO 298
#define NO 299
#define LABEL 300
#define SCHEDULE 301
#define NOROUTE 302
#define URPFFAILED 303
#define FRAGMENT 304
#define USER 305
#define GROUP 306
#define MAXMSS 307
#define MAXIMUM 308
#define TTL 309
#define TOS 310
#define DSCP 311
#define DROP 312
#define TABLE 313
#define TRACKER 314
#define REASSEMBLE 315
#define FRAGDROP 316
#define FRAGCROP 317
#define ANCHOR 318
#define NATANCHOR 319
#define RDRANCHOR 320
#define BINATANCHOR 321
#define SET 322
#define OPTIMIZATION 323
#define TIMEOUT 324
#define LIMIT 325
#define LOGINTERFACE 326
#define BLOCKPOLICY 327
#define RANDOMID 328
#define REQUIREORDER 329
#define SYNPROXY 330
#define FINGERPRINTS 331
#define NOSYNC 332
#define DEBUG 333
#define SKIP 334
#define HOSTID 335
#define ANTISPOOF 336
#define FOR 337
#define INCLUDE 338
#define BITMASK 339
#define RANDOM 340
#define SOURCEHASH 341
#define ROUNDROBIN 342
#define STATICPORT 343
#define PROBABILITY 344
#define ALTQ 345
#define CBQ 346
#define CODEL 347
#define PRIQ 348
#define HFSC 349
#define FAIRQ 350
#define BANDWIDTH 351
#define TBRSIZE 352
#define LINKSHARE 353
#define REALTIME 354
#define UPPERLIMIT 355
#define QUEUE 356
#define PRIORITY 357
#define QLIMIT 358
#define HOGS 359
#define BUCKETS 360
#define RTABLE 361
#define TARGET 362
#define INTERVAL 363
#define DNPIPE 364
#define DNQUEUE 365
#define LOAD 366
#define RULESET_OPTIMIZATION 367
#define PRIO 368
#define STICKYADDRESS 369
#define MAXSRCSTATES 370
#define MAXSRCNODES 371
#define SOURCETRACK 372
#define GLOBAL 373
#define RULE 374
#define MAXSRCCONN 375
#define MAXSRCCONNRATE 376
#define OVERLOAD 377
#define FLUSH 378
#define SLOPPY 379
#define TAGGED 380
#define TAG 381
#define IFBOUND 382
#define FLOATING 383
#define STATEPOLICY 384
#define STATEDEFAULTS 385
#define ROUTE 386
#define SETTOS 387
#define DIVERTTO 388
#define DIVERTREPLY 389
#define STRING 390
#define NUMBER 391
#define PORTBINARY 392
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  139,  152,  152,
  152,  152,  152,  152,   19,  140,  140,  140,  140,  140,
  140,  140,  140,  140,  140,  140,  140,  140,  140,  140,
  140,   79,   79,   82,   82,   83,   83,   84,   84,  149,
   81,   81,  158,  158,  158,  158,  160,  159,  159,  145,
  145,  145,  145,  146,   27,  141,  161,  128,  128,  130,
  130,  129,  129,  129,  129,  129,  129,  129,  129,  129,
   18,   18,   18,  150,   94,   94,   95,   95,   96,   96,
  163,  122,  122,  124,  124,  123,  123,  123,   12,   12,
  151,  164,  131,  131,  133,  133,  132,  132,  132,  132,
  147,  148,  165,  125,  125,  127,  127,  126,  126,  126,
  126,  126,  115,  115,  101,  101,  101,  101,  101,  101,
  101,  101,  101,  101,  102,  102,  103,  104,  104,  105,
  166,  108,  106,  106,  107,  107,  107,  107,  107,  107,
  107,  167,  111,  109,  109,  110,  110,  110,  110,  110,
  168,  114,  112,  112,  113,  113,  113,   98,   98,   98,
   99,   99,  100,  144,  169,  116,  116,  118,  118,  117,
  117,  117,  117,  117,  117,  117,  117,  117,  117,  117,
  117,  117,  117,  117,  117,  117,  117,  117,  117,  117,
  117,  117,  117,  117,  117,  117,  117,  119,  119,  121,
  121,  120,   31,   31,   14,   14,   24,   24,   24,   30,
   30,   30,   30,   30,   30,   30,   30,   30,   30,   45,
   45,   46,   46,   16,   16,   16,   90,   90,   89,   89,
   89,   89,   89,   91,   91,   92,   92,   93,   93,   93,
   93,    1,    1,    1,    2,    2,    3,    4,   17,   17,
   17,   36,   36,   36,   37,   37,   38,   39,   39,   47,
   47,   62,   62,   62,   63,   64,   64,   49,   49,   50,
   50,   48,   48,   48,  154,  154,   51,   51,   51,   52,
   52,   56,   56,   53,   53,   53,   54,   54,   54,   54,
   54,   54,   54,    5,    5,   55,   65,   65,   66,   66,
   67,   67,   67,   32,   34,   68,   68,   69,   69,   70,
   70,   70,    8,    8,   71,   71,   72,   72,   73,   73,
   73,    9,    9,   29,   28,   28,   28,   40,   40,   40,
   40,   41,   41,   43,   43,   42,   42,   42,   44,   44,
   44,    6,    6,    7,    7,   10,   10,   11,   20,   20,
   20,   23,   23,   85,   85,   85,   85,   21,   21,   21,
   86,   86,   87,   87,   88,   88,   88,   88,   88,   88,
   88,   88,   88,   88,   88,   77,   78,   97,   97,   97,
   15,   15,   33,   58,   58,   57,   57,   76,   76,   76,
   35,   35,  170,  134,  134,  136,  136,  135,  135,  135,
  135,  135,  135,   75,   75,   75,   26,   26,   26,   26,
   25,   25,  142,  143,   80,   80,  137,  137,  138,  138,
   59,   59,   60,   60,   61,   61,   74,   74,   74,   74,
   74,  153,  153,  155,  155,  156,  157,  157,  162,  162,
   13,   13,   22,   22,   22,   22,   22,   22,
};
static const YYINT yylen[] = {                            2,
    0,    3,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    4,    3,    2,    2,    3,
    3,    3,    3,    3,    1,    3,    3,    3,    6,    3,
    6,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    1,    1,    2,    1,    2,    1,    1,    1,    3,
    1,    0,    0,    2,    3,    3,    0,    5,    0,   10,
    7,    7,    7,    5,    2,    8,    0,    2,    0,    2,
    1,    1,    2,    2,    2,    1,    2,    1,    2,    3,
    2,    2,    2,    5,    2,    5,    2,    4,    1,    3,
    0,    2,    0,    2,    1,    1,    2,    2,    1,    0,
    5,    0,    2,    0,    2,    1,    1,    3,    4,    2,
    5,    5,    0,    2,    0,    2,    1,    2,    2,    2,
    1,    2,    1,    1,    1,    4,    1,    4,    1,    4,
    1,    4,    1,    4,    1,    3,    1,    1,    3,    1,
    0,    2,    1,    3,    2,    8,    2,    8,    2,    8,
    1,    0,    2,    1,    3,    2,    6,    2,    2,    1,
    0,    2,    1,    3,    2,    2,    1,    0,    1,    4,
    2,    4,    1,    9,    0,    2,    0,    2,    1,    2,
    2,    1,    1,    2,    2,    1,    1,    2,    1,    1,
    1,    1,    1,    2,    4,    6,    2,    6,    4,    2,
    3,    2,    2,    2,    4,    1,    1,    4,    2,    3,
    1,    1,    2,    6,    1,    1,    1,    1,    2,    0,
    1,    1,    5,    1,    1,    4,    4,    6,    1,    1,
    1,    1,    1,    0,    1,    1,    0,    1,    0,    1,
    1,    2,    2,    1,    4,    1,    3,    1,    1,    1,
    2,    0,    2,    5,    2,    4,    2,    1,    0,    1,
    1,    0,    2,    5,    2,    4,    1,    1,    1,    1,
    3,    0,    2,    5,    1,    2,    4,    0,    2,    0,
    2,    1,    3,    2,    2,    0,    1,    1,    4,    2,
    0,    2,    4,    2,    2,    2,    1,    3,    3,    3,
    1,    3,    3,    1,    1,    3,    1,    4,    2,    4,
    1,    2,    3,    1,    1,    1,    4,    2,    4,    1,
    2,    3,    1,    1,    1,    4,    2,    4,    1,    2,
    3,    1,    1,    1,    4,    3,    2,    2,    5,    2,
    5,    2,    4,    2,    4,    1,    3,    3,    1,    3,
    3,    1,    1,    1,    1,    1,    1,    2,    1,    2,
    2,    1,    1,    2,    3,    3,    3,    0,    1,    2,
    3,    0,    1,    3,    2,    1,    2,    2,    4,    5,
    2,    1,    1,    1,    2,    2,    2,    2,    4,    6,
    0,    1,    1,    1,    4,    2,    4,    0,    2,    4,
    0,    1,    0,    2,    0,    2,    1,    1,    1,    2,
    1,    1,    1,    0,    2,    4,    0,    1,    2,    1,
    3,    3,   10,   13,    0,    2,    0,    3,    0,    2,
    1,    4,    2,    4,    1,    4,    0,    1,    3,    3,
    3,    2,    2,    4,    2,    2,    4,    2,    1,    0,
    1,    1,    1,    2,    2,    1,    2,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,  217,    0,  218,  392,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    3,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   19,
    0,    0,    0,    0,    0,    0,   17,  229,    0,    0,
    0,  221,  219,    0,   51,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   18,    0,    0,
    0,    0,    0,   65,    0,    0,    0,  235,  236,    0,
    0,    0,    2,    4,    5,    6,    7,    8,    9,   10,
   11,   12,   13,   14,   15,   24,   16,   22,   21,   23,
   20,    0,    0,    0,    0,    0,   44,    0,    0,    0,
   26,    0,    0,    0,   28,    0,    0,   30,   43,   42,
   32,   35,   34,  451,  452,   36,   37,   39,   40,  305,
  304,   33,   27,   25,  362,  363,   38,    0,  376,    0,
    0,    0,    0,    0,    0,  384,    0,  382,  383,    0,
  373,    0,  243,    0,    0,  242,    0,   99,  253,    0,
    0,    0,    0,    0,   49,   48,   50,    0,    0,  422,
  420,  421,    0,    0,  260,  261,    0,    0,    0,  230,
  231,    0,  232,  233,    0,    0,  238,    0,    0,    0,
    0,  443,  442,    0,    0,  446,    0,  375,  377,  381,
  360,  361,  378,    0,    0,  385,  449,    0,    0,  248,
  249,  250,    0,  246,  258,    0,    0,   89,   85,    0,
    0,  257,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  121,  117,    0,    0,    0,   46,  419,    0,
    0,    0,    0,    0,    0,  226,    0,  227,  101,    0,
    0,    0,    0,    0,  285,    0,    0,    0,    0,    0,
    0,  374,  251,  245,    0,    0,    0,   84,    0,    0,
    0,  173,    0,  111,  169,    0,  161,    0,  141,  152,
  123,  124,  118,  122,  119,  120,  116,  112,   64,    0,
  438,    0,    0,    0,    0,  268,  269,    0,  263,  267,
    0,  270,    0,    0,    0,  223,    0,    0,  107,    0,
  106,    0,    0,    0,    0,    0,  445,   29,    0,  448,
   31,    0,  379,    0,  247,    0,    0,   90,    0,    0,
    0,   96,   95,    0,  254,    0,  255,    0,  137,    0,
  135,    0,    0,  140,    0,  138,    0,    0,    0,    0,
    0,  431,    0,    0,  435,    0,    0,    0,    0,    0,
  287,    0,    0,    0,  279,    0,  288,    0,    0,    0,
    0,    0,  228,  110,    0,  105,    0,    0,   61,   62,
   63,    0,    0,    0,  380,   86,    0,   87,  386,   97,
   98,   94,    0,    0,    0,  126,    0,  134,    0,    0,
  167,    0,  163,  128,    0,  130,    0,    0,    0,  151,
    0,  143,  132,    0,    0,    0,  160,    0,  154,    0,
    0,    0,  439,    0,  441,  440,    0,    0,    0,    0,
  453,    0,    0,    0,    0,    0,  284,  307,  315,    0,
  295,  296,    0,    0,    0,    0,  294,    0,    0,  426,
    0,    0,  275,    0,  273,    0,  271,    0,  108,    0,
    0,    0,  430,  444,  447,  370,    0,  256,  170,    0,
  171,  136,  166,  165,    0,  139,    0,  145,    0,  147,
    0,  149,    0,    0,  156,  158,  159,    0,    0,    0,
    0,    0,  408,  409,    0,  411,  412,  413,  407,    0,
    0,  264,    0,  265,    0,  454,  455,  457,  312,    0,
    0,    0,    0,    0,    0,    0,    0,  283,    0,    0,
    0,  281,   66,    0,  292,  109,    0,    0,    0,   88,
    0,  164,    0,    0,    0,  144,    0,  155,    0,    0,
  433,  436,    0,  432,  410,  402,  406,  174,    0,    0,
    0,  313,  289,  298,  299,  300,  306,  303,  302,  428,
    0,    0,    0,    0,   72,    0,    0,    0,    0,   78,
    0,    0,    0,   76,   71,    0,    0,   57,   60,    0,
    0,    0,    0,    0,  190,    0,    0,  189,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  206,  186,    0,  182,  183,  191,  192,
  187,  193,  179,    0,  207,  172,    0,    0,    0,    0,
  290,    0,    0,  266,  308,    0,  309,    0,  394,    0,
  423,  276,  274,    0,   73,   81,   83,   82,   74,   77,
   79,  356,  357,   75,    0,   70,  293,    0,  337,  334,
    0,    0,  352,  353,    0,    0,  338,  354,  355,    0,
    0,  340,    0,    0,  364,  387,  323,  324,    0,    0,
    0,  180,  316,  332,  333,    0,    0,    0,  181,  325,
  185,  358,  188,    0,    0,  212,  209,    0,  215,  216,
  202,  388,    0,  203,    0,  194,    0,  197,  184,  200,
    0,  204,  314,    0,  178,    0,    0,    0,    0,    0,
  434,    0,    0,    0,    0,   80,   53,  336,    0,    0,
    0,    0,    0,    0,  365,  366,    0,    0,  321,    0,
    0,  330,  213,    0,  211,    0,  367,    0,    0,    0,
    0,  201,    0,    0,    0,  157,    0,  310,    0,    0,
  400,  393,  277,    0,  335,    0,    0,  347,  348,    0,
    0,  350,  351,    0,    0,    0,  322,    0,    0,  331,
    0,  208,    0,  389,    0,  195,    0,  199,    0,  205,
    0,    0,    0,    0,  424,  396,  395,    0,   54,   58,
    0,    0,  339,    0,  342,  341,    0,  344,  371,  317,
    0,  318,  326,    0,  327,    0,  210,    0,    0,    0,
  146,  148,  150,    0,    0,   55,   56,    0,    0,    0,
    0,    0,  390,  196,  198,    0,  397,  343,  345,  319,
  328,  214,  416,
};
static const YYINT yydgoto[] = {                          2,
   80,  280,  169,  228,  142,  666,  671,  680,  687,  654,
  615,  374,  136,  701,   22,   90,  187,  584,  143,  158,
  395,  445,  159,   23,   24,  180,   25,  617,  662,   53,
  696,  712,  761,  446,  555,  253,  438,  309,  310,  618,
  766,  667,  770,  672,  192,  195,  313,  375,  314,  467,
  376,  550,  377,  457,  458,  471,  760,  640,  365,  501,
  366,  381,  465,  574,  447,  560,  448,  682,  775,  683,
  689,  778,  690,  305,  795,  572,  342,  620,  131,  379,
   56,   58,  177,  449,  621,  735,  160,  161,   76,  198,
   77,  223,  224,  165,  336,  229,  622,  284,  404,  285,
  243,  350,  351,  355,  356,  421,  422,  357,  428,  429,
  359,  412,  413,  352,  293,  538,  623,  624,  625,  697,
  746,  278,  343,  344,  171,  244,  245,  533,  585,  586,
  259,  321,  322,  433,  509,  510,  462,  389,   26,   27,
   28,   29,   30,   31,   32,   33,   34,   35,   36,   37,
   38,    3,  125,  205,  267,  128,  269,  764,  589,  658,
  534,  218,  279,  260,  172,  358,  360,  353,  539,  434,
};
static const YYINT yysindex[] = {                       -76,
    0, 1261, 1257,   59,    0,  752,    0,    0,   68, -272,
 -207, -207, -207, 2395, -180, -179,  -11, -129,   43,  217,
    0,  308,  214,  -11,  214,  384,  407,  437,  447,  453,
  457,  470,  476,  511,  516,  526,  535,  539,  581,    0,
  606,  -40,  619,  629,  635,  642,    0,    0,  628,  641,
  663,    0,    0,  259,    0,  214, -207,  -11,  -11,  -11,
  319,  141,  -66, -225,  -36, -265,  324,  330,  -11,  300,
 -207,  313, 1690,  695,  483,  387,  485,    0,   63,    0,
  -11, -207,  350,    0,  -21,  -21,  -21,    0,    0, -180,
  504, -180,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  445,  427,  435,  697,  509,    0,  504,  504,  504,
    0,  400,  403,  786,    0,  423,  786,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  455,    0,  472,
  491,  460,  495,  497,  792,    0,  520,    0,    0,  827,
    0,  608,    0,   31,  504,    0,  786,    0,    0,  484,
  546, 1876,    0,  667,    0,    0,    0,  350,  483,    0,
    0,    0,  -11,  -11,    0,    0,  633,  -11,  525,    0,
    0,   64,    0,    0,  878,    0,    0,  -11,  633,  633,
  633,    0,    0,  786,  243,    0,  531,    0,    0,    0,
    0,    0,    0,  922,  616,    0,    0, 1690, -207,    0,
    0,    0,  245,    0,    0,  786,  484,    0,    0,    0,
  975,    0,  -59,  972,  977,  986,  989,  992,  451,  654,
  656,  670,    0,    0, 1876,  -59, -207,    0,    0,  504,
  836,  -77, -189,  504, 1017,    0,  435,    0,    0,  -91,
  504, -189, -189, -189,    0,  786,   11,  786,   93,  676,
 1007,    0,    0,    0,  608,  -34, 1030,    0,  -88,   94,
  786,    0,  786,    0,    0,  685,    0,  696,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  633,
    0,   47,   47,   47,  504,    0,    0,  786,    0,    0,
  386,    0,  711,  833,  633,    0, 1060,  709,    0,  786,
    0,  -91,  633,  742,  742,  742,    0,    0,  243,    0,
    0,  531,    0,  734,    0,   95,  786,    0,  731,  300,
  744,    0,    0,  -88,    0,  975,    0,  748,    0,  369,
    0, 1099, -133,    0,  479,    0, 1102,  637, 1105,  439,
  881,    0,  786,  763,    0,    0,    0,    0,  633,  459,
    0,  115,  786,  153,    0,  880,    0,  777,  975,  -53,
  899, -189,    0,    0,  609,    0, -189,  778,    0,    0,
    0,  786,  786,  803,    0,    0,  -34,    0,    0,    0,
    0,    0,  786,  108,  786,    0,  685,    0,  300,  300,
    0,  827,    0,    0,  696,    0,   37,   55,   62,    0,
  827,    0,    0,  106,  451,  300,    0,  827,    0,   28,
  -28,   34,    0, 1115,    0,    0, -189,  135,  786,  786,
    0, 1116, 1117, 1121,  350,  788,    0,    0,    0,   28,
    0,    0,  743, 1139,  799,  800,    0, 1145,  115,    0,
  813,  742,    0,  786,    0,  386,    0,    0,    0,  786,
  138,    0,    0,    0,    0,    0,  786,    0,    0,  748,
    0,    0,    0,    0, -133,    0,  451,    0,  451,    0,
  451,    0,  637,  451,    0,    0,    0,  439,  927,  786,
  154, 1156,    0,    0, -207,    0,    0,    0,    0, 1115,
    0,    0,  459,    0,  161,    0,    0,    0,    0,  350,
  162,  809,  810,  812, 1159, 1151,  816,    0, -207,  928,
  828,    0,    0,  646,    0,    0,   28, 1097, 4927,    0,
  786,    0,  827,  827,  827,    0,  300,    0,   28,  711,
    0,    0,  -28,    0,    0,    0,    0,    0,  786,  193,
  786,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   84,    0,  786,  209,    0,  830,  448,  831,  838,    0,
  832,  508,  846,    0,    0,  646,  786,    0,    0,  -12,
  -69,   82,  946,  948,    0,  955,  850,    0,  128,  148,
  508,  853,  300,  -20,  957,  537,  -14,  854,  123,  126,
  855, -207,  572,    0,    0,  864,    0,    0,    0,    0,
    0,    0,    0, 4927,    0,    0,  859,  860,  861,  451,
    0,  975,  786,    0,    0,  161,    0,  786,    0,  971,
    0,    0,    0,  828,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -207,    0,    0, 1247,    0,    0,
  872, 1216,    0,    0,  786,  991,    0,    0,    0,  786,
  993,    0, 1235, 1235,    0,    0,    0,    0,  786,  898,
  582,    0,    0,    0,    0,  786,  907,  585,    0,    0,
    0,    0,    0,  -25,  923,    0,    0, 1235,    0,    0,
    0,    0,  910,    0,  300,    0,  300,    0,    0,    0,
 1016,    0,    0, -207,    0,  827,  827,  827, 1264,  742,
    0,  786,   34,  350,  786,    0,    0,    0,  872,  592,
  603,  645,  648, 1690,    0,    0,  234,  582,    0,  268,
  585,    0,    0,  916,    0,  540,    0,  576,  596,  613,
  350,    0,  451,  451,  451,    0, 1020,    0,  786,  210,
    0,    0,    0, 1282,    0,  218,  786,    0,    0,  224,
  786,    0,    0,  684,  230,  786,    0,  316,  786,    0,
  827,    0,  923,    0,  924,    0,  300,    0,  300,    0,
 1271, 1272, 1275,   34,    0,    0,    0,   34,    0,    0,
 1307, 1310,    0,  592,    0,    0,  645,    0,    0,    0,
  234,    0,    0,  268,    0,  933,    0, 1284, 1285, 1286,
    0,    0,    0, 1044,  786,    0,    0,  786,  786,  786,
  786, 1291,    0,    0,    0,  350,    0,    0,    0,    0,
    0,    0,    0,
};
static const YYINT yyrindex[] = {                       113,
    0,  552,  657,    0,    0, 1849,    0,    0,    0, 3110,
    0,    0,    0,    0,  994,    0, 1746,    0,    0,    0,
    0,    0, 2614, 3783, 4897,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 1995, 2123,
 2257,    0,    0,    0,    0, 3474, 1488,  841,  841,  841,
    0,    0,    0,    0,    0,    0,    0,    0, 1323,    0,
    0,    0,    0, 1356, 1604,    0, 1720,    0,  949, 1851,
 1119,    0,    0,    0, 3174, 3174,  721,    0,    0, 3226,
  358,   35,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 3590,    0, 1034, 1034, 1034,
    0,    0,    0,  256,    0,    0,  956,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  112,    0,    0,    0,    0,    0,    0,    0,  290,
    0,    0,    0,    0,   53,    0,  -26,    0,    0,    0,
    0,    0, 1238,    0,    0,    0,    0,   59, 3899,    0,
    0,    0,  781, 3342,    0,    0,  679, 2186,    0,    0,
    0,  651,    0,    0,    0,   -7,    0, 3706,  868,  868,
  868,    0,    0, 2317,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  801,    0,    0,   33,    0,    0,    0,  185,
  949,    0, 1326,  336,  653,  931, 1027, 1085,    0,    0,
    0,    0,    0,    0,    3, 1326,    0,    0,    0,  134,
 3835,    0, 1943, 3518,    0,    0,    0,    0,    0,    0,
 4067,   14,   14,   14,    0,  513,  265,   91,  962,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -16,
    5,    0,  956,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 1086,
    0,    0,    0,    0, 4196,    0,    0,  660,    0,    0,
  519,    0, 2287, 2485,  851,    0,    0,    0,    0, 1290,
    0,  526, 4310, 1343, 1343, 1343,    0,    0,    0,    0,
    0,    0,    0,  158,    0,   58,  215,    0,    0,    0,
    0,    0,    0, 1345,    0,  949,    0,    0,    0,  962,
    0,    0,    0,    0,  962,    0,    0,    0,    0,    0,
    0,    0,   33,    0,    0, 2859, 2859, 2859, 4359,    0,
    0,    0, 1370,    0,    0, 2371,    0,    0,  444,    0,
 2728, 3634,    0,    0,  519,    0, 4472,    0,    0,    0,
    0,  513,   91,  190,    0,    0,    0,    0,    0,    0,
    0,    0,    5,  962,   91,    0,    0,    0,    0,    0,
    0,  251,    0,    0,    0,    0,    0,    0,    0,    0,
  363,    0,    0,    0,    0,    0,    0,  211,    0,  519,
    0,    0,    0,    0,    0,    0, 4521,  651,  198,  549,
    0,    0,  690,  766,    0,  783,    0,    0,    0,  519,
    0,    0,  467,    0,    0,    0,    0,  590,    0,    0,
    0,  235,    0,  956,    0,  519,    0,   29,    0,   49,
 1498, 4613,    0,    0,    0,    0,  215,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    4,  215,
   58,    0,    0,    0, 2981,    0,    0,    0,    0, 3951,
 4814,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 1498,    0,    0,    0,    0,    0,    0,    0,    0,  335,
    0,    0,    0,  976,    0,    0,  519, 1350,  976,    0,
   91,    0,  974,  974,  974,    0,    0,    0,  519,   18,
    0,    0,    0,    0,    0,    0,    0,    0,  198,  804,
   39,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  461,   91,  962,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   12,   49,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    9,    0,    0,    0,    0,    0,    0,
    0,   26,  215,    0,    0,    0,    0,   52,    0,  583,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  660, 1058,    0,    0,    0,  660,
 1181,    0, 4662, 4662,    0,    0,    0,    0,  549,  905,
    0,    0,    0,    0,    0,  549,  954,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, 4662,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 4765,    0,    0,    0,    0,  651,  651,  651,    0,    8,
    0,   39,    0,    0,   91,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  999,    0,  962,  651,  651,
    0,    0,    0,    0,    0,    0, 1360,    0,   71,  102,
    0,    0,    0,    0,    0,  651,  198,    0,    0,  651,
  198,    0,    0, 1798,  804,   39,    0,  804,   39,    0,
  974,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 1361,   71,    0,    0,  198,  198,   39,
   39,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
 1650,    0, -155,  -86, -319,    0,    0, -457, -622,  780,
    0,  -74,    0,    0, 1383,  176, 1229,    0,    0,    0,
    0,  220, 1315,    0,    0, 1073,    0,    0, -444,    0,
    0,  640,  554, -387,    0,  785,    0, -354,    0,    0,
    0, -690,    0, -673,    0, 1135,  480,  930,    0,    0,
 -310,    0,    0, -391,    0,  943,    0,    0, -404,    0,
  858,    0, -466,    0,  938,    0, -467,    0,    0, -627,
    0,    0, -611,    0,    0,    0, -497,    0,    0,  848,
    0,   -4, 1221,  -81,    0, -618,  666, 1183,  639,    0,
  636,    0, 1129,    0,    0, -226,    0, 1160,    0, -325,
    0,    0,  998,    0,  996,    0,  915,    0,    0,  911,
    0,    0,  935,    0, 1827,  901,  794,    0,    0, -662,
    0,    0, 1072,    0, 1248, 1179,    0,    0,  839,    0,
    0, 1106,    0, -337,  917,    0,  797, -315,    0,    0,
    0, 1437, 1441,   -3,   -2,    0,    0,    0,    0,    0,
    0,    0, -162, -123,    0, -182,    0,    0,    0,    0,
    0, -163,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 5316
static const YYINT yytable[] = {                         45,
   46,  178,  104,  207,  170,  227,  286,   59,   60,  390,
  391,  364,  114,  291,  744,  439,  450,  429,  176,  695,
  400,   68,  405,  278,  268,  703,  500,  425,  257,  435,
  436,  320,  745,  134,  661,  427,  291,  286,   69,  767,
  502,  619,  266,  231,  239,  308,    1,  561,  286,  337,
  425,  129,  117,  665,  217,  736,  127,  519,  771,  275,
  168,   67,  259,  283,  573,  742,  144,  239,   47,  464,
  227,  286,  286,  455,  470,  281,  487,  174,  311,  747,
  265,  286,  286,  232,   74,   75,  364,  312,  286,  483,
  484,  286,  286,  456,  489,  168,  178,  450,  286,  286,
  286,  491,  276,  329,  256,  332,  497,  217,  286,  776,
  286,  286,    1,  828,  286,  102,  346,   55,  780,  499,
  817,  359,    1,  455,  135,  114,  619,   54,  779,  286,
  286,  176,  562,  829,  286,  328,  217,  217,  217,  470,
  277,  450,  327,  456,  330,  494,  530,  442,  633,  393,
  373,  217,  359,  226,  541,  359,  170,  347,  559,  348,
  442,  450,  705,  286,  130,  707,  392,  368,  722,  363,
  477,  286,  397,  286,  443,  441,  444,  725,  217,  639,
  442,  217,   57,  830,  370,  167,  407,  443,  441,  444,
  403,  415,  455,  442,   93,  286,  385,  217,  368,  369,
   92,  368,  831,  318,  670,  217,  638,  443,  441,  444,
   78,  339,  456,  398,  273,  286,  728,  331,  345,  396,
  443,  441,  444,  739,  132,  340,  587,  630,  409,  410,
  369,  116,  479,  369,  641,  179,  217,  440,  631,  431,
  480,  286,  299,   74,  429,   85,   86,   87,  485,  450,
  679,  153,  217,  217,  286,   79,  411,  493,  286,  512,
   81,  217,  536,  124,  498,  659,  442,  217,  474,  475,
  686,  170,  341,  217,  513,  133,  278,   83,  552,  478,
  777,  481,  278,  693,  765,  274,  563,  102,  217,  706,
  708,  162,  291,  443,  441,  444,  429,  239,  319,   41,
  442,  239,  239,  239,  461,  371,  425,  537,  239,  239,
  239,  239,  306,  307,  427,  514,  515,  635,   67,   67,
  663,  664,  286,  126,  239,  239,  286,  443,  441,  444,
  282,  759,   67,  643,  797,   67,  463,  553,  239,  286,
  531,  239,  803,   67,  398,  125,  535,  694,  806,  239,
  286,  286,  259,  540,  810,  225,   67,  537,  114,  217,
   82,  362,  239,  286,  291,  743,  259,  259,    1,    1,
    1,    1,    1,  450,  278,  702,  551,  660,  425,  627,
  628,  629,  102,  291,  291,  749,  427,  750,  100,   67,
  259,  100,  114,   93,  286,  239,  636,  425,    1,    1,
    1,  259,  824,  142,  757,  100,  825,  259,   67,  406,
  644,    1,  217,  259,  239,   67,   94,  626,  168,  359,
  225,  239,  286,  453,  454,    1,  291,  292,  286,  286,
    1,    1,    1,    1,    1,  634,  362,  637,  286,  286,
  813,  286,  286,  359,  291,  292,   95,  450,    1,  642,
    1,  291,  292,  427,  451,  452,   96,    1,  125,  583,
  286,  286,   97,  657,  616,  368,   98,  819,    1,  820,
  405,  668,  669,  453,  454,   88,  297,   89,    1,   99,
  286,  359,  359,  359,   91,  100,  359,  359,  359,  368,
  359,  450,  450,  359,  359,  291,  292,  369,   91,  297,
  556,  359,    1,  122,  175,  176,  297,  297,  373,  721,
  297,  583,  140,  141,  723,  140,  141,  677,  678,  414,
  101,  369,  217,  429,  570,  102,  297,  368,  368,  368,
  123,  713,  368,  368,  368,  103,  368,  684,  685,  368,
  368,  730,  453,  454,  104,   91,  732,  368,  105,  616,
  175,  176,  753,  754,  755,  737,  286,  461,  100,  369,
  369,  369,  740,  450,  369,  369,  369,   84,  369,  450,
  450,  369,  369,  429,  429,  429,  429,  429,  100,  369,
  782,  286,  783,  217,  785,  787,  789,  286,  286,  297,
  106,  297,  399,   85,   86,   87,  798,  450,  758,  301,
  450,  763,  804,  429,  286,  122,  807,  710,  286,  286,
  286,  811,  450,  450,  814,  107,  784,  816,  286,  217,
  259,  450,  301,  677,  678,  259,  259,  450,  108,  301,
  301,  259,  123,  301,  259,  796,  786,  286,  109,  217,
  450,  168,  762,  805,  110,  286,  259,  808,  115,  301,
  726,  111,  812,  788,  450,  815,  217,  684,  685,  450,
  450,  450,  133,  371,  450,  450,  450,  112,  450,  713,
  372,  450,  450,  398,  398,  398,  398,  398,  168,  450,
  113,  125,  125,  125,  125,  125,  125,  125,  262,  140,
  141,  125,  125,  125,  145,  146,  259,  259,  259,  259,
  259,  837,  114,  398,  838,  839,  840,  841,  121,  752,
  163,  262,  301,  137,  301,  450,  450,  450,  259,  138,
  181,  181,  181,  164,  809,  125,  259,  217,  184,  297,
  188,  373,  427,  469,  162,  297,  297,  259,  259,  175,
  176,  324,  325,  326,  297,  297,  297,   74,  297,  297,
  166,  297,  450,  189,  762,  297,  297,  297,  196,  297,
  801,  802,  646,  647,  648,  297,  297,  297,  297,  297,
  297,  297,  297,  297,  197,  133,  297,  297,  185,  186,
  297,  297,  427,  427,  427,  427,  427,  522,  297,  523,
  202,  424,  311,  203,  297,  204,  297,  425,  426,  403,
  403,  403,  403,  403,  427,  297,  297,  297,  297,  297,
  297,  391,  427,  206,  249,  311,  190,  191,  681,  688,
  100,  100,  297,  100,  193,  194,  311,  297,  427,  403,
  297,  297,  211,  212,  297,  297,  450,  391,  391,  391,
  291,  292,  311,  311,  311,  208,  297,  297,  306,  307,
  252,  215,  301,  297,  297,  297,  297,  297,  301,  301,
  262,  468,  209,  450,  450,  450,  472,  301,  301,  301,
  217,  301,  301,  225,  301,  286,  219,  262,  301,  301,
  301,  210,  301,  262,  220,  213,  371,  214,  301,  301,
  301,  301,  301,  301,  301,  301,  301,  652,  653,  301,
  301,  233,  286,  301,  301,  311,  252,  311,  100,  100,
  216,  301,  221,  222,  320,  255,  511,  301,  258,  301,
  126,  399,  399,  399,  399,  399,  699,  700,  301,  301,
  301,  301,  301,  301,  247,  575,  576,  320,  286,  286,
  127,  262,  391,  391,  391,  301,  262,  262,  320,  577,
  301,  399,  578,  301,  301,  262,  681,  301,  301,  688,
  579,  711,  176,  329,  320,  320,  320,  262,  270,  301,
  301,  677,  678,  580,  684,  685,  301,  301,  301,  301,
  301,  663,  664,  262,  263,  264,  329,  417,  417,  417,
  418,  419,  768,  769,  417,  417,  417,  329,  133,  133,
  133,  133,  133,  133,  133,  271,  581,  168,  133,  133,
  133,  286,   48,  329,  329,  329,  287,  262,  262,  262,
  262,  262,   49,   50,   51,  288,  420,  320,  289,  320,
  681,  290,  582,  688,  668,  669,  129,  772,  773,  262,
  450,  450,  133,  259,  294,  311,  295,  262,  252,  286,
  286,  311,  311,  127,  252,  252,  252,  316,  262,  262,
  296,  311,  311,   52,  311,  311,  333,  346,  334,  450,
  338,  311,  311,  311,  349,  311,  329,  450,  329,  456,
  456,  311,  311,  311,  361,  354,  311,  311,  311,  311,
  346,  378,  311,  311,  131,  380,  311,  311,  384,  382,
  383,  346,  388,  252,  311,  450,  450,  387,  252,  252,
  311,  394,  311,  262,  252,  252,  252,  252,  262,  262,
  399,  311,  311,  311,  311,  311,  311,  262,  252,  301,
  262,  302,  303,  304,  401,  262,  262,  282,  311,  408,
  262,  262,  416,  311,  262,  423,  311,  311,  430,  129,
  311,  311,  432,  437,  262,  458,  458,  262,  182,  183,
  367,  368,  311,  311,  459,  262,  460,  466,  473,  311,
  311,  311,  311,  311,  320,  476,  516,  517,  262,  520,
  346,  518,  346,  320,  320,  524,  320,  320,  525,  526,
  349,  527,  529,  450,  450,  549,  554,  320,  564,  567,
  565,  252,  566,  320,  320,  320,  569,  131,  320,  320,
  320,  262,  568,  349,  320,  320,  571,  463,  320,  588,
  645,  649,  651,  329,  349,  655,  320,  650,  262,  673,
  262,  674,  329,  329,  320,  329,  329,  262,  675,  676,
  698,  252,  692,  714,  704,  709,  329,  115,  320,  716,
  717,  718,  329,  329,  329,  724,  727,  329,  329,  329,
  320,  660,  729,  329,  329,  320,   40,  329,  320,  320,
   21,  731,  320,  733,  734,  329,  127,  127,  127,  127,
  127,  127,  127,  329,  320,  320,  127,  127,  127,  738,
  694,  799,  320,  320,  320,  320,  259,  329,  741,  748,
  751,  259,  259,  349,  756,  349,  781,  259,  794,  329,
  259,  821,  822,  818,  329,  823,  826,  329,  329,  827,
  127,  329,  286,  832,  833,  834,  835,  346,  836,  286,
  239,  842,  252,  329,  329,  168,  346,  346,  100,  346,
  346,  329,  329,  329,  329,  286,  199,  200,  201,  286,
  346,  450,  429,  262,   92,  100,  346,  346,  346,   59,
  115,  346,  346,  346,  450,  244,  450,  346,  346,  414,
  415,  346,  129,  129,  129,  129,  129,  129,  129,  346,
  691,   41,  129,  129,  129,   42,  147,  346,  244,  843,
  790,  317,  521,  230,  259,  532,  528,  632,  248,  774,
  272,  346,  286,  335,  482,  298,  800,  546,  548,  286,
  486,  558,  286,  346,  286,  402,  129,  715,  346,  542,
  246,  346,  346,  297,  656,  346,  557,  386,  720,  286,
  131,  131,  131,  131,  131,  131,  131,  346,  346,   43,
  131,  131,  131,   44,    0,  346,  346,  346,  346,    0,
  349,    0,    0,  503,  504,  505,  506,  507,    0,  349,
  349,    0,  349,  349,  252,  252,  252,  252,  252,  252,
  252,    0,    0,  349,  131,  252,  252,    0,  300,  349,
  349,  349,  315,  508,  349,  349,  349,    0,    0,  323,
  349,  349,  286,    0,  349,    0,    0,   45,    0,    0,
    0,    0,  349,    0,    0,    0,    0,    0,  252,    0,
  349,    0,   39,    5,    6,    7,    4,    5,    6,    7,
   45,    0,    0,    0,  349,    0,    0,    0,   45,    0,
  450,   45,    0,  369,    0,    0,  349,  450,    5,    6,
    7,  349,    0,    0,  349,  349,    0,    0,  349,    0,
    0,    0,    0,    0,    0,    8,    0,  450,    0,    8,
  349,  349,    0,    0,    0,    0,    0,  286,  349,  349,
  349,  349,    0,    9,   10,   11,   12,   13,   10,   11,
   12,   13,   14,  113,  113,  113,  113,  113,  113,  113,
    0,  286,  286,    0,  113,  113,   15,    0,   16,   10,
   11,   12,   13,    0,    0,   17,    0,    0,    0,    0,
   45,    0,    0,  241,    0,    0,   18,    0,  244,    0,
  450,  244,  244,  244,  244,  244,   19,  115,    0,  244,
  244,  244,  244,    0,  244,  244,  241,  244,  244,    0,
    0,    0,    0,    0,  244,  244,  244,  286,  244,  244,
   20,  244,  244,  244,  244,  244,  244,    0,    0,  244,
  244,  244,  244,    0,    0,  244,  244,    0,    0,  244,
  244,  286,  286,   91,    0,    0,    0,  244,    0,  286,
  286,    0,    0,  244,    0,  244,    0,    0,    0,    0,
    0,    0,  244,    0,  244,  244,  244,  244,  244,  244,
    0,    0,    0,    0,    0,    0,    0,  118,  119,  120,
    0,  244,    0,    0,    0,    0,  244,    0,  139,  244,
  244,    0,    0,  244,  244,    0,    0,    0,    0,  240,
  173,    0,    0,    0,    0,  244,  244,    0,    0,    0,
    0,    0,  244,  244,  244,    0,    0,    0,    0,    0,
   45,    0,  240,    0,   45,   45,   45,   45,    0,  286,
  286,   45,   45,   45,   45,    0,   45,   45,    0,   45,
   45,    0,    0,    0,    0,  450,   45,   45,   45,    0,
   45,    0,    0,    0,    0,    0,   45,   45,   45,    0,
    0,   45,   45,   45,   45,    0,    0,   45,   45,  450,
  450,   45,   45,    0,    0,    0,    0,    0,    0,   45,
    0,    0,    0,    0,    0,   45,    0,   45,    0,    0,
    0,    0,    0,    0,    0,    0,   45,   45,   45,   45,
   45,   45,  250,  251,    0,    0,    0,  254,    0,    0,
    0,    0,    0,   45,    0,    0,    0,  261,   45,    0,
    0,   45,   45,    0,    0,   45,   45,    0,  220,    0,
    0,    0,    0,    0,    0,    0,  241,   45,   45,    0,
  241,  241,  241,  241,   45,   45,   45,  241,  241,  241,
  241,  220,  241,  241,    0,  241,  241,  450,  450,    0,
    0,    0,    0,  241,  241,    0,  241,  241,    0,  241,
  241,  241,  241,  241,  241,    0,    0,  241,  241,  241,
  241,    0,    0,  241,  241,    0,    0,  241,  241,    0,
    0,    0,    0,    0,    0,  241,    0,    0,    0,    0,
    0,  241,    0,  241,    0,    0,    0,    0,    0,    0,
  241,    0,    0,    0,    0,    0,    0,  241,    0,    0,
    0,    0,  278,    0,    0,    0,    0,    0,    0,  241,
    0,    0,    0,    0,  241,    0,    0,  241,  241,    0,
    0,  241,    0,    0,    0,  278,    0,    0,    0,    0,
    0,    0,  240,  241,  241,    0,  240,  240,  240,  240,
  241,  241,  241,  240,  240,  240,  240,  148,  240,  240,
    0,  240,  240,    0,  222,    0,    0,    0,    0,  240,
  240,    0,  240,  240,    0,  240,  240,  240,  240,  240,
  240,  149,    0,  240,  240,  240,  240,  222,    0,  240,
  240,    0,    0,  240,  240,    0,    0,    0,    0,    0,
    0,  240,    0,    0,    0,    0,    0,  240,    0,  240,
    0,    0,    0,    0,    0,    0,  240,    0,    0,  150,
  151,  152,    0,  240,  153,  154,  155,    0,  156,    0,
    0,  145,  146,    0,    0,  240,    0,    0,    0,  157,
  240,    0,    0,  240,  240,    0,    0,  240,    0,    0,
    0,  252,  252,  252,  252,  252,  252,  252,    0,  240,
  240,  252,  252,  252,    0,  450,  240,  240,  240,    0,
  220,  220,  220,  220,  220,  220,  220,  220,  220,    0,
    0,    0,  220,  220,  220,  220,    0,  220,  220,  450,
  220,  220,  224,    0,    0,    0,    0,    0,    0,    0,
    0,  220,  220,    0,  220,  220,  220,  220,  220,  220,
    0,    0,  220,  220,  220,  224,    0,    0,  220,  220,
    0,    0,  220,    0,    0,    0,    0,  450,  450,  450,
  220,    0,  450,  450,  450,    0,  450,    0,  220,  450,
  450,    0,    0,    0,    0,    0,    0,  450,    0,    0,
    0,    0,  220,    0,    0,  252,  113,  113,  113,  113,
  113,  113,  113,    0,  220,  278,  115,  113,  113,  220,
    0,  278,  220,  220,    0,    0,  220,    0,  252,    0,
    0,  234,  235,  236,  237,  238,  239,  240,  220,  220,
    0,  278,  241,  242,    0,    0,  220,  220,    0,    0,
    0,    0,    0,  488,  490,  492,    0,    0,    0,    0,
  495,  496,    0,    0,    0,    0,  222,  222,  222,  222,
  222,  222,  222,  222,  222,    0,  225,    0,  222,  222,
  222,  222,    0,  222,  222,    0,  222,  222,    0,    0,
    0,  278,  278,  278,  278,  278,    0,  222,  222,  225,
  222,  222,  222,  222,  222,  222,  425,    0,  222,  222,
  222,    0,    0,  278,  222,  222,    0,    0,  222,    0,
    0,  278,    0,  543,    0,  544,  222,  545,    0,  425,
  547,    0,  278,  278,  222,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  222,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  286,
  222,    0,    0,    0,    0,  222,  286,    0,  222,  222,
  286,    0,  222,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  222,  222,  286,  286,  286,    0,
  282,    0,  222,  222,  224,  224,  224,  224,  224,  224,
  224,  224,  224,    0,    0,    0,  224,  224,  224,  224,
    0,  224,  224,  282,  224,  224,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  224,  224,    0,  224,  224,
  224,  224,  224,  224,    0,    0,  224,  224,  224,    0,
    0,    0,  224,  224,    0,    0,  224,    0,    0,  286,
    0,  286,    0,    0,  224,    0,    0,    0,  252,    0,
    0,    0,  224,  252,  252,    0,  719,    0,    0,  252,
  252,  252,  252,    0,    0,    0,  224,    0,    0,    0,
    0,    0,    0,    0,    0,  252,  252,    0,  224,    0,
    0,    0,    0,  224,    0,    0,  224,  224,    0,  252,
  224,    0,  252,  282,  272,    0,    0,    0,    0,    0,
  252,    0,  224,  224,    0,    0,    0,    0,    0,    0,
  224,  224,    0,  252,    0,    0,    0,  272,  225,  225,
  225,  225,  225,  225,  225,  225,  225,    0,    0,    0,
  225,  225,  225,  225,    0,  225,  225,    0,  225,  225,
    0,    0,    0,    0,    0,    0,  252,    0,    0,  225,
  225,    0,  225,  225,  225,  225,  225,  225,    0,    0,
  225,  225,  225,    0,    0,  252,  225,  225,    0,    0,
  225,    0,  252,    0,    0,  425,    0,    0,  225,  791,
  792,  793,    0,    0,    0,    0,  225,    0,    0,    0,
    0,    0,    0,    0,  286,    0,    0,    0,    0,    0,
  225,    0,    0,    0,    0,    0,    0,  272,    0,    0,
    0,    0,  225,    0,    0,    0,    0,  225,  286,  286,
  225,  225,    0,  234,  225,  425,  425,  425,  425,  425,
    0,    0,    0,  282,    0,    0,  225,  225,    0,  282,
  282,    0,    0,    0,  225,  225,  234,  425,    0,  282,
  282,    0,  282,  282,    0,  425,    0,    0,    0,  282,
  282,  282,    0,  282,    0,    0,  425,    0,    0,  282,
  282,  282,    0,    0,  282,  282,  282,  282,    0,  286,
  282,  282,    0,    0,  282,  282,    0,    0,    0,    0,
    0,    0,  282,    0,    0,    0,    0,    0,  282,    0,
  282,    0,    0,    0,    0,    0,  286,  286,    0,  282,
  282,  282,  282,  282,  282,    0,    0,   61,   62,   63,
   64,   65,    0,   66,    0,   67,  282,   68,   69,   70,
    0,  282,    0,    0,  282,  282,    0,  280,  282,  282,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  282,  282,    0,  272,  272,    0,    0,  282,  282,  282,
  280,   71,    0,  272,  272,    0,  272,  272,    0,    0,
    0,    0,    0,  272,  272,  272,    0,  272,   72,   73,
    0,    0,    0,  272,  272,  272,    0,    0,  272,  272,
  272,  272,    0,    0,  272,  272,    0,    0,  272,  272,
    0,    0,    0,    0,    0,    0,  272,    0,    0,    0,
    0,    0,  272,    0,  272,    0,    0,    0,    0,    0,
    0,    0,    0,  272,  272,  272,  272,  272,  272,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  272,    0,    0,    0,    0,  272,    0,    0,  272,  272,
  280,    0,  272,  272,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  272,  272,    0,    0,  405,    0,
    0,  272,  272,  272,    0,    0,  234,    0,  234,  234,
  234,  234,  234,  234,    0,    0,    0,  234,  234,  234,
  234,  405,  234,  234,    0,  234,  234,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  234,  234,    0,  234,
  234,  234,  234,  234,  234,    0,    0,  234,  234,  234,
    0,    0,    0,  234,  234,    0,    0,  234,    0,    0,
    0,    0,    0,    0,    0,  234,    0,    0,    0,    0,
    0,    0,    0,  234,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  234,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  234,
    0,    0,    0,    0,  234,    0,    0,  234,  234,    0,
    0,  234,    0,    0,    0,    0,    0,    0,    0,    0,
  401,    0,    0,  234,  234,    0,    0,  280,    0,    0,
    0,  234,  234,    0,    0,    0,  280,  280,    0,  280,
  280,    0,    0,  401,    0,    0,  280,  280,  280,    0,
  280,    0,    0,    0,    0,    0,  280,  280,  280,    0,
    0,  280,  280,  280,  280,    0,    0,  280,  280,    0,
    0,  280,  280,    0,    0,    0,    0,    0,    0,  280,
    0,    0,    0,    0,    0,  280,    0,  280,    0,    0,
    0,    0,    0,    0,    0,    0,  280,  280,  280,  280,
  280,  280,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  280,    0,    0,    0,    0,  280,    0,
    0,  280,  280,    0,    0,  280,  280,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  280,  280,    0,
    0,    0,    0,    0,  280,  280,  280,    0,    0,   52,
    0,  405,    0,    0,    0,    0,  405,  405,  405,    0,
    0,    0,  405,  405,  405,  405,    0,  405,  405,    0,
  405,  405,   52,    0,    0,    0,    0,    0,    0,    0,
    0,  405,    0,    0,    0,    0,    0,  405,  405,  405,
    0,    0,  405,  405,  405,    0,    0,    0,  405,  405,
    0,    0,  405,    0,    0,    0,    0,    0,    0,    0,
  405,    0,    0,  417,    0,    0,    0,    0,  405,    0,
    0,    0,    0,    0,    0,    0,    0,  403,  403,  403,
  403,  403,  405,    0,    0,    0,  417,    0,    0,    0,
    0,    0,    0,    0,  405,    0,    0,    0,    0,  405,
    0,    0,  405,  405,    0,    0,  405,  403,    0,    0,
    0,    0,   52,    0,    0,  239,    0,    0,  405,  405,
    0,    0,    0,  401,    0,    0,  405,  405,  401,  401,
  401,    0,    0,    0,  401,  401,  401,  401,  239,  401,
  401,    0,  401,  401,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  401,    0,    0,    0,    0,    0,  401,
  401,  401,    0,    0,  401,  401,  401,    0,    0,    0,
  401,  401,    0,    0,  401,    0,    0,    0,    0,    0,
    0,    0,  401,    0,    0,    0,    0,    0,    0,    0,
  401,    0,    0,    0,    0,    0,    0,    0,    0,  401,
  401,  401,  401,  401,  401,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  401,    0,    0,    0,
    0,  401,    0,    0,  401,  401,    0,    0,  401,  401,
    0,  252,    0,    0,    0,    0,    0,    0,    0,    0,
  401,  401,    0,    0,    0,    0,    0,    0,  401,  401,
    0,   52,   52,   52,  252,   52,   52,   52,   52,   52,
    0,    0,    0,   52,   52,   52,   52,    0,   52,   52,
    0,   52,   52,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   52,    0,    0,    0,    0,    0,   52,   52,
   52,    0,    0,   52,   52,   52,    0,    0,    0,   52,
   52,    0,    0,   52,    0,    0,    0,    0,    0,    0,
    0,   52,    0,    0,    0,    0,  417,    0,    0,   52,
  417,  417,  417,    0,    0,    0,    0,  417,  417,  417,
  417,    0,    0,   52,    0,    0,    0,    0,    0,    0,
    0,    0,  417,    0,    0,   52,    0,    0,    0,    0,
   52,    0,    0,   52,   52,    0,    0,   52,    0,    0,
    0,    0,    0,  234,    0,    0,    0,    0,  239,   52,
   52,    0,  239,  239,  239,  239,    0,   52,   52,  239,
  239,  239,  239,    0,  239,  239,  234,  239,  239,    0,
    0,    0,  417,  417,  417,  417,  417,    0,  239,  239,
    0,  239,  239,  239,  239,  239,  239,  259,    0,  239,
  239,  239,    0,    0,  417,  239,  239,    0,    0,  239,
    0,    0,  417,    0,    0,    0,    0,  239,    0,    0,
  259,    0,    0,  417,  417,  239,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  239,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  239,    0,    0,    0,    0,  239,    0,    0,  239,
  239,    0,    0,  239,    0,    0,  234,    0,    0,  237,
    0,    0,    0,    0,  252,  239,  239,    0,    0,  252,
  252,  252,    0,  239,  239,  252,  252,  252,  252,    0,
  252,  252,  237,  252,  252,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  252,  252,    0,  252,  252,  252,
  252,  252,  252,  278,    0,  252,  252,  252,    0,    0,
    0,  252,  252,    0,    0,  252,    0,    0,    0,    0,
    0,    0,    0,  252,    0,    0,  278,    0,    0,    0,
    0,  252,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  252,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  252,    0,    0,
    0,    0,  252,    0,    0,  252,  252,    0,    0,  252,
    0,    0,  237,    0,    0,  252,    0,    0,    0,    0,
    0,  252,  252,    0,    0,    0,    0,    0,    0,  252,
  252,    0,    0,    0,    0,    0,  234,    0,  252,  234,
  234,  234,  234,  234,    0,    0,    0,  234,  234,  234,
  234,    0,  234,  234,    0,  234,  234,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  234,    0,    0,    0,
    0,    0,  234,  234,  234,    0,    0,  234,  234,  234,
  259,    0,    0,  234,  234,  259,  259,  234,    0,    0,
    0,  259,  252,    0,  259,  234,    0,    0,    0,    0,
    0,    0,    0,  234,    0,    0,    0,  259,  259,    0,
    0,    0,    0,    0,    0,  252,    0,  234,    0,    0,
    0,  259,    0,    0,  259,    0,    0,    0,  252,  234,
    0,    0,  259,    0,  234,    0,    0,  234,  234,    0,
    0,  234,    0,    0,  437,  259,    0,    0,    0,    0,
    0,    0,  237,  234,  234,    0,  237,  237,  237,  237,
    0,  234,  234,  237,  237,  237,  237,  437,  237,  237,
    0,  237,  237,    0,    0,    0,    0,    0,  259,    0,
    0,    0,  237,    0,    0,    0,    0,    0,  237,  237,
  237,    0,    0,  237,  237,  237,  278,  259,    0,  237,
  237,    0,  278,  237,  259,    0,    0,    0,  418,    0,
    0,  237,    0,    0,    0,    0,    0,    0,    0,  237,
    0,    0,    0,  278,  278,    0,    0,    0,    0,    0,
    0,  418,    0,  237,    0,    0,    0,  278,    0,    0,
  278,    0,    0,    0,    0,  237,    0,    0,  278,    0,
  237,    0,    0,  237,  237,    0,    0,  237,    0,    0,
  404,  278,    0,    0,    0,    0,    0,    0,  252,  237,
  237,    0,    0,  252,  252,  252,    0,  237,  237,  252,
  252,  252,  252,  404,  252,  252,    0,  252,  252,    0,
    0,    0,    0,    0,  278,    0,    0,    0,  252,    0,
    0,    0,    0,    0,  252,  252,  252,    0,    0,  252,
  252,  252,    0,  278,    0,  252,  252,    0,    0,  252,
  278,    0,    0,    0,    0,    0,    0,  252,    0,    0,
    0,    0,    0,    0,    0,  252,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  252,    0,    0,    0,  252,
  252,  252,    0,    0,    0,    0,  252,  252,  252,  252,
    0,  252,    0,    0,    0,    0,  252,    0,    0,  252,
  252,  252,    0,  252,    0,    0,  259,    0,    0,    0,
    0,    0,    0,    0,    0,  252,  252,    0,    0,    0,
    0,    0,    0,  252,  252,    0,    0,  437,    0,  259,
    0,    0,  437,  437,  437,    0,    0,    0,  437,  437,
  437,  437,    0,  437,  437,    0,  437,  437,    0,    0,
    0,  252,  252,  252,  252,  252,    0,  437,    0,    0,
    0,    0,    0,  437,  437,  437,    0,    0,  437,  437,
  437,    0,    0,  252,  437,  437,    0,    0,  437,    0,
    0,  252,    0,    0,    0,    0,  437,    0,    0,    0,
    0,  418,  252,  252,  437,  418,  418,  418,    0,    0,
    0,    0,  418,  418,  418,  418,    0,    0,  437,    0,
    0,    0,    0,    0,    0,    0,    0,  418,    0,  259,
  437,    0,    0,    0,    0,  437,    0,    0,  437,  437,
    0,    0,  437,    0,    0,  259,    0,    0,    0,    0,
    0,    0,    0,  404,  437,  437,    0,    0,  404,  404,
  404,    0,  437,  437,  404,  404,  404,  404,  259,  404,
  404,    0,  404,  404,    0,    0,    0,  418,  418,  418,
  418,  418,    0,  404,    0,    0,    0,    0,    0,  404,
  404,  404,    0,    0,  404,  404,  404,    0,    0,  418,
  404,  404,    0,    0,  404,    0,    0,  418,    0,    0,
    0,    0,  404,    0,    0,    0,    0,    0,  418,  418,
  404,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  404,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  404,    0,    0,    0,
    0,  404,    0,    0,  404,  404,    0,    0,  404,  262,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  259,
  404,  404,    0,    0,  259,  259,  259,    0,  404,  404,
  259,    0,  262,  259,    0,  259,  259,    0,  259,  259,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  259,
    0,    0,    0,    0,    0,  259,  259,  259,  262,    0,
  259,  259,  259,    0,    0,    0,  259,  259,    0,    0,
  259,    0,    0,    0,    0,    0,    0,    0,  259,    0,
    0,  262,    0,    0,    0,    0,  259,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  259,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  259,    0,    0,    0,    0,  259,    0,    0,
  259,  259,  262,    0,  259,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  259,  259,    0,    0,
    0,    0,    0,    0,  259,  259,    0,    0,  259,    0,
    0,    0,    0,  259,  259,  259,    0,    0,    0,  259,
    0,    0,  259,    0,  259,  259,    0,  259,  259,    0,
    0,  278,    0,    0,    0,    0,    0,    0,  259,    0,
    0,    0,    0,    0,  259,  259,  259,    0,    0,  259,
  259,  259,    0,    0,  278,  259,  259,    0,    0,  259,
    0,    0,    0,    0,    0,    0,    0,  259,    0,    0,
    0,    0,    0,    0,    0,  259,    0,    0,    0,    0,
  278,    0,    0,    0,    0,    0,    0,    0,    0,  259,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  259,    0,  278,    0,    0,  259,    0,    0,  259,
  259,    0,    0,  259,    0,    0,    0,    0,    0,    0,
    0,    0,  262,    0,    0,  259,  259,  262,  262,  262,
    0,    0,    0,  259,  259,    0,  262,    0,  262,  262,
    0,  262,  262,    0,  278,    0,    0,    0,    0,    0,
    0,    0,  262,    0,    0,    0,    0,    0,  262,  262,
  262,    0,    0,  262,  262,  262,    0,    0,    0,  262,
  262,  262,  177,  262,    0,    0,  262,  262,  262,    0,
    0,  262,    0,    0,    0,  262,    0,  262,  262,  262,
  262,  262,    0,    0,    0,  175,    0,    0,    0,    0,
    0,  262,    0,  262,    0,    0,    0,  262,  262,  262,
    0,    0,  262,  262,  262,  262,    0,    0,  262,  262,
  262,  372,  262,  262,  262,    0,    0,  262,    0,    0,
  262,    0,    0,    0,    0,    0,    0,    0,  262,  262,
  262,    0,    0,    0,  372,    0,    0,  262,  262,    0,
    0,    0,  262,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  262,    0,    0,    0,    0,  262,
    0,    0,  262,  262,    0,    0,  262,    0,    0,    0,
    0,    0,    0,    0,  278,  177,    0,    0,  262,  262,
  278,  278,    0,    0,    0,    0,  262,  262,    0,    0,
  278,  278,    0,  278,  278,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  278,    0,    0,    0,    0,    0,
  278,  278,  278,    0,   49,  278,  278,  278,    0,    0,
    0,  278,  278,  278,  372,  278,    0,    0,    0,  278,
  278,    0,    0,  278,    0,    0,    0,   49,    0,  278,
  278,  278,  278,  278,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  278,    0,  278,    0,    0,    0,  278,
  278,  278,    0,  177,  278,  278,  278,  278,    0,    0,
  278,  278,  278,    0,  278,  278,  278,    0,    0,  278,
    0,    0,  278,    0,    0,    0,  175,    0,    0,    0,
  278,  278,  278,    0,    0,    0,    0,    0,    0,  278,
  278,    0,    0,    0,  278,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  278,    0,    0,    0,
    0,  278,  175,    0,  278,  278,    0,   49,  278,    0,
    0,  175,  175,    0,  175,  175,    0,    0,    0,    0,
  278,  278,    0,    0,    0,  175,  234,    0,  278,  278,
    0,  175,  175,  175,    0,    0,  175,  175,  175,    0,
    0,    0,  175,  175,    0,    0,  175,    0,    0,  234,
    0,  372,    0,    0,  175,    0,    0,    0,    0,    0,
  372,  372,  175,  372,  372,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  372,    0,  175,    0,    0,  168,
  372,  372,  372,    0,    0,  372,  372,  372,  175,    0,
    0,  372,  372,  175,    0,  372,  175,  175,    0,    0,
  175,    0,    0,  372,    0,    0,    0,    0,    0,    0,
    0,  372,  175,  175,    0,    0,    0,    0,    0,    0,
  175,  175,    0,    0,    0,  372,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  372,    0,    0,
    0,    0,  372,    0,    0,  372,  372,    0,    0,  372,
    0,    0,    0,    0,   49,    0,    0,    0,    0,    0,
    0,  372,  372,   49,   49,    0,   49,   49,    0,  372,
  372,    0,    0,    0,    0,    0,    0,   49,    0,    0,
    0,    0,    0,   49,   49,   49,    0,    0,   49,   49,
   49,    0,    0,    0,   49,   49,    0,    0,   49,    0,
    0,    0,    0,  175,    0,    0,   49,    0,    0,    0,
    0,    0,  175,  175,   49,  175,  175,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  175,    0,   49,    0,
    0,    0,  175,  175,  175,    0,    0,  175,  175,  175,
   49,    0,    0,  175,  175,   49,    0,  175,   49,   49,
    0,    0,   49,    0,    0,  175,    0,    0,    0,    0,
    0,    0,    0,  175,   49,   49,    0,    0,    0,    0,
    0,    0,   49,   49,    0,    0,    0,  175,    0,  234,
    0,  234,  234,  234,  234,  234,    0,    0,    0,  175,
  234,  234,  234,  234,  175,    0,    0,  175,  175,    0,
    0,  175,    0,    0,    0,    0,  234,  234,    0,    0,
    0,    0,    0,  175,  175,    0,  590,    0,    0,    0,
  234,  175,  175,  234,    0,  591,  592,    0,  593,  594,
    0,  234,    0,    0,    0,    0,    0,    0,    0,  595,
    0,    0,    0,    0,  234,  596,  339,  597,    0,    0,
  598,  599,  600,    0,    0,    0,  601,  602,    0,    0,
  603,    0,    0,    0,    0,    0,    0,    0,  604,    0,
    0,    0,    0,    0,    0,    0,  605,  234,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  606,    0,    0,    0,    0,    0,  234,    0,    0,    0,
    0,    0,  607,  234,    0,    0,    0,  608,    0,    0,
  609,  610,    0,    0,  611,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  612,    0,    0,
    0,    0,    0,    0,  613,  614,
};
static const YYINT yycheck[] = {                          3,
    3,   83,   10,  127,   79,   40,   33,   12,   13,  325,
  326,   40,   10,   10,   40,  370,   33,   10,   10,   40,
  340,   10,  348,   10,  207,   40,  431,   10,  192,  367,
  368,  123,  695,  299,   47,   10,   33,   33,   10,  730,
  432,  539,  205,  167,   10,  123,  123,  515,   44,  276,
   33,  277,   57,  123,   44,  674,  123,  445,  732,  223,
   33,   33,   10,  123,  531,  688,   71,   33,   10,  123,
   40,   33,   40,   40,  385,  231,   40,   82,  268,  698,
  204,   33,   44,  170,  265,  266,   40,  277,   40,  409,
  410,   40,   44,   60,   40,   33,  178,   40,   60,   61,
   62,   40,  226,  267,   41,  269,  426,   44,   60,  737,
   40,   60,    0,  804,   44,  123,  280,  390,  741,  430,
  783,   10,   10,   40,  390,  123,  624,   60,  740,  125,
   60,  123,  520,  807,   44,  125,   44,   44,   44,  450,
  227,   40,  266,   60,  268,   40,  462,   33,  553,  332,
  123,   44,   41,  123,  480,   44,  231,  281,  513,  283,
   33,   60,   40,  125,  390,   40,  329,   10,  636,  123,
  397,  123,  336,  125,   60,   61,   62,  644,   44,  571,
   33,   44,  390,  811,  308,  123,  350,   60,   61,   62,
  346,  355,   40,   33,   10,  125,  320,   44,   41,   10,
   25,   44,  814,  295,  123,   44,  123,   60,   61,   62,
  390,  300,   60,  337,  219,  125,  661,  125,  125,  125,
   60,   61,   62,  681,  261,  314,  537,  547,  362,  363,
   41,   56,  125,   44,  572,  257,   44,  123,  549,  363,
  404,   44,  247,  265,   10,  286,  287,  288,  412,  373,
  123,   41,   44,   44,   40,  267,  390,  421,   44,  125,
  390,   44,  125,  123,  428,  278,   33,   44,  392,  393,
  123,  346,  361,   44,  438,  312,  263,   61,  125,  403,
  738,  405,  269,  603,  729,   41,  125,  295,   44,  609,
  610,   41,  289,   60,   61,   62,  289,  263,  390,   10,
   33,  267,  268,  269,  379,  278,  289,  471,  274,  275,
  276,  277,  390,  391,  289,  439,  440,  125,  290,  291,
  390,  391,  125,  390,  290,  291,  278,   60,   61,   62,
  390,  723,  304,  125,  125,  307,  390,  501,  304,  125,
  464,  307,  125,  315,   10,   10,  470,  368,  125,  315,
  302,  303,  300,  477,  125,  390,  328,  521,  356,   44,
  318,  390,  328,  390,  361,  391,  314,   10,  256,  257,
  258,  259,  260,  390,  361,  390,  500,  390,  361,  543,
  544,  545,  390,  380,  381,  705,  361,  707,  380,  361,
   33,  380,  390,   10,  390,  361,  560,  380,  286,  287,
  288,  268,  794,   41,  720,  380,  798,  274,  380,   41,
  574,  299,   44,  361,  380,  387,   10,  541,   33,  308,
  390,  387,  390,  390,  391,  313,  390,  391,  390,  391,
  318,  319,  320,  321,  322,  559,  390,  561,  390,  391,
  125,  390,  391,  332,  390,  391,   10,  390,  336,  573,
  338,  390,  391,   10,  302,  303,   10,  345,  123,  534,
  390,  391,   10,  587,  539,  308,   10,  787,  356,  789,
   10,  390,  391,  390,  391,  262,   10,  264,  366,   10,
  390,  370,  371,  372,  300,   10,  375,  376,  377,  332,
  379,  390,  391,  382,  383,  390,  391,  308,  314,   33,
  505,  390,  390,  363,  390,  391,   40,   41,  123,  633,
   44,  586,  390,  391,  638,  390,  391,  390,  391,   41,
   10,  332,   44,  289,  529,   10,   60,  370,  371,  372,
  390,  613,  375,  376,  377,   10,  379,  390,  391,  382,
  383,  665,  390,  391,   10,  361,  670,  390,   10,  624,
  390,  391,  716,  717,  718,  679,   44,  632,   40,  370,
  371,  372,  686,  353,  375,  376,  377,  260,  379,  359,
  360,  382,  383,  339,  340,  341,  342,  343,   60,  390,
   41,   33,  746,   44,  748,  749,  750,  390,  391,  123,
   10,  125,   10,  286,  287,  288,  760,  308,  722,   10,
  390,  725,  766,  369,  390,  363,  770,  612,   60,   61,
   62,  775,  362,  363,  778,   10,   41,  781,  363,   44,
  263,  332,   33,  390,  391,  268,  269,  363,   10,   40,
   41,  274,  390,   44,  277,  759,   41,  125,   10,   44,
  390,   33,  724,  767,   10,  390,  289,  771,  390,   60,
  655,   10,  776,   41,  390,  779,   44,  390,  391,  370,
  371,  372,   10,  278,  375,  376,  377,   40,  379,  751,
  285,  382,  383,  339,  340,  341,  342,  343,   33,  390,
   40,  346,  347,  348,  349,  350,  351,  352,   10,  390,
  391,  356,  357,  358,  382,  383,  339,  340,  341,  342,
  343,  825,   40,  369,  828,  829,  830,  831,  390,  714,
   75,   33,  123,  390,  125,  353,  354,  355,  361,  390,
   85,   86,   87,  337,   41,  390,  369,   44,   90,  263,
   92,  123,  289,  125,   40,  269,  270,  380,  381,  390,
  391,  262,  263,  264,  278,  279,  280,  265,  282,  283,
  266,  285,  390,  309,  836,  289,  290,  291,   62,  293,
  764,  764,  315,  316,  317,  299,  300,  301,  302,  303,
  304,  305,  306,  307,  266,  123,  310,  311,  275,  276,
  314,  315,  339,  340,  341,  342,  343,   45,  322,   47,
  391,  353,   10,  391,  328,   10,  330,  359,  360,  339,
  340,  341,  342,  343,  361,  339,  340,  341,  342,  343,
  344,  260,  369,  391,  179,   33,  390,  391,  599,  600,
  302,  303,  356,  380,  390,  391,   44,  361,  390,  369,
  364,  365,  373,  374,  368,  369,   33,  286,  287,  288,
  390,  391,   60,   61,   62,  391,  380,  381,  390,  391,
   10,   60,  263,  387,  388,  389,  390,  391,  269,  270,
   10,  382,  391,   60,   61,   62,  387,  278,  279,  280,
   44,  282,  283,  390,  285,  363,  269,   10,  289,  290,
  291,  391,  293,   33,  277,  391,  278,  391,  299,  300,
  301,  302,  303,  304,  305,  306,  307,  390,  391,  310,
  311,  356,  390,  314,  315,  123,  274,  125,  390,  391,
  391,  322,  305,  306,   10,  391,  437,  328,   41,  330,
  390,  339,  340,  341,  342,  343,  390,  391,  339,  340,
  341,  342,  343,  344,  268,  290,  291,   33,  390,  391,
   10,  263,  286,  287,  288,  356,  268,  269,   44,  304,
  361,  369,  307,  364,  365,  277,  737,  368,  369,  740,
  315,  390,  391,   10,   60,   61,   62,  289,   47,  380,
  381,  390,  391,  328,  390,  391,  387,  388,  389,  390,
  391,  390,  391,  199,  200,  201,   33,  267,  268,  353,
  354,  355,  390,  391,  274,  275,  276,   44,  346,  347,
  348,  349,  350,  351,  352,  390,  361,   33,  356,  357,
  358,   40,  261,   60,   61,   62,   40,  339,  340,  341,
  342,  343,  271,  272,  273,   40,  390,  123,   40,  125,
  811,   40,  387,  814,  390,  391,   10,  390,  391,  361,
  390,  391,  390,   10,  391,  263,  391,  369,  268,  390,
  391,  269,  270,  123,  274,  275,  276,   41,  380,  381,
  391,  279,  280,  312,  282,  283,  391,   10,   62,  269,
   41,  289,  290,  291,  390,  293,  123,  277,  125,  390,
  391,  299,  300,  301,  300,  390,  304,  305,  306,  307,
   33,  381,  310,  311,   10,  263,  314,  315,  390,  315,
   41,   44,  361,  263,  322,  305,  306,  323,  268,  269,
  328,  378,  330,  263,  274,  275,  276,  277,  268,  269,
  390,  339,  340,  341,  342,  343,  344,  277,   10,  294,
  263,  296,  297,  298,  391,  268,  269,  390,  356,   41,
  290,  291,   41,  361,  277,   41,  364,  365,  268,  123,
  368,  369,  390,  369,  304,  390,  391,  307,   86,   87,
  303,  304,  380,  381,  285,  315,  390,  269,  391,  387,
  388,  389,  390,  391,  270,  373,   61,   61,  328,  392,
  123,   61,  125,  279,  280,   47,  282,  283,  390,  390,
   10,   47,  380,  390,  391,  269,   41,  293,  390,   41,
  391,  361,  391,  299,  300,  301,  391,  123,  304,  305,
  306,  361,   62,   33,  310,  311,  289,  390,  314,  123,
  391,  391,  391,  270,   44,  380,  322,  390,  361,  284,
  380,  284,  279,  280,  330,  282,  283,  387,  284,  390,
  284,  123,  390,  380,  391,  391,  293,   10,  344,  391,
  391,  391,  299,  300,  301,  285,   10,  304,  305,  306,
  356,  390,   47,  310,  311,  361,   10,  314,  364,  365,
   10,  281,  368,  281,   40,  322,  346,  347,  348,  349,
  350,  351,  352,  330,  380,  381,  356,  357,  358,  392,
  368,   10,  388,  389,  390,  391,  263,  344,  392,  390,
  285,  268,  269,  123,   41,  125,  391,  274,  289,  356,
  277,   41,   41,  390,  361,   41,   10,  364,  365,   10,
  390,  368,   33,  391,   41,   41,   41,  270,  285,   40,
  337,   41,   10,  380,  381,   10,  279,  280,  390,  282,
  283,  388,  389,  390,  391,  390,  118,  119,  120,   60,
  293,  390,   10,  268,   10,  380,  299,  300,  301,   10,
  123,  304,  305,  306,  391,   10,  368,  310,  311,   10,
   10,  314,  346,  347,  348,  349,  350,  351,  352,  322,
  601,  125,  356,  357,  358,    3,   72,  330,   33,  836,
  751,  257,  450,  165,  361,  466,  459,  550,  178,  734,
  218,  344,   33,  275,  407,  246,  125,  493,  498,   40,
  415,  511,  123,  356,  125,  344,  390,  624,  361,  485,
  173,  364,  365,  245,  586,  368,  510,  322,  632,   60,
  346,  347,  348,  349,  350,  351,  352,  380,  381,    3,
  356,  357,  358,    3,   -1,  388,  389,  390,  391,   -1,
  270,   -1,   -1,  339,  340,  341,  342,  343,   -1,  279,
  280,   -1,  282,  283,  346,  347,  348,  349,  350,  351,
  352,   -1,   -1,  293,  390,  357,  358,   -1,  250,  299,
  300,  301,  254,  369,  304,  305,  306,   -1,   -1,  261,
  310,  311,  123,   -1,  314,   -1,   -1,   10,   -1,   -1,
   -1,   -1,  322,   -1,   -1,   -1,   -1,   -1,  390,   -1,
  330,   -1,  256,  257,  258,  259,  256,  257,  258,  259,
   33,   -1,   -1,   -1,  344,   -1,   -1,   -1,   41,   -1,
   33,   44,   -1,  305,   -1,   -1,  356,   40,  257,  258,
  259,  361,   -1,   -1,  364,  365,   -1,   -1,  368,   -1,
   -1,   -1,   -1,   -1,   -1,  299,   -1,   60,   -1,  299,
  380,  381,   -1,   -1,   -1,   -1,   -1,  278,  388,  389,
  390,  391,   -1,  313,  318,  319,  320,  321,  318,  319,
  320,  321,  322,  346,  347,  348,  349,  350,  351,  352,
   -1,  302,  303,   -1,  357,  358,  336,   -1,  338,  318,
  319,  320,  321,   -1,   -1,  345,   -1,   -1,   -1,   -1,
  123,   -1,   -1,   10,   -1,   -1,  356,   -1,  263,   -1,
  123,  266,  267,  268,  269,  270,  366,  390,   -1,  274,
  275,  276,  277,   -1,  279,  280,   33,  282,  283,   -1,
   -1,   -1,   -1,   -1,  289,  290,  291,  278,  293,  294,
  390,  296,  297,  298,  299,  300,  301,   -1,   -1,  304,
  305,  306,  307,   -1,   -1,  310,  311,   -1,   -1,  314,
  315,  302,  303,   24,   -1,   -1,   -1,  322,   -1,  390,
  391,   -1,   -1,  328,   -1,  330,   -1,   -1,   -1,   -1,
   -1,   -1,  337,   -1,  339,  340,  341,  342,  343,  344,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   58,   59,   60,
   -1,  356,   -1,   -1,   -1,   -1,  361,   -1,   69,  364,
  365,   -1,   -1,  368,  369,   -1,   -1,   -1,   -1,   10,
   81,   -1,   -1,   -1,   -1,  380,  381,   -1,   -1,   -1,
   -1,   -1,  387,  388,  389,   -1,   -1,   -1,   -1,   -1,
  263,   -1,   33,   -1,  267,  268,  269,  270,   -1,  390,
  391,  274,  275,  276,  277,   -1,  279,  280,   -1,  282,
  283,   -1,   -1,   -1,   -1,  278,  289,  290,  291,   -1,
  293,   -1,   -1,   -1,   -1,   -1,  299,  300,  301,   -1,
   -1,  304,  305,  306,  307,   -1,   -1,  310,  311,  302,
  303,  314,  315,   -1,   -1,   -1,   -1,   -1,   -1,  322,
   -1,   -1,   -1,   -1,   -1,  328,   -1,  330,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  339,  340,  341,  342,
  343,  344,  183,  184,   -1,   -1,   -1,  188,   -1,   -1,
   -1,   -1,   -1,  356,   -1,   -1,   -1,  198,  361,   -1,
   -1,  364,  365,   -1,   -1,  368,  369,   -1,   10,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  263,  380,  381,   -1,
  267,  268,  269,  270,  387,  388,  389,  274,  275,  276,
  277,   33,  279,  280,   -1,  282,  283,  390,  391,   -1,
   -1,   -1,   -1,  290,  291,   -1,  293,  294,   -1,  296,
  297,  298,  299,  300,  301,   -1,   -1,  304,  305,  306,
  307,   -1,   -1,  310,  311,   -1,   -1,  314,  315,   -1,
   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,   -1,   -1,
   -1,  328,   -1,  330,   -1,   -1,   -1,   -1,   -1,   -1,
  337,   -1,   -1,   -1,   -1,   -1,   -1,  344,   -1,   -1,
   -1,   -1,   10,   -1,   -1,   -1,   -1,   -1,   -1,  356,
   -1,   -1,   -1,   -1,  361,   -1,   -1,  364,  365,   -1,
   -1,  368,   -1,   -1,   -1,   33,   -1,   -1,   -1,   -1,
   -1,   -1,  263,  380,  381,   -1,  267,  268,  269,  270,
  387,  388,  389,  274,  275,  276,  277,  308,  279,  280,
   -1,  282,  283,   -1,   10,   -1,   -1,   -1,   -1,  290,
  291,   -1,  293,  294,   -1,  296,  297,  298,  299,  300,
  301,  332,   -1,  304,  305,  306,  307,   33,   -1,  310,
  311,   -1,   -1,  314,  315,   -1,   -1,   -1,   -1,   -1,
   -1,  322,   -1,   -1,   -1,   -1,   -1,  328,   -1,  330,
   -1,   -1,   -1,   -1,   -1,   -1,  337,   -1,   -1,  370,
  371,  372,   -1,  344,  375,  376,  377,   -1,  379,   -1,
   -1,  382,  383,   -1,   -1,  356,   -1,   -1,   -1,  390,
  361,   -1,   -1,  364,  365,   -1,   -1,  368,   -1,   -1,
   -1,  346,  347,  348,  349,  350,  351,  352,   -1,  380,
  381,  356,  357,  358,   -1,  308,  387,  388,  389,   -1,
  262,  263,  264,  265,  266,  267,  268,  269,  270,   -1,
   -1,   -1,  274,  275,  276,  277,   -1,  279,  280,  332,
  282,  283,   10,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  293,  294,   -1,  296,  297,  298,  299,  300,  301,
   -1,   -1,  304,  305,  306,   33,   -1,   -1,  310,  311,
   -1,   -1,  314,   -1,   -1,   -1,   -1,  370,  371,  372,
  322,   -1,  375,  376,  377,   -1,  379,   -1,  330,  382,
  383,   -1,   -1,   -1,   -1,   -1,   -1,  390,   -1,   -1,
   -1,   -1,  344,   -1,   -1,   10,  346,  347,  348,  349,
  350,  351,  352,   -1,  356,  263,  356,  357,  358,  361,
   -1,  269,  364,  365,   -1,   -1,  368,   -1,   33,   -1,
   -1,  346,  347,  348,  349,  350,  351,  352,  380,  381,
   -1,  289,  357,  358,   -1,   -1,  388,  389,   -1,   -1,
   -1,   -1,   -1,  417,  418,  419,   -1,   -1,   -1,   -1,
  424,  425,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
  266,  267,  268,  269,  270,   -1,   10,   -1,  274,  275,
  276,  277,   -1,  279,  280,   -1,  282,  283,   -1,   -1,
   -1,  339,  340,  341,  342,  343,   -1,  293,  294,   33,
  296,  297,  298,  299,  300,  301,   10,   -1,  304,  305,
  306,   -1,   -1,  361,  310,  311,   -1,   -1,  314,   -1,
   -1,  369,   -1,  487,   -1,  489,  322,  491,   -1,   33,
  494,   -1,  380,  381,  330,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  344,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   33,
  356,   -1,   -1,   -1,   -1,  361,   40,   -1,  364,  365,
   44,   -1,  368,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  380,  381,   60,   61,   62,   -1,
   10,   -1,  388,  389,  262,  263,  264,  265,  266,  267,
  268,  269,  270,   -1,   -1,   -1,  274,  275,  276,  277,
   -1,  279,  280,   33,  282,  283,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  293,  294,   -1,  296,  297,
  298,  299,  300,  301,   -1,   -1,  304,  305,  306,   -1,
   -1,   -1,  310,  311,   -1,   -1,  314,   -1,   -1,  123,
   -1,  125,   -1,   -1,  322,   -1,   -1,   -1,  263,   -1,
   -1,   -1,  330,  268,  269,   -1,  630,   -1,   -1,  274,
  275,  276,  277,   -1,   -1,   -1,  344,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  290,  291,   -1,  356,   -1,
   -1,   -1,   -1,  361,   -1,   -1,  364,  365,   -1,  304,
  368,   -1,  307,  123,   10,   -1,   -1,   -1,   -1,   -1,
  315,   -1,  380,  381,   -1,   -1,   -1,   -1,   -1,   -1,
  388,  389,   -1,  328,   -1,   -1,   -1,   33,  262,  263,
  264,  265,  266,  267,  268,  269,  270,   -1,   -1,   -1,
  274,  275,  276,  277,   -1,  279,  280,   -1,  282,  283,
   -1,   -1,   -1,   -1,   -1,   -1,  361,   -1,   -1,  293,
  294,   -1,  296,  297,  298,  299,  300,  301,   -1,   -1,
  304,  305,  306,   -1,   -1,  380,  310,  311,   -1,   -1,
  314,   -1,  387,   -1,   -1,  289,   -1,   -1,  322,  753,
  754,  755,   -1,   -1,   -1,   -1,  330,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  278,   -1,   -1,   -1,   -1,   -1,
  344,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,   -1,
   -1,   -1,  356,   -1,   -1,   -1,   -1,  361,  302,  303,
  364,  365,   -1,   10,  368,  339,  340,  341,  342,  343,
   -1,   -1,   -1,  263,   -1,   -1,  380,  381,   -1,  269,
  270,   -1,   -1,   -1,  388,  389,   33,  361,   -1,  279,
  280,   -1,  282,  283,   -1,  369,   -1,   -1,   -1,  289,
  290,  291,   -1,  293,   -1,   -1,  380,   -1,   -1,  299,
  300,  301,   -1,   -1,  304,  305,  306,  307,   -1,  363,
  310,  311,   -1,   -1,  314,  315,   -1,   -1,   -1,   -1,
   -1,   -1,  322,   -1,   -1,   -1,   -1,   -1,  328,   -1,
  330,   -1,   -1,   -1,   -1,   -1,  390,  391,   -1,  339,
  340,  341,  342,  343,  344,   -1,   -1,  323,  324,  325,
  326,  327,   -1,  329,   -1,  331,  356,  333,  334,  335,
   -1,  361,   -1,   -1,  364,  365,   -1,   10,  368,  369,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  380,  381,   -1,  269,  270,   -1,   -1,  387,  388,  389,
   33,  367,   -1,  279,  280,   -1,  282,  283,   -1,   -1,
   -1,   -1,   -1,  289,  290,  291,   -1,  293,  384,  385,
   -1,   -1,   -1,  299,  300,  301,   -1,   -1,  304,  305,
  306,  307,   -1,   -1,  310,  311,   -1,   -1,  314,  315,
   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,   -1,
   -1,   -1,  328,   -1,  330,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  339,  340,  341,  342,  343,  344,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  356,   -1,   -1,   -1,   -1,  361,   -1,   -1,  364,  365,
  123,   -1,  368,  369,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  380,  381,   -1,   -1,   10,   -1,
   -1,  387,  388,  389,   -1,   -1,  263,   -1,  265,  266,
  267,  268,  269,  270,   -1,   -1,   -1,  274,  275,  276,
  277,   33,  279,  280,   -1,  282,  283,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  293,  294,   -1,  296,
  297,  298,  299,  300,  301,   -1,   -1,  304,  305,  306,
   -1,   -1,   -1,  310,  311,   -1,   -1,  314,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  330,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  344,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  356,
   -1,   -1,   -1,   -1,  361,   -1,   -1,  364,  365,   -1,
   -1,  368,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   10,   -1,   -1,  380,  381,   -1,   -1,  270,   -1,   -1,
   -1,  388,  389,   -1,   -1,   -1,  279,  280,   -1,  282,
  283,   -1,   -1,   33,   -1,   -1,  289,  290,  291,   -1,
  293,   -1,   -1,   -1,   -1,   -1,  299,  300,  301,   -1,
   -1,  304,  305,  306,  307,   -1,   -1,  310,  311,   -1,
   -1,  314,  315,   -1,   -1,   -1,   -1,   -1,   -1,  322,
   -1,   -1,   -1,   -1,   -1,  328,   -1,  330,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  339,  340,  341,  342,
  343,  344,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  356,   -1,   -1,   -1,   -1,  361,   -1,
   -1,  364,  365,   -1,   -1,  368,  369,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  380,  381,   -1,
   -1,   -1,   -1,   -1,  387,  388,  389,   -1,   -1,   10,
   -1,  263,   -1,   -1,   -1,   -1,  268,  269,  270,   -1,
   -1,   -1,  274,  275,  276,  277,   -1,  279,  280,   -1,
  282,  283,   33,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  293,   -1,   -1,   -1,   -1,   -1,  299,  300,  301,
   -1,   -1,  304,  305,  306,   -1,   -1,   -1,  310,  311,
   -1,   -1,  314,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  322,   -1,   -1,   10,   -1,   -1,   -1,   -1,  330,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  339,  340,  341,
  342,  343,  344,   -1,   -1,   -1,   33,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  356,   -1,   -1,   -1,   -1,  361,
   -1,   -1,  364,  365,   -1,   -1,  368,  369,   -1,   -1,
   -1,   -1,  123,   -1,   -1,   10,   -1,   -1,  380,  381,
   -1,   -1,   -1,  263,   -1,   -1,  388,  389,  268,  269,
  270,   -1,   -1,   -1,  274,  275,  276,  277,   33,  279,
  280,   -1,  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,  299,
  300,  301,   -1,   -1,  304,  305,  306,   -1,   -1,   -1,
  310,  311,   -1,   -1,  314,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  322,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  330,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  339,
  340,  341,  342,  343,  344,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  356,   -1,   -1,   -1,
   -1,  361,   -1,   -1,  364,  365,   -1,   -1,  368,  369,
   -1,   10,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  380,  381,   -1,   -1,   -1,   -1,   -1,   -1,  388,  389,
   -1,  262,  263,  264,   33,  266,  267,  268,  269,  270,
   -1,   -1,   -1,  274,  275,  276,  277,   -1,  279,  280,
   -1,  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,  299,  300,
  301,   -1,   -1,  304,  305,  306,   -1,   -1,   -1,  310,
  311,   -1,   -1,  314,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  322,   -1,   -1,   -1,   -1,  263,   -1,   -1,  330,
  267,  268,  269,   -1,   -1,   -1,   -1,  274,  275,  276,
  277,   -1,   -1,  344,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  289,   -1,   -1,  356,   -1,   -1,   -1,   -1,
  361,   -1,   -1,  364,  365,   -1,   -1,  368,   -1,   -1,
   -1,   -1,   -1,   10,   -1,   -1,   -1,   -1,  263,  380,
  381,   -1,  267,  268,  269,  270,   -1,  388,  389,  274,
  275,  276,  277,   -1,  279,  280,   33,  282,  283,   -1,
   -1,   -1,  339,  340,  341,  342,  343,   -1,  293,  294,
   -1,  296,  297,  298,  299,  300,  301,   10,   -1,  304,
  305,  306,   -1,   -1,  361,  310,  311,   -1,   -1,  314,
   -1,   -1,  369,   -1,   -1,   -1,   -1,  322,   -1,   -1,
   33,   -1,   -1,  380,  381,  330,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  344,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  356,   -1,   -1,   -1,   -1,  361,   -1,   -1,  364,
  365,   -1,   -1,  368,   -1,   -1,  123,   -1,   -1,   10,
   -1,   -1,   -1,   -1,  263,  380,  381,   -1,   -1,  268,
  269,  270,   -1,  388,  389,  274,  275,  276,  277,   -1,
  279,  280,   33,  282,  283,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  293,  294,   -1,  296,  297,  298,
  299,  300,  301,   10,   -1,  304,  305,  306,   -1,   -1,
   -1,  310,  311,   -1,   -1,  314,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  322,   -1,   -1,   33,   -1,   -1,   -1,
   -1,  330,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  344,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  356,   -1,   -1,
   -1,   -1,  361,   -1,   -1,  364,  365,   -1,   -1,  368,
   -1,   -1,  123,   -1,   -1,   10,   -1,   -1,   -1,   -1,
   -1,  380,  381,   -1,   -1,   -1,   -1,   -1,   -1,  388,
  389,   -1,   -1,   -1,   -1,   -1,  263,   -1,   33,  266,
  267,  268,  269,  270,   -1,   -1,   -1,  274,  275,  276,
  277,   -1,  279,  280,   -1,  282,  283,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  293,   -1,   -1,   -1,
   -1,   -1,  299,  300,  301,   -1,   -1,  304,  305,  306,
  263,   -1,   -1,  310,  311,  268,  269,  314,   -1,   -1,
   -1,  274,   10,   -1,  277,  322,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  330,   -1,   -1,   -1,  290,  291,   -1,
   -1,   -1,   -1,   -1,   -1,   33,   -1,  344,   -1,   -1,
   -1,  304,   -1,   -1,  307,   -1,   -1,   -1,  123,  356,
   -1,   -1,  315,   -1,  361,   -1,   -1,  364,  365,   -1,
   -1,  368,   -1,   -1,   10,  328,   -1,   -1,   -1,   -1,
   -1,   -1,  263,  380,  381,   -1,  267,  268,  269,  270,
   -1,  388,  389,  274,  275,  276,  277,   33,  279,  280,
   -1,  282,  283,   -1,   -1,   -1,   -1,   -1,  361,   -1,
   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,  299,  300,
  301,   -1,   -1,  304,  305,  306,  263,  380,   -1,  310,
  311,   -1,  269,  314,  387,   -1,   -1,   -1,   10,   -1,
   -1,  322,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  330,
   -1,   -1,   -1,  290,  291,   -1,   -1,   -1,   -1,   -1,
   -1,   33,   -1,  344,   -1,   -1,   -1,  304,   -1,   -1,
  307,   -1,   -1,   -1,   -1,  356,   -1,   -1,  315,   -1,
  361,   -1,   -1,  364,  365,   -1,   -1,  368,   -1,   -1,
   10,  328,   -1,   -1,   -1,   -1,   -1,   -1,  263,  380,
  381,   -1,   -1,  268,  269,  270,   -1,  388,  389,  274,
  275,  276,  277,   33,  279,  280,   -1,  282,  283,   -1,
   -1,   -1,   -1,   -1,  361,   -1,   -1,   -1,  293,   -1,
   -1,   -1,   -1,   -1,  299,  300,  301,   -1,   -1,  304,
  305,  306,   -1,  380,   -1,  310,  311,   -1,   -1,  314,
  387,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  330,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  263,   -1,   -1,   -1,  344,
  268,  269,   -1,   -1,   -1,   -1,  274,  275,  276,  277,
   -1,  356,   -1,   -1,   -1,   -1,  361,   -1,   -1,  364,
  365,  289,   -1,  368,   -1,   -1,   10,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  380,  381,   -1,   -1,   -1,
   -1,   -1,   -1,  388,  389,   -1,   -1,  263,   -1,   33,
   -1,   -1,  268,  269,  270,   -1,   -1,   -1,  274,  275,
  276,  277,   -1,  279,  280,   -1,  282,  283,   -1,   -1,
   -1,  339,  340,  341,  342,  343,   -1,  293,   -1,   -1,
   -1,   -1,   -1,  299,  300,  301,   -1,   -1,  304,  305,
  306,   -1,   -1,  361,  310,  311,   -1,   -1,  314,   -1,
   -1,  369,   -1,   -1,   -1,   -1,  322,   -1,   -1,   -1,
   -1,  263,  380,  381,  330,  267,  268,  269,   -1,   -1,
   -1,   -1,  274,  275,  276,  277,   -1,   -1,  344,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  289,   -1,  123,
  356,   -1,   -1,   -1,   -1,  361,   -1,   -1,  364,  365,
   -1,   -1,  368,   -1,   -1,   10,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  263,  380,  381,   -1,   -1,  268,  269,
  270,   -1,  388,  389,  274,  275,  276,  277,   33,  279,
  280,   -1,  282,  283,   -1,   -1,   -1,  339,  340,  341,
  342,  343,   -1,  293,   -1,   -1,   -1,   -1,   -1,  299,
  300,  301,   -1,   -1,  304,  305,  306,   -1,   -1,  361,
  310,  311,   -1,   -1,  314,   -1,   -1,  369,   -1,   -1,
   -1,   -1,  322,   -1,   -1,   -1,   -1,   -1,  380,  381,
  330,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  344,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  356,   -1,   -1,   -1,
   -1,  361,   -1,   -1,  364,  365,   -1,   -1,  368,   10,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,
  380,  381,   -1,   -1,  268,  269,  270,   -1,  388,  389,
  274,   -1,   33,  277,   -1,  279,  280,   -1,  282,  283,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  293,
   -1,   -1,   -1,   -1,   -1,  299,  300,  301,   10,   -1,
  304,  305,  306,   -1,   -1,   -1,  310,  311,   -1,   -1,
  314,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,
   -1,   33,   -1,   -1,   -1,   -1,  330,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  344,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  356,   -1,   -1,   -1,   -1,  361,   -1,   -1,
  364,  365,  123,   -1,  368,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  380,  381,   -1,   -1,
   -1,   -1,   -1,   -1,  388,  389,   -1,   -1,  263,   -1,
   -1,   -1,   -1,  268,  269,  270,   -1,   -1,   -1,  274,
   -1,   -1,  277,   -1,  279,  280,   -1,  282,  283,   -1,
   -1,   10,   -1,   -1,   -1,   -1,   -1,   -1,  293,   -1,
   -1,   -1,   -1,   -1,  299,  300,  301,   -1,   -1,  304,
  305,  306,   -1,   -1,   33,  310,  311,   -1,   -1,  314,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  330,   -1,   -1,   -1,   -1,
   10,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  344,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  356,   -1,   33,   -1,   -1,  361,   -1,   -1,  364,
  365,   -1,   -1,  368,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  263,   -1,   -1,  380,  381,  268,  269,  270,
   -1,   -1,   -1,  388,  389,   -1,  277,   -1,  279,  280,
   -1,  282,  283,   -1,  123,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,  299,  300,
  301,   -1,   -1,  304,  305,  306,   -1,   -1,   -1,  310,
  311,  263,   10,  314,   -1,   -1,  268,  269,  270,   -1,
   -1,  322,   -1,   -1,   -1,  277,   -1,  279,  280,  330,
  282,  283,   -1,   -1,   -1,   33,   -1,   -1,   -1,   -1,
   -1,  293,   -1,  344,   -1,   -1,   -1,  299,  300,  301,
   -1,   -1,  304,  305,  306,  356,   -1,   -1,  310,  311,
  361,   10,  314,  364,  365,   -1,   -1,  368,   -1,   -1,
  322,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  330,  380,
  381,   -1,   -1,   -1,   33,   -1,   -1,  388,  389,   -1,
   -1,   -1,  344,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  356,   -1,   -1,   -1,   -1,  361,
   -1,   -1,  364,  365,   -1,   -1,  368,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  263,  123,   -1,   -1,  380,  381,
  269,  270,   -1,   -1,   -1,   -1,  388,  389,   -1,   -1,
  279,  280,   -1,  282,  283,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,
  299,  300,  301,   -1,   10,  304,  305,  306,   -1,   -1,
   -1,  310,  311,  263,  123,  314,   -1,   -1,   -1,  269,
  270,   -1,   -1,  322,   -1,   -1,   -1,   33,   -1,  279,
  280,  330,  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  293,   -1,  344,   -1,   -1,   -1,  299,
  300,  301,   -1,   10,  304,  305,  306,  356,   -1,   -1,
  310,  311,  361,   -1,  314,  364,  365,   -1,   -1,  368,
   -1,   -1,  322,   -1,   -1,   -1,   33,   -1,   -1,   -1,
  330,  380,  381,   -1,   -1,   -1,   -1,   -1,   -1,  388,
  389,   -1,   -1,   -1,  344,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  356,   -1,   -1,   -1,
   -1,  361,  270,   -1,  364,  365,   -1,  123,  368,   -1,
   -1,  279,  280,   -1,  282,  283,   -1,   -1,   -1,   -1,
  380,  381,   -1,   -1,   -1,  293,   10,   -1,  388,  389,
   -1,  299,  300,  301,   -1,   -1,  304,  305,  306,   -1,
   -1,   -1,  310,  311,   -1,   -1,  314,   -1,   -1,   33,
   -1,  270,   -1,   -1,  322,   -1,   -1,   -1,   -1,   -1,
  279,  280,  330,  282,  283,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  293,   -1,  344,   -1,   -1,   33,
  299,  300,  301,   -1,   -1,  304,  305,  306,  356,   -1,
   -1,  310,  311,  361,   -1,  314,  364,  365,   -1,   -1,
  368,   -1,   -1,  322,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  330,  380,  381,   -1,   -1,   -1,   -1,   -1,   -1,
  388,  389,   -1,   -1,   -1,  344,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  356,   -1,   -1,
   -1,   -1,  361,   -1,   -1,  364,  365,   -1,   -1,  368,
   -1,   -1,   -1,   -1,  270,   -1,   -1,   -1,   -1,   -1,
   -1,  380,  381,  279,  280,   -1,  282,  283,   -1,  388,
  389,   -1,   -1,   -1,   -1,   -1,   -1,  293,   -1,   -1,
   -1,   -1,   -1,  299,  300,  301,   -1,   -1,  304,  305,
  306,   -1,   -1,   -1,  310,  311,   -1,   -1,  314,   -1,
   -1,   -1,   -1,  270,   -1,   -1,  322,   -1,   -1,   -1,
   -1,   -1,  279,  280,  330,  282,  283,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  293,   -1,  344,   -1,
   -1,   -1,  299,  300,  301,   -1,   -1,  304,  305,  306,
  356,   -1,   -1,  310,  311,  361,   -1,  314,  364,  365,
   -1,   -1,  368,   -1,   -1,  322,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  330,  380,  381,   -1,   -1,   -1,   -1,
   -1,   -1,  388,  389,   -1,   -1,   -1,  344,   -1,  263,
   -1,  265,  266,  267,  268,  269,   -1,   -1,   -1,  356,
  274,  275,  276,  277,  361,   -1,   -1,  364,  365,   -1,
   -1,  368,   -1,   -1,   -1,   -1,  290,  291,   -1,   -1,
   -1,   -1,   -1,  380,  381,   -1,  270,   -1,   -1,   -1,
  304,  388,  389,  307,   -1,  279,  280,   -1,  282,  283,
   -1,  315,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  293,
   -1,   -1,   -1,   -1,  328,  299,  300,  301,   -1,   -1,
  304,  305,  306,   -1,   -1,   -1,  310,  311,   -1,   -1,
  314,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  330,  361,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  344,   -1,   -1,   -1,   -1,   -1,  380,   -1,   -1,   -1,
   -1,   -1,  356,  387,   -1,   -1,   -1,  361,   -1,   -1,
  364,  365,   -1,   -1,  368,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  381,   -1,   -1,
   -1,   -1,   -1,   -1,  388,  389,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 392
#define YYUNDFTOKEN 565
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'!'",0,0,0,0,0,0,"'('","')'",0,0,"','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
0,"'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"PASS","BLOCK","MATCH","SCRUB","RETURN","IN","OS","OUT","LOG",
"QUICK","ON","FROM","TO","FLAGS","RETURNRST","RETURNICMP","RETURNICMP6","PROTO",
"INET","INET6","ALL","ANY","ICMPTYPE","ICMP6TYPE","CODE","KEEP","MODULATE",
"STATE","PORT","RDR","NAT","BINAT","ARROW","NODF","MINTTL","ERROR","ALLOWOPTS",
"FASTROUTE","FILENAME","ROUTETO","DUPTO","REPLYTO","NO","LABEL","SCHEDULE",
"NOROUTE","URPFFAILED","FRAGMENT","USER","GROUP","MAXMSS","MAXIMUM","TTL","TOS",
"DSCP","DROP","TABLE","TRACKER","REASSEMBLE","FRAGDROP","FRAGCROP","ANCHOR",
"NATANCHOR","RDRANCHOR","BINATANCHOR","SET","OPTIMIZATION","TIMEOUT","LIMIT",
"LOGINTERFACE","BLOCKPOLICY","RANDOMID","REQUIREORDER","SYNPROXY",
"FINGERPRINTS","NOSYNC","DEBUG","SKIP","HOSTID","ANTISPOOF","FOR","INCLUDE",
"BITMASK","RANDOM","SOURCEHASH","ROUNDROBIN","STATICPORT","PROBABILITY","ALTQ",
"CBQ","CODEL","PRIQ","HFSC","FAIRQ","BANDWIDTH","TBRSIZE","LINKSHARE",
"REALTIME","UPPERLIMIT","QUEUE","PRIORITY","QLIMIT","HOGS","BUCKETS","RTABLE",
"TARGET","INTERVAL","DNPIPE","DNQUEUE","LOAD","RULESET_OPTIMIZATION","PRIO",
"STICKYADDRESS","MAXSRCSTATES","MAXSRCNODES","SOURCETRACK","GLOBAL","RULE",
"MAXSRCCONN","MAXSRCCONNRATE","OVERLOAD","FLUSH","SLOPPY","TAGGED","TAG",
"IFBOUND","FLOATING","STATEPOLICY","STATEDEFAULTS","ROUTE","SETTOS","DIVERTTO",
"DIVERTREPLY","STRING","NUMBER","PORTBINARY",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : ruleset",
"ruleset :",
"ruleset : ruleset include '\\n'",
"ruleset : ruleset '\\n'",
"ruleset : ruleset option '\\n'",
"ruleset : ruleset scrubrule '\\n'",
"ruleset : ruleset natrule '\\n'",
"ruleset : ruleset binatrule '\\n'",
"ruleset : ruleset pfrule '\\n'",
"ruleset : ruleset anchorrule '\\n'",
"ruleset : ruleset loadrule '\\n'",
"ruleset : ruleset altqif '\\n'",
"ruleset : ruleset queuespec '\\n'",
"ruleset : ruleset varset '\\n'",
"ruleset : ruleset antispoof '\\n'",
"ruleset : ruleset tabledef '\\n'",
"ruleset : '{' fakeanchor '}' '\\n'",
"ruleset : ruleset error '\\n'",
"include : INCLUDE STRING",
"fakeanchor : fakeanchor '\\n'",
"fakeanchor : fakeanchor anchorrule '\\n'",
"fakeanchor : fakeanchor binatrule '\\n'",
"fakeanchor : fakeanchor natrule '\\n'",
"fakeanchor : fakeanchor pfrule '\\n'",
"fakeanchor : fakeanchor error '\\n'",
"optimizer : string",
"option : SET OPTIMIZATION STRING",
"option : SET RULESET_OPTIMIZATION optimizer",
"option : SET TIMEOUT timeout_spec",
"option : SET TIMEOUT '{' optnl timeout_list '}'",
"option : SET LIMIT limit_spec",
"option : SET LIMIT '{' optnl limit_list '}'",
"option : SET LOGINTERFACE stringall",
"option : SET HOSTID number",
"option : SET BLOCKPOLICY DROP",
"option : SET BLOCKPOLICY RETURN",
"option : SET REQUIREORDER yesno",
"option : SET FINGERPRINTS STRING",
"option : SET STATEPOLICY statelock",
"option : SET DEBUG STRING",
"option : SET SKIP interface",
"option : SET STATEDEFAULTS state_opt_list",
"stringall : STRING",
"stringall : ALL",
"string : STRING string",
"string : STRING",
"varstring : numberstring varstring",
"varstring : numberstring",
"numberstring : NUMBER",
"numberstring : STRING",
"varset : STRING '=' varstring",
"anchorname : STRING",
"anchorname :",
"pfa_anchorlist :",
"pfa_anchorlist : pfa_anchorlist '\\n'",
"pfa_anchorlist : pfa_anchorlist pfrule '\\n'",
"pfa_anchorlist : pfa_anchorlist anchorrule '\\n'",
"$$1 :",
"pfa_anchor : '{' $$1 '\\n' pfa_anchorlist '}'",
"pfa_anchor :",
"anchorrule : ANCHOR anchorname dir quick interface af proto fromto filter_opts pfa_anchor",
"anchorrule : NATANCHOR string interface af proto fromto rtable",
"anchorrule : RDRANCHOR string interface af proto fromto rtable",
"anchorrule : BINATANCHOR string interface af proto fromto rtable",
"loadrule : LOAD ANCHOR string FROM string",
"scrubaction : no SCRUB",
"scrubrule : scrubaction dir logquick interface af proto fromto scrub_opts",
"$$2 :",
"scrub_opts : $$2 scrub_opts_l",
"scrub_opts :",
"scrub_opts_l : scrub_opts_l scrub_opt",
"scrub_opts_l : scrub_opt",
"scrub_opt : NODF",
"scrub_opt : MINTTL NUMBER",
"scrub_opt : MAXMSS NUMBER",
"scrub_opt : SETTOS tos",
"scrub_opt : fragcache",
"scrub_opt : REASSEMBLE STRING",
"scrub_opt : RANDOMID",
"scrub_opt : RTABLE NUMBER",
"scrub_opt : not TAGGED string",
"fragcache : FRAGMENT REASSEMBLE",
"fragcache : FRAGMENT FRAGCROP",
"fragcache : FRAGMENT FRAGDROP",
"antispoof : ANTISPOOF logquick antispoof_ifspc af antispoof_opts",
"antispoof_ifspc : FOR antispoof_if",
"antispoof_ifspc : FOR '{' optnl antispoof_iflst '}'",
"antispoof_iflst : antispoof_if optnl",
"antispoof_iflst : antispoof_iflst comma antispoof_if optnl",
"antispoof_if : if_item",
"antispoof_if : '(' if_item ')'",
"$$3 :",
"antispoof_opts : $$3 antispoof_opts_l",
"antispoof_opts :",
"antispoof_opts_l : antispoof_opts_l antispoof_opt",
"antispoof_opts_l : antispoof_opt",
"antispoof_opt : label",
"antispoof_opt : TRACKER number",
"antispoof_opt : RTABLE NUMBER",
"not : '!'",
"not :",
"tabledef : TABLE '<' STRING '>' table_opts",
"$$4 :",
"table_opts : $$4 table_opts_l",
"table_opts :",
"table_opts_l : table_opts_l table_opt",
"table_opts_l : table_opt",
"table_opt : STRING",
"table_opt : '{' optnl '}'",
"table_opt : '{' optnl host_list '}'",
"table_opt : FILENAME STRING",
"altqif : ALTQ interface queue_opts QUEUE qassign",
"queuespec : QUEUE STRING interface queue_opts qassign",
"$$5 :",
"queue_opts : $$5 queue_opts_l",
"queue_opts :",
"queue_opts_l : queue_opts_l queue_opt",
"queue_opts_l : queue_opt",
"queue_opt : BANDWIDTH bandwidth",
"queue_opt : PRIORITY NUMBER",
"queue_opt : QLIMIT NUMBER",
"queue_opt : scheduler",
"queue_opt : TBRSIZE NUMBER",
"bandwidth : STRING",
"bandwidth : NUMBER",
"scheduler : CBQ",
"scheduler : CBQ '(' cbqflags_list ')'",
"scheduler : PRIQ",
"scheduler : PRIQ '(' priqflags_list ')'",
"scheduler : HFSC",
"scheduler : HFSC '(' hfsc_opts ')'",
"scheduler : FAIRQ",
"scheduler : FAIRQ '(' fairq_opts ')'",
"scheduler : CODEL",
"scheduler : CODEL '(' codel_opts ')'",
"cbqflags_list : cbqflags_item",
"cbqflags_list : cbqflags_list comma cbqflags_item",
"cbqflags_item : STRING",
"priqflags_list : priqflags_item",
"priqflags_list : priqflags_list comma priqflags_item",
"priqflags_item : STRING",
"$$6 :",
"hfsc_opts : $$6 hfscopts_list",
"hfscopts_list : hfscopts_item",
"hfscopts_list : hfscopts_list comma hfscopts_item",
"hfscopts_item : LINKSHARE bandwidth",
"hfscopts_item : LINKSHARE '(' bandwidth comma NUMBER comma bandwidth ')'",
"hfscopts_item : REALTIME bandwidth",
"hfscopts_item : REALTIME '(' bandwidth comma NUMBER comma bandwidth ')'",
"hfscopts_item : UPPERLIMIT bandwidth",
"hfscopts_item : UPPERLIMIT '(' bandwidth comma NUMBER comma bandwidth ')'",
"hfscopts_item : STRING",
"$$7 :",
"fairq_opts : $$7 fairqopts_list",
"fairqopts_list : fairqopts_item",
"fairqopts_list : fairqopts_list comma fairqopts_item",
"fairqopts_item : LINKSHARE bandwidth",
"fairqopts_item : LINKSHARE '(' bandwidth number bandwidth ')'",
"fairqopts_item : HOGS bandwidth",
"fairqopts_item : BUCKETS number",
"fairqopts_item : STRING",
"$$8 :",
"codel_opts : $$8 codelopts_list",
"codelopts_list : codelopts_item",
"codelopts_list : codelopts_list comma codelopts_item",
"codelopts_item : INTERVAL number",
"codelopts_item : TARGET number",
"codelopts_item : STRING",
"qassign :",
"qassign : qassign_item",
"qassign : '{' optnl qassign_list '}'",
"qassign_list : qassign_item optnl",
"qassign_list : qassign_list comma qassign_item optnl",
"qassign_item : STRING",
"pfrule : action dir logquick interface route af proto fromto filter_opts",
"$$9 :",
"filter_opts : $$9 filter_opts_l",
"filter_opts :",
"filter_opts_l : filter_opts_l filter_opt",
"filter_opts_l : filter_opt",
"filter_opt : USER uids",
"filter_opt : GROUP gids",
"filter_opt : flags",
"filter_opt : icmpspec",
"filter_opt : PRIO NUMBER",
"filter_opt : TOS tos",
"filter_opt : dscp",
"filter_opt : keep",
"filter_opt : TRACKER number",
"filter_opt : FRAGMENT",
"filter_opt : ALLOWOPTS",
"filter_opt : label",
"filter_opt : schedule",
"filter_opt : qname",
"filter_opt : DNPIPE number",
"filter_opt : DNPIPE '(' number ')'",
"filter_opt : DNPIPE '(' number comma number ')'",
"filter_opt : DNQUEUE number",
"filter_opt : DNQUEUE '(' number comma number ')'",
"filter_opt : DNQUEUE '(' number ')'",
"filter_opt : TAG string",
"filter_opt : not TAGGED string",
"filter_opt : PROBABILITY probability",
"filter_opt : RTABLE NUMBER",
"filter_opt : DIVERTTO portplain",
"filter_opt : DIVERTTO STRING PORT portplain",
"filter_opt : DIVERTREPLY",
"filter_opt : filter_sets",
"filter_sets : SET '(' filter_sets_l ')'",
"filter_sets : SET filter_set",
"filter_sets_l : filter_sets_l comma filter_set",
"filter_sets_l : filter_set",
"filter_set : prio",
"prio : PRIO NUMBER",
"prio : PRIO '(' NUMBER comma NUMBER ')'",
"probability : STRING",
"probability : NUMBER",
"action : PASS",
"action : MATCH",
"action : BLOCK blockspec",
"blockspec :",
"blockspec : DROP",
"blockspec : RETURNRST",
"blockspec : RETURNRST '(' TTL NUMBER ')'",
"blockspec : RETURNICMP",
"blockspec : RETURNICMP6",
"blockspec : RETURNICMP '(' reticmpspec ')'",
"blockspec : RETURNICMP6 '(' reticmp6spec ')'",
"blockspec : RETURNICMP '(' reticmpspec comma reticmp6spec ')'",
"blockspec : RETURN",
"reticmpspec : STRING",
"reticmpspec : NUMBER",
"reticmp6spec : STRING",
"reticmp6spec : NUMBER",
"dir :",
"dir : IN",
"dir : OUT",
"quick :",
"quick : QUICK",
"logquick :",
"logquick : log",
"logquick : QUICK",
"logquick : log QUICK",
"logquick : QUICK log",
"log : LOG",
"log : LOG '(' logopts ')'",
"logopts : logopt",
"logopts : logopts comma logopt",
"logopt : ALL",
"logopt : USER",
"logopt : GROUP",
"logopt : TO string",
"interface :",
"interface : ON if_item_not",
"interface : ON '{' optnl if_list '}'",
"if_list : if_item_not optnl",
"if_list : if_list comma if_item_not optnl",
"if_item_not : not if_item",
"if_item : STRING",
"af :",
"af : INET",
"af : INET6",
"proto :",
"proto : PROTO proto_item",
"proto : PROTO '{' optnl proto_list '}'",
"proto_list : proto_item optnl",
"proto_list : proto_list comma proto_item optnl",
"proto_item : protoval",
"protoval : STRING",
"protoval : NUMBER",
"fromto : ALL",
"fromto : from os to",
"os :",
"os : OS xos",
"os : OS '{' optnl os_list '}'",
"xos : STRING",
"os_list : xos optnl",
"os_list : os_list comma xos optnl",
"from :",
"from : FROM ipportspec",
"to :",
"to : TO ipportspec",
"ipportspec : ipspec",
"ipportspec : ipspec PORT portspec",
"ipportspec : PORT portspec",
"optnl : '\\n' optnl",
"optnl :",
"ipspec : ANY",
"ipspec : xhost",
"ipspec : '{' optnl host_list '}'",
"toipspec : TO ipspec",
"toipspec :",
"host_list : ipspec optnl",
"host_list : host_list comma ipspec optnl",
"xhost : not host",
"xhost : not NOROUTE",
"xhost : not URPFFAILED",
"host : STRING",
"host : STRING '-' STRING",
"host : STRING '/' NUMBER",
"host : NUMBER '/' NUMBER",
"host : dynaddr",
"host : dynaddr '/' NUMBER",
"host : '<' STRING '>'",
"number : NUMBER",
"number : STRING",
"dynaddr : '(' STRING ')'",
"portspec : port_item",
"portspec : '{' optnl port_list '}'",
"port_list : port_item optnl",
"port_list : port_list comma port_item optnl",
"port_item : portrange",
"port_item : unaryop portrange",
"port_item : portrange PORTBINARY portrange",
"portplain : numberstring",
"portrange : numberstring",
"uids : uid_item",
"uids : '{' optnl uid_list '}'",
"uid_list : uid_item optnl",
"uid_list : uid_list comma uid_item optnl",
"uid_item : uid",
"uid_item : unaryop uid",
"uid_item : uid PORTBINARY uid",
"uid : STRING",
"uid : NUMBER",
"gids : gid_item",
"gids : '{' optnl gid_list '}'",
"gid_list : gid_item optnl",
"gid_list : gid_list comma gid_item optnl",
"gid_item : gid",
"gid_item : unaryop gid",
"gid_item : gid PORTBINARY gid",
"gid : STRING",
"gid : NUMBER",
"flag : STRING",
"flags : FLAGS flag '/' flag",
"flags : FLAGS '/' flag",
"flags : FLAGS ANY",
"icmpspec : ICMPTYPE icmp_item",
"icmpspec : ICMPTYPE '{' optnl icmp_list '}'",
"icmpspec : ICMP6TYPE icmp6_item",
"icmpspec : ICMP6TYPE '{' optnl icmp6_list '}'",
"icmp_list : icmp_item optnl",
"icmp_list : icmp_list comma icmp_item optnl",
"icmp6_list : icmp6_item optnl",
"icmp6_list : icmp6_list comma icmp6_item optnl",
"icmp_item : icmptype",
"icmp_item : icmptype CODE STRING",
"icmp_item : icmptype CODE NUMBER",
"icmp6_item : icmp6type",
"icmp6_item : icmp6type CODE STRING",
"icmp6_item : icmp6type CODE NUMBER",
"icmptype : STRING",
"icmptype : NUMBER",
"icmp6type : STRING",
"icmp6type : NUMBER",
"tos : STRING",
"tos : NUMBER",
"dscp : DSCP STRING",
"sourcetrack : SOURCETRACK",
"sourcetrack : SOURCETRACK GLOBAL",
"sourcetrack : SOURCETRACK RULE",
"statelock : IFBOUND",
"statelock : FLOATING",
"keep : NO STATE",
"keep : KEEP STATE state_opt_spec",
"keep : MODULATE STATE state_opt_spec",
"keep : SYNPROXY STATE state_opt_spec",
"flush :",
"flush : FLUSH",
"flush : FLUSH GLOBAL",
"state_opt_spec : '(' state_opt_list ')'",
"state_opt_spec :",
"state_opt_list : state_opt_item",
"state_opt_list : state_opt_list comma state_opt_item",
"state_opt_item : MAXIMUM NUMBER",
"state_opt_item : NOSYNC",
"state_opt_item : MAXSRCSTATES NUMBER",
"state_opt_item : MAXSRCCONN NUMBER",
"state_opt_item : MAXSRCCONNRATE NUMBER '/' NUMBER",
"state_opt_item : OVERLOAD '<' STRING '>' flush",
"state_opt_item : MAXSRCNODES NUMBER",
"state_opt_item : sourcetrack",
"state_opt_item : statelock",
"state_opt_item : SLOPPY",
"state_opt_item : STRING NUMBER",
"label : LABEL STRING",
"schedule : SCHEDULE STRING",
"qname : QUEUE STRING",
"qname : QUEUE '(' STRING ')'",
"qname : QUEUE '(' STRING comma STRING ')'",
"no :",
"no : NO",
"portstar : numberstring",
"redirspec : host",
"redirspec : '{' optnl redir_host_list '}'",
"redir_host_list : host optnl",
"redir_host_list : redir_host_list comma host optnl",
"redirpool :",
"redirpool : ARROW redirspec",
"redirpool : ARROW redirspec PORT portstar",
"hashkey :",
"hashkey : string",
"$$10 :",
"pool_opts : $$10 pool_opts_l",
"pool_opts :",
"pool_opts_l : pool_opts_l pool_opt",
"pool_opts_l : pool_opt",
"pool_opt : BITMASK",
"pool_opt : RANDOM",
"pool_opt : SOURCEHASH hashkey",
"pool_opt : ROUNDROBIN",
"pool_opt : STATICPORT",
"pool_opt : STICKYADDRESS",
"redirection :",
"redirection : ARROW host",
"redirection : ARROW host PORT portstar",
"natpasslog :",
"natpasslog : PASS",
"natpasslog : PASS log",
"natpasslog : log",
"nataction : no NAT natpasslog",
"nataction : no RDR natpasslog",
"natrule : nataction interface af proto fromto tag tagged rtable redirpool pool_opts",
"binatrule : no BINAT natpasslog interface af proto FROM ipspec toipspec tag tagged rtable redirection",
"tag :",
"tag : TAG STRING",
"tagged :",
"tagged : not TAGGED string",
"rtable :",
"rtable : RTABLE NUMBER",
"route_host : STRING",
"route_host : '(' STRING host ')'",
"route_host_list : route_host optnl",
"route_host_list : route_host_list comma route_host optnl",
"routespec : route_host",
"routespec : '{' optnl route_host_list '}'",
"route :",
"route : FASTROUTE",
"route : ROUTETO routespec pool_opts",
"route : REPLYTO routespec pool_opts",
"route : DUPTO routespec pool_opts",
"timeout_spec : STRING NUMBER",
"timeout_spec : INTERVAL NUMBER",
"timeout_list : timeout_list comma timeout_spec optnl",
"timeout_list : timeout_spec optnl",
"limit_spec : STRING NUMBER",
"limit_list : limit_list comma limit_spec optnl",
"limit_list : limit_spec optnl",
"comma : ','",
"comma :",
"yesno : NO",
"yesno : STRING",
"unaryop : '='",
"unaryop : '!' '='",
"unaryop : '<' '='",
"unaryop : '<'",
"unaryop : '>' '='",
"unaryop : '>'",

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
#line 4666 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"

int
yyerror(const char *fmt, ...)
{
	va_list		 ap;

	file->errors++;
	va_start(ap, fmt);
	fprintf(stderr, "%s:%d: ", file->name, yylval.lineno);
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	va_end(ap);
	return (0);
}

int
disallow_table(struct node_host *h, const char *fmt)
{
	for (; h != NULL; h = h->next)
		if (h->addr.type == PF_ADDR_TABLE) {
			yyerror(fmt, h->addr.v.tblname);
			return (1);
		}
	return (0);
}

int
disallow_urpf_failed(struct node_host *h, const char *fmt)
{
	for (; h != NULL; h = h->next)
		if (h->addr.type == PF_ADDR_URPFFAILED) {
			yyerror(fmt);
			return (1);
		}
	return (0);
}

int
disallow_alias(struct node_host *h, const char *fmt)
{
	for (; h != NULL; h = h->next)
		if (DYNIF_MULTIADDR(h->addr)) {
			yyerror(fmt, h->addr.v.tblname);
			return (1);
		}
	return (0);
}

int
rule_consistent(struct pf_rule *r, int anchor_call)
{
	int	problems = 0;

	switch (r->action) {
	case PF_PASS:
	case PF_DROP:
	case PF_SCRUB:
	case PF_NOSCRUB:
		problems = filter_consistent(r, anchor_call);
		break;
	case PF_NAT:
	case PF_NONAT:
		problems = nat_consistent(r);
		break;
	case PF_RDR:
	case PF_NORDR:
		problems = rdr_consistent(r);
		break;
	case PF_BINAT:
	case PF_NOBINAT:
	default:
		break;
	}
	return (problems);
}

int
filter_consistent(struct pf_rule *r, int anchor_call)
{
	int	problems = 0;

	if (r->proto != IPPROTO_TCP && r->proto != IPPROTO_UDP &&
	    (r->src.port_op || r->dst.port_op)) {
		yyerror("port only applies to tcp/udp");
		problems++;
	}
	if (r->proto != IPPROTO_ICMP && r->proto != IPPROTO_ICMPV6 &&
	    (r->type || r->code)) {
		yyerror("icmp-type/code only applies to icmp");
		problems++;
	}
	if (!r->af && (r->type || r->code)) {
		yyerror("must indicate address family with icmp-type/code");
		problems++;
	}
	if (r->overload_tblname[0] &&
	    r->max_src_conn == 0 && r->max_src_conn_rate.seconds == 0) {
		yyerror("'overload' requires 'max-src-conn' "
		    "or 'max-src-conn-rate'");
		problems++;
	}
	if ((r->proto == IPPROTO_ICMP && r->af == AF_INET6) ||
	    (r->proto == IPPROTO_ICMPV6 && r->af == AF_INET)) {
		yyerror("proto %s doesn't match address family %s",
		    r->proto == IPPROTO_ICMP ? "icmp" : "icmp6",
		    r->af == AF_INET ? "inet" : "inet6");
		problems++;
	}
	if (r->allow_opts && r->action != PF_PASS) {
		yyerror("allow-opts can only be specified for pass rules");
		problems++;
	}
	if (r->rule_flag & PFRULE_FRAGMENT && (r->src.port_op ||
	    r->dst.port_op || r->flagset || r->type || r->code)) {
		yyerror("fragments can be filtered only on IP header fields");
		problems++;
	}
	if (r->rule_flag & PFRULE_RETURNRST && r->proto != IPPROTO_TCP) {
		yyerror("return-rst can only be applied to TCP rules");
		problems++;
	}
	if (r->max_src_nodes && !(r->rule_flag & PFRULE_RULESRCTRACK)) {
		yyerror("max-src-nodes requires 'source-track rule'");
		problems++;
	}
	if (r->action == PF_DROP && r->keep_state) {
		yyerror("keep state on block rules doesn't make sense");
		problems++;
	}
	if (r->rule_flag & PFRULE_STATESLOPPY &&
	    (r->keep_state == PF_STATE_MODULATE ||
	    r->keep_state == PF_STATE_SYNPROXY)) {
		yyerror("sloppy state matching cannot be used with "
		    "synproxy state or modulate state");
		problems++;
	}
	if ((r->rule_flag & PFRULE_TOS) && (r->rule_flag & PFRULE_DSCP)) {
		yyerror("tos and dscp cannot be used together");
		problems++;
	}
	if (r->dnpipe && r->pdnpipe && !r->direction) {
		yyerror("dummynet cannot be specified without direction");
		problems++;
	}

	return (-problems);
}

int
nat_consistent(struct pf_rule *r)
{
	return (0);	/* yeah! */
}

int
rdr_consistent(struct pf_rule *r)
{
	int			 problems = 0;

	if (r->proto != IPPROTO_TCP && r->proto != IPPROTO_UDP) {
		if (r->src.port_op) {
			yyerror("src port only applies to tcp/udp");
			problems++;
		}
		if (r->dst.port_op) {
			yyerror("dst port only applies to tcp/udp");
			problems++;
		}
		if (r->rpool.proxy_port[0]) {
			yyerror("rpool port only applies to tcp/udp");
			problems++;
		}
	}
	if (r->dst.port_op &&
	    r->dst.port_op != PF_OP_EQ && r->dst.port_op != PF_OP_RRG) {
		yyerror("invalid port operator for rdr destination port");
		problems++;
	}
	return (-problems);
}

int
process_tabledef(char *name, struct table_opts *opts)
{
	struct pfr_buffer	 ab;
	struct node_tinit	*ti;

	bzero(&ab, sizeof(ab));
	ab.pfrb_type = PFRB_ADDRS;
	SIMPLEQ_FOREACH(ti, &opts->init_nodes, entries) {
		if (ti->file)
			if (pfr_buf_load(&ab, ti->file, 0, append_addr)) {
				if (errno)
					yyerror("cannot load \"%s\": %s",
					    ti->file, strerror(errno));
				else
					yyerror("file \"%s\" contains bad data",
					    ti->file);
				goto _error;
			}
		if (ti->host)
			if (append_addr_host(&ab, ti->host, 0, 0)) {
				yyerror("cannot create address buffer: %s",
				    strerror(errno));
				goto _error;
			}
	}
	if (pf->opts & PF_OPT_VERBOSE)
		print_tabledef(name, opts->flags, opts->init_addr,
		    &opts->init_nodes);
	if (!(pf->opts & PF_OPT_NOACTION) &&
	    pfctl_define_table(name, opts->flags, opts->init_addr,
	    pf->anchor->name, &ab, pf->anchor->ruleset.tticket)) {
		yyerror("cannot define table %s: %s", name,
		    pfr_strerror(errno));
		goto _error;
	}
	pf->tdirty = 1;
	pfr_buf_clear(&ab);
	return (0);
_error:
	pfr_buf_clear(&ab);
	return (-1);
}

struct keywords {
	const char	*k_name;
	int		 k_val;
};

/* macro gore, but you should've seen the prior indentation nightmare... */

#define FREE_LIST(T,r) \
	do { \
		T *p, *node = r; \
		while (node != NULL) { \
			p = node; \
			node = node->next; \
			free(p); \
		} \
	} while (0)

#define LOOP_THROUGH(T,n,r,C) \
	do { \
		T *n; \
		if (r == NULL) { \
			r = calloc(1, sizeof(T)); \
			if (r == NULL) \
				err(1, "LOOP: calloc"); \
			r->next = NULL; \
		} \
		n = r; \
		while (n != NULL) { \
			do { \
				C; \
			} while (0); \
			n = n->next; \
		} \
	} while (0)

void
expand_label_str(char *label, size_t len, const char *srch, const char *repl)
{
	char *tmp;
	char *p, *q;

	if ((tmp = calloc(1, len)) == NULL)
		err(1, "expand_label_str: calloc");
	p = q = label;
	while ((q = strstr(p, srch)) != NULL) {
		*q = '\0';
		if ((strlcat(tmp, p, len) >= len) ||
		    (strlcat(tmp, repl, len) >= len))
			errx(1, "expand_label: label too long");
		q += strlen(srch);
		p = q;
	}
	if (strlcat(tmp, p, len) >= len)
		errx(1, "expand_label: label too long");
	strlcpy(label, tmp, len);	/* always fits */
	free(tmp);
}

void
expand_label_if(const char *name, char *label, size_t len, const char *ifname)
{
	if (strstr(label, name) != NULL) {
		if (!*ifname)
			expand_label_str(label, len, name, "any");
		else
			expand_label_str(label, len, name, ifname);
	}
}

void
expand_label_addr(const char *name, char *label, size_t len, sa_family_t af,
    struct node_host *h)
{
	char tmp[64], tmp_not[66];

	if (strstr(label, name) != NULL) {
		switch (h->addr.type) {
		case PF_ADDR_DYNIFTL:
			snprintf(tmp, sizeof(tmp), "(%s)", h->addr.v.ifname);
			break;
		case PF_ADDR_TABLE:
			snprintf(tmp, sizeof(tmp), "<%s>", h->addr.v.tblname);
			break;
		case PF_ADDR_NOROUTE:
			snprintf(tmp, sizeof(tmp), "no-route");
			break;
		case PF_ADDR_URPFFAILED:
			snprintf(tmp, sizeof(tmp), "urpf-failed");
			break;
		case PF_ADDR_ADDRMASK:
			if (!af || (PF_AZERO(&h->addr.v.a.addr, af) &&
			    PF_AZERO(&h->addr.v.a.mask, af)))
				snprintf(tmp, sizeof(tmp), "any");
			else {
				char	a[48];
				int	bits;

				if (inet_ntop(af, &h->addr.v.a.addr, a,
				    sizeof(a)) == NULL)
					snprintf(tmp, sizeof(tmp), "?");
				else {
					bits = unmask(&h->addr.v.a.mask, af);
					if ((af == AF_INET && bits < 32) ||
					    (af == AF_INET6 && bits < 128))
						snprintf(tmp, sizeof(tmp),
						    "%s/%d", a, bits);
					else
						snprintf(tmp, sizeof(tmp),
						    "%s", a);
				}
			}
			break;
		default:
			snprintf(tmp, sizeof(tmp), "?");
			break;
		}

		if (h->not) {
			snprintf(tmp_not, sizeof(tmp_not), "! %s", tmp);
			expand_label_str(label, len, name, tmp_not);
		} else
			expand_label_str(label, len, name, tmp);
	}
}

void
expand_label_port(const char *name, char *label, size_t len,
    struct node_port *port)
{
	char	 a1[6], a2[6], op[13] = "";

	if (strstr(label, name) != NULL) {
		snprintf(a1, sizeof(a1), "%u", ntohs(port->port[0]));
		snprintf(a2, sizeof(a2), "%u", ntohs(port->port[1]));
		if (!port->op)
			;
		else if (port->op == PF_OP_IRG)
			snprintf(op, sizeof(op), "%s><%s", a1, a2);
		else if (port->op == PF_OP_XRG)
			snprintf(op, sizeof(op), "%s<>%s", a1, a2);
		else if (port->op == PF_OP_EQ)
			snprintf(op, sizeof(op), "%s", a1);
		else if (port->op == PF_OP_NE)
			snprintf(op, sizeof(op), "!=%s", a1);
		else if (port->op == PF_OP_LT)
			snprintf(op, sizeof(op), "<%s", a1);
		else if (port->op == PF_OP_LE)
			snprintf(op, sizeof(op), "<=%s", a1);
		else if (port->op == PF_OP_GT)
			snprintf(op, sizeof(op), ">%s", a1);
		else if (port->op == PF_OP_GE)
			snprintf(op, sizeof(op), ">=%s", a1);
		expand_label_str(label, len, name, op);
	}
}

void
expand_label_proto(const char *name, char *label, size_t len, u_int8_t proto)
{
	struct protoent *pe;
	char n[4];

	if (strstr(label, name) != NULL) {
		pe = getprotobynumber(proto);
		if (pe != NULL)
			expand_label_str(label, len, name, pe->p_name);
		else {
			snprintf(n, sizeof(n), "%u", proto);
			expand_label_str(label, len, name, n);
		}
	}
}

void
expand_label_nr(const char *name, char *label, size_t len)
{
	char n[11];

	if (strstr(label, name) != NULL) {
		snprintf(n, sizeof(n), "%u", pf->anchor->match);
		expand_label_str(label, len, name, n);
	}
}

void
expand_label(char *label, size_t len, const char *ifname, sa_family_t af,
    struct node_host *src_host, struct node_port *src_port,
    struct node_host *dst_host, struct node_port *dst_port,
    u_int8_t proto)
{
	expand_label_if("$if", label, len, ifname);
	expand_label_addr("$srcaddr", label, len, af, src_host);
	expand_label_addr("$dstaddr", label, len, af, dst_host);
	expand_label_port("$srcport", label, len, src_port);
	expand_label_port("$dstport", label, len, dst_port);
	expand_label_proto("$proto", label, len, proto);
	expand_label_nr("$nr", label, len);
}

int
expand_altq(struct pf_altq *a, struct node_if *interfaces,
    struct node_queue *nqueues, struct node_queue_bw bwspec,
    struct node_queue_opt *opts)
{
	struct pf_altq		 pa, pb;
	char			 qname[PF_QNAME_SIZE];
	struct node_queue	*n;
	struct node_queue_bw	 bw;
	int			 errs = 0;

	if ((pf->loadopt & PFCTL_FLAG_ALTQ) == 0) {
		FREE_LIST(struct node_if, interfaces);
		if (nqueues)
			FREE_LIST(struct node_queue, nqueues);
		return (0);
	}

	LOOP_THROUGH(struct node_if, interface, interfaces,
		memcpy(&pa, a, sizeof(struct pf_altq));
		if (strlcpy(pa.ifname, interface->ifname,
		    sizeof(pa.ifname)) >= sizeof(pa.ifname))
			errx(1, "expand_altq: strlcpy");

		if (interface->not) {
			yyerror("altq on ! <interface> is not supported");
			errs++;
		} else {
			if (eval_pfaltq(pf, &pa, &bwspec, opts))
				errs++;
			else
				if (pfctl_add_altq(pf, &pa))
					errs++;

			if (pf->opts & PF_OPT_VERBOSE) {
				print_altq(&pf->paltq->altq, 0,
				    &bwspec, opts);
				if (nqueues && nqueues->tail) {
					printf("queue { ");
					LOOP_THROUGH(struct node_queue, queue,
					    nqueues,
						printf("%s ",
						    queue->queue);
					);
					printf("}");
				}
				printf("\n");
			}

			if (pa.scheduler == ALTQT_CBQ ||
			    pa.scheduler == ALTQT_HFSC) {
				/* now create a root queue */
				memset(&pb, 0, sizeof(struct pf_altq));
				if (strlcpy(qname, "root_", sizeof(qname)) >=
				    sizeof(qname))
					errx(1, "expand_altq: strlcpy");
				if (strlcat(qname, interface->ifname,
				    sizeof(qname)) >= sizeof(qname))
					errx(1, "expand_altq: strlcat");
				if (strlcpy(pb.qname, qname,
				    sizeof(pb.qname)) >= sizeof(pb.qname))
					errx(1, "expand_altq: strlcpy");
				if (strlcpy(pb.ifname, interface->ifname,
				    sizeof(pb.ifname)) >= sizeof(pb.ifname))
					errx(1, "expand_altq: strlcpy");
				pb.qlimit = pa.qlimit;
				pb.scheduler = pa.scheduler;
				bw.bw_absolute = pa.ifbandwidth;
				bw.bw_percent = 0;
				if (eval_pfqueue(pf, &pb, &bw, opts))
					errs++;
				else
					if (pfctl_add_altq(pf, &pb))
						errs++;
			}

			LOOP_THROUGH(struct node_queue, queue, nqueues,
				n = calloc(1, sizeof(struct node_queue));
				if (n == NULL)
					err(1, "expand_altq: calloc");
				if (pa.scheduler == ALTQT_CBQ ||
				    pa.scheduler == ALTQT_HFSC)
					if (strlcpy(n->parent, qname,
					    sizeof(n->parent)) >=
					    sizeof(n->parent))
						errx(1, "expand_altq: strlcpy");
				if (strlcpy(n->queue, queue->queue,
				    sizeof(n->queue)) >= sizeof(n->queue))
					errx(1, "expand_altq: strlcpy");
				if (strlcpy(n->ifname, interface->ifname,
				    sizeof(n->ifname)) >= sizeof(n->ifname))
					errx(1, "expand_altq: strlcpy");
				n->scheduler = pa.scheduler;
				n->next = NULL;
				n->tail = n;
				if (queues == NULL)
					queues = n;
				else {
					queues->tail->next = n;
					queues->tail = n;
				}
			);
		}
	);
	FREE_LIST(struct node_if, interfaces);
	if (nqueues)
		FREE_LIST(struct node_queue, nqueues);

	return (errs);
}

int
expand_queue(struct pf_altq *a, struct node_if *interfaces,
    struct node_queue *nqueues, struct node_queue_bw bwspec,
    struct node_queue_opt *opts)
{
	struct node_queue	*n, *nq;
	struct pf_altq		 pa;
	u_int8_t		 found = 0;
	u_int8_t		 errs = 0;

	if ((pf->loadopt & PFCTL_FLAG_ALTQ) == 0) {
		FREE_LIST(struct node_queue, nqueues);
		return (0);
	}

	if (queues == NULL) {
		yyerror("queue %s has no parent", a->qname);
		FREE_LIST(struct node_queue, nqueues);
		return (1);
	}

	LOOP_THROUGH(struct node_if, interface, interfaces,
		LOOP_THROUGH(struct node_queue, tqueue, queues,
			if (!strncmp(a->qname, tqueue->queue, PF_QNAME_SIZE) &&
			    (interface->ifname[0] == 0 ||
			    (!interface->not && !strncmp(interface->ifname,
			    tqueue->ifname, IFNAMSIZ)) ||
			    (interface->not && strncmp(interface->ifname,
			    tqueue->ifname, IFNAMSIZ)))) {
				/* found ourself in queues */
				found++;

				memcpy(&pa, a, sizeof(struct pf_altq));

				if (pa.scheduler != ALTQT_NONE &&
				    pa.scheduler != tqueue->scheduler) {
					yyerror("exactly one scheduler type "
					    "per interface allowed");
					return (1);
				}
				pa.scheduler = tqueue->scheduler;

				/* scheduler dependent error checking */
				switch (pa.scheduler) {
				case ALTQT_PRIQ:
					if (nqueues != NULL) {
						yyerror("priq queues cannot "
						    "have child queues");
						return (1);
					}
					if (bwspec.bw_absolute > 0 ||
					    bwspec.bw_percent < 100) {
						yyerror("priq doesn't take "
						    "bandwidth");
						return (1);
					}
					break;
				default:
					break;
				}

				if (strlcpy(pa.ifname, tqueue->ifname,
				    sizeof(pa.ifname)) >= sizeof(pa.ifname))
					errx(1, "expand_queue: strlcpy");
				if (strlcpy(pa.parent, tqueue->parent,
				    sizeof(pa.parent)) >= sizeof(pa.parent))
					errx(1, "expand_queue: strlcpy");

				if (eval_pfqueue(pf, &pa, &bwspec, opts))
					errs++;
				else
					if (pfctl_add_altq(pf, &pa))
						errs++;

				for (nq = nqueues; nq != NULL; nq = nq->next) {
					if (!strcmp(a->qname, nq->queue)) {
						yyerror("queue cannot have "
						    "itself as child");
						errs++;
						continue;
					}
					n = calloc(1,
					    sizeof(struct node_queue));
					if (n == NULL)
						err(1, "expand_queue: calloc");
					if (strlcpy(n->parent, a->qname,
					    sizeof(n->parent)) >=
					    sizeof(n->parent))
						errx(1, "expand_queue strlcpy");
					if (strlcpy(n->queue, nq->queue,
					    sizeof(n->queue)) >=
					    sizeof(n->queue))
						errx(1, "expand_queue strlcpy");
					if (strlcpy(n->ifname, tqueue->ifname,
					    sizeof(n->ifname)) >=
					    sizeof(n->ifname))
						errx(1, "expand_queue strlcpy");
					n->scheduler = tqueue->scheduler;
					n->next = NULL;
					n->tail = n;
					if (queues == NULL)
						queues = n;
					else {
						queues->tail->next = n;
						queues->tail = n;
					}
				}
				if ((pf->opts & PF_OPT_VERBOSE) && (
				    (found == 1 && interface->ifname[0] == 0) ||
				    (found > 0 && interface->ifname[0] != 0))) {
					print_queue(&pf->paltq->altq, 0,
					    &bwspec, interface->ifname[0] != 0,
					    opts);
					if (nqueues && nqueues->tail) {
						printf("{ ");
						LOOP_THROUGH(struct node_queue,
						    queue, nqueues,
							printf("%s ",
							    queue->queue);
						);
						printf("}");
					}
					printf("\n");
				}
			}
		);
	);

	FREE_LIST(struct node_queue, nqueues);
	FREE_LIST(struct node_if, interfaces);

	if (!found) {
		yyerror("queue %s has no parent", a->qname);
		errs++;
	}

	if (errs)
		return (1);
	else
		return (0);
}

void
expand_rule(struct pf_rule *r,
    struct node_if *interfaces, struct node_host *rpool_hosts,
    struct node_proto *protos, struct node_os *src_oses,
    struct node_host *src_hosts, struct node_port *src_ports,
    struct node_host *dst_hosts, struct node_port *dst_ports,
    struct node_uid *uids, struct node_gid *gids, struct node_icmp *icmp_types,
    const char *anchor_call)
{
	sa_family_t		 af = r->af;
	int			 added = 0, error = 0;
	char			 ifname[IF_NAMESIZE];
	char			 label[PF_RULE_LABEL_SIZE];
	char			 schedule[PF_RULE_LABEL_SIZE];
	char			 tagname[PF_TAG_NAME_SIZE];
	char			 match_tagname[PF_TAG_NAME_SIZE];
	struct pf_pooladdr	*pa;
	struct node_host	*h;
	u_int8_t		 flags, flagset, keep_state;

	if (strlcpy(label, r->label, sizeof(label)) >= sizeof(label))
		errx(1, "expand_rule: strlcpy");
	if (strlcpy(schedule, r->schedule, sizeof(schedule)) > sizeof(schedule))
		errx(1, "expand_rule: strlcpy");
	if (strlcpy(tagname, r->tagname, sizeof(tagname)) >= sizeof(tagname))
		errx(1, "expand_rule: strlcpy");
	if (strlcpy(match_tagname, r->match_tagname, sizeof(match_tagname)) >=
	    sizeof(match_tagname))
		errx(1, "expand_rule: strlcpy");
	flags = r->flags;
	flagset = r->flagset;
	keep_state = r->keep_state;

	LOOP_THROUGH(struct node_if, interface, interfaces,
	LOOP_THROUGH(struct node_proto, proto, protos,
	LOOP_THROUGH(struct node_icmp, icmp_type, icmp_types,
	LOOP_THROUGH(struct node_host, src_host, src_hosts,
	LOOP_THROUGH(struct node_port, src_port, src_ports,
	LOOP_THROUGH(struct node_os, src_os, src_oses,
	LOOP_THROUGH(struct node_host, dst_host, dst_hosts,
	LOOP_THROUGH(struct node_port, dst_port, dst_ports,
	LOOP_THROUGH(struct node_uid, uid, uids,
	LOOP_THROUGH(struct node_gid, gid, gids,

		r->af = af;
		/* for link-local IPv6 address, interface must match up */
		if ((r->af && src_host->af && r->af != src_host->af) ||
		    (r->af && dst_host->af && r->af != dst_host->af) ||
		    (src_host->af && dst_host->af &&
		    src_host->af != dst_host->af) ||
		    (src_host->ifindex && dst_host->ifindex &&
		    src_host->ifindex != dst_host->ifindex) ||
		    (src_host->ifindex && *interface->ifname &&
		    src_host->ifindex != if_nametoindex(interface->ifname)) ||
		    (dst_host->ifindex && *interface->ifname &&
		    dst_host->ifindex != if_nametoindex(interface->ifname)))
			continue;
		if (!r->af && src_host->af)
			r->af = src_host->af;
		else if (!r->af && dst_host->af)
			r->af = dst_host->af;

		if (*interface->ifname)
			strlcpy(r->ifname, interface->ifname,
			    sizeof(r->ifname));
		else if (if_indextoname(src_host->ifindex, ifname))
			strlcpy(r->ifname, ifname, sizeof(r->ifname));
		else if (if_indextoname(dst_host->ifindex, ifname))
			strlcpy(r->ifname, ifname, sizeof(r->ifname));
		else
			memset(r->ifname, '\0', sizeof(r->ifname));

		if (strlcpy(r->label, label, sizeof(r->label)) >=
		    sizeof(r->label))
			errx(1, "expand_rule: strlcpy");
		if (strlcpy(r->schedule, schedule, sizeof(r->schedule)) >=
			sizeof(r->schedule))
			errx(1, "expand_rule: strlcpy");
		if (strlcpy(r->tagname, tagname, sizeof(r->tagname)) >=
		    sizeof(r->tagname))
			errx(1, "expand_rule: strlcpy");
		if (strlcpy(r->match_tagname, match_tagname,
		    sizeof(r->match_tagname)) >= sizeof(r->match_tagname))
			errx(1, "expand_rule: strlcpy");
		expand_label(r->label, PF_RULE_LABEL_SIZE, r->ifname, r->af,
		    src_host, src_port, dst_host, dst_port, proto->proto);
		expand_label(r->schedule, PF_RULE_LABEL_SIZE, r->ifname, r->af,
			src_host, src_port, dst_host, dst_port, proto->proto);
		expand_label(r->tagname, PF_TAG_NAME_SIZE, r->ifname, r->af,
		    src_host, src_port, dst_host, dst_port, proto->proto);
		expand_label(r->match_tagname, PF_TAG_NAME_SIZE, r->ifname,
		    r->af, src_host, src_port, dst_host, dst_port,
		    proto->proto);

		error += check_netmask(src_host, r->af);
		error += check_netmask(dst_host, r->af);

		r->ifnot = interface->not;
		r->proto = proto->proto;
		r->src.addr = src_host->addr;
		r->src.neg = src_host->not;
		r->src.port[0] = src_port->port[0];
		r->src.port[1] = src_port->port[1];
		r->src.port_op = src_port->op;
		r->dst.addr = dst_host->addr;
		r->dst.neg = dst_host->not;
		r->dst.port[0] = dst_port->port[0];
		r->dst.port[1] = dst_port->port[1];
		r->dst.port_op = dst_port->op;
		r->uid.op = uid->op;
		r->uid.uid[0] = uid->uid[0];
		r->uid.uid[1] = uid->uid[1];
		r->gid.op = gid->op;
		r->gid.gid[0] = gid->gid[0];
		r->gid.gid[1] = gid->gid[1];
		r->type = icmp_type->type;
		r->code = icmp_type->code;

		if ((keep_state == PF_STATE_MODULATE ||
		    keep_state == PF_STATE_SYNPROXY) &&
		    r->proto && r->proto != IPPROTO_TCP)
			r->keep_state = PF_STATE_NORMAL;
		else
			r->keep_state = keep_state;

		if (r->proto && r->proto != IPPROTO_TCP) {
			r->flags = 0;
			r->flagset = 0;
		} else {
			r->flags = flags;
			r->flagset = flagset;
		}
		if (icmp_type->proto && r->proto != icmp_type->proto) {
			yyerror("icmp-type mismatch");
			error++;
		}

		if (src_os && src_os->os) {
			r->os_fingerprint = pfctl_get_fingerprint(src_os->os);
			if ((pf->opts & PF_OPT_VERBOSE2) &&
			    r->os_fingerprint == PF_OSFP_NOMATCH)
				fprintf(stderr,
				    "warning: unknown '%s' OS fingerprint\n",
				    src_os->os);
		} else {
			r->os_fingerprint = PF_OSFP_ANY;
		}

		TAILQ_INIT(&r->rpool.list);
		for (h = rpool_hosts; h != NULL; h = h->next) {
			pa = calloc(1, sizeof(struct pf_pooladdr));
			if (pa == NULL)
				err(1, "expand_rule: calloc");
			pa->addr = h->addr;
			if (h->ifname != NULL) {
				if (strlcpy(pa->ifname, h->ifname,
				    sizeof(pa->ifname)) >=
				    sizeof(pa->ifname))
					errx(1, "expand_rule: strlcpy");
			} else
				pa->ifname[0] = 0;
			TAILQ_INSERT_TAIL(&r->rpool.list, pa, entries);
		}

		if (rule_consistent(r, anchor_call[0]) < 0 || error)
			yyerror("skipping rule due to errors");
		else {
			r->nr = pf->astack[pf->asd]->match++;
			pfctl_add_rule(pf, r, anchor_call);
			added++;
		}

	))))))))));

	FREE_LIST(struct node_if, interfaces);
	FREE_LIST(struct node_proto, protos);
	FREE_LIST(struct node_host, src_hosts);
	FREE_LIST(struct node_port, src_ports);
	FREE_LIST(struct node_os, src_oses);
	FREE_LIST(struct node_host, dst_hosts);
	FREE_LIST(struct node_port, dst_ports);
	FREE_LIST(struct node_uid, uids);
	FREE_LIST(struct node_gid, gids);
	FREE_LIST(struct node_icmp, icmp_types);
	FREE_LIST(struct node_host, rpool_hosts);

	if (!added)
		yyerror("rule expands to no valid combination");
}

int
expand_skip_interface(struct node_if *interfaces)
{
	int	errs = 0;

	if (!interfaces || (!interfaces->next && !interfaces->not &&
	    !strcmp(interfaces->ifname, "none"))) {
		if (pf->opts & PF_OPT_VERBOSE)
			printf("set skip on none\n");
		errs = pfctl_set_interface_flags(pf, "", PFI_IFLAG_SKIP, 0);
		return (errs);
	}

	if (pf->opts & PF_OPT_VERBOSE)
		printf("set skip on {");
	LOOP_THROUGH(struct node_if, interface, interfaces,
		if (pf->opts & PF_OPT_VERBOSE)
			printf(" %s", interface->ifname);
		if (interface->not) {
			yyerror("skip on ! <interface> is not supported");
			errs++;
		} else
			errs += pfctl_set_interface_flags(pf,
			    interface->ifname, PFI_IFLAG_SKIP, 1);
	);
	if (pf->opts & PF_OPT_VERBOSE)
		printf(" }\n");

	FREE_LIST(struct node_if, interfaces);

	if (errs)
		return (1);
	else
		return (0);
}

#undef FREE_LIST
#undef LOOP_THROUGH

int
check_rulestate(int desired_state)
{
	if (require_order && (rulestate > desired_state)) {
		yyerror("Rules must be in order: options, normalization, "
		    "queueing, translation, filtering");
		return (1);
	}
	rulestate = desired_state;
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
		{ "all",		ALL},
		{ "allow-opts",		ALLOWOPTS},
		{ "altq",		ALTQ},
		{ "anchor",		ANCHOR},
		{ "antispoof",		ANTISPOOF},
		{ "any",		ANY},
		{ "bandwidth",		BANDWIDTH},
		{ "binat",		BINAT},
		{ "binat-anchor",	BINATANCHOR},
		{ "bitmask",		BITMASK},
		{ "block",		BLOCK},
		{ "block-policy",	BLOCKPOLICY},
		{ "buckets",		BUCKETS},
		{ "cbq",		CBQ},
		{ "code",		CODE},
		{ "codelq",		CODEL},
		{ "crop",		FRAGCROP},
		{ "debug",		DEBUG},
		{ "divert-reply",	DIVERTREPLY},
		{ "divert-to",		DIVERTTO},
		{ "dnpipe",		DNPIPE},
		{ "dnqueue",		DNQUEUE},
		{ "drop",		DROP},
		{ "drop-ovl",		FRAGDROP},
		{ "dscp",		DSCP},
		{ "dup-to",		DUPTO},
		{ "fairq",		FAIRQ},
		{ "fastroute",		FASTROUTE},
		{ "file",		FILENAME},
		{ "fingerprints",	FINGERPRINTS},
		{ "flags",		FLAGS},
		{ "floating",		FLOATING},
		{ "flush",		FLUSH},
		{ "for",		FOR},
		{ "fragment",		FRAGMENT},
		{ "from",		FROM},
		{ "global",		GLOBAL},
		{ "group",		GROUP},
		{ "hfsc",		HFSC},
		{ "hogs",		HOGS},
		{ "hostid",		HOSTID},
		{ "icmp-type",		ICMPTYPE},
		{ "icmp6-type",		ICMP6TYPE},
		{ "if-bound",		IFBOUND},
		{ "in",			IN},
		{ "include",		INCLUDE},
		{ "inet",		INET},
		{ "inet6",		INET6},
		{ "interval",		INTERVAL},
		{ "keep",		KEEP},
		{ "label",		LABEL},
		{ "limit",		LIMIT},
		{ "linkshare",		LINKSHARE},
		{ "load",		LOAD},
		{ "log",		LOG},
		{ "loginterface",	LOGINTERFACE},
		{ "match",		MATCH},
		{ "max",		MAXIMUM},
		{ "max-mss",		MAXMSS},
		{ "max-src-conn",	MAXSRCCONN},
		{ "max-src-conn-rate",	MAXSRCCONNRATE},
		{ "max-src-nodes",	MAXSRCNODES},
		{ "max-src-states",	MAXSRCSTATES},
		{ "min-ttl",		MINTTL},
		{ "modulate",		MODULATE},
		{ "nat",		NAT},
		{ "nat-anchor",		NATANCHOR},
		{ "no",			NO},
		{ "no-df",		NODF},
		{ "no-route",		NOROUTE},
		{ "no-sync",		NOSYNC},
		{ "on",			ON},
		{ "optimization",	OPTIMIZATION},
		{ "os",			OS},
		{ "out",		OUT},
		{ "overload",		OVERLOAD},
		{ "pass",		PASS},
		{ "port",		PORT},
		{ "prio",		PRIO},
		{ "priority",		PRIORITY},
		{ "priq",		PRIQ},
		{ "probability",	PROBABILITY},
		{ "proto",		PROTO},
		{ "qlimit",		QLIMIT},
		{ "queue",		QUEUE},
		{ "quick",		QUICK},
		{ "random",		RANDOM},
		{ "random-id",		RANDOMID},
		{ "rdr",		RDR},
		{ "rdr-anchor",		RDRANCHOR},
		{ "realtime",		REALTIME},
		{ "reassemble",		REASSEMBLE},
		{ "reply-to",		REPLYTO},
		{ "require-order",	REQUIREORDER},
		{ "return",		RETURN},
		{ "return-icmp",	RETURNICMP},
		{ "return-icmp6",	RETURNICMP6},
		{ "return-rst",		RETURNRST},
		{ "round-robin",	ROUNDROBIN},
		{ "route",		ROUTE},
		{ "route-to",		ROUTETO},
		{ "rtable",		RTABLE},
		{ "rule",		RULE},
		{ "ruleset-optimization",	RULESET_OPTIMIZATION},
		{ "schedule",		SCHEDULE},
		{ "scrub",		SCRUB},
		{ "set",		SET},
		{ "set-tos",		SETTOS},
		{ "skip",		SKIP},
		{ "sloppy",		SLOPPY},
		{ "source-hash",	SOURCEHASH},
		{ "source-track",	SOURCETRACK},
		{ "state",		STATE},
		{ "state-defaults",	STATEDEFAULTS},
		{ "state-policy",	STATEPOLICY},
		{ "static-port",	STATICPORT},
		{ "sticky-address",	STICKYADDRESS},
		{ "synproxy",		SYNPROXY},
		{ "table",		TABLE},
		{ "tag",		TAG},
		{ "tagged",		TAGGED},
		{ "target",		TARGET},
		{ "tbrsize",		TBRSIZE},
		{ "timeout",		TIMEOUT},
		{ "to",			TO},
		{ "tos",		TOS},
		{ "tracker",		TRACKER},
		{ "ttl",		TTL},
		{ "upperlimit",		UPPERLIMIT},
		{ "urpf-failed",	URPFFAILED},
		{ "user",		USER},
	};
	const struct keywords	*p;

	p = bsearch(s, keywords, sizeof(keywords)/sizeof(keywords[0]),
	    sizeof(keywords[0]), kw_cmp);

	if (p) {
		if (debug > 1)
			fprintf(stderr, "%s: %d\n", s, p->k_val);
		return (p->k_val);
	} else {
		if (debug > 1)
			fprintf(stderr, "string: %s\n", s);
		return (STRING);
	}
}

#define MAXPUSHBACK	128

char	*parsebuf;
int	 parseindex;
char	 pushback_buffer[MAXPUSHBACK];
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
			yyerror("reached end of file while parsing quoted string");
			if (popfile() == EOF)
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
		if (popfile() == EOF)
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
	char	 buf[8096];
	char	*p, *val;
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
				*p++ = (char)c;
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
				else if (next == '\n')
					continue;
				else
					lungetc(next);
			} else if (c == quotec) {
				*p = '\0';
				break;
			}
			if (p + 1 >= buf + sizeof(buf) - 1) {
				yyerror("string too long");
				return (findeol());
			}
			*p++ = (char)c;
		}
		yylval.v.string = strdup(buf);
		if (yylval.v.string == NULL)
			err(1, "yylex: strdup");
		return (STRING);
	case '<':
		next = lgetc(0);
		if (next == '>') {
			yylval.v.i = PF_OP_XRG;
			return (PORTBINARY);
		}
		lungetc(next);
		break;
	case '>':
		next = lgetc(0);
		if (next == '<') {
			yylval.v.i = PF_OP_IRG;
			return (PORTBINARY);
		}
		lungetc(next);
		break;
	case '-':
		next = lgetc(0);
		if (next == '>')
			return (ARROW);
		lungetc(next);
		break;
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
	x != '!' && x != '=' && x != '/' && x != '#' && \
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
		warn("cannot stat %s", fname);
		return (-1);
	}
	if (st.st_uid != 0 && st.st_uid != getuid()) {
		warnx("%s: owner not root or current user", fname);
		return (-1);
	}
	if (st.st_mode & (S_IRWXG | S_IRWXO)) {
		warnx("%s: group/world readable/writeable", fname);
		return (-1);
	}
	return (0);
}

struct file *
pushfile(const char *name, int secret)
{
	struct file	*nfile;

	if ((nfile = calloc(1, sizeof(struct file))) == NULL ||
	    (nfile->name = strdup(name)) == NULL) {
		warn("malloc");
		return (NULL);
	}
	if (TAILQ_FIRST(&files) == NULL && strcmp(nfile->name, "-") == 0) {
		nfile->stream = stdin;
		free(nfile->name);
		if ((nfile->name = strdup("stdin")) == NULL) {
			warn("strdup");
			free(nfile);
			return (NULL);
		}
	} else if ((nfile->stream = fopen(nfile->name, "r")) == NULL) {
		warn("%s", nfile->name);
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

	if ((prev = TAILQ_PREV(file, files, entry)) != NULL) {
		prev->errors += file->errors;
		TAILQ_REMOVE(&files, file, entry);
		fclose(file->stream);
		free(file->name);
		free(file);
		file = prev;
		return (0);
	}
	return (EOF);
}

int
parse_config(char *filename, struct pfctl *xpf)
{
	int		 errors = 0;
	struct sym	*sym;

	pf = xpf;
	errors = 0;
	rulestate = PFCTL_STATE_NONE;
	returnicmpdefault = (ICMP_UNREACH << 8) | ICMP_UNREACH_PORT;
	returnicmp6default =
	    (ICMP6_DST_UNREACH << 8) | ICMP6_DST_UNREACH_NOPORT;
	blockpolicy = PFRULE_DROP;
	require_order = 1;

	if ((file = pushfile(filename, 0)) == NULL) {
		warn("cannot open the main config file!");
		return (-1);
	}

	yyparse();
	errors = file->errors;
	popfile();

	/* Free macros and check which have not been used. */
	while ((sym = TAILQ_FIRST(&symhead))) {
		if ((pf->opts & PF_OPT_VERBOSE2) && !sym->used)
			fprintf(stderr, "warning: macro '%s' not "
			    "used\n", sym->nam);
		free(sym->nam);
		free(sym->val);
		TAILQ_REMOVE(&symhead, sym, entry);
		free(sym);
	}

	return (errors ? -1 : 0);
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
pfctl_cmdline_symset(char *s)
{
	char	*sym, *val;
	int	 ret;

	if ((val = strrchr(s, '=')) == NULL)
		return (-1);

	if ((sym = malloc(strlen(s) - strlen(val) + 1)) == NULL)
		err(1, "pfctl_cmdline_symset: malloc");

	strlcpy(sym, s, strlen(s) - strlen(val) + 1);

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

void
mv_rules(struct pf_ruleset *src, struct pf_ruleset *dst)
{
	int i;
	struct pf_rule *r;

	for (i = 0; i < PF_RULESET_MAX; ++i) {
		while ((r = TAILQ_FIRST(src->rules[i].active.ptr))
		    != NULL) {
			TAILQ_REMOVE(src->rules[i].active.ptr, r, entries);
			TAILQ_INSERT_TAIL(dst->rules[i].active.ptr, r, entries);
			dst->anchor->match++;
		}
		src->anchor->match = 0;
		while ((r = TAILQ_FIRST(src->rules[i].inactive.ptr))
		    != NULL) {
			TAILQ_REMOVE(src->rules[i].inactive.ptr, r, entries);
			TAILQ_INSERT_TAIL(dst->rules[i].inactive.ptr,
				r, entries);
		}
	}
}

void
decide_address_family(struct node_host *n, sa_family_t *af)
{
	if (*af != 0 || n == NULL)
		return;
	*af = n->af;
	while ((n = n->next) != NULL) {
		if (n->af != *af) {
			*af = 0;
			return;
		}
	}
}

void
remove_invalid_hosts(struct node_host **nh, sa_family_t *af)
{
	struct node_host	*n = *nh, *prev = NULL;

	while (n != NULL) {
		if (*af && n->af && n->af != *af) {
			/* unlink and free n */
			struct node_host *next = n->next;

			/* adjust tail pointer */
			if (n == (*nh)->tail)
				(*nh)->tail = prev;
			/* adjust previous node's next pointer */
			if (prev == NULL)
				*nh = next;
			else
				prev->next = next;
			/* free node */
			if (n->ifname != NULL)
				free(n->ifname);
			free(n);
			n = next;
		} else {
			if (n->af && !*af)
				*af = n->af;
			prev = n;
			n = n->next;
		}
	}
}

int
invalid_redirect(struct node_host *nh, sa_family_t af)
{
	if (!af) {
		struct node_host *n;

		/* tables and dyniftl are ok without an address family */
		for (n = nh; n != NULL; n = n->next) {
			if (n->addr.type != PF_ADDR_TABLE &&
			    n->addr.type != PF_ADDR_DYNIFTL) {
				yyerror("address family not given and "
				    "translation address expands to multiple "
				    "address families");
				return (1);
			}
		}
	}
	if (nh == NULL) {
		yyerror("no translation address with matching address family "
		    "found.");
		return (1);
	}
	return (0);
}

int
atoul(char *s, u_long *ulvalp)
{
	u_long	 ulval;
	char	*ep;

	errno = 0;
	ulval = strtoul(s, &ep, 0);
	if (s[0] == '\0' || *ep != '\0')
		return (-1);
	if (errno == ERANGE && ulval == ULONG_MAX)
		return (-1);
	*ulvalp = ulval;
	return (0);
}

int
getservice(char *n)
{
	struct servent	*s;
	u_long		 ulval;

	if (atoul(n, &ulval) == 0) {
		if (ulval > 65535) {
			yyerror("illegal port value %lu", ulval);
			return (-1);
		}
		return (htons(ulval));
	} else {
		s = getservbyname(n, "tcp");
		if (s == NULL)
			s = getservbyname(n, "udp");
		if (s == NULL) {
			yyerror("unknown port %s", n);
			return (-1);
		}
		return (s->s_port);
	}
}

int
rule_label(struct pf_rule *r, char *s)
{
	if (s) {
		if (strlcpy(r->label, s, sizeof(r->label)) >=
		    sizeof(r->label)) {
			yyerror("rule label too long (max %d chars)",
			    sizeof(r->label)-1);
			return (-1);
		}
	}
	return (0);
}

int
rule_schedule(struct pf_rule *r, char *s)
{
	if (s) {
		if (strlcpy(r->schedule, s, sizeof(r->label)) >=
		   sizeof(r->label)) {
			yyerror("rule schedule label too long (max %d chars)",
				sizeof(r->label)-1);
			return (-1);
		}
	}
	return (0);
}

u_int16_t
parseicmpspec(char *w, sa_family_t af)
{
	const struct icmpcodeent	*p;
	u_long				 ulval;
	u_int8_t			 icmptype;

	if (af == AF_INET)
		icmptype = returnicmpdefault >> 8;
	else
		icmptype = returnicmp6default >> 8;

	if (atoul(w, &ulval) == -1) {
		if ((p = geticmpcodebyname(icmptype, w, af)) == NULL) {
			yyerror("unknown icmp code %s", w);
			return (0);
		}
		ulval = p->code;
	}
	if (ulval > 255) {
		yyerror("invalid icmp code %lu", ulval);
		return (0);
	}
	return (icmptype << 8 | ulval);
}

int
parseport(char *port, struct range *r, int extensions)
{
	char	*p = strchr(port, ':');

	if (p == NULL) {
		if ((r->a = getservice(port)) == -1)
			return (-1);
		r->b = 0;
		r->t = PF_OP_NONE;
		return (0);
	}
	if ((extensions & PPORT_STAR) && !strcmp(p+1, "*")) {
		*p = 0;
		if ((r->a = getservice(port)) == -1)
			return (-1);
		r->b = 0;
		r->t = PF_OP_IRG;
		return (0);
	}
	if ((extensions & PPORT_RANGE)) {
		*p++ = 0;
		if ((r->a = getservice(port)) == -1 ||
		    (r->b = getservice(p)) == -1)
			return (-1);
		if (r->a == r->b) {
			r->b = 0;
			r->t = PF_OP_NONE;
		} else
			r->t = PF_OP_RRG;
		return (0);
	}
	return (-1);
}

int
pfctl_load_anchors(int dev, struct pfctl *pf, struct pfr_buffer *trans)
{
	struct loadanchors	*la;

	TAILQ_FOREACH(la, &loadanchorshead, entries) {
		if (pf->opts & PF_OPT_VERBOSE)
			fprintf(stderr, "\nLoading anchor %s from %s\n",
			    la->anchorname, la->filename);
		if (pfctl_rules(dev, la->filename, pf->opts, pf->optimize,
		    la->anchorname, trans) == -1)
			return (-1);
	}

	return (0);
}

int
kw_casecmp(const void *k, const void *e)
{
	return (strcasecmp(k, ((const struct keywords *)e)->k_name));
}

int
map_tos(char *s, int *val)
{
	/* DiffServ Codepoints and other TOS mappings */
	const struct keywords	 toswords[] = {
		{ "af11",		IPTOS_DSCP_AF11 },
		{ "af12",		IPTOS_DSCP_AF12 },
		{ "af13",		IPTOS_DSCP_AF13 },
		{ "af21",		IPTOS_DSCP_AF21 },
		{ "af22",		IPTOS_DSCP_AF22 },
		{ "af23",		IPTOS_DSCP_AF23 },
		{ "af31",		IPTOS_DSCP_AF31 },
		{ "af32",		IPTOS_DSCP_AF32 },
		{ "af33",		IPTOS_DSCP_AF33 },
		{ "af41",		IPTOS_DSCP_AF41 },
		{ "af42",		IPTOS_DSCP_AF42 },
		{ "af43",		IPTOS_DSCP_AF43 },
		{ "critical",		IPTOS_PREC_CRITIC_ECP },
		{ "cs0",		IPTOS_DSCP_CS0 },
		{ "cs1",		IPTOS_DSCP_CS1 },
		{ "cs2",		IPTOS_DSCP_CS2 },
		{ "cs3",		IPTOS_DSCP_CS3 },
		{ "cs4",		IPTOS_DSCP_CS4 },
		{ "cs5",		IPTOS_DSCP_CS5 },
		{ "cs6",		IPTOS_DSCP_CS6 },
		{ "cs7",		IPTOS_DSCP_CS7 },
		{ "ef",			IPTOS_DSCP_EF },
		{ "inetcontrol",	IPTOS_PREC_INTERNETCONTROL },
		{ "lowdelay",		IPTOS_LOWDELAY },
		{ "netcontrol",		IPTOS_PREC_NETCONTROL },
		{ "reliability",	IPTOS_RELIABILITY },
		{ "throughput",		IPTOS_THROUGHPUT }
	};
	const struct keywords	*p;

	p = bsearch(s, toswords, sizeof(toswords)/sizeof(toswords[0]),
	    sizeof(toswords[0]), kw_casecmp);

	if (p) {
		*val = p->k_val;
		return (1);
	}
	return (0);
}

int
rt_tableid_max(void)
{
#ifdef __FreeBSD__
	int fibs;
	size_t l = sizeof(fibs);

        if (sysctlbyname("net.fibs", &fibs, &l, NULL, 0) == -1)
		fibs = 16;	/* XXX RT_MAXFIBS, at least limit it some. */
	/*
	 * As the OpenBSD code only compares > and not >= we need to adjust
	 * here given we only accept values of 0..n and want to avoid #ifdefs
	 * in the grammar.
	 */
	return (fibs - 1);
#else
	return (RT_TABLEID_MAX);
#endif
}
#line 4452 "parse.c"

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
case 17:
#line 551 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ file->errors++; }
break;
case 18:
#line 554 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
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
case 25:
#line 581 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "none"))
				yyval.v.i = 0;
			else if (!strcmp(yystack.l_mark[0].v.string, "basic"))
				yyval.v.i = PF_OPTIMIZE_BASIC;
			else if (!strcmp(yystack.l_mark[0].v.string, "profile"))
				yyval.v.i = PF_OPTIMIZE_BASIC | PF_OPTIMIZE_PROFILE;
			else {
				yyerror("unknown ruleset-optimization %s", yystack.l_mark[0].v.string);
				YYERROR;
			}
		}
break;
case 26:
#line 595 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (check_rulestate(PFCTL_STATE_OPTION)) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			if (pfctl_set_optimization(pf, yystack.l_mark[0].v.string) != 0) {
				yyerror("unknown optimization %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 27:
#line 607 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (!(pf->opts & PF_OPT_OPTIMIZE)) {
				pf->opts |= PF_OPT_OPTIMIZE;
				pf->optimize = yystack.l_mark[0].v.i;
			}
		}
break;
case 32:
#line 617 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (check_rulestate(PFCTL_STATE_OPTION)) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			if (pfctl_set_logif(pf, yystack.l_mark[0].v.string) != 0) {
				yyerror("error setting loginterface %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 33:
#line 629 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number == 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("hostid must be non-zero");
				YYERROR;
			}
			if (pfctl_set_hostid(pf, yystack.l_mark[0].v.number) != 0) {
				yyerror("error setting hostid %08x", yystack.l_mark[0].v.number);
				YYERROR;
			}
		}
break;
case 34:
#line 639 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (pf->opts & PF_OPT_VERBOSE)
				printf("set block-policy drop\n");
			if (check_rulestate(PFCTL_STATE_OPTION))
				YYERROR;
			blockpolicy = PFRULE_DROP;
		}
break;
case 35:
#line 646 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (pf->opts & PF_OPT_VERBOSE)
				printf("set block-policy return\n");
			if (check_rulestate(PFCTL_STATE_OPTION))
				YYERROR;
			blockpolicy = PFRULE_RETURN;
		}
break;
case 36:
#line 653 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (pf->opts & PF_OPT_VERBOSE)
				printf("set require-order %s\n",
				    yystack.l_mark[0].v.number == 1 ? "yes" : "no");
			require_order = yystack.l_mark[0].v.number;
		}
break;
case 37:
#line 659 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (pf->opts & PF_OPT_VERBOSE)
				printf("set fingerprints \"%s\"\n", yystack.l_mark[0].v.string);
			if (check_rulestate(PFCTL_STATE_OPTION)) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			if (!pf->anchor->name[0]) {
				if (pfctl_file_fingerprints(pf->dev,
				    pf->opts, yystack.l_mark[0].v.string)) {
					yyerror("error loading "
					    "fingerprints %s", yystack.l_mark[0].v.string);
					free(yystack.l_mark[0].v.string);
					YYERROR;
				}
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 38:
#line 677 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (pf->opts & PF_OPT_VERBOSE)
				switch (yystack.l_mark[0].v.i) {
				case 0:
					printf("set state-policy floating\n");
					break;
				case PFRULE_IFBOUND:
					printf("set state-policy if-bound\n");
					break;
				}
			default_statelock = yystack.l_mark[0].v.i;
		}
break;
case 39:
#line 689 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (check_rulestate(PFCTL_STATE_OPTION)) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			if (pfctl_set_debug(pf, yystack.l_mark[0].v.string) != 0) {
				yyerror("error setting debuglevel %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 40:
#line 701 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (expand_skip_interface(yystack.l_mark[0].v.interface) != 0) {
				yyerror("error setting skip interface(s)");
				YYERROR;
			}
		}
break;
case 41:
#line 707 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (keep_state_defaults != NULL) {
				yyerror("cannot redefine state-defaults");
				YYERROR;
			}
			keep_state_defaults = yystack.l_mark[0].v.state_opt;
		}
break;
case 42:
#line 716 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.string = yystack.l_mark[0].v.string; }
break;
case 43:
#line 717 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if ((yyval.v.string = strdup("all")) == NULL) {
				err(1, "stringall: strdup");
			}
		}
break;
case 44:
#line 724 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (asprintf(&yyval.v.string, "%s %s", yystack.l_mark[-1].v.string, yystack.l_mark[0].v.string) == -1)
				err(1, "string: asprintf");
			free(yystack.l_mark[-1].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 46:
#line 733 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (asprintf(&yyval.v.string, "%s %s", yystack.l_mark[-1].v.string, yystack.l_mark[0].v.string) == -1)
				err(1, "string: asprintf");
			free(yystack.l_mark[-1].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 48:
#line 742 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			char	*s;
			if (asprintf(&s, "%lld", (long long)yystack.l_mark[0].v.number) == -1) {
				yyerror("string: asprintf");
				YYERROR;
			}
			yyval.v.string = s;
		}
break;
case 50:
#line 753 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (pf->opts & PF_OPT_VERBOSE)
				printf("%s = \"%s\"\n", yystack.l_mark[-2].v.string, yystack.l_mark[0].v.string);
			if (symset(yystack.l_mark[-2].v.string, yystack.l_mark[0].v.string, 0) == -1)
				err(1, "cannot store variable %s", yystack.l_mark[-2].v.string);
			free(yystack.l_mark[-2].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 51:
#line 763 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.string = yystack.l_mark[0].v.string; }
break;
case 52:
#line 764 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.string = NULL; }
break;
case 57:
#line 774 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			char ta[PF_ANCHOR_NAME_SIZE];
			struct pf_ruleset *rs;

			/* steping into a brace anchor */
			pf->asd++;
			pf->bn++;
			pf->brace = 1;

			/* create a holding ruleset in the root */
			snprintf(ta, PF_ANCHOR_NAME_SIZE, "_%d", pf->bn);
			rs = pf_find_or_create_ruleset(ta);
			if (rs == NULL)
				err(1, "pfa_anchor: pf_find_or_create_ruleset");
			pf->astack[pf->asd] = rs->anchor;
			pf->anchor = rs->anchor;
		}
break;
case 58:
#line 791 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			pf->alast = pf->anchor;
			pf->asd--;
			pf->anchor = pf->astack[pf->asd];
		}
break;
case 60:
#line 801 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct pf_rule	r;
			struct node_proto	*proto;

			if (check_rulestate(PFCTL_STATE_FILTER)) {
				if (yystack.l_mark[-8].v.string)
					free(yystack.l_mark[-8].v.string);
				YYERROR;
			}

			if (yystack.l_mark[-8].v.string && (yystack.l_mark[-8].v.string[0] == '_' || strstr(yystack.l_mark[-8].v.string, "/_") != NULL)) {
				free(yystack.l_mark[-8].v.string);
				yyerror("anchor names beginning with '_' "
				    "are reserved for internal use");
				YYERROR;
			}

			memset(&r, 0, sizeof(r));
			if (pf->astack[pf->asd + 1]) {
				/* move inline rules into relative location */
				pf_anchor_setup(&r,
				    &pf->astack[pf->asd]->ruleset,
				    yystack.l_mark[-8].v.string ? yystack.l_mark[-8].v.string : pf->alast->name);
		
				if (r.anchor == NULL)
					err(1, "anchorrule: unable to "
					    "create ruleset");

				if (pf->alast != r.anchor) {
					if (r.anchor->match) {
						yyerror("inline anchor '%s' "
						    "already exists",
						    r.anchor->name);
						YYERROR;
					}
					mv_rules(&pf->alast->ruleset,
					    &r.anchor->ruleset);
				}
				pf_remove_if_empty_ruleset(&pf->alast->ruleset);
				pf->alast = r.anchor;
			} else {
				if (!yystack.l_mark[-8].v.string) {
					yyerror("anchors without explicit "
					    "rules must specify a name");
					YYERROR;
				}
			}
			r.direction = yystack.l_mark[-7].v.i;
			r.quick = yystack.l_mark[-6].v.logquick.quick;
			r.af = yystack.l_mark[-4].v.i;
			r.prob = yystack.l_mark[-1].v.filter_opts.prob;
			r.rtableid = yystack.l_mark[-1].v.filter_opts.rtableid;

			if (yystack.l_mark[-1].v.filter_opts.tag)
				if (strlcpy(r.tagname, yystack.l_mark[-1].v.filter_opts.tag,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			if (yystack.l_mark[-1].v.filter_opts.match_tag)
				if (strlcpy(r.match_tagname, yystack.l_mark[-1].v.filter_opts.match_tag,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			r.match_tag_not = yystack.l_mark[-1].v.filter_opts.match_tag_not;
			if (rule_label(&r, yystack.l_mark[-1].v.filter_opts.label))
				YYERROR;
			free(yystack.l_mark[-1].v.filter_opts.label);
			r.flags = yystack.l_mark[-1].v.filter_opts.flags.b1;
			r.flagset = yystack.l_mark[-1].v.filter_opts.flags.b2;
			if ((yystack.l_mark[-1].v.filter_opts.flags.b1 & yystack.l_mark[-1].v.filter_opts.flags.b2) != yystack.l_mark[-1].v.filter_opts.flags.b1) {
				yyerror("flags always false");
				YYERROR;
			}
			if (yystack.l_mark[-1].v.filter_opts.flags.b1 || yystack.l_mark[-1].v.filter_opts.flags.b2 || yystack.l_mark[-2].v.fromto.src_os) {
				for (proto = yystack.l_mark[-3].v.proto; proto != NULL &&
				    proto->proto != IPPROTO_TCP;
				    proto = proto->next)
					;	/* nothing */
				if (proto == NULL && yystack.l_mark[-3].v.proto != NULL) {
					if (yystack.l_mark[-1].v.filter_opts.flags.b1 || yystack.l_mark[-1].v.filter_opts.flags.b2)
						yyerror(
						    "flags only apply to tcp");
					if (yystack.l_mark[-2].v.fromto.src_os)
						yyerror(
						    "OS fingerprinting only "
						    "applies to tcp");
					YYERROR;
				}
			}

			r.tos = yystack.l_mark[-1].v.filter_opts.tos;

			if (yystack.l_mark[-1].v.filter_opts.keep.action) {
				yyerror("cannot specify state handling "
				    "on anchors");
				YYERROR;
			}

			if (yystack.l_mark[-1].v.filter_opts.match_tag)
				if (strlcpy(r.match_tagname, yystack.l_mark[-1].v.filter_opts.match_tag,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			r.match_tag_not = yystack.l_mark[-1].v.filter_opts.match_tag_not;
			if (yystack.l_mark[-1].v.filter_opts.marker & FOM_PRIO) {
				if (yystack.l_mark[-1].v.filter_opts.prio == 0)
					r.prio = PF_PRIO_ZERO;
				else
					r.prio = yystack.l_mark[-1].v.filter_opts.prio;
			}
			if (yystack.l_mark[-1].v.filter_opts.marker & FOM_SETPRIO) {
				r.set_prio[0] = yystack.l_mark[-1].v.filter_opts.set_prio[0];
				r.set_prio[1] = yystack.l_mark[-1].v.filter_opts.set_prio[1];
				r.scrub_flags |= PFSTATE_SETPRIO;
			}

			decide_address_family(yystack.l_mark[-2].v.fromto.src.host, &r.af);
			decide_address_family(yystack.l_mark[-2].v.fromto.dst.host, &r.af);

			expand_rule(&r, yystack.l_mark[-5].v.interface, NULL, yystack.l_mark[-3].v.proto, yystack.l_mark[-2].v.fromto.src_os,
			    yystack.l_mark[-2].v.fromto.src.host, yystack.l_mark[-2].v.fromto.src.port, yystack.l_mark[-2].v.fromto.dst.host, yystack.l_mark[-2].v.fromto.dst.port,
			    yystack.l_mark[-1].v.filter_opts.uid, yystack.l_mark[-1].v.filter_opts.gid, yystack.l_mark[-1].v.filter_opts.icmpspec,
			    pf->astack[pf->asd + 1] ? pf->alast->name : yystack.l_mark[-8].v.string);
			free(yystack.l_mark[-8].v.string);
			pf->astack[pf->asd + 1] = NULL;
		}
break;
case 61:
#line 933 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct pf_rule	r;

			if (check_rulestate(PFCTL_STATE_NAT)) {
				free(yystack.l_mark[-5].v.string);
				YYERROR;
			}

			memset(&r, 0, sizeof(r));
			r.action = PF_NAT;
			r.af = yystack.l_mark[-3].v.i;
			r.rtableid = yystack.l_mark[0].v.rtableid;

			decide_address_family(yystack.l_mark[-1].v.fromto.src.host, &r.af);
			decide_address_family(yystack.l_mark[-1].v.fromto.dst.host, &r.af);

			expand_rule(&r, yystack.l_mark[-4].v.interface, NULL, yystack.l_mark[-2].v.proto, yystack.l_mark[-1].v.fromto.src_os,
			    yystack.l_mark[-1].v.fromto.src.host, yystack.l_mark[-1].v.fromto.src.port, yystack.l_mark[-1].v.fromto.dst.host, yystack.l_mark[-1].v.fromto.dst.port,
			    0, 0, 0, yystack.l_mark[-5].v.string);
			free(yystack.l_mark[-5].v.string);
		}
break;
case 62:
#line 954 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct pf_rule	r;

			if (check_rulestate(PFCTL_STATE_NAT)) {
				free(yystack.l_mark[-5].v.string);
				YYERROR;
			}

			memset(&r, 0, sizeof(r));
			r.action = PF_RDR;
			r.af = yystack.l_mark[-3].v.i;
			r.rtableid = yystack.l_mark[0].v.rtableid;

			decide_address_family(yystack.l_mark[-1].v.fromto.src.host, &r.af);
			decide_address_family(yystack.l_mark[-1].v.fromto.dst.host, &r.af);

			if (yystack.l_mark[-1].v.fromto.src.port != NULL) {
				yyerror("source port parameter not supported"
				    " in rdr-anchor");
				YYERROR;
			}
			if (yystack.l_mark[-1].v.fromto.dst.port != NULL) {
				if (yystack.l_mark[-1].v.fromto.dst.port->next != NULL) {
					yyerror("destination port list "
					    "expansion not supported in "
					    "rdr-anchor");
					YYERROR;
				} else if (yystack.l_mark[-1].v.fromto.dst.port->op != PF_OP_EQ) {
					yyerror("destination port operators"
					    " not supported in rdr-anchor");
					YYERROR;
				}
				r.dst.port[0] = yystack.l_mark[-1].v.fromto.dst.port->port[0];
				r.dst.port[1] = yystack.l_mark[-1].v.fromto.dst.port->port[1];
				r.dst.port_op = yystack.l_mark[-1].v.fromto.dst.port->op;
			}

			expand_rule(&r, yystack.l_mark[-4].v.interface, NULL, yystack.l_mark[-2].v.proto, yystack.l_mark[-1].v.fromto.src_os,
			    yystack.l_mark[-1].v.fromto.src.host, yystack.l_mark[-1].v.fromto.src.port, yystack.l_mark[-1].v.fromto.dst.host, yystack.l_mark[-1].v.fromto.dst.port,
			    0, 0, 0, yystack.l_mark[-5].v.string);
			free(yystack.l_mark[-5].v.string);
		}
break;
case 63:
#line 996 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct pf_rule	r;

			if (check_rulestate(PFCTL_STATE_NAT)) {
				free(yystack.l_mark[-5].v.string);
				YYERROR;
			}

			memset(&r, 0, sizeof(r));
			r.action = PF_BINAT;
			r.af = yystack.l_mark[-3].v.i;
			r.rtableid = yystack.l_mark[0].v.rtableid;
			if (yystack.l_mark[-2].v.proto != NULL) {
				if (yystack.l_mark[-2].v.proto->next != NULL) {
					yyerror("proto list expansion"
					    " not supported in binat-anchor");
					YYERROR;
				}
				r.proto = yystack.l_mark[-2].v.proto->proto;
				free(yystack.l_mark[-2].v.proto);
			}

			if (yystack.l_mark[-1].v.fromto.src.host != NULL || yystack.l_mark[-1].v.fromto.src.port != NULL ||
			    yystack.l_mark[-1].v.fromto.dst.host != NULL || yystack.l_mark[-1].v.fromto.dst.port != NULL) {
				yyerror("fromto parameter not supported"
				    " in binat-anchor");
				YYERROR;
			}

			decide_address_family(yystack.l_mark[-1].v.fromto.src.host, &r.af);
			decide_address_family(yystack.l_mark[-1].v.fromto.dst.host, &r.af);

			pfctl_add_rule(pf, &r, yystack.l_mark[-5].v.string);
			free(yystack.l_mark[-5].v.string);
		}
break;
case 64:
#line 1033 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct loadanchors	*loadanchor;

			if (strlen(pf->anchor->name) + 1 +
			    strlen(yystack.l_mark[-2].v.string) >= MAXPATHLEN) {
				yyerror("anchorname %s too long, max %u\n",
				    yystack.l_mark[-2].v.string, MAXPATHLEN - 1);
				free(yystack.l_mark[-2].v.string);
				YYERROR;
			}
			loadanchor = calloc(1, sizeof(struct loadanchors));
			if (loadanchor == NULL)
				err(1, "loadrule: calloc");
			if ((loadanchor->anchorname = malloc(MAXPATHLEN)) ==
			    NULL)
				err(1, "loadrule: malloc");
			if (pf->anchor->name[0])
				snprintf(loadanchor->anchorname, MAXPATHLEN,
				    "%s/%s", pf->anchor->name, yystack.l_mark[-2].v.string);
			else
				strlcpy(loadanchor->anchorname, yystack.l_mark[-2].v.string, MAXPATHLEN);
			if ((loadanchor->filename = strdup(yystack.l_mark[0].v.string)) == NULL)
				err(1, "loadrule: strdup");

			TAILQ_INSERT_TAIL(&loadanchorshead, loadanchor,
			    entries);

			free(yystack.l_mark[-2].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 65:
#line 1064 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = yyval.v.b.w = 0;
			if (yystack.l_mark[-1].v.i)
				yyval.v.b.b1 = PF_NOSCRUB;
			else
				yyval.v.b.b1 = PF_SCRUB;
		}
break;
case 66:
#line 1074 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct pf_rule	r;

			if (check_rulestate(PFCTL_STATE_SCRUB))
				YYERROR;

			memset(&r, 0, sizeof(r));

			r.action = yystack.l_mark[-7].v.b.b1;
			r.direction = yystack.l_mark[-6].v.i;

			r.log = yystack.l_mark[-5].v.logquick.log;
			r.logif = yystack.l_mark[-5].v.logquick.logif;
			if (yystack.l_mark[-5].v.logquick.quick) {
				yyerror("scrub rules do not support 'quick'");
				YYERROR;
			}

			r.af = yystack.l_mark[-3].v.i;
			if (yystack.l_mark[0].v.scrub_opts.nodf)
				r.rule_flag |= PFRULE_NODF;
			if (yystack.l_mark[0].v.scrub_opts.randomid)
				r.rule_flag |= PFRULE_RANDOMID;
			if (yystack.l_mark[0].v.scrub_opts.reassemble_tcp) {
				if (r.direction != PF_INOUT) {
					yyerror("reassemble tcp rules can not "
					    "specify direction");
					YYERROR;
				}
				r.rule_flag |= PFRULE_REASSEMBLE_TCP;
			}
			if (yystack.l_mark[0].v.scrub_opts.minttl)
				r.min_ttl = yystack.l_mark[0].v.scrub_opts.minttl;
			if (yystack.l_mark[0].v.scrub_opts.maxmss)
				r.max_mss = yystack.l_mark[0].v.scrub_opts.maxmss;
			if (yystack.l_mark[0].v.scrub_opts.marker & SOM_SETTOS) {
				r.rule_flag |= PFRULE_SET_TOS;
				r.set_tos = yystack.l_mark[0].v.scrub_opts.settos;
			}
			if (yystack.l_mark[0].v.scrub_opts.fragcache)
				r.rule_flag |= yystack.l_mark[0].v.scrub_opts.fragcache;
			if (yystack.l_mark[0].v.scrub_opts.match_tag)
				if (strlcpy(r.match_tagname, yystack.l_mark[0].v.scrub_opts.match_tag,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			r.match_tag_not = yystack.l_mark[0].v.scrub_opts.match_tag_not;
			r.rtableid = yystack.l_mark[0].v.scrub_opts.rtableid;

			expand_rule(&r, yystack.l_mark[-4].v.interface, NULL, yystack.l_mark[-2].v.proto, yystack.l_mark[-1].v.fromto.src_os,
			    yystack.l_mark[-1].v.fromto.src.host, yystack.l_mark[-1].v.fromto.src.port, yystack.l_mark[-1].v.fromto.dst.host, yystack.l_mark[-1].v.fromto.dst.port,
			    NULL, NULL, NULL, "");
		}
break;
case 67:
#line 1131 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
				bzero(&scrub_opts, sizeof scrub_opts);
				scrub_opts.rtableid = -1;
			}
break;
case 68:
#line 1136 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.scrub_opts = scrub_opts; }
break;
case 69:
#line 1137 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			bzero(&scrub_opts, sizeof scrub_opts);
			scrub_opts.rtableid = -1;
			yyval.v.scrub_opts = scrub_opts;
		}
break;
case 72:
#line 1148 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (scrub_opts.nodf) {
				yyerror("no-df cannot be respecified");
				YYERROR;
			}
			scrub_opts.nodf = 1;
		}
break;
case 73:
#line 1155 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (scrub_opts.marker & SOM_MINTTL) {
				yyerror("min-ttl cannot be respecified");
				YYERROR;
			}
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("illegal min-ttl value %d", yystack.l_mark[0].v.number);
				YYERROR;
			}
			scrub_opts.marker |= SOM_MINTTL;
			scrub_opts.minttl = yystack.l_mark[0].v.number;
		}
break;
case 74:
#line 1167 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (scrub_opts.marker & SOM_MAXMSS) {
				yyerror("max-mss cannot be respecified");
				YYERROR;
			}
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 65535) {
				yyerror("illegal max-mss value %d", yystack.l_mark[0].v.number);
				YYERROR;
			}
			scrub_opts.marker |= SOM_MAXMSS;
			scrub_opts.maxmss = yystack.l_mark[0].v.number;
		}
break;
case 75:
#line 1179 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (scrub_opts.marker & SOM_SETTOS) {
				yyerror("set-tos cannot be respecified");
				YYERROR;
			}
			scrub_opts.marker |= SOM_SETTOS;
			scrub_opts.settos = yystack.l_mark[0].v.number;
		}
break;
case 76:
#line 1187 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (scrub_opts.marker & SOM_FRAGCACHE) {
				yyerror("fragcache cannot be respecified");
				YYERROR;
			}
			scrub_opts.marker |= SOM_FRAGCACHE;
			scrub_opts.fragcache = yystack.l_mark[0].v.i;
		}
break;
case 77:
#line 1195 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (strcasecmp(yystack.l_mark[0].v.string, "tcp") != 0) {
				yyerror("scrub reassemble supports only tcp, "
				    "not '%s'", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
			if (scrub_opts.reassemble_tcp) {
				yyerror("reassemble tcp cannot be respecified");
				YYERROR;
			}
			scrub_opts.reassemble_tcp = 1;
		}
break;
case 78:
#line 1209 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (scrub_opts.randomid) {
				yyerror("random-id cannot be respecified");
				YYERROR;
			}
			scrub_opts.randomid = 1;
		}
break;
case 79:
#line 1216 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > rt_tableid_max()) {
				yyerror("invalid rtable id");
				YYERROR;
			}
			scrub_opts.rtableid = yystack.l_mark[0].v.number;
		}
break;
case 80:
#line 1223 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			scrub_opts.match_tag = yystack.l_mark[0].v.string;
			scrub_opts.match_tag_not = yystack.l_mark[-2].v.number;
		}
break;
case 81:
#line 1229 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = 0; /* default */ }
break;
case 82:
#line 1230 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = 0; }
break;
case 83:
#line 1231 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = 0; }
break;
case 84:
#line 1234 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct pf_rule		 r;
			struct node_host	*h = NULL, *hh;
			struct node_if		*i, *j;

			if (check_rulestate(PFCTL_STATE_FILTER))
				YYERROR;

			for (i = yystack.l_mark[-2].v.interface; i; i = i->next) {
				bzero(&r, sizeof(r));

				r.action = PF_DROP;
				r.direction = PF_IN;
				r.log = yystack.l_mark[-3].v.logquick.log;
				r.logif = yystack.l_mark[-3].v.logquick.logif;
				r.quick = yystack.l_mark[-3].v.logquick.quick;
				r.af = yystack.l_mark[-1].v.i;
				if (rule_label(&r, yystack.l_mark[0].v.antispoof_opts.label))
					YYERROR;
				r.rtableid = yystack.l_mark[0].v.antispoof_opts.rtableid;
				r.cuid = yystack.l_mark[0].v.antispoof_opts.tracker;
				j = calloc(1, sizeof(struct node_if));
				if (j == NULL)
					err(1, "antispoof: calloc");
				if (strlcpy(j->ifname, i->ifname,
				    sizeof(j->ifname)) >= sizeof(j->ifname)) {
					free(j);
					yyerror("interface name too long");
					YYERROR;
				}
				j->not = 1;
				if (i->dynamic) {
					h = calloc(1, sizeof(*h));
					if (h == NULL)
						err(1, "address: calloc");
					h->addr.type = PF_ADDR_DYNIFTL;
					set_ipmask(h, 128);
					if (strlcpy(h->addr.v.ifname, i->ifname,
					    sizeof(h->addr.v.ifname)) >=
					    sizeof(h->addr.v.ifname)) {
						free(h);
						yyerror(
						    "interface name too long");
						YYERROR;
					}
					hh = malloc(sizeof(*hh));
					if (hh == NULL)
						 err(1, "address: malloc");
					bcopy(h, hh, sizeof(*hh));
					h->addr.iflags = PFI_AFLAG_NETWORK;
				} else {
					h = ifa_lookup(j->ifname,
					    PFI_AFLAG_NETWORK);
					hh = NULL;
				}

				if (h != NULL)
					expand_rule(&r, j, NULL, NULL, NULL, h,
					    NULL, NULL, NULL, NULL, NULL,
					    NULL, "");

				if ((i->ifa_flags & IFF_LOOPBACK) == 0) {
					bzero(&r, sizeof(r));

					r.action = PF_DROP;
					r.direction = PF_IN;
					r.log = yystack.l_mark[-3].v.logquick.log;
					r.logif = yystack.l_mark[-3].v.logquick.logif;
					r.quick = yystack.l_mark[-3].v.logquick.quick;
					r.af = yystack.l_mark[-1].v.i;
					r.cuid = yystack.l_mark[0].v.antispoof_opts.tracker;
					if (rule_label(&r, yystack.l_mark[0].v.antispoof_opts.label))
						YYERROR;
					r.rtableid = yystack.l_mark[0].v.antispoof_opts.rtableid;
					if (hh != NULL)
						h = hh;
					else
						h = ifa_lookup(i->ifname, 0);
					if (h != NULL)
						expand_rule(&r, NULL, NULL,
						    NULL, NULL, h, NULL, NULL,
						    NULL, NULL, NULL, NULL, "");
				} else
					free(hh);
			}
			free(yystack.l_mark[0].v.antispoof_opts.label);
		}
break;
case 85:
#line 1323 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[0].v.interface; }
break;
case 86:
#line 1324 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[-1].v.interface; }
break;
case 87:
#line 1327 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[-1].v.interface; }
break;
case 88:
#line 1328 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.interface->tail->next = yystack.l_mark[-1].v.interface;
			yystack.l_mark[-3].v.interface->tail = yystack.l_mark[-1].v.interface;
			yyval.v.interface = yystack.l_mark[-3].v.interface;
		}
break;
case 89:
#line 1335 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[0].v.interface; }
break;
case 90:
#line 1336 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-1].v.interface->dynamic = 1;
			yyval.v.interface = yystack.l_mark[-1].v.interface;
		}
break;
case 91:
#line 1342 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
				bzero(&antispoof_opts, sizeof antispoof_opts);
				antispoof_opts.rtableid = -1;
			}
break;
case 92:
#line 1347 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.antispoof_opts = antispoof_opts; }
break;
case 93:
#line 1348 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			bzero(&antispoof_opts, sizeof antispoof_opts);
			antispoof_opts.rtableid = -1;
			yyval.v.antispoof_opts = antispoof_opts;
		}
break;
case 96:
#line 1359 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (antispoof_opts.label) {
				yyerror("label cannot be redefined");
				YYERROR;
			}
			antispoof_opts.label = yystack.l_mark[0].v.string;
		}
break;
case 97:
#line 1366 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			antispoof_opts.tracker = yystack.l_mark[0].v.number;
		}
break;
case 98:
#line 1369 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > rt_tableid_max()) {
				yyerror("invalid rtable id");
				YYERROR;
			}
			antispoof_opts.rtableid = yystack.l_mark[0].v.number;
		}
break;
case 99:
#line 1378 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.number = 1; }
break;
case 100:
#line 1379 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.number = 0; }
break;
case 101:
#line 1382 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct node_host	 *h, *nh;
			struct node_tinit	 *ti, *nti;

			if (strlen(yystack.l_mark[-2].v.string) >= PF_TABLE_NAME_SIZE) {
				yyerror("table name too long, max %d chars",
				    PF_TABLE_NAME_SIZE - 1);
				free(yystack.l_mark[-2].v.string);
				YYERROR;
			}
			if (pf->loadopt & PFCTL_FLAG_TABLE)
				if (process_tabledef(yystack.l_mark[-2].v.string, &yystack.l_mark[0].v.table_opts)) {
					free(yystack.l_mark[-2].v.string);
					YYERROR;
				}
			free(yystack.l_mark[-2].v.string);
			for (ti = SIMPLEQ_FIRST(&yystack.l_mark[0].v.table_opts.init_nodes);
			    ti != SIMPLEQ_END(&yystack.l_mark[0].v.table_opts.init_nodes); ti = nti) {
				if (ti->file)
					free(ti->file);
				for (h = ti->host; h != NULL; h = nh) {
					nh = h->next;
					free(h);
				}
				nti = SIMPLEQ_NEXT(ti, entries);
				free(ti);
			}
		}
break;
case 102:
#line 1412 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			bzero(&table_opts, sizeof table_opts);
			SIMPLEQ_INIT(&table_opts.init_nodes);
		}
break;
case 103:
#line 1417 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.table_opts = table_opts; }
break;
case 104:
#line 1419 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			bzero(&table_opts, sizeof table_opts);
			SIMPLEQ_INIT(&table_opts.init_nodes);
			yyval.v.table_opts = table_opts;
		}
break;
case 107:
#line 1430 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "const"))
				table_opts.flags |= PFR_TFLAG_CONST;
			else if (!strcmp(yystack.l_mark[0].v.string, "persist"))
				table_opts.flags |= PFR_TFLAG_PERSIST;
			else if (!strcmp(yystack.l_mark[0].v.string, "counters"))
				table_opts.flags |= PFR_TFLAG_COUNTERS;
			else {
				yyerror("invalid table option '%s'", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 108:
#line 1444 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ table_opts.init_addr = 1; }
break;
case 109:
#line 1445 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct node_host	*n;
			struct node_tinit	*ti;

			for (n = yystack.l_mark[-1].v.host; n != NULL; n = n->next) {
				switch (n->addr.type) {
				case PF_ADDR_ADDRMASK:
					continue; /* ok */
				case PF_ADDR_RANGE:
					yyerror("address ranges are not "
					    "permitted inside tables");
					break;
				case PF_ADDR_DYNIFTL:
					yyerror("dynamic addresses are not "
					    "permitted inside tables");
					break;
				case PF_ADDR_TABLE:
					yyerror("tables cannot contain tables");
					break;
				case PF_ADDR_NOROUTE:
					yyerror("\"no-route\" is not permitted "
					    "inside tables");
					break;
				case PF_ADDR_URPFFAILED:
					yyerror("\"urpf-failed\" is not "
					    "permitted inside tables");
					break;
				default:
					yyerror("unknown address type %d",
					    n->addr.type);
				}
				YYERROR;
			}
			if (!(ti = calloc(1, sizeof(*ti))))
				err(1, "table_opt: calloc");
			ti->host = yystack.l_mark[-1].v.host;
			SIMPLEQ_INSERT_TAIL(&table_opts.init_nodes, ti,
			    entries);
			table_opts.init_addr = 1;
		}
break;
case 110:
#line 1485 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct node_tinit	*ti;

			if (!(ti = calloc(1, sizeof(*ti))))
				err(1, "table_opt: calloc");
			ti->file = yystack.l_mark[0].v.string;
			SIMPLEQ_INSERT_TAIL(&table_opts.init_nodes, ti,
			    entries);
			table_opts.init_addr = 1;
		}
break;
case 111:
#line 1497 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct pf_altq	a;

			if (check_rulestate(PFCTL_STATE_QUEUE))
				YYERROR;

			memset(&a, 0, sizeof(a));
			if (yystack.l_mark[-2].v.queue_opts.scheduler.qtype == ALTQT_NONE) {
				yyerror("no scheduler specified!");
				YYERROR;
			}
			a.scheduler = yystack.l_mark[-2].v.queue_opts.scheduler.qtype;
			a.qlimit = yystack.l_mark[-2].v.queue_opts.qlimit;
			a.tbrsize = yystack.l_mark[-2].v.queue_opts.tbrsize;
			if (yystack.l_mark[0].v.queue == NULL && yystack.l_mark[-2].v.queue_opts.scheduler.qtype != ALTQT_CODEL) {
				yyerror("no child queues specified");
				YYERROR;
			}
			if (expand_altq(&a, yystack.l_mark[-3].v.interface, yystack.l_mark[0].v.queue, yystack.l_mark[-2].v.queue_opts.queue_bwspec,
			    &yystack.l_mark[-2].v.queue_opts.scheduler))
				YYERROR;
		}
break;
case 112:
#line 1521 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct pf_altq	a;

			if (check_rulestate(PFCTL_STATE_QUEUE)) {
				free(yystack.l_mark[-3].v.string);
				YYERROR;
			}

			memset(&a, 0, sizeof(a));

			if (strlcpy(a.qname, yystack.l_mark[-3].v.string, sizeof(a.qname)) >=
			    sizeof(a.qname)) {
				yyerror("queue name too long (max "
				    "%d chars)", PF_QNAME_SIZE-1);
				free(yystack.l_mark[-3].v.string);
				YYERROR;
			}
			free(yystack.l_mark[-3].v.string);
			if (yystack.l_mark[-1].v.queue_opts.tbrsize) {
				yyerror("cannot specify tbrsize for queue");
				YYERROR;
			}
			if (yystack.l_mark[-1].v.queue_opts.priority > 255) {
				yyerror("priority out of range: max 255");
				YYERROR;
			}
			a.priority = yystack.l_mark[-1].v.queue_opts.priority;
			a.qlimit = yystack.l_mark[-1].v.queue_opts.qlimit;
			a.scheduler = yystack.l_mark[-1].v.queue_opts.scheduler.qtype;
			if (expand_queue(&a, yystack.l_mark[-2].v.interface, yystack.l_mark[0].v.queue, yystack.l_mark[-1].v.queue_opts.queue_bwspec,
			    &yystack.l_mark[-1].v.queue_opts.scheduler)) {
				yyerror("errors in queue definition");
				YYERROR;
			}
		}
break;
case 113:
#line 1558 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			bzero(&queue_opts, sizeof queue_opts);
			queue_opts.priority = DEFAULT_PRIORITY;
			queue_opts.qlimit = DEFAULT_QLIMIT;
			queue_opts.scheduler.qtype = ALTQT_NONE;
			queue_opts.queue_bwspec.bw_percent = 100;
		}
break;
case 114:
#line 1566 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.queue_opts = queue_opts; }
break;
case 115:
#line 1567 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			bzero(&queue_opts, sizeof queue_opts);
			queue_opts.priority = DEFAULT_PRIORITY;
			queue_opts.qlimit = DEFAULT_QLIMIT;
			queue_opts.scheduler.qtype = ALTQT_NONE;
			queue_opts.queue_bwspec.bw_percent = 100;
			yyval.v.queue_opts = queue_opts;
		}
break;
case 118:
#line 1581 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (queue_opts.marker & QOM_BWSPEC) {
				yyerror("bandwidth cannot be respecified");
				YYERROR;
			}
			queue_opts.marker |= QOM_BWSPEC;
			queue_opts.queue_bwspec = yystack.l_mark[0].v.queue_bwspec;
		}
break;
case 119:
#line 1589 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (queue_opts.marker & QOM_PRIORITY) {
				yyerror("priority cannot be respecified");
				YYERROR;
			}
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("priority out of range: max 255");
				YYERROR;
			}
			queue_opts.marker |= QOM_PRIORITY;
			queue_opts.priority = yystack.l_mark[0].v.number;
		}
break;
case 120:
#line 1601 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (queue_opts.marker & QOM_QLIMIT) {
				yyerror("qlimit cannot be respecified");
				YYERROR;
			}
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 65535) {
				yyerror("qlimit out of range: max 65535");
				YYERROR;
			}
			queue_opts.marker |= QOM_QLIMIT;
			queue_opts.qlimit = yystack.l_mark[0].v.number;
		}
break;
case 121:
#line 1613 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (queue_opts.marker & QOM_SCHEDULER) {
				yyerror("scheduler cannot be respecified");
				YYERROR;
			}
			queue_opts.marker |= QOM_SCHEDULER;
			queue_opts.scheduler = yystack.l_mark[0].v.queue_options;
		}
break;
case 122:
#line 1621 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (queue_opts.marker & QOM_TBRSIZE) {
				yyerror("tbrsize cannot be respecified");
				YYERROR;
			}
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 65535) {
				yyerror("tbrsize too big: max 65535");
				YYERROR;
			}
			queue_opts.marker |= QOM_TBRSIZE;
			queue_opts.tbrsize = yystack.l_mark[0].v.number;
		}
break;
case 123:
#line 1635 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			double	 bps;
			char	*cp;

			yyval.v.queue_bwspec.bw_percent = 0;

			bps = strtod(yystack.l_mark[0].v.string, &cp);
			if (cp != NULL) {
				if (strlen(cp) > 1) {
					char *cu = cp + 1;
					if (!strcmp(cu, "Bit") ||
					    !strcmp(cu, "B") ||
					    !strcmp(cu, "bit") ||
					    !strcmp(cu, "b")) {
						*cu = 0;
					}
				}
				if (!strcmp(cp, "b"))
					; /* nothing */
				else if (!strcmp(cp, "K"))
					bps *= 1000;
				else if (!strcmp(cp, "M"))
					bps *= 1000 * 1000;
				else if (!strcmp(cp, "G"))
					bps *= 1000 * 1000 * 1000;
				else if (!strcmp(cp, "%")) {
					if (bps < 0 || bps > 100) {
						yyerror("bandwidth spec "
						    "out of range");
						free(yystack.l_mark[0].v.string);
						YYERROR;
					}
					yyval.v.queue_bwspec.bw_percent = bps;
					bps = 0;
				} else {
					yyerror("unknown unit %s", cp);
					free(yystack.l_mark[0].v.string);
					YYERROR;
				}
			}
			free(yystack.l_mark[0].v.string);
			yyval.v.queue_bwspec.bw_absolute = (u_int32_t)bps;
		}
break;
case 124:
#line 1678 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("bandwidth number too big");
				YYERROR;
			}
			yyval.v.queue_bwspec.bw_percent = 0;
			yyval.v.queue_bwspec.bw_absolute = yystack.l_mark[0].v.number;
		}
break;
case 125:
#line 1688 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_CBQ;
			yyval.v.queue_options.data.cbq_opts.flags = 0;
		}
break;
case 126:
#line 1692 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_CBQ;
			yyval.v.queue_options.data.cbq_opts.flags = yystack.l_mark[-1].v.number;
		}
break;
case 127:
#line 1696 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_PRIQ;
			yyval.v.queue_options.data.priq_opts.flags = 0;
		}
break;
case 128:
#line 1700 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_PRIQ;
			yyval.v.queue_options.data.priq_opts.flags = yystack.l_mark[-1].v.number;
		}
break;
case 129:
#line 1704 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_HFSC;
			bzero(&yyval.v.queue_options.data.hfsc_opts,
			    sizeof(struct node_hfsc_opts));
		}
break;
case 130:
#line 1709 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_HFSC;
			yyval.v.queue_options.data.hfsc_opts = yystack.l_mark[-1].v.hfsc_opts;
		}
break;
case 131:
#line 1713 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_FAIRQ;
			bzero(&yyval.v.queue_options.data.fairq_opts,
				sizeof(struct node_fairq_opts));
		}
break;
case 132:
#line 1718 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_FAIRQ;
			yyval.v.queue_options.data.fairq_opts = yystack.l_mark[-1].v.fairq_opts;
		}
break;
case 133:
#line 1722 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_CODEL;
			bzero(&yyval.v.queue_options.data.codel_opts,
				sizeof(struct codel_opts));
		}
break;
case 134:
#line 1727 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_CODEL;
			yyval.v.queue_options.data.codel_opts = yystack.l_mark[-1].v.codel_opts;
		}
break;
case 135:
#line 1733 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.number |= yystack.l_mark[0].v.number; }
break;
case 136:
#line 1734 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.number |= yystack.l_mark[0].v.number; }
break;
case 137:
#line 1737 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "default"))
				yyval.v.number = CBQCLF_DEFCLASS;
			else if (!strcmp(yystack.l_mark[0].v.string, "borrow"))
				yyval.v.number = CBQCLF_BORROW;
			else if (!strcmp(yystack.l_mark[0].v.string, "red"))
				yyval.v.number = CBQCLF_RED;
			else if (!strcmp(yystack.l_mark[0].v.string, "ecn"))
				yyval.v.number = CBQCLF_RED|CBQCLF_ECN;
			else if (!strcmp(yystack.l_mark[0].v.string, "rio"))
				yyval.v.number = CBQCLF_RIO;
			else if (!strcmp(yystack.l_mark[0].v.string, "codel"))
				yyval.v.number = CBQCLF_CODEL;
			else {
				yyerror("unknown cbq flag \"%s\"", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 138:
#line 1759 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.number |= yystack.l_mark[0].v.number; }
break;
case 139:
#line 1760 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.number |= yystack.l_mark[0].v.number; }
break;
case 140:
#line 1763 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "default"))
				yyval.v.number = PRCF_DEFAULTCLASS;
			else if (!strcmp(yystack.l_mark[0].v.string, "red"))
				yyval.v.number = PRCF_RED;
			else if (!strcmp(yystack.l_mark[0].v.string, "ecn"))
				yyval.v.number = PRCF_RED|PRCF_ECN;
			else if (!strcmp(yystack.l_mark[0].v.string, "rio"))
				yyval.v.number = PRCF_RIO;
			else if (!strcmp(yystack.l_mark[0].v.string, "codel"))
				yyval.v.number = PRCF_CODEL;
			else {
				yyerror("unknown priq flag \"%s\"", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 141:
#line 1783 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
				bzero(&hfsc_opts,
				    sizeof(struct node_hfsc_opts));
			}
break;
case 142:
#line 1787 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.hfsc_opts = hfsc_opts;
		}
break;
case 145:
#line 1796 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (hfsc_opts.linkshare.used) {
				yyerror("linkshare already specified");
				YYERROR;
			}
			hfsc_opts.linkshare.m2 = yystack.l_mark[0].v.queue_bwspec;
			hfsc_opts.linkshare.used = 1;
		}
break;
case 146:
#line 1805 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-3].v.number < 0 || yystack.l_mark[-3].v.number > INT_MAX) {
				yyerror("timing in curve out of range");
				YYERROR;
			}
			if (hfsc_opts.linkshare.used) {
				yyerror("linkshare already specified");
				YYERROR;
			}
			hfsc_opts.linkshare.m1 = yystack.l_mark[-5].v.queue_bwspec;
			hfsc_opts.linkshare.d = yystack.l_mark[-3].v.number;
			hfsc_opts.linkshare.m2 = yystack.l_mark[-1].v.queue_bwspec;
			hfsc_opts.linkshare.used = 1;
		}
break;
case 147:
#line 1819 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (hfsc_opts.realtime.used) {
				yyerror("realtime already specified");
				YYERROR;
			}
			hfsc_opts.realtime.m2 = yystack.l_mark[0].v.queue_bwspec;
			hfsc_opts.realtime.used = 1;
		}
break;
case 148:
#line 1828 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-3].v.number < 0 || yystack.l_mark[-3].v.number > INT_MAX) {
				yyerror("timing in curve out of range");
				YYERROR;
			}
			if (hfsc_opts.realtime.used) {
				yyerror("realtime already specified");
				YYERROR;
			}
			hfsc_opts.realtime.m1 = yystack.l_mark[-5].v.queue_bwspec;
			hfsc_opts.realtime.d = yystack.l_mark[-3].v.number;
			hfsc_opts.realtime.m2 = yystack.l_mark[-1].v.queue_bwspec;
			hfsc_opts.realtime.used = 1;
		}
break;
case 149:
#line 1842 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (hfsc_opts.upperlimit.used) {
				yyerror("upperlimit already specified");
				YYERROR;
			}
			hfsc_opts.upperlimit.m2 = yystack.l_mark[0].v.queue_bwspec;
			hfsc_opts.upperlimit.used = 1;
		}
break;
case 150:
#line 1851 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-3].v.number < 0 || yystack.l_mark[-3].v.number > INT_MAX) {
				yyerror("timing in curve out of range");
				YYERROR;
			}
			if (hfsc_opts.upperlimit.used) {
				yyerror("upperlimit already specified");
				YYERROR;
			}
			hfsc_opts.upperlimit.m1 = yystack.l_mark[-5].v.queue_bwspec;
			hfsc_opts.upperlimit.d = yystack.l_mark[-3].v.number;
			hfsc_opts.upperlimit.m2 = yystack.l_mark[-1].v.queue_bwspec;
			hfsc_opts.upperlimit.used = 1;
		}
break;
case 151:
#line 1865 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "default"))
				hfsc_opts.flags |= HFCF_DEFAULTCLASS;
			else if (!strcmp(yystack.l_mark[0].v.string, "red"))
				hfsc_opts.flags |= HFCF_RED;
			else if (!strcmp(yystack.l_mark[0].v.string, "ecn"))
				hfsc_opts.flags |= HFCF_RED|HFCF_ECN;
			else if (!strcmp(yystack.l_mark[0].v.string, "rio"))
				hfsc_opts.flags |= HFCF_RIO;
			else if (!strcmp(yystack.l_mark[0].v.string, "codel"))
				hfsc_opts.flags |= HFCF_CODEL;
			else {
				yyerror("unknown hfsc flag \"%s\"", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 152:
#line 1885 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
				bzero(&fairq_opts,
				    sizeof(struct node_fairq_opts));
			}
break;
case 153:
#line 1889 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.fairq_opts = fairq_opts;
		}
break;
case 156:
#line 1898 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (fairq_opts.linkshare.used) {
				yyerror("linkshare already specified");
				YYERROR;
			}
			fairq_opts.linkshare.m2 = yystack.l_mark[0].v.queue_bwspec;
			fairq_opts.linkshare.used = 1;
		}
break;
case 157:
#line 1906 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (fairq_opts.linkshare.used) {
				yyerror("linkshare already specified");
				YYERROR;
			}
			fairq_opts.linkshare.m1 = yystack.l_mark[-3].v.queue_bwspec;
			fairq_opts.linkshare.d = yystack.l_mark[-2].v.number;
			fairq_opts.linkshare.m2 = yystack.l_mark[-1].v.queue_bwspec;
			fairq_opts.linkshare.used = 1;
		}
break;
case 158:
#line 1916 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			fairq_opts.hogs_bw = yystack.l_mark[0].v.queue_bwspec;
		}
break;
case 159:
#line 1919 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			fairq_opts.nbuckets = yystack.l_mark[0].v.number;
		}
break;
case 160:
#line 1922 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "default"))
				fairq_opts.flags |= FARF_DEFAULTCLASS;
			else if (!strcmp(yystack.l_mark[0].v.string, "red"))
				fairq_opts.flags |= FARF_RED;
			else if (!strcmp(yystack.l_mark[0].v.string, "ecn"))
				fairq_opts.flags |= FARF_RED|FARF_ECN;
			else if (!strcmp(yystack.l_mark[0].v.string, "rio"))
				fairq_opts.flags |= FARF_RIO;
			else if (!strcmp(yystack.l_mark[0].v.string, "codel"))
				fairq_opts.flags |= FARF_CODEL;
			else {
				yyerror("unknown fairq flag \"%s\"", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 161:
#line 1942 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
				bzero(&codel_opts,
				    sizeof(struct codel_opts));
			}
break;
case 162:
#line 1946 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.codel_opts = codel_opts;
		}
break;
case 165:
#line 1955 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (codel_opts.interval) {
				yyerror("interval already specified");
				YYERROR;
			}
			codel_opts.interval = yystack.l_mark[0].v.number;
		}
break;
case 166:
#line 1962 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (codel_opts.target) {
				yyerror("target already specified");
				YYERROR;
			}
			codel_opts.target = yystack.l_mark[0].v.number;
		}
break;
case 167:
#line 1969 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "ecn"))
				codel_opts.ecn = 1;
			else {
				yyerror("unknown codel option \"%s\"", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 168:
#line 1981 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.queue = NULL; }
break;
case 169:
#line 1982 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.queue = yystack.l_mark[0].v.queue; }
break;
case 170:
#line 1983 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.queue = yystack.l_mark[-1].v.queue; }
break;
case 171:
#line 1986 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.queue = yystack.l_mark[-1].v.queue; }
break;
case 172:
#line 1987 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.queue->tail->next = yystack.l_mark[-1].v.queue;
			yystack.l_mark[-3].v.queue->tail = yystack.l_mark[-1].v.queue;
			yyval.v.queue = yystack.l_mark[-3].v.queue;
		}
break;
case 173:
#line 1994 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue = calloc(1, sizeof(struct node_queue));
			if (yyval.v.queue == NULL)
				err(1, "qassign_item: calloc");
			if (strlcpy(yyval.v.queue->queue, yystack.l_mark[0].v.string, sizeof(yyval.v.queue->queue)) >=
			    sizeof(yyval.v.queue->queue)) {
				yyerror("queue name '%s' too long (max "
				    "%d chars)", yystack.l_mark[0].v.string, sizeof(yyval.v.queue->queue)-1);
				free(yystack.l_mark[0].v.string);
				free(yyval.v.queue);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
			yyval.v.queue->next = NULL;
			yyval.v.queue->tail = yyval.v.queue;
		}
break;
case 174:
#line 2014 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct pf_rule		 r;
			struct node_state_opt	*o;
			struct node_proto	*proto;
			int			 srctrack = 0;
			int			 statelock = 0;
			int			 adaptive = 0;
			int			 defaults = 0;

			if (check_rulestate(PFCTL_STATE_FILTER))
				YYERROR;

			memset(&r, 0, sizeof(r));

			r.action = yystack.l_mark[-8].v.b.b1;
			switch (yystack.l_mark[-8].v.b.b2) {
			case PFRULE_RETURNRST:
				r.rule_flag |= PFRULE_RETURNRST;
				r.return_ttl = yystack.l_mark[-8].v.b.w;
				break;
			case PFRULE_RETURNICMP:
				r.rule_flag |= PFRULE_RETURNICMP;
				r.return_icmp = yystack.l_mark[-8].v.b.w;
				r.return_icmp6 = yystack.l_mark[-8].v.b.w2;
				break;
			case PFRULE_RETURN:
				r.rule_flag |= PFRULE_RETURN;
				r.return_icmp = yystack.l_mark[-8].v.b.w;
				r.return_icmp6 = yystack.l_mark[-8].v.b.w2;
				break;
			}
			r.direction = yystack.l_mark[-7].v.i;
			r.log = yystack.l_mark[-6].v.logquick.log;
			r.logif = yystack.l_mark[-6].v.logquick.logif;
			r.quick = yystack.l_mark[-6].v.logquick.quick;
			r.prob = yystack.l_mark[0].v.filter_opts.prob;
			r.rtableid = yystack.l_mark[0].v.filter_opts.rtableid;

			if (yystack.l_mark[0].v.filter_opts.marker & FOM_PRIO) {
				if (yystack.l_mark[0].v.filter_opts.prio == 0)
					r.prio = PF_PRIO_ZERO;
				else
					r.prio = yystack.l_mark[0].v.filter_opts.prio;
			}
			if (yystack.l_mark[0].v.filter_opts.marker & FOM_SETPRIO) {
				r.set_prio[0] = yystack.l_mark[0].v.filter_opts.set_prio[0];
				r.set_prio[1] = yystack.l_mark[0].v.filter_opts.set_prio[1];
				r.scrub_flags |= PFSTATE_SETPRIO;
			}

			r.af = yystack.l_mark[-3].v.i;
			if (yystack.l_mark[0].v.filter_opts.tag)
				if (strlcpy(r.tagname, yystack.l_mark[0].v.filter_opts.tag,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			if (yystack.l_mark[0].v.filter_opts.match_tag)
				if (strlcpy(r.match_tagname, yystack.l_mark[0].v.filter_opts.match_tag,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			r.match_tag_not = yystack.l_mark[0].v.filter_opts.match_tag_not;
			if (rule_label(&r, yystack.l_mark[0].v.filter_opts.label))
				YYERROR;
			free(yystack.l_mark[0].v.filter_opts.label);
			if  (rule_schedule(&r, yystack.l_mark[0].v.filter_opts.schedule))
				YYERROR;
			free(yystack.l_mark[0].v.filter_opts.schedule);
			if (yystack.l_mark[0].v.filter_opts.tracker)
				r.cuid = yystack.l_mark[0].v.filter_opts.tracker;
			r.flags = yystack.l_mark[0].v.filter_opts.flags.b1;
			r.flagset = yystack.l_mark[0].v.filter_opts.flags.b2;
			if ((yystack.l_mark[0].v.filter_opts.flags.b1 & yystack.l_mark[0].v.filter_opts.flags.b2) != yystack.l_mark[0].v.filter_opts.flags.b1) {
				yyerror("flags always false");
				YYERROR;
			}
			if (yystack.l_mark[0].v.filter_opts.flags.b1 || yystack.l_mark[0].v.filter_opts.flags.b2 || yystack.l_mark[-1].v.fromto.src_os) {
				for (proto = yystack.l_mark[-2].v.proto; proto != NULL &&
				    proto->proto != IPPROTO_TCP;
				    proto = proto->next)
					;	/* nothing */
				if (proto == NULL && yystack.l_mark[-2].v.proto != NULL) {
					if (yystack.l_mark[0].v.filter_opts.flags.b1 || yystack.l_mark[0].v.filter_opts.flags.b2)
						yyerror(
						    "flags only apply to tcp");
					if (yystack.l_mark[-1].v.fromto.src_os)
						yyerror(
						    "OS fingerprinting only "
						    "apply to tcp");
					YYERROR;
				}
#if 0
				if ((yystack.l_mark[0].v.filter_opts.flags.b1 & parse_flags("S")) == 0 &&
				    yystack.l_mark[-1].v.fromto.src_os) {
					yyerror("OS fingerprinting requires "
					    "the SYN TCP flag (flags S/SA)");
					YYERROR;
				}
#endif
			}

			if (yystack.l_mark[0].v.filter_opts.tos) {
				r.tos = yystack.l_mark[0].v.filter_opts.tos;
				r.rule_flag |= PFRULE_TOS;
			}
			if (yystack.l_mark[0].v.filter_opts.dscp) {
				r.tos = yystack.l_mark[0].v.filter_opts.dscp;
				r.rule_flag |= PFRULE_DSCP;
			}
			r.keep_state = yystack.l_mark[0].v.filter_opts.keep.action;
			o = yystack.l_mark[0].v.filter_opts.keep.options;

			/* 'keep state' by default on pass rules. */
			if (!r.keep_state && !r.action &&
			    !(yystack.l_mark[0].v.filter_opts.marker & FOM_KEEP)) {
				r.keep_state = PF_STATE_NORMAL;
				o = keep_state_defaults;
				defaults = 1;
			}

			while (o) {
				struct node_state_opt	*p = o;

				switch (o->type) {
				case PF_STATE_OPT_MAX:
					if (r.max_states) {
						yyerror("state option 'max' "
						    "multiple definitions");
						YYERROR;
					}
					r.max_states = o->data.max_states;
					break;
				case PF_STATE_OPT_NOSYNC:
					if (r.rule_flag & PFRULE_NOSYNC) {
						yyerror("state option 'sync' "
						    "multiple definitions");
						YYERROR;
					}
					r.rule_flag |= PFRULE_NOSYNC;
					break;
				case PF_STATE_OPT_SRCTRACK:
					if (srctrack) {
						yyerror("state option "
						    "'source-track' "
						    "multiple definitions");
						YYERROR;
					}
					srctrack =  o->data.src_track;
					r.rule_flag |= PFRULE_SRCTRACK;
					break;
				case PF_STATE_OPT_MAX_SRC_STATES:
					if (r.max_src_states) {
						yyerror("state option "
						    "'max-src-states' "
						    "multiple definitions");
						YYERROR;
					}
					if (o->data.max_src_states == 0) {
						yyerror("'max-src-states' must "
						    "be > 0");
						YYERROR;
					}
					r.max_src_states =
					    o->data.max_src_states;
					r.rule_flag |= PFRULE_SRCTRACK;
					break;
				case PF_STATE_OPT_OVERLOAD:
					if (r.overload_tblname[0]) {
						yyerror("multiple 'overload' "
						    "table definitions");
						YYERROR;
					}
					if (strlcpy(r.overload_tblname,
					    o->data.overload.tblname,
					    PF_TABLE_NAME_SIZE) >=
					    PF_TABLE_NAME_SIZE) {
						yyerror("state option: "
						    "strlcpy");
						YYERROR;
					}
					r.flush = o->data.overload.flush;
					break;
				case PF_STATE_OPT_MAX_SRC_CONN:
					if (r.max_src_conn) {
						yyerror("state option "
						    "'max-src-conn' "
						    "multiple definitions");
						YYERROR;
					}
					if (o->data.max_src_conn == 0) {
						yyerror("'max-src-conn' "
						    "must be > 0");
						YYERROR;
					}
					r.max_src_conn =
					    o->data.max_src_conn;
					r.rule_flag |= PFRULE_SRCTRACK |
					    PFRULE_RULESRCTRACK;
					break;
				case PF_STATE_OPT_MAX_SRC_CONN_RATE:
					if (r.max_src_conn_rate.limit) {
						yyerror("state option "
						    "'max-src-conn-rate' "
						    "multiple definitions");
						YYERROR;
					}
					if (!o->data.max_src_conn_rate.limit ||
					    !o->data.max_src_conn_rate.seconds) {
						yyerror("'max-src-conn-rate' "
						    "values must be > 0");
						YYERROR;
					}
					if (o->data.max_src_conn_rate.limit >
					    PF_THRESHOLD_MAX) {
						yyerror("'max-src-conn-rate' "
						    "maximum rate must be < %u",
						    PF_THRESHOLD_MAX);
						YYERROR;
					}
					r.max_src_conn_rate.limit =
					    o->data.max_src_conn_rate.limit;
					r.max_src_conn_rate.seconds =
					    o->data.max_src_conn_rate.seconds;
					r.rule_flag |= PFRULE_SRCTRACK |
					    PFRULE_RULESRCTRACK;
					break;
				case PF_STATE_OPT_MAX_SRC_NODES:
					if (r.max_src_nodes) {
						yyerror("state option "
						    "'max-src-nodes' "
						    "multiple definitions");
						YYERROR;
					}
					if (o->data.max_src_nodes == 0) {
						yyerror("'max-src-nodes' must "
						    "be > 0");
						YYERROR;
					}
					r.max_src_nodes =
					    o->data.max_src_nodes;
					r.rule_flag |= PFRULE_SRCTRACK |
					    PFRULE_RULESRCTRACK;
					break;
				case PF_STATE_OPT_STATELOCK:
					if (statelock) {
						yyerror("state locking option: "
						    "multiple definitions");
						YYERROR;
					}
					statelock = 1;
					r.rule_flag |= o->data.statelock;
					break;
				case PF_STATE_OPT_SLOPPY:
					if (r.rule_flag & PFRULE_STATESLOPPY) {
						yyerror("state sloppy option: "
						    "multiple definitions");
						YYERROR;
					}
					r.rule_flag |= PFRULE_STATESLOPPY;
					break;
				case PF_STATE_OPT_TIMEOUT:
					if (o->data.timeout.number ==
					    PFTM_ADAPTIVE_START ||
					    o->data.timeout.number ==
					    PFTM_ADAPTIVE_END)
						adaptive = 1;
					if (r.timeout[o->data.timeout.number]) {
						yyerror("state timeout %s "
						    "multiple definitions",
						    pf_timeouts[o->data.
						    timeout.number].name);
						YYERROR;
					}
					r.timeout[o->data.timeout.number] =
					    o->data.timeout.seconds;
				}
				o = o->next;
				if (!defaults)
					free(p);
			}

			/* 'flags S/SA' by default on stateful rules */
			if (!r.action && !r.flags && !r.flagset &&
			    !yystack.l_mark[0].v.filter_opts.fragment && !(yystack.l_mark[0].v.filter_opts.marker & FOM_FLAGS) &&
			    r.keep_state) {
				r.flags = parse_flags("S");
				r.flagset =  parse_flags("SA");
			}
			if (!adaptive && r.max_states) {
				r.timeout[PFTM_ADAPTIVE_START] =
				    (r.max_states / 10) * 6;
				r.timeout[PFTM_ADAPTIVE_END] =
				    (r.max_states / 10) * 12;
			}
			if (r.rule_flag & PFRULE_SRCTRACK) {
				if (srctrack == PF_SRCTRACK_GLOBAL &&
				    r.max_src_nodes) {
					yyerror("'max-src-nodes' is "
					    "incompatible with "
					    "'source-track global'");
					YYERROR;
				}
				if (srctrack == PF_SRCTRACK_GLOBAL &&
				    r.max_src_conn) {
					yyerror("'max-src-conn' is "
					    "incompatible with "
					    "'source-track global'");
					YYERROR;
				}
				if (srctrack == PF_SRCTRACK_GLOBAL &&
				    r.max_src_conn_rate.seconds) {
					yyerror("'max-src-conn-rate' is "
					    "incompatible with "
					    "'source-track global'");
					YYERROR;
				}
				if (r.timeout[PFTM_SRC_NODE] <
				    r.max_src_conn_rate.seconds)
					r.timeout[PFTM_SRC_NODE] =
					    r.max_src_conn_rate.seconds;
				r.rule_flag |= PFRULE_SRCTRACK;
				if (srctrack == PF_SRCTRACK_RULE)
					r.rule_flag |= PFRULE_RULESRCTRACK;
			}
			if (r.keep_state && !statelock)
				r.rule_flag |= default_statelock;

			if (yystack.l_mark[0].v.filter_opts.fragment)
				r.rule_flag |= PFRULE_FRAGMENT;
			r.allow_opts = yystack.l_mark[0].v.filter_opts.allowopts;

			decide_address_family(yystack.l_mark[-1].v.fromto.src.host, &r.af);
			decide_address_family(yystack.l_mark[-1].v.fromto.dst.host, &r.af);

			if (yystack.l_mark[-4].v.route.rt) {
				if (!r.direction) {
					yyerror("direction must be explicit "
					    "with rules that specify routing");
					YYERROR;
				}
				r.rt = yystack.l_mark[-4].v.route.rt;
				r.rpool.opts = yystack.l_mark[-4].v.route.pool_opts;
				if (yystack.l_mark[-4].v.route.key != NULL)
					memcpy(&r.rpool.key, yystack.l_mark[-4].v.route.key,
					    sizeof(struct pf_poolhashkey));
			}
			if (r.rt && r.rt != PF_FASTROUTE) {
				decide_address_family(yystack.l_mark[-4].v.route.host, &r.af);
				remove_invalid_hosts(&yystack.l_mark[-4].v.route.host, &r.af);
				if (yystack.l_mark[-4].v.route.host == NULL) {
					yyerror("no routing address with "
					    "matching address family found.");
					YYERROR;
				}
				if ((r.rpool.opts & PF_POOL_TYPEMASK) ==
				    PF_POOL_NONE && (yystack.l_mark[-4].v.route.host->next != NULL ||
				    yystack.l_mark[-4].v.route.host->addr.type == PF_ADDR_TABLE ||
				    DYNIF_MULTIADDR(yystack.l_mark[-4].v.route.host->addr)))
					r.rpool.opts |= PF_POOL_ROUNDROBIN;
				if ((r.rpool.opts & PF_POOL_TYPEMASK) !=
				    PF_POOL_ROUNDROBIN &&
				    disallow_table(yystack.l_mark[-4].v.route.host, "tables are only "
				    "supported in round-robin routing pools"))
					YYERROR;
				if ((r.rpool.opts & PF_POOL_TYPEMASK) !=
				    PF_POOL_ROUNDROBIN &&
				    disallow_alias(yystack.l_mark[-4].v.route.host, "interface (%s) "
				    "is only supported in round-robin "
				    "routing pools"))
					YYERROR;
				if (yystack.l_mark[-4].v.route.host->next != NULL) {
					if ((r.rpool.opts & PF_POOL_TYPEMASK) !=
					    PF_POOL_ROUNDROBIN) {
						yyerror("r.rpool.opts must "
						    "be PF_POOL_ROUNDROBIN");
						YYERROR;
					}
				}
			}
			if (yystack.l_mark[0].v.filter_opts.queues.qname != NULL) {
				if (strlcpy(r.qname, yystack.l_mark[0].v.filter_opts.queues.qname,
				    sizeof(r.qname)) >= sizeof(r.qname)) {
					yyerror("rule qname too long (max "
					    "%d chars)", sizeof(r.qname)-1);
					YYERROR;
				}
				free(yystack.l_mark[0].v.filter_opts.queues.qname);
			}
			if (yystack.l_mark[0].v.filter_opts.queues.pqname != NULL) {
				if (strlcpy(r.pqname, yystack.l_mark[0].v.filter_opts.queues.pqname,
				    sizeof(r.pqname)) >= sizeof(r.pqname)) {
					yyerror("rule pqname too long (max "
					    "%d chars)", sizeof(r.pqname)-1);
					YYERROR;
				}
				free(yystack.l_mark[0].v.filter_opts.queues.pqname);
			}
#ifdef __FreeBSD__
			r.divert.port = yystack.l_mark[0].v.filter_opts.divert.port;
#else
			if ((r.divert.port = yystack.l_mark[0].v.filter_opts.divert.port)) {
				if (r.direction == PF_OUT) {
					if (yystack.l_mark[0].v.filter_opts.divert.addr) {
						yyerror("address specified "
						    "for outgoing divert");
						YYERROR;
					}
					bzero(&r.divert.addr,
					    sizeof(r.divert.addr));
				} else {
					if (!yystack.l_mark[0].v.filter_opts.divert.addr) {
						yyerror("no address specified "
						    "for incoming divert");
						YYERROR;
					}
					if (yystack.l_mark[0].v.filter_opts.divert.addr->af != r.af) {
						yyerror("address family "
						    "mismatch for divert");
						YYERROR;
					}
					r.divert.addr =
					    yystack.l_mark[0].v.filter_opts.divert.addr->addr.v.a.addr;
				}
			}
#endif

			if (yystack.l_mark[0].v.filter_opts.dnpipe) {
				r.dnpipe = yystack.l_mark[0].v.filter_opts.dnpipe;
				if (yystack.l_mark[0].v.filter_opts.free_flags & PFRULE_DN_IS_PIPE)
					r.free_flags |= PFRULE_DN_IS_PIPE;
				else
					r.free_flags |= PFRULE_DN_IS_QUEUE;
				r.pdnpipe = yystack.l_mark[0].v.filter_opts.pdnpipe;
			}

			expand_rule(&r, yystack.l_mark[-5].v.interface, yystack.l_mark[-4].v.route.host, yystack.l_mark[-2].v.proto, yystack.l_mark[-1].v.fromto.src_os,
			    yystack.l_mark[-1].v.fromto.src.host, yystack.l_mark[-1].v.fromto.src.port, yystack.l_mark[-1].v.fromto.dst.host, yystack.l_mark[-1].v.fromto.dst.port,
			    yystack.l_mark[0].v.filter_opts.uid, yystack.l_mark[0].v.filter_opts.gid, yystack.l_mark[0].v.filter_opts.icmpspec, "");
		}
break;
case 175:
#line 2459 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
				bzero(&filter_opts, sizeof filter_opts);
				filter_opts.rtableid = -1;
			}
break;
case 176:
#line 2464 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.filter_opts = filter_opts; }
break;
case 177:
#line 2465 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			bzero(&filter_opts, sizeof filter_opts);
			filter_opts.rtableid = -1;
			yyval.v.filter_opts = filter_opts;
		}
break;
case 180:
#line 2476 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.uid)
				yystack.l_mark[0].v.uid->tail->next = filter_opts.uid;
			filter_opts.uid = yystack.l_mark[0].v.uid;
		}
break;
case 181:
#line 2481 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.gid)
				yystack.l_mark[0].v.gid->tail->next = filter_opts.gid;
			filter_opts.gid = yystack.l_mark[0].v.gid;
		}
break;
case 182:
#line 2486 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.marker & FOM_FLAGS) {
				yyerror("flags cannot be redefined");
				YYERROR;
			}
			filter_opts.marker |= FOM_FLAGS;
			filter_opts.flags.b1 |= yystack.l_mark[0].v.b.b1;
			filter_opts.flags.b2 |= yystack.l_mark[0].v.b.b2;
			filter_opts.flags.w |= yystack.l_mark[0].v.b.w;
			filter_opts.flags.w2 |= yystack.l_mark[0].v.b.w2;
		}
break;
case 183:
#line 2497 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.marker & FOM_ICMP) {
				yyerror("icmp-type cannot be redefined");
				YYERROR;
			}
			filter_opts.marker |= FOM_ICMP;
			filter_opts.icmpspec = yystack.l_mark[0].v.icmp;
		}
break;
case 184:
#line 2505 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.marker & FOM_PRIO) {
				yyerror("prio cannot be redefined");
				YYERROR;
			}
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > PF_PRIO_MAX) {
				yyerror("prio must be 0 - %u", PF_PRIO_MAX);
				YYERROR;
			}
			filter_opts.marker |= FOM_PRIO;
			filter_opts.prio = yystack.l_mark[0].v.number;
		}
break;
case 185:
#line 2517 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.marker & FOM_TOS) {
				yyerror("tos cannot be redefined");
				YYERROR;
			}
			filter_opts.marker |= FOM_TOS;
			filter_opts.tos = yystack.l_mark[0].v.number;
		}
break;
case 186:
#line 2525 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.marker & FOM_DSCP) {
				yyerror("dscp cannot be redefined");
				YYERROR;
			}
			filter_opts.marker |= FOM_DSCP;
			filter_opts.dscp = yystack.l_mark[0].v.number;
		}
break;
case 187:
#line 2533 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.marker & FOM_KEEP) {
				yyerror("modulate or keep cannot be redefined");
				YYERROR;
			}
			filter_opts.marker |= FOM_KEEP;
			filter_opts.keep.action = yystack.l_mark[0].v.keep_state.action;
			filter_opts.keep.options = yystack.l_mark[0].v.keep_state.options;
		}
break;
case 188:
#line 2542 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			filter_opts.tracker = yystack.l_mark[0].v.number;
		}
break;
case 189:
#line 2545 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			filter_opts.fragment = 1;
		}
break;
case 190:
#line 2548 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			filter_opts.allowopts = 1;
		}
break;
case 191:
#line 2551 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.label) {
				yyerror("label cannot be redefined");
				YYERROR;
			}
			filter_opts.label = yystack.l_mark[0].v.string;
		}
break;
case 192:
#line 2558 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.schedule) {
				yyerror("schedule label cannot be redefined");
				YYERROR;
			}
			filter_opts.schedule = yystack.l_mark[0].v.string;
		}
break;
case 193:
#line 2565 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.queues.qname) {
				yyerror("queue cannot be redefined");
				YYERROR;
			}
			filter_opts.queues = yystack.l_mark[0].v.qassign;
		}
break;
case 194:
#line 2572 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			filter_opts.dnpipe = yystack.l_mark[0].v.number;
			filter_opts.free_flags |= PFRULE_DN_IS_PIPE;
		}
break;
case 195:
#line 2576 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			filter_opts.dnpipe = yystack.l_mark[-1].v.number;
			filter_opts.free_flags |= PFRULE_DN_IS_PIPE;
		}
break;
case 196:
#line 2580 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			filter_opts.pdnpipe = yystack.l_mark[-1].v.number;
			filter_opts.dnpipe = yystack.l_mark[-3].v.number;
			filter_opts.free_flags |= PFRULE_DN_IS_PIPE;
		}
break;
case 197:
#line 2585 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			filter_opts.dnpipe = yystack.l_mark[0].v.number;
			filter_opts.free_flags |= PFRULE_DN_IS_QUEUE;
		}
break;
case 198:
#line 2589 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			filter_opts.pdnpipe = yystack.l_mark[-1].v.number;
			filter_opts.dnpipe = yystack.l_mark[-3].v.number;
			filter_opts.free_flags |= PFRULE_DN_IS_QUEUE;
		}
break;
case 199:
#line 2594 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			filter_opts.dnpipe = yystack.l_mark[-1].v.number;
			filter_opts.free_flags |= PFRULE_DN_IS_QUEUE;
		}
break;
case 200:
#line 2598 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			filter_opts.tag = yystack.l_mark[0].v.string;
		}
break;
case 201:
#line 2601 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			filter_opts.match_tag = yystack.l_mark[0].v.string;
			filter_opts.match_tag_not = yystack.l_mark[-2].v.number;
		}
break;
case 202:
#line 2605 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			double	p;

			p = floor(yystack.l_mark[0].v.probability * UINT_MAX + 0.5);
			if (p < 0.0 || p > UINT_MAX) {
				yyerror("invalid probability: %lf", p);
				YYERROR;
			}
			filter_opts.prob = (u_int32_t)p;
			if (filter_opts.prob == 0)
				filter_opts.prob = 1;
		}
break;
case 203:
#line 2617 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > rt_tableid_max()) {
				yyerror("invalid rtable id");
				YYERROR;
			}
			filter_opts.rtableid = yystack.l_mark[0].v.number;
		}
break;
case 204:
#line 2624 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
#ifdef __FreeBSD__
			filter_opts.divert.port = yystack.l_mark[0].v.range.a;
			if (!filter_opts.divert.port) {
				yyerror("invalid divert port: %u", ntohs(yystack.l_mark[0].v.range.a));
				YYERROR;
			}
#endif
		}
break;
case 205:
#line 2633 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
#ifndef __FreeBSD__
			if ((filter_opts.divert.addr = host(yystack.l_mark[-2].v.string)) == NULL) {
				yyerror("could not parse divert address: %s",
				    yystack.l_mark[-2].v.string);
				free(yystack.l_mark[-2].v.string);
				YYERROR;
			}
#else
			if (yystack.l_mark[-2].v.string)
#endif
			free(yystack.l_mark[-2].v.string);
			filter_opts.divert.port = yystack.l_mark[0].v.range.a;
			if (!filter_opts.divert.port) {
				yyerror("invalid divert port: %u", ntohs(yystack.l_mark[0].v.range.a));
				YYERROR;
			}
		}
break;
case 206:
#line 2651 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
#ifdef __FreeBSD__
			yyerror("divert-reply has no meaning in FreeBSD pf(4)");
			YYERROR;
#else
			filter_opts.divert.port = 1;	/* some random value */
#endif
		}
break;
case 208:
#line 2662 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.filter_opts = filter_opts; }
break;
case 209:
#line 2663 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.filter_opts = filter_opts; }
break;
case 212:
#line 2670 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.marker & FOM_SETPRIO) {
				yyerror("prio cannot be redefined");
				YYERROR;
			}
			filter_opts.marker |= FOM_SETPRIO;
			filter_opts.set_prio[0] = yystack.l_mark[0].v.b.b1;
			filter_opts.set_prio[1] = yystack.l_mark[0].v.b.b2;
		}
break;
case 213:
#line 2679 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > PF_PRIO_MAX) {
				yyerror("prio must be 0 - %u", PF_PRIO_MAX);
				YYERROR;
			}
			yyval.v.b.b1 = yyval.v.b.b2 = yystack.l_mark[0].v.number;
		}
break;
case 214:
#line 2686 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-3].v.number < 0 || yystack.l_mark[-3].v.number > PF_PRIO_MAX ||
			    yystack.l_mark[-1].v.number < 0 || yystack.l_mark[-1].v.number > PF_PRIO_MAX) {
				yyerror("prio must be 0 - %u", PF_PRIO_MAX);
				YYERROR;
			}
			yyval.v.b.b1 = yystack.l_mark[-3].v.number;
			yyval.v.b.b2 = yystack.l_mark[-1].v.number;
		}
break;
case 215:
#line 2697 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			char	*e;
			double	 p = strtod(yystack.l_mark[0].v.string, &e);

			if (*e == '%') {
				p *= 0.01;
				e++;
			}
			if (*e) {
				yyerror("invalid probability: %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
			yyval.v.probability = p;
		}
break;
case 216:
#line 2713 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.probability = (double)yystack.l_mark[0].v.number;
		}
break;
case 217:
#line 2719 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = PF_PASS; yyval.v.b.b2 = yyval.v.b.w = 0; }
break;
case 218:
#line 2720 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = PF_MATCH; yyval.v.b.b2 = yyval.v.b.w = 0; }
break;
case 219:
#line 2721 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.b = yystack.l_mark[0].v.b; yyval.v.b.b1 = PF_DROP; }
break;
case 220:
#line 2724 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = blockpolicy;
			yyval.v.b.w = returnicmpdefault;
			yyval.v.b.w2 = returnicmp6default;
		}
break;
case 221:
#line 2729 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_DROP;
			yyval.v.b.w = 0;
			yyval.v.b.w2 = 0;
		}
break;
case 222:
#line 2734 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_RETURNRST;
			yyval.v.b.w = 0;
			yyval.v.b.w2 = 0;
		}
break;
case 223:
#line 2739 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-1].v.number < 0 || yystack.l_mark[-1].v.number > 255) {
				yyerror("illegal ttl value %d", yystack.l_mark[-1].v.number);
				YYERROR;
			}
			yyval.v.b.b2 = PFRULE_RETURNRST;
			yyval.v.b.w = yystack.l_mark[-1].v.number;
			yyval.v.b.w2 = 0;
		}
break;
case 224:
#line 2748 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_RETURNICMP;
			yyval.v.b.w = returnicmpdefault;
			yyval.v.b.w2 = returnicmp6default;
		}
break;
case 225:
#line 2753 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_RETURNICMP;
			yyval.v.b.w = returnicmpdefault;
			yyval.v.b.w2 = returnicmp6default;
		}
break;
case 226:
#line 2758 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_RETURNICMP;
			yyval.v.b.w = yystack.l_mark[-1].v.number;
			yyval.v.b.w2 = returnicmpdefault;
		}
break;
case 227:
#line 2763 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_RETURNICMP;
			yyval.v.b.w = returnicmpdefault;
			yyval.v.b.w2 = yystack.l_mark[-1].v.number;
		}
break;
case 228:
#line 2768 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_RETURNICMP;
			yyval.v.b.w = yystack.l_mark[-3].v.number;
			yyval.v.b.w2 = yystack.l_mark[-1].v.number;
		}
break;
case 229:
#line 2773 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_RETURN;
			yyval.v.b.w = returnicmpdefault;
			yyval.v.b.w2 = returnicmp6default;
		}
break;
case 230:
#line 2780 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (!(yyval.v.number = parseicmpspec(yystack.l_mark[0].v.string, AF_INET))) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 231:
#line 2787 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			u_int8_t		icmptype;

			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("invalid icmp code %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			icmptype = returnicmpdefault >> 8;
			yyval.v.number = (icmptype << 8 | yystack.l_mark[0].v.number);
		}
break;
case 232:
#line 2799 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (!(yyval.v.number = parseicmpspec(yystack.l_mark[0].v.string, AF_INET6))) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 233:
#line 2806 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			u_int8_t		icmptype;

			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("invalid icmp code %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			icmptype = returnicmp6default >> 8;
			yyval.v.number = (icmptype << 8 | yystack.l_mark[0].v.number);
		}
break;
case 234:
#line 2818 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_INOUT; }
break;
case 235:
#line 2819 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_IN; }
break;
case 236:
#line 2820 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_OUT; }
break;
case 237:
#line 2823 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.quick = 0; }
break;
case 238:
#line 2824 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.quick = 1; }
break;
case 239:
#line 2827 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.log = 0; yyval.v.logquick.quick = 0; yyval.v.logquick.logif = 0; }
break;
case 240:
#line 2828 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick = yystack.l_mark[0].v.logquick; yyval.v.logquick.quick = 0; }
break;
case 241:
#line 2829 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.quick = 1; yyval.v.logquick.log = 0; yyval.v.logquick.logif = 0; }
break;
case 242:
#line 2830 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick = yystack.l_mark[-1].v.logquick; yyval.v.logquick.quick = 1; }
break;
case 243:
#line 2831 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick = yystack.l_mark[0].v.logquick; yyval.v.logquick.quick = 1; }
break;
case 244:
#line 2834 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.log = PF_LOG; yyval.v.logquick.logif = 0; }
break;
case 245:
#line 2835 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.logquick.log = PF_LOG | yystack.l_mark[-1].v.logquick.log;
			yyval.v.logquick.logif = yystack.l_mark[-1].v.logquick.logif;
		}
break;
case 246:
#line 2841 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick = yystack.l_mark[0].v.logquick; }
break;
case 247:
#line 2842 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.logquick.log = yystack.l_mark[-2].v.logquick.log | yystack.l_mark[0].v.logquick.log;
			yyval.v.logquick.logif = yystack.l_mark[0].v.logquick.logif;
			if (yyval.v.logquick.logif == 0)
				yyval.v.logquick.logif = yystack.l_mark[-2].v.logquick.logif;
		}
break;
case 248:
#line 2850 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.log = PF_LOG_ALL; yyval.v.logquick.logif = 0; }
break;
case 249:
#line 2851 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.log = PF_LOG_SOCKET_LOOKUP; yyval.v.logquick.logif = 0; }
break;
case 250:
#line 2852 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.log = PF_LOG_SOCKET_LOOKUP; yyval.v.logquick.logif = 0; }
break;
case 251:
#line 2853 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			const char	*errstr;
			u_int		 i;

			yyval.v.logquick.log = 0;
			if (strncmp(yystack.l_mark[0].v.string, "pflog", 5)) {
				yyerror("%s: should be a pflog interface", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			i = strtonum(yystack.l_mark[0].v.string + 5, 0, 255, &errstr);
			if (errstr) {
				yyerror("%s: %s", yystack.l_mark[0].v.string, errstr);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
			yyval.v.logquick.logif = i;
		}
break;
case 252:
#line 2874 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = NULL; }
break;
case 253:
#line 2875 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[0].v.interface; }
break;
case 254:
#line 2876 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[-1].v.interface; }
break;
case 255:
#line 2879 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[-1].v.interface; }
break;
case 256:
#line 2880 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.interface->tail->next = yystack.l_mark[-1].v.interface;
			yystack.l_mark[-3].v.interface->tail = yystack.l_mark[-1].v.interface;
			yyval.v.interface = yystack.l_mark[-3].v.interface;
		}
break;
case 257:
#line 2887 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[0].v.interface; yyval.v.interface->not = yystack.l_mark[-1].v.number; }
break;
case 258:
#line 2890 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct node_host	*n;

			yyval.v.interface = calloc(1, sizeof(struct node_if));
			if (yyval.v.interface == NULL)
				err(1, "if_item: calloc");
			if (strlcpy(yyval.v.interface->ifname, yystack.l_mark[0].v.string, sizeof(yyval.v.interface->ifname)) >=
			    sizeof(yyval.v.interface->ifname)) {
				free(yystack.l_mark[0].v.string);
				free(yyval.v.interface);
				yyerror("interface name too long");
				YYERROR;
			}

			if ((n = ifa_exists(yystack.l_mark[0].v.string)) != NULL)
				yyval.v.interface->ifa_flags = n->ifa_flags;

			free(yystack.l_mark[0].v.string);
			yyval.v.interface->not = 0;
			yyval.v.interface->next = NULL;
			yyval.v.interface->tail = yyval.v.interface;
		}
break;
case 259:
#line 2914 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = 0; }
break;
case 260:
#line 2915 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = AF_INET; }
break;
case 261:
#line 2916 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = AF_INET6; }
break;
case 262:
#line 2919 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.proto = NULL; }
break;
case 263:
#line 2920 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.proto = yystack.l_mark[0].v.proto; }
break;
case 264:
#line 2921 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.proto = yystack.l_mark[-1].v.proto; }
break;
case 265:
#line 2924 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.proto = yystack.l_mark[-1].v.proto; }
break;
case 266:
#line 2925 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.proto->tail->next = yystack.l_mark[-1].v.proto;
			yystack.l_mark[-3].v.proto->tail = yystack.l_mark[-1].v.proto;
			yyval.v.proto = yystack.l_mark[-3].v.proto;
		}
break;
case 267:
#line 2932 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			u_int8_t	pr;

			pr = (u_int8_t)yystack.l_mark[0].v.number;
			if (pr == 0) {
				yyerror("proto 0 cannot be used");
				YYERROR;
			}
			yyval.v.proto = calloc(1, sizeof(struct node_proto));
			if (yyval.v.proto == NULL)
				err(1, "proto_item: calloc");
			yyval.v.proto->proto = pr;
			yyval.v.proto->next = NULL;
			yyval.v.proto->tail = yyval.v.proto;
		}
break;
case 268:
#line 2949 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct protoent	*p;

			p = getprotobyname(yystack.l_mark[0].v.string);
			if (p == NULL) {
				yyerror("unknown protocol %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			yyval.v.number = p->p_proto;
			free(yystack.l_mark[0].v.string);
		}
break;
case 269:
#line 2961 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("protocol outside range");
				YYERROR;
			}
		}
break;
case 270:
#line 2969 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.fromto.src.host = NULL;
			yyval.v.fromto.src.port = NULL;
			yyval.v.fromto.dst.host = NULL;
			yyval.v.fromto.dst.port = NULL;
			yyval.v.fromto.src_os = NULL;
		}
break;
case 271:
#line 2976 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.fromto.src = yystack.l_mark[-2].v.peer;
			yyval.v.fromto.src_os = yystack.l_mark[-1].v.os;
			yyval.v.fromto.dst = yystack.l_mark[0].v.peer;
		}
break;
case 272:
#line 2983 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.os = NULL; }
break;
case 273:
#line 2984 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.os = yystack.l_mark[0].v.os; }
break;
case 274:
#line 2985 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.os = yystack.l_mark[-1].v.os; }
break;
case 275:
#line 2988 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.os = calloc(1, sizeof(struct node_os));
			if (yyval.v.os == NULL)
				err(1, "os: calloc");
			yyval.v.os->os = yystack.l_mark[0].v.string;
			yyval.v.os->tail = yyval.v.os;
		}
break;
case 276:
#line 2997 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.os = yystack.l_mark[-1].v.os; }
break;
case 277:
#line 2998 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.os->tail->next = yystack.l_mark[-1].v.os;
			yystack.l_mark[-3].v.os->tail = yystack.l_mark[-1].v.os;
			yyval.v.os = yystack.l_mark[-3].v.os;
		}
break;
case 278:
#line 3005 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.peer.host = NULL;
			yyval.v.peer.port = NULL;
		}
break;
case 279:
#line 3009 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.peer = yystack.l_mark[0].v.peer;
		}
break;
case 280:
#line 3014 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.peer.host = NULL;
			yyval.v.peer.port = NULL;
		}
break;
case 281:
#line 3018 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (disallow_urpf_failed(yystack.l_mark[0].v.peer.host, "\"urpf-failed\" is "
			    "not permitted in a destination address"))
				YYERROR;
			yyval.v.peer = yystack.l_mark[0].v.peer;
		}
break;
case 282:
#line 3026 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.peer.host = yystack.l_mark[0].v.host;
			yyval.v.peer.port = NULL;
		}
break;
case 283:
#line 3030 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.peer.host = yystack.l_mark[-2].v.host;
			yyval.v.peer.port = yystack.l_mark[0].v.port;
		}
break;
case 284:
#line 3034 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.peer.host = NULL;
			yyval.v.peer.port = yystack.l_mark[0].v.port;
		}
break;
case 287:
#line 3044 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.host = NULL; }
break;
case 288:
#line 3045 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[0].v.host; }
break;
case 289:
#line 3046 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[-1].v.host; }
break;
case 290:
#line 3049 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[0].v.host; }
break;
case 291:
#line 3050 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.host = NULL; }
break;
case 292:
#line 3053 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[-1].v.host; }
break;
case 293:
#line 3054 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-1].v.host == NULL)
				yyval.v.host = yystack.l_mark[-3].v.host;
			else if (yystack.l_mark[-3].v.host == NULL)
				yyval.v.host = yystack.l_mark[-1].v.host;
			else {
				yystack.l_mark[-3].v.host->tail->next = yystack.l_mark[-1].v.host;
				yystack.l_mark[-3].v.host->tail = yystack.l_mark[-1].v.host->tail;
				yyval.v.host = yystack.l_mark[-3].v.host;
			}
		}
break;
case 294:
#line 3067 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct node_host	*n;

			for (n = yystack.l_mark[0].v.host; n != NULL; n = n->next)
				n->not = yystack.l_mark[-1].v.number;
			yyval.v.host = yystack.l_mark[0].v.host;
		}
break;
case 295:
#line 3074 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.host = calloc(1, sizeof(struct node_host));
			if (yyval.v.host == NULL)
				err(1, "xhost: calloc");
			yyval.v.host->addr.type = PF_ADDR_NOROUTE;
			yyval.v.host->next = NULL;
			yyval.v.host->not = yystack.l_mark[-1].v.number;
			yyval.v.host->tail = yyval.v.host;
		}
break;
case 296:
#line 3083 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.host = calloc(1, sizeof(struct node_host));
			if (yyval.v.host == NULL)
				err(1, "xhost: calloc");
			yyval.v.host->addr.type = PF_ADDR_URPFFAILED;
			yyval.v.host->next = NULL;
			yyval.v.host->not = yystack.l_mark[-1].v.number;
			yyval.v.host->tail = yyval.v.host;
		}
break;
case 297:
#line 3094 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if ((yyval.v.host = host(yystack.l_mark[0].v.string)) == NULL)	{
				/* error. "any" is handled elsewhere */
				free(yystack.l_mark[0].v.string);
				yyerror("could not parse host specification");
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);

		}
break;
case 298:
#line 3104 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct node_host *b, *e;

			if ((b = host(yystack.l_mark[-2].v.string)) == NULL || (e = host(yystack.l_mark[0].v.string)) == NULL) {
				free(yystack.l_mark[-2].v.string);
				free(yystack.l_mark[0].v.string);
				yyerror("could not parse host specification");
				YYERROR;
			}
			if (b->af != e->af ||
			    b->addr.type != PF_ADDR_ADDRMASK ||
			    e->addr.type != PF_ADDR_ADDRMASK ||
			    unmask(&b->addr.v.a.mask, b->af) !=
			    (b->af == AF_INET ? 32 : 128) ||
			    unmask(&e->addr.v.a.mask, e->af) !=
			    (e->af == AF_INET ? 32 : 128) ||
			    b->next != NULL || b->not ||
			    e->next != NULL || e->not) {
				free(b);
				free(e);
				free(yystack.l_mark[-2].v.string);
				free(yystack.l_mark[0].v.string);
				yyerror("invalid address range");
				YYERROR;
			}
			memcpy(&b->addr.v.a.mask, &e->addr.v.a.addr,
			    sizeof(b->addr.v.a.mask));
			b->addr.type = PF_ADDR_RANGE;
			yyval.v.host = b;
			free(e);
			free(yystack.l_mark[-2].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 299:
#line 3137 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			char	*buf;

			if (asprintf(&buf, "%s/%lld", yystack.l_mark[-2].v.string, (long long)yystack.l_mark[0].v.number) == -1)
				err(1, "host: asprintf");
			free(yystack.l_mark[-2].v.string);
			if ((yyval.v.host = host(buf)) == NULL)	{
				/* error. "any" is handled elsewhere */
				free(buf);
				yyerror("could not parse host specification");
				YYERROR;
			}
			free(buf);
		}
break;
case 300:
#line 3151 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			char	*buf;

			/* ie. for 10/8 parsing */
#ifdef __FreeBSD__
			if (asprintf(&buf, "%lld/%lld", (long long)yystack.l_mark[-2].v.number, (long long)yystack.l_mark[0].v.number) == -1)
#else
			if (asprintf(&buf, "%lld/%lld", yystack.l_mark[-2].v.number, yystack.l_mark[0].v.number) == -1)
#endif
				err(1, "host: asprintf");
			if ((yyval.v.host = host(buf)) == NULL)	{
				/* error. "any" is handled elsewhere */
				free(buf);
				yyerror("could not parse host specification");
				YYERROR;
			}
			free(buf);
		}
break;
case 302:
#line 3170 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct node_host	*n;

			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 128) {
				yyerror("bit number too big");
				YYERROR;
			}
			yyval.v.host = yystack.l_mark[-2].v.host;
			for (n = yystack.l_mark[-2].v.host; n != NULL; n = n->next)
				set_ipmask(n, yystack.l_mark[0].v.number);
		}
break;
case 303:
#line 3181 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (strlen(yystack.l_mark[-1].v.string) >= PF_TABLE_NAME_SIZE) {
				yyerror("table name '%s' too long", yystack.l_mark[-1].v.string);
				free(yystack.l_mark[-1].v.string);
				YYERROR;
			}
			yyval.v.host = calloc(1, sizeof(struct node_host));
			if (yyval.v.host == NULL)
				err(1, "host: calloc");
			yyval.v.host->addr.type = PF_ADDR_TABLE;
			if (strlcpy(yyval.v.host->addr.v.tblname, yystack.l_mark[-1].v.string,
			    sizeof(yyval.v.host->addr.v.tblname)) >=
			    sizeof(yyval.v.host->addr.v.tblname))
				errx(1, "host: strlcpy");
			free(yystack.l_mark[-1].v.string);
			yyval.v.host->next = NULL;
			yyval.v.host->tail = yyval.v.host;
		}
break;
case 305:
#line 3202 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			u_long	ulval;

			if (atoul(yystack.l_mark[0].v.string, &ulval) == -1) {
				yyerror("%s is not a number", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			} else
				yyval.v.number = ulval;
			free(yystack.l_mark[0].v.string);
		}
break;
case 306:
#line 3215 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			int	 flags = 0;
			char	*p, *op;

			op = yystack.l_mark[-1].v.string;
			if (!isalpha(op[0])) {
				yyerror("invalid interface name '%s'", op);
				free(op);
				YYERROR;
			}
			while ((p = strrchr(yystack.l_mark[-1].v.string, ':')) != NULL) {
				if (!strcmp(p+1, "network"))
					flags |= PFI_AFLAG_NETWORK;
				else if (!strcmp(p+1, "broadcast"))
					flags |= PFI_AFLAG_BROADCAST;
				else if (!strcmp(p+1, "peer"))
					flags |= PFI_AFLAG_PEER;
				else if (!strcmp(p+1, "0"))
					flags |= PFI_AFLAG_NOALIAS;
				else {
					yyerror("interface %s has bad modifier",
					    yystack.l_mark[-1].v.string);
					free(op);
					YYERROR;
				}
				*p = '\0';
			}
			if (flags & (flags - 1) & PFI_AFLAG_MODEMASK) {
				free(op);
				yyerror("illegal combination of "
				    "interface modifiers");
				YYERROR;
			}
			yyval.v.host = calloc(1, sizeof(struct node_host));
			if (yyval.v.host == NULL)
				err(1, "address: calloc");
			yyval.v.host->af = 0;
			set_ipmask(yyval.v.host, 128);
			yyval.v.host->addr.type = PF_ADDR_DYNIFTL;
			yyval.v.host->addr.iflags = flags;
			if (strlcpy(yyval.v.host->addr.v.ifname, yystack.l_mark[-1].v.string,
			    sizeof(yyval.v.host->addr.v.ifname)) >=
			    sizeof(yyval.v.host->addr.v.ifname)) {
				free(op);
				free(yyval.v.host);
				yyerror("interface name too long");
				YYERROR;
			}
			free(op);
			yyval.v.host->next = NULL;
			yyval.v.host->tail = yyval.v.host;
		}
break;
case 307:
#line 3269 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.port = yystack.l_mark[0].v.port; }
break;
case 308:
#line 3270 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.port = yystack.l_mark[-1].v.port; }
break;
case 309:
#line 3273 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.port = yystack.l_mark[-1].v.port; }
break;
case 310:
#line 3274 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.port->tail->next = yystack.l_mark[-1].v.port;
			yystack.l_mark[-3].v.port->tail = yystack.l_mark[-1].v.port;
			yyval.v.port = yystack.l_mark[-3].v.port;
		}
break;
case 311:
#line 3281 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.port = calloc(1, sizeof(struct node_port));
			if (yyval.v.port == NULL)
				err(1, "port_item: calloc");
			yyval.v.port->port[0] = yystack.l_mark[0].v.range.a;
			yyval.v.port->port[1] = yystack.l_mark[0].v.range.b;
			if (yystack.l_mark[0].v.range.t)
				yyval.v.port->op = PF_OP_RRG;
			else
				yyval.v.port->op = PF_OP_EQ;
			yyval.v.port->next = NULL;
			yyval.v.port->tail = yyval.v.port;
		}
break;
case 312:
#line 3294 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.range.t) {
				yyerror("':' cannot be used with an other "
				    "port operator");
				YYERROR;
			}
			yyval.v.port = calloc(1, sizeof(struct node_port));
			if (yyval.v.port == NULL)
				err(1, "port_item: calloc");
			yyval.v.port->port[0] = yystack.l_mark[0].v.range.a;
			yyval.v.port->port[1] = yystack.l_mark[0].v.range.b;
			yyval.v.port->op = yystack.l_mark[-1].v.i;
			yyval.v.port->next = NULL;
			yyval.v.port->tail = yyval.v.port;
		}
break;
case 313:
#line 3309 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-2].v.range.t || yystack.l_mark[0].v.range.t) {
				yyerror("':' cannot be used with an other "
				    "port operator");
				YYERROR;
			}
			yyval.v.port = calloc(1, sizeof(struct node_port));
			if (yyval.v.port == NULL)
				err(1, "port_item: calloc");
			yyval.v.port->port[0] = yystack.l_mark[-2].v.range.a;
			yyval.v.port->port[1] = yystack.l_mark[0].v.range.a;
			yyval.v.port->op = yystack.l_mark[-1].v.i;
			yyval.v.port->next = NULL;
			yyval.v.port->tail = yyval.v.port;
		}
break;
case 314:
#line 3326 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (parseport(yystack.l_mark[0].v.string, &yyval.v.range, 0) == -1) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 315:
#line 3335 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (parseport(yystack.l_mark[0].v.string, &yyval.v.range, PPORT_RANGE) == -1) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 316:
#line 3344 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.uid = yystack.l_mark[0].v.uid; }
break;
case 317:
#line 3345 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.uid = yystack.l_mark[-1].v.uid; }
break;
case 318:
#line 3348 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.uid = yystack.l_mark[-1].v.uid; }
break;
case 319:
#line 3349 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.uid->tail->next = yystack.l_mark[-1].v.uid;
			yystack.l_mark[-3].v.uid->tail = yystack.l_mark[-1].v.uid;
			yyval.v.uid = yystack.l_mark[-3].v.uid;
		}
break;
case 320:
#line 3356 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.uid = calloc(1, sizeof(struct node_uid));
			if (yyval.v.uid == NULL)
				err(1, "uid_item: calloc");
			yyval.v.uid->uid[0] = yystack.l_mark[0].v.number;
			yyval.v.uid->uid[1] = yystack.l_mark[0].v.number;
			yyval.v.uid->op = PF_OP_EQ;
			yyval.v.uid->next = NULL;
			yyval.v.uid->tail = yyval.v.uid;
		}
break;
case 321:
#line 3366 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number == UID_MAX && yystack.l_mark[-1].v.i != PF_OP_EQ && yystack.l_mark[-1].v.i != PF_OP_NE) {
				yyerror("user unknown requires operator = or "
				    "!=");
				YYERROR;
			}
			yyval.v.uid = calloc(1, sizeof(struct node_uid));
			if (yyval.v.uid == NULL)
				err(1, "uid_item: calloc");
			yyval.v.uid->uid[0] = yystack.l_mark[0].v.number;
			yyval.v.uid->uid[1] = yystack.l_mark[0].v.number;
			yyval.v.uid->op = yystack.l_mark[-1].v.i;
			yyval.v.uid->next = NULL;
			yyval.v.uid->tail = yyval.v.uid;
		}
break;
case 322:
#line 3381 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-2].v.number == UID_MAX || yystack.l_mark[0].v.number == UID_MAX) {
				yyerror("user unknown requires operator = or "
				    "!=");
				YYERROR;
			}
			yyval.v.uid = calloc(1, sizeof(struct node_uid));
			if (yyval.v.uid == NULL)
				err(1, "uid_item: calloc");
			yyval.v.uid->uid[0] = yystack.l_mark[-2].v.number;
			yyval.v.uid->uid[1] = yystack.l_mark[0].v.number;
			yyval.v.uid->op = yystack.l_mark[-1].v.i;
			yyval.v.uid->next = NULL;
			yyval.v.uid->tail = yyval.v.uid;
		}
break;
case 323:
#line 3398 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "unknown"))
				yyval.v.number = UID_MAX;
			else {
				struct passwd	*pw;

				if ((pw = getpwnam(yystack.l_mark[0].v.string)) == NULL) {
					yyerror("unknown user %s", yystack.l_mark[0].v.string);
					free(yystack.l_mark[0].v.string);
					YYERROR;
				}
				yyval.v.number = pw->pw_uid;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 324:
#line 3413 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number >= UID_MAX) {
				yyerror("illegal uid value %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			yyval.v.number = yystack.l_mark[0].v.number;
		}
break;
case 325:
#line 3422 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.gid = yystack.l_mark[0].v.gid; }
break;
case 326:
#line 3423 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.gid = yystack.l_mark[-1].v.gid; }
break;
case 327:
#line 3426 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.gid = yystack.l_mark[-1].v.gid; }
break;
case 328:
#line 3427 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.gid->tail->next = yystack.l_mark[-1].v.gid;
			yystack.l_mark[-3].v.gid->tail = yystack.l_mark[-1].v.gid;
			yyval.v.gid = yystack.l_mark[-3].v.gid;
		}
break;
case 329:
#line 3434 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.gid = calloc(1, sizeof(struct node_gid));
			if (yyval.v.gid == NULL)
				err(1, "gid_item: calloc");
			yyval.v.gid->gid[0] = yystack.l_mark[0].v.number;
			yyval.v.gid->gid[1] = yystack.l_mark[0].v.number;
			yyval.v.gid->op = PF_OP_EQ;
			yyval.v.gid->next = NULL;
			yyval.v.gid->tail = yyval.v.gid;
		}
break;
case 330:
#line 3444 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number == GID_MAX && yystack.l_mark[-1].v.i != PF_OP_EQ && yystack.l_mark[-1].v.i != PF_OP_NE) {
				yyerror("group unknown requires operator = or "
				    "!=");
				YYERROR;
			}
			yyval.v.gid = calloc(1, sizeof(struct node_gid));
			if (yyval.v.gid == NULL)
				err(1, "gid_item: calloc");
			yyval.v.gid->gid[0] = yystack.l_mark[0].v.number;
			yyval.v.gid->gid[1] = yystack.l_mark[0].v.number;
			yyval.v.gid->op = yystack.l_mark[-1].v.i;
			yyval.v.gid->next = NULL;
			yyval.v.gid->tail = yyval.v.gid;
		}
break;
case 331:
#line 3459 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-2].v.number == GID_MAX || yystack.l_mark[0].v.number == GID_MAX) {
				yyerror("group unknown requires operator = or "
				    "!=");
				YYERROR;
			}
			yyval.v.gid = calloc(1, sizeof(struct node_gid));
			if (yyval.v.gid == NULL)
				err(1, "gid_item: calloc");
			yyval.v.gid->gid[0] = yystack.l_mark[-2].v.number;
			yyval.v.gid->gid[1] = yystack.l_mark[0].v.number;
			yyval.v.gid->op = yystack.l_mark[-1].v.i;
			yyval.v.gid->next = NULL;
			yyval.v.gid->tail = yyval.v.gid;
		}
break;
case 332:
#line 3476 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "unknown"))
				yyval.v.number = GID_MAX;
			else {
				struct group	*grp;

				if ((grp = getgrnam(yystack.l_mark[0].v.string)) == NULL) {
					yyerror("unknown group %s", yystack.l_mark[0].v.string);
					free(yystack.l_mark[0].v.string);
					YYERROR;
				}
				yyval.v.number = grp->gr_gid;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 333:
#line 3491 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number >= GID_MAX) {
				yyerror("illegal gid value %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			yyval.v.number = yystack.l_mark[0].v.number;
		}
break;
case 334:
#line 3500 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			int	f;

			if ((f = parse_flags(yystack.l_mark[0].v.string)) < 0) {
				yyerror("bad flags %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
			yyval.v.b.b1 = f;
		}
break;
case 335:
#line 3513 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = yystack.l_mark[-2].v.b.b1; yyval.v.b.b2 = yystack.l_mark[0].v.b.b1; }
break;
case 336:
#line 3514 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = 0; yyval.v.b.b2 = yystack.l_mark[0].v.b.b1; }
break;
case 337:
#line 3515 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = 0; yyval.v.b.b2 = 0; }
break;
case 338:
#line 3518 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.icmp = yystack.l_mark[0].v.icmp; }
break;
case 339:
#line 3519 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.icmp = yystack.l_mark[-1].v.icmp; }
break;
case 340:
#line 3520 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.icmp = yystack.l_mark[0].v.icmp; }
break;
case 341:
#line 3521 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.icmp = yystack.l_mark[-1].v.icmp; }
break;
case 342:
#line 3524 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.icmp = yystack.l_mark[-1].v.icmp; }
break;
case 343:
#line 3525 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.icmp->tail->next = yystack.l_mark[-1].v.icmp;
			yystack.l_mark[-3].v.icmp->tail = yystack.l_mark[-1].v.icmp;
			yyval.v.icmp = yystack.l_mark[-3].v.icmp;
		}
break;
case 344:
#line 3532 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.icmp = yystack.l_mark[-1].v.icmp; }
break;
case 345:
#line 3533 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.icmp->tail->next = yystack.l_mark[-1].v.icmp;
			yystack.l_mark[-3].v.icmp->tail = yystack.l_mark[-1].v.icmp;
			yyval.v.icmp = yystack.l_mark[-3].v.icmp;
		}
break;
case 346:
#line 3540 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.icmp = calloc(1, sizeof(struct node_icmp));
			if (yyval.v.icmp == NULL)
				err(1, "icmp_item: calloc");
			yyval.v.icmp->type = yystack.l_mark[0].v.number;
			yyval.v.icmp->code = 0;
			yyval.v.icmp->proto = IPPROTO_ICMP;
			yyval.v.icmp->next = NULL;
			yyval.v.icmp->tail = yyval.v.icmp;
		}
break;
case 347:
#line 3550 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			const struct icmpcodeent	*p;

			if ((p = geticmpcodebyname(yystack.l_mark[-2].v.number-1, yystack.l_mark[0].v.string, AF_INET)) == NULL) {
				yyerror("unknown icmp-code %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}

			free(yystack.l_mark[0].v.string);
			yyval.v.icmp = calloc(1, sizeof(struct node_icmp));
			if (yyval.v.icmp == NULL)
				err(1, "icmp_item: calloc");
			yyval.v.icmp->type = yystack.l_mark[-2].v.number;
			yyval.v.icmp->code = p->code + 1;
			yyval.v.icmp->proto = IPPROTO_ICMP;
			yyval.v.icmp->next = NULL;
			yyval.v.icmp->tail = yyval.v.icmp;
		}
break;
case 348:
#line 3569 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("illegal icmp-code %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			yyval.v.icmp = calloc(1, sizeof(struct node_icmp));
			if (yyval.v.icmp == NULL)
				err(1, "icmp_item: calloc");
			yyval.v.icmp->type = yystack.l_mark[-2].v.number;
			yyval.v.icmp->code = yystack.l_mark[0].v.number + 1;
			yyval.v.icmp->proto = IPPROTO_ICMP;
			yyval.v.icmp->next = NULL;
			yyval.v.icmp->tail = yyval.v.icmp;
		}
break;
case 349:
#line 3585 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.icmp = calloc(1, sizeof(struct node_icmp));
			if (yyval.v.icmp == NULL)
				err(1, "icmp_item: calloc");
			yyval.v.icmp->type = yystack.l_mark[0].v.number;
			yyval.v.icmp->code = 0;
			yyval.v.icmp->proto = IPPROTO_ICMPV6;
			yyval.v.icmp->next = NULL;
			yyval.v.icmp->tail = yyval.v.icmp;
		}
break;
case 350:
#line 3595 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			const struct icmpcodeent	*p;

			if ((p = geticmpcodebyname(yystack.l_mark[-2].v.number-1, yystack.l_mark[0].v.string, AF_INET6)) == NULL) {
				yyerror("unknown icmp6-code %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);

			yyval.v.icmp = calloc(1, sizeof(struct node_icmp));
			if (yyval.v.icmp == NULL)
				err(1, "icmp_item: calloc");
			yyval.v.icmp->type = yystack.l_mark[-2].v.number;
			yyval.v.icmp->code = p->code + 1;
			yyval.v.icmp->proto = IPPROTO_ICMPV6;
			yyval.v.icmp->next = NULL;
			yyval.v.icmp->tail = yyval.v.icmp;
		}
break;
case 351:
#line 3614 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("illegal icmp-code %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			yyval.v.icmp = calloc(1, sizeof(struct node_icmp));
			if (yyval.v.icmp == NULL)
				err(1, "icmp_item: calloc");
			yyval.v.icmp->type = yystack.l_mark[-2].v.number;
			yyval.v.icmp->code = yystack.l_mark[0].v.number + 1;
			yyval.v.icmp->proto = IPPROTO_ICMPV6;
			yyval.v.icmp->next = NULL;
			yyval.v.icmp->tail = yyval.v.icmp;
		}
break;
case 352:
#line 3630 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			const struct icmptypeent	*p;

			if ((p = geticmptypebyname(yystack.l_mark[0].v.string, AF_INET)) == NULL) {
				yyerror("unknown icmp-type %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			yyval.v.number = p->type + 1;
			free(yystack.l_mark[0].v.string);
		}
break;
case 353:
#line 3641 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("illegal icmp-type %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			yyval.v.number = yystack.l_mark[0].v.number + 1;
		}
break;
case 354:
#line 3650 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			const struct icmptypeent	*p;

			if ((p = geticmptypebyname(yystack.l_mark[0].v.string, AF_INET6)) ==
			    NULL) {
				yyerror("unknown icmp6-type %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			yyval.v.number = p->type + 1;
			free(yystack.l_mark[0].v.string);
		}
break;
case 355:
#line 3662 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("illegal icmp6-type %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			yyval.v.number = yystack.l_mark[0].v.number + 1;
		}
break;
case 356:
#line 3671 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			int val;
			char *end;

			if (map_tos(yystack.l_mark[0].v.string, &val))
				yyval.v.number = val;
			else if (yystack.l_mark[0].v.string[0] == '0' && yystack.l_mark[0].v.string[1] == 'x') {
				errno = 0;
				yyval.v.number = strtoul(yystack.l_mark[0].v.string, &end, 16);
				if (errno || *end != '\0')
					yyval.v.number = 256;
			} else
				yyval.v.number = 256;		/* flag bad argument */
			if (yyval.v.number < 0 || yyval.v.number > 255) {
				yyerror("illegal tos value %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 357:
#line 3691 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.number = yystack.l_mark[0].v.number;
			if (yyval.v.number < 0 || yyval.v.number > 255) {
				yyerror("illegal tos value %s", yystack.l_mark[0].v.number);
				YYERROR;
			}
		}
break;
case 358:
#line 3700 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "EF"))
				yyval.v.number = DSCP_EF;
			else if (!strcmp(yystack.l_mark[0].v.string, "VA"))
				yyval.v.number = DSCP_VA;
			else if (!strcmp(yystack.l_mark[0].v.string, "af11"))
				yyval.v.number = DSCP_AF11;
			else if (!strcmp(yystack.l_mark[0].v.string, "af12"))
				yyval.v.number = DSCP_AF12;
			else if (!strcmp(yystack.l_mark[0].v.string, "af13"))
				yyval.v.number = DSCP_AF13;
			else if (!strcmp(yystack.l_mark[0].v.string, "af21"))
				yyval.v.number = DSCP_AF21;
			else if (!strcmp(yystack.l_mark[0].v.string, "af22"))
				yyval.v.number = DSCP_AF22;
			else if (!strcmp(yystack.l_mark[0].v.string, "af23"))
				yyval.v.number = DSCP_AF23;
			else if (!strcmp(yystack.l_mark[0].v.string, "af31"))
				yyval.v.number = DSCP_AF31;
			else if (!strcmp(yystack.l_mark[0].v.string, "af32"))
				yyval.v.number = DSCP_AF32;
			else if (!strcmp(yystack.l_mark[0].v.string, "af33"))
				yyval.v.number = DSCP_AF33;
			else if (!strcmp(yystack.l_mark[0].v.string, "af41"))
				yyval.v.number = DSCP_AF41;
			else if (!strcmp(yystack.l_mark[0].v.string, "af42"))
				yyval.v.number = DSCP_AF42;
			else if (!strcmp(yystack.l_mark[0].v.string, "af43"))
				yyval.v.number = DSCP_AF43;
			else if (yystack.l_mark[0].v.string[0] == '0' && yystack.l_mark[0].v.string[1] == 'x')
				yyval.v.number = strtoul(yystack.l_mark[0].v.string, NULL, 16) * 4;
			else
				yyval.v.number = strtoul(yystack.l_mark[0].v.string, NULL, 10) * 4;
			if (!yyval.v.number || yyval.v.number > 255) {
				yyerror("illegal dscp value %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 359:
#line 3742 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_SRCTRACK; }
break;
case 360:
#line 3743 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_SRCTRACK_GLOBAL; }
break;
case 361:
#line 3744 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_SRCTRACK_RULE; }
break;
case 362:
#line 3747 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.i = PFRULE_IFBOUND;
		}
break;
case 363:
#line 3750 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.i = 0;
		}
break;
case 364:
#line 3755 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.keep_state.action = 0;
			yyval.v.keep_state.options = NULL;
		}
break;
case 365:
#line 3759 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.keep_state.action = PF_STATE_NORMAL;
			yyval.v.keep_state.options = yystack.l_mark[0].v.state_opt;
		}
break;
case 366:
#line 3763 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.keep_state.action = PF_STATE_MODULATE;
			yyval.v.keep_state.options = yystack.l_mark[0].v.state_opt;
		}
break;
case 367:
#line 3767 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.keep_state.action = PF_STATE_SYNPROXY;
			yyval.v.keep_state.options = yystack.l_mark[0].v.state_opt;
		}
break;
case 368:
#line 3773 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = 0; }
break;
case 369:
#line 3774 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_FLUSH; }
break;
case 370:
#line 3775 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.i = PF_FLUSH | PF_FLUSH_GLOBAL;
		}
break;
case 371:
#line 3780 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.state_opt = yystack.l_mark[-1].v.state_opt; }
break;
case 372:
#line 3781 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.state_opt = NULL; }
break;
case 373:
#line 3784 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.state_opt = yystack.l_mark[0].v.state_opt; }
break;
case 374:
#line 3785 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-2].v.state_opt->tail->next = yystack.l_mark[0].v.state_opt;
			yystack.l_mark[-2].v.state_opt->tail = yystack.l_mark[0].v.state_opt;
			yyval.v.state_opt = yystack.l_mark[-2].v.state_opt;
		}
break;
case 375:
#line 3792 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_MAX;
			yyval.v.state_opt->data.max_states = yystack.l_mark[0].v.number;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 376:
#line 3805 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_NOSYNC;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 377:
#line 3813 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_MAX_SRC_STATES;
			yyval.v.state_opt->data.max_src_states = yystack.l_mark[0].v.number;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 378:
#line 3826 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_MAX_SRC_CONN;
			yyval.v.state_opt->data.max_src_conn = yystack.l_mark[0].v.number;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 379:
#line 3839 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-2].v.number < 0 || yystack.l_mark[-2].v.number > UINT_MAX ||
			    yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_MAX_SRC_CONN_RATE;
			yyval.v.state_opt->data.max_src_conn_rate.limit = yystack.l_mark[-2].v.number;
			yyval.v.state_opt->data.max_src_conn_rate.seconds = yystack.l_mark[0].v.number;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 380:
#line 3854 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (strlen(yystack.l_mark[-2].v.string) >= PF_TABLE_NAME_SIZE) {
				yyerror("table name '%s' too long", yystack.l_mark[-2].v.string);
				free(yystack.l_mark[-2].v.string);
				YYERROR;
			}
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			if (strlcpy(yyval.v.state_opt->data.overload.tblname, yystack.l_mark[-2].v.string,
			    PF_TABLE_NAME_SIZE) >= PF_TABLE_NAME_SIZE)
				errx(1, "state_opt_item: strlcpy");
			free(yystack.l_mark[-2].v.string);
			yyval.v.state_opt->type = PF_STATE_OPT_OVERLOAD;
			yyval.v.state_opt->data.overload.flush = yystack.l_mark[0].v.i;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 381:
#line 3872 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_MAX_SRC_NODES;
			yyval.v.state_opt->data.max_src_nodes = yystack.l_mark[0].v.number;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 382:
#line 3885 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_SRCTRACK;
			yyval.v.state_opt->data.src_track = yystack.l_mark[0].v.i;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 383:
#line 3894 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_STATELOCK;
			yyval.v.state_opt->data.statelock = yystack.l_mark[0].v.i;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 384:
#line 3903 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_SLOPPY;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 385:
#line 3911 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			int	i;

			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			for (i = 0; pf_timeouts[i].name &&
			    strcmp(pf_timeouts[i].name, yystack.l_mark[-1].v.string); ++i)
				;	/* nothing */
			if (!pf_timeouts[i].name) {
				yyerror("illegal timeout name %s", yystack.l_mark[-1].v.string);
				free(yystack.l_mark[-1].v.string);
				YYERROR;
			}
			if (strchr(pf_timeouts[i].name, '.') == NULL) {
				yyerror("illegal state timeout %s", yystack.l_mark[-1].v.string);
				free(yystack.l_mark[-1].v.string);
				YYERROR;
			}
			free(yystack.l_mark[-1].v.string);
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_TIMEOUT;
			yyval.v.state_opt->data.timeout.number = pf_timeouts[i].timeout;
			yyval.v.state_opt->data.timeout.seconds = yystack.l_mark[0].v.number;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 386:
#line 3943 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.string = yystack.l_mark[0].v.string;
		}
break;
case 387:
#line 3948 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.string = yystack.l_mark[0].v.string;
		}
break;
case 388:
#line 3953 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.qassign.qname = yystack.l_mark[0].v.string;
			yyval.v.qassign.pqname = NULL;
		}
break;
case 389:
#line 3957 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.qassign.qname = yystack.l_mark[-1].v.string;
			yyval.v.qassign.pqname = NULL;
		}
break;
case 390:
#line 3961 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.qassign.qname = yystack.l_mark[-3].v.string;
			yyval.v.qassign.pqname = yystack.l_mark[-1].v.string;
		}
break;
case 391:
#line 3967 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = 0; }
break;
case 392:
#line 3968 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = 1; }
break;
case 393:
#line 3971 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (parseport(yystack.l_mark[0].v.string, &yyval.v.range, PPORT_RANGE|PPORT_STAR) == -1) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 394:
#line 3980 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[0].v.host; }
break;
case 395:
#line 3981 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[-1].v.host; }
break;
case 396:
#line 3984 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[-1].v.host; }
break;
case 397:
#line 3985 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.host->tail->next = yystack.l_mark[-1].v.host;
			yystack.l_mark[-3].v.host->tail = yystack.l_mark[-1].v.host->tail;
			yyval.v.host = yystack.l_mark[-3].v.host;
		}
break;
case 398:
#line 3992 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.redirection = NULL; }
break;
case 399:
#line 3993 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.redirection = calloc(1, sizeof(struct redirection));
			if (yyval.v.redirection == NULL)
				err(1, "redirection: calloc");
			yyval.v.redirection->host = yystack.l_mark[0].v.host;
			yyval.v.redirection->rport.a = yyval.v.redirection->rport.b = yyval.v.redirection->rport.t = 0;
		}
break;
case 400:
#line 4000 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.redirection = calloc(1, sizeof(struct redirection));
			if (yyval.v.redirection == NULL)
				err(1, "redirection: calloc");
			yyval.v.redirection->host = yystack.l_mark[-2].v.host;
			yyval.v.redirection->rport = yystack.l_mark[0].v.range;
		}
break;
case 401:
#line 4010 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.hashkey = calloc(1, sizeof(struct pf_poolhashkey));
			if (yyval.v.hashkey == NULL)
				err(1, "hashkey: calloc");
			yyval.v.hashkey->key32[0] = arc4random();
			yyval.v.hashkey->key32[1] = arc4random();
			yyval.v.hashkey->key32[2] = arc4random();
			yyval.v.hashkey->key32[3] = arc4random();
		}
break;
case 402:
#line 4020 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (!strncmp(yystack.l_mark[0].v.string, "0x", 2)) {
				if (strlen(yystack.l_mark[0].v.string) != 34) {
					free(yystack.l_mark[0].v.string);
					yyerror("hex key must be 128 bits "
						"(32 hex digits) long");
					YYERROR;
				}
				yyval.v.hashkey = calloc(1, sizeof(struct pf_poolhashkey));
				if (yyval.v.hashkey == NULL)
					err(1, "hashkey: calloc");

				if (sscanf(yystack.l_mark[0].v.string, "0x%8x%8x%8x%8x",
				    &yyval.v.hashkey->key32[0], &yyval.v.hashkey->key32[1],
				    &yyval.v.hashkey->key32[2], &yyval.v.hashkey->key32[3]) != 4) {
					free(yyval.v.hashkey);
					free(yystack.l_mark[0].v.string);
					yyerror("invalid hex key");
					YYERROR;
				}
			} else {
				MD5_CTX	context;

				yyval.v.hashkey = calloc(1, sizeof(struct pf_poolhashkey));
				if (yyval.v.hashkey == NULL)
					err(1, "hashkey: calloc");
				MD5Init(&context);
				MD5Update(&context, (unsigned char *)yystack.l_mark[0].v.string,
				    strlen(yystack.l_mark[0].v.string));
				MD5Final((unsigned char *)yyval.v.hashkey, &context);
				HTONL(yyval.v.hashkey->key32[0]);
				HTONL(yyval.v.hashkey->key32[1]);
				HTONL(yyval.v.hashkey->key32[2]);
				HTONL(yyval.v.hashkey->key32[3]);
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 403:
#line 4059 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ bzero(&pool_opts, sizeof pool_opts); }
break;
case 404:
#line 4061 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.pool_opts = pool_opts; }
break;
case 405:
#line 4062 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			bzero(&pool_opts, sizeof pool_opts);
			yyval.v.pool_opts = pool_opts;
		}
break;
case 408:
#line 4072 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (pool_opts.type) {
				yyerror("pool type cannot be redefined");
				YYERROR;
			}
			pool_opts.type =  PF_POOL_BITMASK;
		}
break;
case 409:
#line 4079 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (pool_opts.type) {
				yyerror("pool type cannot be redefined");
				YYERROR;
			}
			pool_opts.type = PF_POOL_RANDOM;
		}
break;
case 410:
#line 4086 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (pool_opts.type) {
				yyerror("pool type cannot be redefined");
				YYERROR;
			}
			pool_opts.type = PF_POOL_SRCHASH;
			pool_opts.key = yystack.l_mark[0].v.hashkey;
		}
break;
case 411:
#line 4094 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (pool_opts.type) {
				yyerror("pool type cannot be redefined");
				YYERROR;
			}
			pool_opts.type = PF_POOL_ROUNDROBIN;
		}
break;
case 412:
#line 4101 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (pool_opts.staticport) {
				yyerror("static-port cannot be redefined");
				YYERROR;
			}
			pool_opts.staticport = 1;
		}
break;
case 413:
#line 4108 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.marker & POM_STICKYADDRESS) {
				yyerror("sticky-address cannot be redefined");
				YYERROR;
			}
			pool_opts.marker |= POM_STICKYADDRESS;
			pool_opts.opts |= PF_POOL_STICKYADDR;
		}
break;
case 414:
#line 4118 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.redirection = NULL; }
break;
case 415:
#line 4119 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.redirection = calloc(1, sizeof(struct redirection));
			if (yyval.v.redirection == NULL)
				err(1, "redirection: calloc");
			yyval.v.redirection->host = yystack.l_mark[0].v.host;
			yyval.v.redirection->rport.a = yyval.v.redirection->rport.b = yyval.v.redirection->rport.t = 0;
		}
break;
case 416:
#line 4126 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.redirection = calloc(1, sizeof(struct redirection));
			if (yyval.v.redirection == NULL)
				err(1, "redirection: calloc");
			yyval.v.redirection->host = yystack.l_mark[-2].v.host;
			yyval.v.redirection->rport = yystack.l_mark[0].v.range;
		}
break;
case 417:
#line 4135 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = yyval.v.b.b2 = 0; yyval.v.b.w2 = 0; }
break;
case 418:
#line 4136 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = 1; yyval.v.b.b2 = 0; yyval.v.b.w2 = 0; }
break;
case 419:
#line 4137 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = 1; yyval.v.b.b2 = yystack.l_mark[0].v.logquick.log; yyval.v.b.w2 = yystack.l_mark[0].v.logquick.logif; }
break;
case 420:
#line 4138 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = 0; yyval.v.b.b2 = yystack.l_mark[0].v.logquick.log; yyval.v.b.w2 = yystack.l_mark[0].v.logquick.logif; }
break;
case 421:
#line 4141 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-2].v.i && yystack.l_mark[0].v.b.b1) {
				yyerror("\"pass\" not valid with \"no\"");
				YYERROR;
			}
			if (yystack.l_mark[-2].v.i)
				yyval.v.b.b1 = PF_NONAT;
			else
				yyval.v.b.b1 = PF_NAT;
			yyval.v.b.b2 = yystack.l_mark[0].v.b.b1;
			yyval.v.b.w = yystack.l_mark[0].v.b.b2;
			yyval.v.b.w2 = yystack.l_mark[0].v.b.w2;
		}
break;
case 422:
#line 4154 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-2].v.i && yystack.l_mark[0].v.b.b1) {
				yyerror("\"pass\" not valid with \"no\"");
				YYERROR;
			}
			if (yystack.l_mark[-2].v.i)
				yyval.v.b.b1 = PF_NORDR;
			else
				yyval.v.b.b1 = PF_RDR;
			yyval.v.b.b2 = yystack.l_mark[0].v.b.b1;
			yyval.v.b.w = yystack.l_mark[0].v.b.b2;
			yyval.v.b.w2 = yystack.l_mark[0].v.b.w2;
		}
break;
case 423:
#line 4171 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct pf_rule	r;

			if (check_rulestate(PFCTL_STATE_NAT))
				YYERROR;

			memset(&r, 0, sizeof(r));

			r.action = yystack.l_mark[-9].v.b.b1;
			r.natpass = yystack.l_mark[-9].v.b.b2;
			r.log = yystack.l_mark[-9].v.b.w;
			r.logif = yystack.l_mark[-9].v.b.w2;
			r.af = yystack.l_mark[-7].v.i;

			if (!r.af) {
				if (yystack.l_mark[-5].v.fromto.src.host && yystack.l_mark[-5].v.fromto.src.host->af &&
				    !yystack.l_mark[-5].v.fromto.src.host->ifindex)
					r.af = yystack.l_mark[-5].v.fromto.src.host->af;
				else if (yystack.l_mark[-5].v.fromto.dst.host && yystack.l_mark[-5].v.fromto.dst.host->af &&
				    !yystack.l_mark[-5].v.fromto.dst.host->ifindex)
					r.af = yystack.l_mark[-5].v.fromto.dst.host->af;
			}

			if (yystack.l_mark[-4].v.string != NULL)
				if (strlcpy(r.tagname, yystack.l_mark[-4].v.string, PF_TAG_NAME_SIZE) >=
				    PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}

			if (yystack.l_mark[-3].v.tagged.name)
				if (strlcpy(r.match_tagname, yystack.l_mark[-3].v.tagged.name,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			r.match_tag_not = yystack.l_mark[-3].v.tagged.neg;
			r.rtableid = yystack.l_mark[-2].v.rtableid;

			if (r.action == PF_NONAT || r.action == PF_NORDR) {
				if (yystack.l_mark[-1].v.redirection != NULL) {
					yyerror("translation rule with 'no' "
					    "does not need '->'");
					YYERROR;
				}
			} else {
				if (yystack.l_mark[-1].v.redirection == NULL || yystack.l_mark[-1].v.redirection->host == NULL) {
					yyerror("translation rule requires '-> "
					    "address'");
					YYERROR;
				}
				if (!r.af && ! yystack.l_mark[-1].v.redirection->host->ifindex)
					r.af = yystack.l_mark[-1].v.redirection->host->af;

				remove_invalid_hosts(&yystack.l_mark[-1].v.redirection->host, &r.af);
				if (invalid_redirect(yystack.l_mark[-1].v.redirection->host, r.af))
					YYERROR;
				if (check_netmask(yystack.l_mark[-1].v.redirection->host, r.af))
					YYERROR;

				r.rpool.proxy_port[0] = ntohs(yystack.l_mark[-1].v.redirection->rport.a);

				switch (r.action) {
				case PF_RDR:
					if (!yystack.l_mark[-1].v.redirection->rport.b && yystack.l_mark[-1].v.redirection->rport.t &&
					    yystack.l_mark[-5].v.fromto.dst.port != NULL) {
						r.rpool.proxy_port[1] =
						    ntohs(yystack.l_mark[-1].v.redirection->rport.a) +
						    (ntohs(
						    yystack.l_mark[-5].v.fromto.dst.port->port[1]) -
						    ntohs(
						    yystack.l_mark[-5].v.fromto.dst.port->port[0]));
					} else
						r.rpool.proxy_port[1] =
						    ntohs(yystack.l_mark[-1].v.redirection->rport.b);
					break;
				case PF_NAT:
					r.rpool.proxy_port[1] =
					    ntohs(yystack.l_mark[-1].v.redirection->rport.b);
					if (!r.rpool.proxy_port[0] &&
					    !r.rpool.proxy_port[1]) {
						r.rpool.proxy_port[0] =
						    PF_NAT_PROXY_PORT_LOW;
						r.rpool.proxy_port[1] =
						    PF_NAT_PROXY_PORT_HIGH;
					} else if (!r.rpool.proxy_port[1])
						r.rpool.proxy_port[1] =
						    r.rpool.proxy_port[0];
					break;
				default:
					break;
				}

				r.rpool.opts = yystack.l_mark[0].v.pool_opts.type;
				if ((r.rpool.opts & PF_POOL_TYPEMASK) ==
				    PF_POOL_NONE && (yystack.l_mark[-1].v.redirection->host->next != NULL ||
				    yystack.l_mark[-1].v.redirection->host->addr.type == PF_ADDR_TABLE ||
				    DYNIF_MULTIADDR(yystack.l_mark[-1].v.redirection->host->addr)))
					r.rpool.opts = PF_POOL_ROUNDROBIN;
				if ((r.rpool.opts & PF_POOL_TYPEMASK) !=
				    PF_POOL_ROUNDROBIN &&
				    disallow_table(yystack.l_mark[-1].v.redirection->host, "tables are only "
				    "supported in round-robin redirection "
				    "pools"))
					YYERROR;
				if ((r.rpool.opts & PF_POOL_TYPEMASK) !=
				    PF_POOL_ROUNDROBIN &&
				    disallow_alias(yystack.l_mark[-1].v.redirection->host, "interface (%s) "
				    "is only supported in round-robin "
				    "redirection pools"))
					YYERROR;
				if (yystack.l_mark[-1].v.redirection->host->next != NULL) {
					if ((r.rpool.opts & PF_POOL_TYPEMASK) !=
					    PF_POOL_ROUNDROBIN) {
						yyerror("only round-robin "
						    "valid for multiple "
						    "redirection addresses");
						YYERROR;
					}
				}
			}

			if (yystack.l_mark[0].v.pool_opts.key != NULL)
				memcpy(&r.rpool.key, yystack.l_mark[0].v.pool_opts.key,
				    sizeof(struct pf_poolhashkey));

			 if (yystack.l_mark[0].v.pool_opts.opts)
				r.rpool.opts |= yystack.l_mark[0].v.pool_opts.opts;

			if (yystack.l_mark[0].v.pool_opts.staticport) {
				if (r.action != PF_NAT) {
					yyerror("the 'static-port' option is "
					    "only valid with nat rules");
					YYERROR;
				}
				if (r.rpool.proxy_port[0] !=
				    PF_NAT_PROXY_PORT_LOW &&
				    r.rpool.proxy_port[1] !=
				    PF_NAT_PROXY_PORT_HIGH) {
					yyerror("the 'static-port' option can't"
					    " be used when specifying a port"
					    " range");
					YYERROR;
				}
				r.rpool.proxy_port[0] = 0;
				r.rpool.proxy_port[1] = 0;
			}

			expand_rule(&r, yystack.l_mark[-8].v.interface, yystack.l_mark[-1].v.redirection == NULL ? NULL : yystack.l_mark[-1].v.redirection->host, yystack.l_mark[-6].v.proto,
			    yystack.l_mark[-5].v.fromto.src_os, yystack.l_mark[-5].v.fromto.src.host, yystack.l_mark[-5].v.fromto.src.port, yystack.l_mark[-5].v.fromto.dst.host,
			    yystack.l_mark[-5].v.fromto.dst.port, 0, 0, 0, "");
			free(yystack.l_mark[-1].v.redirection);
		}
break;
case 424:
#line 4330 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct pf_rule		binat;
			struct pf_pooladdr	*pa;

			if (check_rulestate(PFCTL_STATE_NAT))
				YYERROR;
			if (disallow_urpf_failed(yystack.l_mark[-4].v.host, "\"urpf-failed\" is not "
			    "permitted as a binat destination"))
				YYERROR;

			memset(&binat, 0, sizeof(binat));

			if (yystack.l_mark[-12].v.i && yystack.l_mark[-10].v.b.b1) {
				yyerror("\"pass\" not valid with \"no\"");
				YYERROR;
			}
			if (yystack.l_mark[-12].v.i)
				binat.action = PF_NOBINAT;
			else
				binat.action = PF_BINAT;
			binat.natpass = yystack.l_mark[-10].v.b.b1;
			binat.log = yystack.l_mark[-10].v.b.b2;
			binat.logif = yystack.l_mark[-10].v.b.w2;
			binat.af = yystack.l_mark[-8].v.i;
			if (!binat.af && yystack.l_mark[-5].v.host != NULL && yystack.l_mark[-5].v.host->af)
				binat.af = yystack.l_mark[-5].v.host->af;
			if (!binat.af && yystack.l_mark[-4].v.host != NULL && yystack.l_mark[-4].v.host->af)
				binat.af = yystack.l_mark[-4].v.host->af;

			if (!binat.af && yystack.l_mark[0].v.redirection != NULL && yystack.l_mark[0].v.redirection->host)
				binat.af = yystack.l_mark[0].v.redirection->host->af;
			if (!binat.af) {
				yyerror("address family (inet/inet6) "
				    "undefined");
				YYERROR;
			}

			if (yystack.l_mark[-9].v.interface != NULL) {
				memcpy(binat.ifname, yystack.l_mark[-9].v.interface->ifname,
				    sizeof(binat.ifname));
				binat.ifnot = yystack.l_mark[-9].v.interface->not;
				free(yystack.l_mark[-9].v.interface);
			}

			if (yystack.l_mark[-3].v.string != NULL)
				if (strlcpy(binat.tagname, yystack.l_mark[-3].v.string,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			if (yystack.l_mark[-2].v.tagged.name)
				if (strlcpy(binat.match_tagname, yystack.l_mark[-2].v.tagged.name,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			binat.match_tag_not = yystack.l_mark[-2].v.tagged.neg;
			binat.rtableid = yystack.l_mark[-1].v.rtableid;

			if (yystack.l_mark[-7].v.proto != NULL) {
				binat.proto = yystack.l_mark[-7].v.proto->proto;
				free(yystack.l_mark[-7].v.proto);
			}

			if (yystack.l_mark[-5].v.host != NULL && disallow_table(yystack.l_mark[-5].v.host, "invalid use of "
			    "table <%s> as the source address of a binat rule"))
				YYERROR;
			if (yystack.l_mark[-5].v.host != NULL && disallow_alias(yystack.l_mark[-5].v.host, "invalid use of "
			    "interface (%s) as the source address of a binat "
			    "rule"))
				YYERROR;
			if (yystack.l_mark[0].v.redirection != NULL && yystack.l_mark[0].v.redirection->host != NULL && disallow_table(
			    yystack.l_mark[0].v.redirection->host, "invalid use of table <%s> as the "
			    "redirect address of a binat rule"))
				YYERROR;
			if (yystack.l_mark[0].v.redirection != NULL && yystack.l_mark[0].v.redirection->host != NULL && disallow_alias(
			    yystack.l_mark[0].v.redirection->host, "invalid use of interface (%s) as the "
			    "redirect address of a binat rule"))
				YYERROR;

			if (yystack.l_mark[-5].v.host != NULL) {
				if (yystack.l_mark[-5].v.host->next) {
					yyerror("multiple binat ip addresses");
					YYERROR;
				}
				if (yystack.l_mark[-5].v.host->addr.type == PF_ADDR_DYNIFTL)
					yystack.l_mark[-5].v.host->af = binat.af;
				if (yystack.l_mark[-5].v.host->af != binat.af) {
					yyerror("binat ip versions must match");
					YYERROR;
				}
				if (check_netmask(yystack.l_mark[-5].v.host, binat.af))
					YYERROR;
				memcpy(&binat.src.addr, &yystack.l_mark[-5].v.host->addr,
				    sizeof(binat.src.addr));
				free(yystack.l_mark[-5].v.host);
			}
			if (yystack.l_mark[-4].v.host != NULL) {
				if (yystack.l_mark[-4].v.host->next) {
					yyerror("multiple binat ip addresses");
					YYERROR;
				}
				if (yystack.l_mark[-4].v.host->af != binat.af && yystack.l_mark[-4].v.host->af) {
					yyerror("binat ip versions must match");
					YYERROR;
				}
				if (check_netmask(yystack.l_mark[-4].v.host, binat.af))
					YYERROR;
				memcpy(&binat.dst.addr, &yystack.l_mark[-4].v.host->addr,
				    sizeof(binat.dst.addr));
				binat.dst.neg = yystack.l_mark[-4].v.host->not;
				free(yystack.l_mark[-4].v.host);
			}

			if (binat.action == PF_NOBINAT) {
				if (yystack.l_mark[0].v.redirection != NULL) {
					yyerror("'no binat' rule does not need"
					    " '->'");
					YYERROR;
				}
			} else {
				if (yystack.l_mark[0].v.redirection == NULL || yystack.l_mark[0].v.redirection->host == NULL) {
					yyerror("'binat' rule requires"
					    " '-> address'");
					YYERROR;
				}

				remove_invalid_hosts(&yystack.l_mark[0].v.redirection->host, &binat.af);
				if (invalid_redirect(yystack.l_mark[0].v.redirection->host, binat.af))
					YYERROR;
				if (yystack.l_mark[0].v.redirection->host->next != NULL) {
					yyerror("binat rule must redirect to "
					    "a single address");
					YYERROR;
				}
				if (check_netmask(yystack.l_mark[0].v.redirection->host, binat.af))
					YYERROR;

				if (!PF_AZERO(&binat.src.addr.v.a.mask,
				    binat.af) &&
				    !PF_AEQ(&binat.src.addr.v.a.mask,
				    &yystack.l_mark[0].v.redirection->host->addr.v.a.mask, binat.af)) {
					yyerror("'binat' source mask and "
					    "redirect mask must be the same");
					YYERROR;
				}

				TAILQ_INIT(&binat.rpool.list);
				pa = calloc(1, sizeof(struct pf_pooladdr));
				if (pa == NULL)
					err(1, "binat: calloc");
				pa->addr = yystack.l_mark[0].v.redirection->host->addr;
				pa->ifname[0] = 0;
				TAILQ_INSERT_TAIL(&binat.rpool.list,
				    pa, entries);

				free(yystack.l_mark[0].v.redirection);
			}

			pfctl_add_rule(pf, &binat, "");
		}
break;
case 425:
#line 4495 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.string = NULL; }
break;
case 426:
#line 4496 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.string = yystack.l_mark[0].v.string; }
break;
case 427:
#line 4499 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.tagged.neg = 0; yyval.v.tagged.name = NULL; }
break;
case 428:
#line 4500 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.tagged.neg = yystack.l_mark[-2].v.number; yyval.v.tagged.name = yystack.l_mark[0].v.string; }
break;
case 429:
#line 4503 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.rtableid = -1; }
break;
case 430:
#line 4504 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > rt_tableid_max()) {
				yyerror("invalid rtable id");
				YYERROR;
			}
			yyval.v.rtableid = yystack.l_mark[0].v.number;
		}
break;
case 431:
#line 4513 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.host = calloc(1, sizeof(struct node_host));
			if (yyval.v.host == NULL)
				err(1, "route_host: calloc");
			yyval.v.host->ifname = yystack.l_mark[0].v.string;
			set_ipmask(yyval.v.host, 128);
			yyval.v.host->next = NULL;
			yyval.v.host->tail = yyval.v.host;
		}
break;
case 432:
#line 4522 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			struct node_host *n;

			yyval.v.host = yystack.l_mark[-1].v.host;
			for (n = yystack.l_mark[-1].v.host; n != NULL; n = n->next)
				n->ifname = yystack.l_mark[-2].v.string;
		}
break;
case 433:
#line 4531 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[-1].v.host; }
break;
case 434:
#line 4532 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-3].v.host->af == 0)
				yystack.l_mark[-3].v.host->af = yystack.l_mark[-1].v.host->af;
			if (yystack.l_mark[-3].v.host->af != yystack.l_mark[-1].v.host->af) {
				yyerror("all pool addresses must be in the "
				    "same address family");
				YYERROR;
			}
			yystack.l_mark[-3].v.host->tail->next = yystack.l_mark[-1].v.host;
			yystack.l_mark[-3].v.host->tail = yystack.l_mark[-1].v.host->tail;
			yyval.v.host = yystack.l_mark[-3].v.host;
		}
break;
case 435:
#line 4546 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[0].v.host; }
break;
case 436:
#line 4547 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[-1].v.host; }
break;
case 437:
#line 4550 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.route.host = NULL;
			yyval.v.route.rt = 0;
			yyval.v.route.pool_opts = 0;
		}
break;
case 438:
#line 4555 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.route.host = NULL;
			yyval.v.route.rt = PF_FASTROUTE;
			yyval.v.route.pool_opts = 0;
		}
break;
case 439:
#line 4560 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.route.host = yystack.l_mark[-1].v.host;
			yyval.v.route.rt = PF_ROUTETO;
			yyval.v.route.pool_opts = yystack.l_mark[0].v.pool_opts.type | yystack.l_mark[0].v.pool_opts.opts;
			if (yystack.l_mark[0].v.pool_opts.key != NULL)
				yyval.v.route.key = yystack.l_mark[0].v.pool_opts.key;
		}
break;
case 440:
#line 4567 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.route.host = yystack.l_mark[-1].v.host;
			yyval.v.route.rt = PF_REPLYTO;
			yyval.v.route.pool_opts = yystack.l_mark[0].v.pool_opts.type | yystack.l_mark[0].v.pool_opts.opts;
			if (yystack.l_mark[0].v.pool_opts.key != NULL)
				yyval.v.route.key = yystack.l_mark[0].v.pool_opts.key;
		}
break;
case 441:
#line 4574 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			yyval.v.route.host = yystack.l_mark[-1].v.host;
			yyval.v.route.rt = PF_DUPTO;
			yyval.v.route.pool_opts = yystack.l_mark[0].v.pool_opts.type | yystack.l_mark[0].v.pool_opts.opts;
			if (yystack.l_mark[0].v.pool_opts.key != NULL)
				yyval.v.route.key = yystack.l_mark[0].v.pool_opts.key;
		}
break;
case 442:
#line 4584 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (check_rulestate(PFCTL_STATE_OPTION)) {
				free(yystack.l_mark[-1].v.string);
				YYERROR;
			}
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			if (pfctl_set_timeout(pf, yystack.l_mark[-1].v.string, yystack.l_mark[0].v.number, 0) != 0) {
				yyerror("unknown timeout %s", yystack.l_mark[-1].v.string);
				free(yystack.l_mark[-1].v.string);
				YYERROR;
			}
			free(yystack.l_mark[-1].v.string);
		}
break;
case 443:
#line 4600 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (check_rulestate(PFCTL_STATE_OPTION))
				YYERROR;
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			if (pfctl_set_timeout(pf, "interval", yystack.l_mark[0].v.number, 0) != 0)
				YYERROR;
		}
break;
case 446:
#line 4617 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (check_rulestate(PFCTL_STATE_OPTION)) {
				free(yystack.l_mark[-1].v.string);
				YYERROR;
			}
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			if (pfctl_set_limit(pf, yystack.l_mark[-1].v.string, yystack.l_mark[0].v.number) != 0) {
				yyerror("unable to set limit %s %u", yystack.l_mark[-1].v.string, yystack.l_mark[0].v.number);
				free(yystack.l_mark[-1].v.string);
				YYERROR;
			}
			free(yystack.l_mark[-1].v.string);
		}
break;
case 451:
#line 4643 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.number = 0; }
break;
case 452:
#line 4644 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "yes"))
				yyval.v.number = 1;
			else {
				yyerror("invalid value '%s', expected 'yes' "
				    "or 'no'", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 453:
#line 4657 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_OP_EQ; }
break;
case 454:
#line 4658 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_OP_NE; }
break;
case 455:
#line 4659 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_OP_LE; }
break;
case 456:
#line 4660 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_OP_LT; }
break;
case 457:
#line 4661 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_OP_GE; }
break;
case 458:
#line 4662 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_OP_GT; }
break;
#line 9547 "parse.c"
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
