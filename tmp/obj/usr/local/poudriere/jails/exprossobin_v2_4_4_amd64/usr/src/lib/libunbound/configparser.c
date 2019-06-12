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
#define yyparse    ub_c_parse
#endif /* yyparse */

#ifndef yylex
#define yylex      ub_c_lex
#endif /* yylex */

#ifndef yyerror
#define yyerror    ub_c_error
#endif /* yyerror */

#ifndef yychar
#define yychar     ub_c_char
#endif /* yychar */

#ifndef yyval
#define yyval      ub_c_val
#endif /* yyval */

#ifndef yylval
#define yylval     ub_c_lval
#endif /* yylval */

#ifndef yydebug
#define yydebug    ub_c_debug
#endif /* yydebug */

#ifndef yynerrs
#define yynerrs    ub_c_nerrs
#endif /* yynerrs */

#ifndef yyerrflag
#define yyerrflag  ub_c_errflag
#endif /* yyerrflag */

#ifndef yylhs
#define yylhs      ub_c_lhs
#endif /* yylhs */

#ifndef yylen
#define yylen      ub_c_len
#endif /* yylen */

#ifndef yydefred
#define yydefred   ub_c_defred
#endif /* yydefred */

#ifndef yydgoto
#define yydgoto    ub_c_dgoto
#endif /* yydgoto */

#ifndef yysindex
#define yysindex   ub_c_sindex
#endif /* yysindex */

#ifndef yyrindex
#define yyrindex   ub_c_rindex
#endif /* yyrindex */

#ifndef yygindex
#define yygindex   ub_c_gindex
#endif /* yygindex */

#ifndef yytable
#define yytable    ub_c_table
#endif /* yytable */

#ifndef yycheck
#define yycheck    ub_c_check
#endif /* yycheck */

#ifndef yyname
#define yyname     ub_c_name
#endif /* yyname */

#ifndef yyrule
#define yyrule     ub_c_rule
#endif /* yyrule */
#define YYPREFIX "ub_c_"

#define YYPURE 0

#line 39 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
#include "config.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "util/configyyrename.h"
#include "util/config_file.h"
#include "util/net_help.h"

int ub_c_lex(void);
void ub_c_error(const char *message);

/* these need to be global, otherwise they cannot be used inside yacc */
extern struct config_parser_state* cfg_parser;

#if 0
#define OUTYY(s)  printf s /* used ONLY when debugging */
#else
#define OUTYY(s)
#endif

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 64 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
typedef union {
	char*	str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 137 "configparser.c"

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

#define SPACE 257
#define LETTER 258
#define NEWLINE 259
#define COMMENT 260
#define COLON 261
#define ANY 262
#define ZONESTR 263
#define STRING_ARG 264
#define VAR_SERVER 265
#define VAR_VERBOSITY 266
#define VAR_NUM_THREADS 267
#define VAR_PORT 268
#define VAR_OUTGOING_RANGE 269
#define VAR_INTERFACE 270
#define VAR_DO_IP4 271
#define VAR_DO_IP6 272
#define VAR_PREFER_IP6 273
#define VAR_DO_UDP 274
#define VAR_DO_TCP 275
#define VAR_TCP_MSS 276
#define VAR_OUTGOING_TCP_MSS 277
#define VAR_CHROOT 278
#define VAR_USERNAME 279
#define VAR_DIRECTORY 280
#define VAR_LOGFILE 281
#define VAR_PIDFILE 282
#define VAR_MSG_CACHE_SIZE 283
#define VAR_MSG_CACHE_SLABS 284
#define VAR_NUM_QUERIES_PER_THREAD 285
#define VAR_RRSET_CACHE_SIZE 286
#define VAR_RRSET_CACHE_SLABS 287
#define VAR_OUTGOING_NUM_TCP 288
#define VAR_INFRA_HOST_TTL 289
#define VAR_INFRA_LAME_TTL 290
#define VAR_INFRA_CACHE_SLABS 291
#define VAR_INFRA_CACHE_NUMHOSTS 292
#define VAR_INFRA_CACHE_LAME_SIZE 293
#define VAR_NAME 294
#define VAR_STUB_ZONE 295
#define VAR_STUB_HOST 296
#define VAR_STUB_ADDR 297
#define VAR_TARGET_FETCH_POLICY 298
#define VAR_HARDEN_SHORT_BUFSIZE 299
#define VAR_HARDEN_LARGE_QUERIES 300
#define VAR_FORWARD_ZONE 301
#define VAR_FORWARD_HOST 302
#define VAR_FORWARD_ADDR 303
#define VAR_DO_NOT_QUERY_ADDRESS 304
#define VAR_HIDE_IDENTITY 305
#define VAR_HIDE_VERSION 306
#define VAR_IDENTITY 307
#define VAR_VERSION 308
#define VAR_HARDEN_GLUE 309
#define VAR_MODULE_CONF 310
#define VAR_TRUST_ANCHOR_FILE 311
#define VAR_TRUST_ANCHOR 312
#define VAR_VAL_OVERRIDE_DATE 313
#define VAR_BOGUS_TTL 314
#define VAR_VAL_CLEAN_ADDITIONAL 315
#define VAR_VAL_PERMISSIVE_MODE 316
#define VAR_INCOMING_NUM_TCP 317
#define VAR_MSG_BUFFER_SIZE 318
#define VAR_KEY_CACHE_SIZE 319
#define VAR_KEY_CACHE_SLABS 320
#define VAR_TRUSTED_KEYS_FILE 321
#define VAR_VAL_NSEC3_KEYSIZE_ITERATIONS 322
#define VAR_USE_SYSLOG 323
#define VAR_OUTGOING_INTERFACE 324
#define VAR_ROOT_HINTS 325
#define VAR_DO_NOT_QUERY_LOCALHOST 326
#define VAR_CACHE_MAX_TTL 327
#define VAR_HARDEN_DNSSEC_STRIPPED 328
#define VAR_ACCESS_CONTROL 329
#define VAR_LOCAL_ZONE 330
#define VAR_LOCAL_DATA 331
#define VAR_INTERFACE_AUTOMATIC 332
#define VAR_STATISTICS_INTERVAL 333
#define VAR_DO_DAEMONIZE 334
#define VAR_USE_CAPS_FOR_ID 335
#define VAR_STATISTICS_CUMULATIVE 336
#define VAR_OUTGOING_PORT_PERMIT 337
#define VAR_OUTGOING_PORT_AVOID 338
#define VAR_DLV_ANCHOR_FILE 339
#define VAR_DLV_ANCHOR 340
#define VAR_NEG_CACHE_SIZE 341
#define VAR_HARDEN_REFERRAL_PATH 342
#define VAR_PRIVATE_ADDRESS 343
#define VAR_PRIVATE_DOMAIN 344
#define VAR_REMOTE_CONTROL 345
#define VAR_CONTROL_ENABLE 346
#define VAR_CONTROL_INTERFACE 347
#define VAR_CONTROL_PORT 348
#define VAR_SERVER_KEY_FILE 349
#define VAR_SERVER_CERT_FILE 350
#define VAR_CONTROL_KEY_FILE 351
#define VAR_CONTROL_CERT_FILE 352
#define VAR_CONTROL_USE_CERT 353
#define VAR_EXTENDED_STATISTICS 354
#define VAR_LOCAL_DATA_PTR 355
#define VAR_JOSTLE_TIMEOUT 356
#define VAR_STUB_PRIME 357
#define VAR_UNWANTED_REPLY_THRESHOLD 358
#define VAR_LOG_TIME_ASCII 359
#define VAR_DOMAIN_INSECURE 360
#define VAR_PYTHON 361
#define VAR_PYTHON_SCRIPT 362
#define VAR_VAL_SIG_SKEW_MIN 363
#define VAR_VAL_SIG_SKEW_MAX 364
#define VAR_CACHE_MIN_TTL 365
#define VAR_VAL_LOG_LEVEL 366
#define VAR_AUTO_TRUST_ANCHOR_FILE 367
#define VAR_KEEP_MISSING 368
#define VAR_ADD_HOLDDOWN 369
#define VAR_DEL_HOLDDOWN 370
#define VAR_SO_RCVBUF 371
#define VAR_EDNS_BUFFER_SIZE 372
#define VAR_PREFETCH 373
#define VAR_PREFETCH_KEY 374
#define VAR_SO_SNDBUF 375
#define VAR_SO_REUSEPORT 376
#define VAR_HARDEN_BELOW_NXDOMAIN 377
#define VAR_IGNORE_CD_FLAG 378
#define VAR_LOG_QUERIES 379
#define VAR_TCP_UPSTREAM 380
#define VAR_SSL_UPSTREAM 381
#define VAR_SSL_SERVICE_KEY 382
#define VAR_SSL_SERVICE_PEM 383
#define VAR_SSL_PORT 384
#define VAR_FORWARD_FIRST 385
#define VAR_STUB_FIRST 386
#define VAR_MINIMAL_RESPONSES 387
#define VAR_RRSET_ROUNDROBIN 388
#define VAR_MAX_UDP_SIZE 389
#define VAR_DELAY_CLOSE 390
#define VAR_UNBLOCK_LAN_ZONES 391
#define VAR_INSECURE_LAN_ZONES 392
#define VAR_INFRA_CACHE_MIN_RTT 393
#define VAR_DNS64_PREFIX 394
#define VAR_DNS64_SYNTHALL 395
#define VAR_DNSTAP 396
#define VAR_DNSTAP_ENABLE 397
#define VAR_DNSTAP_SOCKET_PATH 398
#define VAR_DNSTAP_SEND_IDENTITY 399
#define VAR_DNSTAP_SEND_VERSION 400
#define VAR_DNSTAP_IDENTITY 401
#define VAR_DNSTAP_VERSION 402
#define VAR_DNSTAP_LOG_RESOLVER_QUERY_MESSAGES 403
#define VAR_DNSTAP_LOG_RESOLVER_RESPONSE_MESSAGES 404
#define VAR_DNSTAP_LOG_CLIENT_QUERY_MESSAGES 405
#define VAR_DNSTAP_LOG_CLIENT_RESPONSE_MESSAGES 406
#define VAR_DNSTAP_LOG_FORWARDER_QUERY_MESSAGES 407
#define VAR_DNSTAP_LOG_FORWARDER_RESPONSE_MESSAGES 408
#define VAR_HARDEN_ALGO_DOWNGRADE 409
#define VAR_IP_TRANSPARENT 410
#define VAR_DISABLE_DNSSEC_LAME_CHECK 411
#define VAR_RATELIMIT 412
#define VAR_RATELIMIT_SLABS 413
#define VAR_RATELIMIT_SIZE 414
#define VAR_RATELIMIT_FOR_DOMAIN 415
#define VAR_RATELIMIT_BELOW_DOMAIN 416
#define VAR_RATELIMIT_FACTOR 417
#define VAR_CAPS_WHITELIST 418
#define VAR_CACHE_MAX_NEGATIVE_TTL 419
#define VAR_PERMIT_SMALL_HOLDDOWN 420
#define VAR_QNAME_MINIMISATION 421
#define VAR_IP_FREEBIND 422
#define VAR_DEFINE_TAG 423
#define VAR_LOCAL_ZONE_TAG 424
#define VAR_ACCESS_CONTROL_TAG 425
#define VAR_LOCAL_ZONE_OVERRIDE 426
#define VAR_ACCESS_CONTROL_TAG_ACTION 427
#define VAR_ACCESS_CONTROL_TAG_DATA 428
#define YYERRCODE 256
typedef int YYINT;
static const YYINT ub_c_lhs[] = {                        -1,
    0,    0,    1,    1,    1,    1,    1,    1,    2,    3,
    3,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
    4,    5,    5,  144,  144,  144,  144,  144,    6,    7,
    7,  150,  150,  150,  150,   15,   16,   75,   78,   87,
   17,   26,   66,   18,   79,   80,   37,   59,   74,   19,
   20,   22,   23,   21,   24,   25,  109,  110,  111,  112,
  113,   76,   65,   91,  108,   27,   28,   29,   30,   31,
   67,   81,   82,   97,   53,   63,   54,   92,   47,   48,
   49,   50,  101,  105,  117,  125,  136,  102,   60,   32,
   33,   34,   89,  118,  119,  120,   35,   36,   38,   39,
   41,   42,   40,  123,   43,   44,   45,   51,   70,  106,
   84,  124,   77,  132,   85,   86,  103,  104,   90,   46,
   68,   71,   52,   55,   93,   94,   69,  133,   95,   56,
   57,   58,  107,   96,   64,   98,   99,  100,  134,   61,
   62,   83,   72,   73,   88,  114,  115,  116,  121,  122,
  137,  138,  140,  142,  143,  141,  126,  128,  127,  129,
  130,  131,  135,  145,  146,  147,  149,  148,  151,  152,
  153,  154,   10,   11,   11,  155,  155,  155,  155,  155,
  155,  155,  155,  156,  158,  157,  163,  159,  160,  161,
  162,   12,   13,   13,  164,  164,  164,  164,  164,  164,
  164,  164,  164,  164,  164,  164,  165,  166,  167,  168,
  169,  170,  171,  172,  173,  174,  175,  176,    8,    9,
    9,  177,  178,  139,
};
static const YYINT ub_c_len[] = {                         2,
    0,    2,    2,    2,    2,    2,    2,    2,    1,    2,
    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    2,    0,    1,    1,    1,    1,    1,    1,    2,
    0,    1,    1,    1,    1,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    3,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    3,    2,    2,    2,    2,    2,    2,    2,
    2,    3,    3,    4,    4,    4,    2,    2,    2,    3,
    3,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    1,    2,    0,    1,    1,    1,    1,    1,
    1,    1,    1,    2,    2,    2,    2,    2,    2,    2,
    2,    1,    2,    0,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    1,    2,
    0,    1,    2,    2,
};
static const YYINT ub_c_defred[] = {                      1,
    0,    9,  141,  149,  293,  339,  312,    2,   11,  143,
  151,  341,  295,  314,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,   10,
   12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,
   42,   43,   44,   45,   46,   47,   48,   49,   50,   51,
   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,
   62,   63,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   73,   74,   75,   76,   77,   78,   79,   80,   81,
   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,
   92,   93,   94,   95,   96,   97,   98,   99,  100,  101,
  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
  112,  113,  114,  115,  116,  117,  118,  119,  120,  121,
  122,  123,  124,  125,  126,  127,  128,  129,  130,  131,
  132,  133,  134,  135,  136,  137,  138,  139,  140,    0,
    0,    0,    0,    0,  142,  144,  145,  146,  147,  148,
    0,    0,    0,    0,  150,  152,  153,  154,  155,    0,
  340,  342,    0,    0,    0,    0,    0,    0,    0,    0,
  294,  296,  297,  298,  299,  300,  301,  302,  303,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  313,  315,  316,  317,  318,  319,  320,  321,  322,
  323,  324,  325,  326,  157,  156,  161,  164,  162,  170,
  171,  174,  172,  173,  175,  176,  186,  187,  188,  189,
  190,  210,  211,  212,  217,  218,  167,  219,  220,  223,
  221,  222,  225,  226,  227,  240,  199,  200,  201,  202,
  228,  243,  195,  197,  244,  250,  251,  252,  168,  209,
  260,  261,  196,  255,  183,  163,  191,  241,  247,  229,
    0,    0,  264,  169,  158,  182,  233,  159,  165,  166,
  192,  193,  262,  231,  235,  236,  160,  265,  213,  239,
  184,  198,  245,  246,  249,  254,  194,  258,  256,  257,
  203,  208,  237,  238,  204,  205,  230,  253,  185,  177,
  178,  179,  180,  181,  266,  267,  268,  214,  215,  216,
  224,  269,  270,  232,  206,  344,  277,  279,  278,    0,
    0,  282,  234,  248,  259,  283,  207,  271,    0,    0,
    0,    0,    0,  284,  285,  286,  288,  287,  289,  290,
  291,  292,  343,  304,  306,  305,  308,  309,  310,  311,
  307,  327,  328,  329,  330,  331,  332,  333,  334,  335,
  336,  337,  338,  242,  263,  280,  281,  272,  273,    0,
    0,    0,  276,  274,  275,
};
static const YYINT ub_c_dgoto[] = {                       1,
    8,    9,   15,   10,   16,   11,   17,   12,   18,   13,
   19,   14,   20,  150,  151,  152,  153,  154,  155,  156,
  157,  158,  159,  160,  161,  162,  163,  164,  165,  166,
  167,  168,  169,  170,  171,  172,  173,  174,  175,  176,
  177,  178,  179,  180,  181,  182,  183,  184,  185,  186,
  187,  188,  189,  190,  191,  192,  193,  194,  195,  196,
  197,  198,  199,  200,  201,  202,  203,  204,  205,  206,
  207,  208,  209,  210,  211,  212,  213,  214,  215,  216,
  217,  218,  219,  220,  221,  222,  223,  224,  225,  226,
  227,  228,  229,  230,  231,  232,  233,  234,  235,  236,
  237,  238,  239,  240,  241,  242,  243,  244,  245,  246,
  247,  248,  249,  250,  251,  252,  253,  254,  255,  256,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  285,  286,  287,  288,  289,  290,  295,
  296,  297,  298,  299,  311,  312,  313,  314,  315,  316,
  317,  318,  319,  332,  333,  334,  335,  336,  337,  338,
  339,  340,  341,  342,  343,  344,  301,  302,
};
static const YYINT ub_c_sindex[] = {                      0,
 -124,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -259, -208, -200, -362, -148, -211,
 -229, -228, -227, -226, -222, -221, -220, -177, -174, -173,
 -172, -171, -166, -138, -137, -127, -126, -125, -122, -121,
 -120, -119, -118, -117, -116,  -94,  -92,  -91,  -90,  -89,
  -88,  -85,  -84,  -83,  -82,  -81,  -80,  -58,  -57,  -56,
  -55,  -54,  -53,  -52,  -51,  -50,  -49,  -48,  -47,  -46,
  -45,  -44,  -42,  -41,  -40,  -39,  -38,  -37,  -36,  -35,
  -34,  -33,  -32,  -31,  -30,  -29,  -28,  -26,  -25,  -24,
  -23,  -22,  -21,  -20,  -19,  -18,  -17,  -16,  -15,  -14,
  -13,  -12,  -11,  -10,   -9,   -8,   -7,   -6,   -5,   -4,
   -3,   -2,   -1,    9,   10,   11,   12,   13,   14,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,
   26,   27,   28,   29,   30,   31,   44,   45,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,   57,
   58,   59,   60,   61,    0,    0,    0,    0,    0,    0,
   62,   63,   64,   65,    0,    0,    0,    0,    0,   66,
    0,    0,   67,   68,   69,   70,   71,   72,   73,   74,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   75,
   76,   77,   78,   79,   80,   81,   88,   89,   90,   91,
   92,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   93,   94,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   95,
   96,    0,    0,    0,    0,    0,    0,    0,   97,  104,
  105,  106,  107,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  108,
  109,  110,    0,    0,    0,
};
static const YYINT ub_c_rindex[] = {                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    1,    2,    3,    4,    5,    6,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT ub_c_gindex[] = {                      0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 402
static const YYINT ub_c_table[] = {                     300,
    3,    4,    5,    6,    7,    8,   21,   22,   23,   24,
   25,   26,   27,   28,   29,   30,   31,   32,   33,   34,
   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,
   45,   46,   47,   48,  345,  346,  347,  348,   49,   50,
   51,  349,  350,  351,   52,   53,   54,   55,   56,   57,
   58,   59,   60,   61,   62,   63,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
   78,   79,   80,   81,   82,   83,   84,   85,   86,   87,
   88,   89,   90,   91,   92,  280,  352,  281,  282,  353,
  354,  355,  356,  291,   93,   94,   95,  357,   96,   97,
   98,  292,  293,   99,  100,  101,  102,  103,  104,  105,
  106,  107,  108,  109,  110,  111,  112,  113,  114,  115,
  116,  117,  118,  119,  120,  358,  359,  121,  122,  123,
  124,  125,  126,  127,  128,  129,  360,  361,  362,    0,
    2,  363,  364,  365,  366,  367,  368,  369,  283,  130,
  131,  132,  133,  134,  135,  136,  137,  138,  139,  140,
  141,  142,  143,  144,  145,  146,  147,  148,  149,  370,
    3,  371,  372,  373,  374,  375,    4,  284,  376,  377,
  378,  379,  380,  381,  294,  320,  321,  322,  323,  324,
  325,  326,  327,  328,  329,  330,  331,  303,  304,  305,
  306,  307,  308,  309,  310,  382,  383,  384,  385,  386,
  387,  388,  389,  390,  391,  392,  393,  394,  395,  396,
    5,  397,  398,  399,  400,  401,  402,  403,  404,  405,
  406,  407,  408,  409,  410,  411,    6,  412,  413,  414,
  415,  416,  417,  418,  419,  420,  421,  422,  423,  424,
  425,  426,  427,  428,  429,  430,  431,  432,  433,  434,
  435,  436,  437,    0,    0,    3,    4,    5,    6,    7,
    8,    7,  438,  439,  440,  441,  442,  443,  444,  445,
  446,  447,  448,  449,  450,  451,  452,  453,  454,  455,
  456,  457,  458,  459,  460,    3,    4,    5,    6,    7,
    8,    3,    4,    5,    6,    7,    8,  461,  462,  463,
  464,  465,  466,  467,  468,  469,  470,  471,  472,  473,
  474,  475,  476,  477,  478,  479,  480,  481,  482,  483,
  484,  485,  486,  487,  488,  489,  490,  491,  492,  493,
  494,  495,  496,  497,  498,    3,    4,    5,    6,    7,
    8,  499,  500,  501,  502,  503,  504,  505,  506,  507,
  508,    3,    4,    5,    6,    7,    8,  509,  510,  511,
  512,  513,  514,  515,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,    4,    5,    6,
    7,    8,
};
static const YYINT ub_c_check[] = {                     362,
    0,    0,    0,    0,    0,    0,  266,  267,  268,  269,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
  280,  281,  282,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  292,  293,  264,  264,  264,  264,  298,  299,
  300,  264,  264,  264,  304,  305,  306,  307,  308,  309,
  310,  311,  312,  313,  314,  315,  316,  317,  318,  319,
  320,  321,  322,  323,  324,  325,  326,  327,  328,  329,
  330,  331,  332,  333,  334,  335,  336,  337,  338,  339,
  340,  341,  342,  343,  344,  294,  264,  296,  297,  264,
  264,  264,  264,  294,  354,  355,  356,  264,  358,  359,
  360,  302,  303,  363,  364,  365,  366,  367,  368,  369,
  370,  371,  372,  373,  374,  375,  376,  377,  378,  379,
  380,  381,  382,  383,  384,  264,  264,  387,  388,  389,
  390,  391,  392,  393,  394,  395,  264,  264,  264,   -1,
  265,  264,  264,  264,  264,  264,  264,  264,  357,  409,
  410,  411,  412,  413,  414,  415,  416,  417,  418,  419,
  420,  421,  422,  423,  424,  425,  426,  427,  428,  264,
  295,  264,  264,  264,  264,  264,  301,  386,  264,  264,
  264,  264,  264,  264,  385,  397,  398,  399,  400,  401,
  402,  403,  404,  405,  406,  407,  408,  346,  347,  348,
  349,  350,  351,  352,  353,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  345,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  361,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,   -1,   -1,  265,  265,  265,  265,  265,
  265,  396,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  295,  295,  295,  295,  295,
  295,  301,  301,  301,  301,  301,  301,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  264,  264,  264,  264,  345,  345,  345,  345,  345,
  345,  264,  264,  264,  264,  264,  264,  264,  264,  264,
  264,  361,  361,  361,  361,  361,  361,  264,  264,  264,
  264,  264,  264,  264,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  396,  396,  396,  396,
  396,  396,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 428
#define YYUNDFTOKEN 609
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const ub_c_name[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SPACE","LETTER","NEWLINE",
"COMMENT","COLON","ANY","ZONESTR","STRING_ARG","VAR_SERVER","VAR_VERBOSITY",
"VAR_NUM_THREADS","VAR_PORT","VAR_OUTGOING_RANGE","VAR_INTERFACE","VAR_DO_IP4",
"VAR_DO_IP6","VAR_PREFER_IP6","VAR_DO_UDP","VAR_DO_TCP","VAR_TCP_MSS",
"VAR_OUTGOING_TCP_MSS","VAR_CHROOT","VAR_USERNAME","VAR_DIRECTORY",
"VAR_LOGFILE","VAR_PIDFILE","VAR_MSG_CACHE_SIZE","VAR_MSG_CACHE_SLABS",
"VAR_NUM_QUERIES_PER_THREAD","VAR_RRSET_CACHE_SIZE","VAR_RRSET_CACHE_SLABS",
"VAR_OUTGOING_NUM_TCP","VAR_INFRA_HOST_TTL","VAR_INFRA_LAME_TTL",
"VAR_INFRA_CACHE_SLABS","VAR_INFRA_CACHE_NUMHOSTS","VAR_INFRA_CACHE_LAME_SIZE",
"VAR_NAME","VAR_STUB_ZONE","VAR_STUB_HOST","VAR_STUB_ADDR",
"VAR_TARGET_FETCH_POLICY","VAR_HARDEN_SHORT_BUFSIZE","VAR_HARDEN_LARGE_QUERIES",
"VAR_FORWARD_ZONE","VAR_FORWARD_HOST","VAR_FORWARD_ADDR",
"VAR_DO_NOT_QUERY_ADDRESS","VAR_HIDE_IDENTITY","VAR_HIDE_VERSION",
"VAR_IDENTITY","VAR_VERSION","VAR_HARDEN_GLUE","VAR_MODULE_CONF",
"VAR_TRUST_ANCHOR_FILE","VAR_TRUST_ANCHOR","VAR_VAL_OVERRIDE_DATE",
"VAR_BOGUS_TTL","VAR_VAL_CLEAN_ADDITIONAL","VAR_VAL_PERMISSIVE_MODE",
"VAR_INCOMING_NUM_TCP","VAR_MSG_BUFFER_SIZE","VAR_KEY_CACHE_SIZE",
"VAR_KEY_CACHE_SLABS","VAR_TRUSTED_KEYS_FILE",
"VAR_VAL_NSEC3_KEYSIZE_ITERATIONS","VAR_USE_SYSLOG","VAR_OUTGOING_INTERFACE",
"VAR_ROOT_HINTS","VAR_DO_NOT_QUERY_LOCALHOST","VAR_CACHE_MAX_TTL",
"VAR_HARDEN_DNSSEC_STRIPPED","VAR_ACCESS_CONTROL","VAR_LOCAL_ZONE",
"VAR_LOCAL_DATA","VAR_INTERFACE_AUTOMATIC","VAR_STATISTICS_INTERVAL",
"VAR_DO_DAEMONIZE","VAR_USE_CAPS_FOR_ID","VAR_STATISTICS_CUMULATIVE",
"VAR_OUTGOING_PORT_PERMIT","VAR_OUTGOING_PORT_AVOID","VAR_DLV_ANCHOR_FILE",
"VAR_DLV_ANCHOR","VAR_NEG_CACHE_SIZE","VAR_HARDEN_REFERRAL_PATH",
"VAR_PRIVATE_ADDRESS","VAR_PRIVATE_DOMAIN","VAR_REMOTE_CONTROL",
"VAR_CONTROL_ENABLE","VAR_CONTROL_INTERFACE","VAR_CONTROL_PORT",
"VAR_SERVER_KEY_FILE","VAR_SERVER_CERT_FILE","VAR_CONTROL_KEY_FILE",
"VAR_CONTROL_CERT_FILE","VAR_CONTROL_USE_CERT","VAR_EXTENDED_STATISTICS",
"VAR_LOCAL_DATA_PTR","VAR_JOSTLE_TIMEOUT","VAR_STUB_PRIME",
"VAR_UNWANTED_REPLY_THRESHOLD","VAR_LOG_TIME_ASCII","VAR_DOMAIN_INSECURE",
"VAR_PYTHON","VAR_PYTHON_SCRIPT","VAR_VAL_SIG_SKEW_MIN","VAR_VAL_SIG_SKEW_MAX",
"VAR_CACHE_MIN_TTL","VAR_VAL_LOG_LEVEL","VAR_AUTO_TRUST_ANCHOR_FILE",
"VAR_KEEP_MISSING","VAR_ADD_HOLDDOWN","VAR_DEL_HOLDDOWN","VAR_SO_RCVBUF",
"VAR_EDNS_BUFFER_SIZE","VAR_PREFETCH","VAR_PREFETCH_KEY","VAR_SO_SNDBUF",
"VAR_SO_REUSEPORT","VAR_HARDEN_BELOW_NXDOMAIN","VAR_IGNORE_CD_FLAG",
"VAR_LOG_QUERIES","VAR_TCP_UPSTREAM","VAR_SSL_UPSTREAM","VAR_SSL_SERVICE_KEY",
"VAR_SSL_SERVICE_PEM","VAR_SSL_PORT","VAR_FORWARD_FIRST","VAR_STUB_FIRST",
"VAR_MINIMAL_RESPONSES","VAR_RRSET_ROUNDROBIN","VAR_MAX_UDP_SIZE",
"VAR_DELAY_CLOSE","VAR_UNBLOCK_LAN_ZONES","VAR_INSECURE_LAN_ZONES",
"VAR_INFRA_CACHE_MIN_RTT","VAR_DNS64_PREFIX","VAR_DNS64_SYNTHALL","VAR_DNSTAP",
"VAR_DNSTAP_ENABLE","VAR_DNSTAP_SOCKET_PATH","VAR_DNSTAP_SEND_IDENTITY",
"VAR_DNSTAP_SEND_VERSION","VAR_DNSTAP_IDENTITY","VAR_DNSTAP_VERSION",
"VAR_DNSTAP_LOG_RESOLVER_QUERY_MESSAGES",
"VAR_DNSTAP_LOG_RESOLVER_RESPONSE_MESSAGES",
"VAR_DNSTAP_LOG_CLIENT_QUERY_MESSAGES",
"VAR_DNSTAP_LOG_CLIENT_RESPONSE_MESSAGES",
"VAR_DNSTAP_LOG_FORWARDER_QUERY_MESSAGES",
"VAR_DNSTAP_LOG_FORWARDER_RESPONSE_MESSAGES","VAR_HARDEN_ALGO_DOWNGRADE",
"VAR_IP_TRANSPARENT","VAR_DISABLE_DNSSEC_LAME_CHECK","VAR_RATELIMIT",
"VAR_RATELIMIT_SLABS","VAR_RATELIMIT_SIZE","VAR_RATELIMIT_FOR_DOMAIN",
"VAR_RATELIMIT_BELOW_DOMAIN","VAR_RATELIMIT_FACTOR","VAR_CAPS_WHITELIST",
"VAR_CACHE_MAX_NEGATIVE_TTL","VAR_PERMIT_SMALL_HOLDDOWN",
"VAR_QNAME_MINIMISATION","VAR_IP_FREEBIND","VAR_DEFINE_TAG",
"VAR_LOCAL_ZONE_TAG","VAR_ACCESS_CONTROL_TAG","VAR_LOCAL_ZONE_OVERRIDE",
"VAR_ACCESS_CONTROL_TAG_ACTION","VAR_ACCESS_CONTROL_TAG_DATA",0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const ub_c_rule[] = {
"$accept : toplevelvars",
"toplevelvars :",
"toplevelvars : toplevelvars toplevelvar",
"toplevelvar : serverstart contents_server",
"toplevelvar : stubstart contents_stub",
"toplevelvar : forwardstart contents_forward",
"toplevelvar : pythonstart contents_py",
"toplevelvar : rcstart contents_rc",
"toplevelvar : dtstart contents_dt",
"serverstart : VAR_SERVER",
"contents_server : contents_server content_server",
"contents_server :",
"content_server : server_num_threads",
"content_server : server_verbosity",
"content_server : server_port",
"content_server : server_outgoing_range",
"content_server : server_do_ip4",
"content_server : server_do_ip6",
"content_server : server_prefer_ip6",
"content_server : server_do_udp",
"content_server : server_do_tcp",
"content_server : server_tcp_mss",
"content_server : server_outgoing_tcp_mss",
"content_server : server_interface",
"content_server : server_chroot",
"content_server : server_username",
"content_server : server_directory",
"content_server : server_logfile",
"content_server : server_pidfile",
"content_server : server_msg_cache_size",
"content_server : server_msg_cache_slabs",
"content_server : server_num_queries_per_thread",
"content_server : server_rrset_cache_size",
"content_server : server_rrset_cache_slabs",
"content_server : server_outgoing_num_tcp",
"content_server : server_infra_host_ttl",
"content_server : server_infra_lame_ttl",
"content_server : server_infra_cache_slabs",
"content_server : server_infra_cache_numhosts",
"content_server : server_infra_cache_lame_size",
"content_server : server_target_fetch_policy",
"content_server : server_harden_short_bufsize",
"content_server : server_harden_large_queries",
"content_server : server_do_not_query_address",
"content_server : server_hide_identity",
"content_server : server_hide_version",
"content_server : server_identity",
"content_server : server_version",
"content_server : server_harden_glue",
"content_server : server_module_conf",
"content_server : server_trust_anchor_file",
"content_server : server_trust_anchor",
"content_server : server_val_override_date",
"content_server : server_bogus_ttl",
"content_server : server_val_clean_additional",
"content_server : server_val_permissive_mode",
"content_server : server_incoming_num_tcp",
"content_server : server_msg_buffer_size",
"content_server : server_key_cache_size",
"content_server : server_key_cache_slabs",
"content_server : server_trusted_keys_file",
"content_server : server_val_nsec3_keysize_iterations",
"content_server : server_use_syslog",
"content_server : server_outgoing_interface",
"content_server : server_root_hints",
"content_server : server_do_not_query_localhost",
"content_server : server_cache_max_ttl",
"content_server : server_harden_dnssec_stripped",
"content_server : server_access_control",
"content_server : server_local_zone",
"content_server : server_local_data",
"content_server : server_interface_automatic",
"content_server : server_statistics_interval",
"content_server : server_do_daemonize",
"content_server : server_use_caps_for_id",
"content_server : server_statistics_cumulative",
"content_server : server_outgoing_port_permit",
"content_server : server_outgoing_port_avoid",
"content_server : server_dlv_anchor_file",
"content_server : server_dlv_anchor",
"content_server : server_neg_cache_size",
"content_server : server_harden_referral_path",
"content_server : server_private_address",
"content_server : server_private_domain",
"content_server : server_extended_statistics",
"content_server : server_local_data_ptr",
"content_server : server_jostle_timeout",
"content_server : server_unwanted_reply_threshold",
"content_server : server_log_time_ascii",
"content_server : server_domain_insecure",
"content_server : server_val_sig_skew_min",
"content_server : server_val_sig_skew_max",
"content_server : server_cache_min_ttl",
"content_server : server_val_log_level",
"content_server : server_auto_trust_anchor_file",
"content_server : server_add_holddown",
"content_server : server_del_holddown",
"content_server : server_keep_missing",
"content_server : server_so_rcvbuf",
"content_server : server_edns_buffer_size",
"content_server : server_prefetch",
"content_server : server_prefetch_key",
"content_server : server_so_sndbuf",
"content_server : server_harden_below_nxdomain",
"content_server : server_ignore_cd_flag",
"content_server : server_log_queries",
"content_server : server_tcp_upstream",
"content_server : server_ssl_upstream",
"content_server : server_ssl_service_key",
"content_server : server_ssl_service_pem",
"content_server : server_ssl_port",
"content_server : server_minimal_responses",
"content_server : server_rrset_roundrobin",
"content_server : server_max_udp_size",
"content_server : server_so_reuseport",
"content_server : server_delay_close",
"content_server : server_unblock_lan_zones",
"content_server : server_insecure_lan_zones",
"content_server : server_dns64_prefix",
"content_server : server_dns64_synthall",
"content_server : server_infra_cache_min_rtt",
"content_server : server_harden_algo_downgrade",
"content_server : server_ip_transparent",
"content_server : server_ratelimit",
"content_server : server_ratelimit_slabs",
"content_server : server_ratelimit_size",
"content_server : server_ratelimit_for_domain",
"content_server : server_ratelimit_below_domain",
"content_server : server_ratelimit_factor",
"content_server : server_caps_whitelist",
"content_server : server_cache_max_negative_ttl",
"content_server : server_permit_small_holddown",
"content_server : server_qname_minimisation",
"content_server : server_ip_freebind",
"content_server : server_define_tag",
"content_server : server_local_zone_tag",
"content_server : server_disable_dnssec_lame_check",
"content_server : server_access_control_tag",
"content_server : server_local_zone_override",
"content_server : server_access_control_tag_action",
"content_server : server_access_control_tag_data",
"stubstart : VAR_STUB_ZONE",
"contents_stub : contents_stub content_stub",
"contents_stub :",
"content_stub : stub_name",
"content_stub : stub_host",
"content_stub : stub_addr",
"content_stub : stub_prime",
"content_stub : stub_first",
"forwardstart : VAR_FORWARD_ZONE",
"contents_forward : contents_forward content_forward",
"contents_forward :",
"content_forward : forward_name",
"content_forward : forward_host",
"content_forward : forward_addr",
"content_forward : forward_first",
"server_num_threads : VAR_NUM_THREADS STRING_ARG",
"server_verbosity : VAR_VERBOSITY STRING_ARG",
"server_statistics_interval : VAR_STATISTICS_INTERVAL STRING_ARG",
"server_statistics_cumulative : VAR_STATISTICS_CUMULATIVE STRING_ARG",
"server_extended_statistics : VAR_EXTENDED_STATISTICS STRING_ARG",
"server_port : VAR_PORT STRING_ARG",
"server_interface : VAR_INTERFACE STRING_ARG",
"server_outgoing_interface : VAR_OUTGOING_INTERFACE STRING_ARG",
"server_outgoing_range : VAR_OUTGOING_RANGE STRING_ARG",
"server_outgoing_port_permit : VAR_OUTGOING_PORT_PERMIT STRING_ARG",
"server_outgoing_port_avoid : VAR_OUTGOING_PORT_AVOID STRING_ARG",
"server_outgoing_num_tcp : VAR_OUTGOING_NUM_TCP STRING_ARG",
"server_incoming_num_tcp : VAR_INCOMING_NUM_TCP STRING_ARG",
"server_interface_automatic : VAR_INTERFACE_AUTOMATIC STRING_ARG",
"server_do_ip4 : VAR_DO_IP4 STRING_ARG",
"server_do_ip6 : VAR_DO_IP6 STRING_ARG",
"server_do_udp : VAR_DO_UDP STRING_ARG",
"server_do_tcp : VAR_DO_TCP STRING_ARG",
"server_prefer_ip6 : VAR_PREFER_IP6 STRING_ARG",
"server_tcp_mss : VAR_TCP_MSS STRING_ARG",
"server_outgoing_tcp_mss : VAR_OUTGOING_TCP_MSS STRING_ARG",
"server_tcp_upstream : VAR_TCP_UPSTREAM STRING_ARG",
"server_ssl_upstream : VAR_SSL_UPSTREAM STRING_ARG",
"server_ssl_service_key : VAR_SSL_SERVICE_KEY STRING_ARG",
"server_ssl_service_pem : VAR_SSL_SERVICE_PEM STRING_ARG",
"server_ssl_port : VAR_SSL_PORT STRING_ARG",
"server_do_daemonize : VAR_DO_DAEMONIZE STRING_ARG",
"server_use_syslog : VAR_USE_SYSLOG STRING_ARG",
"server_log_time_ascii : VAR_LOG_TIME_ASCII STRING_ARG",
"server_log_queries : VAR_LOG_QUERIES STRING_ARG",
"server_chroot : VAR_CHROOT STRING_ARG",
"server_username : VAR_USERNAME STRING_ARG",
"server_directory : VAR_DIRECTORY STRING_ARG",
"server_logfile : VAR_LOGFILE STRING_ARG",
"server_pidfile : VAR_PIDFILE STRING_ARG",
"server_root_hints : VAR_ROOT_HINTS STRING_ARG",
"server_dlv_anchor_file : VAR_DLV_ANCHOR_FILE STRING_ARG",
"server_dlv_anchor : VAR_DLV_ANCHOR STRING_ARG",
"server_auto_trust_anchor_file : VAR_AUTO_TRUST_ANCHOR_FILE STRING_ARG",
"server_trust_anchor_file : VAR_TRUST_ANCHOR_FILE STRING_ARG",
"server_trusted_keys_file : VAR_TRUSTED_KEYS_FILE STRING_ARG",
"server_trust_anchor : VAR_TRUST_ANCHOR STRING_ARG",
"server_domain_insecure : VAR_DOMAIN_INSECURE STRING_ARG",
"server_hide_identity : VAR_HIDE_IDENTITY STRING_ARG",
"server_hide_version : VAR_HIDE_VERSION STRING_ARG",
"server_identity : VAR_IDENTITY STRING_ARG",
"server_version : VAR_VERSION STRING_ARG",
"server_so_rcvbuf : VAR_SO_RCVBUF STRING_ARG",
"server_so_sndbuf : VAR_SO_SNDBUF STRING_ARG",
"server_so_reuseport : VAR_SO_REUSEPORT STRING_ARG",
"server_ip_transparent : VAR_IP_TRANSPARENT STRING_ARG",
"server_ip_freebind : VAR_IP_FREEBIND STRING_ARG",
"server_edns_buffer_size : VAR_EDNS_BUFFER_SIZE STRING_ARG",
"server_msg_buffer_size : VAR_MSG_BUFFER_SIZE STRING_ARG",
"server_msg_cache_size : VAR_MSG_CACHE_SIZE STRING_ARG",
"server_msg_cache_slabs : VAR_MSG_CACHE_SLABS STRING_ARG",
"server_num_queries_per_thread : VAR_NUM_QUERIES_PER_THREAD STRING_ARG",
"server_jostle_timeout : VAR_JOSTLE_TIMEOUT STRING_ARG",
"server_delay_close : VAR_DELAY_CLOSE STRING_ARG",
"server_unblock_lan_zones : VAR_UNBLOCK_LAN_ZONES STRING_ARG",
"server_insecure_lan_zones : VAR_INSECURE_LAN_ZONES STRING_ARG",
"server_rrset_cache_size : VAR_RRSET_CACHE_SIZE STRING_ARG",
"server_rrset_cache_slabs : VAR_RRSET_CACHE_SLABS STRING_ARG",
"server_infra_host_ttl : VAR_INFRA_HOST_TTL STRING_ARG",
"server_infra_lame_ttl : VAR_INFRA_LAME_TTL STRING_ARG",
"server_infra_cache_numhosts : VAR_INFRA_CACHE_NUMHOSTS STRING_ARG",
"server_infra_cache_lame_size : VAR_INFRA_CACHE_LAME_SIZE STRING_ARG",
"server_infra_cache_slabs : VAR_INFRA_CACHE_SLABS STRING_ARG",
"server_infra_cache_min_rtt : VAR_INFRA_CACHE_MIN_RTT STRING_ARG",
"server_target_fetch_policy : VAR_TARGET_FETCH_POLICY STRING_ARG",
"server_harden_short_bufsize : VAR_HARDEN_SHORT_BUFSIZE STRING_ARG",
"server_harden_large_queries : VAR_HARDEN_LARGE_QUERIES STRING_ARG",
"server_harden_glue : VAR_HARDEN_GLUE STRING_ARG",
"server_harden_dnssec_stripped : VAR_HARDEN_DNSSEC_STRIPPED STRING_ARG",
"server_harden_below_nxdomain : VAR_HARDEN_BELOW_NXDOMAIN STRING_ARG",
"server_harden_referral_path : VAR_HARDEN_REFERRAL_PATH STRING_ARG",
"server_harden_algo_downgrade : VAR_HARDEN_ALGO_DOWNGRADE STRING_ARG",
"server_use_caps_for_id : VAR_USE_CAPS_FOR_ID STRING_ARG",
"server_caps_whitelist : VAR_CAPS_WHITELIST STRING_ARG",
"server_private_address : VAR_PRIVATE_ADDRESS STRING_ARG",
"server_private_domain : VAR_PRIVATE_DOMAIN STRING_ARG",
"server_prefetch : VAR_PREFETCH STRING_ARG",
"server_prefetch_key : VAR_PREFETCH_KEY STRING_ARG",
"server_unwanted_reply_threshold : VAR_UNWANTED_REPLY_THRESHOLD STRING_ARG",
"server_do_not_query_address : VAR_DO_NOT_QUERY_ADDRESS STRING_ARG",
"server_do_not_query_localhost : VAR_DO_NOT_QUERY_LOCALHOST STRING_ARG",
"server_access_control : VAR_ACCESS_CONTROL STRING_ARG STRING_ARG",
"server_module_conf : VAR_MODULE_CONF STRING_ARG",
"server_val_override_date : VAR_VAL_OVERRIDE_DATE STRING_ARG",
"server_val_sig_skew_min : VAR_VAL_SIG_SKEW_MIN STRING_ARG",
"server_val_sig_skew_max : VAR_VAL_SIG_SKEW_MAX STRING_ARG",
"server_cache_max_ttl : VAR_CACHE_MAX_TTL STRING_ARG",
"server_cache_max_negative_ttl : VAR_CACHE_MAX_NEGATIVE_TTL STRING_ARG",
"server_cache_min_ttl : VAR_CACHE_MIN_TTL STRING_ARG",
"server_bogus_ttl : VAR_BOGUS_TTL STRING_ARG",
"server_val_clean_additional : VAR_VAL_CLEAN_ADDITIONAL STRING_ARG",
"server_val_permissive_mode : VAR_VAL_PERMISSIVE_MODE STRING_ARG",
"server_ignore_cd_flag : VAR_IGNORE_CD_FLAG STRING_ARG",
"server_val_log_level : VAR_VAL_LOG_LEVEL STRING_ARG",
"server_val_nsec3_keysize_iterations : VAR_VAL_NSEC3_KEYSIZE_ITERATIONS STRING_ARG",
"server_add_holddown : VAR_ADD_HOLDDOWN STRING_ARG",
"server_del_holddown : VAR_DEL_HOLDDOWN STRING_ARG",
"server_keep_missing : VAR_KEEP_MISSING STRING_ARG",
"server_permit_small_holddown : VAR_PERMIT_SMALL_HOLDDOWN STRING_ARG",
"server_key_cache_size : VAR_KEY_CACHE_SIZE STRING_ARG",
"server_key_cache_slabs : VAR_KEY_CACHE_SLABS STRING_ARG",
"server_neg_cache_size : VAR_NEG_CACHE_SIZE STRING_ARG",
"server_local_zone : VAR_LOCAL_ZONE STRING_ARG STRING_ARG",
"server_local_data : VAR_LOCAL_DATA STRING_ARG",
"server_local_data_ptr : VAR_LOCAL_DATA_PTR STRING_ARG",
"server_minimal_responses : VAR_MINIMAL_RESPONSES STRING_ARG",
"server_rrset_roundrobin : VAR_RRSET_ROUNDROBIN STRING_ARG",
"server_max_udp_size : VAR_MAX_UDP_SIZE STRING_ARG",
"server_dns64_prefix : VAR_DNS64_PREFIX STRING_ARG",
"server_dns64_synthall : VAR_DNS64_SYNTHALL STRING_ARG",
"server_define_tag : VAR_DEFINE_TAG STRING_ARG",
"server_local_zone_tag : VAR_LOCAL_ZONE_TAG STRING_ARG STRING_ARG",
"server_access_control_tag : VAR_ACCESS_CONTROL_TAG STRING_ARG STRING_ARG",
"server_access_control_tag_action : VAR_ACCESS_CONTROL_TAG_ACTION STRING_ARG STRING_ARG STRING_ARG",
"server_access_control_tag_data : VAR_ACCESS_CONTROL_TAG_DATA STRING_ARG STRING_ARG STRING_ARG",
"server_local_zone_override : VAR_LOCAL_ZONE_OVERRIDE STRING_ARG STRING_ARG STRING_ARG",
"server_ratelimit : VAR_RATELIMIT STRING_ARG",
"server_ratelimit_size : VAR_RATELIMIT_SIZE STRING_ARG",
"server_ratelimit_slabs : VAR_RATELIMIT_SLABS STRING_ARG",
"server_ratelimit_for_domain : VAR_RATELIMIT_FOR_DOMAIN STRING_ARG STRING_ARG",
"server_ratelimit_below_domain : VAR_RATELIMIT_BELOW_DOMAIN STRING_ARG STRING_ARG",
"server_ratelimit_factor : VAR_RATELIMIT_FACTOR STRING_ARG",
"server_qname_minimisation : VAR_QNAME_MINIMISATION STRING_ARG",
"stub_name : VAR_NAME STRING_ARG",
"stub_host : VAR_STUB_HOST STRING_ARG",
"stub_addr : VAR_STUB_ADDR STRING_ARG",
"stub_first : VAR_STUB_FIRST STRING_ARG",
"stub_prime : VAR_STUB_PRIME STRING_ARG",
"forward_name : VAR_NAME STRING_ARG",
"forward_host : VAR_FORWARD_HOST STRING_ARG",
"forward_addr : VAR_FORWARD_ADDR STRING_ARG",
"forward_first : VAR_FORWARD_FIRST STRING_ARG",
"rcstart : VAR_REMOTE_CONTROL",
"contents_rc : contents_rc content_rc",
"contents_rc :",
"content_rc : rc_control_enable",
"content_rc : rc_control_interface",
"content_rc : rc_control_port",
"content_rc : rc_server_key_file",
"content_rc : rc_server_cert_file",
"content_rc : rc_control_key_file",
"content_rc : rc_control_cert_file",
"content_rc : rc_control_use_cert",
"rc_control_enable : VAR_CONTROL_ENABLE STRING_ARG",
"rc_control_port : VAR_CONTROL_PORT STRING_ARG",
"rc_control_interface : VAR_CONTROL_INTERFACE STRING_ARG",
"rc_control_use_cert : VAR_CONTROL_USE_CERT STRING_ARG",
"rc_server_key_file : VAR_SERVER_KEY_FILE STRING_ARG",
"rc_server_cert_file : VAR_SERVER_CERT_FILE STRING_ARG",
"rc_control_key_file : VAR_CONTROL_KEY_FILE STRING_ARG",
"rc_control_cert_file : VAR_CONTROL_CERT_FILE STRING_ARG",
"dtstart : VAR_DNSTAP",
"contents_dt : contents_dt content_dt",
"contents_dt :",
"content_dt : dt_dnstap_enable",
"content_dt : dt_dnstap_socket_path",
"content_dt : dt_dnstap_send_identity",
"content_dt : dt_dnstap_send_version",
"content_dt : dt_dnstap_identity",
"content_dt : dt_dnstap_version",
"content_dt : dt_dnstap_log_resolver_query_messages",
"content_dt : dt_dnstap_log_resolver_response_messages",
"content_dt : dt_dnstap_log_client_query_messages",
"content_dt : dt_dnstap_log_client_response_messages",
"content_dt : dt_dnstap_log_forwarder_query_messages",
"content_dt : dt_dnstap_log_forwarder_response_messages",
"dt_dnstap_enable : VAR_DNSTAP_ENABLE STRING_ARG",
"dt_dnstap_socket_path : VAR_DNSTAP_SOCKET_PATH STRING_ARG",
"dt_dnstap_send_identity : VAR_DNSTAP_SEND_IDENTITY STRING_ARG",
"dt_dnstap_send_version : VAR_DNSTAP_SEND_VERSION STRING_ARG",
"dt_dnstap_identity : VAR_DNSTAP_IDENTITY STRING_ARG",
"dt_dnstap_version : VAR_DNSTAP_VERSION STRING_ARG",
"dt_dnstap_log_resolver_query_messages : VAR_DNSTAP_LOG_RESOLVER_QUERY_MESSAGES STRING_ARG",
"dt_dnstap_log_resolver_response_messages : VAR_DNSTAP_LOG_RESOLVER_RESPONSE_MESSAGES STRING_ARG",
"dt_dnstap_log_client_query_messages : VAR_DNSTAP_LOG_CLIENT_QUERY_MESSAGES STRING_ARG",
"dt_dnstap_log_client_response_messages : VAR_DNSTAP_LOG_CLIENT_RESPONSE_MESSAGES STRING_ARG",
"dt_dnstap_log_forwarder_query_messages : VAR_DNSTAP_LOG_FORWARDER_QUERY_MESSAGES STRING_ARG",
"dt_dnstap_log_forwarder_response_messages : VAR_DNSTAP_LOG_FORWARDER_RESPONSE_MESSAGES STRING_ARG",
"pythonstart : VAR_PYTHON",
"contents_py : contents_py content_py",
"contents_py :",
"content_py : py_script",
"py_script : VAR_PYTHON_SCRIPT STRING_ARG",
"server_disable_dnssec_lame_check : VAR_DISABLE_DNSSEC_LAME_CHECK STRING_ARG",

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
#line 1792 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"

/* parse helper routines could be here */
#line 1171 "configparser.c"

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
#line 141 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{ 
		OUTYY(("\nP(server:)\n")); 
	}
break;
case 141:
#line 205 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		struct config_stub* s;
		OUTYY(("\nP(stub_zone:)\n")); 
		s = (struct config_stub*)calloc(1, sizeof(struct config_stub));
		if(s) {
			s->next = cfg_parser->cfg->stubs;
			cfg_parser->cfg->stubs = s;
		} else 
			yyerror("out of memory");
	}
break;
case 149:
#line 221 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		struct config_stub* s;
		OUTYY(("\nP(forward_zone:)\n")); 
		s = (struct config_stub*)calloc(1, sizeof(struct config_stub));
		if(s) {
			s->next = cfg_parser->cfg->forwards;
			cfg_parser->cfg->forwards = s;
		} else 
			yyerror("out of memory");
	}
break;
case 156:
#line 237 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{ 
		OUTYY(("P(server_num_threads:%s)\n", yystack.l_mark[0].str)); 
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->num_threads = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 157:
#line 246 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{ 
		OUTYY(("P(server_verbosity:%s)\n", yystack.l_mark[0].str)); 
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->verbosity = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 158:
#line 255 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{ 
		OUTYY(("P(server_statistics_interval:%s)\n", yystack.l_mark[0].str)); 
		if(strcmp(yystack.l_mark[0].str, "") == 0 || strcmp(yystack.l_mark[0].str, "0") == 0)
			cfg_parser->cfg->stat_interval = 0;
		else if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else cfg_parser->cfg->stat_interval = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 159:
#line 266 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_statistics_cumulative:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->stat_cumulative = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 160:
#line 275 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_extended_statistics:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->stat_extended = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 161:
#line 284 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_port:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("port number expected");
		else cfg_parser->cfg->port = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 162:
#line 293 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_interface:%s)\n", yystack.l_mark[0].str));
		if(cfg_parser->cfg->num_ifs == 0)
			cfg_parser->cfg->ifs = calloc(1, sizeof(char*));
		else 	cfg_parser->cfg->ifs = realloc(cfg_parser->cfg->ifs,
				(cfg_parser->cfg->num_ifs+1)*sizeof(char*));
		if(!cfg_parser->cfg->ifs)
			yyerror("out of memory");
		else
			cfg_parser->cfg->ifs[cfg_parser->cfg->num_ifs++] = yystack.l_mark[0].str;
	}
break;
case 163:
#line 306 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_outgoing_interface:%s)\n", yystack.l_mark[0].str));
		if(cfg_parser->cfg->num_out_ifs == 0)
			cfg_parser->cfg->out_ifs = calloc(1, sizeof(char*));
		else 	cfg_parser->cfg->out_ifs = realloc(
			cfg_parser->cfg->out_ifs, 
			(cfg_parser->cfg->num_out_ifs+1)*sizeof(char*));
		if(!cfg_parser->cfg->out_ifs)
			yyerror("out of memory");
		else
			cfg_parser->cfg->out_ifs[
				cfg_parser->cfg->num_out_ifs++] = yystack.l_mark[0].str;
	}
break;
case 164:
#line 321 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_outgoing_range:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else cfg_parser->cfg->outgoing_num_ports = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 165:
#line 330 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_outgoing_port_permit:%s)\n", yystack.l_mark[0].str));
		if(!cfg_mark_ports(yystack.l_mark[0].str, 1, 
			cfg_parser->cfg->outgoing_avail_ports, 65536))
			yyerror("port number or range (\"low-high\") expected");
		free(yystack.l_mark[0].str);
	}
break;
case 166:
#line 339 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_outgoing_port_avoid:%s)\n", yystack.l_mark[0].str));
		if(!cfg_mark_ports(yystack.l_mark[0].str, 0, 
			cfg_parser->cfg->outgoing_avail_ports, 65536))
			yyerror("port number or range (\"low-high\") expected");
		free(yystack.l_mark[0].str);
	}
break;
case 167:
#line 348 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_outgoing_num_tcp:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->outgoing_num_tcp = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 168:
#line 357 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_incoming_num_tcp:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->incoming_num_tcp = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 169:
#line 366 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_interface_automatic:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->if_automatic = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 170:
#line 375 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_do_ip4:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->do_ip4 = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 171:
#line 384 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_do_ip6:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->do_ip6 = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 172:
#line 393 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_do_udp:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->do_udp = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 173:
#line 402 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_do_tcp:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->do_tcp = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 174:
#line 411 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_prefer_ip6:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->prefer_ip6 = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 175:
#line 420 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_tcp_mss:%s)\n", yystack.l_mark[0].str));
                if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
                        yyerror("number expected");
                else cfg_parser->cfg->tcp_mss = atoi(yystack.l_mark[0].str);
                free(yystack.l_mark[0].str);
	}
break;
case 176:
#line 429 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_outgoing_tcp_mss:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->outgoing_tcp_mss = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 177:
#line 438 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_tcp_upstream:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->tcp_upstream = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 178:
#line 447 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_ssl_upstream:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->ssl_upstream = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 179:
#line 456 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_ssl_service_key:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->ssl_service_key);
		cfg_parser->cfg->ssl_service_key = yystack.l_mark[0].str;
	}
break;
case 180:
#line 463 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_ssl_service_pem:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->ssl_service_pem);
		cfg_parser->cfg->ssl_service_pem = yystack.l_mark[0].str;
	}
break;
case 181:
#line 470 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_ssl_port:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("port number expected");
		else cfg_parser->cfg->ssl_port = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 182:
#line 479 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_do_daemonize:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->do_daemonize = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 183:
#line 488 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_use_syslog:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->use_syslog = (strcmp(yystack.l_mark[0].str, "yes")==0);
#if !defined(HAVE_SYSLOG_H) && !defined(UB_ON_WINDOWS)
		if(strcmp(yystack.l_mark[0].str, "yes") == 0)
			yyerror("no syslog services are available. "
				"(reconfigure and compile to add)");
#endif
		free(yystack.l_mark[0].str);
	}
break;
case 184:
#line 502 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_log_time_ascii:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->log_time_ascii = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 185:
#line 511 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_log_queries:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->log_queries = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 186:
#line 520 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_chroot:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->chrootdir);
		cfg_parser->cfg->chrootdir = yystack.l_mark[0].str;
	}
break;
case 187:
#line 527 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_username:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->username);
		cfg_parser->cfg->username = yystack.l_mark[0].str;
	}
break;
case 188:
#line 534 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_directory:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->directory);
		cfg_parser->cfg->directory = yystack.l_mark[0].str;
		/* change there right away for includes relative to this */
		if(yystack.l_mark[0].str[0]) {
			char* d;
#ifdef UB_ON_WINDOWS
			w_config_adjust_directory(cfg_parser->cfg);
#endif
			d = cfg_parser->cfg->directory;
			/* adjust directory if we have already chroot,
			 * like, we reread after sighup */
			if(cfg_parser->chroot && cfg_parser->chroot[0] &&
				strncmp(d, cfg_parser->chroot, strlen(
				cfg_parser->chroot)) == 0)
				d += strlen(cfg_parser->chroot);
			if(chdir(d))
				log_err("cannot chdir to directory: %s (%s)",
					d, strerror(errno));
		}
	}
break;
case 189:
#line 558 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_logfile:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->logfile);
		cfg_parser->cfg->logfile = yystack.l_mark[0].str;
		cfg_parser->cfg->use_syslog = 0;
	}
break;
case 190:
#line 566 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_pidfile:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->pidfile);
		cfg_parser->cfg->pidfile = yystack.l_mark[0].str;
	}
break;
case 191:
#line 573 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_root_hints:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->root_hints, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 192:
#line 580 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_dlv_anchor_file:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->dlv_anchor_file);
		cfg_parser->cfg->dlv_anchor_file = yystack.l_mark[0].str;
	}
break;
case 193:
#line 587 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_dlv_anchor:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->dlv_anchor_list, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 194:
#line 594 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_auto_trust_anchor_file:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->
			auto_trust_anchor_file_list, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 195:
#line 602 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_trust_anchor_file:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->
			trust_anchor_file_list, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 196:
#line 610 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_trusted_keys_file:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->
			trusted_keys_file_list, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 197:
#line 618 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_trust_anchor:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->trust_anchor_list, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 198:
#line 625 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_domain_insecure:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->domain_insecure, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 199:
#line 632 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_hide_identity:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->hide_identity = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 200:
#line 641 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_hide_version:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->hide_version = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 201:
#line 650 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_identity:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->identity);
		cfg_parser->cfg->identity = yystack.l_mark[0].str;
	}
break;
case 202:
#line 657 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_version:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->version);
		cfg_parser->cfg->version = yystack.l_mark[0].str;
	}
break;
case 203:
#line 664 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_so_rcvbuf:%s)\n", yystack.l_mark[0].str));
		if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->so_rcvbuf))
			yyerror("buffer size expected");
		free(yystack.l_mark[0].str);
	}
break;
case 204:
#line 672 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_so_sndbuf:%s)\n", yystack.l_mark[0].str));
		if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->so_sndbuf))
			yyerror("buffer size expected");
		free(yystack.l_mark[0].str);
	}
break;
case 205:
#line 680 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
        OUTYY(("P(server_so_reuseport:%s)\n", yystack.l_mark[0].str));
        if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
            yyerror("expected yes or no.");
        else cfg_parser->cfg->so_reuseport =
            (strcmp(yystack.l_mark[0].str, "yes")==0);
        free(yystack.l_mark[0].str);
    }
break;
case 206:
#line 690 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
        OUTYY(("P(server_ip_transparent:%s)\n", yystack.l_mark[0].str));
        if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
            yyerror("expected yes or no.");
        else cfg_parser->cfg->ip_transparent =
            (strcmp(yystack.l_mark[0].str, "yes")==0);
        free(yystack.l_mark[0].str);
    }
break;
case 207:
#line 700 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
        OUTYY(("P(server_ip_freebind:%s)\n", yystack.l_mark[0].str));
        if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
            yyerror("expected yes or no.");
        else cfg_parser->cfg->ip_freebind =
            (strcmp(yystack.l_mark[0].str, "yes")==0);
        free(yystack.l_mark[0].str);
    }
break;
case 208:
#line 710 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_edns_buffer_size:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else if (atoi(yystack.l_mark[0].str) < 12)
			yyerror("edns buffer size too small");
		else if (atoi(yystack.l_mark[0].str) > 65535)
			cfg_parser->cfg->edns_buffer_size = 65535;
		else cfg_parser->cfg->edns_buffer_size = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 209:
#line 723 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_msg_buffer_size:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else if (atoi(yystack.l_mark[0].str) < 4096)
			yyerror("message buffer size too small (use 4096)");
		else cfg_parser->cfg->msg_buffer_size = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 210:
#line 734 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_msg_cache_size:%s)\n", yystack.l_mark[0].str));
		if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->msg_cache_size))
			yyerror("memory size expected");
		free(yystack.l_mark[0].str);
	}
break;
case 211:
#line 742 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_msg_cache_slabs:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else {
			cfg_parser->cfg->msg_cache_slabs = atoi(yystack.l_mark[0].str);
			if(!is_pow2(cfg_parser->cfg->msg_cache_slabs))
				yyerror("must be a power of 2");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 212:
#line 755 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_num_queries_per_thread:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else cfg_parser->cfg->num_queries_per_thread = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 213:
#line 764 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_jostle_timeout:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->jostle_time = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 214:
#line 773 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_delay_close:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->delay_close = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 215:
#line 782 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_unblock_lan_zones:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->unblock_lan_zones = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 216:
#line 792 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_insecure_lan_zones:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->insecure_lan_zones = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 217:
#line 802 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_rrset_cache_size:%s)\n", yystack.l_mark[0].str));
		if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->rrset_cache_size))
			yyerror("memory size expected");
		free(yystack.l_mark[0].str);
	}
break;
case 218:
#line 810 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_rrset_cache_slabs:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else {
			cfg_parser->cfg->rrset_cache_slabs = atoi(yystack.l_mark[0].str);
			if(!is_pow2(cfg_parser->cfg->rrset_cache_slabs))
				yyerror("must be a power of 2");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 219:
#line 823 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_infra_host_ttl:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->host_ttl = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 220:
#line 832 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_infra_lame_ttl:%s)\n", yystack.l_mark[0].str));
		verbose(VERB_DETAIL, "ignored infra-lame-ttl: %s (option "
			"removed, use infra-host-ttl)", yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 221:
#line 840 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_infra_cache_numhosts:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else cfg_parser->cfg->infra_cache_numhosts = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 222:
#line 849 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_infra_cache_lame_size:%s)\n", yystack.l_mark[0].str));
		verbose(VERB_DETAIL, "ignored infra-cache-lame-size: %s "
			"(option removed, use infra-cache-numhosts)", yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 223:
#line 857 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_infra_cache_slabs:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else {
			cfg_parser->cfg->infra_cache_slabs = atoi(yystack.l_mark[0].str);
			if(!is_pow2(cfg_parser->cfg->infra_cache_slabs))
				yyerror("must be a power of 2");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 224:
#line 870 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_infra_cache_min_rtt:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->infra_cache_min_rtt = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 225:
#line 879 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_target_fetch_policy:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->target_fetch_policy);
		cfg_parser->cfg->target_fetch_policy = yystack.l_mark[0].str;
	}
break;
case 226:
#line 886 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_harden_short_bufsize:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->harden_short_bufsize = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 227:
#line 896 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_harden_large_queries:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->harden_large_queries = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 228:
#line 906 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_harden_glue:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->harden_glue = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 229:
#line 916 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_harden_dnssec_stripped:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->harden_dnssec_stripped = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 230:
#line 926 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_harden_below_nxdomain:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->harden_below_nxdomain = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 231:
#line 936 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_harden_referral_path:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->harden_referral_path = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 232:
#line 946 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_harden_algo_downgrade:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->harden_algo_downgrade = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 233:
#line 956 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_use_caps_for_id:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->use_caps_bits_for_id = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 234:
#line 966 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_caps_whitelist:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->caps_whitelist, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 235:
#line 973 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_private_address:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->private_address, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 236:
#line 980 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_private_domain:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->private_domain, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 237:
#line 987 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_prefetch:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->prefetch = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 238:
#line 996 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_prefetch_key:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->prefetch_key = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 239:
#line 1005 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_unwanted_reply_threshold:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->unwanted_threshold = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 240:
#line 1014 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_do_not_query_address:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->donotqueryaddrs, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 241:
#line 1021 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_do_not_query_localhost:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->donotquery_localhost = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 242:
#line 1031 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_access_control:%s %s)\n", yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "deny")!=0 && strcmp(yystack.l_mark[0].str, "refuse")!=0 &&
			strcmp(yystack.l_mark[0].str, "deny_non_local")!=0 &&
			strcmp(yystack.l_mark[0].str, "refuse_non_local")!=0 &&
			strcmp(yystack.l_mark[0].str, "allow")!=0 && 
			strcmp(yystack.l_mark[0].str, "allow_snoop")!=0) {
			yyerror("expected deny, refuse, deny_non_local, "
				"refuse_non_local, allow or allow_snoop "
				"in access control action");
		} else {
			if(!cfg_str2list_insert(&cfg_parser->cfg->acls, yystack.l_mark[-1].str, yystack.l_mark[0].str))
				fatal_exit("out of memory adding acl");
		}
	}
break;
case 243:
#line 1048 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_module_conf:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->module_conf);
		cfg_parser->cfg->module_conf = yystack.l_mark[0].str;
	}
break;
case 244:
#line 1055 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_val_override_date:%s)\n", yystack.l_mark[0].str));
		if(*yystack.l_mark[0].str == '\0' || strcmp(yystack.l_mark[0].str, "0") == 0) {
			cfg_parser->cfg->val_date_override = 0;
		} else if(strlen(yystack.l_mark[0].str) == 14) {
			cfg_parser->cfg->val_date_override = 
				cfg_convert_timeval(yystack.l_mark[0].str);
			if(!cfg_parser->cfg->val_date_override)
				yyerror("bad date/time specification");
		} else {
			if(atoi(yystack.l_mark[0].str) == 0)
				yyerror("number expected");
			cfg_parser->cfg->val_date_override = atoi(yystack.l_mark[0].str);
		}
		free(yystack.l_mark[0].str);
	}
break;
case 245:
#line 1073 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_val_sig_skew_min:%s)\n", yystack.l_mark[0].str));
		if(*yystack.l_mark[0].str == '\0' || strcmp(yystack.l_mark[0].str, "0") == 0) {
			cfg_parser->cfg->val_sig_skew_min = 0;
		} else {
			cfg_parser->cfg->val_sig_skew_min = atoi(yystack.l_mark[0].str);
			if(!cfg_parser->cfg->val_sig_skew_min)
				yyerror("number expected");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 246:
#line 1086 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_val_sig_skew_max:%s)\n", yystack.l_mark[0].str));
		if(*yystack.l_mark[0].str == '\0' || strcmp(yystack.l_mark[0].str, "0") == 0) {
			cfg_parser->cfg->val_sig_skew_max = 0;
		} else {
			cfg_parser->cfg->val_sig_skew_max = atoi(yystack.l_mark[0].str);
			if(!cfg_parser->cfg->val_sig_skew_max)
				yyerror("number expected");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 247:
#line 1099 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_cache_max_ttl:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->max_ttl = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 248:
#line 1108 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_cache_max_negative_ttl:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->max_negative_ttl = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 249:
#line 1117 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_cache_min_ttl:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->min_ttl = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 250:
#line 1126 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_bogus_ttl:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->bogus_ttl = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 251:
#line 1135 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_val_clean_additional:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->val_clean_additional = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 252:
#line 1145 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_val_permissive_mode:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->val_permissive_mode = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 253:
#line 1155 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_ignore_cd_flag:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->ignore_cd = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 254:
#line 1164 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_val_log_level:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->val_log_level = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 255:
#line 1173 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_val_nsec3_keysize_iterations:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->val_nsec3_key_iterations);
		cfg_parser->cfg->val_nsec3_key_iterations = yystack.l_mark[0].str;
	}
break;
case 256:
#line 1180 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_add_holddown:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->add_holddown = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 257:
#line 1189 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_del_holddown:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->del_holddown = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 258:
#line 1198 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_keep_missing:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->keep_missing = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 259:
#line 1207 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_permit_small_holddown:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->permit_small_holddown =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 260:
#line 1216 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_key_cache_size:%s)\n", yystack.l_mark[0].str));
		if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->key_cache_size))
			yyerror("memory size expected");
		free(yystack.l_mark[0].str);
	}
break;
case 261:
#line 1224 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_key_cache_slabs:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else {
			cfg_parser->cfg->key_cache_slabs = atoi(yystack.l_mark[0].str);
			if(!is_pow2(cfg_parser->cfg->key_cache_slabs))
				yyerror("must be a power of 2");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 262:
#line 1237 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_neg_cache_size:%s)\n", yystack.l_mark[0].str));
		if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->neg_cache_size))
			yyerror("memory size expected");
		free(yystack.l_mark[0].str);
	}
break;
case 263:
#line 1245 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_local_zone:%s %s)\n", yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "static")!=0 && strcmp(yystack.l_mark[0].str, "deny")!=0 &&
		   strcmp(yystack.l_mark[0].str, "refuse")!=0 && strcmp(yystack.l_mark[0].str, "redirect")!=0 &&
		   strcmp(yystack.l_mark[0].str, "transparent")!=0 && strcmp(yystack.l_mark[0].str, "nodefault")!=0
		   && strcmp(yystack.l_mark[0].str, "typetransparent")!=0
		   && strcmp(yystack.l_mark[0].str, "always_transparent")!=0
		   && strcmp(yystack.l_mark[0].str, "always_refuse")!=0
		   && strcmp(yystack.l_mark[0].str, "always_nxdomain")!=0
		   && strcmp(yystack.l_mark[0].str, "inform")!=0 && strcmp(yystack.l_mark[0].str, "inform_deny")!=0)
			yyerror("local-zone type: expected static, deny, "
				"refuse, redirect, transparent, "
				"typetransparent, inform, inform_deny, "
				"always_transparent, always_refuse, "
				"always_nxdomain or nodefault");
		else if(strcmp(yystack.l_mark[0].str, "nodefault")==0) {
			if(!cfg_strlist_insert(&cfg_parser->cfg->
				local_zones_nodefault, yystack.l_mark[-1].str))
				fatal_exit("out of memory adding local-zone");
			free(yystack.l_mark[0].str);
		} else {
			if(!cfg_str2list_insert(&cfg_parser->cfg->local_zones, 
				yystack.l_mark[-1].str, yystack.l_mark[0].str))
				fatal_exit("out of memory adding local-zone");
		}
	}
break;
case 264:
#line 1273 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_local_data:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->local_data, yystack.l_mark[0].str))
			fatal_exit("out of memory adding local-data");
	}
break;
case 265:
#line 1280 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		char* ptr;
		OUTYY(("P(server_local_data_ptr:%s)\n", yystack.l_mark[0].str));
		ptr = cfg_ptr_reverse(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if(ptr) {
			if(!cfg_strlist_insert(&cfg_parser->cfg->
				local_data, ptr))
				fatal_exit("out of memory adding local-data");
		} else {
			yyerror("local-data-ptr could not be reversed");
		}
	}
break;
case 266:
#line 1295 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_minimal_responses:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->minimal_responses =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 267:
#line 1305 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_rrset_roundrobin:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->rrset_roundrobin =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 268:
#line 1315 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_max_udp_size:%s)\n", yystack.l_mark[0].str));
		cfg_parser->cfg->max_udp_size = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 269:
#line 1322 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(dns64_prefix:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->dns64_prefix);
		cfg_parser->cfg->dns64_prefix = yystack.l_mark[0].str;
	}
break;
case 270:
#line 1329 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_dns64_synthall:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dns64_synthall = (strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 271:
#line 1338 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		char* p, *s = yystack.l_mark[0].str;
		OUTYY(("P(server_define_tag:%s)\n", yystack.l_mark[0].str));
		while((p=strsep(&s, " \t\n")) != NULL) {
			if(*p) {
				if(!config_add_tag(cfg_parser->cfg, p))
					yyerror("could not define-tag, "
						"out of memory");
			}
		}
		free(yystack.l_mark[0].str);
	}
break;
case 272:
#line 1352 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		size_t len = 0;
		uint8_t* bitlist = config_parse_taglist(cfg_parser->cfg, yystack.l_mark[0].str,
			&len);
		free(yystack.l_mark[0].str);
		OUTYY(("P(server_local_zone_tag:%s)\n", yystack.l_mark[-1].str));
		if(!bitlist)
			yyerror("could not parse tags, (define-tag them first)");
		if(bitlist) {
			if(!cfg_strbytelist_insert(
				&cfg_parser->cfg->local_zone_tags,
				yystack.l_mark[-1].str, bitlist, len)) {
				yyerror("out of memory");
				free(yystack.l_mark[-1].str);
			}
		}
	}
break;
case 273:
#line 1371 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		size_t len = 0;
		uint8_t* bitlist = config_parse_taglist(cfg_parser->cfg, yystack.l_mark[0].str,
			&len);
		free(yystack.l_mark[0].str);
		OUTYY(("P(server_access_control_tag:%s)\n", yystack.l_mark[-1].str));
		if(!bitlist)
			yyerror("could not parse tags, (define-tag them first)");
		if(bitlist) {
			if(!cfg_strbytelist_insert(
				&cfg_parser->cfg->acl_tags,
				yystack.l_mark[-1].str, bitlist, len)) {
				yyerror("out of memory");
				free(yystack.l_mark[-1].str);
			}
		}
	}
break;
case 274:
#line 1390 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_access_control_tag_action:%s %s %s)\n", yystack.l_mark[-2].str, yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(!cfg_str3list_insert(&cfg_parser->cfg->acl_tag_actions,
			yystack.l_mark[-2].str, yystack.l_mark[-1].str, yystack.l_mark[0].str)) {
			yyerror("out of memory");
			free(yystack.l_mark[-2].str);
			free(yystack.l_mark[-1].str);
			free(yystack.l_mark[0].str);
		}
	}
break;
case 275:
#line 1402 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_access_control_tag_data:%s %s %s)\n", yystack.l_mark[-2].str, yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(!cfg_str3list_insert(&cfg_parser->cfg->acl_tag_datas,
			yystack.l_mark[-2].str, yystack.l_mark[-1].str, yystack.l_mark[0].str)) {
			yyerror("out of memory");
			free(yystack.l_mark[-2].str);
			free(yystack.l_mark[-1].str);
			free(yystack.l_mark[0].str);
		}
	}
break;
case 276:
#line 1414 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_local_zone_override:%s %s %s)\n", yystack.l_mark[-2].str, yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(!cfg_str3list_insert(&cfg_parser->cfg->local_zone_overrides,
			yystack.l_mark[-2].str, yystack.l_mark[-1].str, yystack.l_mark[0].str)) {
			yyerror("out of memory");
			free(yystack.l_mark[-2].str);
			free(yystack.l_mark[-1].str);
			free(yystack.l_mark[0].str);
		}
	}
break;
case 277:
#line 1426 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{ 
		OUTYY(("P(server_ratelimit:%s)\n", yystack.l_mark[0].str)); 
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->ratelimit = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 278:
#line 1435 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_ratelimit_size:%s)\n", yystack.l_mark[0].str));
		if(!cfg_parse_memsize(yystack.l_mark[0].str, &cfg_parser->cfg->ratelimit_size))
			yyerror("memory size expected");
		free(yystack.l_mark[0].str);
	}
break;
case 279:
#line 1443 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_ratelimit_slabs:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("number expected");
		else {
			cfg_parser->cfg->ratelimit_slabs = atoi(yystack.l_mark[0].str);
			if(!is_pow2(cfg_parser->cfg->ratelimit_slabs))
				yyerror("must be a power of 2");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 280:
#line 1456 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_ratelimit_for_domain:%s %s)\n", yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0) {
			yyerror("number expected");
		} else {
			if(!cfg_str2list_insert(&cfg_parser->cfg->
				ratelimit_for_domain, yystack.l_mark[-1].str, yystack.l_mark[0].str))
				fatal_exit("out of memory adding "
					"ratelimit-for-domain");
		}
	}
break;
case 281:
#line 1469 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_ratelimit_below_domain:%s %s)\n", yystack.l_mark[-1].str, yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0) {
			yyerror("number expected");
		} else {
			if(!cfg_str2list_insert(&cfg_parser->cfg->
				ratelimit_below_domain, yystack.l_mark[-1].str, yystack.l_mark[0].str))
				fatal_exit("out of memory adding "
					"ratelimit-below-domain");
		}
	}
break;
case 282:
#line 1482 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{ 
		OUTYY(("P(server_ratelimit_factor:%s)\n", yystack.l_mark[0].str)); 
		if(atoi(yystack.l_mark[0].str) == 0 && strcmp(yystack.l_mark[0].str, "0") != 0)
			yyerror("number expected");
		else cfg_parser->cfg->ratelimit_factor = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 283:
#line 1491 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(server_qname_minimisation:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->qname_minimisation = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 284:
#line 1501 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(name:%s)\n", yystack.l_mark[0].str));
		if(cfg_parser->cfg->stubs->name)
			yyerror("stub name override, there must be one name "
				"for one stub-zone");
		free(cfg_parser->cfg->stubs->name);
		cfg_parser->cfg->stubs->name = yystack.l_mark[0].str;
	}
break;
case 285:
#line 1511 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(stub-host:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->stubs->hosts, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 286:
#line 1518 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(stub-addr:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->stubs->addrs, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 287:
#line 1525 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(stub-first:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->stubs->isfirst=(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 288:
#line 1534 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(stub-prime:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->stubs->isprime = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 289:
#line 1544 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(name:%s)\n", yystack.l_mark[0].str));
		if(cfg_parser->cfg->forwards->name)
			yyerror("forward name override, there must be one "
				"name for one forward-zone");
		free(cfg_parser->cfg->forwards->name);
		cfg_parser->cfg->forwards->name = yystack.l_mark[0].str;
	}
break;
case 290:
#line 1554 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(forward-host:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->forwards->hosts, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 291:
#line 1561 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(forward-addr:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->forwards->addrs, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 292:
#line 1568 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(forward-first:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->forwards->isfirst=(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 293:
#line 1577 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{ 
		OUTYY(("\nP(remote-control:)\n")); 
	}
break;
case 304:
#line 1588 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(control_enable:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->remote_control_enable = 
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 305:
#line 1598 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(control_port:%s)\n", yystack.l_mark[0].str));
		if(atoi(yystack.l_mark[0].str) == 0)
			yyerror("control port number expected");
		else cfg_parser->cfg->control_port = atoi(yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 306:
#line 1607 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(control_interface:%s)\n", yystack.l_mark[0].str));
		if(!cfg_strlist_insert(&cfg_parser->cfg->control_ifs, yystack.l_mark[0].str))
			yyerror("out of memory");
	}
break;
case 307:
#line 1614 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(control_use_cert:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->remote_control_use_cert =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
case 308:
#line 1624 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(rc_server_key_file:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->server_key_file);
		cfg_parser->cfg->server_key_file = yystack.l_mark[0].str;
	}
break;
case 309:
#line 1631 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(rc_server_cert_file:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->server_cert_file);
		cfg_parser->cfg->server_cert_file = yystack.l_mark[0].str;
	}
break;
case 310:
#line 1638 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(rc_control_key_file:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->control_key_file);
		cfg_parser->cfg->control_key_file = yystack.l_mark[0].str;
	}
break;
case 311:
#line 1645 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(rc_control_cert_file:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->control_cert_file);
		cfg_parser->cfg->control_cert_file = yystack.l_mark[0].str;
	}
break;
case 312:
#line 1652 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("\nP(dnstap:)\n"));
	}
break;
case 327:
#line 1669 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_enable:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap = (strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 328:
#line 1677 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_socket_path:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->dnstap_socket_path);
		cfg_parser->cfg->dnstap_socket_path = yystack.l_mark[0].str;
	}
break;
case 329:
#line 1684 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_send_identity:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_send_identity = (strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 330:
#line 1692 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_send_version:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_send_version = (strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 331:
#line 1700 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_identity:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->dnstap_identity);
		cfg_parser->cfg->dnstap_identity = yystack.l_mark[0].str;
	}
break;
case 332:
#line 1707 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_version:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->dnstap_version);
		cfg_parser->cfg->dnstap_version = yystack.l_mark[0].str;
	}
break;
case 333:
#line 1714 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_log_resolver_query_messages:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_log_resolver_query_messages =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 334:
#line 1723 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_log_resolver_response_messages:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_log_resolver_response_messages =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 335:
#line 1732 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_log_client_query_messages:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_log_client_query_messages =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 336:
#line 1741 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_log_client_response_messages:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_log_client_response_messages =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 337:
#line 1750 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_log_forwarder_query_messages:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_log_forwarder_query_messages =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 338:
#line 1759 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(dt_dnstap_log_forwarder_response_messages:%s)\n", yystack.l_mark[0].str));
		if(strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->dnstap_log_forwarder_response_messages =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
	}
break;
case 339:
#line 1768 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{ 
		OUTYY(("\nP(python:)\n")); 
	}
break;
case 343:
#line 1777 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(python-script:%s)\n", yystack.l_mark[0].str));
		free(cfg_parser->cfg->python_script);
		cfg_parser->cfg->python_script = yystack.l_mark[0].str;
	}
break;
case 344:
#line 1783 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/contrib/unbound/util/configparser.y"
	{
		OUTYY(("P(disable_dnssec_lame_check:%s)\n", yystack.l_mark[0].str));
		if (strcmp(yystack.l_mark[0].str, "yes") != 0 && strcmp(yystack.l_mark[0].str, "no") != 0)
			yyerror("expected yes or no.");
		else cfg_parser->cfg->disable_dnssec_lame_check =
			(strcmp(yystack.l_mark[0].str, "yes")==0);
		free(yystack.l_mark[0].str);
	}
break;
#line 3100 "configparser.c"
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
