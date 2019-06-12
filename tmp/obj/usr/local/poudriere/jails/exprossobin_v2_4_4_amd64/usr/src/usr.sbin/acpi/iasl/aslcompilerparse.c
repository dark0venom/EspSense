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
#define yyparse    AslCompilerparse
#endif /* yyparse */

#ifndef yylex
#define yylex      AslCompilerlex
#endif /* yylex */

#ifndef yyerror
#define yyerror    AslCompilererror
#endif /* yyerror */

#ifndef yychar
#define yychar     AslCompilerchar
#endif /* yychar */

#ifndef yyval
#define yyval      AslCompilerval
#endif /* yyval */

#ifndef yylval
#define yylval     AslCompilerlval
#endif /* yylval */

#ifndef yydebug
#define yydebug    AslCompilerdebug
#endif /* yydebug */

#ifndef yynerrs
#define yynerrs    AslCompilernerrs
#endif /* yynerrs */

#ifndef yyerrflag
#define yyerrflag  AslCompilererrflag
#endif /* yyerrflag */

#ifndef yylhs
#define yylhs      AslCompilerlhs
#endif /* yylhs */

#ifndef yylen
#define yylen      AslCompilerlen
#endif /* yylen */

#ifndef yydefred
#define yydefred   AslCompilerdefred
#endif /* yydefred */

#ifndef yydgoto
#define yydgoto    AslCompilerdgoto
#endif /* yydgoto */

#ifndef yysindex
#define yysindex   AslCompilersindex
#endif /* yysindex */

#ifndef yyrindex
#define yyrindex   AslCompilerrindex
#endif /* yyrindex */

#ifndef yygindex
#define yygindex   AslCompilergindex
#endif /* yygindex */

#ifndef yytable
#define yytable    AslCompilertable
#endif /* yytable */

#ifndef yycheck
#define yycheck    AslCompilercheck
#endif /* yycheck */

#ifndef yyname
#define yyname     AslCompilername
#endif /* yyname */

#ifndef yyrule
#define yyrule     AslCompilerrule
#endif /* yyrule */
#define YYPREFIX "AslCompiler"

#define YYPURE 0

#line 2 "aslcompiler.y"
/******************************************************************************
 *
 * Module Name: aslparser.y - Master Bison/Yacc input file for iASL
 *
 *****************************************************************************/

/******************************************************************************
 *
 * 1. Copyright Notice
 *
 * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.
 * All rights reserved.
 *
 * 2. License
 *
 * 2.1. This is your license from Intel Corp. under its intellectual property
 * rights. You may have additional license terms from the party that provided
 * you this software, covering your right to use that party's intellectual
 * property rights.
 *
 * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a
 * copy of the source code appearing in this file ("Covered Code") an
 * irrevocable, perpetual, worldwide license under Intel's copyrights in the
 * base code distributed originally by Intel ("Original Intel Code") to copy,
 * make derivatives, distribute, use and display any portion of the Covered
 * Code in any form, with the right to sublicense such rights; and
 *
 * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent
 * license (with the right to sublicense), under only those claims of Intel
 * patents that are infringed by the Original Intel Code, to make, use, sell,
 * offer to sell, and import the Covered Code and derivative works thereof
 * solely to the minimum extent necessary to exercise the above copyright
 * license, and in no event shall the patent license extend to any additions
 * to or modifications of the Original Intel Code. No other license or right
 * is granted directly or by implication, estoppel or otherwise;
 *
 * The above copyright and patent license is granted only if the following
 * conditions are met:
 *
 * 3. Conditions
 *
 * 3.1. Redistribution of Source with Rights to Further Distribute Source.
 * Redistribution of source code of any substantial portion of the Covered
 * Code or modification with rights to further distribute source must include
 * the above Copyright Notice, the above License, this list of Conditions,
 * and the following Disclaimer and Export Compliance provision. In addition,
 * Licensee must cause all Covered Code to which Licensee contributes to
 * contain a file documenting the changes Licensee made to create that Covered
 * Code and the date of any change. Licensee must include in that file the
 * documentation of any changes made by any predecessor Licensee. Licensee
 * must include a prominent statement that the modification is derived,
 * directly or indirectly, from Original Intel Code.
 *
 * 3.2. Redistribution of Source with no Rights to Further Distribute Source.
 * Redistribution of source code of any substantial portion of the Covered
 * Code or modification without rights to further distribute source must
 * include the following Disclaimer and Export Compliance provision in the
 * documentation and/or other materials provided with distribution. In
 * addition, Licensee may not authorize further sublicense of source of any
 * portion of the Covered Code, and must include terms to the effect that the
 * license from Licensee to its licensee is limited to the intellectual
 * property embodied in the software Licensee provides to its licensee, and
 * not to intellectual property embodied in modifications its licensee may
 * make.
 *
 * 3.3. Redistribution of Executable. Redistribution in executable form of any
 * substantial portion of the Covered Code or modification must reproduce the
 * above Copyright Notice, and the following Disclaimer and Export Compliance
 * provision in the documentation and/or other materials provided with the
 * distribution.
 *
 * 3.4. Intel retains all right, title, and interest in and to the Original
 * Intel Code.
 *
 * 3.5. Neither the name Intel nor any other trademark owned or controlled by
 * Intel shall be used in advertising or otherwise to promote the sale, use or
 * other dealings in products derived from or relating to the Covered Code
 * without prior written authorization from Intel.
 *
 * 4. Disclaimer and Export Compliance
 *
 * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED
 * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE
 * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,
 * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY
 * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY
 * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES
 * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR
 * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,
 * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY
 * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL
 * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS
 * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY
 * LIMITED REMEDY.
 *
 * 4.3. Licensee shall not export, either directly or indirectly, any of this
 * software or system incorporating such software without first obtaining any
 * required license or other approval from the U. S. Department of Commerce or
 * any other agency or department of the United States Government. In the
 * event Licensee exports any such software from the United States or
 * re-exports any such software from a foreign destination, Licensee shall
 * ensure that the distribution and export/re-export of the software is in
 * compliance with all laws, regulations, orders, or other restrictions of the
 * U.S. Export Administration Regulations. Licensee agrees that neither it nor
 * any of its subsidiaries will export/re-export any technical data, process,
 * software, or service, directly or indirectly, to any country for which the
 * United States government or any agency thereof requires an export license,
 * other governmental approval, or letter of assurance, without first obtaining
 * such license, approval or letter.
 *
 *****************************************************************************
 *
 * Alternatively, you may choose to be licensed under the terms of the
 * following license:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions, and the following disclaimer,
 *    without modification.
 * 2. Redistributions in binary form must reproduce at minimum a disclaimer
 *    substantially similar to the "NO WARRANTY" disclaimer below
 *    ("Disclaimer") and any redistribution must be conditioned upon
 *    including a substantially similar Disclaimer requirement for further
 *    binary redistribution.
 * 3. Neither the names of the above-listed copyright holders nor the names
 *    of any contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Alternatively, you may choose to be licensed under the terms of the
 * GNU General Public License ("GPL") version 2 as published by the Free
 * Software Foundation.
 *
 *****************************************************************************/

#include <contrib/dev/acpica/compiler/aslcompiler.h>
#include <contrib/dev/acpica/include/acpi.h>
#include <contrib/dev/acpica/include/accommon.h>

#define _COMPONENT          ACPI_COMPILER
        ACPI_MODULE_NAME    ("aslparse")

/*
 * Global Notes:
 *
 * October 2005: The following list terms have been optimized (from the
 * original ASL grammar in the ACPI specification) to force the immediate
 * reduction of each list item so that the parse stack use doesn't increase on
 * each list element and possibly overflow on very large lists (>4000 items).
 * This dramatically reduces use of the parse stack overall.
 *
 *      ArgList, TermList, ByteList, DWordList, PackageList,
 *      ResourceMacroList, and FieldUnitList
 */

void *
AslLocalAllocate (
    unsigned int            Size);


/* Bison/yacc configuration */

#define static
#undef malloc
#define malloc              AslLocalAllocate
#undef alloca
#define alloca              AslLocalAllocate
#define yytname             AslCompilername

#define YYINITDEPTH         600             /* State stack depth */
#define YYDEBUG             1               /* Enable debug output */
#define YYERROR_VERBOSE     1               /* Verbose error messages */
#define YYFLAG              -32768

/* Define YYMALLOC/YYFREE to prevent redefinition errors  */

#define YYMALLOC            AslLocalAllocate
#define YYFREE              ACPI_FREE
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 201 "aslcompiler.y"
typedef union {
    UINT64              i;
    char                *s;
    ACPI_PARSE_OBJECT   *n;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 309 "aslcompilerparse.c"

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

#define PARSEOP_ACCESSAS 257
#define PARSEOP_ACCESSATTRIB_BLOCK 258
#define PARSEOP_ACCESSATTRIB_BLOCK_CALL 259
#define PARSEOP_ACCESSATTRIB_BYTE 260
#define PARSEOP_ACCESSATTRIB_MULTIBYTE 261
#define PARSEOP_ACCESSATTRIB_QUICK 262
#define PARSEOP_ACCESSATTRIB_RAW_BYTES 263
#define PARSEOP_ACCESSATTRIB_RAW_PROCESS 264
#define PARSEOP_ACCESSATTRIB_SND_RCV 265
#define PARSEOP_ACCESSATTRIB_WORD 266
#define PARSEOP_ACCESSATTRIB_WORD_CALL 267
#define PARSEOP_ACCESSTYPE_ANY 268
#define PARSEOP_ACCESSTYPE_BUF 269
#define PARSEOP_ACCESSTYPE_BYTE 270
#define PARSEOP_ACCESSTYPE_DWORD 271
#define PARSEOP_ACCESSTYPE_QWORD 272
#define PARSEOP_ACCESSTYPE_WORD 273
#define PARSEOP_ACQUIRE 274
#define PARSEOP_ADD 275
#define PARSEOP_ADDRESSINGMODE_7BIT 276
#define PARSEOP_ADDRESSINGMODE_10BIT 277
#define PARSEOP_ADDRESSTYPE_ACPI 278
#define PARSEOP_ADDRESSTYPE_MEMORY 279
#define PARSEOP_ADDRESSTYPE_NVS 280
#define PARSEOP_ADDRESSTYPE_RESERVED 281
#define PARSEOP_ALIAS 282
#define PARSEOP_AND 283
#define PARSEOP_ARG0 284
#define PARSEOP_ARG1 285
#define PARSEOP_ARG2 286
#define PARSEOP_ARG3 287
#define PARSEOP_ARG4 288
#define PARSEOP_ARG5 289
#define PARSEOP_ARG6 290
#define PARSEOP_BANKFIELD 291
#define PARSEOP_BITSPERBYTE_EIGHT 292
#define PARSEOP_BITSPERBYTE_FIVE 293
#define PARSEOP_BITSPERBYTE_NINE 294
#define PARSEOP_BITSPERBYTE_SEVEN 295
#define PARSEOP_BITSPERBYTE_SIX 296
#define PARSEOP_BREAK 297
#define PARSEOP_BREAKPOINT 298
#define PARSEOP_BUFFER 299
#define PARSEOP_BUSMASTERTYPE_MASTER 300
#define PARSEOP_BUSMASTERTYPE_NOTMASTER 301
#define PARSEOP_BYTECONST 302
#define PARSEOP_CASE 303
#define PARSEOP_CLOCKPHASE_FIRST 304
#define PARSEOP_CLOCKPHASE_SECOND 305
#define PARSEOP_CLOCKPOLARITY_HIGH 306
#define PARSEOP_CLOCKPOLARITY_LOW 307
#define PARSEOP_CONCATENATE 308
#define PARSEOP_CONCATENATERESTEMPLATE 309
#define PARSEOP_CONDREFOF 310
#define PARSEOP_CONNECTION 311
#define PARSEOP_CONTINUE 312
#define PARSEOP_COPYOBJECT 313
#define PARSEOP_CREATEBITFIELD 314
#define PARSEOP_CREATEBYTEFIELD 315
#define PARSEOP_CREATEDWORDFIELD 316
#define PARSEOP_CREATEFIELD 317
#define PARSEOP_CREATEQWORDFIELD 318
#define PARSEOP_CREATEWORDFIELD 319
#define PARSEOP_DATABUFFER 320
#define PARSEOP_DATATABLEREGION 321
#define PARSEOP_DEBUG 322
#define PARSEOP_DECODETYPE_POS 323
#define PARSEOP_DECODETYPE_SUB 324
#define PARSEOP_DECREMENT 325
#define PARSEOP_DEFAULT 326
#define PARSEOP_DEFAULT_ARG 327
#define PARSEOP_DEFINITION_BLOCK 328
#define PARSEOP_DEREFOF 329
#define PARSEOP_DEVICE 330
#define PARSEOP_DEVICEPOLARITY_HIGH 331
#define PARSEOP_DEVICEPOLARITY_LOW 332
#define PARSEOP_DIVIDE 333
#define PARSEOP_DMA 334
#define PARSEOP_DMATYPE_A 335
#define PARSEOP_DMATYPE_COMPATIBILITY 336
#define PARSEOP_DMATYPE_B 337
#define PARSEOP_DMATYPE_F 338
#define PARSEOP_DWORDCONST 339
#define PARSEOP_DWORDIO 340
#define PARSEOP_DWORDMEMORY 341
#define PARSEOP_DWORDSPACE 342
#define PARSEOP_EISAID 343
#define PARSEOP_ELSE 344
#define PARSEOP_ELSEIF 345
#define PARSEOP_ENDDEPENDENTFN 346
#define PARSEOP_ENDIAN_BIG 347
#define PARSEOP_ENDIAN_LITTLE 348
#define PARSEOP_ENDTAG 349
#define PARSEOP_ERRORNODE 350
#define PARSEOP_EVENT 351
#define PARSEOP_EXTENDEDIO 352
#define PARSEOP_EXTENDEDMEMORY 353
#define PARSEOP_EXTENDEDSPACE 354
#define PARSEOP_EXTERNAL 355
#define PARSEOP_FATAL 356
#define PARSEOP_FIELD 357
#define PARSEOP_FINDSETLEFTBIT 358
#define PARSEOP_FINDSETRIGHTBIT 359
#define PARSEOP_FIXEDDMA 360
#define PARSEOP_FIXEDIO 361
#define PARSEOP_FLOWCONTROL_HW 362
#define PARSEOP_FLOWCONTROL_NONE 363
#define PARSEOP_FLOWCONTROL_SW 364
#define PARSEOP_FROMBCD 365
#define PARSEOP_FUNCTION 366
#define PARSEOP_GPIO_INT 367
#define PARSEOP_GPIO_IO 368
#define PARSEOP_I2C_SERIALBUS 369
#define PARSEOP_I2C_SERIALBUS_V2 370
#define PARSEOP_IF 371
#define PARSEOP_INCLUDE 372
#define PARSEOP_INCLUDE_END 373
#define PARSEOP_INCREMENT 374
#define PARSEOP_INDEX 375
#define PARSEOP_INDEXFIELD 376
#define PARSEOP_INTEGER 377
#define PARSEOP_INTERRUPT 378
#define PARSEOP_INTLEVEL_ACTIVEBOTH 379
#define PARSEOP_INTLEVEL_ACTIVEHIGH 380
#define PARSEOP_INTLEVEL_ACTIVELOW 381
#define PARSEOP_INTTYPE_EDGE 382
#define PARSEOP_INTTYPE_LEVEL 383
#define PARSEOP_IO 384
#define PARSEOP_IODECODETYPE_10 385
#define PARSEOP_IODECODETYPE_16 386
#define PARSEOP_IORESTRICT_IN 387
#define PARSEOP_IORESTRICT_NONE 388
#define PARSEOP_IORESTRICT_OUT 389
#define PARSEOP_IORESTRICT_PRESERVE 390
#define PARSEOP_IRQ 391
#define PARSEOP_IRQNOFLAGS 392
#define PARSEOP_LAND 393
#define PARSEOP_LEQUAL 394
#define PARSEOP_LGREATER 395
#define PARSEOP_LGREATEREQUAL 396
#define PARSEOP_LLESS 397
#define PARSEOP_LLESSEQUAL 398
#define PARSEOP_LNOT 399
#define PARSEOP_LNOTEQUAL 400
#define PARSEOP_LOAD 401
#define PARSEOP_LOADTABLE 402
#define PARSEOP_LOCAL0 403
#define PARSEOP_LOCAL1 404
#define PARSEOP_LOCAL2 405
#define PARSEOP_LOCAL3 406
#define PARSEOP_LOCAL4 407
#define PARSEOP_LOCAL5 408
#define PARSEOP_LOCAL6 409
#define PARSEOP_LOCAL7 410
#define PARSEOP_LOCKRULE_LOCK 411
#define PARSEOP_LOCKRULE_NOLOCK 412
#define PARSEOP_LOR 413
#define PARSEOP_MATCH 414
#define PARSEOP_MATCHTYPE_MEQ 415
#define PARSEOP_MATCHTYPE_MGE 416
#define PARSEOP_MATCHTYPE_MGT 417
#define PARSEOP_MATCHTYPE_MLE 418
#define PARSEOP_MATCHTYPE_MLT 419
#define PARSEOP_MATCHTYPE_MTR 420
#define PARSEOP_MAXTYPE_FIXED 421
#define PARSEOP_MAXTYPE_NOTFIXED 422
#define PARSEOP_MEMORY24 423
#define PARSEOP_MEMORY32 424
#define PARSEOP_MEMORY32FIXED 425
#define PARSEOP_MEMTYPE_CACHEABLE 426
#define PARSEOP_MEMTYPE_NONCACHEABLE 427
#define PARSEOP_MEMTYPE_PREFETCHABLE 428
#define PARSEOP_MEMTYPE_WRITECOMBINING 429
#define PARSEOP_METHOD 430
#define PARSEOP_METHODCALL 431
#define PARSEOP_MID 432
#define PARSEOP_MINTYPE_FIXED 433
#define PARSEOP_MINTYPE_NOTFIXED 434
#define PARSEOP_MOD 435
#define PARSEOP_MULTIPLY 436
#define PARSEOP_MUTEX 437
#define PARSEOP_NAME 438
#define PARSEOP_NAMESEG 439
#define PARSEOP_NAMESTRING 440
#define PARSEOP_NAND 441
#define PARSEOP_NOOP 442
#define PARSEOP_NOR 443
#define PARSEOP_NOT 444
#define PARSEOP_NOTIFY 445
#define PARSEOP_OBJECTTYPE 446
#define PARSEOP_OBJECTTYPE_BFF 447
#define PARSEOP_OBJECTTYPE_BUF 448
#define PARSEOP_OBJECTTYPE_DDB 449
#define PARSEOP_OBJECTTYPE_DEV 450
#define PARSEOP_OBJECTTYPE_EVT 451
#define PARSEOP_OBJECTTYPE_FLD 452
#define PARSEOP_OBJECTTYPE_INT 453
#define PARSEOP_OBJECTTYPE_MTH 454
#define PARSEOP_OBJECTTYPE_MTX 455
#define PARSEOP_OBJECTTYPE_OPR 456
#define PARSEOP_OBJECTTYPE_PKG 457
#define PARSEOP_OBJECTTYPE_POW 458
#define PARSEOP_OBJECTTYPE_PRO 459
#define PARSEOP_OBJECTTYPE_STR 460
#define PARSEOP_OBJECTTYPE_THZ 461
#define PARSEOP_OBJECTTYPE_UNK 462
#define PARSEOP_OFFSET 463
#define PARSEOP_ONE 464
#define PARSEOP_ONES 465
#define PARSEOP_OPERATIONREGION 466
#define PARSEOP_OR 467
#define PARSEOP_PACKAGE 468
#define PARSEOP_PACKAGE_LENGTH 469
#define PARSEOP_PARITYTYPE_EVEN 470
#define PARSEOP_PARITYTYPE_MARK 471
#define PARSEOP_PARITYTYPE_NONE 472
#define PARSEOP_PARITYTYPE_ODD 473
#define PARSEOP_PARITYTYPE_SPACE 474
#define PARSEOP_PINCONFIG 475
#define PARSEOP_PINFUNCTION 476
#define PARSEOP_PINGROUP 477
#define PARSEOP_PINGROUPCONFIG 478
#define PARSEOP_PINGROUPFUNCTION 479
#define PARSEOP_PIN_NOPULL 480
#define PARSEOP_PIN_PULLDEFAULT 481
#define PARSEOP_PIN_PULLDOWN 482
#define PARSEOP_PIN_PULLUP 483
#define PARSEOP_POWERRESOURCE 484
#define PARSEOP_PROCESSOR 485
#define PARSEOP_QWORDCONST 486
#define PARSEOP_QWORDIO 487
#define PARSEOP_QWORDMEMORY 488
#define PARSEOP_QWORDSPACE 489
#define PARSEOP_RANGETYPE_ENTIRE 490
#define PARSEOP_RANGETYPE_ISAONLY 491
#define PARSEOP_RANGETYPE_NONISAONLY 492
#define PARSEOP_RAW_DATA 493
#define PARSEOP_READWRITETYPE_BOTH 494
#define PARSEOP_READWRITETYPE_READONLY 495
#define PARSEOP_REFOF 496
#define PARSEOP_REGIONSPACE_CMOS 497
#define PARSEOP_REGIONSPACE_EC 498
#define PARSEOP_REGIONSPACE_FFIXEDHW 499
#define PARSEOP_REGIONSPACE_GPIO 500
#define PARSEOP_REGIONSPACE_GSBUS 501
#define PARSEOP_REGIONSPACE_IO 502
#define PARSEOP_REGIONSPACE_IPMI 503
#define PARSEOP_REGIONSPACE_MEM 504
#define PARSEOP_REGIONSPACE_PCC 505
#define PARSEOP_REGIONSPACE_PCI 506
#define PARSEOP_REGIONSPACE_PCIBAR 507
#define PARSEOP_REGIONSPACE_SMBUS 508
#define PARSEOP_REGISTER 509
#define PARSEOP_RELEASE 510
#define PARSEOP_RESERVED_BYTES 511
#define PARSEOP_RESET 512
#define PARSEOP_RESOURCETEMPLATE 513
#define PARSEOP_RESOURCETYPE_CONSUMER 514
#define PARSEOP_RESOURCETYPE_PRODUCER 515
#define PARSEOP_RETURN 516
#define PARSEOP_REVISION 517
#define PARSEOP_SCOPE 518
#define PARSEOP_SERIALIZERULE_NOTSERIAL 519
#define PARSEOP_SERIALIZERULE_SERIAL 520
#define PARSEOP_SHARETYPE_EXCLUSIVE 521
#define PARSEOP_SHARETYPE_EXCLUSIVEWAKE 522
#define PARSEOP_SHARETYPE_SHARED 523
#define PARSEOP_SHARETYPE_SHAREDWAKE 524
#define PARSEOP_SHIFTLEFT 525
#define PARSEOP_SHIFTRIGHT 526
#define PARSEOP_SIGNAL 527
#define PARSEOP_SIZEOF 528
#define PARSEOP_SLAVEMODE_CONTROLLERINIT 529
#define PARSEOP_SLAVEMODE_DEVICEINIT 530
#define PARSEOP_SLEEP 531
#define PARSEOP_SPI_SERIALBUS 532
#define PARSEOP_SPI_SERIALBUS_V2 533
#define PARSEOP_STALL 534
#define PARSEOP_STARTDEPENDENTFN 535
#define PARSEOP_STARTDEPENDENTFN_NOPRI 536
#define PARSEOP_STOPBITS_ONE 537
#define PARSEOP_STOPBITS_ONEPLUSHALF 538
#define PARSEOP_STOPBITS_TWO 539
#define PARSEOP_STOPBITS_ZERO 540
#define PARSEOP_STORE 541
#define PARSEOP_STRING_LITERAL 542
#define PARSEOP_SUBTRACT 543
#define PARSEOP_SWITCH 544
#define PARSEOP_THERMALZONE 545
#define PARSEOP_TIMER 546
#define PARSEOP_TOBCD 547
#define PARSEOP_TOBUFFER 548
#define PARSEOP_TODECIMALSTRING 549
#define PARSEOP_TOHEXSTRING 550
#define PARSEOP_TOINTEGER 551
#define PARSEOP_TOSTRING 552
#define PARSEOP_TOUUID 553
#define PARSEOP_TRANSLATIONTYPE_DENSE 554
#define PARSEOP_TRANSLATIONTYPE_SPARSE 555
#define PARSEOP_TYPE_STATIC 556
#define PARSEOP_TYPE_TRANSLATION 557
#define PARSEOP_UART_SERIALBUS 558
#define PARSEOP_UART_SERIALBUS_V2 559
#define PARSEOP_UNICODE 560
#define PARSEOP_UNLOAD 561
#define PARSEOP_UPDATERULE_ONES 562
#define PARSEOP_UPDATERULE_PRESERVE 563
#define PARSEOP_UPDATERULE_ZEROS 564
#define PARSEOP_VAR_PACKAGE 565
#define PARSEOP_VENDORLONG 566
#define PARSEOP_VENDORSHORT 567
#define PARSEOP_WAIT 568
#define PARSEOP_WHILE 569
#define PARSEOP_WIREMODE_FOUR 570
#define PARSEOP_WIREMODE_THREE 571
#define PARSEOP_WORDBUSNUMBER 572
#define PARSEOP_WORDCONST 573
#define PARSEOP_WORDIO 574
#define PARSEOP_WORDSPACE 575
#define PARSEOP_XFERSIZE_8 576
#define PARSEOP_XFERSIZE_16 577
#define PARSEOP_XFERSIZE_32 578
#define PARSEOP_XFERSIZE_64 579
#define PARSEOP_XFERSIZE_128 580
#define PARSEOP_XFERSIZE_256 581
#define PARSEOP_XFERTYPE_8 582
#define PARSEOP_XFERTYPE_8_16 583
#define PARSEOP_XFERTYPE_16 584
#define PARSEOP_XOR 585
#define PARSEOP_ZERO 586
#define PARSEOP_TOPLD 587
#define PARSEOP_PLD_REVISION 588
#define PARSEOP_PLD_IGNORECOLOR 589
#define PARSEOP_PLD_RED 590
#define PARSEOP_PLD_GREEN 591
#define PARSEOP_PLD_BLUE 592
#define PARSEOP_PLD_WIDTH 593
#define PARSEOP_PLD_HEIGHT 594
#define PARSEOP_PLD_USERVISIBLE 595
#define PARSEOP_PLD_DOCK 596
#define PARSEOP_PLD_LID 597
#define PARSEOP_PLD_PANEL 598
#define PARSEOP_PLD_VERTICALPOSITION 599
#define PARSEOP_PLD_HORIZONTALPOSITION 600
#define PARSEOP_PLD_SHAPE 601
#define PARSEOP_PLD_GROUPORIENTATION 602
#define PARSEOP_PLD_GROUPTOKEN 603
#define PARSEOP_PLD_GROUPPOSITION 604
#define PARSEOP_PLD_BAY 605
#define PARSEOP_PLD_EJECTABLE 606
#define PARSEOP_PLD_EJECTREQUIRED 607
#define PARSEOP_PLD_CABINETNUMBER 608
#define PARSEOP_PLD_CARDCAGENUMBER 609
#define PARSEOP_PLD_REFERENCE 610
#define PARSEOP_PLD_ROTATION 611
#define PARSEOP_PLD_ORDER 612
#define PARSEOP_PLD_RESERVED 613
#define PARSEOP_PLD_VERTICALOFFSET 614
#define PARSEOP_PLD_HORIZONTALOFFSET 615
#define PARSEOP_EXP_EQUALS 616
#define PARSEOP_EXP_ADD_EQ 617
#define PARSEOP_EXP_SUB_EQ 618
#define PARSEOP_EXP_MUL_EQ 619
#define PARSEOP_EXP_DIV_EQ 620
#define PARSEOP_EXP_MOD_EQ 621
#define PARSEOP_EXP_SHL_EQ 622
#define PARSEOP_EXP_SHR_EQ 623
#define PARSEOP_EXP_AND_EQ 624
#define PARSEOP_EXP_XOR_EQ 625
#define PARSEOP_EXP_OR_EQ 626
#define PARSEOP_EXP_LOGICAL_OR 627
#define PARSEOP_EXP_LOGICAL_AND 628
#define PARSEOP_EXP_OR 629
#define PARSEOP_EXP_XOR 630
#define PARSEOP_EXP_AND 631
#define PARSEOP_EXP_EQUAL 632
#define PARSEOP_EXP_NOT_EQUAL 633
#define PARSEOP_EXP_GREATER 634
#define PARSEOP_EXP_LESS 635
#define PARSEOP_EXP_GREATER_EQUAL 636
#define PARSEOP_EXP_LESS_EQUAL 637
#define PARSEOP_EXP_SHIFT_RIGHT 638
#define PARSEOP_EXP_SHIFT_LEFT 639
#define PARSEOP_EXP_ADD 640
#define PARSEOP_EXP_SUBTRACT 641
#define PARSEOP_EXP_MULTIPLY 642
#define PARSEOP_EXP_DIVIDE 643
#define PARSEOP_EXP_MODULO 644
#define PARSEOP_EXP_NOT 645
#define PARSEOP_EXP_LOGICAL_NOT 646
#define PARSEOP_EXP_INCREMENT 647
#define PARSEOP_EXP_DECREMENT 648
#define PARSEOP_OPEN_PAREN 649
#define PARSEOP_CLOSE_PAREN 650
#define PARSEOP_EXP_INDEX_LEFT 651
#define PARSEOP_EXP_INDEX_RIGHT 652
#define PARSEOP_PRINTF 653
#define PARSEOP_FPRINTF 654
#define PARSEOP_FOR 655
#define PARSEOP_STRUCTURE 656
#define PARSEOP_STRUCTURE_NAMESTRING 657
#define PARSEOP_STRUCTURE_TAG 658
#define PARSEOP_STRUCTURE_ELEMENT 659
#define PARSEOP_STRUCTURE_INSTANCE 660
#define PARSEOP_STRUCTURE_REFERENCE 661
#define PARSEOP_STRUCTURE_POINTER 662
#define PARSEOP_ASL_CODE 663
#define PARSEOP_INTEGER_TYPE 664
#define PARSEOP_STRING_TYPE 665
#define PARSEOP_BUFFER_TYPE 666
#define PARSEOP_PACKAGE_TYPE 667
#define PARSEOP_REFERENCE_TYPE 668
#define PARSEOP___DATE__ 669
#define PARSEOP___FILE__ 670
#define PARSEOP___LINE__ 671
#define PARSEOP___PATH__ 672
#define PARSEOP___METHOD__ 673
#define YYERRCODE 256
typedef int YYINT;
static const YYINT AslCompilerlhs[] = {                  -1,
    0,    0,  316,  317,    6,    7,    7,  240,  240,  240,
  240,  240,  240,  239,   21,   21,   21,   21,   21,   21,
   21,   21,  178,  178,  178,   20,   20,   20,   17,   22,
   22,   22,   22,  318,   24,  271,  271,  271,  272,  272,
  272,  272,  272,  272,   23,   23,   23,   23,   23,    1,
    1,    1,    1,  200,  200,  200,  200,  198,  198,  198,
  198,   38,   38,   38,   38,   36,   36,   36,   36,   37,
   37,   11,   11,   11,  202,  202,  202,  202,  201,  201,
   13,   13,   13,   14,   14,   14,  287,  287,   15,   15,
   16,   16,   16,  288,  288,   67,   67,   67,   67,   67,
    5,    5,    5,    5,    2,    2,    2,    2,   12,    8,
    8,    8,    8,   19,   19,  187,  188,  189,  190,  194,
  194,  194,  194,  195,  195,  195,  195,  196,  196,  196,
  196,  197,  197,  197,  197,  192,  192,  193,  193,  193,
  193,  193,  193,  193,  193,  186,  191,    4,    4,    4,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,   10,
   10,   10,   18,   18,   18,  179,  179,  179,  179,  179,
  179,  180,  180,  180,  180,  180,  180,  180,  180,  181,
  181,  181,  181,  181,  182,  182,  182,  182,  182,   25,
   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,
   25,   25,   25,   25,   25,   25,   25,   29,   29,   29,
   29,   29,   29,   29,   29,   29,   29,   29,   29,   28,
   28,   28,   28,   28,   28,   28,   28,   28,   28,   28,
   28,   28,   28,   28,   28,   28,   28,   28,   28,   28,
   28,   28,   28,   28,   28,   28,   28,   28,   28,   28,
   28,   28,   30,   30,   30,   26,   26,   27,   27,   27,
   27,   31,   32,   32,   32,   32,   33,   33,   33,   33,
   33,  261,  263,  263,  264,  264,  294,  294,  294,  298,
  298,  299,  299,  299,  305,  305,  310,  310,   34,   34,
  319,   87,   87,  320,   88,   88,  321,   62,   62,  322,
   89,   89,  183,  183,  183,  183,  183,  183,  183,  323,
   42,   42,   66,   65,  324,  199,    3,    3,  325,   68,
   68,  326,   91,   91,  327,   90,   90,  328,   92,   92,
  217,  329,  217,  217,   69,  330,   93,   93,  331,   43,
   43,  332,   44,   44,  333,   45,   45,  334,   46,   46,
  335,   47,   47,  336,   48,   48,  337,   49,   49,  185,
  338,   94,   94,  339,   70,   70,  340,   95,   95,  341,
   50,   50,  342,   96,   96,  204,  204,   73,   71,  343,
   71,   71,   71,  344,  345,  346,  347,   71,   71,   71,
  348,   51,   51,   35,   35,  349,   72,   72,  350,   52,
   52,  351,   97,   97,  352,   98,   98,  353,  354,  355,
  356,  216,  291,  291,  357,  215,  215,  358,   99,   99,
  359,  360,   53,   53,  361,   74,   74,   39,  262,  362,
  100,  100,  363,   54,   54,  364,  101,  101,  365,  102,
  102,  366,  103,  103,  367,  104,  104,  368,  105,  105,
  369,  106,  106,  370,  107,  107,  371,  108,  108,  372,
  109,  109,  373,  110,  110,  374,   75,   75,  184,  184,
  184,  184,  184,  184,  184,  184,  375,  111,  111,  376,
  112,  112,  377,  378,  379,   55,   55,  380,  113,  113,
  381,  114,  114,  382,  115,  115,  383,   56,   56,  384,
   63,   63,  385,  116,  116,   76,  386,  117,  117,  387,
   77,   77,  388,  118,  118,  389,  119,  119,   40,   40,
  390,   57,   57,   58,   58,  391,  120,  120,  392,  203,
  393,   59,   59,  394,  214,  214,  213,  213,  213,  395,
   60,   60,  396,  121,  121,  397,  122,  122,  398,   78,
   78,  399,   79,   79,  400,   80,   80,   80,  401,   64,
   64,  402,  123,  123,  403,  124,  124,  404,   81,   81,
  405,  125,  125,  406,   82,   82,  407,   83,   83,  408,
  126,  126,  409,  127,  127,  410,   84,   84,  411,   61,
   61,  412,  128,  128,  128,  413,  129,  129,  414,  130,
  130,  415,  131,  131,  416,  132,  132,  417,  133,  133,
  418,  210,  210,  209,  209,  209,  209,  209,  209,  419,
  134,  134,  211,  211,  420,  212,  212,  421,   85,   85,
  422,  135,  135,  423,  136,  136,  424,   86,   86,  425,
  313,  426,  313,  427,  313,  428,  313,  429,  313,  430,
  313,  431,  313,  432,  313,  433,  313,  434,  313,  435,
  313,  436,  313,  437,  313,  438,  313,  439,  313,  440,
  313,  441,  313,  442,  313,  443,  313,  444,  313,  445,
  313,  446,  313,  313,  313,  315,  314,  314,  314,  447,
  314,  448,  314,  449,  314,  450,  314,  451,  314,  452,
  314,  453,  314,  454,  314,  455,  314,  456,  314,  137,
  137,  137,  137,  137,  137,  137,  457,  137,  458,  137,
  459,  137,  138,  138,  138,  138,  138,  138,  139,  139,
  140,  140,  140,  140,  141,  141,  142,  142,  142,  142,
  142,  143,  143,  144,  144,  145,  145,  146,  146,  147,
  147,  147,  147,  148,  148,  149,  149,  149,  150,  150,
  150,  151,  151,  152,  152,  153,  153,  153,  153,  154,
  154,  155,  155,  155,  155,  155,  155,  156,  156,  157,
  157,  157,  157,  158,  158,  159,  159,  159,  159,  159,
  159,  159,  159,  159,  159,  159,  159,  159,  159,  159,
  159,  162,  162,  162,  162,  162,  163,  163,  164,  164,
  164,  164,  208,  208,  208,  208,  208,  208,  208,  208,
  208,  208,  208,  208,  208,  208,  208,  208,  208,  208,
  208,  208,  208,  208,  208,  208,  208,  208,  208,  208,
  165,  165,  165,  166,  166,  166,  166,  166,  166,  166,
  166,  166,  166,  166,  166,  167,  167,  168,  168,  169,
  169,  169,  169,  170,  170,  171,  171,  171,  171,  172,
  172,  173,  173,  174,  174,  174,  175,  175,  176,  176,
  176,  176,  176,  176,  177,  177,  177,  460,  207,  289,
  289,  205,  205,  206,  206,  206,  206,  206,  206,  206,
  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,
  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,
  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,
  206,  206,  206,  206,  461,  218,  218,  462,  219,  219,
  463,  220,  220,  464,  465,  221,  221,  222,  222,  466,
  223,  223,  467,  224,  224,  468,  469,  225,  225,  470,
  226,  226,  471,  227,  227,  472,  228,  228,  473,  229,
  229,  474,  230,  230,  475,  231,  231,  476,  232,  232,
  477,  233,  233,  478,  234,  234,  479,  235,  235,  480,
  236,  236,  481,  237,  237,  482,  238,  238,  483,  241,
  241,  484,  242,  242,  485,  243,  243,  486,  244,  244,
  487,  245,  245,  488,  246,  246,  489,  247,  247,  490,
  491,  248,  248,  492,  249,  249,  493,  250,  250,  494,
  251,  251,  495,  252,  252,  496,  253,  253,  497,  254,
  254,  498,  255,  255,  499,  256,  256,  500,  257,  257,
  501,  258,  258,  502,  259,  259,  503,  504,  260,  260,
  160,  160,  160,   41,   41,   41,   41,  265,  265,  265,
  266,  266,  267,  267,  267,  268,  268,  269,  269,  269,
  270,  270,  270,  273,  273,  274,  274,  275,  275,  275,
  276,  276,  277,  277,  278,  278,  279,  279,  279,  280,
  280,  281,  281,  282,  282,  283,  283,  283,  285,  285,
  285,  284,  284,  286,  286,  290,  290,  292,  292,  292,
  293,  293,  161,  161,  161,  296,  296,  295,  295,  295,
  297,  297,  297,  302,  302,  300,  300,  300,  301,  301,
  303,  303,  304,  304,  304,  306,  306,  306,  307,  307,
  307,  308,  308,  308,  309,  309,  311,  311,  312,  312,
  312,
};
static const YYINT AslCompilerlen[] = {                   2,
    1,    1,    0,    0,   19,    1,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    0,    1,    2,    2,    1,
    1,    1,    3,    0,    5,    0,    1,    2,    0,    3,
    2,    1,    4,    4,    0,    2,    3,    3,    4,    0,
    1,    2,    3,    0,    1,    2,    3,    0,    1,    2,
    3,    0,    1,    2,    3,    1,    1,    1,    1,    2,
    3,    1,    1,    1,    0,    1,    2,    3,    1,    1,
    0,    1,    3,    0,    1,    3,    0,    2,    1,    3,
    0,    1,    3,    0,    2,    0,    1,    1,    2,    2,
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
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    2,    2,    2,    2,    0,    1,    2,    0,
    1,    0,    1,    2,    0,    1,    0,    1,    5,    4,
    0,    7,    4,    0,    7,    4,    0,    6,    4,    0,
    7,    4,    1,    1,    1,    1,    1,    1,    1,    0,
   16,    7,    1,    1,    0,    6,    1,    1,    0,    8,
    4,    0,    7,    4,    0,    7,    4,    0,    6,    4,
    4,    0,    5,    4,    1,    0,    7,    4,    0,    7,
    4,    0,    7,    4,    0,    7,    4,    0,    8,    4,
    0,    7,    4,    0,    7,    4,    0,    8,    4,    1,
    0,    5,    4,    0,    5,    4,    0,    5,    4,    0,
    8,    4,    0,    8,    4,    4,    4,    2,    0,    0,
    5,    4,    2,    0,    0,    0,    0,   12,    4,    2,
    0,    5,    4,    7,    4,    0,    8,    4,    0,   14,
    7,    0,    6,    4,    0,    6,    4,    0,    0,    0,
    0,   15,    0,    1,    0,    8,    4,    0,    6,    4,
    0,    0,   11,    4,    0,    8,    4,    4,    1,    0,
    5,    4,    0,   15,    7,    0,    7,    4,    0,    6,
    4,    0,    6,    4,    0,    6,    4,    0,    6,    4,
    0,    6,    4,    0,    6,    4,    0,    6,    4,    0,
    5,    4,    0,   10,    4,    0,    6,    4,    1,    1,
    1,    1,    1,    1,    1,    1,    0,    6,    4,    0,
   12,    4,    0,    0,    0,   15,    4,    0,    8,    4,
    0,    7,    4,    0,    7,    4,    0,    7,    4,    0,
    7,    4,    0,    7,    4,    1,    0,    7,    4,    0,
    6,    4,    0,    6,    4,    0,    5,    4,    4,    4,
    0,    9,    4,    1,    1,    0,    7,    4,    0,    6,
    0,   12,    4,    0,    6,    4,    0,    1,    3,    0,
   12,    4,    0,    8,    4,    0,    5,    4,    0,    5,
    4,    0,    5,    4,    0,    5,    1,    4,    0,    8,
    4,    0,    7,    4,    0,    7,    4,    0,    5,    4,
    0,    5,    4,    0,    5,    4,    0,    5,    4,    0,
    7,    4,    0,    7,    4,    0,    8,    4,    0,    8,
    4,    0,    4,    1,    4,    0,    6,    4,    0,    6,
    4,    0,    6,    4,    0,    6,    4,    0,    6,    4,
    0,    5,    4,    0,    3,    3,    2,    5,    5,    0,
    7,    4,    4,    4,    0,    5,    4,    0,    5,    4,
    0,    6,    4,    0,    7,    4,    0,    8,    4,    0,
    3,    0,    3,    0,    3,    0,    3,    0,    4,    0,
    4,    0,    4,    0,    4,    0,    4,    0,    4,    0,
    4,    0,    4,    0,    4,    0,    4,    0,    4,    0,
    4,    0,    4,    0,    4,    0,    4,    0,    4,    0,
    4,    0,    4,    3,    1,    4,    3,    3,    5,    0,
    4,    0,    4,    0,    4,    0,    4,    0,    4,    0,
    4,    0,    4,    0,    4,    0,    4,    0,    4,    1,
    1,    1,    1,    1,    1,    1,    0,    5,    0,    5,
    0,    5,    1,    1,    1,    1,    1,    1,    1,    1,
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
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    0,    6,    0,
    2,    0,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    0,   12,    4,    0,   24,    4,
    0,   26,    4,    0,    0,   25,    4,    3,    4,    0,
   23,    4,    0,   25,    4,    0,    0,   24,    4,    0,
    9,    4,    0,    8,    4,    0,   20,    4,    0,   19,
    4,    0,   15,    4,    0,   16,    4,    0,   16,    4,
    0,   14,    4,    0,    8,    4,    0,   12,    4,    0,
   14,    4,    0,   10,    4,    0,   14,    4,    0,   18,
    4,    0,   18,    4,    0,   11,    4,    0,   17,    4,
    0,   15,    4,    0,   24,    4,    0,   26,    4,    0,
    0,   25,    4,    0,   13,    4,    0,   22,    4,    0,
   23,    4,    0,    7,    4,    0,   10,    4,    0,   22,
    4,    0,   23,    4,    0,    8,    4,    0,    8,    4,
    0,   21,    4,    0,   24,    4,    0,    0,   25,    4,
    1,    2,    2,    0,    1,    2,    2,    0,    1,    2,
    1,    2,    0,    1,    2,    1,    2,    0,    1,    2,
    0,    1,    2,    1,    2,    1,    2,    0,    1,    2,
    1,    2,    1,    2,    1,    2,    0,    1,    2,    1,
    2,    1,    2,    1,    2,    0,    1,    2,    0,    1,
    2,    0,    1,    0,    2,    1,    2,    0,    1,    2,
    1,    2,    0,    1,    1,    0,    1,    0,    1,    2,
    0,    1,    2,    1,    2,    0,    1,    2,    0,    1,
    1,    2,    0,    1,    2,    0,    1,    2,    0,    1,
    2,    0,    1,    2,    1,    2,    1,    2,    0,    1,
    2,
};
static const YYINT AslCompilerdefred[] = {                0,
    2,    0,    0,    0,    1,    3,    7,    0,  147,    0,
    0,    0,    0,  146,  116,    0,    0,    0,    0,    0,
    0,  118,    0,    4,    0,   45,    0,   22,    0,    0,
    0,    0,  313,  314,  315,  316,  317,  318,  319,    0,
  323,  324,  325,    0,    0,    0,  345,    0,    0,    0,
    0,    0,    0,    0,    0,  370,    0,    0,    0,    0,
   11,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  439,    0,    0,    0,   10,   12,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  479,  480,
  481,  482,  483,  484,  485,  486,    0,    0,    0,    0,
    0,    0,    0,    0,   14,    9,    0,  516,    0,    0,
    0,    0,  139,  140,    0,    0,  539,    0,    0,    0,
    0,    0,  898,    0,  137,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  138,
    0,  652,  650,    0,    0,    0,    0,  141,  142,  143,
  144,  145,    5,    0,  101,   72,   32,  103,   73,   74,
   15,  102,    0,  104,    0,    0,    0,   16,    0,    0,
    0,    0,    0,  111,  105,   25,  150,  148,  151,  152,
  153,  154,  155,  156,  157,  158,  159,  160,  161,  162,
  163,  164,  165,  166,  167,  168,  169,  170,  171,  172,
  201,  200,  202,  203,  205,    0,  206,  207,  208,  209,
  210,  211,  212,  213,  214,  215,  216,  217,  218,  231,
  232,  267,  268,  219,  220,  233,    0,  234,  235,  236,
  237,  238,    0,  240,  241,  243,  242,  245,  244,  247,
  246,  248,  249,  250,  271,  251,  252,  253,  254,  255,
  222,  256,    0,  257,  258,  224,  225,  259,  227,  260,
  266,  263,  264,  261,  265,  228,  262,    0,  175,  174,
   24,  112,  115,  113,  136,  108,  109,  272,  273,  275,
  276,  274,  269,  270,  204,    8,    0,  149,  230,  226,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   13,    0,  107,  106,
  110,   31,  114,    0,    0,    0,    0,  418,    0,   47,
  700,  712,  706,  702,  704,  708,  710,  714,  718,  716,
  692,  690,  674,  676,  672,  686,  688,  678,  682,  680,
  684,  668,  666,  658,  670,  664,  660,  662,    0,    0,
  388,    0,  654,  656,    0,   34,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   42,    0,    0,    0,
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
    0,  653,  651,   33,  694,    0,    0,    0,    0,    0,
    0,   49,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  393,    0,  400,    0,    0,  655,  657,    0,    0,  303,
   23,  281,  278,  279,  277,    0,  280,  306,    0,  309,
    0,  312,    0,    0,    0,    0,    0,    0,  334,    0,
  337,    0,  340,    0,    0,    0,    0,    0,    0,    0,
  348,    0,  351,    0,  354,    0,  357,    0,  360,    0,
  363,    0,  366,    0,  369,    0,  373,    0,  379,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  382,    0,
  385,    0,  387,  386,  403,    0,  405,    0,    0,  408,
    0,    0,    0,  123,    0,    0,    0,    0,  414,    0,
  417,    0,  430,    0,  434,    0,  437,    0,  438,  442,
    0,  448,    0,    0,    0,  451,    0,  454,    0,  460,
    0,  457,    0,  466,    0,  463,    0,  472,    0,  469,
    0,  478,    0,  475,    0,  489,    0,  492,    0,  497,
    0,  500,    0,  503,    0,  506,    0,  509,    0,  512,
    0,  515,    0,  519,    0,  525,    0,  522,    0,  528,
    0,    0,    0,    0,    0,    0,    0,  533,    0,  538,
    0,    0,  543,    0,  552,    0,  558,    0,    0,    0,
    0,    0,    0,  561,    0,  564,    0,  901,  902,  568,
    0,    0,  571,    0,  574,    0,  577,    0,  580,    0,
  583,    0,  586,    0,  589,    0,  592,    0,  595,    0,
  598,    0,  601,    0,  605,  603,  608,    0,  611,    0,
  614,    0,  617,    0,  620,    0,  632,    0,  634,  633,
  637,    0,  640,    0,  643,    0,  649,    0,  646,    0,
  623,  823,  824,  825,  826,  827,  828,  829,  830,  831,
  832,  833,  834,  835,  836,  837,  838,  839,  840,  841,
  842,  843,  844,  845,  846,  847,  848,  849,  850,    0,
    0,    0,  546,    0,  427,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  665,  661,  663,    0,    0,    0,    0,
  696,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   55,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  372,
  378,    0,    0,  402,  810,  799,  811,  802,  803,  801,
  797,  804,  805,  806,  800,  807,  808,  798,  809,  796,
 1125,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  441,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  471,    0,    0,    0,    0,    0,    0,    0,  494,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  527,
    0,    0,    0,   76,    0,    0,    0,    0,  557,  560,
  563,    0,  566,    0,    0,    0,  579,  582,  585,  588,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  636,  639,    0,    0,    0,    0,  622,    0,    0,
    0,    0,    0,  419,  392,    0,  399,    0,   35,    0,
    0,    0,    0,  127,    0,    0,  286,    0,    0,  284,
  283,  308,    0,    0,    0,   44,   43,  326,    0,    0,
    0,    0,  339,    0,  173,    0,    0,    0,    0,    0,
    0,    0,   45,    0,    0,   88,   85,    0,    0,    0,
    0,    0,  131,    0,    0,    0,  733,  738,  734,  736,
  737,  735,    0,  413,  416,  429,    0,   45,    0,    0,
    0,  450,  453,  459,  456,  465,  462,  468,    0,  477,
    0,  488,  783,  786,  787,  784,  785,  782,    0, 1093,
    0,    0,    0,    0,    0,    0,    0,    0,  524,  521,
  859,  857,  865,  862,  863,  854,  861,  855,  864,  856,
  860,  858,    0,  534,  535,    0,    0,  540,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  899,  903,  904,  905,  906,  907,  908,  909,  910,
  911,  912,  913,  914,  915,  916,  917,  918,  919,  920,
  921,  922,  923,  924,  925,  926,  927,  928,  929,  930,
  931,  932,  933,  934,  935,  936,  937,  938,  939,  940,
  941,  942,  943,  944,   45,    0,    0,    0,    0,    0,
   45,  607,  610,  613,  616,  619,    0,    0,  642,   45,
    0,  625,  626,    0,  545,    0,    0,    0,  391,    0,
    0,  302,  305,  311,  322,    0,   57,  333,  336,  347,
  350,  353,  356,    0,  362,  365,    0,    0,    0,    0,
   82,    0,   95,   92,  404,    0,  411,    0,    0,    0,
  447,  445,    0,    0,    0,    0,    0,    0,    0,  502,
  505,  508,  511,  514,  518,    0,  537,   78,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  573,  576,  591,  594,    0,    0,    0,
   97,   98,    0,  631,    0,  645,    0,    0,    0,    0,
    0,    0,    0,  359,  368,  381,  384,    0,   86,   89,
    0,  407,  780,  781,    0,  432,  436,    0,    0,    0,
    0,  869,  868,  294,    0,  499,    0,    0, 1100,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  958,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  570,    0,    0,  597,   99,  100,  600,  648,
  628,  629,  426,    0,   45,    0,   83,    0,   93,    0,
   45,    0,    0,    0,    0,    0,  532,    0,    0,  947,
  760,  761,  762,  763,    0,  950,  866,  867, 1137,    0,
  953,    0,  957,  955,  959,  962,    0,  965,    0,  969,
  967,  972,    0,  975,    0,  978,  772,  773,    0,  981,
  871,  873,  870,  872, 1150,    0,  984,    0,  987,    0,
  990,    0,  993,  775,  774,    0,  999,    0,  996, 1123,
    0, 1002, 1134, 1135,    0, 1008,    0, 1005,    0, 1011,
    0, 1014,    0, 1017,    0, 1020,    0, 1023,    0, 1026,
    0, 1029,    0, 1033, 1031, 1036,    0,  746,  745, 1039,
    0, 1042,    0, 1048,    0, 1045,    0, 1051,    0, 1054,
    0, 1057,    0, 1060,    0, 1063,    0, 1066,    0, 1070,
 1068,    0,    0,    0,   45,  420,    0,    0,   90,  885,
  884,  886,    0,    0,    0,    0,  474,    0,    0,   45,
   45,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  902,
    0,    0,    0,    0,    0,    0,    0,    0,  331,    0,
  376,    0,    0,  396,    0,    0,  433,    0,    0,    0,
    0,    0, 1072, 1073,    0,  794,  795, 1115,    0,    0,
  756,  757, 1095,    0,    0,    0,    0,    0,    0,    0,
    0,  769,  770,  771,    0,  819,  822,  820,  821,    0,
  817,  818,  874,  875, 1145,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 1143,    0,    0,    0,
    0,    0,    0,    0,    0,  759,  758, 1097,    0,    0,
    0,    0,    0,  750,  747,  751,  749,  748, 1087,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  375,    0,
    0,    0,    0,    0,  491,  495,  542,  551,  895,  896,
  897,    0,  788,  789, 1111,    0,    0, 1140,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 1118,    0,    0,    0,    0,    0,    0,    0,    0,
  887,  888, 1166,    0,    0,    0, 1044,  878,  877,  876,
  879, 1152,    0,    0,    0,    0,    0,    0,    0,   45,
   45,  397,    0,    0,    0,    0,    0,   68,   63,   66,
    0,   67,   69,    0,    0,   45,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  889,  890,  891,  892,  893,
  894, 1171,    0, 1121,  974, 1148,    0, 1168,    0,    0,
    0,    0,    0,    0,    0,  995,    0,    0,    0,    0,
    0,    0, 1090,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  902,    0,    0, 1056, 1059,    0,    0,    0,
    0,    0,  398,    0,    0,    0,    0,  282,   70,    0,
  410,    0,    0,    0,    0,  853,  851,  852, 1132,    0,
  790,  793,  792,  791, 1113,    0,    0,    0,    0,    0,
  971,    0,    0,    0,  739,  740, 1082,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  330,  421,    0,    0,    0,    0,
    0,    0,    0,    0,   65,   71,  444,  496,    0,    0,
    0,    0,    0,    0,    0,  135,    0,    0,    0,    0,
    0,  776,  778,  777,  779, 1106,    0,    0,    0,    0,
    0,    0,    0,    0, 1004,    0,    0,    0,    0,   59,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 1047,
  765,  764, 1102,    0,    0,    0,    0,    0,    0,  422,
  321,  300,    0,    0,  344,  341,    0,  530,  529,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  555,  117,
  298,    0,    0, 1016,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  815,  813,  816,  814,  812, 1127,    0,
    0,    0,    0,    0,    0,  720,  721,  722,    0,  723,
    0,    0,  724,  725,  726, 1077, 1076,  299,  343,  946,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 1155,    0,    0,  998,    0,    0,    0,    0,    0,   61,
    0,    0,    0,    0,    0, 1080,    0,    0,    0,  766,
  767,  768, 1104,    0,    0,    0,    0,    0,  727,  729,
  731,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 1035,  755,  754,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  992, 1001, 1007,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  983,    0,    0,    0,
    0,  554,    0, 1022,    0,    0,    0,  752,  753,    0,
    0,    0,    0,    0,    0,    0,  728,  730,  732,    0,
    0,    0,    0,    0,    0,    0,    0,  986,  989,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 1019,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 1010, 1013,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  980,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 1130,    0,    0,    0,  977,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 1062,    0,    0,    0,    0,    0,
  883,  882, 1161,    0,    0,    0,    0,    0,    0,    0,
 1038,    0, 1050,    0,    0,    0,    0,    0,    0,  881,
  880, 1158,  961,    0,    0,    0,    0,    0,    0, 1041,
 1053,    0,    0,  949,    0,    0,  744,  741,  743,  742,
 1085,    0,    0,  968, 1025,    0,    0, 1065,    0,    0,
  956, 1164,  964,    0, 1032, 1069,  952, 1028,
};
static const YYINT AslCompilerdgoto[] = {                 3,
  972,  165,  984,  166,  167,    4,    5,  168,  169,  170,
  171,  172, 1350, 1146, 1451, 1353, 1045,  173,  174,  991,
  175,  176,   27,  177,  178,  399,  400,  401,  402,  403,
  184,  185,  186, 1918,  187, 1919, 1920, 1921,  188, 1922,
 2114,  189,  190,  191,  192,  193,  194,  195,  196,  197,
  198,  199,  200,  201,  202,  203,  204, 1213,  205,  206,
  207,  208,  209,  210,  211,  212, 1430, 1431,  213, 1432,
  441,  214,  215,  216,  217,  218,  219,  220,  221,  222,
  223,  224,  225,  226,  227,  228,  229,  230,  231,  232,
  233,  234,  235,  236,  237,  238,  239,  240,  241,  242,
  243,  244,  245,  246,  247,  248,  249,  250,  251,  252,
  253,  254,  255,  256,  257,  258,  259,  260,  261,  262,
 1963,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  273,  274,  275,  276,  277, 2176, 1163, 2017, 2481,
 1657, 1829, 2310, 2247, 1773, 1818, 1585, 2103, 2213, 1785,
 1609, 1626, 2076, 1455, 1189, 1855, 2005, 1768, 1147, 1703,
 1635, 2159, 1790, 1791, 1999, 1214, 1589, 1464, 1615, 1795,
 1902, 2462, 2443, 1693, 1893, 1942, 1852,  278,  825,  736,
  841,  708,  279,  280,  281,  282,  754, 1114, 1153, 2066,
  283,  284,  285,  986, 1116, 2090, 2068, 2091,  286,  987,
 1064, 1065,  287,  288, 1072, 1263,  289,  930,  931,  290,
  291,  292, 1102,  293,  294,  295, 1923, 1264, 1265, 1266,
 1267, 1268, 1269, 1270, 1271, 1272, 1273, 1274, 1275, 1276,
 1277, 1278, 1279, 1280, 1281, 1282, 1283, 1284,  296,  297,
 1285, 1286, 1287, 1288, 1289, 1290, 1291, 1292, 1293, 1294,
 1295, 1296, 1297, 1298, 1299, 1300, 1301, 1302, 1303, 1304,
 1989,  298,  978,  976, 2151, 1951, 2465, 1742, 1884, 1050,
 1091,  459, 1707, 1737, 1381, 2040, 2161, 2014, 1365, 1770,
 1931, 1705, 1809, 1631, 1866,  749, 1023, 1149,  579, 2105,
 1441, 2388, 1929, 1574, 1776, 1590, 1729,  852, 1368, 1868,
 1616, 1717, 1831, 2132,  938, 2445, 2425, 2483, 1820, 2142,
 1870, 1864,  299,  300,  301,    8,   25,  679,  448,  450,
  452,  454,  456,  307, 1683,  461,  463,  465, 2052,  467,
  469,  471,  473,  475,  477,  479,  481,  483, 1685,  485,
  487,  489, 1106,  970, 1330, 1841, 1983,  493,  497,  499,
  501,  503,  641, 1328, 1753, 2110,  640,  505,  507, 1571,
  509,  512,  516,  514,  518,  520,  524,  522,  528,  526,
  532,  530,  536,  534,  538,  540,  542, 1191, 1926,  544,
  546,  548,  550,  552,  554,  556,  560,  558,  562,  564,
  566,  362,  569,  638,  571, 2089,  573,  575,  577,  581,
  583,  585,  587,  589,  591,  593,  595,  597,  599,  601,
  603,  605,  607,  609,  611,  613,  615,  631,  617,  621,
  623,  625,  629,  627,  396,  395,  676,  677,  666,  669,
  670,  668,  665,  664,  667,  657,  655,  656,  660,  662,
  661,  663,  658,  659,  654,  653,  643,  646,  647,  645,
  648,  649,  644,  650,  652,  651, 2254, 2255, 2256,  368,
 1472, 1474, 1476, 1478, 1708, 1482, 1484, 1486, 1711, 1488,
 1490, 1492, 1494, 1496, 1498, 1500, 1502, 1506, 1504, 1508,
 1512, 1510, 1514, 1516, 1518, 1520, 1522, 1524, 1526, 1528,
 1734, 1530, 1532, 1534, 1538, 1536, 1540, 1542, 1544, 1546,
 1548, 1550, 1552, 1748,
};
static const YYINT AslCompilersindex[] = {             -139,
    0, -481,    0, -149,    0,    0,    0, -326,    0,  138,
 -326,  177, -146,    0,    0,  190, -326,  211, -326,  220,
 -146,    0, -381,    0,  152,    0,21279,    0, -372, -368,
 -359, -357,    0,    0,    0,    0,    0,    0,    0, -351,
    0,    0,    0, -345, -332, -309,    0, -305, -282, -280,
 -275, -271, -269, -260, -246,    0, -244, -242, -238, -236,
    0, -234, -232, -230, -220, -217, -215, -212, -202, -200,
 -191, -183,    0, -181, -179, -171,    0,    0, -169, -160,
 -158, -147,  -99,  -93,  -88,  -83,  -77,  -68,    0,    0,
    0,    0,    0,    0,    0,    0,  -66,  -63,  -56,  -44,
  -42,  -38,  -35,  -33,    0,    0,  -25,    0,  -19,   -9,
   -7,   15,    0,    0,   17,   87,    0,   90,  101,  118,
  135,  141,    0,  145,    0,  154,  169,  193,  202,  210,
  216,  218,  222,  240,  262,  304,  307,  310,  320,  327,
  330,  332,  334,  343,  345,  369,  372,  377,  379,    0,
  381,    0,    0,30044,  400,  404,  411,    0,    0,    0,
    0,    0,    0,28165,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  263, 7918,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  116,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -175,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  417,    0,    0,    0,
    0,  166,  308,  416,  424,  433, -472,  435,  447,  451,
  453,  467,  492,  514,  531,  564,  591,  605,  631,  636,
  649,  687,  230,  816, -203,  820,  824,  829,  842,  866,
  868,  871, -326,  876,  878,  882,  884,  888,  927,  929,
  939,  945,  958,  962,  965,  975,  977,  992, 1001, 1003,
 1013, 1025, 1027, 1029, 1031, 1033, 1040, 1043, 1051, 1055,
 1056, -472, 1060, 1071, 1074, 1075, 1077,  586, 1081, 1084,
 1085, 1087, 1095, 1096, 1097, 1100, 1102, 1103, 1104, 1105,
 1108, 1109, 1115, 1116, 1118, 1121, 1122,  256, 1123, 1124,
 1125, 1129, 1130, 1134,30044,30044,    0,18018,    0,    0,
    0,    0,    0, -304, -176, 1135, 1136,    0, 1220,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -45, -229,
    0,30044,    0,    0,30044,    0,  648, 1172,  718,30044,
  743,  598,  744,30044,  745,  598,    0,29426, 1273,  748,
30044,  750,30044,  751, 1172,  753,30044,  754,30044,  755,
30044,  756,30044,  760,30044,  766,30044,  770,30044,  771,
  598,  772, 1172,  787,30044,  788,  598,  791,30044,  800,
  802,  803,  598,  805, 1358,  813,30044,  814,  598,  817,
30044,  821,30044,  822,30044,  826,  598,  828,30044,  830,
  836, 1172,  837,30044,  839,  598,  840,30044,  843,30044,
  847,30044,  848,30044,  849,30044,  850,30044,  855,30044,
  858,30044,  859,  598,  863,30044,  870,30044,  872,30044,
  874,  598,  875,30044,  881,30044,  883,30044,  885,  598,
  886,  598,  887,30044,  890,30044,  892,30044,  893, 1172,
  895, 1172,  896,  598,  898,30044, 1285,  899,  598,  900,
  598,  903, 1172,  904, 1172,  905, 1172,  907, 1305,  908,
30044,  917,  598,  918,30044,  920,30044,  922, 1172,  923,
 1172,  934,30044,  952,30044,  954,30044,  955,30044,  956,
30044,  959,  598,  960,  966,  971,30044,  972,30044,  973,
30044,  976,30044,  978,30044,  980,30044,  982,  983,  986,
  236,  987, 1172,  988, 1172,  989,30044,  990,30044,  993,
 8352,    0,    0,    0,    0,  854,  994,  236,  995,30044,
30044,    0,30044,30044,30044,30044,30044,30044,30044,30044,
30044,30044,30044,30044,30044,30044,30044,30044,30044,30044,
30044,30044,30044,30044,30044,30044,30044,30044,30044,30044,
    0, 1210,    0, 1218, 7918,    0,    0,17614,30044,    0,
    0,    0,    0,    0,    0,  -31,    0,    0, 5090,    0,
 1435,    0, 5090, 1365, 1435, -326,18422,30044,    0, 5090,
    0, 5090,    0,    0,    0,    0,  851, 1472,    0,    0,
    0, 5494,    0, 5090,    0, 5090,    0, 5090,    0, 5090,
    0, 5090,    0, 5090,    0, 1474,    0, -299,    0,    0,
    0,    0,    0,    0,    0,  997,    0,    0,    0,  998,
    0, 5090,    0,    0,    0,  999,    0, 1493, 1484,    0,
    0,    0,    0,    0,    0, 1488, 1415, 1500,    0, 5898,
    0, 5898,    0, 5898,    0, 1484,    0,18826,    0,    0,
 -207,    0, 5090, 1442, 1435,    0, 5090,    0, 5090,    0,
 5090,    0, 5090,    0, 5090,    0, 5090,    0,51465,    0,
 5090,    0, 1564,    0, 5090,    0, 5090,    0, 6302,    0,
 1581,    0, 5090,    0, 5090,    0, 5090,    0, 1583,    0,
 1585,    0, 5090,    0, 5090,    0, 5898,    0,  -29,    0,
    0,    0,    0,    0, 1002,    0,    0,    0, 1607,    0,
 5090,30044,    0, 1609,    0, 1611,    0,    0,    0,    0,
 1006,    0,    0,    0, -156,    0,  -98,    0,    0,    0,
 7918, 1007,    0, 1009,    0, 5090,    0, 5090,    0,  -82,
    0,  -50,    0,51499,    0,51533,    0, 6706,    0, 5090,
    0,51567,    0, 1010,    0,    0,    0, 5898,    0, 5898,
    0, 5898,    0, 5898,    0, 5898,    0, 7110,    0,    0,
    0, 1011,    0,   -2,    0,  -29,    0,51601,    0, 5090,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 1049,
  -22,30044,    0,30044,    0, 7514, 7918, 1622, 7918, 7918,
 7918, 7918, 7918, 7918, 7918, 7918, 7918, 7918, 1982, 2473,
 1957, 1907, 2233, 1209, 1209,  171,  171,  171,  171,  286,
  286, -523, -523,    0,    0,    0, 1542,25914, 1019,30044,
    0,   -3, 7918,30044,28474, 1472,  -85, 1022, 1472, 1417,
 1474, 1058, 1059, 1551,    0,    0, 1638, 1472, 1472, 1172,
 1035, 2682, 1435, 1435, 1435, 1474, 1435, 1435, 1474,    0,
    0, 1560, 1472,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  653, 1642,30044, 1431,  628, 1039, 1044, 1048, 1642,
 1569,    0, 1472, 1437, 1657, 1054, 1079, 1080, 1082, 1083,
 1086,    0, 1089, 1172, 1090, 1474, 1091,  521,30044,    0,
 1474, 1472, 1472,30044,30044, 1472, 1472, 1093, 1094,    0,
 1410, 1472,    0,    0,   36,  417,30044,30044,    0,    0,
    0,27701,    0, 1582, 1472, 1472,    0,    0,    0,    0,
 1172, 1472, 1586, 1598, 1098, 1099, 1107, 1110, 1113,30044,
 1472,    0,    0, 1114, 1602, 1472, -327,    0, 8352, 7918,
 7918,    1,  236,    0,    0, 1606,    0, 7918,    0,30044,
    0,    0,    0,    0,    0, 1119,    0, 7918, 1126,    0,
    0,    0, 1127, 1610, 1662,    0,    0,    0,30044, 1128,
 1131,  851,    0, 1132,    0, 1179, 1181, 1184, 1435, 1186,
 1187, 1474,    0, 1472, 1493,    0,    0, 1139, 1188,    0,
    0,    0,    0,    0, 1474, 1620,    0,    0,    0,    0,
    0,    0, 1664,    0,    0,    0, 1189,    0, 1190, 1625,
  628,    0,    0,    0,    0,    0,    0,    0,  851,    0,
 1690,    0,    0,    0,    0,    0,    0,    0, 1474,    0,
 1703, 1472, 1191, 1204, 1207, 1208, 1212, 1213,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 1474,    0,    0, 1221,30044,    0, 1709, 1710,
 1117, 1137, 1140, 1176, 1211, 1224, 1225, 1226, 1227, 1229,
 1230, 1231, 1235, 1236, 1237, 1238, 1239, 1243, 1244, 1245,
 1250, 1254, 1256, 1270, 1271, 1272, 1275, 1276, 1277, 1278,
 1279, 1281, 1283, 1284, 1288, 1289, 1310, 1311, 1312, 1313,
 1314,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 1316, 1317,  103, 1318, -180,
    0,    0,    0,    0,    0,    0, 7918, 1323,    0,    0,
 1328,    0,    0, 1142,    0,30044,30044,30044,    0, 1331,
 7918,    0,    0,    0,    0,  628,    0,    0,    0,    0,
    0,    0,    0, 1335,    0,    0, 1336,21588, 1339,   49,
    0,  653,    0,    0,    0, 1342,    0,  362, 1636,21897,
    0,    0, 1718,30044, 1690, 1721,  319, 1581, 1343,    0,
    0,    0,    0,    0,    0, 1474,    0,    0,30044,30044,
 1581, 1512, 1516, 1523, 1524, -227, 1529, 1574, 1603, 1644,
 1666, 1673, 1738, 1740, 1741, 1742, 1743, 1744, 1745, 1746,
 1748, 1749, 1750, 1751, 1753, 1757, 1758, 1759, 1761, 1762,
 1764, 1765, 1767, 1768, 1769, 1770, 1771, 1772, 1773, 1775,
 1784, 1785,22206,    0,    0,    0,    0, 1394, 1922,  -73,
    0,    0,22515,    0,22824,    0, -327, 7918,    2, 7918,
 2003, 1925, 2006,    0,    0,    0,    0, 1493,    0,    0,
   81,    0,    0,    0, 2007,    0,    0,  362, 7918, 2008,
  521,    0,    0,    0, 1484,    0, 1403, 1404,    0, 1406,
 1409,  697, 1412, -188, 1413, -188, 1414,30044, 1420,    0,
 1421, -188, 1422, -188, 1424,30044, 1425,30044, 1427,30044,
 1428,  520, 1434,  523, 1438,30044, 1439,30044, 1440, -188,
 1441,  522, 1443,  520, 1445,  598, 1448,  425, 1449,  425,
 1451,  425, 1452,  523, 1454,  523, 1456,  236, 1460,  523,
 1463,  523, 1464, -188, 1466, -188, 1468,30044, 1469, 1410,
 1471,30044, 1475,30044, 1476,30044, 1477, 1478, 1479,30044,
 1481,30044, 1482,  598, 1483,  598, 1486, -188, 1491, -188,
 1492,30044,    0, 1804, 1809,    0,    0,    0,    0,    0,
    0,    0,    0,30044,    0,  362,    0,  653,    0, -254,
    0, 2023,30044, 1494, 1474, 1642,    0, 1958, 1964,    0,
    0,    0,    0,    0, 2080,    0,    0,    0,    0, 2099,
    0, 2102,    0,    0,    0,    0, 2099,    0, 2102,    0,
    0,    0, 2103,    0, 2104,    0,    0,    0, 2105,    0,
    0,    0,    0,    0,    0, 2106,    0, 2108,    0, 2108,
    0, 2109,    0,    0,    0, 2110,    0, 2111,    0,    0,
 1506,    0,    0,    0, 2125,    0, 2127,    0, 2128,    0,
 2130,    0, 2131,    0, 2132,    0, 2133,    0, 2134,    0,
 2099,    0, 2102,    0,    0,    0, 2136,    0,    0,    0,
 2137,    0, 2137,    0, 2138,    0, 2060,    0, 2140,    0,
 2140,    0, 1535,    0, 1536,    0, 2099,    0, 2099,    0,
    0, 1537,30044, 2064,    0,    0,23133, 2146,    0,    0,
    0,    0, 1541,23442, -254, 7918,    0, 1474, 1543,    0,
    0,  667, 2150,  551, 2151,  600, 2099, 2152, 2151, 2099,
 2152,30044,30044,  452,29117,  458, 2153, 2154,  520,30044,
  452, 2076,30044,30044,30044,30044,29117, -188, 2156,30044,
30044, 2151, 2099, 2152,30044,  659, 2160, 2160,30044,    0,
  911, 2162, 2162, 2084, 2085, 2151, 2151, 2152,    0, 1561,
    0,23751, 1565,    0, -254, 2091,    0, 1567, 1570, 2096,
24060,24369,    0,    0,  291,    0,    0,    0,  579, 2102,
    0,    0,    0, 2151, -188, 2102, 2102, 2151, 2102, 2177,
 2178,    0,    0,    0, 2179,    0,    0,    0,    0, 2180,
    0,    0,    0,    0,    0,30044,30044, 2183, 2186, 2179,
30044, 2187, 2188, 2189, 2191, 2193,    0,  598, 2194, 2196,
 2200, 2102, 2151, 2102, 2201,    0,    0,    0,  438, 2203,
 2204, 1605,27803,    0,    0,    0,    0,    0,    0,  550,
 2209, 2212,30044,30044, 2102, 2102, 2102, 2139,    0, 2141,
  116, 1616,  164, 2144,    0,    0,    0,    0,    0,    0,
    0, 2178,    0,    0,    0, 2213, 2215,    0, 2099, 2213,
 2215, 2099,  371, 2156,  598, 1621,  523, 2217,30044, 2180,
 2229, 2229,  452,30044, 2178,   89,30044,30044,30044,30044,
30044,    0, 1954, 1628,30044,  236, 2213, 2215, 2099,30044,
    0,    0,    0,30044,30044, 2158,    0,    0,    0,    0,
    0,    0,30044,30044,   97,   99, 2238, 2213, 2099,    0,
    0,    0, 2161, 1634, 1637, 1639, -146,    0,    0,    0,
  107,    0,    0, 2241,  164,    0, 1640,  393, 2243,  691,
 2245, 2151, 2247, 2252, 2151,    0,    0,    0,    0,    0,
    0,    0, 1647,    0,    0,    0,29117,    0, 2254,  775,
 2255, 2256, 2179, 2257, 1653,    0, 2260, 2261, 2178, 2262,
 2263, 1659,    0, 2190, 2266, 1581, 2267, 2270, 2151, 2271,
 2108, 2108,    0, 2272, 2272,    0,    0,30044, 2275, 2151,
24678,24987,    0,  164,  490,  437, -193,    0,    0,  164,
    0, -146,  121,25296, 2197,    0,    0,    0,    0,30044,
    0,    0,    0,    0,    0,  425, 2277,30044,  425, 2279,
    0, 2180,  838, 2280,    0,    0,    0,  236,  236, 1581,
30044, 2202,30044,30044, 1676,  236,  236, 2072,30044,  236,
 2288,30044,  425, 2291,30044, 2292, 2296,27871,  711, 2299,
 2299, 2300,30044, 2301,    0,    0,  155, 1696, 2303, 1702,
 1704,51439, 1705, 1708,    0,    0,    0,    0,30044, 2315,
 2316,30044,    0,    0,    0,    0,    0, 2317, 2318,30044,
 2320,    0,    0,    0,    0,    0,  236, 1581, 1581, 2321,
 2322,30044, 2323, 2324,    0, 1581, 1581, 1719, -146,    0,
  168, 1581,  236, 2327, 2329,30044, 2331,30044,30044,    0,
    0,    0,    0,  738, 2333, 2333,30044, 2334,30044,    0,
    0,    0,28808, 1729,    0,    0, 1730,    0,    0,  189,
30044,30044, 2338,30044,30044, 2339,  236, 1581, 2152, 2152,
  236, 2178,30044,  191,30044,30044, 2152, 2152,    0,    0,
    0, 1734,30044,    0, 2341, 2152,30044,30044, 2342,30044,
 2178, 2343, 2344,    0,    0,    0,    0,    0,    0,  552,
 2345, 2346, 2347,30044, 2350,    0,    0,    0, 1755,    0,
 1760, 1763,    0,    0,    0,    0,    0,    0,    0,    0,
 2351, 2353,30044, 2354, 2355,30044, 1581, 2152, 2156, 2156,
    0, 1752, 2178,    0, 2178, 2178, 2156, 2156, 2283,    0,
  236, 2156, 2364, 2366,30044,    0, 1794,  758,  758,    0,
    0,    0,    0,30044,30044,30044, 2370,30044,    0,    0,
    0,30044,30044, 2401,30044,30044, 2402, 2152, 2156, 2194,
 2179, 2330, 1800, 1802, 1806, 2194, 2194,30044, 2152, 2194,
30044,30044, 2410,    0,    0,    0, 2414, 2415, 2416, 2417,
 2418,30044, 2419, -146, -146, -146, 2420, 2421,30044, 2422,
 2424,30044, 2156, 2194, 1847, 2194,30044,    0,    0,    0,
 1848, 1849,  194, 2156, 1850, 2457, 2459,30044,  778,  778,
30044,30044,30044, 2488,30044, 1883, 1884, 1885,30044,30044,
 2492,30044,30044, 2537, 2194, 1932,    0, 1933,  198, 2461,
 2462,    0, 2194,    0,30044,30044, 2559,    0,    0, 2560,
 2561, 2562, 2563, 2564,30044, 2585,    0,    0,    0, 2587,
 2588,30044, 2589, 2590,30044, 1986, 2514,    0,    0,30044,
30044, 1993, 2600, 2603,30044,  236,  236,  236,  236,30044,
 2604,30044,30044,30044, 2605,30044,30044, 2607, 2529,30044,
  200,  204,    0,30044,30044, 2609, 1581, 1581, 1581, 1581,
 1581,30044, 2611, 1581, 2612,30044, 2613, 2614,30044,30044,
  217,    0,    0, 1581, 2615,30044, 2152, 2152, 2152, 2152,
 2321, 1581,30044, 2321,30044, 2616,30044, 2156,30044, 2617,
 2538,    0, 2321,30044, 2618, 2156, 2156, 2156, 2156, 2178,
 2321, 2620, 2156, 1581,30044,    0, 2621, 2613,30044,    0,
 2156, 1581,30044, 2194, 2179, 2194, 2179, 2016, 2156,30044,
 2621, 2321, 1581,  538, 2624, 2156, 2613, 2621, 2321, 1581,
 2019, 2194, 2020, 2194,    0, 2621, 1581, 2624, 2156, 2321,
    0,    0,    0,  575, 2021, 2628, 2178, 2624, 2156, 2321,
    0, 2024,    0, 2025, 2624, 2321, 2028, 2628, 2178,    0,
    0,    0,    0, 1023, 2629, 2029, 2058, 2628, 2178,    0,
    0, 2059, 2178,    0, 2629, 2065,    0,    0,    0,    0,
    0,  538, 2067,    0,    0, 2629, 2097,    0, 2100, 2147,
    0,    0,    0, 2148,    0,    0,    0,    0,
};
static const YYINT AslCompilerrindex[] = {                0,
    0,    0,    0, 2710,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,26223,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 7947,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,17211,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 4715,    0,27150,    0, 5119,    0,19259,19663,
20067,20471,20875,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,25605,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 5523,    0,    0,    0,
    0,    0, 5927,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 6331,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 7139,    0,    0,    0,
 6735, 4105,30353,  623,30662,  638, 2591,30971,31280,28978,
31589,31898,32207,32516,32825,33134,33443,  752,29287,33752,
  852,34061,    0,  879,    0,34370,  906,34679,34988,35297,
  948,35606,    0,29596,35915,  979,36224,36533,36842,37151,
37460,37769,38078,38387,  991,38696,39005,39314, 1042,39623,
39932,40241, 1112, 1120,40550,40859,41168,29905,30214, 1178,
41477, 2591, 1180, 1240,30523,30832,31141, 2623,29735, 1251,
41786,42095,31450,31759,42404,42713,43022,43331,43640, 1280,
 2149,43949,44258,44567,44876,45185,45494,    0,  274,32068,
32377,45803,46112,  566,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 8726, 9130,  285,46421,    0,27459,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 2157,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 2163,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    4,    0,    0,    0,    0, 7543,    0,    0,    0,    0,
 2736,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,26532,    0,46730,14411,    0,    0,    0,    5,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 2659,    0,  228,    0,    0,
    0,    0,    0,  -18,  -16,  -14,    0, 2164,  -12,   -5,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,14787,
15191,15595,15999,16403,51635,    0,51669,16807,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 2165,    0,
 1798, 1852, 1887,    0, 1936,    0,    0,    0,    0, 2164,
    0, 2164,    0, 2164,    0, 2165,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 2166,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 2164,    0,    0,    0,
  491,  496,  501,  537,    0,  543,  549,    0,    0,    0,
    0,  232,    0,    0,    0,    0,    0,  587,  594,  601,
    0,  604,  616,    0,    0,    0,    0,    0,    0,    0,
 2167,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, 2164,    0, 2164,
    0, 2164,    0, 2164,    0, 2164,    0, 2170,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    7,    0,    0,   10,    0,14815,15219,
15623,16027,16431,16835,17239,17643,18047,18451,14007,13603,
13199,12795,12391,11583,11987, 9967,10371,10775,11179, 9159,
 9563, 8351, 8755,    0,    0,    0,    0, 2658,    0,    0,
    0,    0,   11,    0,    0, 2164,    0,    0, 2164,    0,
    0,    0, 2663,    0, 3724,    0, 2662, 2164, 2164,   13,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 2164,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   23, 2171,    0,    0,    0,    0,    0,    0, 2171,
    0,    0, 2164,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   25,    0,
    0, 2164, 2164,    0,    0, 2164, 2164,    0,    0,    0,
    0, 2164, 4686,    0,    0, 1175,    0,    0,    0,    0,
    0,    0,    0,    0, 2164, 2164,    0,    0,    0,    0,
    0, 2164,    0,    0,    0,    0,    0,    0,    0,   26,
 2164,    0,    0,    0,    0, 2164,    0,    0,   27,18855,
   28,    0,    0,    0,    0,    0,    0, 2172,    0,   29,
 2737, 2815, 2850,    0, 2885,    0,    0,   31,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  238,    0,
    0,   33,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 2164,  243,    0,    0, 2173,    0, 2063,
 2101, 2135,    0, 2214,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 2174,    0,
 1019,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 2175, 2164,    0,    0,    0, 9534,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  245,    0,    0, 2176,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 2665,
    0,    0,    0,    0,    0,    0,   37,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    7, 2744,    0,    0,
   38,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  247,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   40, 1019,    0,   42, 2166,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   44,
 2166,  985,  -11,   45,47039,    0,   48,   70,47348,47657,
47966,  891,   20,48275,48584,  111,  909,  894,  473,   85,
  250,  257,   24,   54,  294,   66,   74,  207,  212,48893,
 1660,49202,49511,49820, 2210,50129,50438,  495,  534,  214,
  223,50747,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   46,    0, 2747,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   47, 2211,
    0,    0,    0,    0, 2165,    0,    0,    0,    0,    0,
    0,    0,    0, 2757,    0, 2757,    0,    0,    0,    0,
    0, 2757,    0, 2757,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 2758,    0,    0,    0,    0,    0, 2757,
    0,    0,    0,    0,    0, 1022,    0, 2759,    0, 2759,
    0, 2759,    0, 2758,    0, 2758,    0,    0,    0, 2758,
    0, 2758,    0, 2757,    0, 2757,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 1022,    0, 1022,    0, 2757,    0, 2757,
    0,    0,    0,51056,26841,    0,    0,    0,    0,    0,
    0,    0,    0, 2230,    0,    0,    0,  247,    0,    0,
    0,    0, 2231,    0,    0, 2171,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 2232,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 2234,    0,    0,    0,    0,
    0, 2760,    0, 2762,    0, 2764,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 2767,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   52, 2235,    0,
    0,    0,    0,    0,    0, 2768,    0,    0,    0,    0,
 2783,    0,    0,    0,    0,    0,    0,    0,    0, 9534,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 2785,    0,
    0,    0,    0,    0,   55,    0,    0,    0,    0, 2236,
 2237,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 2239,
  228,    0,    0,    0,    0,    0,    0,   56, 2240,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 2786,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 2819,
    0,    0,  228,  228,    0,    0,    0,    0,    0,    0,
25605,    0, 2754,    0,    0,    0,    0,    0,    0,    0,
    0, 2237,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   58, 2235, 2242,    0,   60,    0, 2839,    0,
    0,    0,    0,    0, 2237,    0,    0,    0,    0,    0,
    0,    0, 2248,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 2754,    0,    0, 2844,    0, 2847,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 2851,
    0,    0, 2239,    0,    0,    0,    0,    0, 2237,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 2754,    0,51506,    0,    0,    0, 2774,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 2759,    0,    0, 2759,    0,
    0,    0, 2856,    0,    0,    0,    0,    0,    0, 2166,
    0,    0,    0,    0,    0,    0,    0, -343,  251,    0,
    0,    0, 2759,    0,    0,    0,    0,    0, 2857,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 1009,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  228,    0,
    0,    0, 3040, 3142, 3185,    0,14382,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, 2166, 2166, 2264,
    0,  228,    0,    0,    0, 2166, 2166,    0, 2268,    0,
    0,    0,    0,    0,    0,    0, 2269,    0,    0,    0,
    0,    0,    0, 2858,    0,    0,    0,    0,    0,    0,
    0,    0, 2274,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, 2166, 2276, 2276,
   62, 2237,    0,    0,    0,    0, 2276, 2276,    0,    0,
    0,    0,  261,    0,    0, 2276,    0,    0,    0,   63,
 2237,    0,    0,    0,    0,    0,    0,    0,    0, 2860,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 2166, 2276, 2235, 2235,
    0,    0, 2237,    0, 2237, 2237, 2235, 2235,    0,    0,
    0, 2235,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, 2276, 2235, 2240,
 2239,    0,    0,    0,    0, 2240, 2240,  228, 2276, 2240,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 2235, 2240,    0, 2240,  251,    0,    0,    0,
    0,    0,    0, 2235,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 2240,    0,    0,    0,    0,    0,
    0,    0, 2240,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  251,
  251,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  251,
    0,    0,    0,    0,    0,    0, 2166, 2166, 2166, 2166,
 2166,    0,    0, 2166,    0,    0, 2278,    0,    0,    0,
    0,    0,    0, 2166,    0,    0, 2276, 2276, 2276, 2276,
 2264, 2166,    0, 2264,    0,    0,   64, 2235,    0,    0,
    0,    0, 2264,    0,    0, 2235, 2235, 2235, 2235, 2237,
 2264,    0, 2235, 2166,    0,    0, 2281, 2278,    0,    0,
 2235, 2166,    0, 2240, 2239, 2240, 2239,    0, 2235,    0,
 2281, 2264, 2166,   65, 2282, 2235, 2278, 2281, 2264, 2166,
    0, 2240,    0, 2240,    0, 2281, 2166, 2282, 2235, 2264,
    0,    0,    0, 2284,    0, 2285, 2237, 2282, 2235, 2264,
    0,    0,    0,    0, 2282, 2264,    0, 2285, 2237,    0,
    0,    0,    0,   69, 2287,    0,    0, 2285, 2237,    0,
    0,    0, 2237,    0, 2287,    0,    0,    0,    0,    0,
    0, 2290,    0,    0,    0, 2287,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT AslCompilergindex[] = {                0,
    0,    0,    0,    0, -830,    0, 2901,    0,    0,    0,
    0,    0,    0,-1314,    0,    0,    0, -425, -303,  253,
 2742, -130, -661, -382,    0,  -24,  -10,  915,   -6,    9,
 1854,    0,    0,    0,    0,  921,    0,-1831,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, 1480,    0, 1487,
 1066,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -289,    0,    0,    0,    0,    0,
 -135,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -127,    0,    0,    0, 2427,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,-1166,    0,    0,
    0,    0,  633,  707,    0,    0,    0,    0,    0,-1656,
-1457,    0,    0,-1379, 1459,    0,    0,    0, -744,    0,
-1451,    0,-1684,    0,    0, 1395,-1613,    0, 1063,    0,
    0,    0,  445,-1619,    0,    0,    0,  109,    0,    0,
    0,    0,    0,    0, -360,  -13,   -4,  844, 2920,    0,
   -1,    0, 2575, -455, 2122, -875,49407,-2111,    0,-1629,
 1725,    0,    0,    0,-1703,  897,    0, 1844,    0,    0,
    0,    0, 1618,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,-1787, -324,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
-1802,    0, -633,   75,    0, 1076,-2334, 1282, -198,-1362,
    0, 2584,  303, 1291,    0,  981,  845,    0, 1587,  123,
-1766,-1450,-1433,-1294,-1578,    0, -754,-1005,    0,  914,
    0,-2282,-1748,    0,-1637, -457,    0,    0,    0,-1786,
-1123,-1589, 1214,-1067, 1396,-2170,-2125,-2359, 1223,    0,
-1826,    0, 2805, -119,  158,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,
};
#define YYTABLESIZE 52319
static const YYINT AslCompilertable[] = {                15,
  495, 1063,  179, 1021, 1363, 1465,   10,   22,   16,   12,
  968, 1030,  974, 1875,  975,   18,  180,   20, 1470,  491,
  182, 1099,  681,  398, 1167,  195,  673,  197, 1479,  198,
 1718,  196,  948,  553,  405,  183, 1823, 1450,  199,  704,
 1110,  756, 1806, 1949, 1326, 1326, 1628,  624,   50,   14,
  547, 1556,  494,  296,   51, 1924,   27,  681, 1637,  730,
 1639,  981, 2053,  979, 1800,  682,   84, 1009, 1092,   37,
  627,  548,   52, 1779,  285, 1758,   28,  672, 1572, 1217,
   38,   53,  682, 1108,  619,  293,  681, 1099,  951,  549,
 1109,  960, 1448, 1993, 1934, 1142, 1814, 1012, 1139, 1117,
  682, 1170,  731, 1147,  709, 1154, 1079, 1129, 1160, 1018,
 1837, 1933, 1084,  963, 1807, 2490,    1, 1021,  436,  437,
  438, 1968, 1428, 2475, 1568, 2426, 2494,  691, 1000,  682,
   61,  695, 1129, 2486,  681, 1842,  821, 1924, 1967,  179,
 1129, 1035, 1129,  457, 2447, 1429, 1709,  838, 1155,  681,
 1990,  681, 2047,  180,  988, 2299,  726,  182,  683, 1979,
 1218, 1858,  740,  681, 1990,  681, 2020,    6,  746, 1443,
 1120, 1876,  183, 1449,  758,  705,  458,  682,    2,  682,
   77,   11,  766,   14, 2054, 2071, 1688,   78,    2, 2056,
  682,  775,  682,  683,  682,  732, 1924,  681, 1990,  681,
 1732,  826, 1924, 1905, 1906, 1569,  682, 1917,  682,  793,
  671, 2143,  842, 1956,    9,    9, 1953,  801, 2351, 2352,
   13, 1976,  683, 1977, 1196,  809, 1746,  811, 1747, 1428,
   14, 1991, 1129,   17, 1129,  105,  106, 1129, 2371,  829,
  682, 2143,  682, 2143,  834, 2057,  836, 2143,   61, 1673,
 1024, 1675, 1429, 1689,   19, 1027, 1774, 1061,  854, 1778,
 2143, 1798, 2012,   21,  632,  633, 1064, 2457,   24, 2038,
  683,   54,  822, 1927,   26,   75,  302, 2467,  874, 2111,
  303,   56, 1813,  839, 2472,  683,   81,  683,   77,  304,
   84,  305, 2144, 1006,   58, 2438, 1955,  306,   77,  683,
 1003,  683, 2448,  308,   60,   78,  553, 1690, 1691, 1692,
 2455,  675,  684, 2180,  678, 2194,  309,  892, 2302,  689,
  685,  410, 2329,  693, 2372, 1587, 1588,  697, 2373,  706,
  700,  510,  702,  683,  934,  683,  712,  685,  714,  310,
  716, 2392,  718,  311,  720,  635,  722,  684,  724,  733,
 1000,  445,   54,  105,  106,  685,   75,  734,  742, 1136,
 1137, 1138,   56, 1140, 1141,  737,  312,   81,  313,   77,
  760,   84,  762,  314,  764,   58,  684,  315,  768,  316,
 2025, 2036, 2037,  773,  685,   60, 1063,  777,  317,  779,
 1641,  781, 1643,  783,  985,  785, 1647,  787, 1649,  789,
 1351,  791,  318, 1354,  319,  795,  320,  797, 1932,  799,
  321, 1935,  322,  803,  323,  805,  324,  807,  325,  674,
 1914,  447, 1480,  813,  684,  815,  823,  817,  326, 2120,
 1943,  327,  685,  328,  824,  831,  329,  840, 1969,  684,
  442,  684, 1032,  445, 2266,  685,  330,  685,  331,  685,
  851,  397, 2134,  684,  856,  684,  858,  332, 1980,  439,
  440,  685,  864,  685,  866,  333,  868,  334,  870,  335,
  872,  443,  444,  636, 1915,  445,  878,  336,  880,  337,
  882, 1348,  884,  753,  886,  490,  888,  684,  338,  684,
  339, 2189, 2190, 1070,  445,  685,  898,  685,  900, 2197,
 2198,  340,  948,  948, 1469, 1344, 1360, 1066, 2202,  936,
  937,  618,  939,  940,  941,  942,  943,  944,  945,  946,
  947,  948,  949,  950,  951,  952,  953,  954,  955,  956,
  957,  958,  959,  960,  961,  962,  963,  964,  965,  966,
  979,  979,  979,  979, 1009, 1009, 1009, 1009,  973,  341,
 2229, 1071,  445, 2192, 2061,  342,  686, 2069,  951,  951,
  343,  960,  960,  449,  681,  344, 1134, 1077,  445,  397,
 1699,  345, 2207,  707, 1012, 1012, 1012, 1012, 1000, 1000,
  346, 2095,  347,  963,  963,  348, 1018, 1018, 1018, 1018,
 2263,  728,  349, 1190, 1021, 1021, 1021, 1021, 1195, 1078,
  445, 2274,  105, 2031,  350,  687,  351,  682, 2273,  621,
  352, 1219, 1220,  353, 2233,  354, 2234, 2235,  681,  445,
  771,  445,  710,  355,  988,  988, 1916, 1098, 2432,  356,
 2434,  195,   23,  197,  278,  198,  279,  196,   24,  357,
  687,  358,  738, 1423,  199,  280, 1109, 1093,  445, 1433,
 1325, 1563, 1121,  624,   50,  681,  547, 2080, 1435,  296,
   51,  682,   27,  359, 1669,  360, 1671, 1135,  819,  687,
  707,  451,   84, 1337, 1092,   37,  627,  548,   52,  453,
  285,  707,   28,  845,  753,  847,   38,   53,  455, 1108,
  460,  293, 2050, 1099,  982,  549, 1109,  860,  682,  862,
  683, 1142,  462, 1567, 1139, 1117,  464, 1170,  466, 1147,
 1576, 1154, 1079, 1129, 1160, 2129, 2130,  687, 1084,  827,
 1024, 1024,  468, 2137, 2138, 1027, 1027, 1061, 1061, 2145,
  843,  894,  687,  896,  687,  361, 1064, 1064,  363, 2396,
 2397, 2398, 2399, 1006, 1006, 2048,  687,  470,  687,  364,
 1003, 1003, 1426,  445,  683, 2230, 2231, 1157, 1158, 1159,
 1160, 1161, 1162, 2236, 2237, 2188,  365,  979, 2240,  472,
   61,    9, 1453, 1454,  988, 1145,  989,    9,  140,  141,
  687,  143,  687,  366,  140,  141,  474,  143,  993,  367,
  994,  683,  995,  369,  996, 2264,  997,    9,  998, 1327,
  999, 1100,  370, 1101,  140,  141,  994,  143,  432,  433,
  434,  435,  436,  437,  438,  635, 1003,  371, 2049,  476,
   77, 2418,  635,  635, 2228,  635,  544,   78, 1055, 2295,
 1782, 1783, 1784,  544,  544, 1015,  544, 1462, 1463, 1108,
 2303,  372, 1015, 1015, 1118, 1015,  478, 1033, 1803, 1804,
  373, 1036, 1750, 1037,  684, 1038,  994, 1039,  374, 1040,
  480, 1041,  685,  994,  375, 1043,  376, 1058, 2466, 1046,
  377, 1047, 1849, 1850, 1851,  105,  106, 1051, 1055, 1052,
 2476, 1053, 1996, 1997, 1998, 1055,  482, 1056,  378, 1057,
 2487,  484, 1066, 1059, 2489, 1157, 1158, 1159, 1160, 1161,
 1162, 1607, 1608, 1687,  486, 1062, 1624, 1625,  684, 1694,
  379,  994,  994, 2210, 2211, 2212,  685, 1058, 1633, 1634,
 1871, 1872, 1771, 1772, 1058,  434,  435,  436,  437,  438,
 1075,   61, 1076, 1055, 1055, 1183, 1184, 1185, 1186, 1187,
 1188,  181,  488,  179, 1082,  684, 1936, 1937, 1938, 1939,
 1940, 1941,  380,  685, 2407,  381,  307,  180,  382, 1317,
 1113,  182, 2414, 2415, 2416, 2417, 1763, 1764,  383, 2421,
 1094,  320, 1058, 1058, 1096,  384,  183, 2428,  385, 1331,
  386,   77,  387, 1766, 1767, 2436, 1793, 1794,   78, 1816,
 1817,  388, 2446,  389, 2377, 2378, 2379, 2380, 2381, 1853,
 1854, 2384, 1958, 1959, 1960, 2458,  307, 1891, 1892, 1965,
 1152, 2393, 1027,  307, 1028, 2468, 1029,  390, 1592, 2401,
  391,  320, 1594, 1752, 1597,  392, 1599,  393,  320,  394,
 1601, 1581, 1582, 1583, 1584,  753,  105,  106, 1761, 1762,
  753, 2422, 1622, 1611, 1612, 1613, 1614,   15,  406, 2429,
 2015, 2016,  407,  753,  753, 1125, 1215, 2101, 2102,  408,
 2440,  307,  307, 2245, 2246,  446, 1651, 2450, 1653, 1058,
 1139,  492, 1655, 1142, 2456,  496,  320,  320,  181,  498,
 1665, 2308, 2309, 1322,  500,  367, 1898, 1899, 1900, 1901,
 1677,  397, 1679, 2441, 2442, 1323, 1681,  502, 1132, 1005,
 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015,
 1016, 1017, 1018, 1019, 1020,  753, 2001, 2002, 2003, 2004,
 1181,  504,  994,  506, 2060, 1192,  508,  994, 2460, 2461,
 1085,  511, 1086,  513, 1087,  367, 1088,  515, 1089,  517,
  176,   23,  367,  519, 1055,  179,  278,  687, 2084, 1055,
  180,  279, 1179,  621,  621,  621,  621,  621,  621,  621,
  621,  621,  621,  621,  621,  621,  621,  621,  621,  621,
  621,  621,  621,  621,  621,  621,  621,  621,  621,  621,
  621, 1630,  521, 1058,  523,  380,  178,  277, 1058, 1308,
  367,  367,  177,   24,  525, 1438, 1101, 1440,  181,  280,
  527,  687, 1824, 1825, 1826, 1827, 1828, 2154, 2155, 2156,
 2157, 2158,  401,  529, 1645,  621, 1347,  531,   80, 1630,
  533, 1630, 2152, 2153, 2072, 2073, 2074, 2075, 1119, 1356,
  535, 1123,  537, 1459,  578,  380,  190,   23,  687,  409,
 1130, 1131,  380,  192,  278, 2181, 2182,  539, 1981, 1982,
  193,  279,  397,  191,   24, 1144,  541, 1781,  543, 1792,
 2196, 1352,  401, 1366, 1994,  194,  280, 2200,  545,  401,
 1805, 1792,  976,  976, 1810,  997,  997,  307,  642, 1815,
  547,  431,  549, 1822,  551, 1169,  553, 1376,  555,  409,
  380,  380,  320,  991,  991,  557,  409,  680,  559,   80,
 2477, 2478, 2479, 2480, 1193, 1194,  561, 2224, 1197, 1198,
  563,  565,  443, 2400, 1216,  568, 2403,  401,  401,  945,
  945,  945,  945,  179,  476, 2411,  570, 1306, 1307,  572,
  574,  431,  576, 2419, 1309,  179,  580,  180,  431,  582,
  584,  182,  586, 1318,  409,  409, 2257, 2258, 1321,  180,
  588,  590,  592,  182, 2439,  594,  183,  596,  598,  600,
  602, 2449,  443,  604,  606, 1113, 1152,  688,  183,  443,
  608,  610, 2459,  612,  476,  493,  614,  616,  620,  622,
  624,  476, 2469, 2291,  626,  628,  431,  431, 2473,  630,
  637,  639,  690,  692,  694,  698, 1349,  699,  179,  701,
  703,  748,  711,  713,  715,  717,  367,  832,  179,  719,
  179,  751,  180, 2320, 2321,  721,  182,  443,  443,  723,
  725,  727,  180, 1561,  180,  493,  182,  849,  182,  476,
  476,  183,  493,  937, 1970, 1562,  729,  739, 1971, 1972,
  741,  183, 1696,  183, 1369,  507, 2345, 1974, 1975,  743,
 1467,  744,  745,  510,  747,   33,   34,   35,   36,   37,
   38,   39,  750,  757,  753,  967,  759, 2364, 2365,  932,
  761,  763,  753,  969, 1113,  765, 1113,  767,  977,  769,
  493,  493, 1113, 1882, 1113,  770,  772,  980,  774,  776,
 2386, 1792,  778,   56, 2391,  507,  780,  782,  784,  786,
   58,  445,  507,  510,  788,   61,  380,  790,  792, 2404,
  510,  531,  794,  541,  753,  990,   15,  975, 1113,  796,
 1113,  798,  753,  800,  802, 1659, 1152, 1022, 1152, 2423,
  804, 1024,  806,  401,  808,  810,  812, 1025,  753,  814,
 1944,  816,  818, 1026,  820,  828,   75,  830,  833,  835,
  507,  507,  837,  844,  846,   77,  848,  850,  510,  510,
  409,  531,   78,  541, 1034, 2081,  853,  855,  531,  857,
  541,  859,  861,  550,   89,   90,   91,   92,   93,   94,
   95,   96, 1966,  863,  569, 1005, 1006, 1007, 1008, 1009,
 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019,
 1020,  865,  431,  867,  869,  871, 2123, 1044,  873,  875,
  105,  106,  751,  599, 2126,  876,  531,  531,  541,  541,
  877,  879,  881,  550, 1049,  883, 1054,  885, 1055,  887,
  550,  889,  890,  443,  569,  891,  893,  895,  897,  899,
 2149,  569,  901,  933,  935,  476, 1001, 1002, 1004, 1698,
 1061, 1060, 1067, 2165, 1068, 1069, 1073, 2177, 1074, 1084,
 1092, 2051,  179,  599, 1097, 1104, 1105,  120, 1107,  179,
  599, 1122, 1124, 1126, 1127, 1128,  180, 2193,  550,  550,
  182, 1129, 1143,  180, 1133, 1148, 1156,  182, 1164,  569,
  569, 1168, 1170, 1165, 2206,  183,  493, 1166, 1113,  753,
 1171,  753,  183, 1172, 1305, 1336, 1113, 1358, 1310, 1113,
 1152, 1152,  753,  753, 2078, 2079,  753, 1113,  599,  599,
 1311,  753, 2086, 2087, 1320,  753, 2092,  179, 1173, 1174,
 1329, 1175, 1176, 1364, 1335, 1177,  179,  179, 1178, 1180,
 1182,  180, 1199, 1200, 1357,  182, 1367, 1312, 1313, 1362,
  180,  180, 1379, 1380,  182,  182, 1314, 1437, 1456, 1315,
  183, 1458, 1316, 1319, 1461, 1382,  507, 1471, 1332,  183,
  183, 1473, 1759, 2128,  510, 1333, 1334, 1338, 1475, 1477,
 1339, 1340, 1152, 1152, 1481, 1383,   14,  753, 1384, 2146,
  173,  173,  173,  173,  173,  173,  173,  173,  173,  173,
  173,  173,  173,  173,  173,  173,  173,  173,  173,  173,
  173,  173,  173,  173,  173,  173,  173,  173,  173,  753,
  753,  173,  173, 2187, 1385,  173,  397, 2191, 1341, 1483,
 1342, 1777,  531, 1343,  541, 1345, 1346, 1355, 1359, 1361,
 1370,  121,  428,  429,  430,  431,  432,  433,  434,  435,
  436,  437,  438, 1371, 1812, 1113, 1372, 1373, 1485, 1386,
 1113, 1374, 1375, 1113, 1152, 1152, 1152, 1113, 1835, 1836,
 1377, 1152, 1387, 1388, 1389, 1390,  753, 1391, 1392, 1393,
  753,  753,  181, 1394, 1395, 1396, 1397, 1398, 1111,  753,
  753, 1399, 1400, 1401,  550,  120, 1857, 2239, 1402, 1487,
 1861, 1710, 1403, 1988, 1404,  569, 1201, 1202, 1203, 1204,
 1205, 1206, 1207, 1208, 1209, 1210, 1211, 1212, 1405, 1406,
 1407, 1489,  121, 1408, 1409, 1410, 1411, 1412, 1491, 1413,
  116, 1414, 1415,  753,  599, 1888, 1416, 1417, 1150, 1005,
 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015,
 1016, 1017, 1018, 1019, 1020, 1733,  179,  179, 1418, 1419,
 1420, 1421, 1422,  751, 1113, 1424, 1425, 1427,  751,  179,
  180,  180, 1434, 1988,  182,  182,  120, 1436, 1988,  122,
 1442,  751,  751,  180, 1444, 1445, 1152,  182, 1447,  183,
  183, 1452, 1466, 1493, 2065, 1495, 1497, 1499, 1501, 1503,
 1505, 1507,  183, 1509, 1511, 1513, 1515,  753, 1517, 1113,
 1152,  116, 1519, 1521, 1523, 1152, 1525, 1527, 2065, 1529,
 1531, 2065, 1533, 1535, 1537, 1539, 1541, 1543, 1545, 1113,
 1547, 2265, 2357, 2358, 2359, 2360, 1034, 2271, 2272, 1549,
 1551, 2275, 1554,  751, 1555,  753, 1564, 1565,  753, 1566,
 1570, 1573, 1577, 1578, 2007, 1579,  753, 2010, 1580, 1682,
  122, 1586, 1591, 1593, 1684, 2296, 1695, 2298,  753, 1595,
 1596, 1598, 1856, 1600, 1602, 2140, 1604, 1606, 1859, 1860,
 1700, 1862,  753, 1610, 1152, 1152, 1701, 1617, 1619, 1621,
 1623, 2034, 1627, 1113, 1629,  753, 2326, 1632, 1636,  753,
 1638, 1640, 2044, 1642, 2332, 1644,  129, 1152, 1152, 1646,
 2065, 2065, 1648, 1650, 1887, 1652, 1889, 1654, 1656,  753,
 1660, 1113, 1152, 1702, 1662, 1664, 1666, 1667, 1668, 1152,
 1670, 1672, 1674, 2065, 2065, 1676,  753, 1907, 1908, 1909,
 1678, 1680, 1704, 1697,  128, 1706, 1712, 1713, 1714, 1715,
 1113, 1716, 1719, 1720, 1721, 1722, 1034, 1034, 1034, 1034,
 1034, 1034, 1034, 1034, 1034, 1034, 1034, 1034, 1723, 1152,
 1724, 1725, 2065, 1726, 1727, 1728, 1730, 1731,  118, 1735,
 1736, 1739, 1740, 1741, 1744, 1745, 1749,  129, 1751, 1755,
 1756, 2065, 1760, 1765, 1769, 1775, 1796, 1797, 1801, 1808,
 1113, 1113, 1113, 1819, 1113, 1830, 1833, 1834, 1152, 1152,
 1838, 2065, 2065, 1843, 1840, 2431, 1844, 2433, 1846, 1845,
 1863, 1865, 1867, 1869,  753,  128, 1873, 2065, 2065, 1874,
 1877, 1878, 1879, 2452, 1880, 2454, 1881, 1883, 1113, 1885,
   15,   15,   15, 1886, 1890, 1152, 1894, 1895, 2065, 2286,
 2287, 2288, 1903, 1152, 1896, 1904, 1928,  130, 1930,  118,
 1947, 1910,  181, 1911, 2065, 1913, 1925, 1113, 1113, 1113,
 1945, 1113, 1950, 1962,  181, 1152, 1152, 1964, 2065, 2065,
 1973, 1978, 1985, 1984, 1992, 1986, 2000, 1987, 2006, 1995,
 2008, 2065, 2065, 1111, 1150, 2009, 2011, 2013, 2018, 2019,
 2021, 1113, 2022, 2023, 2024, 2026, 2027, 2028, 1152, 2030,
 2032, 2065, 2029, 2033, 2035, 2039, 1152, 1152, 2043, 2059,
 2062, 2065, 2070, 2077, 2082, 2085, 1113, 2088, 1113, 1152,
 1152, 2093, 2065, 2065, 2096, 2098, 1152,  181,  130, 2099,
 2065, 2065, 2104, 2107, 2109, 2112, 2113,  181, 1113,  181,
  752, 2115, 1152, 2116, 2118, 2065, 1152, 2119, 2121, 2122,
 2124, 2125, 2065, 2127, 2131, 2133, 2135, 2136, 2139, 1113,
 2147, 1152, 2148, 2065, 2150, 2065, 2160, 2164, 2178, 2179,
 2065, 2183, 2186, 2199, 2201, 2205, 2208, 2209, 2214, 2215,
 2216, 1152,  751, 2218, 2222, 2065, 2223, 2225, 2226, 2065,
  751, 2232, 1111, 2219, 1111, 2238, 1113, 2241, 2220, 2242,
 1111, 2221, 1111, 2252,  110,  110,  110,  110,  110,  110,
  110,  110,  110,  110,  110,  110,  110,  110,  110,  110,
  110,  110,  110,  110,  110,  110,  110,  110,  110,  110,
  110,  110,  751, 2244, 2259, 2262, 1111,  121, 1111, 2268,
  751, 2269, 2267, 2278, 1150, 2270, 1150, 2279, 2280, 2281,
 2282, 2283, 2285, 2289, 2290, 2292,  751, 2293,  111,  111,
  111,  111,  111,  111,  111,  111,  111,  111,  111,  111,
  111,  111,  111,  111,  111,  111,  111,  111,  111,  111,
  111,  111,  111,  111,  111,  111, 2297, 2300, 2301, 2304,
 2305,  120, 2306,  112,  112,  112,  112,  112,  112,  112,
  112,  112,  112,  112,  112,  112,  112,  112,  112,  112,
  112,  112,  112,  112,  112,  112,  112,  112,  112,  112,
  112, 2315, 2317, 2318, 2319, 2322,  116,  425,  426,  427,
  428,  429,  430,  431,  432,  433,  434,  435,  436,  437,
  438,  752,  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,  136,  136,
 2325, 2327, 2328, 2330, 2331,  122,  424,  425,  426,  427,
  428,  429,  430,  431,  432,  433,  434,  435,  436,  437,
  438,  181, 2335, 2336, 2337, 2338, 2339, 2340,  181,  422,
  423,  424,  425,  426,  427,  428,  429,  430,  431,  432,
  433,  434,  435,  436,  437,  438, 1111,  751, 2342,  751,
 2343, 2344, 2346, 2347, 1111, 2349, 2350, 1111, 1150, 1150,
  751,  751, 2353, 2354,  751, 1111, 2355, 2362, 2366,  751,
 2369, 2370, 2376,  751, 2383, 2385, 2387, 2389, 2394, 2405,
 2409, 2413, 2410, 2420, 2424, 2435,  181, 2444, 2451, 2453,
 2463, 2464, 2482, 2470, 2471,  181,  181, 2474, 2484,  110,
  110,  110,  110,  110,  110,  110,  110,  110,  110,  110,
  110,  110,  110,  110,  110,  110,  110,  110,  110,  110,
  110,  110,  110,  110,  110,  110,  110, 2485, 2488,    6,
 1150, 1150,  129,   39, 2491,  751, 2493,  111,  111,  111,
  111,  111,  111,  111,  111,  111,  111,  111,  111,  111,
  111,  111,  111,  111,  111,  111,  111,  111,  111,  111,
  111,  111,  111,  111,  111,  900, 2495,  751,  751, 2496,
  128,  112,  112,  112,  112,  112,  112,  112,  112,  112,
  112,  112,  112,  112,  112,  112,  112,  112,  112,  112,
  112,  112,  112,  112,  112,  112,  112,  112,  112,  295,
  125,   41,  390, 1111,  118,   40,  327,  423, 1111,   96,
  424, 1111, 1150, 1150, 1150, 1111, 2497, 2498,  602, 1150,
 1136, 1149, 1133, 1071,  751, 1114, 1124, 1094,  751,  751,
 1144, 1096,  290,   26,   87, 1091,  291,  751,  751,   36,
   94,  395,   91,   29,  292, 1098, 1086, 1112, 1110, 1165,
  136,  136,  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,  124, 1043,
  287,  751, 1151,  130,  426,  427,  428,  429,  430,  431,
  432,  433,  434,  435,  436,  437,  438, 1151,   62,  295,
  288, 1141, 1167,  289, 1116, 1169, 1119, 1131, 1146, 1088,
 1112, 1120, 1111,  117, 1081,  181,  181, 1089,   64, 1105,
 1101, 1126,  752, 1103,    7,  409, 1912,  752,  181, 1557,
 2055,  735, 2311, 1153, 1150, 2248, 1558,  297, 1078, 1575,
  752,  752, 2063, 1075, 1658, 1138, 2492, 1128,  126, 1946,
 1159, 1156, 2141, 1157, 1083,  751, 1162, 1111, 1150, 1163,
   23, 1378, 1324, 1150, 1439,  567, 2063, 1952, 2117, 2063,
 2162, 1460, 1743, 1738, 2106, 2041, 1832, 1111,  404, 1686,
 1821,    0,    0,    0,    0,   33,   34,   35,   36,   37,
   38,   39,    0,  751,    0,    0,  751,    0,    0,    0,
    0,    0,  752,    0,  751,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  751,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  751,    0, 1150, 1150,    0,   61,    0,    0,    0,    0,
    0, 1111,    0,  751,    0,    0,    0,  751,    0,    0,
    0,    0,    0,    0,    0, 1150, 1150,    0, 2063, 2063,
    0,    0,    0,    0,    0,    0,    0,  751,    0, 1111,
 1150,    0,    0,    0,    0,    0,    0, 1150,    0,    0,
    0, 2063, 2063,    0,  751,   77,    0,    0,    0,    0,
    0,  755,   78,    0,    0,    0,    0,    0, 1111,    0,
    0,    0,    0,  133,   89,   90,   91,   92,   93,   94,
   95,   96,    0,    0,    0,    0,    0, 1150,    0,    0,
 2063,  423,  424,  425,  426,  427,  428,  429,  430,  431,
  432,  433,  434,  435,  436,  437,  438,    0,    0, 2063,
  105,  106,    0,    0,    0,    0,    0,    0, 1111, 1111,
 1111,    0, 1111,    0,    0,    0, 1150, 1150,    0, 2063,
 2063,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  751,    0,    0, 2063, 2063,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 1111,    0,    0,    0,
    0,    0,    0, 1150,    0,    0, 2063,    0,    0,    0,
    0, 1150,    0,    0,    0,  132,    0,    0,    0,    0,
    0,    0, 2063,    0,    0, 1111, 1111, 1111,    0, 1111,
    0,    0,    0, 1150, 1150,    0, 2063, 2063,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 2063,
 2063,    0,    0,    0,    0,    0,    0,    0,  119, 1111,
    0,    0, 1112, 1151,    0,    0, 1150,    0,    0, 2063,
    0,    0,    0,    0, 1150, 1150,    0,    0,    0, 2063,
    0,    0,    0,    0, 1111,    0, 1111, 1150, 1150,    0,
 2063, 2063,    0,    0, 1150,    0,    0,    0, 2063, 2063,
    0,    0,  755,    0,    0,    0, 1111,    0,    0,    0,
 1150,    0,    0, 2063, 1150,    0,    0,    0,    0,    0,
 2063,    0,    0,    0,    0,    0,    0, 1111,    0, 1150,
    0, 2063,    0, 2063,    0,    0,    0,    0, 2063,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 1150,
    0,    0,    0, 2063,    0,    0,    0, 2063,    0,    0,
    0,  752,    0,    0, 1111,    0,  397,    0,    0,  752,
    0, 1112,    0, 1112,    0,    0,    0,    0,    0, 1112,
    0, 1112,    0,  110,  110,  110,  110,  110,  110,  110,
  110,  110,  110,  110,  110,  110,  110,  110,  110,  110,
  110,  110,  110,  110,  110,  110,  110,  110,  110,  110,
  110,  752,    0,    0,    0, 1112,  125, 1112,    0,  752,
    0,    0,    0, 1151,    0, 1151,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  752,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  111,  111,  111,  111,  111,  111,  111,  111,  111,
  111,  111,  111,  111,  111,  111,  111,  111,  111,  111,
  111,  111,  111,  111,  111,  111,  111,  111,  111,    0,
    0,    0,    0,    0,  124,    0,  112,  112,  112,  112,
  112,  112,  112,  112,  112,  112,  112,  112,  112,  112,
  112,  112,  112,  112,  112,  112,  112,  112,  112,  112,
  112,  112,  112,  112,    0,    0,    0,    0,    0,  117,
 1468,  136,  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,  136,    0,
    0,    0,    0,    0,  126,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 1115,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 1112,  752,    0,  752,    0,
    0,    0,    0, 1112,    0,    0, 1112, 1151, 1151,  752,
  752,    0,    0,  752, 1112,    0,    0,    0,  752,    0,
    0,    0,  752,    0,    0,    0,    0,    0, 1154,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 1603,
    0, 1605,    0,    0,    0,    0,    0, 1618,    0, 1620,
    0,    0,    0,  755,    0,    0,    0,    0,  755,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  755,  755,    0,    0,    0,    0,    0,    0, 1151,
 1151,    0,    0, 1661,  752, 1663,  110,  110,  110,  110,
  110,  110,  110,  110,  110,  110,  110,  110,  110,  110,
  110,  110,  110,  110,  110,  110,  110,  110,  110,  110,
  110,  110,  110,  110,    0,    0,  752,  752,    0,  133,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  755,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 1112,    0,    0,    0,    0, 1112,    0,    0,
 1112, 1151, 1151, 1151, 1112,    0,    0,    0, 1151,    0,
    0,    0,    0,  752,    0,    0,    0,  752,  752,    0,
    0,    0,    0,    0,    0,    0,  752,  752,  111,  111,
  111,  111,  111,  111,  111,  111,  111,  111,  111,  111,
  111,  111,  111,  111,  111,  111,  111,  111,  111,  111,
  111,  111,  111,  111,  111,  111,    0,    0,    0,    0,
    0,  132,    0,    0,    0,    0,    0,    0,    0,    0,
  752,  112,  112,  112,  112,  112,  112,  112,  112,  112,
  112,  112,  112,  112,  112,  112,  112,  112,  112,  112,
  112,  112,  112,  112,  112,  112,  112,  112,  112,    0,
    0, 1112,    0, 1780,  119,    0,    0,    0,    0,    0,
    0, 1799,    0,    0, 1802,    0,    0,    0,  328,    0,
    0,    0, 1811, 1151,    0,    0,    0,    0,    0,    0,
    0, 2064,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  752,    0, 1112, 1151,    0,    0,
    0,    0, 1151,    0,    0, 2064,    0,    0, 2064,    0,
    0,    0,    0,    0,    0,    0, 1112,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  752,    0,    0,  752,    0,    0,    0,    0,
    0,    0,    0,  752,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  752,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  752,
    0, 1151, 1151, 1115, 1154,    0,    0,    0,    0,    0,
 1112,    0,  752,    0,    0,    0,  752,    0,    0,    0,
    0,    0,    0,    0, 1151, 1151,    0, 2064, 2064,    0,
    0,    0,    0,    0,    0,    0,  752,    0, 1112, 1151,
 1948,    0,    0,    0,    0, 1954, 1151,    0, 1957,    0,
 2064, 2064, 1961,  752,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, 1112,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 1151,    0,    0, 2064,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  755,    0,    0,    0,    0,    0, 2064,    0,
  755,    0, 1115,    0, 1115,    0,    0, 1112, 1112, 1112,
 1115, 1112, 1115,    0,    0, 1151, 1151,    0, 2064, 2064,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  752,    0,    0, 2064, 2064,    0,    0,    0, 2042,
    0,    0,  755,    0,    0, 1112, 1115,    0, 1115,    0,
  755,    0, 1151,    0, 1154, 2064, 1154,    0,    0,    0,
 1151,    0,    0,    0,    0,    0,  755,    0,    0,    0,
    0, 2064,    0,    0, 1112, 1112, 1112,    0, 1112,    0,
    0,    0, 1151, 1151, 2083, 2064, 2064,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 2064, 2064,
    0,    0,    0,    0, 2108,    0,    0,    0, 1112,    0,
    0,    0,    0,    0,    0, 1151,    0,    0, 2064,    0,
    0,    0,    0, 1151, 1151,    0,    0,    0, 2064,    0,
    0,    0,    0, 1112,    0, 1112, 1151, 1151,    0, 2064,
 2064,    0,    0, 1151,    0,    0,    0, 2064, 2064,    0,
    0,    0,    0,    0,    0, 1112,    0,    0,    0, 1151,
    0,    0, 2064, 1151,    0,    0,    0,    0, 2163, 2064,
    0,    0,    0,    0,    0,    0, 1112,    0, 1151,    0,
 2064,    0, 2064,    0,    0,    0,    0, 2064,    0,    0,
    0,    0,    0,    0,    0,    0, 2195,    0, 1151,    0,
    0,    0, 2064,    0,    0,    0, 2064,    0,    0,    0,
    0,    0,    0, 1112,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 2217, 1115,  755,    0,  755,
    0,    0,    0,    0, 1115,    0,    0, 1115, 1154, 1154,
  755,  755,    0,    0,  755, 1115,    0,    0,    0,  755,
    0,    0,    0,  755,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 2249, 2250, 2251,    0, 2253,
  104,  104,  104,  104,  104,  104,  104,  104,  104,  104,
  104,  104,  104,  104,  104,  104,  104,  104,  104,  104,
  104,  104,  104,  104,  104,  104,  104,  104,    0,    0,
 1154, 1154,    0, 2284,    0,  755,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  301,  301,
  301,  301,  301,  301,  301,    0,    0,    0,    0,    0,
    0,    0, 2312, 2313, 2314,    0, 2316,  755,  755,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  301,    0,    0,    0,
    0,    0,    0,  301,    0,    0, 2341,    0,  301,    0,
    0,    0,    0, 1115,    0,    0,    0,    0, 1115,    0,
    0, 1115, 1154, 1154, 1154, 1115,    0,    0,    0, 1154,
    0, 2361,    0, 2363,  755,    0,    0,    0,  755,  755,
    0,    0,    0,    0,    0,    0,    0,  755,  755,  301,
    0,    0,    0, 2382,    0,    0,    0,    0,  301,    0,
    0,    0,    0,    0,    0,  301,    0,    0,    0,    0,
    0,    0,    0,    0, 2402,    0,    0,  301,  301,  301,
  301,  301,  301,  301,  301,    0,    0,    0,    0,    0,
    0,  755,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 2437,    0,  301,  301,    0,    0,    0,    0,    0,
    0,    0, 1115,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 1154,    0,    0,    0,    0,    0,
    0,    0, 2067,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  755,    0, 1115, 1154,    0,
  301,    0,    0, 1154,    0,    0, 2067,    0,    0, 2067,
    0,    0,    0,    0,    0,    0,    0, 1115,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  755,    0,    0,  755,    0,    0,    0,
    0,    0,    0,    0,  755,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  755,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  755,    0, 1154, 1154,    0,    0,    0,    0,    0,    0,
    0, 1115,    0,  755,    0,    0,    0,  755,    0,    0,
    0,    0,    0,    0,    0, 1154, 1154,    0, 2067, 2067,
    0,    0,    0,    0,    0,    0,    0,  755,    0, 1115,
 1154,    0,    0,    0,    0,    0,    0, 1154,    0,    0,
    0, 2067, 2067,    0,  755,    0,    0,    0,    0,   79,
    0,    0,    0,    0,    0,    0,    0,    0, 1115,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, 1154,   30,  301,
 2067,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   30,    0,    0,    0,    0,    0, 2067,
    0,    0,    0,    0,    0,    0,    0,    0, 1115, 1115,
 1115,    0, 1115,    0,    0,    0, 1154, 1154,    0, 2067,
 2067,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   79,    0,  755,    0,    0, 2067, 2067,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 1115,    0,    0,    0,
    0,    0,    0, 1154,    0,    0, 2067,    0,    0,   30,
    0, 1154,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 2067,    0,    0, 1115, 1115, 1115,    0, 1115,
    0,    0,    0, 1154, 1154,    0, 2067, 2067,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 2067,
 2067,    0,    0,    0,    0,    0,    0,    0,    0, 1115,
    0,    0,    0,    0,    0,    0, 1154,    0,    0, 2067,
    0,    0,    0,    0, 1154, 1154,    0,    0,    0, 2067,
    0,    0,    0,    0, 1115,    0, 1115, 1154, 1154,    0,
 2067, 2067,    0,    0, 1154,    0,    0,    0, 2067, 2067,
    0,    0,    0,    0,    0,    0, 1115,    0,    0,    0,
 1154,    0,    0, 2067, 1154,    0,    0,    0,    0,    0,
 2067,    0,    0,    0,    0,    0,    0, 1115,    0, 1154,
    0, 2067,    0, 2067,    0,    0,    0,    0, 2067,    0,
   30,    0,    0,    0,    0,    0,    0,    0,    0, 1154,
    0,    0,    0, 2067,    0,    0,    0, 2067,   30,   30,
    0,    0,    0,    0, 1115,    0,   30,   30,   30,   30,
   30,   30,   30,   30,   30,   30,    0,    0,    0,    0,
    0,   30,   30,   30,    0,    0,    0,    0,    0,    0,
    0,    0,   30,   30,   30,    0,   30,   30,   30,   30,
   30,   30,   30,   30,    0,   30,   30,    0,    0,   30,
    0,    0,    0,   30,   30,    0,    0,   30,   30,    0,
    0,    0,    0,    0,    0,    0,    0,   30,    0,    0,
    0,    0,    0,    0,    0,   30,    0,    0,    0,   30,
   30,   30,   30,   30,    0,    0,    0,    0,    0,   30,
   30,    0,    0,    0,    0,   30,   30,   30,   30,   30,
   30,   30,    0,    0,    0,    0,    0,    0,   30,    0,
    0,    0,    0,    0,    0,   30,    0,   30,   30,   30,
   30,   30,   30,   30,   30,   30,   30,   30,   30,   30,
   30,   30,   30,   30,   30,    0,    0,   30,   30,    0,
    0,    0,    0,  975,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   30,    0,   30,    0,    0,   30,
   30,   30,   30,   30,   30,   30,   30,   30,   30,   30,
   30,    0,  229,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  229,   30,   30,
   30,   30,   30,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   30,   30,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   30,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   30,    0,   30,   30,    0,    0,
   30,   30,   30,    0,    0,    0,    0,    0,    0,   30,
   30,   30,   30,  229,    0,   30,    0,    0,   30,    0,
    0,    0,    0,    0,    0,   30,   30,   30,   30,   30,
   30,   30,   30,   30,   30,   30,   30,   30,    0,    0,
    0,    0,    0,    0,   30,   30,    0,    0,    0,    0,
    0,    0,   30,   30,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   30,
   30,   30,   32,   32,   32,   32,   32,   32,   32,   32,
   32,   32,   32,   32,   32,   32,   32,   32,   32,   32,
   32,   32,   32,   32,   32,   32,   32,   32,   32,   32,
   23,   30,   30,   30,   30,   30,   30,   30,   30,   30,
   30,   30,   30,   30,   30,   30,   30,   30,   30,   30,
   30,   30,   30,   30,   30,   30,   30,   30,   30,   30,
   30,   23,   23,   30,   30,   23,   30,   30,   30,   30,
    0,    0,    0,    0,  229,    0,    0,    0,    0,    0,
    0,    0,    0,   30,   30,   30,   30,   30,    0,    0,
    0,    0,  229,  229,    0,    0,    0,    0,    0,    0,
  229,  229,  229,  229,  229,  229,  229,  229,  229,  229,
    0,    0,    0,    0,    0,  229,  229,  229,    0,    0,
    0,    0,    0,    0,    0,    0,  229,  229,  229,    0,
  229,  229,  229,  229,  229,  229,  229,  229,    0,  229,
  229,    0,    0,  229,    0,    0,    0,  229,  229,    0,
    0,  229,  229,    0,    0,    0,    0,    0,    0,    0,
    0,  229,    0,    0,    0,    0,    0,    0,    0,  229,
    0,    0,    0,  229,  229,  229,  229,  229,    0,    0,
    0,    0,    0,  229,  229,    0,    0,    0,    0,  229,
  229,  229,  229,  229,  229,  229,    0,    0,    0,    0,
    0,    0,  229,    0,    0,    0,    0,    0,    0,  229,
    0,  229,  229,  229,  229,  229,  229,  229,  229,  229,
  229,  229,  229,  229,  229,  229,  229,  229,  229,    0,
    0,  229,  229,    0,    0,    0,    0,  992,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  229,    0,
  229,    0,    0,  229,  229,  229,  229,  229,  229,  229,
  229,  229,  229,  229,  229,    0,  221,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  221,  229,  229,  229,  229,  229,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  229,  229,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  229,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  229,    0,
  229,  229,    0,    0,  229,  229,  229,    0,    0,    0,
    0,    0,    0,  229,  229,  229,  229,  221,    0,  229,
    0,    0,  229,    0,    0,    0,    0,    0,    0,  229,
  229,  229,  229,  229,  229,  229,  229,  229,  229,  229,
  229,  229,    0,    0,    0,    0,    0,    0,  229,  229,
    0,    0,    0,    0,    0,    0,  229,  229,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  229,  229,  229,  411,  412,  413,  414,
  415,  416,  417,  418,  419,  420,  421,  422,  423,  424,
  425,  426,  427,  428,  429,  430,  431,  432,  433,  434,
  435,  436,  437,  438,  281,  229,  229,  229,  229,  229,
  229,  229,  229,  229,  229,  229,  229,  229,  229,  229,
  229,  229,  229,  229,  229,  229,  229,  229,  229,  229,
  229,  229,  229,  229,  229,  281,  281,  229,  229,  281,
  229,  229,  229,  229,    0,    0,    0,    0,  221,    0,
    0,    0,    0,    0,    0,    0,    0,  229,  229,  229,
  229,  229,    0,    0,    0,    0,  221,  221,    0,    0,
    0,    0,    0,    0,  221,  221,  221,  221,  221,  221,
  221,  221,  221,  221,    0,    0,    0,    0,    0,  221,
  221,  221,    0,    0,    0,    0,    0,    0,    0,    0,
  221,  221,  221,    0,  221,  221,  221,  221,  221,  221,
  221,  221,    0,  221,  221,    0,    0,  221,    0,    0,
    0,  221,  221,    0,    0,  221,  221,    0,    0,    0,
    0,    0,    0,    0,    0,  221,    0,    0,    0,    0,
    0,    0,    0,  221,    0,    0,    0,  221,  221,  221,
  221,  221,    0,    0,    0,    0,    0,  221,  221,    0,
    0,    0,    0,  221,  221,  221,  221,  221,  221,  221,
    0,    0,    0,    0,    0,    0,  221,    0,    0,    0,
    0,    0,    0,  221,    0,  221,  221,  221,  221,  221,
  221,  221,  221,  221,  221,  221,  221,  221,  221,  221,
  221,  221,  221,    0,    0,  221,  221,    0,    0,    0,
    0,  990,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  221,    0,  221,    0,    0,  221,  221,  221,
  221,  221,  221,  221,  221,  221,  221,  221,  221,    0,
  239,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  239,  221,  221,  221,  221,
  221,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  221,  221,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  221,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  221,    0,  221,  221,    0,    0,  221,  221,
  221,    0,    0,    0,    0,    0,    0,  221,  221,  221,
  221,  239,    0,  221,    0,    0,  221,    0,    0,    0,
    0,    0,    0,  221,  221,  221,  221,  221,  221,  221,
  221,  221,  221,  221,  221,  221,    0,    0,    0,    0,
    0,    0,  221,  221,    0,    0,    0,    0,    0,    0,
  221,  221,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  221,  221,  221,
  411,  412,  413,  414,  415,  416,  417,  418,  419,  420,
  421,  422,  423,  424,  425,  426,  427,  428,  429,  430,
  431,  432,  433,  434,  435,  436,  437,  438,  278,  221,
  221,  221,  221,  221,  221,  221,  221,  221,  221,  221,
  221,  221,  221,  221,  221,  221,  221,  221,  221,  221,
  221,  221,  221,  221,  221,  221,  221,  221,  221,  278,
  278,  221,  221,  278,  221,  221,  221,  221,    0,    0,
    0,    0,  239,    0,    0,    0,    0,    0,    0,    0,
    0,  221,  221,  221,  221,  221,    0,    0,    0,    0,
  239,  239,    0,    0,    0,    0,    0,    0,  239,  239,
  239,  239,  239,  239,  239,  239,  239,  239,    0,    0,
    0,    0,    0,  239,  239,  239,    0,    0,    0,    0,
    0,    0,    0,    0,  239,  239,  239,    0,  239,  239,
  239,  239,  239,  239,  239,  239,    0,  239,  239,    0,
    0,  239,    0,    0,    0,  239,  239,    0,    0,  239,
  239,    0,    0,    0,    0,    0,    0,    0,    0,  239,
    0,    0,    0,    0,    0,    0,    0,  239,    0,    0,
    0,  239,  239,  239,  239,  239,    0,    0,    0,    0,
    0,  239,  239,    0,    0,    0,    0,  239,  239,  239,
  239,  239,  239,  239,    0,    0,    0,    0,    0,    0,
  239,    0,    0,    0,    0,    0,    0,  239,    0,  239,
  239,  239,  239,  239,  239,  239,  239,  239,  239,  239,
  239,  239,  239,  239,  239,  239,  239,    0,    0,  239,
  239,    0,    0,    0,    0, 1048,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  239,    0,  239,    0,
    0,  239,  239,  239,  239,  239,  239,  239,  239,  239,
  239,  239,  239,    0,  223,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  223,
  239,  239,  239,  239,  239,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  239,  239,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  239,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  239,    0,  239,  239,
    0,    0,  239,  239,  239,    0,    0,    0,    0,    0,
    0,  239,  239,  239,  239,  223,    0,  239,    0,    0,
  239,    0,    0,    0,    0,    0,    0,  239,  239,  239,
  239,  239,  239,  239,  239,  239,  239,  239,  239,  239,
    0,    0,    0,    0,    0,    0,  239,  239,    0,    0,
    0,    0,    0,    0,  239,  239,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  239,  239,  239,  411,  412,  413,  414,  415,  416,
  417,  418,  419,  420,  421,  422,  423,  424,  425,  426,
  427,  428,  429,  430,  431,  432,  433,  434,  435,  436,
  437,  438,  279,  239,  239,  239,  239,  239,  239,  239,
  239,  239,  239,  239,  239,  239,  239,  239,  239,  239,
  239,  239,  239,  239,  239,  239,  239,  239,  239,  239,
  239,  239,  239,  279,  279,  239,  239,  279,  239,  239,
  239,  239,    0,    0,    0,    0,  223,    0,    0,    0,
    0,    0,    0,    0,    0,  239,  239,  239,  239,  239,
    0,    0,    0,    0,  223,  223,    0,    0,    0,    0,
    0,    0,  223,  223,  223,  223,  223,  223,  223,  223,
  223,  223,    0,    0,    0,    0,    0,  223,  223,  223,
    0,    0,    0,    0,    0,    0,    0,    0,  223,  223,
  223,    0,  223,  223,  223,  223,  223,  223,  223,  223,
    0,  223,  223,    0,    0,  223,    0,    0,    0,  223,
  223,    0,    0,  223,  223,    0,    0,    0,    0,    0,
    0,    0,    0,  223,    0,    0,    0,    0,    0,    0,
    0,  223,    0,    0,    0,  223,  223,  223,  223,  223,
    0,    0,    0,    0,    0,  223,  223,    0,    0,    0,
    0,  223,  223,  223,  223,  223,  223,  223,    0,    0,
    0,    0,    0,    0,  223,    0,    0,    0,    0,    0,
    0,  223,    0,  223,  223,  223,  223,  223,  223,  223,
  223,  223,  223,  223,  223,  223,  223,  223,  223,  223,
  223,    0,    0,  223,  223,    0,    0,    0,    0, 1081,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  223,    0,  223,    0,    0,  223,  223,  223,  223,  223,
  223,  223,  223,  223,  223,  223,  223,    0,  695,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  695,  223,  223,  223,  223,  223,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  223,  223,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  223,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  223,    0,  223,  223,    0,    0,  223,  223,  223,    0,
    0,    0,    0,    0,    0,  223,  223,  223,  223,  695,
    0,  223,    0,    0,  223,    0,    0,    0,    0,    0,
    0,  223,  223,  223,  223,  223,  223,  223,  223,  223,
  223,  223,  223,  223,    0,    0,    0,    0,    0,    0,
  223,  223,    0,    0,    0,    0,    0,    0,  223,  223,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  223,  223,  223,  411,  412,
  413,  414,  415,  416,  417,  418,  419,  420,  421,  422,
  423,  424,  425,  426,  427,  428,  429,  430,  431,  432,
  433,  434,  435,  436,  437,  438,  277,  223,  223,  223,
  223,  223,  223,  223,  223,  223,  223,  223,  223,  223,
  223,  223,  223,  223,  223,  223,  223,  223,  223,  223,
  223,  223,  223,  223,  223,  223,  223,  277,  277,  223,
  223,  277,  223,  223,  223,  223,    0,    0,    0,    0,
  695,    0,    0,    0,    0,    0,    0,    0,    0,  223,
  223,  223,  223,  223,    0,    0,    0,    0,  695,  695,
    0,    0,    0,    0,    0,    0,  695,  695,  695,  695,
  695,  695,  695,  695,  695,  695,    0,    0,    0,    0,
    0,  695,  695,  695,    0,    0,    0,    0,    0,    0,
    0,    0,  695,  695,  695,    0,  695,  695,  695,  695,
  695,  695,  695,  695,    0,  695,  695,    0,    0,  695,
    0,    0,    0,  695,  695,    0,    0,  695,  695,    0,
    0,    0,    0,    0,    0,    0,    0,  695,    0,    0,
    0,    0,    0,    0,    0,  695,    0,    0,    0,  695,
  695,  695,  695,  695,    0,    0,    0,    0,    0,  695,
  695,    0,    0,    0,    0,  695,  695,  695,  695,  695,
  695,  695,    0,    0,    0,    0,    0,    0,  695,    0,
    0,    0,    0,    0,    0,  695,    0,  695,  695,  695,
  695,  695,  695,  695,  695,  695,  695,  695,  695,  695,
  695,  695,  695,  695,  695,    0,    0,  695,  695,    0,
    0,    0,    0, 1090,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  695,    0,  695,    0,    0,  695,
  695,  695,  695,  695,  695,  695,  695,  695,  695,  695,
  695,    0,  173,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  173,  695,  695,
  695,  695,  695,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  695,  695,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  695,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  695,    0,  695,  695,    0,    0,
  695,  695,  695,    0,    0,    0,    0,    0,    0,  695,
  695,  695,  695,  173,    0,  695,    0,    0,  695,    0,
    0,    0,    0,    0,    0,  695,  695,  695,  695,  695,
  695,  695,  695,  695,  695,  695,  695,  695,    0,    0,
    0,    0,    0,    0,  695,  695,    0,    0,    0,    0,
    0,    0,  695,  695,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  695,
  695,  695,  411,  412,  413,  414,  415,  416,  417,  418,
  419,  420,  421,  422,  423,  424,  425,  426,  427,  428,
  429,  430,  431,  432,  433,  434,  435,  436,  437,  438,
  280,  695,  695,  695,  695,  695,  695,  695,  695,  695,
  695,  695,  695,  695,  695,  695,  695,  695,  695,  695,
  695,  695,  695,  695,  695,  695,  695,  695,  695,  695,
  695,  280,  280,  695,  695,  280,  695,  695,  695,  695,
    0,    0,    0,    0,  173,    0,    0,    0,    0,    0,
    0,    0,    0,  695,  695,  695,  695,  695,    0,    0,
    0,    0,  173,  173,    0,    0,    0,    0,    0,    0,
  173,  173,  173,  173,  173,  173,  173,  173,  173,  173,
    0,    0,    0,    0,    0,  173,  173,  173,    0,    0,
    0,    0,    0,    0,    0,    0,  173,  173,  173,    0,
  173,  173,  173,  173,  173,  173,  173,  173,    0,  173,
  173,    0,    0,  173,    0,    0,    0,  173,  173,    0,
    0,  173,  173,    0,    0,    0,    0,    0,    0,    0,
    0,  173,    0,    0,    0,    0,    0,    0,    0,  173,
    0,    0,    0,  173,  173,  173,  173,  173,    0,    0,
    0,    0,    0,  173,  173,    0,    0,    0,    0,  173,
  173,  173,  173,  173,  173,  173,    0,    0,    0,    0,
    0,    0,  173,    0,    0,    0,    0,    0,    0,  173,
    0,  173,  173,  173,  173,  173,  173,  173,  173,  173,
  173,  173,  173,  173,  173,  173,  173,  173,  173,    0,
    0,  173,  173,    0,    0,    0,    0, 1103,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  173,    0,
  173,    0,    0,  173,  173,  173,  173,  173,  173,  173,
  173,  173,  173,  173,  173,    0,  697,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  697,  173,  173,  173,  173,  173,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  173,  173,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  173,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  173,    0,
  173,  173,    0,    0,  173,  173,  173,    0,    0,    0,
    0,    0,    0,  173,  173,  173,  173,  697,    0,  173,
    0,    0,  173,    0,    0,    0,    0,    0,    0,  173,
  173,  173,  173,  173,  173,  173,  173,  173,  173,  173,
  173,  173,    0,    0,    0,    0,    0,    0,  173,  173,
    0,    0,    0,    0,    0,    0,  173,  173,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  173,  173,  173,  411,  412,  413,  414,
  415,  416,  417,  418,  419,  420,  421,  422,  423,  424,
  425,  426,  427,  428,  429,  430,  431,  432,  433,  434,
  435,  436,  437,  438,  173,  173,  173,  173,  173,  173,
  173,  173,  173,  173,  173,  173,  173,  173,  173,  173,
  173,  173,  173,  173,  173,  173,  173,  173,  173,  173,
  173,  173,  173,  173,  173,  173,  173,    0,  173,  173,
  173,  173,  173,  173,    0,    0,    0,    0,  697,    0,
    0,    0,    0,    0,    0,    0,    0,  173,  173,  173,
  173,  173,    0,    0,    0,    0,  697,  697,    0,    0,
    0,    0,    0,    0,  697,  697,  697,  697,  697,  697,
  697,  697,  697,  697,    0,    0,    0,    0,    0,  697,
  697,  697,    0,    0,    0,    0,    0,    0,    0,    0,
  697,  697,  697,    0,  697,  697,  697,  697,  697,  697,
  697,  697,    0,  697,  697,    0,    0,  697,    0,    0,
    0,  697,  697,    0,    0,  697,  697,    0,    0,    0,
    0,    0,    0,    0,    0,  697,    0,    0,    0,    0,
    0,    0,    0,  697,    0,    0,    0,  697,  697,  697,
  697,  697,    0,    0,    0,    0,    0,  697,  697,    0,
    0,    0,    0,  697,  697,  697,  697,  697,  697,  697,
    0,    0,    0,    0,    0,    0,  697,    0,    0,    0,
    0,    0,    0,  697,    0,  697,  697,  697,  697,  697,
  697,  697,  697,  697,  697,  697,  697,  697,  697,  697,
  697,  697,  697,    0,    0,  697,  697,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  697,    0,  697,    0,    0,  697,  697,  697,
  697,  697,  697,  697,  697,  697,  697,  697,  697,    0,
  604,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  604,  697,  697,  697,  697,
  697,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  697,  697,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  697,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  697,    0,  697,  697,    0,    0,  697,  697,
  697,    0,    0,    0,    0,    0,    0,  697,  697,  697,
  697,  604,    0,  697,    0,    0,  697,    0,    0,    0,
    0,    0,    0,  697,  697,  697,  697,  697,  697,  697,
  697,  697,  697,  697,  697,  697,    0,    0,    0,    0,
    0,    0,  697,  697,    0,    0,    0,    0,    0,    0,
  697,  697,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  697,  697,  697,
  411,  412,  413,  414,  415,  416,  417,  418,  419,  420,
  421,  422,  423,  424,  425,  426,  427,  428,  429,  430,
  431,  432,  433,  434,  435,  436,  437,  438,    0,  697,
  697,  697,  697,  697,  697,  697,  697,  697,  697,  697,
  697,  697,  697,  697,  697,  697,  697,  697,  697,  697,
  697,  697,  697,  697,  697,  697,  697,  697,  697,    0,
    0,  697,  697,    0,  697,  697,  697,  697,    0,    0,
    0,    0,  604,    0,    0,    0,    0,    0,    0,    0,
    0,  697,  697,  697,  697,  697,    0,    0,    0,    0,
  604,  604,    0,    0,    0,    0,    0,    0,  604,  604,
  604,  604,  604,  604,  604,  604,  604,  604,    0,    0,
    0,    0,    0,  604,  604,  604,    0,    0,    0,    0,
    0,    0,    0,    0,  604,  604,  604,    0,  604,  604,
  604,  604,  604,  604,  604,  604,    0,  604,  604,    0,
    0,  604,    0,    0,    0,  604,  604,    0,    0,  604,
  604,    0,    0,    0,    0,    0,    0,    0,    0,  604,
    0,    0,    0,    0,    0,    0,    0,  604,    0,    0,
    0,  604,  604,  604,  604,  604,    0,    0,    0,    0,
    0,  604,  604,    0,    0,    0,    0,  604,  604,  604,
  604,  604,  604,  604,    0,    0,    0,    0,    0,    0,
  604,    0,    0,    0,    0,    0,    0,  604,    0,  604,
  604,  604,  604,  604,  604,  604,  604,  604,  604,  604,
  604,  604,  604,  604,  604,  604,  604,    0,    0,  604,
  604,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  604,    0,  604,    0,
    0,  604,  604,  604,  604,  604,  604,  604,  604,  604,
  604,  604,  604,    0,  659,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  659,
  604,  604,  604,  604,  604,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  604,  604,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  604,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  604,    0,  604,  604,
    0,    0,  604,  604,  604,    0,    0,    0,    0,    0,
    0,  604,  604,  604,  604,  659,    0,  604,    0,    0,
  604,    0,    0,    0,    0,    0,    0,  604,  604,  604,
  604,  604,  604,  604,  604,  604,  604,  604,  604,  604,
    0,    0,    0,    0,    0,    0,  604,  604,    0,    0,
    0,    0,    0,    0,  604,  604,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  604,  604,  604,  411,  412,  413,  414,  415,  416,
  417,  418,  419,  420,  421,  422,  423,  424,  425,  426,
  427,  428,  429,  430,  431,  432,  433,  434,  435,  436,
  437,  438,    0,  604,  604,  604,  604,  604,  604,  604,
  604,  604,  604,  604,  604,  604,  604,  604,  604,  604,
  604,  604,  604,  604,  604,  604,  604,  604,  604,  604,
  604,  604,  604,    0,    0,    0,  604,    0,  604,  604,
  604,  604,    0,    0,    0,    0,  659,    0,    0,    0,
    0,    0,    0,    0,    0,  604,  604,  604,  604,  604,
    0,    0,    0,    0,  659,  659,    0,    0,    0,    0,
    0,    0,  659,  659,  659,  659,  659,  659,  659,  659,
  659,  659,    0,    0,    0,    0,    0,  659,  659,  659,
    0,    0,    0,    0,    0,    0,    0,    0,  659,  659,
  659,    0,  659,  659,  659,  659,  659,  659,  659,  659,
    0,  659,  659,    0,    0,  659,    0,    0,    0,  659,
  659,    0,    0,  659,  659,    0,    0,    0,    0,    0,
    0,    0,    0,  659,    0,    0,    0,    0,    0,    0,
    0,  659,    0,    0,    0,  659,  659,  659,  659,  659,
    0,    0,    0,    0,    0,  659,  659,    0,    0,    0,
    0,  659,  659,  659,  659,  659,  659,  659,    0,    0,
    0,    0,    0,    0,  659,    0,    0,    0,    0,    0,
    0,  659,    0,  659,  659,  659,  659,  659,  659,  659,
  659,  659,  659,  659,  659,  659,  659,  659,  659,  659,
  659,    0,    0,  659,  659,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  659,    0,  659,    0,    0,  659,  659,  659,  659,  659,
  659,  659,  659,  659,  659,  659,  659,    0,  671,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  671,  659,  659,  659,  659,  659,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  659,  659,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  659,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  659,    0,  659,  659,    0,    0,  659,  659,  659,    0,
    0,    0,    0,    0,    0,  659,  659,  659,  659,  671,
    0,  659,    0,    0,  659,    0,    0,    0,    0,    0,
    0,  659,  659,  659,  659,  659,  659,  659,  659,  659,
  659,  659,  659,  659,    0,    0,    0,    0,    0,    0,
  659,  659,    0,    0,    0,    0,    0,    0,  659,  659,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  659,  659,  659,    0,  902,
  903,  904,  905,  906,  907,  908,  909,  910,  911,  912,
  913,  914,  915,  916,  917,  918,  919,  920,  921,  922,
  923,  924,  925,  926,  927,  928,  929,  659,  659,  659,
  659,  659,  659,  659,  659,  659,  659,  659,  659,  659,
  659,  659,  659,  659,  659,  659,  659,  659,  659,  659,
  659,  659,    0,    0,    0,  659,  659,    0,    0,  659,
  659,    0,  659,  659,  659,  659,    0,    0,    0,    0,
  671,    0,    0,    0,    0,    0,    0,    0,    0,  659,
  659,  659,  659,  659,    0,    0,    0,    0,  671,  671,
    0,    0,    0,    0,    0,    0,  671,  671,  671,  671,
  671,  671,  671,  671,  671,  671,    0,    0,    0,    0,
    0,  671,  671,  671,    0,    0,    0,    0,    0,    0,
    0,    0,  671,  671,  671,    0,  671,  671,  671,  671,
  671,  671,  671,  671,    0,  671,  671,    0,    0,  671,
    0,    0,    0,  671,  671,    0,    0,  671,  671,    0,
    0,    0,    0,    0,    0,    0,    0,  671,    0,    0,
    0,    0,    0,    0,    0,  671,    0,    0,    0,  671,
  671,  671,  671,  671,    0,    0,    0,    0,    0,  671,
  671,    0,    0,    0,    0,  671,  671,  671,  671,  671,
  671,  671,    0,    0,    0,    0,    0,    0,  671,    0,
    0,    0,    0,    0,    0,  671,    0,  671,  671,  671,
  671,  671,  671,  671,  671,  671,  671,  671,  671,  671,
  671,  671,  671,  671,  671,    0,    0,  671,  671,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  671,    0,  671,    0,    0,  671,
  671,  671,  671,  671,  671,  671,  671,  671,  671,  671,
  671,    0,  669,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  669,  671,  671,
  671,  671,  671,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  671,  671,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  671,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  671,    0,  671,  671,    0,    0,
  671,  671,  671,    0,    0,    0,    0,    0,    0,  671,
  671,  671,  671,  669,    0,  671,    0,    0,  671,    0,
    0,    0,    0,    0,    0,  671,  671,  671,  671,  671,
  671,  671,  671,  671,  671,  671,  671,  671,    0,    0,
    0,    0,    0,    0,  671,  671,    0,    0,    0,    0,
    0,    0,  671,  671,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  671,
  671,  671,  230,  230,  230,  230,  230,  230,  230,  230,
  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,
  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,
    0,  671,  671,  671,  671,  671,  671,  671,  671,  671,
  671,  671,  671,  671,  671,  671,  671,  671,  671,  671,
  671,  671,  671,  671,  671,  671,    0,    0,    0,  671,
  671,    0,    0,  671,  671,    0,  671,  671,  671,  671,
    0,    0,    0,    0,  669,    0,    0,    0,    0,    0,
    0,    0,    0,  671,  671,  671,  671,  671,    0,    0,
    0,    0,  669,  669,    0,    0,    0,    0,    0,    0,
  669,  669,  669,  669,  669,  669,  669,  669,  669,  669,
    0,    0,    0,    0,    0,  669,  669,  669,    0,    0,
    0,    0,    0,    0,    0,    0,  669,  669,  669,    0,
  669,  669,  669,  669,  669,  669,  669,  669,    0,  669,
  669,    0,    0,  669,    0,    0,    0,  669,  669,    0,
    0,  669,  669,    0,    0,    0,    0,    0,    0,    0,
    0,  669,    0,    0,    0,    0,    0,    0,    0,  669,
    0,    0,    0,  669,  669,  669,  669,  669,    0,    0,
    0,    0,    0,  669,  669,    0,    0,    0,    0,  669,
  669,  669,  669,  669,  669,  669,    0,    0,    0,    0,
    0,    0,  669,    0,    0,    0,    0,    0,    0,  669,
    0,  669,  669,  669,  669,  669,  669,  669,  669,  669,
  669,  669,  669,  669,  669,  669,  669,  669,  669,    0,
    0,  669,  669,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  669,    0,
  669,    0,    0,  669,  669,  669,  669,  669,  669,  669,
  669,  669,  669,  669,  669,    0,  667,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  667,  669,  669,  669,  669,  669,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  669,  669,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  669,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  669,    0,
  669,  669,    0,    0,  669,  669,  669,    0,    0,    0,
    0,    0,    0,  669,  669,  669,  669,  667,    0,  669,
    0,    0,  669,    0,    0,    0,    0,    0,    0,  669,
  669,  669,  669,  669,  669,  669,  669,  669,  669,  669,
  669,  669,    0,    0,    0,    0,    0,    0,  669,  669,
    0,    0,    0,    0,    0,    0,  669,  669,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  669,  669,  669,  226,  226,  226,  226,
  226,  226,  226,  226,  226,  226,  226,  226,  226,  226,
  226,  226,  226,  226,  226,  226,  226,  226,  226,  226,
  226,  226,  226,  226,    0,  669,  669,  669,  669,  669,
  669,  669,  669,  669,  669,  669,  669,  669,  669,  669,
  669,  669,  669,  669,  669,  669,  669,  669,    0,    0,
    0,    0,    0,  669,  669,    0,    0,  669,  669,    0,
  669,  669,  669,  669,    0,    0,    0,    0,  667,    0,
    0,    0,    0,    0,    0,    0,    0,  669,  669,  669,
  669,  669,    0,    0,    0,    0,  667,  667,    0,    0,
    0,    0,    0,    0,  667,  667,  667,  667,  667,  667,
  667,  667,  667,  667,    0,    0,    0,    0,    0,  667,
  667,  667,    0,    0,    0,    0,    0,    0,    0,    0,
  667,  667,  667,    0,  667,  667,  667,  667,  667,  667,
  667,  667,    0,  667,  667,    0,    0,  667,    0,    0,
    0,  667,  667,    0,    0,  667,  667,    0,    0,    0,
    0,    0,    0,    0,    0,  667,    0,    0,    0,    0,
    0,    0,    0,  667,    0,    0,    0,  667,  667,  667,
  667,  667,    0,    0,    0,    0,    0,  667,  667,    0,
    0,    0,    0,  667,  667,  667,  667,  667,  667,  667,
    0,    0,    0,    0,    0,    0,  667,    0,    0,    0,
    0,    0,    0,  667,    0,  667,  667,  667,  667,  667,
  667,  667,  667,  667,  667,  667,  667,  667,  667,  667,
  667,  667,  667,    0,    0,  667,  667,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  667,    0,  667,    0,    0,  667,  667,  667,
  667,  667,  667,  667,  667,  667,  667,  667,  667,    0,
  679,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  679,  667,  667,  667,  667,
  667,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  667,  667,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  667,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  667,    0,  667,  667,    0,    0,  667,  667,
  667,    0,    0,    0,    0,    0,    0,  667,  667,  667,
  667,  679,    0,  667,    0,    0,  667,    0,    0,    0,
    0,    0,    0,  667,  667,  667,  667,  667,  667,  667,
  667,  667,  667,  667,  667,  667,    0,    0,    0,    0,
    0,    0,  667,  667,    0,    0,    0,    0,    0,    0,
  667,  667,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  667,  667,  667,
   32,   32,   32,   32,   32,   32,   32,   32,   32,   32,
   32,   32,   32,   32,   32,   32,   32,   32,   32,   32,
   32,   32,   32,   32,   32,   32,   32,   32,    0,  667,
  667,  667,  667,  667,  667,  667,  667,  667,  667,  667,
  667,  667,  667,  667,  667,  667,  667,  667,  667,  667,
  667,  667,    0,    0,    0,    0,    0,  667,  667,    0,
    0,  667,  667,    0,  667,  667,  667,  667,    0,    0,
    0,    0,  679,    0,    0,    0,    0,    0,    0,    0,
    0,  667,  667,  667,  667,  667,    0,    0,    0,    0,
  679,  679,    0,    0,    0,    0,    0,    0,  679,  679,
  679,  679,  679,  679,  679,  679,  679,  679,    0,    0,
    0,    0,    0,  679,  679,  679,    0,    0,    0,    0,
    0,    0,    0,    0,  679,  679,  679,    0,  679,  679,
  679,  679,  679,  679,  679,  679,    0,  679,  679,    0,
    0,  679,    0,    0,    0,  679,  679,    0,    0,  679,
  679,    0,    0,    0,    0,    0,    0,    0,    0,  679,
    0,    0,    0,    0,    0,    0,    0,  679,    0,    0,
    0,  679,  679,  679,  679,  679,    0,    0,    0,    0,
    0,  679,  679,    0,    0,    0,    0,  679,  679,  679,
  679,  679,  679,  679,    0,    0,    0,    0,    0,    0,
  679,    0,    0,    0,    0,    0,    0,  679,    0,  679,
  679,  679,  679,  679,  679,  679,  679,  679,  679,  679,
  679,  679,  679,  679,  679,  679,  679,    0,    0,  679,
  679,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  679,    0,  679,    0,
    0,  679,  679,  679,  679,  679,  679,  679,  679,  679,
  679,  679,  679,    0,  683,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  683,
  679,  679,  679,  679,  679,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  679,  679,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  679,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  679,    0,  679,  679,
    0,    0,  679,  679,  679,    0,    0,    0,    0,    0,
    0,  679,  679,  679,  679,  683,    0,  679,    0,    0,
  679,    0,    0,    0,    0,    0,    0,  679,  679,  679,
  679,  679,  679,  679,  679,  679,  679,  679,  679,  679,
    0,    0,    0,    0,    0,    0,  679,  679,    0,    0,
    0,    0,    0,    0,  679,  679,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  679,  679,  679,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  679,  679,  679,  679,  679,  679,  679,
  679,  679,  679,  679,  679,  679,  679,  679,  679,  679,
  679,  679,  679,  679,    0,    0,    0,    0,    0,    0,
    0,  679,  679,    0,    0,  679,  679,    0,  679,  679,
  679,  679,    0,    0,    0,    0,  683,    0,    0,    0,
    0,    0,    0,    0,    0,  679,  679,  679,  679,  679,
    0,    0,    0,    0,  683,  683,    0,    0,    0,    0,
    0,    0,  683,  683,  683,  683,  683,  683,  683,  683,
  683,  683,    0,    0,    0,    0,    0,  683,  683,  683,
    0,    0,    0,    0,    0,    0,    0,    0,  683,  683,
  683,    0,  683,  683,  683,  683,  683,  683,  683,  683,
    0,  683,  683,    0,    0,  683,    0,    0,    0,  683,
  683,    0,    0,  683,  683,    0,    0,    0,    0,    0,
    0,    0,    0,  683,    0,    0,    0,    0,    0,    0,
    0,  683,    0,    0,    0,  683,  683,  683,  683,  683,
    0,    0,    0,    0,    0,  683,  683,    0,    0,    0,
    0,  683,  683,  683,  683,  683,  683,  683,    0,    0,
    0,    0,    0,    0,  683,    0,    0,    0,    0,    0,
    0,  683,    0,  683,  683,  683,  683,  683,  683,  683,
  683,  683,  683,  683,  683,  683,  683,  683,  683,  683,
  683,    0,    0,  683,  683,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  683,    0,  683,    0,    0,  683,  683,  683,  683,  683,
  683,  683,  683,  683,  683,  683,  683,    0,  681,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  681,  683,  683,  683,  683,  683,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  683,  683,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  683,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  683,    0,  683,  683,    0,    0,  683,  683,  683,    0,
    0,    0,    0,    0,    0,  683,  683,  683,  683,  681,
    0,  683,    0,    0,  683,    0,    0,    0,    0,    0,
    0,  683,  683,  683,  683,  683,  683,  683,  683,  683,
  683,  683,  683,  683,    0,    0,    0,    0,    0,    0,
  683,  683,    0,    0,    0,    0,    0,    0,  683,  683,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  683,  683,  683,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  683,  683,  683,
  683,  683,  683,  683,  683,  683,  683,  683,  683,  683,
  683,  683,  683,  683,  683,  683,  683,  683,    0,    0,
    0,    0,    0,    0,    0,  683,  683,    0,    0,  683,
  683,    0,  683,  683,  683,  683,    0,    0,    0,    0,
  681,    0,    0,    0,    0,    0,    0,    0,    0,  683,
  683,  683,  683,  683,    0,    0,    0,    0,  681,  681,
    0,    0,    0,    0,    0,    0,  681,  681,  681,  681,
  681,  681,  681,  681,  681,  681,    0,    0,    0,    0,
    0,  681,  681,  681,    0,    0,    0,    0,    0,    0,
    0,    0,  681,  681,  681,    0,  681,  681,  681,  681,
  681,  681,  681,  681,    0,  681,  681,    0,    0,  681,
    0,    0,    0,  681,  681,    0,    0,  681,  681,    0,
    0,    0,    0,    0,    0,    0,    0,  681,    0,    0,
    0,    0,    0,    0,    0,  681,    0,    0,    0,  681,
  681,  681,  681,  681,    0,    0,    0,    0,    0,  681,
  681,    0,    0,    0,    0,  681,  681,  681,  681,  681,
  681,  681,    0,    0,    0,    0,    0,    0,  681,    0,
    0,    0,    0,    0,    0,  681,    0,  681,  681,  681,
  681,  681,  681,  681,  681,  681,  681,  681,  681,  681,
  681,  681,  681,  681,  681,    0,    0,  681,  681,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  681,    0,  681,    0,    0,  681,
  681,  681,  681,  681,  681,  681,  681,  681,  681,  681,
  681,    0,  685,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  685,  681,  681,
  681,  681,  681,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  681,  681,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  681,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  681,    0,  681,  681,    0,    0,
  681,  681,  681,    0,    0,    0,    0,    0,    0,  681,
  681,  681,  681,  685,    0,  681,    0,    0,  681,    0,
    0,    0,    0,    0,    0,  681,  681,  681,  681,  681,
  681,  681,  681,  681,  681,  681,  681,  681,    0,    0,
    0,    0,    0,    0,  681,  681,    0,    0,    0,    0,
    0,    0,  681,  681,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  681,
  681,  681,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  681,  681,  681,  681,  681,  681,  681,  681,  681,
  681,  681,  681,  681,  681,  681,  681,  681,  681,  681,
  681,  681,    0,    0,    0,    0,    0,    0,    0,  681,
  681,    0,    0,  681,  681,    0,  681,  681,  681,  681,
    0,    0,    0,    0,  685,    0,    0,    0,    0,    0,
    0,    0,    0,  681,  681,  681,  681,  681,    0,    0,
    0,    0,  685,  685,    0,    0,    0,    0,    0,    0,
  685,  685,  685,  685,  685,  685,  685,  685,  685,  685,
    0,    0,    0,    0,    0,  685,  685,  685,    0,    0,
    0,    0,    0,    0,    0,    0,  685,  685,  685,    0,
  685,  685,  685,  685,  685,  685,  685,  685,    0,  685,
  685,    0,    0,  685,    0,    0,    0,  685,  685,    0,
    0,  685,  685,    0,    0,    0,    0,    0,    0,    0,
    0,  685,    0,    0,    0,    0,    0,    0,    0,  685,
    0,    0,    0,  685,  685,  685,  685,  685,    0,    0,
    0,    0,    0,  685,  685,    0,    0,    0,    0,  685,
  685,  685,  685,  685,  685,  685,    0,    0,    0,    0,
    0,    0,  685,    0,    0,    0,    0,    0,    0,  685,
    0,  685,  685,  685,  685,  685,  685,  685,  685,  685,
  685,  685,  685,  685,  685,  685,  685,  685,  685,    0,
    0,  685,  685,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  685,    0,
  685,    0,    0,  685,  685,  685,  685,  685,  685,  685,
  685,  685,  685,  685,  685,    0,  687,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  687,  685,  685,  685,  685,  685,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  685,  685,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  685,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  685,    0,
  685,  685,    0,    0,  685,  685,  685,    0,    0,    0,
    0,    0,    0,  685,  685,  685,  685,  687,    0,  685,
    0,    0,  685,    0,    0,    0,    0,    0,    0,  685,
  685,  685,  685,  685,  685,  685,  685,  685,  685,  685,
  685,  685,    0,    0,    0,    0,    0,    0,  685,  685,
    0,    0,    0,    0,    0,    0,  685,  685,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  685,  685,  685,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  685,  685,  685,  685,  685,
  685,  685,  685,  685,  685,  685,  685,  685,  685,  685,
  685,  685,  685,  685,  685,  685,    0,    0,    0,    0,
    0,    0,    0,  685,  685,    0,    0,  685,  685,    0,
  685,  685,  685,  685,    0,    0,    0,    0,  687,    0,
    0,    0,    0,    0,    0,    0,    0,  685,  685,  685,
  685,  685,    0,    0,    0,    0,  687,  687,    0,    0,
    0,    0,    0,    0,  687,  687,  687,  687,  687,  687,
  687,  687,  687,  687,    0,    0,    0,    0,    0,  687,
  687,  687,    0,    0,    0,    0,    0,    0,    0,    0,
  687,  687,  687,    0,  687,  687,  687,  687,  687,  687,
  687,  687,    0,  687,  687,    0,    0,  687,    0,    0,
    0,  687,  687,    0,    0,  687,  687,    0,    0,    0,
    0,    0,    0,    0,    0,  687,    0,    0,    0,    0,
    0,    0,    0,  687,    0,    0,    0,  687,  687,  687,
  687,  687,    0,    0,    0,    0,    0,  687,  687,    0,
    0,    0,    0,  687,  687,  687,  687,  687,  687,  687,
    0,    0,    0,    0,    0,    0,  687,    0,    0,    0,
    0,    0,    0,  687,    0,  687,  687,  687,  687,  687,
  687,  687,  687,  687,  687,  687,  687,  687,  687,  687,
  687,  687,  687,    0,    0,  687,  687,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  687,    0,  687,    0,    0,  687,  687,  687,
  687,  687,  687,  687,  687,  687,  687,  687,  687,    0,
  689,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  689,  687,  687,  687,  687,
  687,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  687,  687,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  687,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  687,    0,  687,  687,    0,    0,  687,  687,
  687,    0,    0,    0,    0,    0,    0,  687,  687,  687,
  687,  689,    0,  687,    0,    0,  687,    0,    0,    0,
    0,    0,    0,  687,  687,  687,  687,  687,  687,  687,
  687,  687,  687,  687,  687,  687,    0,    0,    0,    0,
    0,    0,  687,  687,    0,    0,    0,    0,    0,    0,
  687,  687,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  687,  687,  687,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  687,
  687,  687,  687,  687,  687,  687,  687,  687,  687,  687,
  687,  687,  687,  687,  687,  687,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  687,  687,    0,
    0,  687,  687,    0,  687,  687,  687,  687,    0,    0,
    0,    0,  689,    0,    0,    0,    0,    0,    0,    0,
    0,  687,  687,  687,  687,  687,    0,    0,    0,    0,
  689,  689,    0,    0,    0,    0,    0,    0,  689,  689,
  689,  689,  689,  689,  689,  689,  689,  689,    0,    0,
    0,    0,    0,  689,  689,  689,    0,    0,    0,    0,
    0,    0,    0,    0,  689,  689,  689,    0,  689,  689,
  689,  689,  689,  689,  689,  689,    0,  689,  689,    0,
    0,  689,    0,    0,    0,  689,  689,    0,    0,  689,
  689,    0,    0,    0,    0,    0,    0,    0,    0,  689,
    0,    0,    0,    0,    0,    0,    0,  689,    0,    0,
    0,  689,  689,  689,  689,  689,    0,    0,    0,    0,
    0,  689,  689,    0,    0,    0,    0,  689,  689,  689,
  689,  689,  689,  689,    0,    0,    0,    0,    0,    0,
  689,    0,    0,    0,    0,    0,    0,  689,    0,  689,
  689,  689,  689,  689,  689,  689,  689,  689,  689,  689,
  689,  689,  689,  689,  689,  689,  689,    0,    0,  689,
  689,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  689,    0,  689,    0,
    0,  689,  689,  689,  689,  689,  689,  689,  689,  689,
  689,  689,  689,    0,  673,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  673,
  689,  689,  689,  689,  689,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  689,  689,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  689,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  689,    0,  689,  689,
    0,    0,  689,  689,  689,    0,    0,    0,    0,    0,
    0,  689,  689,  689,  689,  673,    0,  689,    0,    0,
  689,    0,    0,    0,    0,    0,    0,  689,  689,  689,
  689,  689,  689,  689,  689,  689,  689,  689,  689,  689,
    0,    0,    0,    0,    0,    0,  689,  689,    0,    0,
    0,    0,    0,    0,  689,  689,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  689,  689,  689,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  689,  689,  689,  689,  689,  689,  689,
  689,  689,  689,  689,  689,  689,  689,  689,  689,  689,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  689,  689,    0,    0,  689,  689,    0,  689,  689,
  689,  689,    0,    0,    0,    0,  673,    0,    0,    0,
    0,    0,    0,    0,    0,  689,  689,  689,  689,  689,
    0,    0,    0,    0,  673,  673,    0,    0,    0,    0,
    0,    0,  673,  673,  673,  673,  673,  673,  673,  673,
  673,  673,    0,    0,    0,    0,    0,  673,  673,  673,
    0,    0,    0,    0,    0,    0,    0,    0,  673,  673,
  673,    0,  673,  673,  673,  673,  673,  673,  673,  673,
    0,  673,  673,    0,    0,  673,    0,    0,    0,  673,
  673,    0,    0,  673,  673,    0,    0,    0,    0,    0,
    0,    0,    0,  673,    0,    0,    0,    0,    0,    0,
    0,  673,    0,    0,    0,  673,  673,  673,  673,  673,
    0,    0,    0,    0,    0,  673,  673,    0,    0,    0,
    0,  673,  673,  673,  673,  673,  673,  673,    0,    0,
    0,    0,    0,    0,  673,    0,    0,    0,    0,    0,
    0,  673,    0,  673,  673,  673,  673,  673,  673,  673,
  673,  673,  673,  673,  673,  673,  673,  673,  673,  673,
  673,    0,    0,  673,  673,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  673,    0,  673,    0,    0,  673,  673,  673,  673,  673,
  673,  673,  673,  673,  673,  673,  673,    0,  677,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  677,  673,  673,  673,  673,  673,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  673,  673,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  673,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  673,    0,  673,  673,    0,    0,  673,  673,  673,    0,
    0,    0,    0,    0,    0,  673,  673,  673,  673,  677,
    0,  673,    0,    0,  673,    0,    0,    0,    0,    0,
    0,  673,  673,  673,  673,  673,  673,  673,  673,  673,
  673,  673,  673,  673,    0,    0,    0,    0,    0,    0,
  673,  673,    0,    0,    0,    0,    0,    0,  673,  673,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  673,  673,  673,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  673,  673,  673,
  673,  673,  673,  673,  673,  673,  673,  673,  673,  673,
  673,  673,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  673,  673,    0,    0,  673,
  673,    0,  673,  673,  673,  673,    0,    0,    0,    0,
  677,    0,    0,    0,    0,    0,    0,    0,    0,  673,
  673,  673,  673,  673,    0,    0,    0,    0,  677,  677,
    0,    0,    0,    0,    0,    0,  677,  677,  677,  677,
  677,  677,  677,  677,  677,  677,    0,    0,    0,    0,
    0,  677,  677,  677,    0,    0,    0,    0,    0,    0,
    0,    0,  677,  677,  677,    0,  677,  677,  677,  677,
  677,  677,  677,  677,    0,  677,  677,    0,    0,  677,
    0,    0,    0,  677,  677,    0,    0,  677,  677,    0,
    0,    0,    0,    0,    0,    0,    0,  677,    0,    0,
    0,    0,    0,    0,    0,  677,    0,    0,    0,  677,
  677,  677,  677,  677,    0,    0,    0,    0,    0,  677,
  677,    0,    0,    0,    0,  677,  677,  677,  677,  677,
  677,  677,    0,    0,    0,    0,    0,    0,  677,    0,
    0,    0,    0,    0,    0,  677,    0,  677,  677,  677,
  677,  677,  677,  677,  677,  677,  677,  677,  677,  677,
  677,  677,  677,  677,  677,    0,    0,  677,  677,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  677,    0,  677,    0,    0,  677,
  677,  677,  677,  677,  677,  677,  677,  677,  677,  677,
  677,    0,  675,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  675,  677,  677,
  677,  677,  677,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  677,  677,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  677,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  677,    0,  677,  677,    0,    0,
  677,  677,  677,    0,    0,    0,    0,    0,    0,  677,
  677,  677,  677,  675,    0,  677,    0,    0,  677,    0,
    0,    0,    0,    0,    0,  677,  677,  677,  677,  677,
  677,  677,  677,  677,  677,  677,  677,  677,    0,    0,
    0,    0,    0,    0,  677,  677,    0,    0,    0,    0,
    0,    0,  677,  677,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  677,
  677,  677,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  677,  677,  677,  677,  677,  677,  677,  677,  677,
  677,  677,  677,  677,  677,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  677,
  677,    0,    0,  677,  677,    0,  677,  677,  677,  677,
    0,    0,    0,    0,  675,    0,    0,    0,    0,    0,
    0,    0,    0,  677,  677,  677,  677,  677,    0,    0,
    0,    0,  675,  675,    0,    0,    0,    0,    0,    0,
  675,  675,  675,  675,  675,  675,  675,  675,  675,  675,
    0,    0,    0,    0,    0,  675,  675,  675,    0,    0,
    0,    0,    0,    0,    0,    0,  675,  675,  675,    0,
  675,  675,  675,  675,  675,  675,  675,  675,    0,  675,
  675,    0,    0,  675,    0,    0,    0,  675,  675,    0,
    0,  675,  675,    0,    0,    0,    0,    0,    0,    0,
    0,  675,    0,    0,    0,    0,    0,    0,    0,  675,
    0,    0,    0,  675,  675,  675,  675,  675,    0,    0,
    0,    0,    0,  675,  675,    0,    0,    0,    0,  675,
  675,  675,  675,  675,  675,  675,    0,    0,    0,    0,
    0,    0,  675,    0,    0,    0,    0,    0,    0,  675,
    0,  675,  675,  675,  675,  675,  675,  675,  675,  675,
  675,  675,  675,  675,  675,  675,  675,  675,  675,    0,
    0,  675,  675,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  675,    0,
  675,    0,    0,  675,  675,  675,  675,  675,  675,  675,
  675,  675,  675,  675,  675,    0,  691,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  691,  675,  675,  675,  675,  675,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  675,  675,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  675,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  675,    0,
  675,  675,    0,    0,  675,  675,  675,    0,    0,    0,
    0,    0,    0,  675,  675,  675,  675,  691,    0,  675,
    0,    0,  675,    0,    0,    0,    0,    0,    0,  675,
  675,  675,  675,  675,  675,  675,  675,  675,  675,  675,
  675,  675,    0,    0,    0,    0,    0,    0,  675,  675,
    0,    0,    0,    0,    0,    0,  675,  675,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  675,  675,  675,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  675,  675,  675,  675,  675,
  675,  675,  675,  675,  675,  675,  675,  675,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  675,  675,    0,    0,  675,  675,    0,
  675,  675,  675,  675,    0,    0,    0,    0,  691,    0,
    0,    0,    0,    0,    0,    0,    0,  675,  675,  675,
  675,  675,    0,    0,    0,    0,  691,  691,    0,    0,
    0,    0,    0,    0,  691,  691,  691,  691,  691,  691,
  691,  691,  691,  691,    0,    0,    0,    0,    0,  691,
  691,  691,    0,    0,    0,    0,    0,    0,    0,    0,
  691,  691,  691,    0,  691,  691,  691,  691,  691,  691,
  691,  691,    0,  691,  691,    0,    0,  691,    0,    0,
    0,  691,  691,    0,    0,  691,  691,    0,    0,    0,
    0,    0,    0,    0,    0,  691,    0,    0,    0,    0,
    0,    0,    0,  691,    0,    0,    0,  691,  691,  691,
  691,  691,    0,    0,    0,    0,    0,  691,  691,    0,
    0,    0,    0,  691,  691,  691,  691,  691,  691,  691,
    0,    0,    0,    0,    0,    0,  691,    0,    0,    0,
    0,    0,    0,  691,    0,  691,  691,  691,  691,  691,
  691,  691,  691,  691,  691,  691,  691,  691,  691,  691,
  691,  691,  691,    0,    0,  691,  691,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  691,    0,  691,    0,    0,  691,  691,  691,
  691,  691,  691,  691,  691,  691,  691,  691,  691,    0,
  693,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  693,  691,  691,  691,  691,
  691,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  691,  691,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  691,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  691,    0,  691,  691,    0,    0,  691,  691,
  691,    0,    0,    0,    0,    0,    0,  691,  691,  691,
  691,  693,    0,  691,    0,    0,  691,    0,    0,    0,
    0,    0,    0,  691,  691,  691,  691,  691,  691,  691,
  691,  691,  691,  691,  691,  691,    0,    0,    0,    0,
    0,    0,  691,  691,    0,    0,    0,    0,    0,    0,
  691,  691,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  691,  691,  691,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  691,
  691,  691,  691,  691,  691,  691,  691,  691,  691,  691,
  691,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  691,  691,    0,
    0,  691,  691,    0,  691,  691,  691,  691,    0,    0,
    0,    0,  693,    0,    0,    0,    0,    0,    0,    0,
    0,  691,  691,  691,  691,  691,    0,    0,    0,    0,
  693,  693,    0,    0,    0,    0,    0,    0,  693,  693,
  693,  693,  693,  693,  693,  693,  693,  693,    0,    0,
    0,    0,    0,  693,  693,  693,    0,    0,    0,    0,
    0,    0,    0,    0,  693,  693,  693,    0,  693,  693,
  693,  693,  693,  693,  693,  693,    0,  693,  693,    0,
    0,  693,    0,    0,    0,  693,  693,    0,    0,  693,
  693,    0,    0,    0,    0,    0,    0,    0,    0,  693,
    0,    0,    0,    0,    0,    0,    0,  693,    0,    0,
    0,  693,  693,  693,  693,  693,    0,    0,    0,    0,
    0,  693,  693,    0,    0,    0,    0,  693,  693,  693,
  693,  693,  693,  693,    0,    0,    0,    0,    0,    0,
  693,    0,    0,    0,    0,    0,    0,  693,    0,  693,
  693,  693,  693,  693,  693,  693,  693,  693,  693,  693,
  693,  693,  693,  693,  693,  693,  693,    0,    0,  693,
  693,    0,    0,    0,    0,  134,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  693,    0,  693,    0,
    0,  693,  693,  693,  693,  693,  693,  693,  693,  693,
  693,  693,  693,    0,  698,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  698,
  693,  693,  693,  693,  693,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  693,  693,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  693,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  693,    0,  693,  693,
    0,    0,  693,  693,  693,    0,    0,    0,    0,    0,
    0,  693,  693,  693,  693,  698,    0,  693,    0,    0,
  693,    0,    0,    0,    0,    0,    0,  693,  693,  693,
  693,  693,  693,  693,  693,  693,  693,  693,  693,  693,
    0,    0,    0,    0,    0,    0,  693,  693,    0,    0,
    0,    0,    0,    0,  693,  693,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  693,  693,  693,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  693,  693,  693,  693,  693,  693,  693,
  693,  693,  693,  693,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  693,  693,    0,    0,  693,  693,    0,  693,  693,
  693,  693,    0,    0,    0,    0,  698,    0,    0,    0,
    0,    0,    0,    0,    0,  693,  693,  693,  693,  693,
    0,    0,    0,    0,  698,  698,    0,    0,    0,    0,
    0,    0,  698,  698,  698,  698,  698,  698,  698,  698,
  698,  698,    0,    0,    0,    0,    0,  698,  698,  698,
    0,    0,    0,    0,    0,    0,    0,    0,  698,  698,
  698,    0,  698,  698,  698,  698,  698,  698,  698,  698,
    0,  698,  698,    0,    0,  698,    0,    0,    0,  698,
  698,    0,    0,  698,  698,    0,    0,    0,    0,    0,
    0,    0,    0,  698,    0,    0,    0,    0,    0,    0,
    0,  698,    0,    0,    0,  698,  698,  698,  698,  698,
    0,    0,    0,    0,    0,  698,  698,    0,    0,    0,
    0,  698,  698,  698,  698,  698,  698,  698,    0,    0,
    0,    0,    0,    0,  698,    0,    0,    0,    0,    0,
    0,  698,    0,  698,  698,  698,  698,  698,  698,  698,
  698,  698,  698,  698,  698,  698,  698,  698,  698,  698,
  698,    0,    0,  698,  698,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  698,    0,  698,    0,    0,  698,  698,  698,  698,  698,
  698,  698,  698,  698,  698,  698,  698,    0,  701,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  701,  698,  698,  698,  698,  698,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  698,  698,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  698,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  698,    0,  698,  698,    0,    0,  698,  698,  698,    0,
    0,    0,    0,    0,    0,  698,  698,  698,  698,  701,
    0,  698,    0,    0,  698,    0,    0,    0,    0,    0,
    0,  698,  698,  698,  698,  698,  698,  698,  698,  698,
  698,  698,  698,  698,    0,    0,    0,    0,    0,    0,
  698,  698,    0,    0,    0,    0,    0,    0,  698,  698,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  698,  698,  698,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,    0,    0,    0,    0,
    0,  134,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  698,  698,    0,    0,  698,
  698,    0,  698,  698,  698,  698,    0,    0,    0,    0,
  701,    0,    0,    0,    0,    0,    0,    0,    0,  698,
  698,  698,  698,  698,    0,    0,    0,    0,  701,  701,
    0,    0,    0,    0,    0,    0,  701,  701,  701,  701,
  701,  701,  701,  701,  701,  701,    0,    0,    0,    0,
    0,  701,  701,  701,    0,    0,    0,    0,    0,    0,
    0,    0,  701,  701,  701,    0,  701,  701,  701,  701,
  701,  701,  701,  701,    0,  701,  701,    0,    0,  701,
    0,    0,    0,  701,  701,    0,    0,  701,  701,    0,
    0,    0,    0,    0,    0,    0,    0,  701,    0,    0,
    0,    0,    0,    0,    0,  701,    0,    0,    0,  701,
  701,  701,  701,  701,    0,    0,    0,    0,    0,  701,
  701,    0,    0,    0,    0,  701,  701,  701,  701,  701,
  701,  701,    0,    0,    0,    0,    0,    0,  701,    0,
    0,    0,    0,    0,    0,  701,    0,  701,  701,  701,
  701,  701,  701,  701,  701,  701,  701,  701,  701,  701,
  701,  701,  701,  701,  701,    0,    0,  701,  701,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  701,    0,  701,    0,    0,  701,
  701,  701,  701,  701,  701,  701,  701,  701,  701,  701,
  701,    0,  713,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  713,  701,  701,
  701,  701,  701,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  701,  701,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  701,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  701,    0,  701,  701,    0,    0,
  701,  701,  701,    0,    0,    0,    0,    0,    0,  701,
  701,  701,  701,  713,    0,  701,    0,    0,  701,    0,
    0,    0,    0,    0,    0,  701,  701,  701,  701,  701,
  701,  701,  701,  701,  701,  701,  701,  701,    0,    0,
    0,    0,    0,    0,  701,  701,    0,    0,    0,    0,
    0,    0,  701,  701,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  701,
  701,  701,   23,   30,   30,   30,   30,   30,   30,   30,
   30,   30,   30,   30,   30,   30,   30,   30,   30,   30,
   30,   30,   30,   30,   30,   30,   30,   30,   30,   30,
   30,    0,    0,   23,   23,    0,  182,   23,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  701,
  701,    0,    0,  701,  701,    0,  701,  701,  701,  701,
    0,    0,    0,    0,  713,    0,    0,    0,    0,    0,
    0,    0,    0,  701,  701,  701,  701,  701,    0,    0,
    0,    0,  713,  713,    0,    0,    0,    0,    0,    0,
  713,  713,  713,  713,  713,  713,  713,  713,  713,  713,
    0,    0,    0,    0,    0,  713,  713,  713,    0,    0,
    0,    0,    0,    0,    0,    0,  713,  713,  713,    0,
  713,  713,  713,  713,  713,  713,  713,  713,    0,  713,
  713,    0,    0,  713,    0,    0,    0,  713,  713,    0,
    0,  713,  713,    0,    0,    0,    0,    0,    0,    0,
    0,  713,    0,    0,    0,    0,    0,    0,    0,  713,
    0,    0,    0,  713,  713,  713,  713,  713,    0,    0,
    0,    0,    0,  713,  713,    0,    0,    0,    0,  713,
  713,  713,  713,  713,  713,  713,    0,    0,    0,    0,
    0,    0,  713,    0,    0,    0,    0,    0,    0,  713,
    0,  713,  713,  713,  713,  713,  713,  713,  713,  713,
  713,  713,  713,  713,  713,  713,  713,  713,  713,    0,
    0,  713,  713,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  713,    0,
  713,    0,    0,  713,  713,  713,  713,  713,  713,  713,
  713,  713,  713,  713,  713,    0,  707,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  707,  713,  713,  713,  713,  713,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  713,  713,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  713,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  713,    0,
  713,  713,    0,    0,  713,  713,  713,    0,    0,    0,
    0,    0,    0,  713,  713,  713,  713,  707,    0,  713,
    0,    0,  713,    0,    0,    0,    0,    0,    0,  713,
  713,  713,  713,  713,  713,  713,  713,  713,  713,  713,
  713,  713,    0,    0,    0,    0,    0,    0,  713,  713,
    0,    0,    0,    0,    0,    0,  713,  713,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  713,  713,  713,  281,  229,  229,  229,
  229,  229,  229,  229,  229,  229,  229,  229,  229,  229,
  229,  229,  229,  229,  229,  229,  229,  229,  229,  229,
  229,  229,  229,  229,  229,    0,    0,  281,  281,    0,
  189,  281,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  713,  713,    0,    0,  713,  713,    0,
  713,  713,  713,  713,    0,    0,    0,    0,  707,    0,
    0,    0,    0,    0,    0,    0,    0,  713,  713,  713,
  713,  713,    0,    0,    0,    0,  707,  707,    0,    0,
    0,    0,    0,    0,  707,  707,  707,  707,  707,  707,
  707,  707,  707,  707,    0,    0,    0,    0,    0,  707,
  707,  707,    0,    0,    0,    0,    0,    0,    0,    0,
  707,  707,  707,    0,  707,  707,  707,  707,  707,  707,
  707,  707,    0,  707,  707,    0,    0,  707,    0,    0,
    0,  707,  707,    0,    0,  707,  707,    0,    0,    0,
    0,    0,    0,    0,    0,  707,    0,    0,    0,    0,
    0,    0,    0,  707,    0,    0,    0,  707,  707,  707,
  707,  707,    0,    0,    0,    0,    0,  707,  707,    0,
    0,    0,    0,  707,  707,  707,  707,  707,  707,  707,
    0,    0,    0,    0,    0,    0,  707,    0,    0,    0,
    0,    0,    0,  707,    0,  707,  707,  707,  707,  707,
  707,  707,  707,  707,  707,  707,  707,  707,  707,  707,
  707,  707,  707,    0,    0,  707,  707,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  707,    0,  707,    0,    0,  707,  707,  707,
  707,  707,  707,  707,  707,  707,  707,  707,  707,    0,
  703,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  703,  707,  707,  707,  707,
  707,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  707,  707,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  707,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  707,    0,  707,  707,    0,    0,  707,  707,
  707,    0,    0,    0,    0,    0,    0,  707,  707,  707,
  707,  703,    0,  707,    0,    0,  707,    0,    0,    0,
    0,    0,    0,  707,  707,  707,  707,  707,  707,  707,
  707,  707,  707,  707,  707,  707,    0,    0,    0,    0,
    0,    0,  707,  707,    0,    0,    0,    0,    0,    0,
  707,  707,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  707,  707,  707,
  278,  221,  221,  221,  221,  221,  221,  221,  221,  221,
  221,  221,  221,  221,  221,  221,  221,  221,  221,  221,
  221,  221,  221,  221,  221,  221,  221,  221,  221,    0,
    0,  278,  278,    0,  184,  278,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  707,  707,    0,
    0,  707,  707,    0,  707,  707,  707,  707,    0,    0,
    0,    0,  703,    0,    0,    0,    0,    0,    0,    0,
    0,  707,  707,  707,  707,  707,    0,    0,    0,    0,
  703,  703,    0,    0,    0,    0,    0,    0,  703,  703,
  703,  703,  703,  703,  703,  703,  703,  703,    0,    0,
    0,    0,    0,  703,  703,  703,    0,    0,    0,    0,
    0,    0,    0,    0,  703,  703,  703,    0,  703,  703,
  703,  703,  703,  703,  703,  703,    0,  703,  703,    0,
    0,  703,    0,    0,    0,  703,  703,    0,    0,  703,
  703,    0,    0,    0,    0,    0,    0,    0,    0,  703,
    0,    0,    0,    0,    0,    0,    0,  703,    0,    0,
    0,  703,  703,  703,  703,  703,    0,    0,    0,    0,
    0,  703,  703,    0,    0,    0,    0,  703,  703,  703,
  703,  703,  703,  703,    0,    0,    0,    0,    0,    0,
  703,    0,    0,    0,    0,    0,    0,  703,    0,  703,
  703,  703,  703,  703,  703,  703,  703,  703,  703,  703,
  703,  703,  703,  703,  703,  703,  703,    0,    0,  703,
  703,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  703,    0,  703,    0,
    0,  703,  703,  703,  703,  703,  703,  703,  703,  703,
  703,  703,  703,    0,  705,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  705,
  703,  703,  703,  703,  703,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  703,  703,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  703,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  703,    0,  703,  703,
    0,    0,  703,  703,  703,    0,    0,    0,    0,    0,
    0,  703,  703,  703,  703,  705,    0,  703,    0,    0,
  703,    0,    0,    0,    0,    0,    0,  703,  703,  703,
  703,  703,  703,  703,  703,  703,  703,  703,  703,  703,
    0,    0,    0,    0,    0,    0,  703,  703,    0,    0,
    0,    0,    0,    0,  703,  703,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  703,  703,  703,  279,  239,  239,  239,  239,  239,
  239,  239,  239,  239,  239,  239,  239,  239,  239,  239,
  239,  239,  239,  239,  239,  239,  239,  239,  239,  239,
  239,  239,  239,    0,    0,  279,  279,    0,  185,  279,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  703,  703,    0,    0,  703,  703,    0,  703,  703,
  703,  703,    0,    0,    0,    0,  705,    0,    0,    0,
    0,    0,    0,    0,    0,  703,  703,  703,  703,  703,
    0,    0,    0,    0,  705,  705,    0,    0,    0,    0,
    0,    0,  705,  705,  705,  705,  705,  705,  705,  705,
  705,  705,    0,    0,    0,    0,    0,  705,  705,  705,
    0,    0,    0,    0,    0,    0,    0,    0,  705,  705,
  705,    0,  705,  705,  705,  705,  705,  705,  705,  705,
    0,  705,  705,    0,    0,  705,    0,    0,    0,  705,
  705,    0,    0,  705,  705,    0,    0,    0,    0,    0,
    0,    0,    0,  705,    0,    0,    0,    0,    0,    0,
    0,  705,    0,    0,    0,  705,  705,  705,  705,  705,
    0,    0,    0,    0,    0,  705,  705,    0,    0,    0,
    0,  705,  705,  705,  705,  705,  705,  705,    0,    0,
    0,    0,    0,    0,  705,    0,    0,    0,    0,    0,
    0,  705,    0,  705,  705,  705,  705,  705,  705,  705,
  705,  705,  705,  705,  705,  705,  705,  705,  705,  705,
  705,    0,    0,  705,  705,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  705,    0,  705,    0,    0,  705,  705,  705,  705,  705,
  705,  705,  705,  705,  705,  705,  705,    0,  709,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  709,  705,  705,  705,  705,  705,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  705,  705,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  705,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  705,    0,  705,  705,    0,    0,  705,  705,  705,    0,
    0,    0,    0,    0,    0,  705,  705,  705,  705,  709,
    0,  705,    0,    0,  705,    0,    0,    0,    0,    0,
    0,  705,  705,  705,  705,  705,  705,  705,  705,  705,
  705,  705,  705,  705,    0,    0,    0,    0,    0,    0,
  705,  705,    0,    0,    0,    0,    0,    0,  705,  705,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  705,  705,  705,  277,  223,
  223,  223,  223,  223,  223,  223,  223,  223,  223,  223,
  223,  223,  223,  223,  223,  223,  223,  223,  223,  223,
  223,  223,  223,  223,  223,  223,  223,    0,    0,  277,
  277,    0,  183,  277,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  705,  705,    0,    0,  705,
  705,    0,  705,  705,  705,  705,    0,    0,    0,    0,
  709,    0,    0,    0,    0,    0,    0,    0,    0,  705,
  705,  705,  705,  705,    0,    0,    0,    0,  709,  709,
    0,    0,    0,    0,    0,    0,  709,  709,  709,  709,
  709,  709,  709,  709,  709,  709,    0,    0,    0,    0,
    0,  709,  709,  709,    0,    0,    0,    0,    0,    0,
    0,    0,  709,  709,  709,    0,  709,  709,  709,  709,
  709,  709,  709,  709,    0,  709,  709,    0,    0,  709,
    0,    0,    0,  709,  709,    0,    0,  709,  709,    0,
    0,    0,    0,    0,    0,    0,    0,  709,    0,    0,
    0,    0,    0,    0,    0,  709,    0,    0,    0,  709,
  709,  709,  709,  709,    0,    0,    0,    0,    0,  709,
  709,    0,    0,    0,    0,  709,  709,  709,  709,  709,
  709,  709,    0,    0,    0,    0,    0,    0,  709,    0,
    0,    0,    0,    0,    0,  709,    0,  709,  709,  709,
  709,  709,  709,  709,  709,  709,  709,  709,  709,  709,
  709,  709,  709,  709,  709,    0,    0,  709,  709,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  709,    0,  709,    0,    0,  709,
  709,  709,  709,  709,  709,  709,  709,  709,  709,  709,
  709,    0,  711,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  711,  709,  709,
  709,  709,  709,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  709,  709,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  709,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  709,    0,  709,  709,    0,    0,
  709,  709,  709,    0,    0,    0,    0,    0,    0,  709,
  709,  709,  709,  711,    0,  709,    0,    0,  709,    0,
    0,    0,    0,    0,    0,  709,  709,  709,  709,  709,
  709,  709,  709,  709,  709,  709,  709,  709,    0,    0,
    0,    0,    0,    0,  709,  709,    0,    0,    0,    0,
    0,    0,  709,  709,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  709,
  709,  709,  280,  695,  695,  695,  695,  695,  695,  695,
  695,  695,  695,  695,  695,  695,  695,  695,  695,  695,
  695,  695,  695,  695,  695,  695,  695,  695,  695,  695,
  695,    0,    0,  280,  280,    0,  186,  280,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  709,
  709,    0,    0,  709,  709,    0,  709,  709,  709,  709,
    0,    0,    0,    0,  711,    0,    0,    0,    0,    0,
    0,    0,    0,  709,  709,  709,  709,  709,    0,    0,
    0,    0,  711,  711,    0,    0,    0,    0,    0,    0,
  711,  711,  711,  711,  711,  711,  711,  711,  711,  711,
    0,    0,    0,    0,    0,  711,  711,  711,    0,    0,
    0,    0,    0,    0,    0,    0,  711,  711,  711,    0,
  711,  711,  711,  711,  711,  711,  711,  711,    0,  711,
  711,    0,    0,  711,    0,    0,    0,  711,  711,    0,
    0,  711,  711,    0,    0,    0,    0,    0,    0,    0,
    0,  711,    0,    0,    0,    0,    0,    0,    0,  711,
    0,    0,    0,  711,  711,  711,  711,  711,    0,    0,
    0,    0,    0,  711,  711,    0,    0,    0,    0,  711,
  711,  711,  711,  711,  711,  711,    0,    0,    0,    0,
    0,    0,  711,    0,    0,    0,    0,    0,    0,  711,
    0,  711,  711,  711,  711,  711,  711,  711,  711,  711,
  711,  711,  711,  711,  711,  711,  711,  711,  711,    0,
    0,  711,  711,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  711,    0,
  711,    0,    0,  711,  711,  711,  711,  711,  711,  711,
  711,  711,  711,  711,  711,    0,  715,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  715,  711,  711,  711,  711,  711,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  711,  711,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  711,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  711,    0,
  711,  711,    0,    0,  711,  711,  711,    0,    0,    0,
    0,    0,    0,  711,  711,  711,  711,  715,    0,  711,
    0,    0,  711,    0,    0,    0,    0,    0,    0,  711,
  711,  711,  711,  711,  711,  711,  711,  711,  711,  711,
  711,  711,    0,    0,    0,    0,    0,    0,  711,  711,
    0,    0,    0,    0,    0,    0,  711,  711,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  711,  711,  711,   13,   13,   13,   13,
   13,   13,   13,   13,   13,   13,   13,   13,   13,   13,
   13,   13,   13,   13,   13,   13,   13,   13,   13,   13,
   13,   13,   13,   13,   13,    0,    0,   13,   13,    0,
    0,   13,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  711,  711,    0,    0,  711,  711,    0,
  711,  711,  711,  711,    0,    0,    0,    0,  715,    0,
    0,    0,    0,    0,    0,    0,    0,  711,  711,  711,
  711,  711,    0,    0,    0,    0,  715,  715,    0,    0,
    0,    0,    0,    0,  715,  715,  715,  715,  715,  715,
  715,  715,  715,  715,    0,    0,    0,    0,    0,  715,
  715,  715,    0,    0,    0,    0,    0,    0,    0,    0,
  715,  715,  715,    0,  715,  715,  715,  715,  715,  715,
  715,  715,    0,  715,  715,    0,    0,  715,    0,    0,
    0,  715,  715,    0,    0,  715,  715,    0,    0,    0,
    0,    0,    0,    0,    0,  715,    0,    0,    0,    0,
    0,    0,    0,  715,    0,    0,    0,  715,  715,  715,
  715,  715,    0,    0,    0,    0,    0,  715,  715,    0,
    0,    0,    0,  715,  715,  715,  715,  715,  715,  715,
    0,    0,    0,    0,    0,    0,  715,    0,    0,    0,
    0,    0,    0,  715,    0,  715,  715,  715,  715,  715,
  715,  715,  715,  715,  715,  715,  715,  715,  715,  715,
  715,  715,  715,    0,    0,  715,  715,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  715,    0,  715,    0,    0,  715,  715,  715,
  715,  715,  715,  715,  715,  715,  715,  715,  715,    0,
  719,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  719,  715,  715,  715,  715,
  715,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  715,  715,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  715,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  715,    0,  715,  715,    0,    0,  715,  715,
  715,    0,    0,    0,    0,    0,    0,  715,  715,  715,
  715,  719,    0,  715,    0,    0,  715,    0,    0,    0,
    0,    0,    0,  715,  715,  715,  715,  715,  715,  715,
  715,  715,  715,  715,  715,  715,    0,    0,    0,    0,
    0,    0,  715,  715,    0,    0,    0,    0,    0,    0,
  715,  715,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  715,  715,  715,
  411,  412,  413,  414,  415,  416,  417,  418,  419,  420,
  421,  422,  423,  424,  425,  426,  427,  428,  429,  430,
  431,  432,  433,  434,  435,  436,  437,  438,    0,    0,
    0,    0,    0,    0,    0,  971,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  715,  715,    0,
    0,  715,  715,    0,  715,  715,  715,  715,    0,    0,
    0,    0,  719,    0,    0,    0,    0,    0,    0,    0,
    0,  715,  715,  715,  715,  715,    0,    0,    0,    0,
  719,  719,    0,    0,    0,    0,    0,    0,  719,  719,
  719,  719,  719,  719,  719,  719,  719,  719,    0,    0,
    0,    0,    0,  719,  719,  719,    0,    0,    0,    0,
    0,    0,    0,    0,  719,  719,  719,    0,  719,  719,
  719,  719,  719,  719,  719,  719,    0,  719,  719,    0,
    0,  719,    0,    0,    0,  719,  719,    0,    0,  719,
  719,    0,    0,    0,    0,    0,    0,    0,    0,  719,
    0,    0,    0,    0,    0,    0,    0,  719,    0,    0,
    0,  719,  719,  719,  719,  719,    0,    0,    0,    0,
    0,  719,  719,    0,    0,    0,    0,  719,  719,  719,
  719,  719,  719,  719,    0,    0,    0,    0,    0,    0,
  719,    0,    0,    0,    0,    0,    0,  719,    0,  719,
  719,  719,  719,  719,  719,  719,  719,  719,  719,  719,
  719,  719,  719,  719,  719,  719,  719,    0,    0,  719,
  719,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  719,    0,  719,    0,
    0,  719,  719,  719,  719,  719,  719,  719,  719,  719,
  719,  719,  719,    0,  717,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  717,
  719,  719,  719,  719,  719,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  719,  719,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  719,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  719,    0,  719,  719,
    0,    0,  719,  719,  719,    0,    0,    0,    0,    0,
    0,  719,  719,  719,  719,  717,    0,  719,    0,    0,
  719,    0,    0,    0,    0,    0,    0,  719,  719,  719,
  719,  719,  719,  719,  719,  719,  719,  719,  719,  719,
    0,    0,    0,    0,    0,    0,  719,  719,    0,    0,
    0,    0,    0,    0,  719,  719,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  719,  719,  719,  411,  412,  413,  414,  415,  416,
  417,  418,  419,  420,  421,  422,  423,  424,  425,  426,
  427,  428,  429,  430,  431,  432,  433,  434,  435,  436,
  437,  438,    0,    0,    0,    0,    0,  634,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  719,  719,    0,    0,  719,  719,    0,  719,  719,
  719,  719,    0,    0,    0,    0,  717,    0,    0,    0,
    0,    0,    0,    0,    0,  719,  719,  719,  719,  719,
    0,    0,    0,    0,  717,  717,    0,    0,    0,    0,
    0,    0,  717,  717,  717,  717,  717,  717,  717,  717,
  717,  717,    0,    0,    0,    0,    0,  717,  717,  717,
    0,    0,    0,    0,    0,    0,    0,    0,  717,  717,
  717,    0,  717,  717,  717,  717,  717,  717,  717,  717,
    0,  717,  717,    0,    0,  717,    0,    0,    0,  717,
  717,    0,    0,  717,  717,    0,    0,    0,    0,    0,
    0,    0,    0,  717,    0,    0,    0,    0,    0,    0,
    0,  717,    0,    0,    0,  717,  717,  717,  717,  717,
    0,    0,    0,    0,    0,  717,  717,    0,    0,    0,
    0,  717,  717,  717,  717,  717,  717,  717,    0,    0,
    0,    0,    0,    0,  717,    0,    0,    0,    0,    0,
    0,  717,    0,  717,  717,  717,  717,  717,  717,  717,
  717,  717,  717,  717,  717,  717,  717,  717,  717,  717,
  717,    0,    0,  717,  717,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  717,    0,  717,    0,    0,  717,  717,  717,  717,  717,
  717,  717,  717,  717,  717,  717,  717,    0,  699,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  699,  717,  717,  717,  717,  717,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  717,  717,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  717,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  717,    0,  717,  717,    0,    0,  717,  717,  717,    0,
    0,    0,    0,    0,    0,  717,  717,  717,  717,  699,
    0,  717,    0,    0,  717,    0,    0,    0,    0,    0,
    0,  717,  717,  717,  717,  717,  717,  717,  717,  717,
  717,  717,  717,  717,    0,    0,    0,    0,    0,    0,
  717,  717,    0,    0,    0,    0,    0,    0,  717,  717,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  717,  717,  717,  411,  412,
  413,  414,  415,  416,  417,  418,  419,  420,  421,  422,
  423,  424,  425,  426,  427,  428,  429,  430,  431,  432,
  433,  434,  435,  436,  437,  438,    0,    0,    0,    0,
    0,  983,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  717,  717,    0,    0,  717,
  717,    0,  717,  717,  717,  717,    0,    0,    0,    0,
  699,    0,    0,    0,    0,    0,    0,    0,    0,  717,
  717,  717,  717,  717,    0,    0,    0,    0,  699,  699,
    0,    0,    0,    0,    0,    0,  699,  699,  699,  699,
  699,  699,  699,  699,  699,  699,    0,    0,    0,    0,
    0,  699,  699,  699,    0,    0,    0,    0,    0,    0,
    0,    0,  699,  699,  699,    0,  699,  699,  699,  699,
  699,  699,  699,  699,    0,  699,  699,    0,    0,  699,
    0,    0,    0,  699,  699,    0,    0,  699,  699,    0,
    0,    0,    0,    0,    0,    0,    0,  699,    0,    0,
    0,    0,    0,    0,    0,  699,    0,    0,    0,  699,
  699,  699,  699,  699,    0,    0,    0,    0,    0,  699,
  699,    0,    0,    0,    0,  699,  699,  699,  699,  699,
  699,  699,    0,    0,    0,    0,    0,    0,  699,    0,
    0,    0,    0,    0,    0,  699,    0,  699,  699,  699,
  699,  699,  699,  699,  699,  699,  699,  699,  699,  699,
  699,  699,  699,  699,  699,    0,    0,  699,  699,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  699,    0,  699,    0,    0,  699,
  699,  699,  699,  699,  699,  699,  699,  699,  699,  699,
  699,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   20,  699,  699,
  699,  699,  699,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  699,  699,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  699,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  699,    0,  699,  699,    0,    0,
  699,  699,  699,    0,    0,    0,    0,    0,    0,  699,
  699,  699,  699,   20,    0,  699,    0,    0,  699,    0,
    0,    0,    0,    0,    0,  699,  699,  699,  699,  699,
  699,  699,  699,  699,  699,  699,  699,  699,    0,    0,
    0,    0,    0,    0,  699,  699,    0,    0,    0,    0,
    0,    0,  699,  699,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  699,
  699,  699,  411,  412,  413,  414,  415,  416,  417,  418,
  419,  420,  421,  422,  423,  424,  425,  426,  427,  428,
  429,  430,  431,  432,  433,  434,  435,  436,  437,  438,
    0,    0,    0,    0,    0, 1031,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  699,
  699,    0,    0,  699,  699,    0,  699,  699,  699,  699,
    0,    0,    0,    0,   20,    0,    0,    0,    0,    0,
    0,    0,    0,  699,  699,  699,  699,  699,    0,    0,
    0,    0,   20,   20,    0,    0,    0,    0,    0,    0,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
    0,    0,    0,    0,    0,   20,   20,   20,    0,    0,
    0,    0,    0,    0,    0,    0,   20,   20,   20,    0,
   20,   20,   20,   20,   20,   20,   20,   20,    0,   20,
   20,    0,    0,   20,    0,    0,    0,   20,   20,    0,
    0,   20,   20,    0,    0,    0,    0,    0,    0,    0,
    0,   20,    0,    0,    0,    0,    0,    0,    0,   20,
    0,    0,    0,   20,   20,   20,   20,   20,    0,    0,
    0,    0,    0,   20,   20,    0,    0,    0,    0,   20,
   20,   20,   20,   20,   20,   20,    0,    0,    0,    0,
    0,    0,   20,    0,    0,    0,    0,    0,    0,   20,
    0,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   20,   20,   20,   20,    0,
    0,   20,   20,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   20,    0,
   20,    0,    0,   20,   20,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   21,   20,   20,   20,   20,   20,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   20,   20,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   20,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   20,    0,
   20,   20,    0,    0,   20,   20,   20,    0,    0,    0,
    0,    0,    0,   20,   20,   20,   20,   21,    0,   20,
    0,    0,   20,    0,    0,    0,    0,    0,    0,   20,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   20,   20,    0,    0,    0,    0,    0,    0,   20,   20,
    0,    0,    0,    0,    0,    0,   20,   20,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   20,   20,   20,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  107,  107,  107,  107,  107,
  107,  107,  107,  107,  107,  107,  107,  107,  107,  107,
  107,  107,  107,  107,  107,  107,  107,  107,  107,  107,
  107,  107,  107,   20,   20,    0,    0,   20,    0,    0,
    0,   20,   20,   20,    0,    0,    0,    0,   21,    0,
    0,    0,    0,    0,    0,    0,    0,   20,   20,   20,
   20,   20,    0,    0,    0,    0,   21,   21,    0,    0,
    0,    0,    0,    0,   21,   21,   21,   21,   21,   21,
   21,   21,   21,   21,    0,    0,    0,    0,    0,   21,
   21,   21,    0,    0,    0,    0,    0,    0,    0,    0,
   21,   21,   21,    0,   21,   21,   21,   21,   21,   21,
   21,   21,    0,   21,   21,    0,    0,   21,    0,    0,
    0,   21,   21,    0,    0,   21,   21,    0,    0,    0,
    0,    0,    0,    0,    0,   21,    0,    0,    0,    0,
    0,    0,    0,   21,    0,    0,    0,   21,   21,   21,
   21,   21,    0,    0,    0,    0,    0,   21,   21,    0,
    0,    0,    0,   21,   21,   21,   21,   21,   21,   21,
    0,    0,    0,    0,    0,    0,   21,    0,    0,    0,
    0,    0,    0,   21,    0,   21,   21,   21,   21,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,    0,    0,   21,   21,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   21,    0,   21,    0,    0,   21,   21,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   21,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   18,   21,   21,   21,   21,
   21,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   21,   21,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   21,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   21,    0,   21,   21,    0,    0,   21,   21,
   21,    0,    0,    0,    0,    0,    0,   21,   21,   21,
   21,   18,    0,   21,    0,    0,   21,    0,    0,    0,
    0,    0,    0,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,   21,   21,   21,    0,    0,    0,    0,
    0,    0,   21,   21,    0,    0,    0,    0,    0,    0,
   21,   21,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   21,   21,   21,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  106,
  106,  106,  106,  106,  106,  106,  106,  106,  106,  106,
  106,  106,  106,  106,  106,  106,  106,  106,  106,  106,
  106,  106,  106,  106,  106,  106,  106,   21,   21,    0,
    0,   21,    0,    0,    0,   21,   21,   21,    0,    0,
    0,    0,   18,    0,    0,    0,    0,    0,    0,    0,
    0,   21,   21,   21,   21,   21,    0,    0,    0,    0,
   18,   18,    0,    0,    0,    0,    0,    0,   18,   18,
   18,   18,   18,   18,   18,   18,   18,   18,    0,    0,
    0,    0,    0,   18,   18,   18,    0,    0,    0,    0,
    0,    0,    0,    0,   18,   18,   18,    0,   18,   18,
   18,   18,   18,   18,   18,   18,    0,   18,   18,    0,
    0,   18,    0,    0,    0,   18,   18,    0,    0,   18,
   18,    0,    0,    0,    0,    0,    0,    0,    0,   18,
    0,    0,    0,    0,    0,    0,    0,   18,    0,    0,
    0,   18,   18,   18,   18,   18,    0,    0,    0,    0,
    0,   18,   18,    0,    0,    0,    0,   18,   18,   18,
   18,   18,   18,   18,    0,    0,    0,    0,    0,    0,
   18,    0,    0,    0,    0,    0,    0,   18,    0,   18,
   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,
   18,   18,   18,   18,   18,   18,   18,    0,    0,   18,
   18,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   18,    0,   18,    0,
    0,   18,   18,   18,   18,   18,   18,   18,   18,   18,
   18,   18,   18,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   17,
   18,   18,   18,   18,   18,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   18,   18,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   18,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   18,    0,   18,   18,
    0,    0,   18,   18,   18,    0,    0,    0,    0,    0,
    0,   18,   18,   18,   18,   17,    0,   18,    0,    0,
   18,    0,    0,    0,    0,    0,    0,   18,   18,   18,
   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,
    0,    0,    0,    0,    0,    0,   18,   18,    0,    0,
    0,    0,    0,    0,   18,   18,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   18,   18,   18,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  110,  110,  110,  110,  110,  110,  110,
  110,  110,  110,  110,  110,  110,  110,  110,  110,  110,
  110,  110,  110,  110,  110,  110,  110,  110,  110,  110,
  110,   18,   18,    0,    0,   18,    0,    0,    0,   18,
   18,   18,    0,    0,    0,    0,   17,    0,    0,    0,
    0,    0,    0,    0,    0,   18,   18,   18,   18,   18,
    0,    0,    0,    0,   17,   17,    0,    0,    0,    0,
    0,    0,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,    0,    0,    0,    0,    0,   17,   17,   17,
    0,    0,    0,    0,    0,    0,    0,    0,   17,   17,
   17,    0,   17,   17,   17,   17,   17,   17,   17,   17,
    0,   17,   17,    0,    0,   17,    0,    0,    0,   17,
   17,    0,    0,   17,   17,    0,    0,    0,    0,    0,
    0,    0,    0,   17,    0,    0,    0,    0,    0,    0,
    0,   17,    0,    0,    0,   17,   17,   17,   17,   17,
    0,    0,    0,    0,    0,   17,   17,    0,    0,    0,
    0,   17,   17,   17,   17,   17,   17,   17,    0,    0,
    0,    0,    0,    0,   17,    0,    0,    0,    0,    0,
    0,   17,    0,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,    0,    0,   17,   17,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   17,    0,   17,    0,    0,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   19,   17,   17,   17,   17,   17,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   17,   17,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   17,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   17,    0,   17,   17,    0,    0,   17,   17,   17,    0,
    0,    0,    0,    0,    0,   17,   17,   17,   17,   19,
    0,   17,    0,    0,   17,    0,    0,    0,    0,    0,
    0,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,    0,    0,    0,    0,    0,    0,
   17,   17,    0,    0,    0,    0,    0,    0,   17,   17,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   17,   17,   17,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   31,   31,   31,
   31,   31,   31,   31,   31,   31,   31,   31,   31,   31,
   31,   31,   31,   31,   31,   31,   31,   31,   31,   31,
   31,   31,   31,   31,   31,   17,   17,    0,    0,   17,
    0,    0,    0,   17,   17,   17,    0,    0,    0,    0,
   19,    0,    0,    0,    0,    0,    0,    0,    0,   17,
   17,   17,   17,   17,    0,    0,    0,    0,   19,   19,
    0,    0,    0,    0,    0,    0,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,    0,    0,    0,    0,
    0,   19,   19,   19,    0,    0,    0,    0,    0,    0,
    0,    0,   19,   19,   19,    0,   19,   19,   19,   19,
   19,   19,   19,   19,    0,   19,   19,    0,    0,   19,
    0,    0,    0,   19,   19,    0,    0,   19,   19,    0,
    0,    0,    0,    0,    0,    0,    0,   19,    0,    0,
    0,    0,    0,    0,    0,   19,    0,    0,    0,   19,
   19,   19,   19,   19,    0,    0,    0,    0,    0,   19,
   19,    0,    0,    0,    0,   19,   19,   19,   19,   19,
   19,   19,    0,    0,    0,    0,    0,    0,   19,    0,
    0,    0,    0,    0,    0,   19,    0,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,    0,    0,   19,   19,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   19,    0,   19,    0,    0,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  164,   19,   19,
   19,   19,   19,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   19,   19,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   19,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   19,    0,   19,   19,    0,    0,
   19,   19,   19,    0,    0,    0,    0,    0,    0,   19,
   19,   19,   19,  163,    0,   19,    0,    0,   19,    0,
    0,    0,    0,    0,    0,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,    0,    0,
    0,    0,    0,    0,   19,   19,    0,    0,    0,    0,
    0,    0,   19,   19,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   19,
   19,   19,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  114,  114,  114,  114,  114,  114,  114,  114,  114,
  114,  114,  114,  114,  114,  114,  114,  114,  114,  114,
  114,  114,  114,  114,  114,  114,  114,  114,  114,   19,
   19,    0,    0,   19,    0,    0,    0,   19,   19,   19,
    0,    0,    0,    0,   28,    0,    0,    0,    0,    0,
    0,    0,    0,   19,   19,   19,   19,   19,    0,    0,
    0,    0,   29,   30,    0,    0,    0,    0,    0,    0,
   31,   32,   33,   34,   35,   36,   37,   38,   39,   40,
    0,    0,    0,    0,    0,   41,   42,   43,    0,    0,
    0,    0,    0,    0,    0,    0,   44,   45,   46,    0,
   47,   48,   49,   50,   51,   52,   53,   54,    0,   55,
   56,    0,    0,   57,    0,    0,    0,   58,   59,    0,
    0,   60,   61,    0,    0,    0,    0,    0,    0,    0,
    0,   62,    0,    0,    0,    0,    0,    0,    0,   63,
    0,    0,    0,   64,   65,   66,   67,   68,    0,    0,
    0,    0,    0,   69,   70,    0,  164,    0,    0,   71,
   72,   73,   74,   75,   76,   14,    0,    0,    0,    0,
    0,    0,   77,    0,    0,    0,    0,    0,    0,   78,
    0,   79,   80,   81,   82,   83,   84,   85,   86,   87,
   88,   89,   90,   91,   92,   93,   94,   95,   96,    0,
    0,   97,   98,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   99,    0,
  100,    0, 1446,  101,  102,  103,  104,  105,  106,  107,
  108,  109,  110,  111,  112,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  113,  114,  115,  116,  117,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  118,  119,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  120,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  121,    0,
  122,  123,    0,    0,  124,  125,  126,    0,    0,    0,
    0,    0,    0,  127,  128,  129,  130,    0,    0,  131,
    0,    0,  132,    0,    0,    0,    0,    0,    0,  133,
    9,  134,  135,  136,  137,  138,  139,  140,  141,  142,
  143,  144,    0,    0,    0,    0,    0,    0,  145,  146,
    0,    0,    0,   28,    0,    0,  147,  148,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   29,   30,  149,  150,  151,    0,    0,    0,   31,
   32,   33,   34,   35,   36,   37,   38,   39,   40,    0,
    0,    0,    0,    0,   41,   42,   43,    0,    0,    0,
    0,    0,    0,    0,    0,   44,   45,   46,    0,   47,
   48,   49,   50,   51,   52,   53,   54,    0,   55,   56,
    0,    0,   57,    0,    0,    0,   58,   59,    0,    0,
   60,   61,    0,  152,  153,    0,    0,  154,    0,    0,
   62,  155,  156,  157,    0,    0,    0,    0,   63,    0,
    0,    0,   64,   65,   66,   67,   68,  158,  159,  160,
  161,  162,   69,   70,    0,  164,    0,    0,   71,   72,
   73,   74,   75,   76,   14,    0,    0,    0,    0,    0,
    0,   77,    0,    0,    0,    0,    0,    0,   78,    0,
   79,   80,   81,   82,   83,   84,   85,   86,   87,   88,
   89,   90,   91,   92,   93,   94,   95,   96,    0,    0,
   97,   98,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   99,    0,  100,
    0, 1457,  101,  102,  103,  104,  105,  106,  107,  108,
  109,  110,  111,  112,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  113,  114,  115,  116,  117,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  118,  119,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  120,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  121,    0,  122,
  123,    0,    0,  124,  125,  126,    0,    0,    0,    0,
    0,    0,  127,  128,  129,  130,    0,    0,  131,    0,
    0,  132,    0,    0,    0,    0,    0,    0,  133,    9,
  134,  135,  136,  137,  138,  139,  140,  141,  142,  143,
  144,    0,    0,    0,    0,    0,    0,  145,  146,    0,
    0,    0,   28,    0,    0,  147,  148,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   29,   30,  149,  150,  151,    0,    0,    0,   31,   32,
   33,   34,   35,   36,   37,   38,   39,   40,    0,    0,
    0,    0,    0,   41,   42,   43,    0,    0,    0,    0,
    0,    0,    0,    0,   44,   45,   46,    0,   47,   48,
   49,   50,   51,   52,   53,   54,    0,   55,   56,    0,
    0,   57,    0,    0,    0,   58,   59,    0,    0,   60,
   61,    0,  152,  153,    0,    0,  154,    0,    0,   62,
  155,  156,  157,    0,    0,    0,    0,   63,    0,    0,
    0,   64,   65,   66,   67,   68,  158,  159,  160,  161,
  162,   69,   70,    0,  164,    0,    0,   71,   72,   73,
   74,   75,   76,   14,    0,    0,    0,    0,    0,    0,
   77,    0,    0,    0,    0,    0,    0,   78,    0,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,
   90,   91,   92,   93,   94,   95,   96,    0,    0,   97,
   98,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   99,    0,  100,    0,
 1553,  101,  102,  103,  104,  105,  106,  107,  108,  109,
  110,  111,  112,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  113,  114,  115,  116,  117,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  118,  119,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  120,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  121,    0,  122,  123,
    0,    0,  124,  125,  126,    0,    0,    0,    0,    0,
    0,  127,  128,  129,  130,    0,    0,  131,    0,    0,
  132,    0,    0,    0,    0,    0,    0,  133,    9,  134,
  135,  136,  137,  138,  139,  140,  141,  142,  143,  144,
    0,    0,    0,    0,    0,    0,  145,  146,    0,    0,
    0,   28,    0,    0,  147,  148,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   29,
   30,  149,  150,  151,    0,    0,    0,   31,   32,   33,
   34,   35,   36,   37,   38,   39,   40,    0,    0,    0,
    0,    0,   41,   42,   43,    0,    0,    0,    0,    0,
    0,    0,    0,   44,   45,   46,    0,   47,   48,   49,
   50,   51,   52,   53,   54,    0,   55,   56,    0,    0,
   57,    0,    0,    0,   58,   59,    0,    0,   60,   61,
    0,  152,  153,    0,    0,  154,    0,    0,   62,  155,
  156,  157,    0,    0,    0,    0,   63,    0,    0,    0,
   64,   65,   66,   67,   68,  158,  159,  160,  161,  162,
   69,   70,    0,  164,    0,    0,   71,   72,   73,   74,
   75,   76,   14,    0,    0,    0,    0,    0,    0,   77,
    0,    0,    0,    0,    0,    0,   78,    0,   79,   80,
   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,
   91,   92,   93,   94,   95,   96,    0,    0,   97,   98,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   99,    0,  100,    0, 1559,
  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,
  111,  112,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  113,
  114,  115,  116,  117,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  118,
  119,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  120,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  121,    0,  122,  123,    0,
    0,  124,  125,  126,    0,    0,    0,    0,    0,    0,
  127,  128,  129,  130,    0,    0,  131,    0,    0,  132,
    0,    0,    0,    0,    0,    0,  133,    9,  134,  135,
  136,  137,  138,  139,  140,  141,  142,  143,  144,    0,
    0,    0,    0,    0,    0,  145,  146,    0,    0,    0,
   28,    0,    0,  147,  148,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   29,   30,
  149,  150,  151,    0,    0,    0,   31,   32,   33,   34,
   35,   36,   37,   38,   39,   40,    0,    0,    0,    0,
    0,   41,   42,   43,    0,    0,    0,    0,    0,    0,
    0,    0,   44,   45,   46,    0,   47,   48,   49,   50,
   51,   52,   53,   54,    0,   55,   56,    0,    0,   57,
    0,    0,    0,   58,   59,    0,    0,   60,   61,    0,
  152,  153,    0,    0,  154,    0,    0,   62,  155,  156,
  157,    0,    0,    0,    0,   63,    0,    0,    0,   64,
   65,   66,   67,   68,  158,  159,  160,  161,  162,   69,
   70,    0,  164,    0,    0,   71,   72,   73,   74,   75,
   76,   14,    0,    0,    0,    0,    0,    0,   77,    0,
    0,    0,    0,    0,    0,   78,    0,   79,   80,   81,
   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,
   92,   93,   94,   95,   96,    0,    0,   97,   98,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   99,    0,  100,    0, 1560,  101,
  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
  112,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  113,  114,
  115,  116,  117,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  118,  119,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  120,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  121,    0,  122,  123,    0,    0,
  124,  125,  126,    0,    0,    0,    0,    0,    0,  127,
  128,  129,  130,    0,    0,  131,    0,    0,  132,    0,
    0,    0,    0,    0,    0,  133,    9,  134,  135,  136,
  137,  138,  139,  140,  141,  142,  143,  144,    0,    0,
    0,    0,    0,    0,  145,  146,    0,    0,    0,   28,
    0,    0,  147,  148,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   29,   30,  149,
  150,  151,    0,    0,    0,   31,   32,   33,   34,   35,
   36,   37,   38,   39,   40,    0,    0,    0,    0,    0,
   41,   42,   43,    0,    0,    0,    0,    0,    0,    0,
    0,   44,   45,   46,    0,   47,   48,   49,   50,   51,
   52,   53,   54,    0,   55,   56,    0,    0,   57,    0,
    0,    0,   58,   59,    0,    0,   60,   61,    0,  152,
  153,    0,    0,  154,    0,    0,   62,  155,  156,  157,
    0,    0,    0,    0,   63,    0,    0,    0,   64,   65,
   66,   67,   68,  158,  159,  160,  161,  162,   69,   70,
    0,  164,    0,    0,   71,   72,   73,   74,   75,   76,
   14,    0,    0,    0,    0,    0,    0,   77,    0,    0,
    0,    0,    0,    0,   78,    0,   79,   80,   81,   82,
   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
   93,   94,   95,   96,    0,    0,   97,   98,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   99,    0,  100,    0, 1754,  101,  102,
  103,  104,  105,  106,  107,  108,  109,  110,  111,  112,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  113,  114,  115,
  116,  117,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  118,  119,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  120,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  121,    0,  122,  123,    0,    0,  124,
  125,  126,    0,    0,    0,    0,    0,    0,  127,  128,
  129,  130,    0,    0,  131,    0,    0,  132,    0,    0,
    0,    0,    0,    0,  133,    9,  134,  135,  136,  137,
  138,  139,  140,  141,  142,  143,  144,    0,    0,    0,
    0,    0,    0,  145,  146,    0,    0,    0,   28,    0,
    0,  147,  148,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   29,   30,  149,  150,
  151,    0,    0,    0,   31,   32,   33,   34,   35,   36,
   37,   38,   39,   40,    0,    0,    0,    0,    0,   41,
   42,   43,    0,    0,    0,    0,    0,    0,    0,    0,
   44,   45,   46,    0,   47,   48,   49,   50,   51,   52,
   53,   54,    0,   55,   56,    0,    0,   57,    0,    0,
    0,   58,   59,    0,    0,   60,   61,    0,  152,  153,
    0,    0,  154,    0,    0,   62,  155,  156,  157,    0,
    0,    0,    0,   63,    0,    0,    0,   64,   65,   66,
   67,   68,  158,  159,  160,  161,  162,   69,   70,    0,
  164,    0,    0,   71,   72,   73,   74,   75,   76,   14,
    0,    0,    0,    0,    0,    0,   77,    0,    0,    0,
    0,    0,    0,   78,    0,   79,   80,   81,   82,   83,
   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,
   94,   95,   96,    0,    0,   97,   98,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   99,    0,  100,    0, 1757,  101,  102,  103,
  104,  105,  106,  107,  108,  109,  110,  111,  112,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  113,  114,  115,  116,
  117,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  118,  119,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  120,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  121,    0,  122,  123,    0,    0,  124,  125,
  126,    0,    0,    0,    0,    0,    0,  127,  128,  129,
  130,    0,    0,  131,    0,    0,  132,    0,    0,    0,
    0,    0,    0,  133,    9,  134,  135,  136,  137,  138,
  139,  140,  141,  142,  143,  144,    0,    0,    0,    0,
    0,    0,  145,  146,    0,    0,    0,   28,    0,    0,
  147,  148,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   29,   30,  149,  150,  151,
    0,    0,    0,   31,   32,   33,   34,   35,   36,   37,
   38,   39,   40,    0,    0,    0,    0,    0,   41,   42,
   43,    0,    0,    0,    0,    0,    0,    0,    0,   44,
   45,   46,    0,   47,   48,   49,   50,   51,   52,   53,
   54,    0,   55,   56,    0,    0,   57,    0,    0,    0,
   58,   59,    0,    0,   60,   61,    0,  152,  153,    0,
    0,  154,    0,    0,   62,  155,  156,  157,    0,    0,
    0,    0,   63,    0,    0,    0,   64,   65,   66,   67,
   68,  158,  159,  160,  161,  162,   69,   70,    0,  164,
    0,    0,   71,   72,   73,   74,   75,   76,   14,    0,
    0,    0,    0,    0,    0,   77,    0,    0,    0,    0,
    0,    0,   78,    0,   79,   80,   81,   82,   83,   84,
   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,
   95,   96,    0,    0,   97,   98,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   99,    0,  100,    0, 1839,  101,  102,  103,  104,
  105,  106,  107,  108,  109,  110,  111,  112,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  113,  114,  115,  116,  117,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  118,  119,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  120,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  121,    0,  122,  123,    0,    0,  124,  125,  126,
    0,    0,    0,    0,    0,    0,  127,  128,  129,  130,
    0,    0,  131,    0,    0,  132,    0,    0,    0,    0,
    0,    0,  133,    9,  134,  135,  136,  137,  138,  139,
  140,  141,  142,  143,  144,    0,    0,    0,    0,    0,
    0,  145,  146,    0,    0,    0,   28,    0,    0,  147,
  148,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   29,   30,  149,  150,  151,    0,
    0,    0,   31,   32,   33,   34,   35,   36,   37,   38,
   39,   40,    0,    0,    0,    0,    0,   41,   42,   43,
    0,    0,    0,    0,    0,    0,    0,    0,   44,   45,
   46,    0,   47,   48,   49,   50,   51,   52,   53,   54,
    0,   55,   56,    0,    0,   57,    0,    0,    0,   58,
   59,    0,    0,   60,   61,    0,  152,  153,    0,    0,
  154,    0,    0,   62,  155,  156,  157,    0,    0,    0,
    0,   63,    0,    0,    0,   64,   65,   66,   67,   68,
  158,  159,  160,  161,  162,   69,   70,    0,  164,    0,
    0,   71,   72,   73,   74,   75,   76,   14,    0,    0,
    0,    0,    0,    0,   77,    0,    0,    0,    0,    0,
    0,   78,    0,   79,   80,   81,   82,   83,   84,   85,
   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
   96,    0,    0,   97,   98,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   99,    0,  100,    0, 1847,  101,  102,  103,  104,  105,
  106,  107,  108,  109,  110,  111,  112,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  113,  114,  115,  116,  117,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  118,  119,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  120,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  121,    0,  122,  123,    0,    0,  124,  125,  126,    0,
    0,    0,    0,    0,    0,  127,  128,  129,  130,    0,
    0,  131,    0,    0,  132,    0,    0,    0,    0,    0,
    0,  133,    9,  134,  135,  136,  137,  138,  139,  140,
  141,  142,  143,  144,    0,    0,    0,    0,    0,    0,
  145,  146,    0,    0,    0,   28,    0,    0,  147,  148,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   29,   30,  149,  150,  151,    0,    0,
    0,   31,   32,   33,   34,   35,   36,   37,   38,   39,
   40,    0,    0,    0,    0,    0,   41,   42,   43,    0,
    0,    0,    0,    0,    0,    0,    0,   44,   45,   46,
    0,   47,   48,   49,   50,   51,   52,   53,   54,    0,
   55,   56,    0,    0,   57,    0,    0,    0,   58,   59,
    0,    0,   60,   61,    0,  152,  153,    0,    0,  154,
    0,    0,   62,  155,  156,  157,    0,    0,    0,    0,
   63,    0,    0,    0,   64,   65,   66,   67,   68,  158,
  159,  160,  161,  162,   69,   70,    0,  164,    0,    0,
   71,   72,   73,   74,   75,   76,   14,    0,    0,    0,
    0,    0,    0,   77,    0,    0,    0,    0,    0,    0,
   78,    0,   79,   80,   81,   82,   83,   84,   85,   86,
   87,   88,   89,   90,   91,   92,   93,   94,   95,   96,
    0,    0,   97,   98,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   99,
    0,  100,    0, 1848,  101,  102,  103,  104,  105,  106,
  107,  108,  109,  110,  111,  112,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  113,  114,  115,  116,  117,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  118,  119,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  120,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  121,
    0,  122,  123,    0,    0,  124,  125,  126,    0,    0,
    0,    0,    0,    0,  127,  128,  129,  130,    0,    0,
  131,    0,    0,  132,    0,    0,    0,    0,    0,    0,
  133,    9,  134,  135,  136,  137,  138,  139,  140,  141,
  142,  143,  144,    0,    0,    0,    0,    0,    0,  145,
  146,    0,    0,    0,   28,    0,    0,  147,  148,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   29,   30,  149,  150,  151,    0,    0,    0,
   31,   32,   33,   34,   35,   36,   37,   38,   39,   40,
    0,    0,    0,    0,    0,   41,   42,   43,    0,    0,
    0,    0,    0,    0,    0,    0,   44,   45,   46,    0,
   47,   48,   49,   50,   51,   52,   53,   54,    0,   55,
   56,    0,    0,   57,    0,    0,    0,   58,   59,    0,
    0,   60,   61,    0,  152,  153,    0,    0,  154,    0,
    0,   62,  155,  156,  157,    0,    0,    0,    0,   63,
    0,    0,    0,   64,   65,   66,   67,   68,  158,  159,
  160,  161,  162,   69,   70,    0,  164,    0,    0,   71,
   72,   73,   74,   75,   76,   14,    0,    0,    0,    0,
    0,    0,   77,    0,    0,    0,    0,    0,    0,   78,
    0,   79,   80,   81,   82,   83,   84,   85,   86,   87,
   88,   89,   90,   91,   92,   93,   94,   95,   96,    0,
    0,   97,   98,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   99,    0,
  100,    0, 2045,  101,  102,  103,  104,  105,  106,  107,
  108,  109,  110,  111,  112,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  113,  114,  115,  116,  117,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  118,  119,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  120,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  121,    0,
  122,  123,    0,    0,  124,  125,  126,    0,    0,    0,
    0,    0,    0,  127,  128,  129,  130,    0,    0,  131,
    0,    0,  132,    0,    0,    0,    0,    0,    0,  133,
    9,  134,  135,  136,  137,  138,  139,  140,  141,  142,
  143,  144,    0,    0,    0,    0,    0,    0,  145,  146,
    0,    0,    0,   28,    0,    0,  147,  148,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   29,   30,  149,  150,  151,    0,    0,    0,   31,
   32,   33,   34,   35,   36,   37,   38,   39,   40,    0,
    0,    0,    0,    0,   41,   42,   43,    0,    0,    0,
    0,    0,    0,    0,    0,   44,   45,   46,    0,   47,
   48,   49,   50,   51,   52,   53,   54,    0,   55,   56,
    0,    0,   57,    0,    0,    0,   58,   59,    0,    0,
   60,   61,    0,  152,  153,    0,    0,  154,    0,    0,
   62,  155,  156,  157,    0,    0,    0,    0,   63,    0,
    0,    0,   64,   65,   66,   67,   68,  158,  159,  160,
  161,  162,   69,   70,    0,  164,    0,    0,   71,   72,
   73,   74,   75,   76,   14,    0,    0,    0,    0,    0,
    0,   77,    0,    0,    0,    0,    0,    0,   78,    0,
   79,   80,   81,   82,   83,   84,   85,   86,   87,   88,
   89,   90,   91,   92,   93,   94,   95,   96,    0,    0,
   97,   98,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   99,    0,  100,
    0, 2046,  101,  102,  103,  104,  105,  106,  107,  108,
  109,  110,  111,  112,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  113,  114,  115,  116,  117,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  118,  119,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  120,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  121,    0,  122,
  123,    0,    0,  124,  125,  126,    0,    0,    0,    0,
    0,    0,  127,  128,  129,  130,    0,    0,  131,    0,
    0,  132,    0,    0,    0,    0,    0,    0,  133,    9,
  134,  135,  136,  137,  138,  139,  140,  141,  142,  143,
  144,    0,    0,    0,    0,    0,    0,  145,  146,    0,
    0,    0,   28,    0,    0,  147,  148,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   29,   30,  149,  150,  151,    0,    0,    0,   31,   32,
   33,   34,   35,   36,   37,   38,   39,   40,    0,    0,
    0,    0,    0,   41,   42,   43,    0,    0,    0,    0,
    0,    0,    0,    0,   44,   45,   46,    0,   47,   48,
   49,   50,   51,   52,   53,   54,    0,   55,   56,    0,
    0,   57,    0,    0,    0,   58,   59,    0,    0,   60,
   61,    0,  152,  153,    0,    0,  154,    0,    0,   62,
  155,  156,  157,    0,    0,    0,    0,   63,    0,    0,
    0,   64,   65,   66,   67,   68,  158,  159,  160,  161,
  162,   69,   70,    0,  164,    0,    0,   71,   72,   73,
   74,   75,   76,   14,    0,    0,    0,    0,    0,    0,
   77,    0,    0,    0,    0,    0,    0,   78,    0,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,
   90,   91,   92,   93,   94,   95,   96,    0,    0,   97,
   98,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   99,    0,  100,    0,
 2058,  101,  102,  103,  104,  105,  106,  107,  108,  109,
  110,  111,  112,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  113,  114,  115,  116,  117,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  118,  119,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  120,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  121,    0,  122,  123,
    0,    0,  124,  125,  126,    0,    0,    0,    0,    0,
    0,  127,  128,  129,  130,    0,    0,  131,    0,    0,
  132,    0,    0,    0,    0,    0,    0,  133,    9,  134,
  135,  136,  137,  138,  139,  140,  141,  142,  143,  144,
    0,    0,    0,    0,    0,    0,  145,  146,    0,    0,
    0,   28,    0,    0,  147,  148,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   29,
   30,  149,  150,  151,    0,    0,    0,   31,   32,   33,
   34,   35,   36,   37,   38,   39,   40,    0,    0,    0,
    0,    0,   41,   42,   43,    0,    0,    0,    0,    0,
    0,    0,    0,   44,   45,   46,    0,   47,   48,   49,
   50,   51,   52,   53,   54,    0,   55,   56,    0,    0,
   57,    0,    0,    0,   58,   59,    0,    0,   60,   61,
    0,  152,  153,    0,    0,  154,    0,    0,   62,  155,
  156,  157,    0,    0,    0,    0,   63,    0,    0,    0,
   64,   65,   66,   67,   68,  158,  159,  160,  161,  162,
   69,   70,    0,  389,    0,    0,   71,   72,   73,   74,
   75,   76,   14,    0,    0,    0,    0,    0,    0,   77,
    0,    0,    0,    0,    0,    0,   78,    0,   79,   80,
   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,
   91,   92,   93,   94,   95,   96,    0,    0,   97,   98,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   99,    0,  100,    0,  389,
  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,
  111,  112,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  113,
  114,  115,  116,  117,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  118,
  119,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  120,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  121,    0,  122,  123,    0,
    0,  124,  125,  126,    0,    0,    0,    0,    0,    0,
  127,  128,  129,  130,    0,    0,  131,    0,    0,  132,
    0,    0,    0,    0,    0,    0,  133,    9,  134,  135,
  136,  137,  138,  139,  140,  141,  142,  143,  144,    0,
    0,    0,    0,    0,    0,  145,  146,    0,    0,    0,
  389,    0,    0,  147,  148,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  389,  389,
  149,  150,  151,    0,    0,    0,  389,  389,  389,  389,
  389,  389,  389,  389,  389,  389,    0,    0,    0,    0,
    0,  389,  389,  389,    0,    0,    0,    0,    0,    0,
    0,    0,  389,  389,  389,    0,  389,  389,  389,  389,
  389,  389,  389,  389,    0,  389,  389,    0,    0,  389,
    0,    0,    0,  389,  389,    0,    0,  389,  389,    0,
  152,  153,    0,    0,  154,    0,    0,  389,  155,  156,
  157,    0,    0,    0,    0,  389,    0,    0,    0,  389,
  389,  389,  389,  389,  158,  159,  160,  161,  162,  389,
  389,    0,  164,    0,    0,  389,  389,  389,  389,  389,
  389,  389,    0,    0,    0,    0,    0,    0,  389,    0,
    0,    0,    0,    0,    0,  389,    0,  389,  389,  389,
  389,  389,  389,  389,  389,  389,  389,  389,  389,  389,
  389,  389,  389,  389,  389,    0,    0,  389,  389,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  389,    0,  389,    0,    0,  389,
  389,  389,  389,  389,  389,  389,  389,  389,  389,  389,
  389,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  389,  389,
  389,  389,  389,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  389,  389,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  389,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  389,    0,  389,  389,    0,    0,
  389,  389,  389,    0,    0,    0,    0,    0,    0,  389,
  389,  389,  389,    0,    0,  389,    0,    0,  389,    0,
    0,    0,    0,    0,    0,  389,  389,  389,  389,  389,
  389,  389,  389,  389,  389,  389,  389,  389,    0,    0,
    0,    0,    0,    0,  389,  389,    0,    0,    0,   28,
    0,    0,  389,  389,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   29,   30,  389,
  389,  389,    0,    0,    0,   31,   32,   33,   34,   35,
   36,   37,   38,   39,   40,    0,    0,    0,    0,    0,
   41,   42,   43,    0,    0,    0,    0,    0,    0,    0,
    0,   44,   45,   46,    0,   47,   48,   49,   50,   51,
   52,   53,   54,    0,   55,   56,    0,    0,   57,    0,
    0,    0,   58,   59,    0,    0,   60,   61,    0,  389,
  389,    0,    0,  389,    0,    0,   62,  389,  389,  389,
    0,    0,    0,    0,   63,    0,    0,    0,   64,   65,
   66,   67,   68,  389,  389,  389,  389,  389,   69,   70,
    0,  567,    0,    0,   71,   72,   73,   74,   75,   76,
   14,    0,    0,    0,    0,    0,    0,   77,    0,    0,
    0,    0,    0,    0,   78,    0,   79,   80,   81,   82,
   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
   93,   94,   95,   96,    0,    0,   97,   98,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   99,    0,  100,    0,  567,  101,  102,
  103,  104,  105,  106,  107,  108,  109,  110,  111,  112,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  113,  114,  115,
  116,  117,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  118,  119,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  120,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  121,    0,  122,  123,    0,    0,  124,
  125,  126,    0,    0,    0,    0,    0,    0,  127,  128,
  129,  130,    0,    0,  131,    0,    0,  132,    0,    0,
    0,    0,    0,    0,  133,    9,  134,  135,  136,  137,
  138,  139,  140,  141,  142,  143,  144,    0,    0,    0,
    0,    0,    0,  145,  146,    0,    0,    0,  567,    0,
    0,  147,  148,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  567,  567,  149,  150,
  151,    0,    0,    0,  567,  567,  567,  567,  567,  567,
  567,  567,  567,  567,    0,    0,    0,    0,    0,  567,
  567,  567,    0,    0,    0,    0,    0,    0,    0,    0,
  567,  567,  567,    0,  567,  567,  567,  567,  567,  567,
  567,  567,    0,  567,  567,    0,    0,  567,    0,    0,
    0,  567,  567,    0,    0,  567,  567,    0,  152,  153,
    0,    0,  154,    0,    0,  567,  155,  156,  157,    0,
    0,    0,    0,  567,    0,    0,    0,  567,  567,  567,
  567,  567,  158,  159,  160,  161,  162,  567,  567,    0,
   45,    0,    0,  567,  567,  567,  567,  567,  567,  567,
    0,    0,    0,    0,    0,    0,  567,    0,    0,    0,
    0,    0,    0,  567,    0,  567,  567,  567,  567,  567,
  567,  567,  567,  567,  567,  567,  567,  567,  567,  567,
  567,  567,  567,    0,    0,  567,  567,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  567,    0,  567,    0,   45,  567,  567,  567,
  567,  567,  567,  567,  567,  567,  567,  567,  567,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  567,  567,  567,  567,
  567,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  567,  567,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  567,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  567,    0,  567,  567,    0,    0,  567,  567,
  567,    0,    0,    0,    0,    0,    0,  567,  567,  567,
  567,    0,    0,  567,    0,    0,  567,    0,    0,    0,
    0,    0,    0,  567,  567,  567,  567,  567,  567,  567,
  567,  567,  567,  567,  567,  567,    0,    0,    0,    0,
    0,    0,  567,  567,    0,    0,    0,    0,    0,    0,
  567,  567,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   45,   45,  567,  567,  567,
    0,    0,    0,   45,   45,   45,   45,   45,   45,   45,
   45,   45,   45,    0,    0,    0,    0,    0,   45,   45,
   45,    0,    0,    0,    0,    0,    0,    0,    0,   45,
   45,   45,    0,   45,   45,   45,   45,   45,   45,   45,
   45,    0,   45,   45,    0,    0,   45,    0,    0,    0,
   45,   45,    0,    0,   45,   45,    0,  567,  567,    0,
    0,    0,    0,    0,   45,  567,  567,  567,    0,    0,
    0,    0,   45,    0,    0,    0,   45,   45,   45,   45,
   45,  567,  567,  567,  567,  567,   45,   45,    0,  374,
    0,    0,   45,   45,   45,   45,   45,   45,   45,    0,
    0,    0,    0,    0,    0,   45,    0,    0,    0,    0,
    0,    0,   45,    0,   45,   45,   45,   45,   45,   45,
   45,   45,   45,   45,   45,   45,   45,   45,   45,   45,
   45,   45,    0,    0,   45,   45,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   45,    0,   45,    0,  374,   45,   45,   45,   45,
   45,   45,   45,   45,   45,   45,   45,   45,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   45,   45,   45,   45,   45,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   45,   45,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   45,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   45,    0,   45,   45,    0,    0,   45,   45,   45,
    0,    0,    0,    0,    0,    0,   45,   45,   45,   45,
    0,    0,   45,    0,    0,   45,    0,    0,    0,    0,
    0,    0,   45,   45,   45,   45,   45,   45,   45,   45,
   45,   45,   45,   45,   45,    0,    0,    0,    0,    0,
    0,   45,   45,    0,    0,    0,    0,    0,    0,   45,
   45,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  374,  374,   45,   45,   45,    0,
    0,    0,  374,  374,  374,  374,  374,  374,  374,  374,
  374,  374,    0,    0,    0,    0,    0,  374,  374,  374,
    0,    0,    0,    0,    0,    0,    0,    0,  374,  374,
  374,    0,  374,  374,  374,  374,  374,  374,  374,  374,
    0,  374,  374,    0,    0,  374,    0,    0,    0,  374,
  374,    0,    0,  374,  374,    0,   45,   45,    0,    0,
   45,    0,    0,  374,   45,   45,   45,    0,    0,    0,
    0,  374,    0,    0,    0,  374,  374,  374,  374,  374,
   45,   45,   45,   45,   45,  374,  374,    0,    0,    0,
    0,  374,  374,  374,  374,  374,  374,  374,    0,    0,
    0,    0,    0,    0,  374,    0,    0,    0,    0,    0,
    0,  374,    0,  374,  374,  374,  374,  374,  374,  374,
  374,  374,  374,  374,  374,  374,  374,  374,  374,  374,
  374,    0,    0,  374,  374,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  374,    0,  374,    0,   46,  374,  374,  374,  374,  374,
  374,  374,  374,  374,  374,  374,  374,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  374,  374,  374,  374,  374,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  374,  374,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  374,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  374,    0,  374,  374,    0,    0,  374,  374,  374,    0,
    0,    0,    0,    0,    0,  374,  374,  374,  374,    0,
    0,  374,    0,    0,  374,    0,    0,    0,    0,    0,
    0,  374,  374,  374,  374,  374,  374,  374,  374,  374,
  374,  374,  374,  374,    0,    0,    0,    0,    0,    0,
  374,  374,    0,    0,    0,   46,    0,    0,  374,  374,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   46,   46,  374,  374,  374,    0,    0,
    0,   46,   46,   46,   46,   46,   46,   46,   46,   46,
   46,    0,    0,    0,    0,    0,   46,   46,   46,    0,
    0,    0,    0,    0,    0,    0,    0,   46,   46,   46,
    0,   46,   46,   46,   46,   46,   46,   46,   46,    0,
   46,   46,    0,    0,   46,    0,    0,    0,   46,   46,
    0,    0,   46,   46,    0,  374,  374,    0,    0,  374,
    0,    0,   46,  374,  374,  374,    0,    0,    0,    0,
   46,    0,    0,    0,   46,   46,   46,   46,   46,  374,
  374,  374,  374,  374,   46,   46,    0,    0,    0,    0,
   46,   46,   46,   46,   46,   46,   46,    0,    0,    0,
    0,    0,    0,   46,    0,    0,    0,    0,    0,    0,
   46,    0,   46,   46,   46,   46,   46,   46,   46,   46,
   46,   46,   46,   46,   46,   46,   46,   46,   46,   46,
    0,    0,   46,   46,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   46,
    0,   46,    0,   48,   46,   46,   46,   46,   46,   46,
   46,   46,   46,   46,   46,   46,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   46,   46,   46,   46,   46,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   46,   46,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   46,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   46,
    0,   46,   46,    0,    0,   46,   46,   46,    0,    0,
    0,    0,    0,    0,   46,   46,   46,   46,    0,    0,
   46,    0,    0,   46,    0,    0,    0,    0,    0,    0,
   46,   46,   46,   46,   46,   46,   46,   46,   46,   46,
   46,   46,   46,    0,    0,    0,    0,    0,    0,   46,
   46,    0,    0,    0,   48,    0,    0,   46,   46,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   48,   48,   46,   46,   46,    0,    0,    0,
   48,   48,   48,   48,   48,   48,   48,   48,   48,   48,
    0,    0,    0,    0,    0,   48,   48,   48,    0,    0,
    0,    0,    0,    0,    0,    0,   48,   48,   48,    0,
   48,   48,   48,   48,   48,   48,   48,   48,    0,   48,
   48,    0,    0,   48,    0,    0,    0,   48,   48,    0,
    0,   48,   48,    0,   46,   46,    0,    0,   46,    0,
    0,   48,   46,   46,   46,    0,    0,    0,    0,   48,
    0,    0,    0,   48,   48,   48,   48,   48,   46,   46,
   46,   46,   46,   48,   48, 1262,    0,    0,    0,   48,
   48,   48,   48,   48,   48,   48,    0,    0,    0,    0,
    0,    0,   48,    0,    0,    0,    0,    0,    0,   48,
    0,   48,   48,   48,   48,   48,   48,   48,   48,   48,
   48,   48,   48,   48,   48,   48,   48,   48,   48,    0,
    0,   48,   48,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   48,    0,
   48,    0,    0,   48,   48,   48,   48,   48,   48,   48,
   48,   48,   48,   48,   48,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   48,   48,   48,   48,   48, 1897,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   48,   48,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   48,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   48,    0,
   48,   48,    0,    0,   48,   48,   48,    0,    0,    0,
    0,    0,    0,   48,   48,   48,   48,    0,    0,   48,
    0,    0,   48,    0,    0, 2100,    0,    0,    0,   48,
   48,   48,   48,   48,   48,   48,   48,   48,   48,   48,
   48,   48,    0,    0,    0,    0,    0,    0,   48,   48,
    0,    0,    0,    0,    0,    0,   48,   48,    0,    0,
    0,    0,    0,    0, 1221,    0,    0,    0,    0,    0,
 1222, 1223, 1224,   48,   48,   48, 1225,    0,    0,    0,
    0,    0, 1226, 1227, 1228,    0,    0,    0,    0,    0,
 1229, 1230,    0,    0,    0,    0,    0, 1231, 1232, 1233,
 1234,    0,    0,    0,    0,    0,    0,    0, 1235,    0,
    0,    0,    0,    0, 1236,    0,    0,    0,    0,    0,
    0, 1237, 1238,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   48,   48,    0,    0,   48,    0,    0,
    0,   48,   48,   48,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 1239, 1240, 1241,    0,   48,   48,   48,
   48,   48,    0,    0,    0,    0, 1221,    0,    0,    0,
    0,    0, 1222, 1223, 1224,    0,    0,    0, 1225,    0,
    0,    0,    0,    0, 1226, 1227, 1228,    0,    0,    0,
    0,    0, 1229, 1230,    0,    0,    0,    0,    0, 1231,
 1232, 1233, 1234,    0,    0, 1242, 1243, 1244, 1245, 1246,
 1235,    0,    0,    0,    0,    0, 1236, 1247, 1248, 1249,
    0,    0,    0, 1237, 1238,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 1221,    0,    0,    0,    0, 1250,
 1222, 1223, 1224,    0,    0,    0, 1225,    0,    0,    0,
    0,    0, 1226, 1227, 1228, 1239, 1240, 1241,    0,    0,
 1229, 1230, 1251, 1252,    0, 1253, 1254, 1231, 1232, 1233,
 1234,    0,    0,    0,    0,    0,    0,    0, 1235,    0,
    0,    0,    0,    0, 1236,    0,    0,    0, 1255, 1256,
    0, 1237, 1238,    0,    0,    0, 1257, 1258,    0,    0,
    0,    0, 1259,    0, 1260, 1261,    0, 1242, 1243, 1244,
 1245, 1246,    0,    0,    0,    0,    0,    0,    0, 1247,
 1248, 1249,    0, 1239, 1240, 1241,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 1250,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 1251, 1252,    0, 1253, 1254,    0,
    0,    0,    0,    0,    0, 1242, 1243, 1244, 1245, 1246,
    0,    0,    0,    0,    0,    0,    0, 1247, 1248, 1249,
 1255, 1256,    0,    0,    0,    0,    0,    0, 1257, 1258,
    0,    0,    0,    0, 1259,    0, 1260, 1261,    0, 1250,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 1251, 1252,    0, 1253, 1254,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   28,    0,    0,    0,    0,    0,    0,    0, 1255, 1256,
    0,    0,    0,    0,    0,    0, 1257, 1258,   29,   30,
    0,    0, 1259,    0, 1260, 1261,   31,   32,   33,   34,
   35,   36,   37,   38,   39,   40,    0,    0,    0,    0,
    0,   41,   42,   43,    0,    0,    0,    0,    0,    0,
    0,    0,   44,   45,   46,    0,   47,   48,   49,   50,
   51,   52,   53,   54,    0,   55,   56,    0,    0,   57,
    0,    0,    0,   58,   59,    0,    0,   60,   61,    0,
    0,    0,    0,    0,    0,    0,    0,   62,    0,    0,
    0,    0,    0,    0,    0,   63,    0,    0,    0,   64,
   65,   66,   67,   68,    0,    0,    0,    0,    0,   69,
   70,    0,    0,    0,    0,   71,   72,   73,   74,   75,
   76,   14,    0,    0,    0,    0,    0,    0,   77,    0,
    0,    0,    0,    0,    0,   78,    0,   79,   80,   81,
   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,
   92,   93,   94,   95,   96,    0,    0,   97,   98,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   99,    0,  100,    0,    0,  101,
  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
  112,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  113,  114,
  115,  116,  117,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  118,  119,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  120,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  121,    0,  122,  123,    0,    0,
  124,  125,  126,    0,    0,    0,    0,    0,    0,  127,
  128,  129,  130,    0,    0,  131,    0,    0,  132,    0,
    0,    0,    0,    0,    0,  133,    9,  134,  135,  136,
  137,  138,  139,  140,  141,  142,  143,  144,    0,    0,
    0,    0,    0,    0,  145,  146,    0,    0,    0, 1117,
    0,    0,  147,  148,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   29,   30,  149,
  150,  151,    0,    0,    0,    0,   32,   33,   34,   35,
   36,   37,   38,   39,    0,    0,    0,    0,    0,    0,
    0,    0,   43,    0,    0,    0,    0,    0,    0,    0,
    0,   44,   45,   46,    0,    0,   48,    0,    0,    0,
    0,    0,    0,    0,    0,   56,    0,    0,   57,    0,
    0,    0,   58,    0,    0,    0,   60,   61,    0,  152,
  153,    0,    0,  154,    0,    0,   62,  155,  156,  157,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   67,   68,  158,  159,  160,  161,  162,   69,    0,
    0,    0,    0,    0,    0,    0,    0,   74,   75,    0,
   14,    0,    0,    0,    0,    0,    0,   77,    0,    0,
    0,    0,    0,    0,   78,    0,   79,   80,   81,   82,
   83,   84,   85,   86,    0,   88,   89,   90,   91,   92,
   93,   94,   95,   96,    0,    0,   97,   98,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  100,    0,    0,  101,  102,
    0,    0,  105,  106,  107,    0,  109,  110,    0,  112,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  113,  114,    0,
  116,  117,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  120,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  123,    0,    0,    0,
  125,    0,    0,    0,    0,    0,    0,    0,  127,  128,
    0,  130,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  133,    9,  134,    0,    0,  137,
  138,  139,  140,  141,  142,  143,  144,    0,    0,    0,
    0,    0,    0,  145,    0,    0,    0,    0,    0,    0,
    0,  147,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  149,  150,
  151,    0,    0,    0,    0, 2166, 2167, 2168, 2169, 2170,
 2171, 2172, 2173, 2174, 2175,    0,    0,    0,    0,    0,
    0,   29,   30,    0,    0,    0,    0,    0,    0,    0,
   32,   33,   34,   35,   36,   37,   38,   39,    0,    0,
    0,    0,    0,    0,    0,    0,   43,    0,    0,    0,
    0,    0,    0,    0,    0,   44,   45,   46,  152,  153,
   48,    0,  154,    0,    0,    0,  155,  156,  397,   56,
    0,    0,   57,    0,    0,    0,   58,    0,    0,    0,
   60,   61,  158,  159,  160,  161,  162,    0,    0,    0,
   62,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   67,   68,    0,    0,    0,
    0,    0,   69,    0,    0,    0,    0,    0,    0,    0,
    0,   74,   75,    0,   14,    0,    0,    0,    0,    0,
    0,   77,    0,    0,    0,    0,    0,    0,   78,    0,
   79,   80,   81,   82,   83,   84,   85,   86,    0,   88,
   89,   90,   91,   92,   93,   94,   95,   96,    0,    0,
   97,   98,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  100,
    0,    0,  101,  102,    0,    0,  105,  106,  107,    0,
  109,  110,    0,  112,    0,    0,    0,    0,    0,    0,
    0,  338,  338,  338,  338,  338,  338,  338,    0,    0,
    0,  113,  114,    0,  116,  117,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  338,
    0,    0,    0,  120,    0,    0,  338,    0,    0,    0,
    0,  338,    0,    0,    0,    0,    0,    0,    0,    0,
  123,    0,    0,    0,  125,    0,    0,    0,    0,    0,
    0,    0,  127,  128,    0,  130,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  133,    9,
  134,    0,  338,  137,  138,  139,  140,  141,  142,  143,
  144,  338,    0,    0,    0,    0,    0,  145,  338,    0,
    0,    0,    0,    0,    0,  147,    0,    0,    0,    0,
  338,  338,  338,  338,  338,  338,  338,  338,    0,    0,
   29,   30,  149,  150,  151,    0,    0,    0,    0,   32,
   33,   34,   35,   36,   37,   38,   39,    0,    0,    0,
    0,    0,    0,    0,    0,   43,  338,  338,    0,    0,
    0,    0,    0,    0,   44,   45,   46,    0,    0,   48,
    0,    0,    0,    0,    0,    0,    0,    0,   56,    0,
    0,   57,    0,    0,    0,   58,    0,    0,    0,   60,
   61,    0,  152,  153,    0,    0,  154,    0,    0,   62,
  155,  156,  397,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  338,   67,   68,  158,  159,  160,  161,
  162,   69,    0,    0,    0,    0,    0,    0,    0,    0,
   74,   75,    0,   14,    0,    0,    0,    0,    0,    0,
   77,    0,    0,    0,    0,    0,    0,   78,    0,   79,
   80,   81,   82,   83,   84,   85,   86,    0,   88,   89,
   90,   91,   92,   93,   94,   95,   96,    0,    0,   97,
   98,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  100,    0,
    0,  101,  102,    0,    0,  105,  106,  107,    0,  109,
  110,    0,  112,    0,    0,    0,    0,    0,    0,    0,
  371,  371,  371,  371,  371,  371,  371,    0,    0,    0,
  113,  114,    0,  116,  117,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 1786, 1787, 1788, 1789,
    0,    0,    0,    0,    0,    0,    0,    0,  371,    0,
    0,    0,  120,    0,    0,  371,    0,    0,    0,    0,
  371,    0,    0,    0,    0,    0,    0,    0,    0,  123,
    0,    0,  338,  125,    0,    0,    0,    0,    0,    0,
    0,  127,  128,    0,  130,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  133,    9,  134,
    0,  371,  137,  138,  139,  140,  141,  142,  143,  144,
  371,    0,    0,    0,    0,    0,  145,  371,    0,    0,
    0,    0,    0,    0,  147,    0,    0,    0,    0,  371,
  371,  371,  371,  371,  371,  371,  371,    0,    0,   29,
   30,  149,  150,  151,    0,    0,    0,    0,   32,   33,
   34,   35,   36,   37,   38,   39,    0,    0,    0,    0,
    0,    0,    0,    0,   43,  371,  371,    0,    0,    0,
    0,    0,    0,   44,   45,   46,    0,    0,   48,    0,
    0,    0,    0,    0,    0,    0,    0,   56,    0,    0,
   57,    0,    0,    0,   58,    0,    0,    0,   60,   61,
    0,  152,  153,    0,    0,  154,    0,    0,   62,  155,
  156,  397,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  371,   67,   68,  158,  159,  160,  161,  162,
   69,    0,    0,    0,    0,    0,    0,    0,    0,   74,
   75,    0,   14,    0,    0,    0,    0,    0,    0,   77,
    0,    0,    0,    0,    0,    0,   78,    0,   79,   80,
   81,   82,   83,   84,   85,   86,    0,   88,   89,   90,
   91,   92,   93,   94,   95,   96,    0,    0,   97,   98,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  100,    0,    0,
  101,  102,    0,    0,  105,  106,  107,    0,  109,  110,
    0,  112,    0,    0,    0,    0,    0,    0,    0,  440,
  440,  440,  440,  440,  440,  440,    0,    0,    0,  113,
  114,    0,  116,  117,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  440,    0,    0,
    0,  120,    0,    0,  440,    0,    0,    0,    0,  440,
    0,    0,    0,    0,    0,    0,    0,    0,  123,    0,
    0,  371,  125,    0,    0,    0,    0,    0,    0,    0,
  127,  128,    0,  130,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  133,    9,  134,    0,
  440,  137,  138,  139,  140,  141,  142,  143,  144,  440,
    0,    0,    0,    0,    0,  145,  440,    0,    0,    0,
    0,    0,    0,  147,    0,    0,    0,    0,  440,  440,
  440,  440,  440,  440,  440,  440,    0,    0,  565,  565,
  149,  150,  151,    0,    0,    0,    0,  565,  565,  565,
  565,  565,  565,  565,  565,    0,    0,    0,    0,    0,
    0,    0,    0,  565,  440,  440,    0,    0,    0,    0,
    0,    0,  565,  565,  565,    0,    0,  565,    0,    0,
    0,    0,    0,    0,    0,    0,  565,    0,    0,  565,
    0,    0,    0,  565,    0,    0,    0,  565,  565,    0,
  152,  153,    0,    0,  154,  696,    0,  565,  155,  156,
  397,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  440,  565,  565,  158,  159,  160,  161,  162,  565,
    0,    0,    0,    0,    0,    0,    0,    0,  565,  565,
    0,  565,    0,    0,    0,    0,    0,    0,  565,    0,
    0,    0,    0,    0,    0,  565,    0,  565,  565,  565,
  565,  565,  565,  565,  565,    0,  565,  565,  565,  565,
  565,  565,  565,  565,  565,    0,    0,  565,  565,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  565,    0,    0,  565,
  565,    0,    0,  565,  565,  565,    0,  565,  565,    0,
  565,    0,    0,    0,    0,    0,    0,    0,  520,  520,
  520,  520,  520,  520,  520,    0,    0,    0,  565,  565,
    0,  565,  565,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  520,    0,    0,    0,
  565,    0,    0,  520,    0,    0,    0,    0,  520,    0,
    0,    0,    0,    0,    0,    0,    0,  565,    0,    0,
  440,  565,    0,    0,    0,    0,    0,    0,    0,  565,
  565,    0,  565,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  565,  565,  565,    0,  520,
  565,  565,  565,  565,  565,  565,  565,  565,  520,    0,
    0,    0,    0,    0,  565,  520,    0,    0,    0,    0,
    0,    0,  565,    0,    0,    0,    0,  520,  520,  520,
  520,  520,  520,  520,  520,    0,    0,   29,   30,  565,
  565,  565,    0,    0,    0,    0,   32,   33,   34,   35,
   36,   37,   38,   39,    0,    0,    0,    0,    0,    0,
    0,    0,   43,  520,  520,    0,    0,    0,    0,    0,
    0,   44,   45,   46,    0,    0,   48,    0,    0,    0,
    0,    0,    0,    0,    0,   56,    0,    0,   57,    0,
    0,    0,   58,    0,    0,    0,   60,   61,    0,  565,
  565,    0,    0,  565,  565,    0,   62,  565,  565,  565,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  520,   67,   68,  565,  565,  565,  565,  565,   69,    0,
    0,    0,    0,    0,    0,    0,    0,   74,   75,    0,
   14,    0,    0,    0,    0,    0,    0,   77,    0,    0,
    0,    0,    0,    0,   78,    0,   79,   80,   81,   82,
   83,   84,   85,   86,    0,   88,   89,   90,   91,   92,
   93,   94,   95,   96,    0,    0,   97,   98,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  100,    0,    0,  101,  102,
    0,    0,  105,  106,  107,    0,  109,  110,    0,  112,
    0,    0,    0,    0,    0,    0,    0,  526,  526,  526,
  526,  526,  526,  526,    0,    0,    0,  113,  114,    0,
  116,  117,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  526,    0,    0,    0,  120,
    0,    0,  526,    0,    0,    0,    0,  526,    0,    0,
    0,    0,    0,    0,    0,    0,  123,    0,    0,  520,
  125,    0,    0,    0,    0,    0,    0,    0,  127,  128,
    0,  130,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  133,    9,  134,    0,  526,  137,
  138,  139,  140,  141,  142,  143,  144,  526,    0,    0,
    0,    0,    0,  145,  526,    0,    0,    0,    0,    0,
    0,  147,    0,    0,    0,    0,  526,  526,  526,  526,
  526,  526,  526,  526,    0,    0,  304,  304,  149,  150,
  151,    0,    0,    0,    0,  304,  304,  304,  304,  304,
  304,  304,  304,    0,    0,    0,    0,    0,    0,    0,
    0,  304,  526,  526,    0,    0,    0,    0,    0,    0,
  304,  304,  304,    0,    0,  304,    0,    0,    0,    0,
    0,    0,    0,    0,  304,    0,    0,  304,    0,    0,
    0,  304,    0,    0,    0,  304,  304,    0,  152,  153,
    0,    0,  154,    0,    0,  304,  155,  156,  397,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  526,
  304,  304,  158,  159,  160,  161,  162,  304,    0,    0,
    0,    0,    0,    0,    0,    0,  304,  304,    0,  304,
    0,    0,    0,    0,    0,    0,  304,    0,    0,    0,
    0,    0,    0,  304,    0,  304,  304,  304,  304,  304,
  304,  304,  304,    0,  304,  304,  304,  304,  304,  304,
  304,  304,  304,    0,    0,  304,  304,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  304,    0,    0,  304,  304,    0,
    0,  304,  304,  304,    0,  304,  304,    0,  304,    0,
    0,    0,    0,    0,    0,    0,  556,  556,  556,  556,
  556,  556,  556,    0,    0,    0,  304,  304,    0,  304,
  304,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  556,    0,    0,    0,  304,    0,
    0,  556,    0,    0,    0,    0,  556,    0,    0,    0,
    0,    0,    0,    0,    0,  304,    0,    0,  526,  304,
    0,    0,    0,    0,    0,    0,    0,  304,  304,    0,
  304,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  304,  304,  304,    0,  556,  304,  304,
  304,  304,  304,  304,  304,  304,  556,    0,    0,    0,
    0,    0,  304,  556,    0,    0,    0,    0,    0,    0,
  304,    0,    0,    0,    0,  556,  556,  556,  556,  556,
  556,  556,  556,    0,    0,  310,  310,  304,  304,  304,
    0,    0,    0,    0,  310,  310,  310,  310,  310,  310,
  310,  310,    0,    0,    0,    0,    0,    0,    0,    0,
  310,  556,  556,    0,    0,    0,    0,    0,    0,  310,
  310,  310,    0,    0,  310,    0,    0,    0,    0,    0,
    0,    0,    0,  310,    0,    0,  310,    0,    0,    0,
  310,    0,    0,    0,  310,  310,    0,  304,  304,    0,
    0,  304,    0,    0,  310,  304,  304,  304,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  556,  310,
  310,  304,  304,  304,  304,  304,  310,    0,    0,    0,
    0,    0,    0,    0,    0,  310,  310,    0,  310,    0,
    0,    0,    0,    0,    0,  310,    0,    0,    0,    0,
    0,    0,  310,    0,  310,  310,  310,  310,  310,  310,
  310,  310,    0,  310,  310,  310,  310,  310,  310,  310,
  310,  310,    0,    0,  310,  310,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  310,    0,    0,  310,  310,    0,    0,
  310,  310,  310,    0,  310,  310,    0,  310,    0,    0,
    0,    0,    0,    0,    0,  559,  559,  559,  559,  559,
  559,  559,    0,    0,    0,  310,  310,    0,  310,  310,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  559,    0,    0,    0,  310,    0,    0,
  559,    0,    0,    0,    0,  559,    0,    0,    0,    0,
    0,    0,    0,    0,  310,    0,    0,  556,  310,    0,
    0,    0,    0,    0,    0,    0,  310,  310,    0,  310,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  310,  310,  310,    0,  559,  310,  310,  310,
  310,  310,  310,  310,  310,  559,    0,    0,    0,    0,
    0,  310,  559,    0,    0,    0,    0,    0,    0,  310,
    0,    0,    0,    0,  559,  559,  559,  559,  559,  559,
  559,  559,    0,    0,  332,  332,  310,  310,  310,    0,
    0,    0,    0,  332,  332,  332,  332,  332,  332,  332,
  332,    0,    0,    0,    0,    0,    0,    0,    0,  332,
  559,  559,    0,    0,    0,    0,    0,    0,  332,  332,
  332,    0,    0,  332,    0,    0,    0,    0,    0,    0,
    0,    0,  332,    0,    0,  332,    0,    0,    0,  332,
    0,    0,    0,  332,  332,    0,  310,  310,    0,    0,
  310,    0,    0,  332,  310,  310,  310,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  559,  332,  332,
  310,  310,  310,  310,  310,  332,    0,    0,    0,    0,
    0,    0,    0,    0,  332,  332,    0,  332,    0,    0,
    0,    0,    0,    0,  332,    0,    0,    0,    0,    0,
    0,  332,    0,  332,  332,  332,  332,  332,  332,  332,
  332,    0,  332,  332,  332,  332,  332,  332,  332,  332,
  332,    0,    0,  332,  332,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  332,    0,    0,  332,  332,    0,    0,  332,
  332,  332,    0,  332,  332,    0,  332,    0,    0,    0,
    0,    0,    0,    0,  562,  562,  562,  562,  562,  562,
  562,    0,    0,    0,  332,  332,    0,  332,  332,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  562,    0,    0,    0,  332,    0,    0,  562,
    0,    0,    0,    0,  562,    0,    0,    0,    0,    0,
    0,    0,    0,  332,    0,    0,  559,  332,    0,    0,
    0,    0,    0,    0,    0,  332,  332,    0,  332,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  332,  332,  332,    0,  562,  332,  332,  332,  332,
  332,  332,  332,  332,  562,    0,    0,    0,    0,    0,
  332,  562,    0,    0,    0,    0,    0,    0,  332,    0,
    0,    0,    0,  562,  562,  562,  562,  562,  562,  562,
  562,    0,    0,  335,  335,  332,  332,  332,    0,    0,
    0,    0,  335,  335,  335,  335,  335,  335,  335,  335,
    0,    0,    0,    0,    0,    0,    0,    0,  335,  562,
  562,    0,    0,    0,    0,    0,    0,  335,  335,  335,
    0,    0,  335,    0,    0,    0,    0,    0,    0,    0,
    0,  335,    0,    0,  335,    0,    0,    0,  335,    0,
    0,    0,  335,  335,    0,  332,  332,    0,    0,  332,
    0,    0,  335,  332,  332,  332,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  562,  335,  335,  332,
  332,  332,  332,  332,  335,    0,    0,    0,    0,    0,
    0,    0,    0,  335,  335,    0,  335,    0,    0,    0,
    0,    0,    0,  335,    0,    0,    0,    0,    0,    0,
  335,    0,  335,  335,  335,  335,  335,  335,  335,  335,
    0,  335,  335,  335,  335,  335,  335,  335,  335,  335,
    0,    0,  335,  335,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  335,    0,    0,  335,  335,    0,    0,  335,  335,
  335,    0,  335,  335,    0,  335,    0,    0,    0,    0,
    0,    0,    0,  578,  578,  578,  578,  578,  578,  578,
    0,    0,    0,  335,  335,    0,  335,  335,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  578,    0,    0,    0,  335,    0,    0,  578,    0,
    0,    0,    0,  578,    0,    0,    0,    0,    0,    0,
    0,    0,  335,    0,    0,  562,  335,    0,    0,    0,
    0,    0,    0,    0,  335,  335,    0,  335,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  335,  335,  335,    0,  578,  335,  335,  335,  335,  335,
  335,  335,  335,  578,    0,    0,    0,    0,    0,  335,
  578,    0,    0,    0,    0,    0,    0,  335,    0,    0,
    0,    0,  578,  578,  578,  578,  578,  578,  578,  578,
    0,    0,  346,  346,  335,  335,  335,    0,    0,    0,
    0,  346,  346,  346,  346,  346,  346,  346,  346,    0,
    0,    0,    0,    0,    0,    0,    0,  346,  578,  578,
    0,    0,    0,    0,    0,    0,  346,  346,  346,    0,
    0,  346,    0,    0,    0,    0,    0,    0,    0,    0,
  346,    0,    0,  346,    0,    0,    0,  346,    0,    0,
    0,  346,  346,    0,  335,  335,    0,    0,  335,    0,
    0,  346,  335,  335,  335,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  578,  346,  346,  335,  335,
  335,  335,  335,  346,    0,    0,    0,    0,    0,    0,
    0,    0,  346,  346,    0,  346,    0,    0,    0,    0,
    0,    0,  346,    0,    0,    0,    0,    0,    0,  346,
    0,  346,  346,  346,  346,  346,  346,  346,  346,    0,
  346,  346,  346,  346,  346,  346,  346,  346,  346,    0,
    0,  346,  346,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  346,    0,    0,  346,  346,    0,    0,  346,  346,  346,
    0,  346,  346,    0,  346,    0,    0,    0,    0,    0,
    0,    0,  581,  581,  581,  581,  581,  581,  581,    0,
    0,    0,  346,  346,    0,  346,  346,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  581,    0,    0,    0,  346,    0,    0,  581,    0,    0,
    0,    0,  581,    0,    0,    0,    0,    0,    0,    0,
    0,  346,    0,    0,  578,  346,    0,    0,    0,    0,
    0,    0,    0,  346,  346,    0,  346,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  346,
  346,  346,    0,  581,  346,  346,  346,  346,  346,  346,
  346,  346,  581,    0,    0,    0,    0,    0,  346,  581,
    0,    0,    0,    0,    0,    0,  346,    0,    0,    0,
    0,  581,  581,  581,  581,  581,  581,  581,  581,    0,
    0,  349,  349,  346,  346,  346,    0,    0,    0,    0,
  349,  349,  349,  349,  349,  349,  349,  349,    0,    0,
    0,    0,    0,    0,    0,    0,  349,  581,  581,    0,
    0,    0,    0,    0,    0,  349,  349,  349,    0,    0,
  349,    0,    0,    0,    0,    0,    0,    0,    0,  349,
    0,    0,  349,    0,    0,    0,  349,    0,    0,    0,
  349,  349,    0,  346,  346,    0,    0,  346,    0,    0,
  349,  346,  346,  346,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  581,  349,  349,  346,  346,  346,
  346,  346,  349,    0,    0,    0,    0,    0,    0,    0,
    0,  349,  349,    0,  349,    0,    0,    0,    0,    0,
    0,  349,    0,    0,    0,    0,    0,    0,  349,    0,
  349,  349,  349,  349,  349,  349,  349,  349,    0,  349,
  349,  349,  349,  349,  349,  349,  349,  349,    0,    0,
  349,  349,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  349,
    0,    0,  349,  349,    0,    0,  349,  349,  349,    0,
  349,  349,    0,  349,    0,    0,    0,    0,    0,    0,
    0,  638,  638,  638,  638,  638,  638,  638,    0,    0,
    0,  349,  349,    0,  349,  349,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  638,
    0,    0,    0,  349,    0,    0,  638,    0,    0,    0,
    0,  638,    0,    0,    0,    0,    0,    0,    0,    0,
  349,    0,    0,  581,  349,    0,    0,    0,    0,    0,
    0,    0,  349,  349,    0,  349,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  349,  349,
  349,    0,  638,  349,  349,  349,  349,  349,  349,  349,
  349,  638,    0,    0,    0,    0,    0,  349,  638,    0,
    0,    0,    0,    0,    0,  349,    0,    0,    0,    0,
  638,  638,  638,  638,  638,  638,  638,  638,    0,    0,
  352,  352,  349,  349,  349,    0,    0,    0,    0,  352,
  352,  352,  352,  352,  352,  352,  352,    0,    0,    0,
    0,    0,    0,    0,    0,  352,  638,  638,    0,    0,
    0,    0,    0,    0,  352,  352,  352,    0,    0,  352,
    0,    0,    0,    0,    0,    0,    0,    0,  352,    0,
    0,  352,    0,    0,    0,  352,    0,    0,    0,  352,
  352,    0,  349,  349,    0,    0,  349,    0,    0,  352,
  349,  349,  349,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  638,  352,  352,  349,  349,  349,  349,
  349,  352,    0,    0,    0,    0,    0,    0,    0,    0,
  352,  352,    0,  352,    0,    0,    0,    0,    0,    0,
  352,    0,    0,    0,    0,    0,    0,  352,    0,  352,
  352,  352,  352,  352,  352,  352,  352,    0,  352,  352,
  352,  352,  352,  352,  352,  352,  352,    0,    0,  352,
  352,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  352,    0,
    0,  352,  352,    0,    0,  352,  352,  352,    0,  352,
  352,    0,  352,    0,    0,    0,    0,    0,    0,    0,
  641,  641,  641,  641,  641,  641,  641,    0,    0,    0,
  352,  352,    0,  352,  352,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  641,    0,
    0,    0,  352,    0,    0,  641,    0,    0,    0,    0,
  641,    0,    0,    0,    0,    0,    0,    0,    0,  352,
    0,    0,  638,  352,    0,    0,    0,    0,    0,    0,
    0,  352,  352,    0,  352,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  352,  352,  352,
    0,  641,  352,  352,  352,  352,  352,  352,  352,  352,
  641,    0,    0,    0,    0,    0,  352,  641,    0,    0,
    0,    0,    0,    0,  352,    0,    0,    0,    0,  641,
  641,  641,  641,  641,  641,  641,  641,    0,    0,  355,
  355,  352,  352,  352,    0,    0,    0,    0,  355,  355,
  355,  355,  355,  355,  355,  355,    0,    0,    0,    0,
    0,    0,    0,    0,  355,  641,  641,    0,    0,    0,
    0,    0,    0,  355,  355,  355,    0,    0,  355,    0,
    0,    0,    0,    0,    0,    0,    0,  355,    0,    0,
  355,    0,    0,    0,  355,    0,    0,    0,  355,  355,
    0,  352,  352,    0,    0,  352,    0,    0,  355,  352,
  352,  352,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  641,  355,  355,  352,  352,  352,  352,  352,
  355,    0,    0,    0,    0,    0,    0,    0,    0,  355,
  355,    0,  355,    0,    0,    0,    0,    0,    0,  355,
    0,    0,    0,    0,    0,    0,  355,    0,  355,  355,
  355,  355,  355,  355,  355,  355,    0,  355,  355,  355,
  355,  355,  355,  355,  355,  355,    0,    0,  355,  355,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  355,    0,    0,
  355,  355,    0,    0,  355,  355,  355,    0,  355,  355,
    0,  355,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  355,
  355,    0,  355,  355,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  355,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  355,    0,
    0,  641,  355,    0,    0,    0,    0,    0,    0,    0,
  355,  355,    0,  355,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  355,  355,  355,    0,
    0,  355,  355,  355,  355,  355,  355,  355,  355,    0,
    0,    0,    0,    0,    0,  355,    0,    0,    0,    0,
    0,    0,    0,  355,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  358,  358,
  355,  355,  355,    0,    0,    0,    0,  358,  358,  358,
  358,  358,  358,  358,  358,    0,    0,    0,    0,    0,
    0,    0,    0,  358,    0,    0,    0,    0,    0,    0,
    0,    0,  358,  358,  358,    0,    0,  358,    0,    0,
    0,    0,    0,    0,    0,    0,  358,    0,    0,  358,
    0,    0,    0,  358,    0,    0,    0,  358,  358,    0,
  355,  355,    0,    0,  355,    0,    0,  358,  355,  355,
  355,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  358,  358,  355,  355,  355,  355,  355,  358,
    0,    0,    0,    0,    0,    0,    0,    0,  358,  358,
    0,  358,    0,    0,    0,    0,    0,    0,  358,    0,
    0,    0,    0,    0,    0,  358,    0,  358,  358,  358,
  358,  358,  358,  358,  358,    0,  358,  358,  358,  358,
  358,  358,  358,  358,  358,    0,    0,  358,  358,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  358,    0,    0,  358,
  358,    0,    0,  358,  358,  358,    0,  358,  358,    0,
  358,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  358,  358,
    0,  358,  358,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  358,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  358,    0,    0,
    0,  358,    0,    0,    0,    0,    0,    0,    0,  358,
  358,    0,  358,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  358,  358,  358,    0,    0,
  358,  358,  358,  358,  358,  358,  358,  358,    0,    0,
    0,    0,    0,    0,  358,    0,    0,    0,    0,    0,
    0,    0,  358,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  361,  361,  358,
  358,  358,    0,    0,    0,    0,  361,  361,  361,  361,
  361,  361,  361,  361,    0,    0,    0,    0,    0,    0,
    0,    0,  361,    0,    0,    0,    0,    0,    0,    0,
    0,  361,  361,  361,    0,    0,  361,    0,    0,    0,
    0,    0,    0,    0,    0,  361,    0,    0,  361,    0,
    0,    0,  361,    0,    0,    0,  361,  361,    0,  358,
  358,    0,    0,  358,    0,    0,  361,  358,  358,  358,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  361,  361,  358,  358,  358,  358,  358,  361,    0,
    0,    0,    0,    0,    0,    0,    0,  361,  361,    0,
  361,    0,    0,    0,    0,    0,    0,  361,    0,    0,
    0,    0,    0,    0,  361,    0,  361,  361,  361,  361,
  361,  361,  361,  361,    0,  361,  361,  361,  361,  361,
  361,  361,  361,  361,    0,    0,  361,  361,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  361,    0,    0,  361,  361,
    0,    0,  361,  361,  361,    0,  361,  361,    0,  361,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  361,  361,    0,
  361,  361,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  361,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  361,    0,    0,    0,
  361,    0,    0,    0,    0,    0,    0,    0,  361,  361,
    0,  361,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  361,  361,  361,    0,    0,  361,
  361,  361,  361,  361,  361,  361,  361,    0,    0,    0,
    0,    0,    0,  361,    0,    0,    0,    0,    0,    0,
    0,  361,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  364,  364,  361,  361,
  361,    0,    0,    0,    0,  364,  364,  364,  364,  364,
  364,  364,  364,    0,    0,    0,    0,    0,    0,    0,
    0,  364,    0,    0,    0,    0,    0,    0,    0,    0,
  364,  364,  364,    0,    0,  364,    0,    0,    0,    0,
    0,    0,    0,    0,  364,    0,    0,  364,    0,    0,
    0,  364,    0,    0,    0,  364,  364,    0,  361,  361,
    0,    0,  361,    0,    0,  364,  361,  361,  361,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  364,  364,  361,  361,  361,  361,  361,  364,    0,    0,
    0,    0,    0,    0,    0,    0,  364,  364,    0,  364,
    0,    0,    0,    0,    0,    0,  364,    0,    0,    0,
    0,    0,    0,  364,    0,  364,  364,  364,  364,  364,
  364,  364,  364,    0,  364,  364,  364,  364,  364,  364,
  364,  364,  364,    0,    0,  364,  364,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  364,    0,    0,  364,  364,    0,
    0,  364,  364,  364,    0,  364,  364,    0,  364,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  364,  364,    0,  364,
  364,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  364,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  364,    0,    0,    0,  364,
    0,    0,    0,    0,    0,    0,    0,  364,  364,    0,
  364,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  364,  364,  364,    0,    0,  364,  364,
  364,  364,  364,  364,  364,  364,    0,    0,    0,    0,
    0,    0,  364,    0,    0,    0,    0,    0,    0,    0,
  364,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  377,  377,  364,  364,  364,
    0,    0,    0,    0,  377,  377,  377,  377,  377,  377,
  377,  377,    0,    0,    0,    0,    0,    0,    0,    0,
  377,    0,    0,    0,    0,    0,    0,    0,    0,  377,
  377,  377,    0,    0,  377,    0,    0,    0,    0,    0,
    0,    0,    0,  377,    0,    0,  377,    0,    0,    0,
  377,    0,    0,    0,  377,  377,    0,  364,  364,    0,
    0,  364,    0,    0,  377,  364,  364,  364,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  377,
  377,  364,  364,  364,  364,  364,  377,    0,    0,    0,
    0,    0,    0,    0,    0,  377,  377,    0,  377,    0,
    0,    0,    0,    0,    0,  377,    0,    0,    0,    0,
    0,    0,  377,    0,  377,  377,  377,  377,  377,  377,
  377,  377,    0,  377,  377,  377,  377,  377,  377,  377,
  377,  377,    0,    0,  377,  377,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  377,    0,    0,  377,  377,    0,    0,
  377,  377,  377,    0,  377,  377,    0,  377,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  377,  377,    0,  377,  377,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  377,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  377,    0,    0,    0,  377,    0,
    0,    0,    0,    0,    0,    0,  377,  377,    0,  377,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  377,  377,  377,    0,    0,  377,  377,  377,
  377,  377,  377,  377,  377,    0,    0,    0,    0,    0,
    0,  377,    0,    0,    0,    0,    0,    0,    0,  377,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  383,  383,  377,  377,  377,    0,
    0,    0,    0,  383,  383,  383,  383,  383,  383,  383,
  383,    0,    0,    0,    0,    0,    0,    0,    0,  383,
    0,    0,    0,    0,    0,    0,    0,    0,  383,  383,
  383,    0,    0,  383,    0,    0,    0,    0,    0,    0,
    0,    0,  383,    0,    0,  383,    0,    0,    0,  383,
    0,    0,    0,  383,  383,    0,  377,  377,    0,    0,
  377,    0,    0,  383,  377,  377,  377,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  383,  383,
  377,  377,  377,  377,  377,  383,    0,    0,    0,    0,
    0,    0,    0,    0,  383,  383,    0,  383,    0,    0,
    0,    0,    0,    0,  383,    0,    0,    0,    0,    0,
    0,  383,    0,  383,  383,  383,  383,  383,  383,  383,
  383,    0,  383,  383,  383,  383,  383,  383,  383,  383,
  383,    0,    0,  383,  383,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  383,    0,    0,  383,  383,    0,    0,  383,
  383,  383,    0,  383,  383,    0,  383,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  383,  383,    0,  383,  383,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  383,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  383,    0,    0,    0,  383,    0,    0,
    0,    0,    0,    0,    0,  383,  383,    0,  383,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  383,  383,  383,    0,    0,  383,  383,  383,  383,
  383,  383,  383,  383,    0,    0,    0,    0,    0,    0,
  383,    0,    0,    0,    0,    0,    0,    0,  383,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  406,  406,  383,  383,  383,    0,    0,
    0,    0,  406,  406,  406,  406,  406,  406,  406,  406,
    0,    0,    0,    0,    0,    0,    0,    0,  406,    0,
    0,    0,    0,    0,    0,    0,    0,  406,  406,  406,
    0,    0,  406,    0,    0,    0,    0,    0,    0,    0,
    0,  406,    0,    0,  406,    0,    0,    0,  406,    0,
    0,    0,  406,  406,    0,  383,  383,    0,    0,  383,
    0,    0,  406,  383,  383,  383,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  406,  406,  383,
  383,  383,  383,  383,  406,    0,    0,    0,    0,    0,
    0,    0,    0,  406,  406,    0,  406,    0,    0,    0,
    0,    0,    0,  406,    0,    0,    0,    0,    0,    0,
  406,    0,  406,  406,  406,  406,  406,  406,  406,  406,
    0,  406,  406,  406,  406,  406,  406,  406,  406,  406,
    0,    0,  406,  406,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  406,    0,    0,  406,  406,    0,    0,  406,  406,
  406,    0,  406,  406,    0,  406,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  406,  406,    0,  406,  406,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  406,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  406,    0,    0,    0,  406,    0,    0,    0,
    0,    0,    0,    0,  406,  406,    0,  406,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  406,  406,  406,    0,    0,  406,  406,  406,  406,  406,
  406,  406,  406,    0,    0,    0,    0,    0,    0,  406,
    0,    0,    0,    0,    0,    0,    0,  406,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  412,  412,  406,  406,  406,    0,    0,    0,
    0,  412,  412,  412,  412,  412,  412,  412,  412,    0,
    0,    0,    0,    0,    0,    0,    0,  412,    0,    0,
    0,    0,    0,    0,    0,    0,  412,  412,  412,    0,
    0,  412,    0,    0,    0,    0,    0,    0,    0,    0,
  412,    0,    0,  412,    0,    0,    0,  412,    0,    0,
    0,  412,  412,    0,  406,  406,    0,    0,  406,    0,
    0,  412,  406,  406,  406,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  412,  412,  406,  406,
  406,  406,  406,  412,    0,    0,    0,    0,    0,    0,
    0,    0,  412,  412,    0,  412,    0,    0,    0,    0,
    0,    0,  412,    0,    0,    0,    0,    0,    0,  412,
    0,  412,  412,  412,  412,  412,  412,  412,  412,    0,
  412,  412,  412,  412,  412,  412,  412,  412,  412,    0,
    0,  412,  412,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  412,    0,    0,  412,  412,    0,    0,  412,  412,  412,
    0,  412,  412,    0,  412,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  412,  412,    0,  412,  412,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  412,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  412,    0,    0,    0,  412,    0,    0,    0,    0,
    0,    0,    0,  412,  412,    0,  412,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  412,
  412,  412,    0,    0,  412,  412,  412,  412,  412,  412,
  412,  412,    0,    0,    0,    0,    0,    0,  412,    0,
    0,    0,    0,    0,    0,    0,  412,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  415,  415,  412,  412,  412,    0,    0,    0,    0,
  415,  415,  415,  415,  415,  415,  415,  415,    0,    0,
    0,    0,    0,    0,    0,    0,  415,    0,    0,    0,
    0,    0,    0,    0,    0,  415,  415,  415,    0,    0,
  415,    0,    0,    0,    0,    0,    0,    0,    0,  415,
    0,    0,  415,    0,    0,    0,  415,    0,    0,    0,
  415,  415,    0,  412,  412,    0,    0,  412,    0,    0,
  415,  412,  412,  412,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  415,  415,  412,  412,  412,
  412,  412,  415,    0,    0,    0,    0,    0,    0,    0,
    0,  415,  415,    0,  415,    0,    0,    0,    0,    0,
    0,  415,    0,    0,    0,    0,    0,    0,  415,    0,
  415,  415,  415,  415,  415,  415,  415,  415,    0,  415,
  415,  415,  415,  415,  415,  415,  415,  415,    0,    0,
  415,  415,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  415,
    0,    0,  415,  415,    0,    0,  415,  415,  415,    0,
  415,  415,    0,  415,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  415,  415,    0,  415,  415,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  415,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  415,    0,    0,    0,  415,    0,    0,    0,    0,    0,
    0,    0,  415,  415,    0,  415,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  415,  415,
  415,    0,    0,  415,  415,  415,  415,  415,  415,  415,
  415,    0,    0,    0,    0,    0,    0,  415,    0,    0,
    0,    0,    0,    0,    0,  415,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  428,  428,  415,  415,  415,    0,    0,    0,    0,  428,
  428,  428,  428,  428,  428,  428,  428,    0,    0,    0,
    0,    0,    0,    0,    0,  428,    0,    0,    0,    0,
    0,    0,    0,    0,  428,  428,  428,    0,    0,  428,
    0,    0,    0,    0,    0,    0,    0,    0,  428,    0,
    0,  428,    0,    0,    0,  428,    0,    0,    0,  428,
  428,    0,  415,  415,    0,    0,  415,    0,    0,  428,
  415,  415,  415,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  428,  428,  415,  415,  415,  415,
  415,  428,    0,    0,    0,    0,    0,    0,    0,    0,
  428,  428,    0,  428,    0,    0,    0,    0,    0,    0,
  428,    0,    0,    0,    0,    0,    0,  428,    0,  428,
  428,  428,  428,  428,  428,  428,  428,    0,  428,  428,
  428,  428,  428,  428,  428,  428,  428,    0,    0,  428,
  428,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  428,    0,
    0,  428,  428,    0,    0,  428,  428,  428,    0,  428,
  428,    0,  428,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  428,  428,    0,  428,  428,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  428,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  428,
    0,    0,    0,  428,    0,    0,    0,    0,    0,    0,
    0,  428,  428,    0,  428,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  428,  428,  428,
    0,    0,  428,  428,  428,  428,  428,  428,  428,  428,
    0,    0,    0,    0,    0,    0,  428,    0,    0,    0,
    0,    0,    0,    0,  428,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  435,
  435,  428,  428,  428,    0,    0,    0,    0,  435,  435,
  435,  435,  435,  435,  435,  435,    0,    0,    0,    0,
    0,    0,    0,    0,  435,    0,    0,    0,    0,    0,
    0,    0,    0,  435,  435,  435,    0,    0,  435,    0,
    0,    0,    0,    0,    0,    0,    0,  435,    0,    0,
  435,    0,    0,    0,  435,    0,    0,    0,  435,  435,
    0,  428,  428,    0,    0,  428,    0,    0,  435,  428,
  428,  428,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  435,  435,  428,  428,  428,  428,  428,
  435,    0,    0,    0,    0,    0,    0,    0,    0,  435,
  435,    0,  435,    0,    0,    0,    0,    0,    0,  435,
    0,    0,    0,    0,    0,    0,  435,    0,  435,  435,
  435,  435,  435,  435,  435,  435,    0,  435,  435,  435,
  435,  435,  435,  435,  435,  435,    0,    0,  435,  435,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  435,    0,    0,
  435,  435,    0,    0,  435,  435,  435,    0,  435,  435,
    0,  435,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  435,
  435,    0,  435,  435,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  435,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  435,    0,
    0,    0,  435,    0,    0,    0,    0,    0,    0,    0,
  435,  435,    0,  435,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  435,  435,  435,    0,
    0,  435,  435,  435,  435,  435,  435,  435,  435,    0,
    0,    0,    0,    0,    0,  435,    0,    0,    0,    0,
    0,    0,    0,  435,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  446,  446,
  435,  435,  435,    0,    0,    0,    0,  446,  446,  446,
  446,  446,  446,  446,  446,    0,    0,    0,    0,    0,
    0,    0,    0,  446,    0,    0,    0,    0,    0,    0,
    0,    0,  446,  446,  446,    0,    0,  446,    0,    0,
    0,    0,    0,    0,    0,    0,  446,    0,    0,  446,
    0,    0,    0,  446,    0,    0,    0,  446,  446,    0,
  435,  435,    0,    0,  435,    0,    0,  446,  435,  435,
  435,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  446,  446,  435,  435,  435,  435,  435,  446,
    0,    0,    0,    0,    0,    0,    0,    0,  446,  446,
    0,  446,    0,    0,    0,    0,    0,    0,  446,    0,
    0,    0,    0,    0,    0,  446,    0,  446,  446,  446,
  446,  446,  446,  446,  446,    0,  446,  446,  446,  446,
  446,  446,  446,  446,  446,    0,    0,  446,  446,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  446,    0,    0,  446,
  446,    0,    0,  446,  446,  446,    0,  446,  446,    0,
  446,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  446,  446,
    0,  446,  446,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  446,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  446,    0,    0,
    0,  446,    0,    0,    0,    0,    0,    0,    0,  446,
  446,    0,  446,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  446,  446,  446,    0,    0,
  446,  446,  446,  446,  446,  446,  446,  446,    0,    0,
    0,    0,    0,    0,  446,    0,    0,    0,    0,    0,
    0,    0,  446,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  449,  449,  446,
  446,  446,    0,    0,    0,    0,  449,  449,  449,  449,
  449,  449,  449,  449,    0,    0,    0,    0,    0,    0,
    0,    0,  449,    0,    0,    0,    0,    0,    0,    0,
    0,  449,  449,  449,    0,    0,  449,    0,    0,    0,
    0,    0,    0,    0,    0,  449,    0,    0,  449,    0,
    0,    0,  449,    0,    0,    0,  449,  449,    0,  446,
  446,    0,    0,  446,    0,    0,  449,  446,  446,  446,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  449,  449,  446,  446,  446,  446,  446,  449,    0,
    0,    0,    0,    0,    0,    0,    0,  449,  449,    0,
  449,    0,    0,    0,    0,    0,    0,  449,    0,    0,
    0,    0,    0,    0,  449,    0,  449,  449,  449,  449,
  449,  449,  449,  449,    0,  449,  449,  449,  449,  449,
  449,  449,  449,  449,    0,    0,  449,  449,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  449,    0,    0,  449,  449,
    0,    0,  449,  449,  449,    0,  449,  449,    0,  449,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  449,  449,    0,
  449,  449,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  449,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  449,    0,    0,    0,
  449,    0,    0,    0,    0,    0,    0,    0,  449,  449,
    0,  449,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  449,  449,  449,    0,    0,  449,
  449,  449,  449,  449,  449,  449,  449,    0,    0,    0,
    0,    0,    0,  449,    0,    0,    0,    0,    0,    0,
    0,  449,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  452,  452,  449,  449,
  449,    0,    0,    0,    0,  452,  452,  452,  452,  452,
  452,  452,  452,    0,    0,    0,    0,    0,    0,    0,
    0,  452,    0,    0,    0,    0,    0,    0,    0,    0,
  452,  452,  452,    0,    0,  452,    0,    0,    0,    0,
    0,    0,    0,    0,  452,    0,    0,  452,    0,    0,
    0,  452,    0,    0,    0,  452,  452,    0,  449,  449,
    0,    0,  449,    0,    0,  452,  449,  449,  449,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  452,  452,  449,  449,  449,  449,  449,  452,    0,    0,
    0,    0,    0,    0,    0,    0,  452,  452,    0,  452,
    0,    0,    0,    0,    0,    0,  452,    0,    0,    0,
    0,    0,    0,  452,    0,  452,  452,  452,  452,  452,
  452,  452,  452,    0,  452,  452,  452,  452,  452,  452,
  452,  452,  452,    0,    0,  452,  452,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  452,    0,    0,  452,  452,    0,
    0,  452,  452,  452,    0,  452,  452,    0,  452,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  452,  452,    0,  452,
  452,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  452,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  452,    0,    0,    0,  452,
    0,    0,    0,    0,    0,    0,    0,  452,  452,    0,
  452,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  452,  452,  452,    0,    0,  452,  452,
  452,  452,  452,  452,  452,  452,    0,    0,    0,    0,
    0,    0,  452,    0,    0,    0,    0,    0,    0,    0,
  452,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  458,  458,  452,  452,  452,
    0,    0,    0,    0,  458,  458,  458,  458,  458,  458,
  458,  458,    0,    0,    0,    0,    0,    0,    0,    0,
  458,    0,    0,    0,    0,    0,    0,    0,    0,  458,
  458,  458,    0,    0,  458,    0,    0,    0,    0,    0,
    0,    0,    0,  458,    0,    0,  458,    0,    0,    0,
  458,    0,    0,    0,  458,  458,    0,  452,  452,    0,
    0,  452,    0,    0,  458,  452,  452,  452,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  458,
  458,  452,  452,  452,  452,  452,  458,    0,    0,    0,
    0,    0,    0,    0,    0,  458,  458,    0,  458,    0,
    0,    0,    0,    0,    0,  458,    0,    0,    0,    0,
    0,    0,  458,    0,  458,  458,  458,  458,  458,  458,
  458,  458,    0,  458,  458,  458,  458,  458,  458,  458,
  458,  458,    0,    0,  458,  458,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  458,    0,    0,  458,  458,    0,    0,
  458,  458,  458,    0,  458,  458,    0,  458,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  458,  458,    0,  458,  458,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  458,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  458,    0,    0,    0,  458,    0,
    0,    0,    0,    0,    0,    0,  458,  458,    0,  458,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  458,  458,  458,    0,    0,  458,  458,  458,
  458,  458,  458,  458,  458,    0,    0,    0,    0,    0,
    0,  458,    0,    0,    0,    0,    0,    0,    0,  458,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  455,  455,  458,  458,  458,    0,
    0,    0,    0,  455,  455,  455,  455,  455,  455,  455,
  455,    0,    0,    0,    0,    0,    0,    0,    0,  455,
    0,    0,    0,    0,    0,    0,    0,    0,  455,  455,
  455,    0,    0,  455,    0,    0,    0,    0,    0,    0,
    0,    0,  455,    0,    0,  455,    0,    0,    0,  455,
    0,    0,    0,  455,  455,    0,  458,  458,    0,    0,
  458,    0,    0,  455,  458,  458,  458,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  455,  455,
  458,  458,  458,  458,  458,  455,    0,    0,    0,    0,
    0,    0,    0,    0,  455,  455,    0,  455,    0,    0,
    0,    0,    0,    0,  455,    0,    0,    0,    0,    0,
    0,  455,    0,  455,  455,  455,  455,  455,  455,  455,
  455,    0,  455,  455,  455,  455,  455,  455,  455,  455,
  455,    0,    0,  455,  455,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  455,    0,    0,  455,  455,    0,    0,  455,
  455,  455,    0,  455,  455,    0,  455,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  455,  455,    0,  455,  455,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  455,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  455,    0,    0,    0,  455,    0,    0,
    0,    0,    0,    0,    0,  455,  455,    0,  455,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  455,  455,  455,    0,    0,  455,  455,  455,  455,
  455,  455,  455,  455,    0,    0,    0,    0,    0,    0,
  455,    0,    0,    0,    0,    0,    0,    0,  455,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  464,  464,  455,  455,  455,    0,    0,
    0,    0,  464,  464,  464,  464,  464,  464,  464,  464,
    0,    0,    0,    0,    0,    0,    0,    0,  464,    0,
    0,    0,    0,    0,    0,    0,    0,  464,  464,  464,
    0,    0,  464,    0,    0,    0,    0,    0,    0,    0,
    0,  464,    0,    0,  464,    0,    0,    0,  464,    0,
    0,    0,  464,  464,    0,  455,  455,    0,    0,  455,
    0,    0,  464,  455,  455,  455,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  464,  464,  455,
  455,  455,  455,  455,  464,    0,    0,    0,    0,    0,
    0,    0,    0,  464,  464,    0,  464,    0,    0,    0,
    0,    0,    0,  464,    0,    0,    0,    0,    0,    0,
  464,    0,  464,  464,  464,  464,  464,  464,  464,  464,
    0,  464,  464,  464,  464,  464,  464,  464,  464,  464,
    0,    0,  464,  464,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  464,    0,    0,  464,  464,    0,    0,  464,  464,
  464,    0,  464,  464,    0,  464,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  464,  464,    0,  464,  464,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  464,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  464,    0,    0,    0,  464,    0,    0,    0,
    0,    0,    0,    0,  464,  464,    0,  464,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  464,  464,  464,    0,    0,  464,  464,  464,  464,  464,
  464,  464,  464,    0,    0,    0,    0,    0,    0,  464,
    0,    0,    0,    0,    0,    0,    0,  464,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  461,  461,  464,  464,  464,    0,    0,    0,
    0,  461,  461,  461,  461,  461,  461,  461,  461,    0,
    0,    0,    0,    0,    0,    0,    0,  461,    0,    0,
    0,    0,    0,    0,    0,    0,  461,  461,  461,    0,
    0,  461,    0,    0,    0,    0,    0,    0,    0,    0,
  461,    0,    0,  461,    0,    0,    0,  461,    0,    0,
    0,  461,  461,    0,  464,  464,    0,    0,  464,    0,
    0,  461,  464,  464,  464,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  461,  461,  464,  464,
  464,  464,  464,  461,    0,    0,    0,    0,    0,    0,
    0,    0,  461,  461,    0,  461,    0,    0,    0,    0,
    0,    0,  461,    0,    0,    0,    0,    0,    0,  461,
    0,  461,  461,  461,  461,  461,  461,  461,  461,    0,
  461,  461,  461,  461,  461,  461,  461,  461,  461,    0,
    0,  461,  461,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  461,    0,    0,  461,  461,    0,    0,  461,  461,  461,
    0,  461,  461,    0,  461,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  461,  461,    0,  461,  461,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  461,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  461,    0,    0,    0,  461,    0,    0,    0,    0,
    0,    0,    0,  461,  461,    0,  461,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  461,
  461,  461,    0,    0,  461,  461,  461,  461,  461,  461,
  461,  461,    0,    0,    0,    0,    0,    0,  461,    0,
    0,    0,    0,    0,    0,    0,  461,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  470,  470,  461,  461,  461,    0,    0,    0,    0,
  470,  470,  470,  470,  470,  470,  470,  470,    0,    0,
    0,    0,    0,    0,    0,    0,  470,    0,    0,    0,
    0,    0,    0,    0,    0,  470,  470,  470,    0,    0,
  470,    0,    0,    0,    0,    0,    0,    0,    0,  470,
    0,    0,  470,    0,    0,    0,  470,    0,    0,    0,
  470,  470,    0,  461,  461,    0,    0,  461,    0,    0,
  470,  461,  461,  461,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  470,  470,  461,  461,  461,
  461,  461,  470,    0,    0,    0,    0,    0,    0,    0,
    0,  470,  470,    0,  470,    0,    0,    0,    0,    0,
    0,  470,    0,    0,    0,    0,    0,    0,  470,    0,
  470,  470,  470,  470,  470,  470,  470,  470,    0,  470,
  470,  470,  470,  470,  470,  470,  470,  470,    0,    0,
  470,  470,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  470,
    0,    0,  470,  470,    0,    0,  470,  470,  470,    0,
  470,  470,    0,  470,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  470,  470,    0,  470,  470,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  470,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  470,    0,    0,    0,  470,    0,    0,    0,    0,    0,
    0,    0,  470,  470,    0,  470,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  470,  470,
  470,    0,    0,  470,  470,  470,  470,  470,  470,  470,
  470,    0,    0,    0,    0,    0,    0,  470,    0,    0,
    0,    0,    0,    0,    0,  470,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  467,  467,  470,  470,  470,    0,    0,    0,    0,  467,
  467,  467,  467,  467,  467,  467,  467,    0,    0,    0,
    0,    0,    0,    0,    0,  467,    0,    0,    0,    0,
    0,    0,    0,    0,  467,  467,  467,    0,    0,  467,
    0,    0,    0,    0,    0,    0,    0,    0,  467,    0,
    0,  467,    0,    0,    0,  467,    0,    0,    0,  467,
  467,    0,  470,  470,    0,    0,  470,    0,    0,  467,
  470,  470,  470,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  467,  467,  470,  470,  470,  470,
  470,  467,    0,    0,    0,    0,    0,    0,    0,    0,
  467,  467,    0,  467,    0,    0,    0,    0,    0,    0,
  467,    0,    0,    0,    0,    0,    0,  467,    0,  467,
  467,  467,  467,  467,  467,  467,  467,    0,  467,  467,
  467,  467,  467,  467,  467,  467,  467,    0,    0,  467,
  467,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  467,    0,
    0,  467,  467,    0,    0,  467,  467,  467,    0,  467,
  467,    0,  467,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  467,  467,    0,  467,  467,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  467,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  467,
    0,    0,    0,  467,    0,    0,    0,    0,    0,    0,
    0,  467,  467,    0,  467,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  467,  467,  467,
    0,    0,  467,  467,  467,  467,  467,  467,  467,  467,
    0,    0,    0,    0,    0,    0,  467,    0,    0,    0,
    0,    0,    0,    0,  467,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  473,
  473,  467,  467,  467,    0,    0,    0,    0,  473,  473,
  473,  473,  473,  473,  473,  473,    0,    0,    0,    0,
    0,    0,    0,    0,  473,    0,    0,    0,    0,    0,
    0,    0,    0,  473,  473,  473,    0,    0,  473,    0,
    0,    0,    0,    0,    0,    0,    0,  473,    0,    0,
  473,    0,    0,    0,  473,    0,    0,    0,  473,  473,
    0,  467,  467,    0,    0,  467,    0,    0,  473,  467,
  467,  467,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  473,  473,  467,  467,  467,  467,  467,
  473,    0,    0,    0,    0,    0,    0,    0,    0,  473,
  473,    0,  473,    0,    0,    0,    0,    0,    0,  473,
    0,    0,    0,    0,    0,    0,  473,    0,  473,  473,
  473,  473,  473,  473,  473,  473,    0,  473,  473,  473,
  473,  473,  473,  473,  473,  473,    0,    0,  473,  473,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  473,    0,    0,
  473,  473,    0,    0,  473,  473,  473,    0,  473,  473,
    0,  473,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  473,
  473,    0,  473,  473,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  473,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  473,    0,
    0,    0,  473,    0,    0,    0,    0,    0,    0,    0,
  473,  473,    0,  473,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  473,  473,  473,    0,
    0,  473,  473,  473,  473,  473,  473,  473,  473,    0,
    0,    0,    0,    0,    0,  473,    0,    0,    0,    0,
    0,    0,    0,  473,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  487,  487,
  473,  473,  473,    0,    0,    0,    0,  487,  487,  487,
  487,  487,  487,  487,  487,    0,    0,    0,    0,    0,
    0,    0,    0,  487,    0,    0,    0,    0,    0,    0,
    0,    0,  487,  487,  487,    0,    0,  487,    0,    0,
    0,    0,    0,    0,    0,    0,  487,    0,    0,  487,
    0,    0,    0,  487,    0,    0,    0,  487,  487,    0,
  473,  473,    0,    0,  473,    0,    0,  487,  473,  473,
  473,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  487,  487,  473,  473,  473,  473,  473,  487,
    0,    0,    0,    0,    0,    0,    0,    0,  487,  487,
    0,  487,    0,    0,    0,    0,    0,    0,  487,    0,
    0,    0,    0,    0,    0,  487,    0,  487,  487,  487,
  487,  487,  487,  487,  487,    0,  487,  487,  487,  487,
  487,  487,  487,  487,  487,    0,    0,  487,  487,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  487,    0,    0,  487,
  487,    0,    0,  487,  487,  487,    0,  487,  487,    0,
  487,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  487,  487,
    0,  487,  487,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  487,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  487,    0,    0,
    0,  487,    0,    0,    0,    0,    0,    0,    0,  487,
  487,    0,  487,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  487,  487,  487,    0,    0,
  487,  487,  487,  487,  487,  487,  487,  487,    0,    0,
    0,    0,    0,    0,  487,    0,    0,    0,    0,    0,
    0,    0,  487,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  490,  490,  487,
  487,  487,    0,    0,    0,    0,  490,  490,  490,  490,
  490,  490,  490,  490,    0,    0,    0,    0,    0,    0,
    0,    0,  490,    0,    0,    0,    0,    0,    0,    0,
    0,  490,  490,  490,    0,    0,  490,    0,    0,    0,
    0,    0,    0,    0,    0,  490,    0,    0,  490,    0,
    0,    0,  490,    0,    0,    0,  490,  490,    0,  487,
  487,    0,    0,  487,    0,    0,  490,  487,  487,  487,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  490,  490,  487,  487,  487,  487,  487,  490,    0,
    0,    0,    0,    0,    0,    0,    0,  490,  490,    0,
  490,    0,    0,    0,    0,    0,    0,  490,    0,    0,
    0,    0,    0,    0,  490,    0,  490,  490,  490,  490,
  490,  490,  490,  490,    0,  490,  490,  490,  490,  490,
  490,  490,  490,  490,    0,    0,  490,  490,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  490,    0,    0,  490,  490,
    0,    0,  490,  490,  490,    0,  490,  490,    0,  490,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  490,  490,    0,
  490,  490,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  490,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  490,    0,    0,    0,
  490,    0,    0,    0,    0,    0,    0,    0,  490,  490,
    0,  490,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  490,  490,  490,    0,    0,  490,
  490,  490,  490,  490,  490,  490,  490,    0,    0,    0,
    0,    0,    0,  490,    0,    0,    0,    0,    0,    0,
    0,  490,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  498,  498,  490,  490,
  490,    0,    0,    0,    0,  498,  498,  498,  498,  498,
  498,  498,  498,    0,    0,    0,    0,    0,    0,    0,
    0,  498,    0,    0,    0,    0,    0,    0,    0,    0,
  498,  498,  498,    0,    0,  498,    0,    0,    0,    0,
    0,    0,    0,    0,  498,    0,    0,  498,    0,    0,
    0,  498,    0,    0,    0,  498,  498,    0,  490,  490,
    0,    0,  490,    0,    0,  498,  490,  490,  490,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  498,  498,  490,  490,  490,  490,  490,  498,    0,    0,
    0,    0,    0,    0,    0,    0,  498,  498,    0,  498,
    0,    0,    0,    0,    0,    0,  498,    0,    0,    0,
    0,    0,    0,  498,    0,  498,  498,  498,  498,  498,
  498,  498,  498,    0,  498,  498,  498,  498,  498,  498,
  498,  498,  498,    0,    0,  498,  498,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  498,    0,    0,  498,  498,    0,
    0,  498,  498,  498,    0,  498,  498,    0,  498,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  498,  498,    0,  498,
  498,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  498,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  498,    0,    0,    0,  498,
    0,    0,    0,    0,    0,    0,    0,  498,  498,    0,
  498,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  498,  498,  498,    0,    0,  498,  498,
  498,  498,  498,  498,  498,  498,    0,    0,    0,    0,
    0,    0,  498,    0,    0,    0,    0,    0,    0,    0,
  498,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  501,  501,  498,  498,  498,
    0,    0,    0,    0,  501,  501,  501,  501,  501,  501,
  501,  501,    0,    0,    0,    0,    0,    0,    0,    0,
  501,    0,    0,    0,    0,    0,    0,    0,    0,  501,
  501,  501,    0,    0,  501,    0,    0,    0,    0,    0,
    0,    0,    0,  501,    0,    0,  501,    0,    0,    0,
  501,    0,    0,    0,  501,  501,    0,  498,  498,    0,
    0,  498,    0,    0,  501,  498,  498,  498,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  501,
  501,  498,  498,  498,  498,  498,  501,    0,    0,    0,
    0,    0,    0,    0,    0,  501,  501,    0,  501,    0,
    0,    0,    0,    0,    0,  501,    0,    0,    0,    0,
    0,    0,  501,    0,  501,  501,  501,  501,  501,  501,
  501,  501,    0,  501,  501,  501,  501,  501,  501,  501,
  501,  501,    0,    0,  501,  501,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  501,    0,    0,  501,  501,    0,    0,
  501,  501,  501,    0,  501,  501,    0,  501,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  501,  501,    0,  501,  501,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  501,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  501,    0,    0,    0,  501,    0,
    0,    0,    0,    0,    0,    0,  501,  501,    0,  501,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  501,  501,  501,    0,    0,  501,  501,  501,
  501,  501,  501,  501,  501,    0,    0,    0,    0,    0,
    0,  501,    0,    0,    0,    0,    0,    0,    0,  501,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  504,  504,  501,  501,  501,    0,
    0,    0,    0,  504,  504,  504,  504,  504,  504,  504,
  504,    0,    0,    0,    0,    0,    0,    0,    0,  504,
    0,    0,    0,    0,    0,    0,    0,    0,  504,  504,
  504,    0,    0,  504,    0,    0,    0,    0,    0,    0,
    0,    0,  504,    0,    0,  504,    0,    0,    0,  504,
    0,    0,    0,  504,  504,    0,  501,  501,    0,    0,
  501,    0,    0,  504,  501,  501,  501,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  504,  504,
  501,  501,  501,  501,  501,  504,    0,    0,    0,    0,
    0,    0,    0,    0,  504,  504,    0,  504,    0,    0,
    0,    0,    0,    0,  504,    0,    0,    0,    0,    0,
    0,  504,    0,  504,  504,  504,  504,  504,  504,  504,
  504,    0,  504,  504,  504,  504,  504,  504,  504,  504,
  504,    0,    0,  504,  504,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  504,    0,    0,  504,  504,    0,    0,  504,
  504,  504,    0,  504,  504,    0,  504,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  504,  504,    0,  504,  504,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  504,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  504,    0,    0,    0,  504,    0,    0,
    0,    0,    0,    0,    0,  504,  504,    0,  504,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  504,  504,  504,    0,    0,  504,  504,  504,  504,
  504,  504,  504,  504,    0,    0,    0,    0,    0,    0,
  504,    0,    0,    0,    0,    0,    0,    0,  504,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  513,  513,  504,  504,  504,    0,    0,
    0,    0,  513,  513,  513,  513,  513,  513,  513,  513,
    0,    0,    0,    0,    0,    0,    0,    0,  513,    0,
    0,    0,    0,    0,    0,    0,    0,  513,  513,  513,
    0,    0,  513,    0,    0,    0,    0,    0,    0,    0,
    0,  513,    0,    0,  513,    0,    0,    0,  513,    0,
    0,    0,  513,  513,    0,  504,  504,    0,    0,  504,
    0,    0,  513,  504,  504,  504,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  513,  513,  504,
  504,  504,  504,  504,  513,    0,    0,    0,    0,    0,
    0,    0,    0,  513,  513,    0,  513,    0,    0,    0,
    0,    0,    0,  513,    0,    0,    0,    0,    0,    0,
  513,    0,  513,  513,  513,  513,  513,  513,  513,  513,
    0,  513,  513,  513,  513,  513,  513,  513,  513,  513,
    0,    0,  513,  513,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  513,    0,    0,  513,  513,    0,    0,  513,  513,
  513,    0,  513,  513,    0,  513,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  513,  513,    0,  513,  513,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  513,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  513,    0,    0,    0,  513,    0,    0,    0,
    0,    0,    0,    0,  513,  513,    0,  513,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  513,  513,  513,    0,    0,  513,  513,  513,  513,  513,
  513,  513,  513,    0,    0,    0,    0,    0,    0,  513,
    0,    0,    0,    0,    0,    0,    0,  513,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  517,  517,  513,  513,  513,    0,    0,    0,
    0,  517,  517,  517,  517,  517,  517,  517,  517,    0,
    0,    0,    0,    0,    0,    0,    0,  517,    0,    0,
    0,    0,    0,    0,    0,    0,  517,  517,  517,    0,
    0,  517,    0,    0,    0,    0,    0,    0,    0,    0,
  517,    0,    0,  517,    0,    0,    0,  517,    0,    0,
    0,  517,  517,    0,  513,  513,    0,    0,  513,    0,
    0,  517,  513,  513,  513,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  517,  517,  513,  513,
  513,  513,  513,  517,    0,    0,    0,    0,    0,    0,
    0,    0,  517,  517,    0,  517,    0,    0,    0,    0,
    0,    0,  517,    0,    0,    0,    0,    0,    0,  517,
    0,  517,  517,  517,  517,  517,  517,  517,  517,    0,
  517,  517,  517,  517,  517,  517,  517,  517,  517,    0,
    0,  517,  517,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  517,    0,    0,  517,  517,    0,    0,  517,  517,  517,
    0,  517,  517,    0,  517,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  517,  517,    0,  517,  517,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  517,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  517,    0,    0,    0,  517,    0,    0,    0,    0,
    0,    0,    0,  517,  517,    0,  517,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  517,
  517,  517,    0,    0,  517,  517,  517,  517,  517,  517,
  517,  517,    0,    0,    0,    0,    0,    0,  517,    0,
    0,    0,    0,    0,    0,    0,  517,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  523,  523,  517,  517,  517,    0,    0,    0,    0,
  523,  523,  523,  523,  523,  523,  523,  523,    0,    0,
    0,    0,    0,    0,    0,    0,  523,    0,    0,    0,
    0,    0,    0,    0,    0,  523,  523,  523,    0,    0,
  523,    0,    0,    0,    0,    0,    0,    0,    0,  523,
    0,    0,  523,    0,    0,    0,  523,    0,    0,    0,
  523,  523,    0,  517,  517,    0,    0,  517,    0,    0,
  523,  517,  517,  517,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  523,  523,  517,  517,  517,
  517,  517,  523,    0,    0,    0,    0,    0,    0,    0,
    0,  523,  523,    0,  523,    0,    0,    0,    0,    0,
    0,  523,    0,    0,    0,    0,    0,    0,  523,    0,
  523,  523,  523,  523,  523,  523,  523,  523,    0,  523,
  523,  523,  523,  523,  523,  523,  523,  523,    0,    0,
  523,  523,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  523,
    0,    0,  523,  523,    0,    0,  523,  523,  523,    0,
  523,  523,    0,  523,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  523,  523,    0,  523,  523,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  523,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  523,    0,    0,    0,  523,    0,    0,    0,    0,    0,
    0,    0,  523,  523,    0,  523,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  523,  523,
  523,    0,    0,  523,  523,  523,  523,  523,  523,  523,
  523,    0,    0,    0,    0,    0,    0,  523,    0,    0,
    0,    0,    0,    0,    0,  523,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  536,  536,  523,  523,  523,    0,    0,    0,    0,  536,
  536,  536,  536,  536,  536,  536,  536,    0,    0,    0,
    0,    0,    0,    0,    0,  536,    0,    0,    0,    0,
    0,    0,    0,    0,  536,  536,  536,    0,    0,  536,
    0,    0,    0,    0,    0,    0,    0,    0,  536,    0,
    0,  536,    0,    0,    0,  536,    0,    0,    0,  536,
  536,    0,  523,  523,    0,    0,  523,    0,    0,  536,
  523,  523,  523,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  536,  536,  523,  523,  523,  523,
  523,  536,    0,    0,    0,    0,    0,    0,    0,    0,
  536,  536,    0,  536,    0,    0,    0,    0,    0,    0,
  536,    0,    0,    0,    0,    0,    0,  536,    0,  536,
  536,  536,  536,  536,  536,  536,  536,    0,  536,  536,
  536,  536,  536,  536,  536,  536,  536,    0,    0,  536,
  536,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  536,    0,
    0,  536,  536,    0,    0,  536,  536,  536,    0,  536,
  536,    0,  536,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  536,  536,    0,  536,  536,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  536,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  536,
    0,    0,    0,  536,    0,    0,    0,    0,    0,    0,
    0,  536,  536,    0,  536,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  536,  536,  536,
    0,    0,  536,  536,  536,  536,  536,  536,  536,  536,
    0,    0,    0,    0,    0,    0,  536,    0,    0,    0,
    0,    0,    0,    0,  536,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  572,
  572,  536,  536,  536,    0,    0,    0,    0,  572,  572,
  572,  572,  572,  572,  572,  572,    0,    0,    0,    0,
    0,    0,    0,    0,  572,    0,    0,    0,    0,    0,
    0,    0,    0,  572,  572,  572,    0,    0,  572,    0,
    0,    0,    0,    0,    0,    0,    0,  572,    0,    0,
  572,    0,    0,    0,  572,    0,    0,    0,  572,  572,
    0,  536,  536,    0,    0,  536,    0,    0,  572,  536,
  536,  536,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  572,  572,  536,  536,  536,  536,  536,
  572,    0,    0,    0,    0,    0,    0,    0,    0,  572,
  572,    0,  572,    0,    0,    0,    0,    0,    0,  572,
    0,    0,    0,    0,    0,    0,  572,    0,  572,  572,
  572,  572,  572,  572,  572,  572,    0,  572,  572,  572,
  572,  572,  572,  572,  572,  572,    0,    0,  572,  572,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  572,    0,    0,
  572,  572,    0,    0,  572,  572,  572,    0,  572,  572,
    0,  572,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  572,
  572,    0,  572,  572,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  572,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  572,    0,
    0,    0,  572,    0,    0,    0,    0,    0,    0,    0,
  572,  572,    0,  572,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  572,  572,  572,    0,
    0,  572,  572,  572,  572,  572,  572,  572,  572,    0,
    0,    0,    0,    0,    0,  572,    0,    0,    0,    0,
    0,    0,    0,  572,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  575,  575,
  572,  572,  572,    0,    0,    0,    0,  575,  575,  575,
  575,  575,  575,  575,  575,    0,    0,    0,    0,    0,
    0,    0,    0,  575,    0,    0,    0,    0,    0,    0,
    0,    0,  575,  575,  575,    0,    0,  575,    0,    0,
    0,    0,    0,    0,    0,    0,  575,    0,    0,  575,
    0,    0,    0,  575,    0,    0,    0,  575,  575,    0,
  572,  572,    0,    0,  572,    0,    0,  575,  572,  572,
  572,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  575,  575,  572,  572,  572,  572,  572,  575,
    0,    0,    0,    0,    0,    0,    0,    0,  575,  575,
    0,  575,    0,    0,    0,    0,    0,    0,  575,    0,
    0,    0,    0,    0,    0,  575,    0,  575,  575,  575,
  575,  575,  575,  575,  575,    0,  575,  575,  575,  575,
  575,  575,  575,  575,  575,    0,    0,  575,  575,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  575,    0,    0,  575,
  575,    0,    0,  575,  575,  575,    0,  575,  575,    0,
  575,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  575,  575,
    0,  575,  575,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  575,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  575,    0,    0,
    0,  575,    0,    0,    0,    0,    0,    0,    0,  575,
  575,    0,  575,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  575,  575,  575,    0,    0,
  575,  575,  575,  575,  575,  575,  575,  575,    0,    0,
    0,    0,    0,    0,  575,    0,    0,    0,    0,    0,
    0,    0,  575,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  584,  584,  575,
  575,  575,    0,    0,    0,    0,  584,  584,  584,  584,
  584,  584,  584,  584,    0,    0,    0,    0,    0,    0,
    0,    0,  584,    0,    0,    0,    0,    0,    0,    0,
    0,  584,  584,  584,    0,    0,  584,    0,    0,    0,
    0,    0,    0,    0,    0,  584,    0,    0,  584,    0,
    0,    0,  584,    0,    0,    0,  584,  584,    0,  575,
  575,    0,    0,  575,    0,    0,  584,  575,  575,  575,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  584,  584,  575,  575,  575,  575,  575,  584,    0,
    0,    0,    0,    0,    0,    0,    0,  584,  584,    0,
  584,    0,    0,    0,    0,    0,    0,  584,    0,    0,
    0,    0,    0,    0,  584,    0,  584,  584,  584,  584,
  584,  584,  584,  584,    0,  584,  584,  584,  584,  584,
  584,  584,  584,  584,    0,    0,  584,  584,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  584,    0,    0,  584,  584,
    0,    0,  584,  584,  584,    0,  584,  584,    0,  584,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  584,  584,    0,
  584,  584,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  584,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  584,    0,    0,    0,
  584,    0,    0,    0,    0,    0,    0,    0,  584,  584,
    0,  584,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  584,  584,  584,    0,    0,  584,
  584,  584,  584,  584,  584,  584,  584,    0,    0,    0,
    0,    0,    0,  584,    0,    0,    0,    0,    0,    0,
    0,  584,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  587,  587,  584,  584,
  584,    0,    0,    0,    0,  587,  587,  587,  587,  587,
  587,  587,  587,    0,    0,    0,    0,    0,    0,    0,
    0,  587,    0,    0,    0,    0,    0,    0,    0,    0,
  587,  587,  587,    0,    0,  587,    0,    0,    0,    0,
    0,    0,    0,    0,  587,    0,    0,  587,    0,    0,
    0,  587,    0,    0,    0,  587,  587,    0,  584,  584,
    0,    0,  584,    0,    0,  587,  584,  584,  584,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  587,  587,  584,  584,  584,  584,  584,  587,    0,    0,
    0,    0,    0,    0,    0,    0,  587,  587,    0,  587,
    0,    0,    0,    0,    0,    0,  587,    0,    0,    0,
    0,    0,    0,  587,    0,  587,  587,  587,  587,  587,
  587,  587,  587,    0,  587,  587,  587,  587,  587,  587,
  587,  587,  587,    0,    0,  587,  587,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  587,    0,    0,  587,  587,    0,
    0,  587,  587,  587,    0,  587,  587,    0,  587,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  587,  587,    0,  587,
  587,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  587,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  587,    0,    0,    0,  587,
    0,    0,    0,    0,    0,    0,    0,  587,  587,    0,
  587,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  587,  587,  587,    0,    0,  587,  587,
  587,  587,  587,  587,  587,  587,    0,    0,    0,    0,
    0,    0,  587,    0,    0,    0,    0,    0,    0,    0,
  587,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  590,  590,  587,  587,  587,
    0,    0,    0,    0,  590,  590,  590,  590,  590,  590,
  590,  590,    0,    0,    0,    0,    0,    0,    0,    0,
  590,    0,    0,    0,    0,    0,    0,    0,    0,  590,
  590,  590,    0,    0,  590,    0,    0,    0,    0,    0,
    0,    0,    0,  590,    0,    0,  590,    0,    0,    0,
  590,    0,    0,    0,  590,  590,    0,  587,  587,    0,
    0,  587,    0,    0,  590,  587,  587,  587,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  590,
  590,  587,  587,  587,  587,  587,  590,    0,    0,    0,
    0,    0,    0,    0,    0,  590,  590,    0,  590,    0,
    0,    0,    0,    0,    0,  590,    0,    0,    0,    0,
    0,    0,  590,    0,  590,  590,  590,  590,  590,  590,
  590,  590,    0,  590,  590,  590,  590,  590,  590,  590,
  590,  590,    0,    0,  590,  590,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  590,    0,    0,  590,  590,    0,    0,
  590,  590,  590,    0,  590,  590,    0,  590,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  590,  590,    0,  590,  590,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  590,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  590,    0,    0,    0,  590,    0,
    0,    0,    0,    0,    0,    0,  590,  590,    0,  590,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  590,  590,  590,    0,    0,  590,  590,  590,
  590,  590,  590,  590,  590,    0,    0,    0,    0,    0,
    0,  590,    0,    0,    0,    0,    0,    0,    0,  590,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  593,  593,  590,  590,  590,    0,
    0,    0,    0,  593,  593,  593,  593,  593,  593,  593,
  593,    0,    0,    0,    0,    0,    0,    0,    0,  593,
    0,    0,    0,    0,    0,    0,    0,    0,  593,  593,
  593,    0,    0,  593,    0,    0,    0,    0,    0,    0,
    0,    0,  593,    0,    0,  593,    0,    0,    0,  593,
    0,    0,    0,  593,  593,    0,  590,  590,    0,    0,
  590,    0,    0,  593,  590,  590,  590,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  593,  593,
  590,  590,  590,  590,  590,  593,    0,    0,    0,    0,
    0,    0,    0,    0,  593,  593,    0,  593,    0,    0,
    0,    0,    0,    0,  593,    0,    0,    0,    0,    0,
    0,  593,    0,  593,  593,  593,  593,  593,  593,  593,
  593,    0,  593,  593,  593,  593,  593,  593,  593,  593,
  593,    0,    0,  593,  593,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  593,    0,    0,  593,  593,    0,    0,  593,
  593,  593,    0,  593,  593,    0,  593,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  593,  593,    0,  593,  593,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  593,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  593,    0,    0,    0,  593,    0,    0,
    0,    0,    0,    0,    0,  593,  593,    0,  593,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  593,  593,  593,    0,    0,  593,  593,  593,  593,
  593,  593,  593,  593,    0,    0,    0,    0,    0,    0,
  593,    0,    0,    0,    0,    0,    0,    0,  593,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  596,  596,  593,  593,  593,    0,    0,
    0,    0,  596,  596,  596,  596,  596,  596,  596,  596,
    0,    0,    0,    0,    0,    0,    0,    0,  596,    0,
    0,    0,    0,    0,    0,    0,    0,  596,  596,  596,
    0,    0,  596,    0,    0,    0,    0,    0,    0,    0,
    0,  596,    0,    0,  596,    0,    0,    0,  596,    0,
    0,    0,  596,  596,    0,  593,  593,    0,    0,  593,
    0,    0,  596,  593,  593,  593,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  596,  596,  593,
  593,  593,  593,  593,  596,    0,    0,    0,    0,    0,
    0,    0,    0,  596,  596,    0,  596,    0,    0,    0,
    0,    0,    0,  596,    0,    0,    0,    0,    0,    0,
  596,    0,  596,  596,  596,  596,  596,  596,  596,  596,
    0,  596,  596,  596,  596,  596,  596,  596,  596,  596,
    0,    0,  596,  596,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  596,    0,    0,  596,  596,    0,    0,  596,  596,
  596,    0,  596,  596,    0,  596,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  596,  596,    0,  596,  596,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  596,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  596,    0,    0,    0,  596,    0,    0,    0,
    0,    0,    0,    0,  596,  596,    0,  596,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  596,  596,  596,    0,    0,  596,  596,  596,  596,  596,
  596,  596,  596,    0,    0,    0,    0,    0,    0,  596,
    0,    0,    0,    0,    0,    0,    0,  596,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  606,  606,  596,  596,  596,    0,    0,    0,
    0,  606,  606,  606,  606,  606,  606,  606,  606,    0,
    0,    0,    0,    0,    0,    0,    0,  606,    0,    0,
    0,    0,    0,    0,    0,    0,  606,  606,  606,    0,
    0,  606,    0,    0,    0,    0,    0,    0,    0,    0,
  606,    0,    0,  606,    0,    0,    0,  606,    0,    0,
    0,  606,  606,    0,  596,  596,    0,    0,  596,    0,
    0,  606,  596,  596,  596,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  606,  606,  596,  596,
  596,  596,  596,  606,    0,    0,    0,    0,    0,    0,
    0,    0,  606,  606,    0,  606,    0,    0,    0,    0,
    0,    0,  606,    0,    0,    0,    0,    0,    0,  606,
    0,  606,  606,  606,  606,  606,  606,  606,  606,    0,
  606,  606,  606,  606,  606,  606,  606,  606,  606,    0,
    0,  606,  606,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  606,    0,    0,  606,  606,    0,    0,  606,  606,  606,
    0,  606,  606,    0,  606,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  606,  606,    0,  606,  606,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  606,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  606,    0,    0,    0,  606,    0,    0,    0,    0,
    0,    0,    0,  606,  606,    0,  606,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  606,
  606,  606,    0,    0,  606,  606,  606,  606,  606,  606,
  606,  606,    0,    0,    0,    0,    0,    0,  606,    0,
    0,    0,    0,    0,    0,    0,  606,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  609,  609,  606,  606,  606,    0,    0,    0,    0,
  609,  609,  609,  609,  609,  609,  609,  609,    0,    0,
    0,    0,    0,    0,    0,    0,  609,    0,    0,    0,
    0,    0,    0,    0,    0,  609,  609,  609,    0,    0,
  609,    0,    0,    0,    0,    0,    0,    0,    0,  609,
    0,    0,  609,    0,    0,    0,  609,    0,    0,    0,
  609,  609,    0,  606,  606,    0,    0,  606,    0,    0,
  609,  606,  606,  606,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  609,  609,  606,  606,  606,
  606,  606,  609,    0,    0,    0,    0,    0,    0,    0,
    0,  609,  609,    0,  609,    0,    0,    0,    0,    0,
    0,  609,    0,    0,    0,    0,    0,    0,  609,    0,
  609,  609,  609,  609,  609,  609,  609,  609,    0,  609,
  609,  609,  609,  609,  609,  609,  609,  609,    0,    0,
  609,  609,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  609,
    0,    0,  609,  609,    0,    0,  609,  609,  609,    0,
  609,  609,    0,  609,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  609,  609,    0,  609,  609,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  609,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  609,    0,    0,    0,  609,    0,    0,    0,    0,    0,
    0,    0,  609,  609,    0,  609,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  609,  609,
  609,    0,    0,  609,  609,  609,  609,  609,  609,  609,
  609,    0,    0,    0,    0,    0,    0,  609,    0,    0,
    0,    0,    0,    0,    0,  609,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  612,  612,  609,  609,  609,    0,    0,    0,    0,  612,
  612,  612,  612,  612,  612,  612,  612,    0,    0,    0,
    0,    0,    0,    0,    0,  612,    0,    0,    0,    0,
    0,    0,    0,    0,  612,  612,  612,    0,    0,  612,
    0,    0,    0,    0,    0,    0,    0,    0,  612,    0,
    0,  612,    0,    0,    0,  612,    0,    0,    0,  612,
  612,    0,  609,  609,    0,    0,  609,    0,    0,  612,
  609,  609,  609,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  612,  612,  609,  609,  609,  609,
  609,  612,    0,    0,    0,    0,    0,    0,    0,    0,
  612,  612,    0,  612,    0,    0,    0,    0,    0,    0,
  612,    0,    0,    0,    0,    0,    0,  612,    0,  612,
  612,  612,  612,  612,  612,  612,  612,    0,  612,  612,
  612,  612,  612,  612,  612,  612,  612,    0,    0,  612,
  612,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  612,    0,
    0,  612,  612,    0,    0,  612,  612,  612,    0,  612,
  612,    0,  612,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  612,  612,    0,  612,  612,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  612,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  612,
    0,    0,    0,  612,    0,    0,    0,    0,    0,    0,
    0,  612,  612,    0,  612,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  612,  612,  612,
    0,    0,  612,  612,  612,  612,  612,  612,  612,  612,
    0,    0,    0,    0,    0,    0,  612,    0,    0,    0,
    0,    0,    0,    0,  612,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  615,
  615,  612,  612,  612,    0,    0,    0,    0,  615,  615,
  615,  615,  615,  615,  615,  615,    0,    0,    0,    0,
    0,    0,    0,    0,  615,    0,    0,    0,    0,    0,
    0,    0,    0,  615,  615,  615,    0,    0,  615,    0,
    0,    0,    0,    0,    0,    0,    0,  615,    0,    0,
  615,    0,    0,    0,  615,    0,    0,    0,  615,  615,
    0,  612,  612,    0,    0,  612,    0,    0,  615,  612,
  612,  612,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  615,  615,  612,  612,  612,  612,  612,
  615,    0,    0,    0,    0,    0,    0,    0,    0,  615,
  615,    0,  615,    0,    0,    0,    0,    0,    0,  615,
    0,    0,    0,    0,    0,    0,  615,    0,  615,  615,
  615,  615,  615,  615,  615,  615,    0,  615,  615,  615,
  615,  615,  615,  615,  615,  615,    0,    0,  615,  615,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  615,    0,    0,
  615,  615,    0,    0,  615,  615,  615,    0,  615,  615,
    0,  615,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  615,
  615,    0,  615,  615,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  615,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  615,    0,
    0,    0,  615,    0,    0,    0,    0,    0,    0,    0,
  615,  615,    0,  615,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  615,  615,  615,    0,
    0,  615,  615,  615,  615,  615,  615,  615,  615,    0,
    0,    0,    0,    0,    0,  615,    0,    0,    0,    0,
    0,    0,    0,  615,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  618,  618,
  615,  615,  615,    0,    0,    0,    0,  618,  618,  618,
  618,  618,  618,  618,  618,    0,    0,    0,    0,    0,
    0,    0,    0,  618,    0,    0,    0,    0,    0,    0,
    0,    0,  618,  618,  618,    0,    0,  618,    0,    0,
    0,    0,    0,    0,    0,    0,  618,    0,    0,  618,
    0,    0,    0,  618,    0,    0,    0,  618,  618,    0,
  615,  615,    0,    0,  615,    0,    0,  618,  615,  615,
  615,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  618,  618,  615,  615,  615,  615,  615,  618,
    0,    0,    0,    0,    0,    0,    0,    0,  618,  618,
    0,  618,    0,    0,    0,    0,    0,    0,  618,    0,
    0,    0,    0,    0,    0,  618,    0,  618,  618,  618,
  618,  618,  618,  618,  618,    0,  618,  618,  618,  618,
  618,  618,  618,  618,  618,    0,    0,  618,  618,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  618,    0,    0,  618,
  618,    0,    0,  618,  618,  618,    0,  618,  618,    0,
  618,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  618,  618,
    0,  618,  618,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  618,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  618,    0,    0,
    0,  618,    0,    0,    0,    0,    0,    0,    0,  618,
  618,    0,  618,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  618,  618,  618,    0,    0,
  618,  618,  618,  618,  618,  618,  618,  618,    0,    0,
    0,    0,    0,    0,  618,    0,    0,    0,    0,    0,
    0,    0,  618,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  630,  630,  618,
  618,  618,    0,    0,    0,    0,  630,  630,  630,  630,
  630,  630,  630,  630,    0,    0,    0,    0,    0,    0,
    0,    0,  630,    0,    0,    0,    0,    0,    0,    0,
    0,  630,  630,  630,    0,    0,  630,    0,    0,    0,
    0,    0,    0,    0,    0,  630,    0,    0,  630,    0,
    0,    0,  630,    0,    0,    0,  630,  630,    0,  618,
  618,    0,    0,  618,    0,    0,  630,  618,  618,  618,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  630,  630,  618,  618,  618,  618,  618,  630,    0,
    0,    0,    0,    0,    0,    0,    0,  630,  630,    0,
  630,    0,    0,    0,    0,    0,    0,  630,    0,    0,
    0,    0,    0,    0,  630,    0,  630,  630,  630,  630,
  630,  630,  630,  630,    0,  630,  630,  630,  630,  630,
  630,  630,  630,  630,    0,    0,  630,  630,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  630,    0,    0,  630,  630,
    0,    0,  630,  630,  630,    0,  630,  630,    0,  630,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  630,  630,    0,
  630,  630,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  630,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  630,    0,    0,    0,
  630,    0,    0,    0,    0,    0,    0,    0,  630,  630,
    0,  630,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  630,  630,  630,    0,    0,  630,
  630,  630,  630,  630,  630,  630,  630,    0,    0,    0,
    0,    0,    0,  630,    0,    0,    0,    0,    0,    0,
    0,  630,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  647,  647,  630,  630,
  630,    0,    0,    0,    0,  647,  647,  647,  647,  647,
  647,  647,  647,    0,    0,    0,    0,    0,    0,    0,
    0,  647,    0,    0,    0,    0,    0,    0,    0,    0,
  647,  647,  647,    0,    0,  647,    0,    0,    0,    0,
    0,    0,    0,    0,  647,    0,    0,  647,    0,    0,
    0,  647,    0,    0,    0,  647,  647,    0,  630,  630,
    0,    0,  630,    0,    0,  647,  630,  630,  630,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  647,  647,  630,  630,  630,  630,  630,  647,    0,    0,
    0,    0,    0,    0,    0,    0,  647,  647,    0,  647,
    0,    0,    0,    0,    0,    0,  647,    0,    0,    0,
    0,    0,    0,  647,    0,  647,  647,  647,  647,  647,
  647,  647,  647,    0,  647,  647,  647,  647,  647,  647,
  647,  647,  647,    0,    0,  647,  647,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  647,    0,    0,  647,  647,    0,
    0,  647,  647,  647,    0,  647,  647,    0,  647,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  647,  647,    0,  647,
  647,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  647,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  647,    0,    0,    0,  647,
    0,    0,    0,    0,    0,    0,    0,  647,  647,    0,
  647,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  647,  647,  647,    0,    0,  647,  647,
  647,  647,  647,  647,  647,  647,    0,    0,    0,    0,
    0,    0,  647,    0,    0,    0,    0,    0,    0,    0,
  647,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  644,  644,  647,  647,  647,
    0,    0,    0,    0,  644,  644,  644,  644,  644,  644,
  644,  644,    0,    0,    0,    0,    0,    0,    0,    0,
  644,    0,    0,    0,    0,    0,    0,    0,    0,  644,
  644,  644,    0,    0,  644,    0,    0,    0,    0,    0,
    0,    0,    0,  644,    0,    0,  644,    0,    0,    0,
  644,    0,    0,    0,  644,  644,    0,  647,  647,    0,
    0,  647,    0,    0,  644,  647,  647,  647,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  644,
  644,  647,  647,  647,  647,  647,  644,    0,    0,    0,
    0,    0,    0,    0,    0,  644,  644,    0,  644,    0,
    0,    0,    0,    0,    0,  644,    0,    0,    0,    0,
    0,    0,  644,    0,  644,  644,  644,  644,  644,  644,
  644,  644,    0,  644,  644,  644,  644,  644,  644,  644,
  644,  644,    0,    0,  644,  644,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  644,    0,    0,  644,  644,    0,    0,
  644,  644,  644,    0,  644,  644,    0,  644,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  644,  644,    0,  644,  644,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  644,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  644,    0,    0,    0,  644,    0,
    0,    0,    0,    0,    0,    0,  644,  644,    0,  644,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  644,  644,  644,    0,    0,  644,  644,  644,
  644,  644,  644,  644,  644,    0,    0,    0,    0,    0,
    0,  644,    0,    0,    0,    0,    0,    0,    0,  644,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  425,  425,  644,  644,  644,    0,
    0,    0,    0,  425,  425,  425,  425,  425,  425,  425,
  425,    0,    0,    0,    0,    0,    0,    0,    0,  425,
    0,    0,    0,    0,    0,    0,    0,    0,  425,  425,
  425,    0,    0,  425,    0,    0,    0,    0,    0,    0,
    0,    0,  425,    0,    0,  425,    0,    0,    0,  425,
    0,    0,    0,  425,  425,    0,  644,  644,    0,    0,
  644,    0,    0,  425,  644,  644,  644,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  425,  425,
  644,  644,  644,  644,  644,  425,    0,    0,    0,    0,
    0,    0,    0,    0,  425,  425,    0,  425,    0,    0,
    0,    0,    0,    0,  425,    0,    0,    0,    0,    0,
    0,  425,    0,  425,  425,  425,  425,  425,  425,  425,
  425,    0,  425,  425,  425,  425,  425,  425,  425,  425,
  425,    0,    0,  425,  425,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  425,    0,    0,  425,  425,    0,    0,  425,
  425,  425,    0,  425,  425,    0,  425,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  425,  425,    0,  425,  425,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  425,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  425,    0,    0,    0,  425,    0,    0,
    0,    0,    0,    0,    0,  425,  425,    0,  425,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  425,  425,  425,    0,    0,  425,  425,  425,  425,
  425,  425,  425,  425,    0,    0,    0,    0,    0,    0,
  425,    0,    0,    0,    0,    0,    0,    0,  425,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  394,  394,  425,  425,  425,    0,    0,
    0,    0,  394,  394,  394,  394,  394,  394,  394,  394,
    0,    0,    0,    0,    0,    0,    0,    0,  394,    0,
    0,    0,    0,    0,    0,    0,    0,  394,  394,  394,
    0,    0,  394,    0,    0,    0,    0,    0,    0,    0,
    0,  394,    0,    0,  394,    0,    0,    0,  394,    0,
    0,    0,  394,  394,    0,  425,  425,    0,    0,  425,
    0,    0,  394,  425,  425,  425,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  394,  394,  425,
  425,  425,  425,  425,  394,    0,    0,    0,    0,    0,
    0,    0,    0,  394,  394,    0,  394,    0,    0,    0,
    0,    0,    0,  394,    0,    0,    0,    0,    0,    0,
  394,    0,  394,  394,  394,  394,  394,  394,  394,  394,
    0,  394,  394,  394,  394,  394,  394,  394,  394,  394,
    0,    0,  394,  394,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  394,    0,    0,  394,  394,    0,    0,  394,  394,
  394,    0,  394,  394,    0,  394,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  394,  394,    0,  394,  394,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  394,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  394,    0,    0,    0,  394,    0,    0,    0,
    0,    0,    0,    0,  394,  394,    0,  394,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  394,  394,  394,    0,    0,  394,  394,  394,  394,  394,
  394,  394,  394,    0,    0,    0,    0,    0,    0,  394,
    0,    0,    0,    0,    0,    0,    0,  394,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  954,  954,  394,  394,  394,    0,    0,    0,
    0,  954,  954,  954,  954,  954,  954,  954,  954,    0,
    0,    0,    0,    0,    0,    0,    0,  954,    0,    0,
    0,    0,    0,    0,    0,    0,  954,  954,  954,    0,
    0,  954,    0,    0,    0,    0,    0,    0,    0,    0,
  954,    0,    0,  954,    0,    0,    0,  954,    0,    0,
    0,  954,  954,    0,  394,  394,    0,    0,  394,    0,
    0,  954,  394,  394,  394,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  954,  954,  394,  394,
  394,  394,  394,  954,    0,    0,    0,    0,    0,    0,
    0,    0,  954,  954,    0,  954,    0,    0,    0,    0,
    0,    0,  954,    0,    0,    0,    0,    0,    0,  954,
    0,  954,  954,  954,  954,  954,  954,  954,  954,    0,
  954,  954,  954,  954,  954,  954,  954,  954,  954,    0,
    0,  954,  954,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  954,    0,    0,  954,  954,    0,    0,  954,  954,  954,
    0,  954,  954,    0,  954,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  954,  954,    0,  954,  954,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  954,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  954,    0,    0,    0,  954,    0,    0,    0,    0,
    0,    0,    0,  954,  954,    0,  954,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  954,
  954,  954,    0,    0,  954,  954,  954,  954,  954,  954,
  954,  954,    0,    0,    0,    0,    0,    0,  954,    0,
    0,    0,    0,    0,    0,    0,  954,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  966,  966,  954,  954,  954,    0,    0,    0,    0,
  966,  966,  966,  966,  966,  966,  966,  966,    0,    0,
    0,    0,    0,    0,    0,    0,  966,    0,    0,    0,
    0,    0,    0,    0,    0,  966,  966,  966,    0,    0,
  966,    0,    0,    0,    0,    0,    0,    0,    0,  966,
    0,    0,  966,    0,    0,    0,  966,    0,    0,    0,
  966,  966,    0,  954,  954,    0,    0,  954,    0,    0,
  966,  954,  954,  954,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  966,  966,  954,  954,  954,
  954,  954,  966,    0,    0,    0,    0,    0,    0,    0,
    0,  966,  966,    0,  966,    0,    0,    0,    0,    0,
    0,  966,    0,    0,    0,    0,    0,    0,  966,    0,
  966,  966,  966,  966,  966,  966,  966,  966,    0,  966,
  966,  966,  966,  966,  966,  966,  966,  966,    0,    0,
  966,  966,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  966,
    0,    0,  966,  966,    0,    0,  966,  966,  966,    0,
  966,  966,    0,  966,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  966,  966,    0,  966,  966,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  966,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  966,    0,    0,    0,  966,    0,    0,    0,    0,    0,
    0,    0,  966,  966,    0,  966,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  966,  966,
  966,    0,    0,  966,  966,  966,  966,  966,  966,  966,
  966,    0,    0,    0,    0,    0,    0,  966,    0,    0,
    0,    0,    0,    0,    0,  966,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  970,  970,  966,  966,  966,    0,    0,    0,    0,  970,
  970,  970,  970,  970,  970,  970,  970,    0,    0,    0,
    0,    0,    0,    0,    0,  970,    0,    0,    0,    0,
    0,    0,    0,    0,  970,  970,  970,    0,    0,  970,
    0,    0,    0,    0,    0,    0,    0,    0,  970,    0,
    0,  970,    0,    0,    0,  970,    0,    0,    0,  970,
  970,    0,  966,  966,    0,    0,  966,    0,    0,  970,
  966,  966,  966,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  970,  970,  966,  966,  966,  966,
  966,  970,    0,    0,    0,    0,    0,    0,    0,    0,
  970,  970,    0,  970,    0,    0,    0,    0,    0,    0,
  970,    0,    0,    0,    0,    0,    0,  970,    0,  970,
  970,  970,  970,  970,  970,  970,  970,    0,  970,  970,
  970,  970,  970,  970,  970,  970,  970,    0,    0,  970,
  970,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  970,    0,
    0,  970,  970,    0,    0,  970,  970,  970,    0,  970,
  970,    0,  970,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  970,  970,    0,  970,  970,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  970,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  970,
    0,    0,    0,  970,    0,    0,    0,    0,    0,    0,
    0,  970,  970,    0,  970,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  970,  970,  970,
    0,    0,  970,  970,  970,  970,  970,  970,  970,  970,
    0,    0,    0,    0,    0,    0,  970,    0,    0,    0,
    0,    0,    0,    0,  970,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  973,
  973,  970,  970,  970,    0,    0,    0,    0,  973,  973,
  973,  973,  973,  973,  973,  973,    0,    0,    0,    0,
    0,    0,    0,    0,  973,    0,    0,    0,    0,    0,
    0,    0,    0,  973,  973,  973,    0,    0,  973,    0,
    0,    0,    0,    0,    0,    0,    0,  973,    0,    0,
  973,    0,    0,    0,  973,    0,    0,    0,  973,  973,
    0,  970,  970,    0,    0,  970,    0,    0,  973,  970,
  970,  970,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  973,  973,  970,  970,  970,  970,  970,
  973,    0,    0,    0,    0,    0,    0,    0,    0,  973,
  973,    0,  973,    0,    0,    0,    0,    0,    0,  973,
    0,    0,    0,    0,    0,    0,  973,    0,  973,  973,
  973,  973,  973,  973,  973,  973,    0,  973,  973,  973,
  973,  973,  973,  973,  973,  973,    0,    0,  973,  973,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  973,    0,    0,
  973,  973,    0,    0,  973,  973,  973,    0,  973,  973,
    0,  973,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  973,
  973,    0,  973,  973,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  973,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  973,    0,
    0,    0,  973,    0,    0,    0,    0,    0,    0,    0,
  973,  973,    0,  973,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  973,  973,  973,    0,
    0,  973,  973,  973,  973,  973,  973,  973,  973,    0,
    0,    0,    0,    0,    0,  973,    0,    0,    0,    0,
    0,    0,    0,  973,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  982,  982,
  973,  973,  973,    0,    0,    0,    0,  982,  982,  982,
  982,  982,  982,  982,  982,    0,    0,    0,    0,    0,
    0,    0,    0,  982,    0,    0,    0,    0,    0,    0,
    0,    0,  982,  982,  982,    0,    0,  982,    0,    0,
    0,    0,    0,    0,    0,    0,  982,    0,    0,  982,
    0,    0,    0,  982,    0,    0,    0,  982,  982,    0,
  973,  973,    0,    0,  973,    0,    0,  982,  973,  973,
  973,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  982,  982,  973,  973,  973,  973,  973,  982,
    0,    0,    0,    0,    0,    0,    0,    0,  982,  982,
    0,  982,    0,    0,    0,    0,    0,    0,  982,    0,
    0,    0,    0,    0,    0,  982,    0,  982,  982,  982,
  982,  982,  982,  982,  982,    0,  982,  982,  982,  982,
  982,  982,  982,  982,  982,    0,    0,  982,  982,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  982,    0,    0,  982,
  982,    0,    0,  982,  982,  982,    0,  982,  982,    0,
  982,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  982,  982,
    0,  982,  982,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  982,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  982,    0,    0,
    0,  982,    0,    0,    0,    0,    0,    0,    0,  982,
  982,    0,  982,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  982,  982,  982,    0,    0,
  982,  982,  982,  982,  982,  982,  982,  982,    0,    0,
    0,    0,    0,    0,  982,    0,    0,    0,    0,    0,
    0,    0,  982,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  985,  985,  982,
  982,  982,    0,    0,    0,    0,  985,  985,  985,  985,
  985,  985,  985,  985,    0,    0,    0,    0,    0,    0,
    0,    0,  985,    0,    0,    0,    0,    0,    0,    0,
    0,  985,  985,  985,    0,    0,  985,    0,    0,    0,
    0,    0,    0,    0,    0,  985,    0,    0,  985,    0,
    0,    0,  985,    0,    0,    0,  985,  985,    0,  982,
  982,    0,    0,  982,    0,    0,  985,  982,  982,  982,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  985,  985,  982,  982,  982,  982,  982,  985,    0,
    0,    0,    0,    0,    0,    0,    0,  985,  985,    0,
  985,    0,    0,    0,    0,    0,    0,  985,    0,    0,
    0,    0,    0,    0,  985,    0,  985,  985,  985,  985,
  985,  985,  985,  985,    0,  985,  985,  985,  985,  985,
  985,  985,  985,  985,    0,    0,  985,  985,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  985,    0,    0,  985,  985,
    0,    0,  985,  985,  985,    0,  985,  985,    0,  985,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  985,  985,    0,
  985,  985,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  985,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  985,    0,    0,    0,
  985,    0,    0,    0,    0,    0,    0,    0,  985,  985,
    0,  985,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  985,  985,  985,    0,    0,  985,
  985,  985,  985,  985,  985,  985,  985,    0,    0,    0,
    0,    0,    0,  985,    0,    0,    0,    0,    0,    0,
    0,  985,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 1030, 1030,  985,  985,
  985,    0,    0,    0,    0, 1030, 1030, 1030, 1030, 1030,
 1030, 1030, 1030,    0,    0,    0,    0,    0,    0,    0,
    0, 1030,    0,    0,    0,    0,    0,    0,    0,    0,
 1030, 1030, 1030,    0,    0, 1030,    0,    0,    0,    0,
    0,    0,    0,    0, 1030,    0,    0, 1030,    0,    0,
    0, 1030,    0,    0,    0, 1030, 1030,    0,  985,  985,
    0,    0,  985,    0,    0, 1030,  985,  985,  985,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 1030, 1030,  985,  985,  985,  985,  985, 1030,    0,    0,
    0,    0,    0,    0,    0,    0, 1030, 1030,    0, 1030,
    0,    0,    0,    0,    0,    0, 1030,    0,    0,    0,
    0,    0,    0, 1030,    0, 1030, 1030, 1030, 1030, 1030,
 1030, 1030, 1030,    0, 1030, 1030, 1030, 1030, 1030, 1030,
 1030, 1030, 1030,    0,    0, 1030, 1030,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 1030,    0,    0, 1030, 1030,    0,
    0, 1030, 1030, 1030,    0, 1030, 1030,    0, 1030,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 1030, 1030,    0, 1030,
 1030,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 1030,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 1030,    0,    0,    0, 1030,
    0,    0,    0,    0,    0,    0,    0, 1030, 1030,    0,
 1030,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 1030, 1030, 1030,    0,    0, 1030, 1030,
 1030, 1030, 1030, 1030, 1030, 1030,    0,    0,    0,    0,
    0,    0, 1030,    0,    0,    0,    0,    0,    0,    0,
 1030,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 1037, 1037, 1030, 1030, 1030,
    0,    0,    0,    0, 1037, 1037, 1037, 1037, 1037, 1037,
 1037, 1037,    0,    0,    0,    0,    0,    0,    0,    0,
 1037,    0,    0,    0,    0,    0,    0,    0,    0, 1037,
 1037, 1037,    0,    0, 1037,    0,    0,    0,    0,    0,
    0,    0,    0, 1037,    0,    0, 1037,    0,    0,    0,
 1037,    0,    0,    0, 1037, 1037,    0, 1030, 1030,    0,
    0, 1030,    0,    0, 1037, 1030, 1030, 1030,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 1037,
 1037, 1030, 1030, 1030, 1030, 1030, 1037,    0,    0,    0,
    0,    0,    0,    0,    0, 1037, 1037,    0, 1037,    0,
    0,    0,    0,    0,    0, 1037,    0,    0,    0,    0,
    0,    0, 1037,    0, 1037, 1037, 1037, 1037, 1037, 1037,
 1037, 1037,    0, 1037, 1037, 1037, 1037, 1037, 1037, 1037,
 1037, 1037,    0,    0, 1037, 1037,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 1037,    0,    0, 1037, 1037,    0,    0,
 1037, 1037, 1037,    0, 1037, 1037,    0, 1037,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 1037, 1037,    0, 1037, 1037,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, 1037,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 1037,    0,    0,    0, 1037,    0,
    0,    0,    0,    0,    0,    0, 1037, 1037,    0, 1037,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 1037, 1037, 1037,    0,    0, 1037, 1037, 1037,
 1037, 1037, 1037, 1037, 1037,    0,    0,    0,    0,    0,
    0, 1037,    0,    0,    0,    0,    0,    0,    0, 1037,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 1040, 1040, 1037, 1037, 1037,    0,
    0,    0,    0, 1040, 1040, 1040, 1040, 1040, 1040, 1040,
 1040,    0,    0,    0,    0,    0,    0,    0,    0, 1040,
    0,    0,    0,    0,    0,    0,    0,    0, 1040, 1040,
 1040,    0,    0, 1040,    0,    0,    0,    0,    0,    0,
    0,    0, 1040,    0,    0, 1040,    0,    0,    0, 1040,
    0,    0,    0, 1040, 1040,    0, 1037, 1037,    0,    0,
 1037,    0,    0, 1040, 1037, 1037, 1037,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 1040, 1040,
 1037, 1037, 1037, 1037, 1037, 1040,    0,    0,    0,    0,
    0,    0,    0,    0, 1040, 1040,    0, 1040,    0,    0,
    0,    0,    0,    0, 1040,    0,    0,    0,    0,    0,
    0, 1040,    0, 1040, 1040, 1040, 1040, 1040, 1040, 1040,
 1040,    0, 1040, 1040, 1040, 1040, 1040, 1040, 1040, 1040,
 1040,    0,    0, 1040, 1040,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 1040,    0,    0, 1040, 1040,    0,    0, 1040,
 1040, 1040,    0, 1040, 1040,    0, 1040,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 1040, 1040,    0, 1040, 1040,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 1040,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 1040,    0,    0,    0, 1040,    0,    0,
    0,    0,    0,    0,    0, 1040, 1040,    0, 1040,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 1040, 1040, 1040,    0,    0, 1040, 1040, 1040, 1040,
 1040, 1040, 1040, 1040,    0,    0,    0,    0,    0,    0,
 1040,    0,    0,    0,    0,    0,    0,    0, 1040,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 1046, 1046, 1040, 1040, 1040,    0,    0,
    0,    0, 1046, 1046, 1046, 1046, 1046, 1046, 1046, 1046,
    0,    0,    0,    0,    0,    0,    0,    0, 1046,    0,
    0,    0,    0,    0,    0,    0,    0, 1046, 1046, 1046,
    0,    0, 1046,    0,    0,    0,    0,    0,    0,    0,
    0, 1046,    0,    0, 1046,    0,    0,    0, 1046,    0,
    0,    0, 1046, 1046,    0, 1040, 1040,    0,    0, 1040,
    0,    0, 1046, 1040, 1040, 1040,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, 1046, 1046, 1040,
 1040, 1040, 1040, 1040, 1046,    0,    0,    0,    0,    0,
    0,    0,    0, 1046, 1046,    0, 1046,    0,    0,    0,
    0,    0,    0, 1046,    0,    0,    0,    0,    0,    0,
 1046,    0, 1046, 1046, 1046, 1046, 1046, 1046, 1046, 1046,
    0, 1046, 1046, 1046, 1046, 1046, 1046, 1046, 1046, 1046,
    0,    0, 1046, 1046,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 1046,    0,    0, 1046, 1046,    0,    0, 1046, 1046,
 1046,    0, 1046, 1046,    0, 1046,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 1046, 1046,    0, 1046, 1046,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 1046,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 1046,    0,    0,    0, 1046,    0,    0,    0,
    0,    0,    0,    0, 1046, 1046,    0, 1046,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 1046, 1046, 1046,    0,    0, 1046, 1046, 1046, 1046, 1046,
 1046, 1046, 1046,    0,    0,    0,    0,    0,    0, 1046,
    0,    0,    0,    0,    0,    0,    0, 1046,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 1049, 1049, 1046, 1046, 1046,    0,    0,    0,
    0, 1049, 1049, 1049, 1049, 1049, 1049, 1049, 1049,    0,
    0,    0,    0,    0,    0,    0,    0, 1049,    0,    0,
    0,    0,    0,    0,    0,    0, 1049, 1049, 1049,    0,
    0, 1049,    0,    0,    0,    0,    0,    0,    0,    0,
 1049,    0,    0, 1049,    0,    0,    0, 1049,    0,    0,
    0, 1049, 1049,    0, 1046, 1046,    0,    0, 1046,    0,
    0, 1049, 1046, 1046, 1046,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 1049, 1049, 1046, 1046,
 1046, 1046, 1046, 1049,    0,    0,    0,    0,    0,    0,
    0,    0, 1049, 1049,    0, 1049,    0,    0,    0,    0,
    0,    0, 1049,    0,    0,    0,    0,    0,    0, 1049,
    0, 1049, 1049, 1049, 1049, 1049, 1049, 1049, 1049,    0,
 1049, 1049, 1049, 1049, 1049, 1049, 1049, 1049, 1049,    0,
    0, 1049, 1049,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 1049,    0,    0, 1049, 1049,    0,    0, 1049, 1049, 1049,
    0, 1049, 1049,    0, 1049,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 1049, 1049,    0, 1049, 1049,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 1049,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 1049,    0,    0,    0, 1049,    0,    0,    0,    0,
    0,    0,    0, 1049, 1049,    0, 1049,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 1049,
 1049, 1049,    0,    0, 1049, 1049, 1049, 1049, 1049, 1049,
 1049, 1049,    0,    0,    0,    0,    0,    0, 1049,    0,
    0,    0,    0,    0,    0,    0, 1049,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 1052, 1052, 1049, 1049, 1049,    0,    0,    0,    0,
 1052, 1052, 1052, 1052, 1052, 1052, 1052, 1052,    0,    0,
    0,    0,    0,    0,    0,    0, 1052,    0,    0,    0,
    0,    0,    0,    0,    0, 1052, 1052, 1052,    0,    0,
 1052,    0,    0,    0,    0,    0,    0,    0,    0, 1052,
    0,    0, 1052,    0,    0,    0, 1052,    0,    0,    0,
 1052, 1052,    0, 1049, 1049,    0,    0, 1049,    0,    0,
 1052, 1049, 1049, 1049,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 1052, 1052, 1049, 1049, 1049,
 1049, 1049, 1052,    0,    0,    0,    0,    0,    0,    0,
    0, 1052, 1052,    0, 1052,    0,    0,    0,    0,    0,
    0, 1052,    0,    0,    0,    0,    0,    0, 1052,    0,
 1052, 1052, 1052, 1052, 1052, 1052, 1052, 1052,    0, 1052,
 1052, 1052, 1052, 1052, 1052, 1052, 1052, 1052,    0,    0,
 1052, 1052,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 1052,
    0,    0, 1052, 1052,    0,    0, 1052, 1052, 1052,    0,
 1052, 1052,    0, 1052,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 1052, 1052,    0, 1052, 1052,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 1052,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 1052,    0,    0,    0, 1052,    0,    0,    0,    0,    0,
    0,    0, 1052, 1052,    0, 1052,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 1052, 1052,
 1052,    0,    0, 1052, 1052, 1052, 1052, 1052, 1052, 1052,
 1052,    0,    0,    0,    0,    0,    0, 1052,    0,    0,
    0,    0,    0,    0,    0, 1052,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 1067, 1067, 1052, 1052, 1052,    0,    0,    0,    0, 1067,
 1067, 1067, 1067, 1067, 1067, 1067, 1067,    0,    0,    0,
    0,    0,    0,    0,    0, 1067,    0,    0,    0,    0,
    0,    0,    0,    0, 1067, 1067, 1067,    0,    0, 1067,
    0,    0,    0,    0,    0,    0,    0,    0, 1067,    0,
    0, 1067,    0,    0,    0, 1067,    0,    0,    0, 1067,
 1067,    0, 1052, 1052,    0,    0, 1052,    0,    0, 1067,
 1052, 1052, 1052,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 1067, 1067, 1052, 1052, 1052, 1052,
 1052, 1067,    0,    0,    0,    0,    0,    0,    0,    0,
 1067, 1067,    0, 1067,    0,    0,    0,    0,    0,    0,
 1067,    0,    0,    0,    0,    0,    0, 1067,    0, 1067,
 1067, 1067, 1067, 1067, 1067, 1067, 1067,    0, 1067, 1067,
 1067, 1067, 1067, 1067, 1067, 1067, 1067,    0,    0, 1067,
 1067,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 1067,    0,
    0, 1067, 1067,    0,    0, 1067, 1067, 1067,    0, 1067,
 1067,    0, 1067,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 1067, 1067,    0, 1067, 1067,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 1067,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 1067,
    0,    0,    0, 1067,    0,    0,    0,    0,    0,    0,
    0, 1067, 1067,    0, 1067,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, 1067, 1067, 1067,
    0,    0, 1067, 1067, 1067, 1067, 1067, 1067, 1067, 1067,
    0,    0,    0,    0,    0,    0, 1067,    0,    0,    0,
    0,    0,    0,    0, 1067,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  329,
  329, 1067, 1067, 1067,    0,    0,    0,    0,  329,  329,
  329,  329,  329,  329,  329,  329,    0,    0,    0,    0,
    0,    0,    0,    0,  329,    0,    0,    0,    0,    0,
    0,    0,    0,  329,  329,  329,    0,    0,  329,    0,
    0,    0,    0,    0,    0,    0,    0,  329,    0,    0,
  329,    0,    0,    0,  329,    0,    0,    0,  329,  329,
    0, 1067, 1067,    0,    0, 1067,    0,    0,  329, 1067,
 1067, 1067,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  329,  329, 1067, 1067, 1067, 1067, 1067,
  329,    0,    0,    0,    0,    0,    0,    0,    0,  329,
  329,    0,  329,    0,    0,    0,    0,    0, 2094,  329,
    0, 2097,    0,    0,    0,    0,  329,    0,  329,  329,
  329,  329,  329,  329,  329,  329,    0,  329,  329,  329,
  329,  329,  329,  329,  329,  329,    0,    0,  329,  329,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  329,    0,    0,
  329,  329,    0,    0,  329,  329,  329,    0,  329,  329,
    0,  329,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  329,
  329,    0,  329,  329,    0,    0,    0,    0,    0,    0,
 2184, 2185,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  329,    0, 2203, 2204,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  329,    0,
    0,    0,  329,    0,    0,    0,    0,    0,    0,    0,
  329,  329,    0,  329,    0,    0,    0,    0,    0,    0,
    0,    0, 2227,    0,    0,    0,  329,  329,  329,    0,
    0,  329,  329,  329,  329,  329,  329,  329,  329,    0,
    0, 2243,    0,    0,    0,  329,    0,    0,    0,    0,
    0,    0,    0,  329,    0,    0,    0,    0,    0,    0,
    0, 2260, 2261,    0,    0,    0,    0,    0,    0,    0,
  329,  329,  329,    0,    0,    0,    0, 2276, 2277,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 2294,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 2307,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 2323, 2324,
  329,  329,    0,    0,  329,    0,    0,    0,  329,  329,
  329, 2333, 2334,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  329,  329,  329,  329,  329,    0,
    0, 2348,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 2356,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 2367, 2368,    0,    0,    0,    0,    0,    0,
 2374, 2375,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 1221,    0,    0, 2390,    0,    0, 1222, 1223,
 1224,    0, 2395,    0, 1225,    0,    0,    0,    0,    0,
 1226, 1227, 1228, 2406,    0, 2408,    0,    0, 1229, 1230,
 2412,    0,    0,    0,    0, 1231, 1232, 1233, 1234,    0,
    0,    0,    0,    0,    0, 2427, 1235,    0,    0, 2430,
    0,    0, 1236,    0,    0,    0,    0,    0,    0, 1237,
 1238,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  342,  342,  342,    0,    0,
    0,  342,    0,    0,    0,    0,    0,  342,  342,  342,
    0, 1239, 1240, 1241,    0,  342,  342,    0,    0,    0,
    0,    0,  342,  342,  342,  342,    0,    0,    0,    0,
    0,    0,    0,  342,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  342,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, 1242, 1243, 1244, 1245, 1246,    0,    0,
    0,    0,    0,    0,    0, 1247, 1248, 1249,  342,  342,
  342,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, 1250,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 1251, 1252,    0, 1253, 1254,    0,    0,    0,    0,    0,
  342,  342,  342,  342,  342,    0,    0,    0,    0,    0,
    0,    0,  342,  342,  342,    0, 1255, 1256,    0,    0,
    0,    0,    0,    0, 1257, 1258,    0,    0,    0,    0,
 1259,    0, 1260, 1261,  342,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  342,  342,    0,
  342,  342,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  342,  342,    0,    0,    0,    0,    0,
    0,  342,  342,    0,    0,    0,    0,  342,    0,  342,
  342,  411,  412,  413,  414,  415,  416,  417,  418,  419,
  420,  421,  422,  423,  424,  425,  426,  427,  428,  429,
  430,  431,  432,  433,  434,  435,  436,  437,  438,    0,
    0,    0,    0,    0, 1042,  411,  412,  413,  414,  415,
  416,  417,  418,  419,  420,  421,  422,  423,  424,  425,
  426,  427,  428,  429,  430,  431,  432,  433,  434,  435,
  436,  437,  438,    0,    0,    0,    0,    0, 1079,  411,
  412,  413,  414,  415,  416,  417,  418,  419,  420,  421,
  422,  423,  424,  425,  426,  427,  428,  429,  430,  431,
  432,  433,  434,  435,  436,  437,  438,    0,    0,    0,
    0,    0, 1080,  411,  412,  413,  414,  415,  416,  417,
  418,  419,  420,  421,  422,  423,  424,  425,  426,  427,
  428,  429,  430,  431,  432,  433,  434,  435,  436,  437,
  438,    0,    0,    0,    0,    0, 1083,  411,  412,  413,
  414,  415,  416,  417,  418,  419,  420,  421,  422,  423,
  424,  425,  426,  427,  428,  429,  430,  431,  432,  433,
  434,  435,  436,  437,  438,    0,    0,    0,    0,    0,
 1095,  225,  225,  225,  225,  225,  225,  225,  225,  225,
  225,  225,  225,  225,  225,  225,  225,  225,  225,  225,
  225,  225,  225,  225,  225,  225,  225,  225,  225,    0,
    0,    0,    0,    0,  187,  226,  226,  226,  226,  226,
  226,  226,  226,  226,  226,  226,  226,  226,  226,  226,
  226,  226,  226,  226,  226,  226,  226,  226,  226,  226,
  226,  226,  226,    0,    0,    0,    0,    0,  188,
};
static const YYINT AslCompilercheck[] = {                13,
  325,  832,   27,  748, 1171, 1368,    8,   21,   13,   11,
  672,  766,   44, 1800,   44,   17,   27,   19, 1381,  323,
   27,   44,  448,  154, 1030,   44,  256,   44,  256,   44,
 1620,   44,   44,  377,  154,   27, 1740, 1352,   44,  465,
   44,  497, 1727, 1870,   44,   44, 1504,   44,   44,  377,
   44,  125,  256,   44,   44, 1843,   44,  483, 1510,  485,
 1512,  695,  256,   44, 1721,  448,   44,   44,   44,   44,
   44,   44,   44, 1711,   44, 1695,   44,  123, 1458,   44,
   44,   44,  465,   44,  388,   44,  512,   44,   44,   44,
   44,   44,   44, 1925, 1861,   44, 1734,   44,   44,   44,
  483,   44,  485,   44,  465,   44,   44,   44,   44,   44,
 1748, 1860,   44,   44, 1728, 2475,  256,   44,  642,  643,
  644, 1888,  303, 2458,   44, 2408, 2486,  452,   44,  512,
  334,  456,   44, 2468,  560, 1755,  562, 1925, 1887,  164,
   44,  775,   44,  616, 2427,  326, 1597,  573, 1024,  575,
   44,  577, 1984,  164,   44, 2267,  481,  164,  448, 1908,
  125, 1775,  487,  589,   44,  591, 1953,  649,  493, 1336,
  256, 1801,  164,  125,  499,  465,  649,  560,  328,  562,
  384,   44,  507,  377, 1987, 2012, 1566,  391,  328, 1992,
  573,  516,  575,  483,  577,  485, 1984,  623,   44,  625,
 1651,  562, 1990, 1833, 1834,  125,  589,   44,  591,  534,
  256,   44,  573,  125,  542,  542, 1873,  542, 2330, 2331,
   44,  125,  512,  125, 1055,  550, 1677,  552, 1679,  303,
  377,  125,   44,   44,   44,  439,  440,   44, 2350,  564,
  623,   44,  625,   44,  569,  125,  571,   44,  334, 1544,
   44, 1546,  326, 1568,   44,   44, 1707,   44,  583, 1710,
   44, 1719, 1947,   44,  395,  396,   44, 2438,  650, 1973,
  560,   44,  562, 1852,  123,   44,  649, 2448,  603,  125,
  649,   44, 1733,  573, 2455,  575,   44,  577,   44,  649,
   44,  649,  125,   44,   44, 2421, 1875,  649,  384,  589,
   44,  591, 2428,  649,   44,  391,  650,  562,  563,  564,
 2436,  442,  448,  125,  445,  125,  649,  621,  125,  450,
  448,   59,  125,  454,  125,  514,  515,  458,  125,  465,
  461,  333,  463,  623,  638,  625,  467,  465,  469,  649,
  471,  125,  473,  649,  475,  650,  477,  483,  479,  485,
  650,  651,  125,  439,  440,  483,  125,  485,  489,  993,
  994,  995,  125,  997,  998,  485,  649,  125,  649,  125,
  501,  125,  503,  649,  505,  125,  512,  649,  509,  649,
 1959, 1971, 1972,  514,  512,  125, 1217,  518,  649,  520,
 1514,  522, 1516,  524,  698,  526, 1520,  528, 1522,  530,
 1145,  532,  649, 1148,  649,  536,  649,  538, 1859,  540,
  649, 1862,  649,  544,  649,  546,  649,  548,  649,  649,
  257,  256,  650,  554,  560,  556,  562,  558,  649, 2059,
 1864,  649,  560,  649,  562,  566,  649,  573, 1889,  575,
  616,  577,  650,  651, 2231,  573,  649,  575,  649,  577,
  581,  655, 2082,  589,  585,  591,  587,  649, 1909,  344,
  345,  589,  593,  591,  595,  649,  597,  649,  599,  649,
  601,  647,  648,  650,  311,  651,  607,  649,  609,  649,
  611, 1143,  613,  497,  615,  256,  617,  623,  649,  625,
  649, 2129, 2130,  650,  651,  623,  627,  625,  629, 2137,
 2138,  649,  514,  515, 1380, 1139, 1168,  832, 2146,  640,
  641,  256,  643,  644,  645,  646,  647,  648,  649,  650,
  651,  652,  653,  654,  655,  656,  657,  658,  659,  660,
  661,  662,  663,  664,  665,  666,  667,  668,  669,  670,
  521,  522,  523,  524,  521,  522,  523,  524,  679,  649,
 2188,  650,  651, 2132, 2006,  649,  448, 2009,  514,  515,
  649,  514,  515,  256,  990,  649,  992,  650,  651,  655,
 1576,  649, 2151,  465,  521,  522,  523,  524,  494,  495,
  649, 2033,  649,  514,  515,  649,  521,  522,  523,  524,
 2228,  483,  649, 1049,  521,  522,  523,  524, 1054,  650,
  651, 2239,  439, 1966,  649,  448,  649,  990, 2238,   44,
  649, 1067, 1068,  649, 2193,  649, 2195, 2196, 1044,  651,
  512,  651,  465,  649,  514,  515,  463,  650, 2415,  649,
 2417,  650,  651,  650,  651,  650,  651,  650,  651,  649,
  483,  649,  485, 1305,  650,  651,  650,  650,  651, 1311,
  650,  650,  977,  650,  650, 1081,  650, 2020, 1320,  650,
  650, 1044,  650,  649, 1540,  649, 1542,  992,  560,  512,
  562,  256,  650, 1129,  650,  650,  650,  650,  650,  256,
  650,  573,  650,  575,  698,  577,  650,  650,  256,  650,
  256,  650,  256,  650,  696,  650,  650,  589, 1081,  591,
  990,  650,  256, 1448,  650,  650,  256,  650,  256,  650,
 1465,  650,  650,  650,  650, 2078, 2079,  560,  650,  562,
  514,  515,  256, 2086, 2087,  514,  515,  514,  515, 2092,
  573,  623,  575,  625,  577,  649,  514,  515,  649, 2377,
 2378, 2379, 2380,  494,  495,  256,  589,  256,  591,  649,
  494,  495,  650,  651, 1044, 2189, 2190,  268,  269,  270,
  271,  272,  273, 2197, 2198, 2128,  649,  693, 2202,  256,
  334,  542,  411,  412,  700,  123,  702,  542,  549,  550,
  623,  552,  625,  649,  549,  550,  256,  552,  714,  649,
  716, 1081,  718,  649,  720, 2229,  722,  542,  724, 1103,
  726,  932,  649,  934,  549,  550,  334,  552,  638,  639,
  640,  641,  642,  643,  644,  542,  742,  649, 1985,  256,
  384, 2400,  549,  550, 2187,  552,  542,  391,  334, 2263,
  379,  380,  381,  549,  550,  542,  552,  519,  520,  970,
 2274,  649,  549,  550,  975,  552,  256,  773, 1724, 1725,
  649,  777, 1683,  779,  990,  781,  384,  783,  649,  785,
  256,  787,  990,  391,  649,  791,  649,  334, 2447,  795,
  649,  797,  582,  583,  584,  439,  440,  803,  384,  805,
 2459,  807,  490,  491,  492,  391,  256,  813,  649,  815,
 2469,  256, 1217,  819, 2473,  268,  269,  270,  271,  272,
  273,  382,  383, 1565,  256,  831,  385,  386, 1044, 1571,
  649,  439,  440,  362,  363,  364, 1044,  384,  494,  495,
 1796, 1797,  323,  324,  391,  640,  641,  642,  643,  644,
  856,  334,  858,  439,  440,  415,  416,  417,  418,  419,
  420,   27,  256,  968,  870, 1081,  576,  577,  578,  579,
  580,  581,  649, 1081, 2388,  649,  334,  968,  649, 1090,
  974,  968, 2396, 2397, 2398, 2399,  300,  301,  649, 2403,
  896,  334,  439,  440,  900,  649,  968, 2411,  649, 1110,
  649,  384,  649,  433,  434, 2419,  529,  530,  391,  331,
  332,  649, 2426,  649, 2357, 2358, 2359, 2360, 2361,  421,
  422, 2364, 1878, 1879, 1880, 2439,  384,  570,  571, 1885,
 1024, 2374,  760,  391,  762, 2449,  764,  649, 1476, 2382,
  649,  384, 1478, 1685, 1482,  649, 1484,  649,  391,  649,
 1486,  335,  336,  337,  338, 1049,  439,  440, 1700, 1701,
 1054, 2404, 1500,  521,  522,  523,  524, 1061,  649, 2412,
  276,  277,  649, 1067, 1068,  981, 1061,  347,  348,  649,
 2423,  439,  440,  306,  307,  649, 1524, 2430, 1526,  817,
  996,  256, 1528,  999, 2437,  256,  439,  440,  164,  256,
 1536,  304,  305, 1097,  256,  334,  537,  538,  539,  540,
 1548,  655, 1550,  556,  557, 1097, 1552,  256,  990,  447,
  448,  449,  450,  451,  452,  453,  454,  455,  456,  457,
  458,  459,  460,  461,  462, 1129,  426,  427,  428,  429,
 1046,  256,  650,  256, 2000, 1051,  256,  655,  554,  555,
  878,  256,  880,  256,  882,  384,  884,  256,  886,  256,
  650,  651,  391,  256,  650,  650,  651,  990, 2024,  655,
  650,  651, 1044,  588,  589,  590,  591,  592,  593,  594,
  595,  596,  597,  598,  599,  600,  601,  602,  603,  604,
  605,  606,  607,  608,  609,  610,  611,  612,  613,  614,
  615, 1506,  256,  650,  256,  334,  650,  651,  655, 1081,
  439,  440,  650,  651,  256, 1326, 1327, 1328,  650,  651,
  256, 1044,  292,  293,  294,  295,  296,  470,  471,  472,
  473,  474,  334,  256, 1518,  650, 1142,  256,   44, 1544,
  256, 1546, 2098, 2099,  387,  388,  389,  390,  976, 1155,
  256,  979,  256, 1364,  649,  384,  650,  651, 1081,  334,
  988,  989,  391,  650,  651, 2121, 2122,  256, 1910, 1911,
  650,  651,  655,  650,  651, 1003,  256, 1713,  256, 1715,
 2136,  123,  384, 1189, 1926,  650,  651, 2143,  256,  391,
 1726, 1727,  382,  383, 1730,  382,  383,  655,   59, 1735,
  256,  334,  256, 1739,  256, 1033,  256, 1213,  256,  384,
  439,  440,  655,  385,  386,  256,  391,  650,  256,  125,
  278,  279,  280,  281, 1052, 1053,  256, 2183, 1056, 1057,
  256,  256,  334, 2381, 1062,  256, 2384,  439,  440,  335,
  336,  337,  338, 1348,  334, 2393,  256, 1075, 1076,  256,
  256,  384,  256, 2401, 1082, 1360,  256, 1348,  391,  256,
  256, 1348,  256, 1091,  439,  440, 2222, 2223, 1096, 1360,
  256,  256,  256, 1360, 2422,  256, 1348,  256,  256,  256,
  256, 2429,  384,  256,  256, 1379, 1380,  650, 1360,  391,
  256,  256, 2440,  256,  384,  334,  256,  256,  256,  256,
  256,  391, 2450, 2259,  256,  256,  439,  440, 2456,  256,
  256,  256,  650,  650,  650,  123, 1144,  650, 1423,  650,
  650,   44,  650,  650,  650,  650,  655,  123, 1433,  650,
 1435,  497, 1423, 2289, 2290,  650, 1423,  439,  440,  650,
  650,  650, 1433, 1437, 1435,  384, 1433,  123, 1435,  439,
  440, 1423,  391, 1564, 1890, 1437,  650,  650, 1894, 1895,
  650, 1433, 1573, 1435, 1192,  334, 2322, 1903, 1904,  650,
 1376,  650,  650,  334,  650,  284,  285,  286,  287,  288,
  289,  290,  650,  650, 1478,  256,  650, 2343, 2344,  616,
  650,  650, 1486,  256, 1488,  650, 1490,  650,   44,  650,
  439,  440, 1496, 1808, 1498,  650,  650,  123,  650,  650,
 2366, 1947,  650,  322, 2370,  384,  650,  650,  650,  650,
  329,  651,  391,  384,  650,  334,  655,  650,  650, 2385,
  391,  334,  650,  334, 1528,   44, 1530,   44, 1532,  650,
 1534,  650, 1536,  650,  650, 1530, 1540,   44, 1542, 2405,
  650,   44,  650,  655,  650,  650,  650,  123, 1552,  650,
 1865,  650,  650,   44,  650,  650,  375,  650,  650,  650,
  439,  440,  650,  650,  650,  384,  650,  650,  439,  440,
  655,  384,  391,  384,  123, 2021,  650,  650,  391,  650,
  391,  650,  650,  334,  403,  404,  405,  406,  407,  408,
  409,  410, 1886,  650,  334,  447,  448,  449,  450,  451,
  452,  453,  454,  455,  456,  457,  458,  459,  460,  461,
  462,  650,  655,  650,  650,  650, 2062,   44,  650,  650,
  439,  440,  698,  334, 2070,  650,  439,  440,  439,  440,
  650,  650,  650,  384,   44,  650,   44,  650,   44,  650,
  391,  650,  650,  655,  384,  650,  650,  650,  650,  650,
 2096,  391,  650,  650,  650,  655,  650,  650,  650, 1575,
   44,  650,   44, 2109,   44,  650,  650, 2113,  650,  650,
  650, 1986, 1687,  384,  616,   44,  125,  496,  650, 1694,
  391,  650,  256,  616,  616,  125, 1687, 2133,  439,  440,
 1687,   44,  123, 1694,  650,   44,  256, 1694,  650,  439,
  440,  123,  256,  650, 2150, 1687,  655,  650, 1712, 1713,
   44, 1715, 1694,  650,  123,   44, 1720,   44,  123, 1723,
 1724, 1725, 1726, 1727, 2018, 2019, 1730, 1731,  439,  440,
  123, 1735, 2026, 2027,  123, 1739, 2030, 1752,  650,  650,
  125,  650,  650,   44,  125,  650, 1761, 1762,  650,  650,
  650, 1752,  650,  650,  125, 1752,   44,  650,  650,  125,
 1761, 1762,   44,   44, 1761, 1762,  650,  616,  123,  650,
 1752,   44,  650,  650,   44,  649,  655,  256,  650, 1761,
 1762,  256, 1698, 2077,  655,  650,  650,  650,  256,  256,
  650,  650, 1796, 1797,  256,  649,  377, 1801,  649, 2093,
  616,  617,  618,  619,  620,  621,  622,  623,  624,  625,
  626,  627,  628,  629,  630,  631,  632,  633,  634,  635,
  636,  637,  638,  639,  640,  641,  642,  643,  644, 1833,
 1834,  647,  648, 2127,  649,  651,  655, 2131,  650,  256,
  650, 1709,  655,  650,  655,  650,  650,  650,  650,  650,
  650,   44,  634,  635,  636,  637,  638,  639,  640,  641,
  642,  643,  644,  650, 1732, 1869,  650,  650,  256,  649,
 1874,  650,  650, 1877, 1878, 1879, 1880, 1881, 1746, 1747,
  650, 1885,  649,  649,  649,  649, 1890,  649,  649,  649,
 1894, 1895,  968,  649,  649,  649,  649,  649,  974, 1903,
 1904,  649,  649,  649,  655,   44, 1774, 2201,  649,  256,
 1778, 1599,  649, 1917,  649,  655,  497,  498,  499,  500,
  501,  502,  503,  504,  505,  506,  507,  508,  649,  649,
  649,  256,  125,  649,  649,  649,  649,  649,  256,  649,
   44,  649,  649, 1947,  655, 1813,  649,  649, 1024,  447,
  448,  449,  450,  451,  452,  453,  454,  455,  456,  457,
  458,  459,  460,  461,  462, 1653, 1981, 1982,  649,  649,
  649,  649,  649, 1049, 1978,  650,  650,  650, 1054, 1994,
 1981, 1982,  650, 1987, 1981, 1982,  125,  650, 1992,   44,
  650, 1067, 1068, 1994,  650,  650, 2000, 1994,  650, 1981,
 1982,  650,  650,  256, 2008,  256,  256,  256,  256,  256,
  256,  256, 1994,  256,  256,  256,  256, 2021,  256, 2023,
 2024,  125,  256,  256,  256, 2029,  256,  256, 2032,  256,
  256, 2035,  256,  256,  256,  256,  256,  256,  256, 2043,
  256, 2230, 2336, 2337, 2338, 2339,  377, 2236, 2237,  256,
  256, 2240,  649, 1129,  123, 2059,   44,  123, 2062,   44,
   44,   44,  650,  650, 1932,  650, 2070, 1935,  650,  256,
  125,  650,  650,  650,  256, 2264,   44, 2266, 2082,  650,
  650,  650, 1770,  650,  650, 2089,  650,  650, 1776, 1777,
  123, 1779, 2096,  650, 2098, 2099,  123,  650,  650,  650,
  650, 1969,  650, 2107,  650, 2109, 2295,  650,  650, 2113,
  650,  650, 1980,  650, 2303,  650,   44, 2121, 2122,  650,
 2124, 2125,  650,  650, 1812,  650, 1814,  650,  650, 2133,
  650, 2135, 2136,   44,  650,  650,  650,  650,  650, 2143,
  650,  650,  650, 2147, 2148,  650, 2150, 1835, 1836, 1837,
  650,  650,   44,  650,   44,   44,   44,   44,   44,   44,
 2164,   44,   44,   44,   44,  650,  497,  498,  499,  500,
  501,  502,  503,  504,  505,  506,  507,  508,   44, 2183,
   44,   44, 2186,   44,   44,   44,   44,   44,   44,   44,
   44,   44,  123,   44,  650,  650,  650,  125,  125,   44,
  650, 2205,  650,   44,   44,   44,   44,   44,  123,   44,
 2214, 2215, 2216,   44, 2218,   44,  123,  123, 2222, 2223,
  650, 2225, 2226,  123,  650, 2414,  650, 2416,  123,  650,
   44,   44,   44,   44, 2238,  125,   44, 2241, 2242,   44,
   44,   44,   44, 2432,   44, 2434,   44,   44, 2252,   44,
 2254, 2255, 2256,   44,   44, 2259,   44,   44, 2262, 2254,
 2255, 2256,   44, 2267,  650,   44,   44,   44,   44,  125,
   44,  123, 1348,  123, 2278,  650,  123, 2281, 2282, 2283,
  650, 2285,   44,  320, 1360, 2289, 2290,  650, 2292, 2293,
  123,   44,  649,  123,   44,  649,   44,  649,   44,  650,
   44, 2305, 2306, 1379, 1380,   44,  650,   44,   44,   44,
   44, 2315,  650,   44,   44,   44,   44,  649, 2322,   44,
   44, 2325,  123,   44,   44,   44, 2330, 2331,   44,  123,
   44, 2335,   44,   44,  123,  650, 2340,  256, 2342, 2343,
 2344,   44, 2346, 2347,   44,   44, 2350, 1423,  125,   44,
 2354, 2355,   44,   44,   44,  650,   44, 1433, 2362, 1435,
  497,  650, 2366,  650,  650, 2369, 2370,  650,   44,   44,
   44,   44, 2376,   44,   44,   44,   44,   44,  650, 2383,
   44, 2385,   44, 2387,   44, 2389,   44,   44,  650,  650,
 2394,   44,   44,  650,   44,   44,   44,   44,   44,   44,
   44, 2405, 1478,   44,   44, 2409,   44,   44,   44, 2413,
 1486,  650, 1488,  649, 1490,  123, 2420,   44,  649,   44,
 1496,  649, 1498,   44,  617,  618,  619,  620,  621,  622,
  623,  624,  625,  626,  627,  628,  629,  630,  631,  632,
  633,  634,  635,  636,  637,  638,  639,  640,  641,  642,
  643,  644, 1528,  650,   44,   44, 1532,  650, 1534,  650,
 1536,  650,  123,   44, 1540,  650, 1542,   44,   44,   44,
   44,   44,   44,   44,   44,   44, 1552,   44,  617,  618,
  619,  620,  621,  622,  623,  624,  625,  626,  627,  628,
  629,  630,  631,  632,  633,  634,  635,  636,  637,  638,
  639,  640,  641,  642,  643,  644,  650,  650,  650,  650,
   44,  650,   44,  617,  618,  619,  620,  621,  622,  623,
  624,  625,  626,  627,  628,  629,  630,  631,  632,  633,
  634,  635,  636,  637,  638,  639,  640,  641,  642,  643,
  644,   44,  650,  650,  650,   44,  650,  631,  632,  633,
  634,  635,  636,  637,  638,  639,  640,  641,  642,  643,
  644,  698,  617,  618,  619,  620,  621,  622,  623,  624,
  625,  626,  627,  628,  629,  630,  631,  632,  633,  634,
  635,  636,  637,  638,  639,  640,  641,  642,  643,  644,
   44,  650,  650,  123,  123,  650,  630,  631,  632,  633,
  634,  635,  636,  637,  638,  639,  640,  641,  642,  643,
  644, 1687,   44,   44,   44,   44,   44,   44, 1694,  628,
  629,  630,  631,  632,  633,  634,  635,  636,  637,  638,
  639,  640,  641,  642,  643,  644, 1712, 1713,   44, 1715,
   44,   44,   44,   44, 1720,  650,  123, 1723, 1724, 1725,
 1726, 1727,  650,   44, 1730, 1731,   44,   44,   44, 1735,
   44,  123,   44, 1739,   44,   44,   44,   44,   44,   44,
   44,   44,  125,   44,   44,  650, 1752,   44,  650,  650,
  650,   44,   44,  650,  650, 1761, 1762,  650,  650,  617,
  618,  619,  620,  621,  622,  623,  624,  625,  626,  627,
  628,  629,  630,  631,  632,  633,  634,  635,  636,  637,
  638,  639,  640,  641,  642,  643,  644,  650,  650,    0,
 1796, 1797,  650,  123,  650, 1801,  650,  617,  618,  619,
  620,  621,  622,  623,  624,  625,  626,  627,  628,  629,
  630,  631,  632,  633,  634,  635,  636,  637,  638,  639,
  640,  641,  642,  643,  644,  123,  650, 1833, 1834,  650,
  650,  617,  618,  619,  620,  621,  622,  623,  624,  625,
  626,  627,  628,  629,  630,  631,  632,  633,  634,  635,
  636,  637,  638,  639,  640,  641,  642,  643,  644,   44,
   44,  123,  125, 1869,  650,  123,  125,   44, 1874,  125,
   44, 1877, 1878, 1879, 1880, 1881,  650,  650,  650, 1885,
   44,   44,   44,   44, 1890,   44,  650,   44, 1894, 1895,
   44,   44,  650,  650,  650,  650,  650, 1903, 1904,  650,
  650,  650,  650,  650,  650,  650,   44,  974,   44,   44,
  617,  618,  619,  620,  621,  622,  623,  624,  625,  626,
  627,  628,  629,  630,  631,  632,  633,  634,  635,  636,
  637,  638,  639,  640,  641,  642,  643,  644,   44,  650,
  650, 1947,   44,  650,  632,  633,  634,  635,  636,  637,
  638,  639,  640,  641,  642,  643,  644, 1024,  125,  650,
  650,  650,   44,  650,  650,  650,  650,   44,  650,  650,
   44,  650, 1978,   44,   44, 1981, 1982,  650,  125,   44,
   44,   44, 1049,   44,    4,  164, 1841, 1054, 1994, 1430,
 1990,  485, 2280,  650, 2000, 2209, 1430,  650,  650, 1461,
 1067, 1068, 2008,  650, 1530,  650, 2482,  650,   44, 1867,
  650,  650, 2089,  650,  650, 2021,  650, 2023, 2024,  650,
   21, 1217, 1099, 2029, 1327,  362, 2032, 1872, 2052, 2035,
 2106, 1365, 1671, 1663, 2041, 1975, 1743, 2043,  154, 1564,
 1738,   -1,   -1,   -1,   -1,  284,  285,  286,  287,  288,
  289,  290,   -1, 2059,   -1,   -1, 2062,   -1,   -1,   -1,
   -1,   -1, 1129,   -1, 2070,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1, 2082,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 2096,   -1, 2098, 2099,   -1,  334,   -1,   -1,   -1,   -1,
   -1, 2107,   -1, 2109,   -1,   -1,   -1, 2113,   -1,   -1,
   -1,   -1,   -1,   -1,   -1, 2121, 2122,   -1, 2124, 2125,
   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2133,   -1, 2135,
 2136,   -1,   -1,   -1,   -1,   -1,   -1, 2143,   -1,   -1,
   -1, 2147, 2148,   -1, 2150,  384,   -1,   -1,   -1,   -1,
   -1,  497,  391,   -1,   -1,   -1,   -1,   -1, 2164,   -1,
   -1,   -1,   -1,   44,  403,  404,  405,  406,  407,  408,
  409,  410,   -1,   -1,   -1,   -1,   -1, 2183,   -1,   -1,
 2186,  629,  630,  631,  632,  633,  634,  635,  636,  637,
  638,  639,  640,  641,  642,  643,  644,   -1,   -1, 2205,
  439,  440,   -1,   -1,   -1,   -1,   -1,   -1, 2214, 2215,
 2216,   -1, 2218,   -1,   -1,   -1, 2222, 2223,   -1, 2225,
 2226,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1, 2238,   -1,   -1, 2241, 2242,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1, 2252,   -1,   -1,   -1,
   -1,   -1,   -1, 2259,   -1,   -1, 2262,   -1,   -1,   -1,
   -1, 2267,   -1,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1, 2278,   -1,   -1, 2281, 2282, 2283,   -1, 2285,
   -1,   -1,   -1, 2289, 2290,   -1, 2292, 2293,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2305,
 2306,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   44, 2315,
   -1,   -1, 1379, 1380,   -1,   -1, 2322,   -1,   -1, 2325,
   -1,   -1,   -1,   -1, 2330, 2331,   -1,   -1,   -1, 2335,
   -1,   -1,   -1,   -1, 2340,   -1, 2342, 2343, 2344,   -1,
 2346, 2347,   -1,   -1, 2350,   -1,   -1,   -1, 2354, 2355,
   -1,   -1,  698,   -1,   -1,   -1, 2362,   -1,   -1,   -1,
 2366,   -1,   -1, 2369, 2370,   -1,   -1,   -1,   -1,   -1,
 2376,   -1,   -1,   -1,   -1,   -1,   -1, 2383,   -1, 2385,
   -1, 2387,   -1, 2389,   -1,   -1,   -1,   -1, 2394,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2405,
   -1,   -1,   -1, 2409,   -1,   -1,   -1, 2413,   -1,   -1,
   -1, 1478,   -1,   -1, 2420,   -1,  655,   -1,   -1, 1486,
   -1, 1488,   -1, 1490,   -1,   -1,   -1,   -1,   -1, 1496,
   -1, 1498,   -1,  617,  618,  619,  620,  621,  622,  623,
  624,  625,  626,  627,  628,  629,  630,  631,  632,  633,
  634,  635,  636,  637,  638,  639,  640,  641,  642,  643,
  644, 1528,   -1,   -1,   -1, 1532,  650, 1534,   -1, 1536,
   -1,   -1,   -1, 1540,   -1, 1542,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1, 1552,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  617,  618,  619,  620,  621,  622,  623,  624,  625,
  626,  627,  628,  629,  630,  631,  632,  633,  634,  635,
  636,  637,  638,  639,  640,  641,  642,  643,  644,   -1,
   -1,   -1,   -1,   -1,  650,   -1,  617,  618,  619,  620,
  621,  622,  623,  624,  625,  626,  627,  628,  629,  630,
  631,  632,  633,  634,  635,  636,  637,  638,  639,  640,
  641,  642,  643,  644,   -1,   -1,   -1,   -1,   -1,  650,
 1379,  617,  618,  619,  620,  621,  622,  623,  624,  625,
  626,  627,  628,  629,  630,  631,  632,  633,  634,  635,
  636,  637,  638,  639,  640,  641,  642,  643,  644,   -1,
   -1,   -1,   -1,   -1,  650,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  974,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1, 1712, 1713,   -1, 1715,   -1,
   -1,   -1,   -1, 1720,   -1,   -1, 1723, 1724, 1725, 1726,
 1727,   -1,   -1, 1730, 1731,   -1,   -1,   -1, 1735,   -1,
   -1,   -1, 1739,   -1,   -1,   -1,   -1,   -1, 1024,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, 1488,
   -1, 1490,   -1,   -1,   -1,   -1,   -1, 1496,   -1, 1498,
   -1,   -1,   -1, 1049,   -1,   -1,   -1,   -1, 1054,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1, 1067, 1068,   -1,   -1,   -1,   -1,   -1,   -1, 1796,
 1797,   -1,   -1, 1532, 1801, 1534,  617,  618,  619,  620,
  621,  622,  623,  624,  625,  626,  627,  628,  629,  630,
  631,  632,  633,  634,  635,  636,  637,  638,  639,  640,
  641,  642,  643,  644,   -1,   -1, 1833, 1834,   -1,  650,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1, 1129,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1, 1869,   -1,   -1,   -1,   -1, 1874,   -1,   -1,
 1877, 1878, 1879, 1880, 1881,   -1,   -1,   -1, 1885,   -1,
   -1,   -1,   -1, 1890,   -1,   -1,   -1, 1894, 1895,   -1,
   -1,   -1,   -1,   -1,   -1,   -1, 1903, 1904,  617,  618,
  619,  620,  621,  622,  623,  624,  625,  626,  627,  628,
  629,  630,  631,  632,  633,  634,  635,  636,  637,  638,
  639,  640,  641,  642,  643,  644,   -1,   -1,   -1,   -1,
   -1,  650,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 1947,  617,  618,  619,  620,  621,  622,  623,  624,  625,
  626,  627,  628,  629,  630,  631,  632,  633,  634,  635,
  636,  637,  638,  639,  640,  641,  642,  643,  644,   -1,
   -1, 1978,   -1, 1712,  650,   -1,   -1,   -1,   -1,   -1,
   -1, 1720,   -1,   -1, 1723,   -1,   -1,   -1,  125,   -1,
   -1,   -1, 1731, 2000,   -1,   -1,   -1,   -1,   -1,   -1,
   -1, 2008,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1, 2021,   -1, 2023, 2024,   -1,   -1,
   -1,   -1, 2029,   -1,   -1, 2032,   -1,   -1, 2035,   -1,
   -1,   -1,   -1,   -1,   -1,   -1, 2043,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1, 2059,   -1,   -1, 2062,   -1,   -1,   -1,   -1,
   -1,   -1,   -1, 2070,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1, 2082,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2096,
   -1, 2098, 2099, 1379, 1380,   -1,   -1,   -1,   -1,   -1,
 2107,   -1, 2109,   -1,   -1,   -1, 2113,   -1,   -1,   -1,
   -1,   -1,   -1,   -1, 2121, 2122,   -1, 2124, 2125,   -1,
   -1,   -1,   -1,   -1,   -1,   -1, 2133,   -1, 2135, 2136,
 1869,   -1,   -1,   -1,   -1, 1874, 2143,   -1, 1877,   -1,
 2147, 2148, 1881, 2150,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2164,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1, 2183,   -1,   -1, 2186,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1, 1478,   -1,   -1,   -1,   -1,   -1, 2205,   -1,
 1486,   -1, 1488,   -1, 1490,   -1,   -1, 2214, 2215, 2216,
 1496, 2218, 1498,   -1,   -1, 2222, 2223,   -1, 2225, 2226,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1, 2238,   -1,   -1, 2241, 2242,   -1,   -1,   -1, 1978,
   -1,   -1, 1528,   -1,   -1, 2252, 1532,   -1, 1534,   -1,
 1536,   -1, 2259,   -1, 1540, 2262, 1542,   -1,   -1,   -1,
 2267,   -1,   -1,   -1,   -1,   -1, 1552,   -1,   -1,   -1,
   -1, 2278,   -1,   -1, 2281, 2282, 2283,   -1, 2285,   -1,
   -1,   -1, 2289, 2290, 2023, 2292, 2293,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2305, 2306,
   -1,   -1,   -1,   -1, 2043,   -1,   -1,   -1, 2315,   -1,
   -1,   -1,   -1,   -1,   -1, 2322,   -1,   -1, 2325,   -1,
   -1,   -1,   -1, 2330, 2331,   -1,   -1,   -1, 2335,   -1,
   -1,   -1,   -1, 2340,   -1, 2342, 2343, 2344,   -1, 2346,
 2347,   -1,   -1, 2350,   -1,   -1,   -1, 2354, 2355,   -1,
   -1,   -1,   -1,   -1,   -1, 2362,   -1,   -1,   -1, 2366,
   -1,   -1, 2369, 2370,   -1,   -1,   -1,   -1, 2107, 2376,
   -1,   -1,   -1,   -1,   -1,   -1, 2383,   -1, 2385,   -1,
 2387,   -1, 2389,   -1,   -1,   -1,   -1, 2394,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1, 2135,   -1, 2405,   -1,
   -1,   -1, 2409,   -1,   -1,   -1, 2413,   -1,   -1,   -1,
   -1,   -1,   -1, 2420,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1, 2164, 1712, 1713,   -1, 1715,
   -1,   -1,   -1,   -1, 1720,   -1,   -1, 1723, 1724, 1725,
 1726, 1727,   -1,   -1, 1730, 1731,   -1,   -1,   -1, 1735,
   -1,   -1,   -1, 1739,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1, 2214, 2215, 2216,   -1, 2218,
  617,  618,  619,  620,  621,  622,  623,  624,  625,  626,
  627,  628,  629,  630,  631,  632,  633,  634,  635,  636,
  637,  638,  639,  640,  641,  642,  643,  644,   -1,   -1,
 1796, 1797,   -1, 2252,   -1, 1801,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  284,  285,
  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,
   -1,   -1, 2281, 2282, 2283,   -1, 2285, 1833, 1834,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,   -1,
   -1,   -1,   -1,  329,   -1,   -1, 2315,   -1,  334,   -1,
   -1,   -1,   -1, 1869,   -1,   -1,   -1,   -1, 1874,   -1,
   -1, 1877, 1878, 1879, 1880, 1881,   -1,   -1,   -1, 1885,
   -1, 2340,   -1, 2342, 1890,   -1,   -1,   -1, 1894, 1895,
   -1,   -1,   -1,   -1,   -1,   -1,   -1, 1903, 1904,  375,
   -1,   -1,   -1, 2362,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1, 2383,   -1,   -1,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,   -1,   -1,   -1,
   -1, 1947,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1, 2420,   -1,  439,  440,   -1,   -1,   -1,   -1,   -1,
   -1,   -1, 1978,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1, 2000,   -1,   -1,   -1,   -1,   -1,
   -1,   -1, 2008,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1, 2021,   -1, 2023, 2024,   -1,
  496,   -1,   -1, 2029,   -1,   -1, 2032,   -1,   -1, 2035,
   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2043,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1, 2059,   -1,   -1, 2062,   -1,   -1,   -1,
   -1,   -1,   -1,   -1, 2070,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1, 2082,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
 2096,   -1, 2098, 2099,   -1,   -1,   -1,   -1,   -1,   -1,
   -1, 2107,   -1, 2109,   -1,   -1,   -1, 2113,   -1,   -1,
   -1,   -1,   -1,   -1,   -1, 2121, 2122,   -1, 2124, 2125,
   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2133,   -1, 2135,
 2136,   -1,   -1,   -1,   -1,   -1,   -1, 2143,   -1,   -1,
   -1, 2147, 2148,   -1, 2150,   -1,   -1,   -1,   -1,   44,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2164,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2183,   44,  655,
 2186,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,   -1,   -1,   -1,   -1,   -1, 2205,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2214, 2215,
 2216,   -1, 2218,   -1,   -1,   -1, 2222, 2223,   -1, 2225,
 2226,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  125,   -1, 2238,   -1,   -1, 2241, 2242,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1, 2252,   -1,   -1,   -1,
   -1,   -1,   -1, 2259,   -1,   -1, 2262,   -1,   -1,  125,
   -1, 2267,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1, 2278,   -1,   -1, 2281, 2282, 2283,   -1, 2285,
   -1,   -1,   -1, 2289, 2290,   -1, 2292, 2293,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2305,
 2306,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2315,
   -1,   -1,   -1,   -1,   -1,   -1, 2322,   -1,   -1, 2325,
   -1,   -1,   -1,   -1, 2330, 2331,   -1,   -1,   -1, 2335,
   -1,   -1,   -1,   -1, 2340,   -1, 2342, 2343, 2344,   -1,
 2346, 2347,   -1,   -1, 2350,   -1,   -1,   -1, 2354, 2355,
   -1,   -1,   -1,   -1,   -1,   -1, 2362,   -1,   -1,   -1,
 2366,   -1,   -1, 2369, 2370,   -1,   -1,   -1,   -1,   -1,
 2376,   -1,   -1,   -1,   -1,   -1,   -1, 2383,   -1, 2385,
   -1, 2387,   -1, 2389,   -1,   -1,   -1,   -1, 2394,   -1,
  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2405,
   -1,   -1,   -1, 2409,   -1,   -1,   -1, 2413,  274,  275,
   -1,   -1,   -1,   -1, 2420,   -1,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,   -1,
   -1,  297,  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,  312,  313,  314,  315,
  316,  317,  318,  319,   -1,  321,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,  330,   -1,   -1,  333,  334,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,
  356,  357,  358,  359,   -1,   -1,   -1,   -1,   -1,  365,
  366,   -1,   -1,   -1,   -1,  371,  372,  373,  374,  375,
  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,  401,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,   -1,  435,
  436,  437,  438,  439,  440,  441,  442,  443,  444,  445,
  446,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,  464,  465,
  466,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  510,   -1,  512,  513,   -1,   -1,
  516,  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,  527,  528,  125,   -1,  531,   -1,   -1,  534,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,  544,  545,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,
   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,
  586,  587,  617,  618,  619,  620,  621,  622,  623,  624,
  625,  626,  627,  628,  629,  630,  631,  632,  633,  634,
  635,  636,  637,  638,  639,  640,  641,  642,  643,  644,
  616,  617,  618,  619,  620,  621,  622,  623,  624,  625,
  626,  627,  628,  629,  630,  631,  632,  633,  634,  635,
  636,  637,  638,  639,  640,  641,  642,  643,  644,  645,
  646,  647,  648,  649,  650,  651,  652,  653,  654,  655,
   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  669,  670,  671,  672,  673,   -1,   -1,
   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
   -1,   -1,   -1,   -1,   -1,  297,  298,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
  312,  313,  314,  315,  316,  317,  318,  319,   -1,  321,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,  330,   -1,
   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,
   -1,   -1,   -1,  355,  356,  357,  358,  359,   -1,   -1,
   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,   -1,  371,
  372,  373,  374,  375,  376,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,  401,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   44,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,
  432,   -1,   -1,  435,  436,  437,  438,  439,  440,  441,
  442,  443,  444,  445,  446,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   59,  464,  465,  466,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,
  512,  513,   -1,   -1,  516,  517,  518,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,  527,  528,  125,   -1,  531,
   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,  544,  545,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,
   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  585,  586,  587,  617,  618,  619,  620,
  621,  622,  623,  624,  625,  626,  627,  628,  629,  630,
  631,  632,  633,  634,  635,  636,  637,  638,  639,  640,
  641,  642,  643,  644,  616,  617,  618,  619,  620,  621,
  622,  623,  624,  625,  626,  627,  628,  629,  630,  631,
  632,  633,  634,  635,  636,  637,  638,  639,  640,  641,
  642,  643,  644,  645,  646,  647,  648,  649,  650,  651,
  652,  653,  654,  655,   -1,   -1,   -1,   -1,  256,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,  670,  671,
  672,  673,   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,  282,  283,  284,  285,  286,  287,
  288,  289,  290,  291,   -1,   -1,   -1,   -1,   -1,  297,
  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,  312,  313,  314,  315,  316,  317,
  318,  319,   -1,  321,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,  330,   -1,   -1,  333,  334,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,  356,  357,
  358,  359,   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,
   -1,   -1,   -1,  371,  372,  373,  374,  375,  376,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,  401,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  430,   -1,  432,   -1,   -1,  435,  436,  437,
  438,  439,  440,  441,  442,  443,  444,  445,  446,   -1,
   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   59,  464,  465,  466,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  510,   -1,  512,  513,   -1,   -1,  516,  517,
  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,  527,
  528,  125,   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,  544,  545,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,
  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,  586,  587,
  617,  618,  619,  620,  621,  622,  623,  624,  625,  626,
  627,  628,  629,  630,  631,  632,  633,  634,  635,  636,
  637,  638,  639,  640,  641,  642,  643,  644,  616,  617,
  618,  619,  620,  621,  622,  623,  624,  625,  626,  627,
  628,  629,  630,  631,  632,  633,  634,  635,  636,  637,
  638,  639,  640,  641,  642,  643,  644,  645,  646,  647,
  648,  649,  650,  651,  652,  653,  654,  655,   -1,   -1,
   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  669,  670,  671,  672,  673,   -1,   -1,   -1,   -1,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   -1,   -1,
   -1,   -1,   -1,  297,  298,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,  312,  313,
  314,  315,  316,  317,  318,  319,   -1,  321,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,  330,   -1,   -1,  333,
  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,
   -1,  355,  356,  357,  358,  359,   -1,   -1,   -1,   -1,
   -1,  365,  366,   -1,   -1,   -1,   -1,  371,  372,  373,
  374,  375,  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,  401,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,
   -1,  435,  436,  437,  438,  439,  440,  441,  442,  443,
  444,  445,  446,   -1,   44,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
  464,  465,  466,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,  512,  513,
   -1,   -1,  516,  517,  518,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,  527,  528,  125,   -1,  531,   -1,   -1,
  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
  544,  545,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,
   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  585,  586,  587,  617,  618,  619,  620,  621,  622,
  623,  624,  625,  626,  627,  628,  629,  630,  631,  632,
  633,  634,  635,  636,  637,  638,  639,  640,  641,  642,
  643,  644,  616,  617,  618,  619,  620,  621,  622,  623,
  624,  625,  626,  627,  628,  629,  630,  631,  632,  633,
  634,  635,  636,  637,  638,  639,  640,  641,  642,  643,
  644,  645,  646,  647,  648,  649,  650,  651,  652,  653,
  654,  655,   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  669,  670,  671,  672,  673,
   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,
   -1,   -1,  282,  283,  284,  285,  286,  287,  288,  289,
  290,  291,   -1,   -1,   -1,   -1,   -1,  297,  298,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,  312,  313,  314,  315,  316,  317,  318,  319,
   -1,  321,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
  330,   -1,   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  351,   -1,   -1,   -1,  355,  356,  357,  358,  359,
   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,
   -1,  371,  372,  373,  374,  375,  376,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,  401,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   44,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  430,   -1,  432,   -1,   -1,  435,  436,  437,  438,  439,
  440,  441,  442,  443,  444,  445,  446,   -1,   44,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,  464,  465,  466,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  510,   -1,  512,  513,   -1,   -1,  516,  517,  518,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,  527,  528,  125,
   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,  544,  545,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  585,  586,  587,  617,  618,
  619,  620,  621,  622,  623,  624,  625,  626,  627,  628,
  629,  630,  631,  632,  633,  634,  635,  636,  637,  638,
  639,  640,  641,  642,  643,  644,  616,  617,  618,  619,
  620,  621,  622,  623,  624,  625,  626,  627,  628,  629,
  630,  631,  632,  633,  634,  635,  636,  637,  638,  639,
  640,  641,  642,  643,  644,  645,  646,  647,  648,  649,
  650,  651,  652,  653,  654,  655,   -1,   -1,   -1,   -1,
  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,
  670,  671,  672,  673,   -1,   -1,   -1,   -1,  274,  275,
   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,   -1,
   -1,  297,  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,  312,  313,  314,  315,
  316,  317,  318,  319,   -1,  321,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,  330,   -1,   -1,  333,  334,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,
  356,  357,  358,  359,   -1,   -1,   -1,   -1,   -1,  365,
  366,   -1,   -1,   -1,   -1,  371,  372,  373,  374,  375,
  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,  401,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,   -1,  435,
  436,  437,  438,  439,  440,  441,  442,  443,  444,  445,
  446,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,  464,  465,
  466,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  510,   -1,  512,  513,   -1,   -1,
  516,  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,  527,  528,  125,   -1,  531,   -1,   -1,  534,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,  544,  545,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,
   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,
  586,  587,  617,  618,  619,  620,  621,  622,  623,  624,
  625,  626,  627,  628,  629,  630,  631,  632,  633,  634,
  635,  636,  637,  638,  639,  640,  641,  642,  643,  644,
  616,  617,  618,  619,  620,  621,  622,  623,  624,  625,
  626,  627,  628,  629,  630,  631,  632,  633,  634,  635,
  636,  637,  638,  639,  640,  641,  642,  643,  644,  645,
  646,  647,  648,  649,  650,  651,  652,  653,  654,  655,
   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  669,  670,  671,  672,  673,   -1,   -1,
   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
   -1,   -1,   -1,   -1,   -1,  297,  298,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
  312,  313,  314,  315,  316,  317,  318,  319,   -1,  321,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,  330,   -1,
   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,
   -1,   -1,   -1,  355,  356,  357,  358,  359,   -1,   -1,
   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,   -1,  371,
  372,  373,  374,  375,  376,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,  401,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   44,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,
  432,   -1,   -1,  435,  436,  437,  438,  439,  440,  441,
  442,  443,  444,  445,  446,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   59,  464,  465,  466,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,
  512,  513,   -1,   -1,  516,  517,  518,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,  527,  528,  125,   -1,  531,
   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,  544,  545,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,
   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  585,  586,  587,  617,  618,  619,  620,
  621,  622,  623,  624,  625,  626,  627,  628,  629,  630,
  631,  632,  633,  634,  635,  636,  637,  638,  639,  640,
  641,  642,  643,  644,  616,  617,  618,  619,  620,  621,
  622,  623,  624,  625,  626,  627,  628,  629,  630,  631,
  632,  633,  634,  635,  636,  637,  638,  639,  640,  641,
  642,  643,  644,  645,  646,  647,  648,   -1,  650,  651,
  652,  653,  654,  655,   -1,   -1,   -1,   -1,  256,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,  670,  671,
  672,  673,   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,  282,  283,  284,  285,  286,  287,
  288,  289,  290,  291,   -1,   -1,   -1,   -1,   -1,  297,
  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,  312,  313,  314,  315,  316,  317,
  318,  319,   -1,  321,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,  330,   -1,   -1,  333,  334,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,  356,  357,
  358,  359,   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,
   -1,   -1,   -1,  371,  372,  373,  374,  375,  376,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,  401,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  430,   -1,  432,   -1,   -1,  435,  436,  437,
  438,  439,  440,  441,  442,  443,  444,  445,  446,   -1,
   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   59,  464,  465,  466,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  510,   -1,  512,  513,   -1,   -1,  516,  517,
  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,  527,
  528,  125,   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,  544,  545,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,
  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,  586,  587,
  617,  618,  619,  620,  621,  622,  623,  624,  625,  626,
  627,  628,  629,  630,  631,  632,  633,  634,  635,  636,
  637,  638,  639,  640,  641,  642,  643,  644,   -1,  617,
  618,  619,  620,  621,  622,  623,  624,  625,  626,  627,
  628,  629,  630,  631,  632,  633,  634,  635,  636,  637,
  638,  639,  640,  641,  642,  643,  644,  645,  646,   -1,
   -1,  649,  650,   -1,  652,  653,  654,  655,   -1,   -1,
   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  669,  670,  671,  672,  673,   -1,   -1,   -1,   -1,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   -1,   -1,
   -1,   -1,   -1,  297,  298,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,  312,  313,
  314,  315,  316,  317,  318,  319,   -1,  321,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,  330,   -1,   -1,  333,
  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,
   -1,  355,  356,  357,  358,  359,   -1,   -1,   -1,   -1,
   -1,  365,  366,   -1,   -1,   -1,   -1,  371,  372,  373,
  374,  375,  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,  401,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,
   -1,  435,  436,  437,  438,  439,  440,  441,  442,  443,
  444,  445,  446,   -1,   44,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
  464,  465,  466,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,  512,  513,
   -1,   -1,  516,  517,  518,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,  527,  528,  125,   -1,  531,   -1,   -1,
  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
  544,  545,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,
   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  585,  586,  587,  617,  618,  619,  620,  621,  622,
  623,  624,  625,  626,  627,  628,  629,  630,  631,  632,
  633,  634,  635,  636,  637,  638,  639,  640,  641,  642,
  643,  644,   -1,  617,  618,  619,  620,  621,  622,  623,
  624,  625,  626,  627,  628,  629,  630,  631,  632,  633,
  634,  635,  636,  637,  638,  639,  640,  641,  642,  643,
  644,  645,  646,   -1,   -1,   -1,  650,   -1,  652,  653,
  654,  655,   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  669,  670,  671,  672,  673,
   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,
   -1,   -1,  282,  283,  284,  285,  286,  287,  288,  289,
  290,  291,   -1,   -1,   -1,   -1,   -1,  297,  298,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,  312,  313,  314,  315,  316,  317,  318,  319,
   -1,  321,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
  330,   -1,   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  351,   -1,   -1,   -1,  355,  356,  357,  358,  359,
   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,
   -1,  371,  372,  373,  374,  375,  376,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,  401,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  430,   -1,  432,   -1,   -1,  435,  436,  437,  438,  439,
  440,  441,  442,  443,  444,  445,  446,   -1,   44,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,  464,  465,  466,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  510,   -1,  512,  513,   -1,   -1,  516,  517,  518,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,  527,  528,  125,
   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,  544,  545,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  585,  586,  587,   -1,  588,
  589,  590,  591,  592,  593,  594,  595,  596,  597,  598,
  599,  600,  601,  602,  603,  604,  605,  606,  607,  608,
  609,  610,  611,  612,  613,  614,  615,  617,  618,  619,
  620,  621,  622,  623,  624,  625,  626,  627,  628,  629,
  630,  631,  632,  633,  634,  635,  636,  637,  638,  639,
  640,  641,   -1,   -1,   -1,  645,  646,   -1,   -1,  649,
  650,   -1,  652,  653,  654,  655,   -1,   -1,   -1,   -1,
  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,
  670,  671,  672,  673,   -1,   -1,   -1,   -1,  274,  275,
   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,   -1,
   -1,  297,  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,  312,  313,  314,  315,
  316,  317,  318,  319,   -1,  321,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,  330,   -1,   -1,  333,  334,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,
  356,  357,  358,  359,   -1,   -1,   -1,   -1,   -1,  365,
  366,   -1,   -1,   -1,   -1,  371,  372,  373,  374,  375,
  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,  401,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,   -1,  435,
  436,  437,  438,  439,  440,  441,  442,  443,  444,  445,
  446,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,  464,  465,
  466,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  510,   -1,  512,  513,   -1,   -1,
  516,  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,  527,  528,  125,   -1,  531,   -1,   -1,  534,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,  544,  545,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,
   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,
  586,  587,  617,  618,  619,  620,  621,  622,  623,  624,
  625,  626,  627,  628,  629,  630,  631,  632,  633,  634,
  635,  636,  637,  638,  639,  640,  641,  642,  643,  644,
   -1,  617,  618,  619,  620,  621,  622,  623,  624,  625,
  626,  627,  628,  629,  630,  631,  632,  633,  634,  635,
  636,  637,  638,  639,  640,  641,   -1,   -1,   -1,  645,
  646,   -1,   -1,  649,  650,   -1,  652,  653,  654,  655,
   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  669,  670,  671,  672,  673,   -1,   -1,
   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
   -1,   -1,   -1,   -1,   -1,  297,  298,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
  312,  313,  314,  315,  316,  317,  318,  319,   -1,  321,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,  330,   -1,
   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,
   -1,   -1,   -1,  355,  356,  357,  358,  359,   -1,   -1,
   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,   -1,  371,
  372,  373,  374,  375,  376,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,  401,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,
  432,   -1,   -1,  435,  436,  437,  438,  439,  440,  441,
  442,  443,  444,  445,  446,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   59,  464,  465,  466,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,
  512,  513,   -1,   -1,  516,  517,  518,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,  527,  528,  125,   -1,  531,
   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,  544,  545,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,
   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  585,  586,  587,  617,  618,  619,  620,
  621,  622,  623,  624,  625,  626,  627,  628,  629,  630,
  631,  632,  633,  634,  635,  636,  637,  638,  639,  640,
  641,  642,  643,  644,   -1,  617,  618,  619,  620,  621,
  622,  623,  624,  625,  626,  627,  628,  629,  630,  631,
  632,  633,  634,  635,  636,  637,  638,  639,   -1,   -1,
   -1,   -1,   -1,  645,  646,   -1,   -1,  649,  650,   -1,
  652,  653,  654,  655,   -1,   -1,   -1,   -1,  256,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,  670,  671,
  672,  673,   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,  282,  283,  284,  285,  286,  287,
  288,  289,  290,  291,   -1,   -1,   -1,   -1,   -1,  297,
  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,  312,  313,  314,  315,  316,  317,
  318,  319,   -1,  321,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,  330,   -1,   -1,  333,  334,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,  356,  357,
  358,  359,   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,
   -1,   -1,   -1,  371,  372,  373,  374,  375,  376,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,  401,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  430,   -1,  432,   -1,   -1,  435,  436,  437,
  438,  439,  440,  441,  442,  443,  444,  445,  446,   -1,
   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   59,  464,  465,  466,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  510,   -1,  512,  513,   -1,   -1,  516,  517,
  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,  527,
  528,  125,   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,  544,  545,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,
  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,  586,  587,
  617,  618,  619,  620,  621,  622,  623,  624,  625,  626,
  627,  628,  629,  630,  631,  632,  633,  634,  635,  636,
  637,  638,  639,  640,  641,  642,  643,  644,   -1,  617,
  618,  619,  620,  621,  622,  623,  624,  625,  626,  627,
  628,  629,  630,  631,  632,  633,  634,  635,  636,  637,
  638,  639,   -1,   -1,   -1,   -1,   -1,  645,  646,   -1,
   -1,  649,  650,   -1,  652,  653,  654,  655,   -1,   -1,
   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  669,  670,  671,  672,  673,   -1,   -1,   -1,   -1,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   -1,   -1,
   -1,   -1,   -1,  297,  298,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,  312,  313,
  314,  315,  316,  317,  318,  319,   -1,  321,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,  330,   -1,   -1,  333,
  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,
   -1,  355,  356,  357,  358,  359,   -1,   -1,   -1,   -1,
   -1,  365,  366,   -1,   -1,   -1,   -1,  371,  372,  373,
  374,  375,  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,  401,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,
   -1,  435,  436,  437,  438,  439,  440,  441,  442,  443,
  444,  445,  446,   -1,   44,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
  464,  465,  466,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,  512,  513,
   -1,   -1,  516,  517,  518,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,  527,  528,  125,   -1,  531,   -1,   -1,
  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
  544,  545,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,
   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  585,  586,  587,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  617,  618,  619,  620,  621,  622,  623,
  624,  625,  626,  627,  628,  629,  630,  631,  632,  633,
  634,  635,  636,  637,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  645,  646,   -1,   -1,  649,  650,   -1,  652,  653,
  654,  655,   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  669,  670,  671,  672,  673,
   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,
   -1,   -1,  282,  283,  284,  285,  286,  287,  288,  289,
  290,  291,   -1,   -1,   -1,   -1,   -1,  297,  298,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,  312,  313,  314,  315,  316,  317,  318,  319,
   -1,  321,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
  330,   -1,   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  351,   -1,   -1,   -1,  355,  356,  357,  358,  359,
   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,
   -1,  371,  372,  373,  374,  375,  376,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,  401,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  430,   -1,  432,   -1,   -1,  435,  436,  437,  438,  439,
  440,  441,  442,  443,  444,  445,  446,   -1,   44,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,  464,  465,  466,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  510,   -1,  512,  513,   -1,   -1,  516,  517,  518,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,  527,  528,  125,
   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,  544,  545,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  585,  586,  587,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  617,  618,  619,
  620,  621,  622,  623,  624,  625,  626,  627,  628,  629,
  630,  631,  632,  633,  634,  635,  636,  637,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  645,  646,   -1,   -1,  649,
  650,   -1,  652,  653,  654,  655,   -1,   -1,   -1,   -1,
  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,
  670,  671,  672,  673,   -1,   -1,   -1,   -1,  274,  275,
   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,   -1,
   -1,  297,  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,  312,  313,  314,  315,
  316,  317,  318,  319,   -1,  321,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,  330,   -1,   -1,  333,  334,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,
  356,  357,  358,  359,   -1,   -1,   -1,   -1,   -1,  365,
  366,   -1,   -1,   -1,   -1,  371,  372,  373,  374,  375,
  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,  401,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,   -1,  435,
  436,  437,  438,  439,  440,  441,  442,  443,  444,  445,
  446,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,  464,  465,
  466,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  510,   -1,  512,  513,   -1,   -1,
  516,  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,  527,  528,  125,   -1,  531,   -1,   -1,  534,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,  544,  545,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,
   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,
  586,  587,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  617,  618,  619,  620,  621,  622,  623,  624,  625,
  626,  627,  628,  629,  630,  631,  632,  633,  634,  635,
  636,  637,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  645,
  646,   -1,   -1,  649,  650,   -1,  652,  653,  654,  655,
   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  669,  670,  671,  672,  673,   -1,   -1,
   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
   -1,   -1,   -1,   -1,   -1,  297,  298,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
  312,  313,  314,  315,  316,  317,  318,  319,   -1,  321,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,  330,   -1,
   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,
   -1,   -1,   -1,  355,  356,  357,  358,  359,   -1,   -1,
   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,   -1,  371,
  372,  373,  374,  375,  376,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,  401,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,
  432,   -1,   -1,  435,  436,  437,  438,  439,  440,  441,
  442,  443,  444,  445,  446,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   59,  464,  465,  466,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,
  512,  513,   -1,   -1,  516,  517,  518,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,  527,  528,  125,   -1,  531,
   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,  544,  545,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,
   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  585,  586,  587,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  617,  618,  619,  620,  621,
  622,  623,  624,  625,  626,  627,  628,  629,  630,  631,
  632,  633,  634,  635,  636,  637,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  645,  646,   -1,   -1,  649,  650,   -1,
  652,  653,  654,  655,   -1,   -1,   -1,   -1,  256,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,  670,  671,
  672,  673,   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,  282,  283,  284,  285,  286,  287,
  288,  289,  290,  291,   -1,   -1,   -1,   -1,   -1,  297,
  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,  312,  313,  314,  315,  316,  317,
  318,  319,   -1,  321,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,  330,   -1,   -1,  333,  334,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,  356,  357,
  358,  359,   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,
   -1,   -1,   -1,  371,  372,  373,  374,  375,  376,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,  401,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  430,   -1,  432,   -1,   -1,  435,  436,  437,
  438,  439,  440,  441,  442,  443,  444,  445,  446,   -1,
   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   59,  464,  465,  466,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  510,   -1,  512,  513,   -1,   -1,  516,  517,
  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,  527,
  528,  125,   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,  544,  545,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,
  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,  586,  587,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  617,
  618,  619,  620,  621,  622,  623,  624,  625,  626,  627,
  628,  629,  630,  631,  632,  633,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  645,  646,   -1,
   -1,  649,  650,   -1,  652,  653,  654,  655,   -1,   -1,
   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  669,  670,  671,  672,  673,   -1,   -1,   -1,   -1,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   -1,   -1,
   -1,   -1,   -1,  297,  298,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,  312,  313,
  314,  315,  316,  317,  318,  319,   -1,  321,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,  330,   -1,   -1,  333,
  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,
   -1,  355,  356,  357,  358,  359,   -1,   -1,   -1,   -1,
   -1,  365,  366,   -1,   -1,   -1,   -1,  371,  372,  373,
  374,  375,  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,  401,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,
   -1,  435,  436,  437,  438,  439,  440,  441,  442,  443,
  444,  445,  446,   -1,   44,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
  464,  465,  466,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,  512,  513,
   -1,   -1,  516,  517,  518,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,  527,  528,  125,   -1,  531,   -1,   -1,
  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
  544,  545,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,
   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  585,  586,  587,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  617,  618,  619,  620,  621,  622,  623,
  624,  625,  626,  627,  628,  629,  630,  631,  632,  633,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  645,  646,   -1,   -1,  649,  650,   -1,  652,  653,
  654,  655,   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  669,  670,  671,  672,  673,
   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,
   -1,   -1,  282,  283,  284,  285,  286,  287,  288,  289,
  290,  291,   -1,   -1,   -1,   -1,   -1,  297,  298,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,  312,  313,  314,  315,  316,  317,  318,  319,
   -1,  321,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
  330,   -1,   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  351,   -1,   -1,   -1,  355,  356,  357,  358,  359,
   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,
   -1,  371,  372,  373,  374,  375,  376,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,  401,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  430,   -1,  432,   -1,   -1,  435,  436,  437,  438,  439,
  440,  441,  442,  443,  444,  445,  446,   -1,   44,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,  464,  465,  466,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  510,   -1,  512,  513,   -1,   -1,  516,  517,  518,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,  527,  528,  125,
   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,  544,  545,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  585,  586,  587,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  617,  618,  619,
  620,  621,  622,  623,  624,  625,  626,  627,  628,  629,
  630,  631,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  645,  646,   -1,   -1,  649,
  650,   -1,  652,  653,  654,  655,   -1,   -1,   -1,   -1,
  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,
  670,  671,  672,  673,   -1,   -1,   -1,   -1,  274,  275,
   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,   -1,
   -1,  297,  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,  312,  313,  314,  315,
  316,  317,  318,  319,   -1,  321,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,  330,   -1,   -1,  333,  334,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,
  356,  357,  358,  359,   -1,   -1,   -1,   -1,   -1,  365,
  366,   -1,   -1,   -1,   -1,  371,  372,  373,  374,  375,
  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,  401,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,   -1,  435,
  436,  437,  438,  439,  440,  441,  442,  443,  444,  445,
  446,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,  464,  465,
  466,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  510,   -1,  512,  513,   -1,   -1,
  516,  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,  527,  528,  125,   -1,  531,   -1,   -1,  534,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,  544,  545,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,
   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,
  586,  587,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  617,  618,  619,  620,  621,  622,  623,  624,  625,
  626,  627,  628,  629,  630,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  645,
  646,   -1,   -1,  649,  650,   -1,  652,  653,  654,  655,
   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  669,  670,  671,  672,  673,   -1,   -1,
   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
   -1,   -1,   -1,   -1,   -1,  297,  298,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
  312,  313,  314,  315,  316,  317,  318,  319,   -1,  321,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,  330,   -1,
   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,
   -1,   -1,   -1,  355,  356,  357,  358,  359,   -1,   -1,
   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,   -1,  371,
  372,  373,  374,  375,  376,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,  401,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,
  432,   -1,   -1,  435,  436,  437,  438,  439,  440,  441,
  442,  443,  444,  445,  446,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   59,  464,  465,  466,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,
  512,  513,   -1,   -1,  516,  517,  518,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,  527,  528,  125,   -1,  531,
   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,  544,  545,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,
   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  585,  586,  587,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  617,  618,  619,  620,  621,
  622,  623,  624,  625,  626,  627,  628,  629,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  645,  646,   -1,   -1,  649,  650,   -1,
  652,  653,  654,  655,   -1,   -1,   -1,   -1,  256,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,  670,  671,
  672,  673,   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,  282,  283,  284,  285,  286,  287,
  288,  289,  290,  291,   -1,   -1,   -1,   -1,   -1,  297,
  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,  312,  313,  314,  315,  316,  317,
  318,  319,   -1,  321,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,  330,   -1,   -1,  333,  334,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,  356,  357,
  358,  359,   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,
   -1,   -1,   -1,  371,  372,  373,  374,  375,  376,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,  401,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  430,   -1,  432,   -1,   -1,  435,  436,  437,
  438,  439,  440,  441,  442,  443,  444,  445,  446,   -1,
   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   59,  464,  465,  466,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  510,   -1,  512,  513,   -1,   -1,  516,  517,
  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,  527,
  528,  125,   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,  544,  545,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,
  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,  586,  587,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  617,
  618,  619,  620,  621,  622,  623,  624,  625,  626,  627,
  628,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  645,  646,   -1,
   -1,  649,  650,   -1,  652,  653,  654,  655,   -1,   -1,
   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  669,  670,  671,  672,  673,   -1,   -1,   -1,   -1,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   -1,   -1,
   -1,   -1,   -1,  297,  298,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,  312,  313,
  314,  315,  316,  317,  318,  319,   -1,  321,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,  330,   -1,   -1,  333,
  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,
   -1,  355,  356,  357,  358,  359,   -1,   -1,   -1,   -1,
   -1,  365,  366,   -1,   -1,   -1,   -1,  371,  372,  373,
  374,  375,  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,  401,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,
   -1,  435,  436,  437,  438,  439,  440,  441,  442,  443,
  444,  445,  446,   -1,   44,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
  464,  465,  466,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,  512,  513,
   -1,   -1,  516,  517,  518,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,  527,  528,  125,   -1,  531,   -1,   -1,
  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
  544,  545,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,
   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  585,  586,  587,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  617,  618,  619,  620,  621,  622,  623,
  624,  625,  626,  627,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  645,  646,   -1,   -1,  649,  650,   -1,  652,  653,
  654,  655,   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  669,  670,  671,  672,  673,
   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,
   -1,   -1,  282,  283,  284,  285,  286,  287,  288,  289,
  290,  291,   -1,   -1,   -1,   -1,   -1,  297,  298,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,  312,  313,  314,  315,  316,  317,  318,  319,
   -1,  321,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
  330,   -1,   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  351,   -1,   -1,   -1,  355,  356,  357,  358,  359,
   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,
   -1,  371,  372,  373,  374,  375,  376,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,  401,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  430,   -1,  432,   -1,   -1,  435,  436,  437,  438,  439,
  440,  441,  442,  443,  444,  445,  446,   -1,   44,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,  464,  465,  466,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  510,   -1,  512,  513,   -1,   -1,  516,  517,  518,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,  527,  528,  125,
   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,  544,  545,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  585,  586,  587,  617,  618,
  619,  620,  621,  622,  623,  624,  625,  626,  627,  628,
  629,  630,  631,  632,  633,  634,  635,  636,  637,  638,
  639,  640,  641,  642,  643,  644,   -1,   -1,   -1,   -1,
   -1,  650,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  645,  646,   -1,   -1,  649,
  650,   -1,  652,  653,  654,  655,   -1,   -1,   -1,   -1,
  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,
  670,  671,  672,  673,   -1,   -1,   -1,   -1,  274,  275,
   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,   -1,
   -1,  297,  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,  312,  313,  314,  315,
  316,  317,  318,  319,   -1,  321,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,  330,   -1,   -1,  333,  334,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,
  356,  357,  358,  359,   -1,   -1,   -1,   -1,   -1,  365,
  366,   -1,   -1,   -1,   -1,  371,  372,  373,  374,  375,
  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,  401,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,   -1,  435,
  436,  437,  438,  439,  440,  441,  442,  443,  444,  445,
  446,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,  464,  465,
  466,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  510,   -1,  512,  513,   -1,   -1,
  516,  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,  527,  528,  125,   -1,  531,   -1,   -1,  534,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,  544,  545,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,
   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,
  586,  587,  616,  617,  618,  619,  620,  621,  622,  623,
  624,  625,  626,  627,  628,  629,  630,  631,  632,  633,
  634,  635,  636,  637,  638,  639,  640,  641,  642,  643,
  644,   -1,   -1,  647,  648,   -1,  650,  651,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  645,
  646,   -1,   -1,  649,  650,   -1,  652,  653,  654,  655,
   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  669,  670,  671,  672,  673,   -1,   -1,
   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
   -1,   -1,   -1,   -1,   -1,  297,  298,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
  312,  313,  314,  315,  316,  317,  318,  319,   -1,  321,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,  330,   -1,
   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,
   -1,   -1,   -1,  355,  356,  357,  358,  359,   -1,   -1,
   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,   -1,  371,
  372,  373,  374,  375,  376,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,  401,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,
  432,   -1,   -1,  435,  436,  437,  438,  439,  440,  441,
  442,  443,  444,  445,  446,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   59,  464,  465,  466,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,
  512,  513,   -1,   -1,  516,  517,  518,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,  527,  528,  125,   -1,  531,
   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,  544,  545,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,
   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  585,  586,  587,  616,  617,  618,  619,
  620,  621,  622,  623,  624,  625,  626,  627,  628,  629,
  630,  631,  632,  633,  634,  635,  636,  637,  638,  639,
  640,  641,  642,  643,  644,   -1,   -1,  647,  648,   -1,
  650,  651,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  645,  646,   -1,   -1,  649,  650,   -1,
  652,  653,  654,  655,   -1,   -1,   -1,   -1,  256,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,  670,  671,
  672,  673,   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,  282,  283,  284,  285,  286,  287,
  288,  289,  290,  291,   -1,   -1,   -1,   -1,   -1,  297,
  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,  312,  313,  314,  315,  316,  317,
  318,  319,   -1,  321,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,  330,   -1,   -1,  333,  334,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,  356,  357,
  358,  359,   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,
   -1,   -1,   -1,  371,  372,  373,  374,  375,  376,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,  401,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  430,   -1,  432,   -1,   -1,  435,  436,  437,
  438,  439,  440,  441,  442,  443,  444,  445,  446,   -1,
   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   59,  464,  465,  466,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  510,   -1,  512,  513,   -1,   -1,  516,  517,
  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,  527,
  528,  125,   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,  544,  545,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,
  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,  586,  587,
  616,  617,  618,  619,  620,  621,  622,  623,  624,  625,
  626,  627,  628,  629,  630,  631,  632,  633,  634,  635,
  636,  637,  638,  639,  640,  641,  642,  643,  644,   -1,
   -1,  647,  648,   -1,  650,  651,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  645,  646,   -1,
   -1,  649,  650,   -1,  652,  653,  654,  655,   -1,   -1,
   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  669,  670,  671,  672,  673,   -1,   -1,   -1,   -1,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   -1,   -1,
   -1,   -1,   -1,  297,  298,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,  312,  313,
  314,  315,  316,  317,  318,  319,   -1,  321,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,  330,   -1,   -1,  333,
  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,
   -1,  355,  356,  357,  358,  359,   -1,   -1,   -1,   -1,
   -1,  365,  366,   -1,   -1,   -1,   -1,  371,  372,  373,
  374,  375,  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,  401,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,
   -1,  435,  436,  437,  438,  439,  440,  441,  442,  443,
  444,  445,  446,   -1,   44,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
  464,  465,  466,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,  512,  513,
   -1,   -1,  516,  517,  518,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,  527,  528,  125,   -1,  531,   -1,   -1,
  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
  544,  545,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,
   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  585,  586,  587,  616,  617,  618,  619,  620,  621,
  622,  623,  624,  625,  626,  627,  628,  629,  630,  631,
  632,  633,  634,  635,  636,  637,  638,  639,  640,  641,
  642,  643,  644,   -1,   -1,  647,  648,   -1,  650,  651,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  645,  646,   -1,   -1,  649,  650,   -1,  652,  653,
  654,  655,   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  669,  670,  671,  672,  673,
   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,
   -1,   -1,  282,  283,  284,  285,  286,  287,  288,  289,
  290,  291,   -1,   -1,   -1,   -1,   -1,  297,  298,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,  312,  313,  314,  315,  316,  317,  318,  319,
   -1,  321,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
  330,   -1,   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  351,   -1,   -1,   -1,  355,  356,  357,  358,  359,
   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,
   -1,  371,  372,  373,  374,  375,  376,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,  401,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  430,   -1,  432,   -1,   -1,  435,  436,  437,  438,  439,
  440,  441,  442,  443,  444,  445,  446,   -1,   44,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,  464,  465,  466,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  510,   -1,  512,  513,   -1,   -1,  516,  517,  518,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,  527,  528,  125,
   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,  544,  545,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  585,  586,  587,  616,  617,
  618,  619,  620,  621,  622,  623,  624,  625,  626,  627,
  628,  629,  630,  631,  632,  633,  634,  635,  636,  637,
  638,  639,  640,  641,  642,  643,  644,   -1,   -1,  647,
  648,   -1,  650,  651,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  645,  646,   -1,   -1,  649,
  650,   -1,  652,  653,  654,  655,   -1,   -1,   -1,   -1,
  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,
  670,  671,  672,  673,   -1,   -1,   -1,   -1,  274,  275,
   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,   -1,
   -1,  297,  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,  312,  313,  314,  315,
  316,  317,  318,  319,   -1,  321,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,  330,   -1,   -1,  333,  334,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,
  356,  357,  358,  359,   -1,   -1,   -1,   -1,   -1,  365,
  366,   -1,   -1,   -1,   -1,  371,  372,  373,  374,  375,
  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,  401,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,   -1,  435,
  436,  437,  438,  439,  440,  441,  442,  443,  444,  445,
  446,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,  464,  465,
  466,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  510,   -1,  512,  513,   -1,   -1,
  516,  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,  527,  528,  125,   -1,  531,   -1,   -1,  534,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,  544,  545,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,
   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,
  586,  587,  616,  617,  618,  619,  620,  621,  622,  623,
  624,  625,  626,  627,  628,  629,  630,  631,  632,  633,
  634,  635,  636,  637,  638,  639,  640,  641,  642,  643,
  644,   -1,   -1,  647,  648,   -1,  650,  651,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  645,
  646,   -1,   -1,  649,  650,   -1,  652,  653,  654,  655,
   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  669,  670,  671,  672,  673,   -1,   -1,
   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
   -1,   -1,   -1,   -1,   -1,  297,  298,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
  312,  313,  314,  315,  316,  317,  318,  319,   -1,  321,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,  330,   -1,
   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,
   -1,   -1,   -1,  355,  356,  357,  358,  359,   -1,   -1,
   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,   -1,  371,
  372,  373,  374,  375,  376,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,  401,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,
  432,   -1,   -1,  435,  436,  437,  438,  439,  440,  441,
  442,  443,  444,  445,  446,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   59,  464,  465,  466,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,
  512,  513,   -1,   -1,  516,  517,  518,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,  527,  528,  125,   -1,  531,
   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,  544,  545,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,
   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  585,  586,  587,  616,  617,  618,  619,
  620,  621,  622,  623,  624,  625,  626,  627,  628,  629,
  630,  631,  632,  633,  634,  635,  636,  637,  638,  639,
  640,  641,  642,  643,  644,   -1,   -1,  647,  648,   -1,
   -1,  651,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  645,  646,   -1,   -1,  649,  650,   -1,
  652,  653,  654,  655,   -1,   -1,   -1,   -1,  256,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,  670,  671,
  672,  673,   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,  282,  283,  284,  285,  286,  287,
  288,  289,  290,  291,   -1,   -1,   -1,   -1,   -1,  297,
  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,  312,  313,  314,  315,  316,  317,
  318,  319,   -1,  321,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,  330,   -1,   -1,  333,  334,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,  356,  357,
  358,  359,   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,
   -1,   -1,   -1,  371,  372,  373,  374,  375,  376,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,  401,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  430,   -1,  432,   -1,   -1,  435,  436,  437,
  438,  439,  440,  441,  442,  443,  444,  445,  446,   -1,
   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   59,  464,  465,  466,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  510,   -1,  512,  513,   -1,   -1,  516,  517,
  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,  527,
  528,  125,   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,  544,  545,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,
  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,  586,  587,
  617,  618,  619,  620,  621,  622,  623,  624,  625,  626,
  627,  628,  629,  630,  631,  632,  633,  634,  635,  636,
  637,  638,  639,  640,  641,  642,  643,  644,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  652,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  645,  646,   -1,
   -1,  649,  650,   -1,  652,  653,  654,  655,   -1,   -1,
   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  669,  670,  671,  672,  673,   -1,   -1,   -1,   -1,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   -1,   -1,
   -1,   -1,   -1,  297,  298,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,  312,  313,
  314,  315,  316,  317,  318,  319,   -1,  321,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,  330,   -1,   -1,  333,
  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,
   -1,  355,  356,  357,  358,  359,   -1,   -1,   -1,   -1,
   -1,  365,  366,   -1,   -1,   -1,   -1,  371,  372,  373,
  374,  375,  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,  401,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,
   -1,  435,  436,  437,  438,  439,  440,  441,  442,  443,
  444,  445,  446,   -1,   44,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
  464,  465,  466,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,  512,  513,
   -1,   -1,  516,  517,  518,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,  527,  528,  125,   -1,  531,   -1,   -1,
  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
  544,  545,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,
   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  585,  586,  587,  617,  618,  619,  620,  621,  622,
  623,  624,  625,  626,  627,  628,  629,  630,  631,  632,
  633,  634,  635,  636,  637,  638,  639,  640,  641,  642,
  643,  644,   -1,   -1,   -1,   -1,   -1,  650,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  645,  646,   -1,   -1,  649,  650,   -1,  652,  653,
  654,  655,   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  669,  670,  671,  672,  673,
   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,
   -1,   -1,  282,  283,  284,  285,  286,  287,  288,  289,
  290,  291,   -1,   -1,   -1,   -1,   -1,  297,  298,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,  312,  313,  314,  315,  316,  317,  318,  319,
   -1,  321,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
  330,   -1,   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  351,   -1,   -1,   -1,  355,  356,  357,  358,  359,
   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,
   -1,  371,  372,  373,  374,  375,  376,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,  401,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  430,   -1,  432,   -1,   -1,  435,  436,  437,  438,  439,
  440,  441,  442,  443,  444,  445,  446,   -1,   44,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,  464,  465,  466,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  510,   -1,  512,  513,   -1,   -1,  516,  517,  518,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,  527,  528,  125,
   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,  544,  545,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  585,  586,  587,  617,  618,
  619,  620,  621,  622,  623,  624,  625,  626,  627,  628,
  629,  630,  631,  632,  633,  634,  635,  636,  637,  638,
  639,  640,  641,  642,  643,  644,   -1,   -1,   -1,   -1,
   -1,  650,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  645,  646,   -1,   -1,  649,
  650,   -1,  652,  653,  654,  655,   -1,   -1,   -1,   -1,
  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,
  670,  671,  672,  673,   -1,   -1,   -1,   -1,  274,  275,
   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,   -1,
   -1,  297,  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,  312,  313,  314,  315,
  316,  317,  318,  319,   -1,  321,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,  330,   -1,   -1,  333,  334,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,
  356,  357,  358,  359,   -1,   -1,   -1,   -1,   -1,  365,
  366,   -1,   -1,   -1,   -1,  371,  372,  373,  374,  375,
  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,  401,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,   -1,  435,
  436,  437,  438,  439,  440,  441,  442,  443,  444,  445,
  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,  464,  465,
  466,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  510,   -1,  512,  513,   -1,   -1,
  516,  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,  527,  528,  125,   -1,  531,   -1,   -1,  534,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,  544,  545,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,
   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,
  586,  587,  617,  618,  619,  620,  621,  622,  623,  624,
  625,  626,  627,  628,  629,  630,  631,  632,  633,  634,
  635,  636,  637,  638,  639,  640,  641,  642,  643,  644,
   -1,   -1,   -1,   -1,   -1,  650,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  645,
  646,   -1,   -1,  649,  650,   -1,  652,  653,  654,  655,
   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  669,  670,  671,  672,  673,   -1,   -1,
   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
   -1,   -1,   -1,   -1,   -1,  297,  298,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
  312,  313,  314,  315,  316,  317,  318,  319,   -1,  321,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,  330,   -1,
   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,
   -1,   -1,   -1,  355,  356,  357,  358,  359,   -1,   -1,
   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,   -1,  371,
  372,  373,  374,  375,  376,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,  401,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,
  432,   -1,   -1,  435,  436,  437,  438,  439,  440,  441,
  442,  443,  444,  445,  446,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   59,  464,  465,  466,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,
  512,  513,   -1,   -1,  516,  517,  518,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,  527,  528,  125,   -1,  531,
   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,  544,  545,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,
   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  585,  586,  587,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  617,  618,  619,  620,  621,
  622,  623,  624,  625,  626,  627,  628,  629,  630,  631,
  632,  633,  634,  635,  636,  637,  638,  639,  640,  641,
  642,  643,  644,  645,  646,   -1,   -1,  649,   -1,   -1,
   -1,  653,  654,  655,   -1,   -1,   -1,   -1,  256,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,  670,  671,
  672,  673,   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,  282,  283,  284,  285,  286,  287,
  288,  289,  290,  291,   -1,   -1,   -1,   -1,   -1,  297,
  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,  312,  313,  314,  315,  316,  317,
  318,  319,   -1,  321,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,  330,   -1,   -1,  333,  334,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,  356,  357,
  358,  359,   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,
   -1,   -1,   -1,  371,  372,  373,  374,  375,  376,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,  401,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  430,   -1,  432,   -1,   -1,  435,  436,  437,
  438,  439,  440,  441,  442,  443,  444,  445,  446,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   59,  464,  465,  466,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  510,   -1,  512,  513,   -1,   -1,  516,  517,
  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,  527,
  528,  125,   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,  544,  545,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,
  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,  586,  587,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  617,
  618,  619,  620,  621,  622,  623,  624,  625,  626,  627,
  628,  629,  630,  631,  632,  633,  634,  635,  636,  637,
  638,  639,  640,  641,  642,  643,  644,  645,  646,   -1,
   -1,  649,   -1,   -1,   -1,  653,  654,  655,   -1,   -1,
   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  669,  670,  671,  672,  673,   -1,   -1,   -1,   -1,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   -1,   -1,
   -1,   -1,   -1,  297,  298,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,  312,  313,
  314,  315,  316,  317,  318,  319,   -1,  321,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,  330,   -1,   -1,  333,
  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,
   -1,  355,  356,  357,  358,  359,   -1,   -1,   -1,   -1,
   -1,  365,  366,   -1,   -1,   -1,   -1,  371,  372,  373,
  374,  375,  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,  401,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,
   -1,  435,  436,  437,  438,  439,  440,  441,  442,  443,
  444,  445,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
  464,  465,  466,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,  512,  513,
   -1,   -1,  516,  517,  518,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,  527,  528,  125,   -1,  531,   -1,   -1,
  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
  544,  545,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,
   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  585,  586,  587,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  617,  618,  619,  620,  621,  622,  623,
  624,  625,  626,  627,  628,  629,  630,  631,  632,  633,
  634,  635,  636,  637,  638,  639,  640,  641,  642,  643,
  644,  645,  646,   -1,   -1,  649,   -1,   -1,   -1,  653,
  654,  655,   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  669,  670,  671,  672,  673,
   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,
   -1,   -1,  282,  283,  284,  285,  286,  287,  288,  289,
  290,  291,   -1,   -1,   -1,   -1,   -1,  297,  298,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,  312,  313,  314,  315,  316,  317,  318,  319,
   -1,  321,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
  330,   -1,   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  351,   -1,   -1,   -1,  355,  356,  357,  358,  359,
   -1,   -1,   -1,   -1,   -1,  365,  366,   -1,   -1,   -1,
   -1,  371,  372,  373,  374,  375,  376,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,  401,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  430,   -1,  432,   -1,   -1,  435,  436,  437,  438,  439,
  440,  441,  442,  443,  444,  445,  446,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,  464,  465,  466,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  510,   -1,  512,  513,   -1,   -1,  516,  517,  518,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,  527,  528,  125,
   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,  544,  545,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  585,  586,  587,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  617,  618,  619,
  620,  621,  622,  623,  624,  625,  626,  627,  628,  629,
  630,  631,  632,  633,  634,  635,  636,  637,  638,  639,
  640,  641,  642,  643,  644,  645,  646,   -1,   -1,  649,
   -1,   -1,   -1,  653,  654,  655,   -1,   -1,   -1,   -1,
  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  669,
  670,  671,  672,  673,   -1,   -1,   -1,   -1,  274,  275,
   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,   -1,
   -1,  297,  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,  312,  313,  314,  315,
  316,  317,  318,  319,   -1,  321,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,  330,   -1,   -1,  333,  334,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,
  356,  357,  358,  359,   -1,   -1,   -1,   -1,   -1,  365,
  366,   -1,   -1,   -1,   -1,  371,  372,  373,  374,  375,
  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,  401,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,   -1,  435,
  436,  437,  438,  439,  440,  441,  442,  443,  444,  445,
  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,  464,  465,
  466,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  510,   -1,  512,  513,   -1,   -1,
  516,  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,  527,  528,  125,   -1,  531,   -1,   -1,  534,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,  544,  545,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,
   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,
  586,  587,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  617,  618,  619,  620,  621,  622,  623,  624,  625,
  626,  627,  628,  629,  630,  631,  632,  633,  634,  635,
  636,  637,  638,  639,  640,  641,  642,  643,  644,  645,
  646,   -1,   -1,  649,   -1,   -1,   -1,  653,  654,  655,
   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  669,  670,  671,  672,  673,   -1,   -1,
   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
   -1,   -1,   -1,   -1,   -1,  297,  298,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
  312,  313,  314,  315,  316,  317,  318,  319,   -1,  321,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,  330,   -1,
   -1,  333,  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  343,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  351,
   -1,   -1,   -1,  355,  356,  357,  358,  359,   -1,   -1,
   -1,   -1,   -1,  365,  366,   -1,   59,   -1,   -1,  371,
  372,  373,  374,  375,  376,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,  401,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,
  432,   -1,  125,  435,  436,  437,  438,  439,  440,  441,
  442,  443,  444,  445,  446,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  464,  465,  466,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,
  512,  513,   -1,   -1,  516,  517,  518,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,  527,  528,   -1,   -1,  531,
   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,  544,  545,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,
   -1,   -1,   -1,  256,   -1,   -1,  568,  569,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,  282,
  283,  284,  285,  286,  287,  288,  289,  290,  291,   -1,
   -1,   -1,   -1,   -1,  297,  298,  299,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,  312,
  313,  314,  315,  316,  317,  318,  319,   -1,  321,  322,
   -1,   -1,  325,   -1,   -1,   -1,  329,  330,   -1,   -1,
  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,
  343,  653,  654,  655,   -1,   -1,   -1,   -1,  351,   -1,
   -1,   -1,  355,  356,  357,  358,  359,  669,  670,  671,
  672,  673,  365,  366,   -1,   59,   -1,   -1,  371,  372,
  373,  374,  375,  376,  377,   -1,   -1,   -1,   -1,   -1,
   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,
  393,  394,  395,  396,  397,  398,  399,  400,  401,  402,
  403,  404,  405,  406,  407,  408,  409,  410,   -1,   -1,
  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,  432,
   -1,  125,  435,  436,  437,  438,  439,  440,  441,  442,
  443,  444,  445,  446,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  464,  465,  466,  467,  468,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,  512,
  513,   -1,   -1,  516,  517,  518,   -1,   -1,   -1,   -1,
   -1,   -1,  525,  526,  527,  528,   -1,   -1,  531,   -1,
   -1,  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,
  543,  544,  545,  546,  547,  548,  549,  550,  551,  552,
  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,   -1,
   -1,   -1,  256,   -1,   -1,  568,  569,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  274,  275,  585,  586,  587,   -1,   -1,   -1,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   -1,   -1,
   -1,   -1,   -1,  297,  298,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,  312,  313,
  314,  315,  316,  317,  318,  319,   -1,  321,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,  330,   -1,   -1,  333,
  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,
  653,  654,  655,   -1,   -1,   -1,   -1,  351,   -1,   -1,
   -1,  355,  356,  357,  358,  359,  669,  670,  671,  672,
  673,  365,  366,   -1,   59,   -1,   -1,  371,  372,  373,
  374,  375,  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,  401,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,
  125,  435,  436,  437,  438,  439,  440,  441,  442,  443,
  444,  445,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  464,  465,  466,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,  512,  513,
   -1,   -1,  516,  517,  518,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,  527,  528,   -1,   -1,  531,   -1,   -1,
  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
  544,  545,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,
   -1,  256,   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,
  275,  585,  586,  587,   -1,   -1,   -1,  282,  283,  284,
  285,  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,
   -1,   -1,  297,  298,  299,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  308,  309,  310,   -1,  312,  313,  314,
  315,  316,  317,  318,  319,   -1,  321,  322,   -1,   -1,
  325,   -1,   -1,   -1,  329,  330,   -1,   -1,  333,  334,
   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,
  654,  655,   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,
  355,  356,  357,  358,  359,  669,  670,  671,  672,  673,
  365,  366,   -1,   59,   -1,   -1,  371,  372,  373,  374,
  375,  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,
   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,
  395,  396,  397,  398,  399,  400,  401,  402,  403,  404,
  405,  406,  407,  408,  409,  410,   -1,   -1,  413,  414,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,  125,
  435,  436,  437,  438,  439,  440,  441,  442,  443,  444,
  445,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,
  465,  466,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,
  485,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  510,   -1,  512,  513,   -1,
   -1,  516,  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,
  525,  526,  527,  528,   -1,   -1,  531,   -1,   -1,  534,
   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,  544,
  545,  546,  547,  548,  549,  550,  551,  552,  553,   -1,
   -1,   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,
  256,   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,
  585,  586,  587,   -1,   -1,   -1,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,   -1,
   -1,  297,  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,  312,  313,  314,  315,
  316,  317,  318,  319,   -1,  321,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,  330,   -1,   -1,  333,  334,   -1,
  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,
  655,   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,
  356,  357,  358,  359,  669,  670,  671,  672,  673,  365,
  366,   -1,   59,   -1,   -1,  371,  372,  373,  374,  375,
  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,  401,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,  125,  435,
  436,  437,  438,  439,  440,  441,  442,  443,  444,  445,
  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,
  466,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  510,   -1,  512,  513,   -1,   -1,
  516,  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,  527,  528,   -1,   -1,  531,   -1,   -1,  534,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,  544,  545,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,  256,
   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,
  586,  587,   -1,   -1,   -1,  282,  283,  284,  285,  286,
  287,  288,  289,  290,  291,   -1,   -1,   -1,   -1,   -1,
  297,  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  308,  309,  310,   -1,  312,  313,  314,  315,  316,
  317,  318,  319,   -1,  321,  322,   -1,   -1,  325,   -1,
   -1,   -1,  329,  330,   -1,   -1,  333,  334,   -1,  645,
  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,
   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,  356,
  357,  358,  359,  669,  670,  671,  672,  673,  365,  366,
   -1,   59,   -1,   -1,  371,  372,  373,  374,  375,  376,
  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,
   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,
  397,  398,  399,  400,  401,  402,  403,  404,  405,  406,
  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  430,   -1,  432,   -1,  125,  435,  436,
  437,  438,  439,  440,  441,  442,  443,  444,  445,  446,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,  466,
  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  510,   -1,  512,  513,   -1,   -1,  516,
  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,
  527,  528,   -1,   -1,  531,   -1,   -1,  534,   -1,   -1,
   -1,   -1,   -1,   -1,  541,  542,  543,  544,  545,  546,
  547,  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,
   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,  256,   -1,
   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,
  587,   -1,   -1,   -1,  282,  283,  284,  285,  286,  287,
  288,  289,  290,  291,   -1,   -1,   -1,   -1,   -1,  297,
  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,  312,  313,  314,  315,  316,  317,
  318,  319,   -1,  321,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,  330,   -1,   -1,  333,  334,   -1,  645,  646,
   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,
   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,  356,  357,
  358,  359,  669,  670,  671,  672,  673,  365,  366,   -1,
   59,   -1,   -1,  371,  372,  373,  374,  375,  376,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,  401,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  430,   -1,  432,   -1,  125,  435,  436,  437,
  438,  439,  440,  441,  442,  443,  444,  445,  446,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,  466,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  510,   -1,  512,  513,   -1,   -1,  516,  517,
  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,  527,
  528,   -1,   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,  544,  545,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,  561,   -1,   -1,   -1,  256,   -1,   -1,
  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,
   -1,   -1,   -1,  282,  283,  284,  285,  286,  287,  288,
  289,  290,  291,   -1,   -1,   -1,   -1,   -1,  297,  298,
  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,
  309,  310,   -1,  312,  313,  314,  315,  316,  317,  318,
  319,   -1,  321,  322,   -1,   -1,  325,   -1,   -1,   -1,
  329,  330,   -1,   -1,  333,  334,   -1,  645,  646,   -1,
   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,
   -1,   -1,  351,   -1,   -1,   -1,  355,  356,  357,  358,
  359,  669,  670,  671,  672,  673,  365,  366,   -1,   59,
   -1,   -1,  371,  372,  373,  374,  375,  376,  377,   -1,
   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,
   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,  398,
  399,  400,  401,  402,  403,  404,  405,  406,  407,  408,
  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  430,   -1,  432,   -1,  125,  435,  436,  437,  438,
  439,  440,  441,  442,  443,  444,  445,  446,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  464,  465,  466,  467,  468,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  510,   -1,  512,  513,   -1,   -1,  516,  517,  518,
   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,  527,  528,
   -1,   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,   -1,
   -1,   -1,  541,  542,  543,  544,  545,  546,  547,  548,
  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,
   -1,  560,  561,   -1,   -1,   -1,  256,   -1,   -1,  568,
  569,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,
   -1,   -1,  282,  283,  284,  285,  286,  287,  288,  289,
  290,  291,   -1,   -1,   -1,   -1,   -1,  297,  298,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,  312,  313,  314,  315,  316,  317,  318,  319,
   -1,  321,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
  330,   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,
  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,
   -1,  351,   -1,   -1,   -1,  355,  356,  357,  358,  359,
  669,  670,  671,  672,  673,  365,  366,   -1,   59,   -1,
   -1,  371,  372,  373,  374,  375,  376,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,  401,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  430,   -1,  432,   -1,  125,  435,  436,  437,  438,  439,
  440,  441,  442,  443,  444,  445,  446,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  464,  465,  466,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  510,   -1,  512,  513,   -1,   -1,  516,  517,  518,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,  527,  528,   -1,
   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,  544,  545,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,  561,   -1,   -1,   -1,  256,   -1,   -1,  568,  569,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,
   -1,  282,  283,  284,  285,  286,  287,  288,  289,  290,
  291,   -1,   -1,   -1,   -1,   -1,  297,  298,  299,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,
   -1,  312,  313,  314,  315,  316,  317,  318,  319,   -1,
  321,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,  330,
   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,
   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,
  351,   -1,   -1,   -1,  355,  356,  357,  358,  359,  669,
  670,  671,  672,  673,  365,  366,   -1,   59,   -1,   -1,
  371,  372,  373,  374,  375,  376,  377,   -1,   -1,   -1,
   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,
  391,   -1,  393,  394,  395,  396,  397,  398,  399,  400,
  401,  402,  403,  404,  405,  406,  407,  408,  409,  410,
   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  430,
   -1,  432,   -1,  125,  435,  436,  437,  438,  439,  440,
  441,  442,  443,  444,  445,  446,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  464,  465,  466,  467,  468,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  510,
   -1,  512,  513,   -1,   -1,  516,  517,  518,   -1,   -1,
   -1,   -1,   -1,   -1,  525,  526,  527,  528,   -1,   -1,
  531,   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,   -1,
  541,  542,  543,  544,  545,  546,  547,  548,  549,  550,
  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,
  561,   -1,   -1,   -1,  256,   -1,   -1,  568,  569,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
   -1,   -1,   -1,   -1,   -1,  297,  298,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
  312,  313,  314,  315,  316,  317,  318,  319,   -1,  321,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,  330,   -1,
   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,
   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,  351,
   -1,   -1,   -1,  355,  356,  357,  358,  359,  669,  670,
  671,  672,  673,  365,  366,   -1,   59,   -1,   -1,  371,
  372,  373,  374,  375,  376,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,  401,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,
  432,   -1,  125,  435,  436,  437,  438,  439,  440,  441,
  442,  443,  444,  445,  446,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  464,  465,  466,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,
  512,  513,   -1,   -1,  516,  517,  518,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,  527,  528,   -1,   -1,  531,
   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,  544,  545,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,
   -1,   -1,   -1,  256,   -1,   -1,  568,  569,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,  282,
  283,  284,  285,  286,  287,  288,  289,  290,  291,   -1,
   -1,   -1,   -1,   -1,  297,  298,  299,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,  312,
  313,  314,  315,  316,  317,  318,  319,   -1,  321,  322,
   -1,   -1,  325,   -1,   -1,   -1,  329,  330,   -1,   -1,
  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,
  343,  653,  654,  655,   -1,   -1,   -1,   -1,  351,   -1,
   -1,   -1,  355,  356,  357,  358,  359,  669,  670,  671,
  672,  673,  365,  366,   -1,   59,   -1,   -1,  371,  372,
  373,  374,  375,  376,  377,   -1,   -1,   -1,   -1,   -1,
   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,
  393,  394,  395,  396,  397,  398,  399,  400,  401,  402,
  403,  404,  405,  406,  407,  408,  409,  410,   -1,   -1,
  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,  432,
   -1,  125,  435,  436,  437,  438,  439,  440,  441,  442,
  443,  444,  445,  446,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  464,  465,  466,  467,  468,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,  512,
  513,   -1,   -1,  516,  517,  518,   -1,   -1,   -1,   -1,
   -1,   -1,  525,  526,  527,  528,   -1,   -1,  531,   -1,
   -1,  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,
  543,  544,  545,  546,  547,  548,  549,  550,  551,  552,
  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,   -1,
   -1,   -1,  256,   -1,   -1,  568,  569,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  274,  275,  585,  586,  587,   -1,   -1,   -1,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   -1,   -1,
   -1,   -1,   -1,  297,  298,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,  312,  313,
  314,  315,  316,  317,  318,  319,   -1,  321,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,  330,   -1,   -1,  333,
  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,
  653,  654,  655,   -1,   -1,   -1,   -1,  351,   -1,   -1,
   -1,  355,  356,  357,  358,  359,  669,  670,  671,  672,
  673,  365,  366,   -1,   59,   -1,   -1,  371,  372,  373,
  374,  375,  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,  401,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,
  125,  435,  436,  437,  438,  439,  440,  441,  442,  443,
  444,  445,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  464,  465,  466,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,  512,  513,
   -1,   -1,  516,  517,  518,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,  527,  528,   -1,   -1,  531,   -1,   -1,
  534,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
  544,  545,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,
   -1,  256,   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,
  275,  585,  586,  587,   -1,   -1,   -1,  282,  283,  284,
  285,  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,
   -1,   -1,  297,  298,  299,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  308,  309,  310,   -1,  312,  313,  314,
  315,  316,  317,  318,  319,   -1,  321,  322,   -1,   -1,
  325,   -1,   -1,   -1,  329,  330,   -1,   -1,  333,  334,
   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,
  654,  655,   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,
  355,  356,  357,  358,  359,  669,  670,  671,  672,  673,
  365,  366,   -1,   59,   -1,   -1,  371,  372,  373,  374,
  375,  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,
   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,
  395,  396,  397,  398,  399,  400,  401,  402,  403,  404,
  405,  406,  407,  408,  409,  410,   -1,   -1,  413,  414,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,  125,
  435,  436,  437,  438,  439,  440,  441,  442,  443,  444,
  445,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,
  465,  466,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,
  485,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  510,   -1,  512,  513,   -1,
   -1,  516,  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,
  525,  526,  527,  528,   -1,   -1,  531,   -1,   -1,  534,
   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,  544,
  545,  546,  547,  548,  549,  550,  551,  552,  553,   -1,
   -1,   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,
  256,   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,
  585,  586,  587,   -1,   -1,   -1,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,   -1,
   -1,  297,  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,  312,  313,  314,  315,
  316,  317,  318,  319,   -1,  321,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,  330,   -1,   -1,  333,  334,   -1,
  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,
  655,   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,
  356,  357,  358,  359,  669,  670,  671,  672,  673,  365,
  366,   -1,   59,   -1,   -1,  371,  372,  373,  374,  375,
  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,  401,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,   -1,  435,
  436,  437,  438,  439,  440,  441,  442,  443,  444,  445,
  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,
  466,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  510,   -1,  512,  513,   -1,   -1,
  516,  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,  527,  528,   -1,   -1,  531,   -1,   -1,  534,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,  544,  545,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,  256,
   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,
  586,  587,   -1,   -1,   -1,  282,  283,  284,  285,  286,
  287,  288,  289,  290,  291,   -1,   -1,   -1,   -1,   -1,
  297,  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  308,  309,  310,   -1,  312,  313,  314,  315,  316,
  317,  318,  319,   -1,  321,  322,   -1,   -1,  325,   -1,
   -1,   -1,  329,  330,   -1,   -1,  333,  334,   -1,  645,
  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,
   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,  356,
  357,  358,  359,  669,  670,  671,  672,  673,  365,  366,
   -1,   59,   -1,   -1,  371,  372,  373,  374,  375,  376,
  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,
   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,
  397,  398,  399,  400,  401,  402,  403,  404,  405,  406,
  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  430,   -1,  432,   -1,  125,  435,  436,
  437,  438,  439,  440,  441,  442,  443,  444,  445,  446,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,  466,
  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  510,   -1,  512,  513,   -1,   -1,  516,
  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,
  527,  528,   -1,   -1,  531,   -1,   -1,  534,   -1,   -1,
   -1,   -1,   -1,   -1,  541,  542,  543,  544,  545,  546,
  547,  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,
   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,  256,   -1,
   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,
  587,   -1,   -1,   -1,  282,  283,  284,  285,  286,  287,
  288,  289,  290,  291,   -1,   -1,   -1,   -1,   -1,  297,
  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,  312,  313,  314,  315,  316,  317,
  318,  319,   -1,  321,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,  330,   -1,   -1,  333,  334,   -1,  645,  646,
   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,
   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,  356,  357,
  358,  359,  669,  670,  671,  672,  673,  365,  366,   -1,
   59,   -1,   -1,  371,  372,  373,  374,  375,  376,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,  401,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  430,   -1,  432,   -1,  125,  435,  436,  437,
  438,  439,  440,  441,  442,  443,  444,  445,  446,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,  466,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  510,   -1,  512,  513,   -1,   -1,  516,  517,
  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,  527,
  528,   -1,   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,  544,  545,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,
  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,
   -1,   -1,   -1,  282,  283,  284,  285,  286,  287,  288,
  289,  290,  291,   -1,   -1,   -1,   -1,   -1,  297,  298,
  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,
  309,  310,   -1,  312,  313,  314,  315,  316,  317,  318,
  319,   -1,  321,  322,   -1,   -1,  325,   -1,   -1,   -1,
  329,  330,   -1,   -1,  333,  334,   -1,  645,  646,   -1,
   -1,   -1,   -1,   -1,  343,  653,  654,  655,   -1,   -1,
   -1,   -1,  351,   -1,   -1,   -1,  355,  356,  357,  358,
  359,  669,  670,  671,  672,  673,  365,  366,   -1,   59,
   -1,   -1,  371,  372,  373,  374,  375,  376,  377,   -1,
   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,
   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,  398,
  399,  400,  401,  402,  403,  404,  405,  406,  407,  408,
  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  430,   -1,  432,   -1,  125,  435,  436,  437,  438,
  439,  440,  441,  442,  443,  444,  445,  446,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  464,  465,  466,  467,  468,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  510,   -1,  512,  513,   -1,   -1,  516,  517,  518,
   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,  527,  528,
   -1,   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,   -1,
   -1,   -1,  541,  542,  543,  544,  545,  546,  547,  548,
  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,
   -1,  560,  561,   -1,   -1,   -1,   -1,   -1,   -1,  568,
  569,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,
   -1,   -1,  282,  283,  284,  285,  286,  287,  288,  289,
  290,  291,   -1,   -1,   -1,   -1,   -1,  297,  298,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,  312,  313,  314,  315,  316,  317,  318,  319,
   -1,  321,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
  330,   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,
  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,
   -1,  351,   -1,   -1,   -1,  355,  356,  357,  358,  359,
  669,  670,  671,  672,  673,  365,  366,   -1,   -1,   -1,
   -1,  371,  372,  373,  374,  375,  376,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,  401,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  430,   -1,  432,   -1,  125,  435,  436,  437,  438,  439,
  440,  441,  442,  443,  444,  445,  446,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  464,  465,  466,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  510,   -1,  512,  513,   -1,   -1,  516,  517,  518,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,  527,  528,   -1,
   -1,  531,   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,  544,  545,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,  561,   -1,   -1,   -1,  256,   -1,   -1,  568,  569,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,
   -1,  282,  283,  284,  285,  286,  287,  288,  289,  290,
  291,   -1,   -1,   -1,   -1,   -1,  297,  298,  299,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,
   -1,  312,  313,  314,  315,  316,  317,  318,  319,   -1,
  321,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,  330,
   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,
   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,
  351,   -1,   -1,   -1,  355,  356,  357,  358,  359,  669,
  670,  671,  672,  673,  365,  366,   -1,   -1,   -1,   -1,
  371,  372,  373,  374,  375,  376,  377,   -1,   -1,   -1,
   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,
  391,   -1,  393,  394,  395,  396,  397,  398,  399,  400,
  401,  402,  403,  404,  405,  406,  407,  408,  409,  410,
   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  430,
   -1,  432,   -1,  125,  435,  436,  437,  438,  439,  440,
  441,  442,  443,  444,  445,  446,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  464,  465,  466,  467,  468,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  510,
   -1,  512,  513,   -1,   -1,  516,  517,  518,   -1,   -1,
   -1,   -1,   -1,   -1,  525,  526,  527,  528,   -1,   -1,
  531,   -1,   -1,  534,   -1,   -1,   -1,   -1,   -1,   -1,
  541,  542,  543,  544,  545,  546,  547,  548,  549,  550,
  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,
  561,   -1,   -1,   -1,  256,   -1,   -1,  568,  569,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
   -1,   -1,   -1,   -1,   -1,  297,  298,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
  312,  313,  314,  315,  316,  317,  318,  319,   -1,  321,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,  330,   -1,
   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,
   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,  351,
   -1,   -1,   -1,  355,  356,  357,  358,  359,  669,  670,
  671,  672,  673,  365,  366,  125,   -1,   -1,   -1,  371,
  372,  373,  374,  375,  376,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,  401,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  430,   -1,
  432,   -1,   -1,  435,  436,  437,  438,  439,  440,  441,
  442,  443,  444,  445,  446,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  464,  465,  466,  467,  468,  125,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  484,  485,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  510,   -1,
  512,  513,   -1,   -1,  516,  517,  518,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,  527,  528,   -1,   -1,  531,
   -1,   -1,  534,   -1,   -1,  125,   -1,   -1,   -1,  541,
  542,  543,  544,  545,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,  561,
   -1,   -1,   -1,   -1,   -1,   -1,  568,  569,   -1,   -1,
   -1,   -1,   -1,   -1,  334,   -1,   -1,   -1,   -1,   -1,
  340,  341,  342,  585,  586,  587,  346,   -1,   -1,   -1,
   -1,   -1,  352,  353,  354,   -1,   -1,   -1,   -1,   -1,
  360,  361,   -1,   -1,   -1,   -1,   -1,  367,  368,  369,
  370,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  378,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,  392,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,
   -1,  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  423,  424,  425,   -1,  669,  670,  671,
  672,  673,   -1,   -1,   -1,   -1,  334,   -1,   -1,   -1,
   -1,   -1,  340,  341,  342,   -1,   -1,   -1,  346,   -1,
   -1,   -1,   -1,   -1,  352,  353,  354,   -1,   -1,   -1,
   -1,   -1,  360,  361,   -1,   -1,   -1,   -1,   -1,  367,
  368,  369,  370,   -1,   -1,  475,  476,  477,  478,  479,
  378,   -1,   -1,   -1,   -1,   -1,  384,  487,  488,  489,
   -1,   -1,   -1,  391,  392,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  334,   -1,   -1,   -1,   -1,  509,
  340,  341,  342,   -1,   -1,   -1,  346,   -1,   -1,   -1,
   -1,   -1,  352,  353,  354,  423,  424,  425,   -1,   -1,
  360,  361,  532,  533,   -1,  535,  536,  367,  368,  369,
  370,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  378,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,  558,  559,
   -1,  391,  392,   -1,   -1,   -1,  566,  567,   -1,   -1,
   -1,   -1,  572,   -1,  574,  575,   -1,  475,  476,  477,
  478,  479,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  487,
  488,  489,   -1,  423,  424,  425,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  509,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  532,  533,   -1,  535,  536,   -1,
   -1,   -1,   -1,   -1,   -1,  475,  476,  477,  478,  479,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  487,  488,  489,
  558,  559,   -1,   -1,   -1,   -1,   -1,   -1,  566,  567,
   -1,   -1,   -1,   -1,  572,   -1,  574,  575,   -1,  509,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  532,  533,   -1,  535,  536,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  558,  559,
   -1,   -1,   -1,   -1,   -1,   -1,  566,  567,  274,  275,
   -1,   -1,  572,   -1,  574,  575,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,   -1,
   -1,  297,  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,  312,  313,  314,  315,
  316,  317,  318,  319,   -1,  321,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,  330,   -1,   -1,  333,  334,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  343,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  351,   -1,   -1,   -1,  355,
  356,  357,  358,  359,   -1,   -1,   -1,   -1,   -1,  365,
  366,   -1,   -1,   -1,   -1,  371,  372,  373,  374,  375,
  376,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,  401,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  430,   -1,  432,   -1,   -1,  435,
  436,  437,  438,  439,  440,  441,  442,  443,  444,  445,
  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,
  466,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  484,  485,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  510,   -1,  512,  513,   -1,   -1,
  516,  517,  518,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,  527,  528,   -1,   -1,  531,   -1,   -1,  534,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,  544,  545,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,  561,   -1,   -1,   -1,  256,
   -1,   -1,  568,  569,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,
  586,  587,   -1,   -1,   -1,   -1,  283,  284,  285,  286,
  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  308,  309,  310,   -1,   -1,  313,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,
   -1,   -1,  329,   -1,   -1,   -1,  333,  334,   -1,  645,
  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  358,  359,  669,  670,  671,  672,  673,  365,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,
  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,
   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,
  397,  398,  399,  400,   -1,  402,  403,  404,  405,  406,
  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,  436,
   -1,   -1,  439,  440,  441,   -1,  443,  444,   -1,  446,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,
  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,
  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,
   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  541,  542,  543,   -1,   -1,  546,
  547,  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,
   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  585,  586,
  587,   -1,   -1,   -1,   -1,  258,  259,  260,  261,  262,
  263,  264,  265,  266,  267,   -1,   -1,   -1,   -1,   -1,
   -1,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  283,  284,  285,  286,  287,  288,  289,  290,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  308,  309,  310,  645,  646,
  313,   -1,  649,   -1,   -1,   -1,  653,  654,  655,  322,
   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,
  333,  334,  669,  670,  671,  672,  673,   -1,   -1,   -1,
  343,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  358,  359,   -1,   -1,   -1,
   -1,   -1,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,
   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,
  393,  394,  395,  396,  397,  398,  399,  400,   -1,  402,
  403,  404,  405,  406,  407,  408,  409,  410,   -1,   -1,
  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,
   -1,   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,
  443,  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  284,  285,  286,  287,  288,  289,  290,   -1,   -1,
   -1,  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,
   -1,   -1,   -1,  496,   -1,   -1,  329,   -1,   -1,   -1,
   -1,  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,
  543,   -1,  375,  546,  547,  548,  549,  550,  551,  552,
  553,  384,   -1,   -1,   -1,   -1,   -1,  560,  391,   -1,
   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,
  403,  404,  405,  406,  407,  408,  409,  410,   -1,   -1,
  274,  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  299,  439,  440,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,
  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,
  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  496,  358,  359,  669,  670,  671,  672,
  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,   -1,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,
   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,
  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  284,  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,
  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  480,  481,  482,  483,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,
   -1,   -1,  496,   -1,   -1,  329,   -1,   -1,   -1,   -1,
  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,
   -1,   -1,  655,  517,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
   -1,  375,  546,  547,  548,  549,  550,  551,  552,  553,
  384,   -1,   -1,   -1,   -1,   -1,  560,  391,   -1,   -1,
   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  274,
  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  299,  439,  440,   -1,   -1,   -1,
   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,
  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,  334,
   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,
  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,  358,  359,  669,  670,  671,  672,  673,
  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,
  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,
   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,
  395,  396,  397,  398,  399,  400,   -1,  402,  403,  404,
  405,  406,  407,  408,  409,  410,   -1,   -1,  413,  414,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,
  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,  444,
   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  284,
  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,  464,
  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,
   -1,  496,   -1,   -1,  329,   -1,   -1,   -1,   -1,  334,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,
   -1,  655,  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,   -1,
  375,  546,  547,  548,  549,  550,  551,  552,  553,  384,
   -1,   -1,   -1,   -1,   -1,  560,  391,   -1,   -1,   -1,
   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,  403,  404,
  405,  406,  407,  408,  409,  410,   -1,   -1,  274,  275,
  585,  586,  587,   -1,   -1,   -1,   -1,  283,  284,  285,
  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  299,  439,  440,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,   -1,  313,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,  334,   -1,
  645,  646,   -1,   -1,  649,  650,   -1,  343,  653,  654,
  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  496,  358,  359,  669,  670,  671,  672,  673,  365,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,
   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,   -1,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,
  436,   -1,   -1,  439,  440,  441,   -1,  443,  444,   -1,
  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  284,  285,
  286,  287,  288,  289,  290,   -1,   -1,   -1,  464,  465,
   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,   -1,
  496,   -1,   -1,  329,   -1,   -1,   -1,   -1,  334,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,
  655,  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,   -1,  375,
  546,  547,  548,  549,  550,  551,  552,  553,  384,   -1,
   -1,   -1,   -1,   -1,  560,  391,   -1,   -1,   -1,   -1,
   -1,   -1,  568,   -1,   -1,   -1,   -1,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  274,  275,  585,
  586,  587,   -1,   -1,   -1,   -1,  283,  284,  285,  286,
  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  299,  439,  440,   -1,   -1,   -1,   -1,   -1,
   -1,  308,  309,  310,   -1,   -1,  313,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,
   -1,   -1,  329,   -1,   -1,   -1,  333,  334,   -1,  645,
  646,   -1,   -1,  649,  650,   -1,  343,  653,  654,  655,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,  358,  359,  669,  670,  671,  672,  673,  365,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,
  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,
   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,
  397,  398,  399,  400,   -1,  402,  403,  404,  405,  406,
  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,  436,
   -1,   -1,  439,  440,  441,   -1,  443,  444,   -1,  446,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  284,  285,  286,
  287,  288,  289,  290,   -1,   -1,   -1,  464,  465,   -1,
  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,   -1,  496,
   -1,   -1,  329,   -1,   -1,   -1,   -1,  334,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,  655,
  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,
   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  541,  542,  543,   -1,  375,  546,
  547,  548,  549,  550,  551,  552,  553,  384,   -1,   -1,
   -1,   -1,   -1,  560,  391,   -1,   -1,   -1,   -1,   -1,
   -1,  568,   -1,   -1,   -1,   -1,  403,  404,  405,  406,
  407,  408,  409,  410,   -1,   -1,  274,  275,  585,  586,
  587,   -1,   -1,   -1,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  299,  439,  440,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,   -1,   -1,   -1,  333,  334,   -1,  645,  646,
   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,
  358,  359,  669,  670,  671,  672,  673,  365,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,   -1,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,  436,   -1,
   -1,  439,  440,  441,   -1,  443,  444,   -1,  446,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  284,  285,  286,  287,
  288,  289,  290,   -1,   -1,   -1,  464,  465,   -1,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  322,   -1,   -1,   -1,  496,   -1,
   -1,  329,   -1,   -1,   -1,   -1,  334,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,  655,  517,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,
  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,   -1,  375,  546,  547,
  548,  549,  550,  551,  552,  553,  384,   -1,   -1,   -1,
   -1,   -1,  560,  391,   -1,   -1,   -1,   -1,   -1,   -1,
  568,   -1,   -1,   -1,   -1,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  274,  275,  585,  586,  587,
   -1,   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  299,  439,  440,   -1,   -1,   -1,   -1,   -1,   -1,  308,
  309,  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,
  329,   -1,   -1,   -1,  333,  334,   -1,  645,  646,   -1,
   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,  358,
  359,  669,  670,  671,  672,  673,  365,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,  377,   -1,
   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,
   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,  398,
  399,  400,   -1,  402,  403,  404,  405,  406,  407,  408,
  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  432,   -1,   -1,  435,  436,   -1,   -1,
  439,  440,  441,   -1,  443,  444,   -1,  446,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  284,  285,  286,  287,  288,
  289,  290,   -1,   -1,   -1,  464,  465,   -1,  467,  468,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  322,   -1,   -1,   -1,  496,   -1,   -1,
  329,   -1,   -1,   -1,   -1,  334,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  513,   -1,   -1,  655,  517,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,  528,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  541,  542,  543,   -1,  375,  546,  547,  548,
  549,  550,  551,  552,  553,  384,   -1,   -1,   -1,   -1,
   -1,  560,  391,   -1,   -1,   -1,   -1,   -1,   -1,  568,
   -1,   -1,   -1,   -1,  403,  404,  405,  406,  407,  408,
  409,  410,   -1,   -1,  274,  275,  585,  586,  587,   -1,
   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,
  439,  440,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
   -1,   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,
  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,  358,  359,
  669,  670,  671,  672,  673,  365,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  374,  375,   -1,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,   -1,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  432,   -1,   -1,  435,  436,   -1,   -1,  439,
  440,  441,   -1,  443,  444,   -1,  446,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  284,  285,  286,  287,  288,  289,
  290,   -1,   -1,   -1,  464,  465,   -1,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  322,   -1,   -1,   -1,  496,   -1,   -1,  329,
   -1,   -1,   -1,   -1,  334,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  513,   -1,   -1,  655,  517,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,  528,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,   -1,  375,  546,  547,  548,  549,
  550,  551,  552,  553,  384,   -1,   -1,   -1,   -1,   -1,
  560,  391,   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,
   -1,   -1,   -1,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,
   -1,   -1,  283,  284,  285,  286,  287,  288,  289,  290,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,  439,
  440,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,
   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,
   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,
   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,  358,  359,  669,
  670,  671,  672,  673,  365,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  374,  375,   -1,  377,   -1,   -1,   -1,
   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,
  391,   -1,  393,  394,  395,  396,  397,  398,  399,  400,
   -1,  402,  403,  404,  405,  406,  407,  408,  409,  410,
   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  432,   -1,   -1,  435,  436,   -1,   -1,  439,  440,
  441,   -1,  443,  444,   -1,  446,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  284,  285,  286,  287,  288,  289,  290,
   -1,   -1,   -1,  464,  465,   -1,  467,  468,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  322,   -1,   -1,   -1,  496,   -1,   -1,  329,   -1,
   -1,   -1,   -1,  334,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  513,   -1,   -1,  655,  517,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  525,  526,   -1,  528,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  541,  542,  543,   -1,  375,  546,  547,  548,  549,  550,
  551,  552,  553,  384,   -1,   -1,   -1,   -1,   -1,  560,
  391,   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,
   -1,   -1,  403,  404,  405,  406,  407,  408,  409,  410,
   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,
   -1,  283,  284,  285,  286,  287,  288,  289,  290,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,  439,  440,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,
   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,
   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  496,  358,  359,  669,  670,
  671,  672,  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  374,  375,   -1,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,   -1,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  432,   -1,   -1,  435,  436,   -1,   -1,  439,  440,  441,
   -1,  443,  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  284,  285,  286,  287,  288,  289,  290,   -1,
   -1,   -1,  464,  465,   -1,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  322,   -1,   -1,   -1,  496,   -1,   -1,  329,   -1,   -1,
   -1,   -1,  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  513,   -1,   -1,  655,  517,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,   -1,  528,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,   -1,  375,  546,  547,  548,  549,  550,  551,
  552,  553,  384,   -1,   -1,   -1,   -1,   -1,  560,  391,
   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,
   -1,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,   -1,
  283,  284,  285,  286,  287,  288,  289,  290,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  299,  439,  440,   -1,
   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,   -1,
  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,
   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,
  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,
  343,  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,  358,  359,  669,  670,  671,
  672,  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,
   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,
  393,  394,  395,  396,  397,  398,  399,  400,   -1,  402,
  403,  404,  405,  406,  407,  408,  409,  410,   -1,   -1,
  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,
   -1,   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,
  443,  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  284,  285,  286,  287,  288,  289,  290,   -1,   -1,
   -1,  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,
   -1,   -1,   -1,  496,   -1,   -1,  329,   -1,   -1,   -1,
   -1,  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  513,   -1,   -1,  655,  517,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,
  543,   -1,  375,  546,  547,  548,  549,  550,  551,  552,
  553,  384,   -1,   -1,   -1,   -1,   -1,  560,  391,   -1,
   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,
  403,  404,  405,  406,  407,  408,  409,  410,   -1,   -1,
  274,  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  299,  439,  440,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,
  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,
  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  496,  358,  359,  669,  670,  671,  672,
  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,   -1,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,
   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,
  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  284,  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,
  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,
   -1,   -1,  496,   -1,   -1,  329,   -1,   -1,   -1,   -1,
  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,
   -1,   -1,  655,  517,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
   -1,  375,  546,  547,  548,  549,  550,  551,  552,  553,
  384,   -1,   -1,   -1,   -1,   -1,  560,  391,   -1,   -1,
   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  274,
  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  299,  439,  440,   -1,   -1,   -1,
   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,
  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,  334,
   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,
  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,  358,  359,  669,  670,  671,  672,  673,
  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,
  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,
   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,
  395,  396,  397,  398,  399,  400,   -1,  402,  403,  404,
  405,  406,  407,  408,  409,  410,   -1,   -1,  413,  414,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,
  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,  444,
   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,
  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,
   -1,  655,  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,   -1,
   -1,  546,  547,  548,  549,  550,  551,  552,  553,   -1,
   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,
  585,  586,  587,   -1,   -1,   -1,   -1,  283,  284,  285,
  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,   -1,  313,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,  334,   -1,
  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,
  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  358,  359,  669,  670,  671,  672,  673,  365,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,
   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,   -1,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,
  436,   -1,   -1,  439,  440,  441,   -1,  443,  444,   -1,
  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,
   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,
   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,   -1,   -1,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,
  586,  587,   -1,   -1,   -1,   -1,  283,  284,  285,  286,
  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  308,  309,  310,   -1,   -1,  313,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,
   -1,   -1,  329,   -1,   -1,   -1,  333,  334,   -1,  645,
  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  358,  359,  669,  670,  671,  672,  673,  365,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,
  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,
   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,
  397,  398,  399,  400,   -1,  402,  403,  404,  405,  406,
  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,  436,
   -1,   -1,  439,  440,  441,   -1,  443,  444,   -1,  446,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,
  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,
  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,
   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  541,  542,  543,   -1,   -1,  546,
  547,  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,
   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,
  587,   -1,   -1,   -1,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,   -1,   -1,   -1,  333,  334,   -1,  645,  646,
   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  358,  359,  669,  670,  671,  672,  673,  365,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,   -1,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,  436,   -1,
   -1,  439,  440,  441,   -1,  443,  444,   -1,  446,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,
  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,   -1,   -1,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,
   -1,   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,
  309,  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,
  329,   -1,   -1,   -1,  333,  334,   -1,  645,  646,   -1,
   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,
  359,  669,  670,  671,  672,  673,  365,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,  377,   -1,
   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,
   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,  398,
  399,  400,   -1,  402,  403,  404,  405,  406,  407,  408,
  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  432,   -1,   -1,  435,  436,   -1,   -1,
  439,  440,  441,   -1,  443,  444,   -1,  446,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,  467,  468,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,  528,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  541,  542,  543,   -1,   -1,  546,  547,  548,
  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,
   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,
   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
   -1,   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,
  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,
  669,  670,  671,  672,  673,  365,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  374,  375,   -1,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,   -1,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  432,   -1,   -1,  435,  436,   -1,   -1,  439,
  440,  441,   -1,  443,  444,   -1,  446,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  464,  465,   -1,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,  528,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,   -1,   -1,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,
   -1,   -1,  283,  284,  285,  286,  287,  288,  289,  290,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,
   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,
   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,
   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,  669,
  670,  671,  672,  673,  365,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  374,  375,   -1,  377,   -1,   -1,   -1,
   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,
  391,   -1,  393,  394,  395,  396,  397,  398,  399,  400,
   -1,  402,  403,  404,  405,  406,  407,  408,  409,  410,
   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  432,   -1,   -1,  435,  436,   -1,   -1,  439,  440,
  441,   -1,  443,  444,   -1,  446,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  464,  465,   -1,  467,  468,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  525,  526,   -1,  528,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  541,  542,  543,   -1,   -1,  546,  547,  548,  549,  550,
  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,
   -1,  283,  284,  285,  286,  287,  288,  289,  290,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,
   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,
   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,  669,  670,
  671,  672,  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  374,  375,   -1,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,   -1,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  432,   -1,   -1,  435,  436,   -1,   -1,  439,  440,  441,
   -1,  443,  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  464,  465,   -1,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,   -1,  528,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,   -1,   -1,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,   -1,
  283,  284,  285,  286,  287,  288,  289,  290,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,   -1,
  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,
   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,
  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,
  343,  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  358,  359,  669,  670,  671,
  672,  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,
   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,
  393,  394,  395,  396,  397,  398,  399,  400,   -1,  402,
  403,  404,  405,  406,  407,  408,  409,  410,   -1,   -1,
  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,
   -1,   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,
  443,  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,
  543,   -1,   -1,  546,  547,  548,  549,  550,  551,  552,
  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  274,  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,
  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,
  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  358,  359,  669,  670,  671,  672,
  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,   -1,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,
   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,
  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,
   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
   -1,   -1,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,
  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,
  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,  334,
   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,
  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  358,  359,  669,  670,  671,  672,  673,
  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,
  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,
   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,
  395,  396,  397,  398,  399,  400,   -1,  402,  403,  404,
  405,  406,  407,  408,  409,  410,   -1,   -1,  413,  414,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,
  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,  444,
   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,
  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,
   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,   -1,
   -1,  546,  547,  548,  549,  550,  551,  552,  553,   -1,
   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,
  585,  586,  587,   -1,   -1,   -1,   -1,  283,  284,  285,
  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,   -1,  313,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,  334,   -1,
  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,
  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  358,  359,  669,  670,  671,  672,  673,  365,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,
   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,   -1,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,
  436,   -1,   -1,  439,  440,  441,   -1,  443,  444,   -1,
  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,
   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,
   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,   -1,   -1,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,
  586,  587,   -1,   -1,   -1,   -1,  283,  284,  285,  286,
  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  308,  309,  310,   -1,   -1,  313,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,
   -1,   -1,  329,   -1,   -1,   -1,  333,  334,   -1,  645,
  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  358,  359,  669,  670,  671,  672,  673,  365,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,
  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,
   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,
  397,  398,  399,  400,   -1,  402,  403,  404,  405,  406,
  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,  436,
   -1,   -1,  439,  440,  441,   -1,  443,  444,   -1,  446,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,
  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,
  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,
   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  541,  542,  543,   -1,   -1,  546,
  547,  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,
   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,
  587,   -1,   -1,   -1,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,   -1,   -1,   -1,  333,  334,   -1,  645,  646,
   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  358,  359,  669,  670,  671,  672,  673,  365,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,   -1,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,  436,   -1,
   -1,  439,  440,  441,   -1,  443,  444,   -1,  446,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,
  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,   -1,   -1,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,
   -1,   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,
  309,  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,
  329,   -1,   -1,   -1,  333,  334,   -1,  645,  646,   -1,
   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,
  359,  669,  670,  671,  672,  673,  365,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,  377,   -1,
   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,
   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,  398,
  399,  400,   -1,  402,  403,  404,  405,  406,  407,  408,
  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  432,   -1,   -1,  435,  436,   -1,   -1,
  439,  440,  441,   -1,  443,  444,   -1,  446,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,  467,  468,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,  528,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  541,  542,  543,   -1,   -1,  546,  547,  548,
  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,
   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,
   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
   -1,   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,
  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,
  669,  670,  671,  672,  673,  365,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  374,  375,   -1,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,   -1,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  432,   -1,   -1,  435,  436,   -1,   -1,  439,
  440,  441,   -1,  443,  444,   -1,  446,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  464,  465,   -1,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,  528,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,   -1,   -1,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,
   -1,   -1,  283,  284,  285,  286,  287,  288,  289,  290,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,
   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,
   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,
   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,  669,
  670,  671,  672,  673,  365,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  374,  375,   -1,  377,   -1,   -1,   -1,
   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,
  391,   -1,  393,  394,  395,  396,  397,  398,  399,  400,
   -1,  402,  403,  404,  405,  406,  407,  408,  409,  410,
   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  432,   -1,   -1,  435,  436,   -1,   -1,  439,  440,
  441,   -1,  443,  444,   -1,  446,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  464,  465,   -1,  467,  468,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  525,  526,   -1,  528,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  541,  542,  543,   -1,   -1,  546,  547,  548,  549,  550,
  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,
   -1,  283,  284,  285,  286,  287,  288,  289,  290,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,
   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,
   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,  669,  670,
  671,  672,  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  374,  375,   -1,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,   -1,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  432,   -1,   -1,  435,  436,   -1,   -1,  439,  440,  441,
   -1,  443,  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  464,  465,   -1,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,   -1,  528,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,   -1,   -1,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,   -1,
  283,  284,  285,  286,  287,  288,  289,  290,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,   -1,
  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,
   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,
  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,
  343,  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  358,  359,  669,  670,  671,
  672,  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,
   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,
  393,  394,  395,  396,  397,  398,  399,  400,   -1,  402,
  403,  404,  405,  406,  407,  408,  409,  410,   -1,   -1,
  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,
   -1,   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,
  443,  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,
  543,   -1,   -1,  546,  547,  548,  549,  550,  551,  552,
  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  274,  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,
  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,
  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  358,  359,  669,  670,  671,  672,
  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,   -1,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,
   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,
  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,
   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
   -1,   -1,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,
  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,
  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,  334,
   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,
  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  358,  359,  669,  670,  671,  672,  673,
  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,
  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,
   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,
  395,  396,  397,  398,  399,  400,   -1,  402,  403,  404,
  405,  406,  407,  408,  409,  410,   -1,   -1,  413,  414,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,
  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,  444,
   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,
  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,
   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,   -1,
   -1,  546,  547,  548,  549,  550,  551,  552,  553,   -1,
   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,
  585,  586,  587,   -1,   -1,   -1,   -1,  283,  284,  285,
  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,   -1,  313,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,  334,   -1,
  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,
  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  358,  359,  669,  670,  671,  672,  673,  365,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,
   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,   -1,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,
  436,   -1,   -1,  439,  440,  441,   -1,  443,  444,   -1,
  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,
   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,
   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,   -1,   -1,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,
  586,  587,   -1,   -1,   -1,   -1,  283,  284,  285,  286,
  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  308,  309,  310,   -1,   -1,  313,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,
   -1,   -1,  329,   -1,   -1,   -1,  333,  334,   -1,  645,
  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  358,  359,  669,  670,  671,  672,  673,  365,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,
  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,
   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,
  397,  398,  399,  400,   -1,  402,  403,  404,  405,  406,
  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,  436,
   -1,   -1,  439,  440,  441,   -1,  443,  444,   -1,  446,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,
  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,
  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,
   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  541,  542,  543,   -1,   -1,  546,
  547,  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,
   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,
  587,   -1,   -1,   -1,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,   -1,   -1,   -1,  333,  334,   -1,  645,  646,
   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  358,  359,  669,  670,  671,  672,  673,  365,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,   -1,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,  436,   -1,
   -1,  439,  440,  441,   -1,  443,  444,   -1,  446,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,
  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,   -1,   -1,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,
   -1,   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,
  309,  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,
  329,   -1,   -1,   -1,  333,  334,   -1,  645,  646,   -1,
   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,
  359,  669,  670,  671,  672,  673,  365,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,  377,   -1,
   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,
   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,  398,
  399,  400,   -1,  402,  403,  404,  405,  406,  407,  408,
  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  432,   -1,   -1,  435,  436,   -1,   -1,
  439,  440,  441,   -1,  443,  444,   -1,  446,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,  467,  468,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,  528,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  541,  542,  543,   -1,   -1,  546,  547,  548,
  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,
   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,
   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
   -1,   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,
  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,
  669,  670,  671,  672,  673,  365,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  374,  375,   -1,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,   -1,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  432,   -1,   -1,  435,  436,   -1,   -1,  439,
  440,  441,   -1,  443,  444,   -1,  446,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  464,  465,   -1,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,  528,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,   -1,   -1,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,
   -1,   -1,  283,  284,  285,  286,  287,  288,  289,  290,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,
   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,
   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,
   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,  669,
  670,  671,  672,  673,  365,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  374,  375,   -1,  377,   -1,   -1,   -1,
   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,
  391,   -1,  393,  394,  395,  396,  397,  398,  399,  400,
   -1,  402,  403,  404,  405,  406,  407,  408,  409,  410,
   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  432,   -1,   -1,  435,  436,   -1,   -1,  439,  440,
  441,   -1,  443,  444,   -1,  446,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  464,  465,   -1,  467,  468,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  525,  526,   -1,  528,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  541,  542,  543,   -1,   -1,  546,  547,  548,  549,  550,
  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,
   -1,  283,  284,  285,  286,  287,  288,  289,  290,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,
   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,
   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,  669,  670,
  671,  672,  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  374,  375,   -1,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,   -1,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  432,   -1,   -1,  435,  436,   -1,   -1,  439,  440,  441,
   -1,  443,  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  464,  465,   -1,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,   -1,  528,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,   -1,   -1,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,   -1,
  283,  284,  285,  286,  287,  288,  289,  290,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,   -1,
  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,
   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,
  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,
  343,  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  358,  359,  669,  670,  671,
  672,  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,
   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,
  393,  394,  395,  396,  397,  398,  399,  400,   -1,  402,
  403,  404,  405,  406,  407,  408,  409,  410,   -1,   -1,
  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,
   -1,   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,
  443,  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,
  543,   -1,   -1,  546,  547,  548,  549,  550,  551,  552,
  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  274,  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,
  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,
  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  358,  359,  669,  670,  671,  672,
  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,   -1,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,
   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,
  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,
   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
   -1,   -1,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,
  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,
  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,  334,
   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,
  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  358,  359,  669,  670,  671,  672,  673,
  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,
  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,
   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,
  395,  396,  397,  398,  399,  400,   -1,  402,  403,  404,
  405,  406,  407,  408,  409,  410,   -1,   -1,  413,  414,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,
  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,  444,
   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,
  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,
   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,   -1,
   -1,  546,  547,  548,  549,  550,  551,  552,  553,   -1,
   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,
  585,  586,  587,   -1,   -1,   -1,   -1,  283,  284,  285,
  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,   -1,  313,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,  334,   -1,
  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,
  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  358,  359,  669,  670,  671,  672,  673,  365,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,
   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,   -1,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,
  436,   -1,   -1,  439,  440,  441,   -1,  443,  444,   -1,
  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,
   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,
   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,   -1,   -1,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,
  586,  587,   -1,   -1,   -1,   -1,  283,  284,  285,  286,
  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  308,  309,  310,   -1,   -1,  313,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,
   -1,   -1,  329,   -1,   -1,   -1,  333,  334,   -1,  645,
  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  358,  359,  669,  670,  671,  672,  673,  365,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,
  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,
   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,
  397,  398,  399,  400,   -1,  402,  403,  404,  405,  406,
  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,  436,
   -1,   -1,  439,  440,  441,   -1,  443,  444,   -1,  446,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,
  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,
  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,
   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  541,  542,  543,   -1,   -1,  546,
  547,  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,
   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,
  587,   -1,   -1,   -1,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,   -1,   -1,   -1,  333,  334,   -1,  645,  646,
   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  358,  359,  669,  670,  671,  672,  673,  365,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,   -1,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,  436,   -1,
   -1,  439,  440,  441,   -1,  443,  444,   -1,  446,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,
  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,   -1,   -1,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,
   -1,   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,
  309,  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,
  329,   -1,   -1,   -1,  333,  334,   -1,  645,  646,   -1,
   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,
  359,  669,  670,  671,  672,  673,  365,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,  377,   -1,
   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,
   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,  398,
  399,  400,   -1,  402,  403,  404,  405,  406,  407,  408,
  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  432,   -1,   -1,  435,  436,   -1,   -1,
  439,  440,  441,   -1,  443,  444,   -1,  446,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,  467,  468,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,  528,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  541,  542,  543,   -1,   -1,  546,  547,  548,
  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,
   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,
   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
   -1,   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,
  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,
  669,  670,  671,  672,  673,  365,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  374,  375,   -1,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,   -1,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  432,   -1,   -1,  435,  436,   -1,   -1,  439,
  440,  441,   -1,  443,  444,   -1,  446,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  464,  465,   -1,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,  528,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,   -1,   -1,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,
   -1,   -1,  283,  284,  285,  286,  287,  288,  289,  290,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,
   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,
   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,
   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,  669,
  670,  671,  672,  673,  365,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  374,  375,   -1,  377,   -1,   -1,   -1,
   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,
  391,   -1,  393,  394,  395,  396,  397,  398,  399,  400,
   -1,  402,  403,  404,  405,  406,  407,  408,  409,  410,
   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  432,   -1,   -1,  435,  436,   -1,   -1,  439,  440,
  441,   -1,  443,  444,   -1,  446,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  464,  465,   -1,  467,  468,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  525,  526,   -1,  528,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  541,  542,  543,   -1,   -1,  546,  547,  548,  549,  550,
  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,
   -1,  283,  284,  285,  286,  287,  288,  289,  290,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,
   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,
   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,  669,  670,
  671,  672,  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  374,  375,   -1,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,   -1,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  432,   -1,   -1,  435,  436,   -1,   -1,  439,  440,  441,
   -1,  443,  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  464,  465,   -1,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,   -1,  528,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,   -1,   -1,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,   -1,
  283,  284,  285,  286,  287,  288,  289,  290,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,   -1,
  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,
   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,
  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,
  343,  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  358,  359,  669,  670,  671,
  672,  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,
   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,
  393,  394,  395,  396,  397,  398,  399,  400,   -1,  402,
  403,  404,  405,  406,  407,  408,  409,  410,   -1,   -1,
  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,
   -1,   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,
  443,  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,
  543,   -1,   -1,  546,  547,  548,  549,  550,  551,  552,
  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  274,  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,
  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,
  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  358,  359,  669,  670,  671,  672,
  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,   -1,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,
   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,
  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,
   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
   -1,   -1,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,
  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,
  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,  334,
   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,
  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  358,  359,  669,  670,  671,  672,  673,
  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,
  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,
   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,
  395,  396,  397,  398,  399,  400,   -1,  402,  403,  404,
  405,  406,  407,  408,  409,  410,   -1,   -1,  413,  414,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,
  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,  444,
   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,
  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,
   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,   -1,
   -1,  546,  547,  548,  549,  550,  551,  552,  553,   -1,
   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,
  585,  586,  587,   -1,   -1,   -1,   -1,  283,  284,  285,
  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,   -1,  313,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,  334,   -1,
  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,
  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  358,  359,  669,  670,  671,  672,  673,  365,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,
   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,   -1,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,
  436,   -1,   -1,  439,  440,  441,   -1,  443,  444,   -1,
  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,
   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,
   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,   -1,   -1,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,
  586,  587,   -1,   -1,   -1,   -1,  283,  284,  285,  286,
  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  308,  309,  310,   -1,   -1,  313,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,
   -1,   -1,  329,   -1,   -1,   -1,  333,  334,   -1,  645,
  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  358,  359,  669,  670,  671,  672,  673,  365,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,
  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,
   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,
  397,  398,  399,  400,   -1,  402,  403,  404,  405,  406,
  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,  436,
   -1,   -1,  439,  440,  441,   -1,  443,  444,   -1,  446,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,
  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,
  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,
   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  541,  542,  543,   -1,   -1,  546,
  547,  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,
   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,
  587,   -1,   -1,   -1,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,   -1,   -1,   -1,  333,  334,   -1,  645,  646,
   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  358,  359,  669,  670,  671,  672,  673,  365,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,   -1,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,  436,   -1,
   -1,  439,  440,  441,   -1,  443,  444,   -1,  446,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,
  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,   -1,   -1,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,
   -1,   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,
  309,  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,
  329,   -1,   -1,   -1,  333,  334,   -1,  645,  646,   -1,
   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,
  359,  669,  670,  671,  672,  673,  365,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,  377,   -1,
   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,
   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,  398,
  399,  400,   -1,  402,  403,  404,  405,  406,  407,  408,
  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  432,   -1,   -1,  435,  436,   -1,   -1,
  439,  440,  441,   -1,  443,  444,   -1,  446,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,  467,  468,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,  528,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  541,  542,  543,   -1,   -1,  546,  547,  548,
  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,
   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,
   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
   -1,   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,
  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,
  669,  670,  671,  672,  673,  365,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  374,  375,   -1,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,   -1,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  432,   -1,   -1,  435,  436,   -1,   -1,  439,
  440,  441,   -1,  443,  444,   -1,  446,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  464,  465,   -1,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,  528,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,   -1,   -1,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,
   -1,   -1,  283,  284,  285,  286,  287,  288,  289,  290,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,
   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,
   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,
   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,  669,
  670,  671,  672,  673,  365,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  374,  375,   -1,  377,   -1,   -1,   -1,
   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,
  391,   -1,  393,  394,  395,  396,  397,  398,  399,  400,
   -1,  402,  403,  404,  405,  406,  407,  408,  409,  410,
   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  432,   -1,   -1,  435,  436,   -1,   -1,  439,  440,
  441,   -1,  443,  444,   -1,  446,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  464,  465,   -1,  467,  468,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  525,  526,   -1,  528,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  541,  542,  543,   -1,   -1,  546,  547,  548,  549,  550,
  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,
   -1,  283,  284,  285,  286,  287,  288,  289,  290,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,
   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,
   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,  669,  670,
  671,  672,  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  374,  375,   -1,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,   -1,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  432,   -1,   -1,  435,  436,   -1,   -1,  439,  440,  441,
   -1,  443,  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  464,  465,   -1,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,   -1,  528,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,   -1,   -1,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,   -1,
  283,  284,  285,  286,  287,  288,  289,  290,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,   -1,
  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,
   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,
  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,
  343,  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  358,  359,  669,  670,  671,
  672,  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,
   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,
  393,  394,  395,  396,  397,  398,  399,  400,   -1,  402,
  403,  404,  405,  406,  407,  408,  409,  410,   -1,   -1,
  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,
   -1,   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,
  443,  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,
  543,   -1,   -1,  546,  547,  548,  549,  550,  551,  552,
  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  274,  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,
  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,
  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  358,  359,  669,  670,  671,  672,
  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,   -1,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,
   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,
  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,
   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
   -1,   -1,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,
  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,
  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,  334,
   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,
  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  358,  359,  669,  670,  671,  672,  673,
  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,
  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,
   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,
  395,  396,  397,  398,  399,  400,   -1,  402,  403,  404,
  405,  406,  407,  408,  409,  410,   -1,   -1,  413,  414,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,
  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,  444,
   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,
  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,
   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,   -1,
   -1,  546,  547,  548,  549,  550,  551,  552,  553,   -1,
   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,
  585,  586,  587,   -1,   -1,   -1,   -1,  283,  284,  285,
  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  308,  309,  310,   -1,   -1,  313,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,
   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,  334,   -1,
  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,
  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  358,  359,  669,  670,  671,  672,  673,  365,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,
   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,
   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,
  396,  397,  398,  399,  400,   -1,  402,  403,  404,  405,
  406,  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,
  436,   -1,   -1,  439,  440,  441,   -1,  443,  444,   -1,
  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,
   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,
   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,
  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  541,  542,  543,   -1,   -1,
  546,  547,  548,  549,  550,  551,  552,  553,   -1,   -1,
   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,
  586,  587,   -1,   -1,   -1,   -1,  283,  284,  285,  286,
  287,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  308,  309,  310,   -1,   -1,  313,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,
   -1,   -1,  329,   -1,   -1,   -1,  333,  334,   -1,  645,
  646,   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  358,  359,  669,  670,  671,  672,  673,  365,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,
  377,   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,
   -1,   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,
  397,  398,  399,  400,   -1,  402,  403,  404,  405,  406,
  407,  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,  436,
   -1,   -1,  439,  440,  441,   -1,  443,  444,   -1,  446,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,
  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,
  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,
   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  541,  542,  543,   -1,   -1,  546,
  547,  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,
   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,
  587,   -1,   -1,   -1,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  308,  309,  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,
   -1,  329,   -1,   -1,   -1,  333,  334,   -1,  645,  646,
   -1,   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  358,  359,  669,  670,  671,  672,  673,  365,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,  377,
   -1,   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,
   -1,   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,
  398,  399,  400,   -1,  402,  403,  404,  405,  406,  407,
  408,  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  432,   -1,   -1,  435,  436,   -1,
   -1,  439,  440,  441,   -1,  443,  444,   -1,  446,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,  467,
  468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,
  528,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  541,  542,  543,   -1,   -1,  546,  547,
  548,  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,
   -1,   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  568,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,
   -1,   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  299,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,
  309,  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,
  329,   -1,   -1,   -1,  333,  334,   -1,  645,  646,   -1,
   -1,  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,
  359,  669,  670,  671,  672,  673,  365,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  374,  375,   -1,  377,   -1,
   -1,   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,
   -1,   -1,  391,   -1,  393,  394,  395,  396,  397,  398,
  399,  400,   -1,  402,  403,  404,  405,  406,  407,  408,
  409,  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  432,   -1,   -1,  435,  436,   -1,   -1,
  439,  440,  441,   -1,  443,  444,   -1,  446,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  464,  465,   -1,  467,  468,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,  528,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  541,  542,  543,   -1,   -1,  546,  547,  548,
  549,  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,
   -1,  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,
   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,
  310,   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,
   -1,   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,
  649,   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,
  669,  670,  671,  672,  673,  365,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  374,  375,   -1,  377,   -1,   -1,
   -1,   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,
   -1,  391,   -1,  393,  394,  395,  396,  397,  398,  399,
  400,   -1,  402,  403,  404,  405,  406,  407,  408,  409,
  410,   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  432,   -1,   -1,  435,  436,   -1,   -1,  439,
  440,  441,   -1,  443,  444,   -1,  446,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  464,  465,   -1,  467,  468,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  525,  526,   -1,  528,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  541,  542,  543,   -1,   -1,  546,  547,  548,  549,
  550,  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,
  560,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,
   -1,   -1,  283,  284,  285,  286,  287,  288,  289,  290,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,
   -1,   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  322,   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,
   -1,   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,
   -1,   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,  669,
  670,  671,  672,  673,  365,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  374,  375,   -1,  377,   -1,   -1,   -1,
   -1,   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,
  391,   -1,  393,  394,  395,  396,  397,  398,  399,  400,
   -1,  402,  403,  404,  405,  406,  407,  408,  409,  410,
   -1,   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  432,   -1,   -1,  435,  436,   -1,   -1,  439,  440,
  441,   -1,  443,  444,   -1,  446,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  464,  465,   -1,  467,  468,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  525,  526,   -1,  528,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  541,  542,  543,   -1,   -1,  546,  547,  548,  549,  550,
  551,  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,
   -1,  283,  284,  285,  286,  287,  288,  289,  290,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,
   -1,  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  322,   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,
   -1,  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,
   -1,  343,  653,  654,  655,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  358,  359,  669,  670,
  671,  672,  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  374,  375,   -1,  377,   -1,   -1,   -1,   -1,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
   -1,  393,  394,  395,  396,  397,  398,  399,  400,   -1,
  402,  403,  404,  405,  406,  407,  408,  409,  410,   -1,
   -1,  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  432,   -1,   -1,  435,  436,   -1,   -1,  439,  440,  441,
   -1,  443,  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  464,  465,   -1,  467,  468,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  525,  526,   -1,  528,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,
  542,  543,   -1,   -1,  546,  547,  548,  549,  550,  551,
  552,  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  274,  275,  585,  586,  587,   -1,   -1,   -1,   -1,
  283,  284,  285,  286,  287,  288,  289,  290,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  308,  309,  310,   -1,   -1,
  313,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,
   -1,   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,
  333,  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,
  343,  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  358,  359,  669,  670,  671,
  672,  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,
   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,
  393,  394,  395,  396,  397,  398,  399,  400,   -1,  402,
  403,  404,  405,  406,  407,  408,  409,  410,   -1,   -1,
  413,  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,
   -1,   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,
  443,  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  513,   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,
  543,   -1,   -1,  546,  547,  548,  549,  550,  551,  552,
  553,   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  274,  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,
   -1,  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,
  334,   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,
  653,  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  358,  359,  669,  670,  671,  672,
  673,  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  374,  375,   -1,  377,   -1,   -1,   -1,   -1,   -1,   -1,
  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,   -1,  393,
  394,  395,  396,  397,  398,  399,  400,   -1,  402,  403,
  404,  405,  406,  407,  408,  409,  410,   -1,   -1,  413,
  414,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,
   -1,  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,
  444,   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  464,  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  496,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,
   -1,   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  541,  542,  543,
   -1,   -1,  546,  547,  548,  549,  550,  551,  552,  553,
   -1,   -1,   -1,   -1,   -1,   -1,  560,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,
  275,  585,  586,  587,   -1,   -1,   -1,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  299,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  308,  309,  310,   -1,   -1,  313,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  322,   -1,   -1,
  325,   -1,   -1,   -1,  329,   -1,   -1,   -1,  333,  334,
   -1,  645,  646,   -1,   -1,  649,   -1,   -1,  343,  653,
  654,  655,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  358,  359,  669,  670,  671,  672,  673,
  365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  374,
  375,   -1,  377,   -1,   -1,   -1,   -1,   -1, 2032,  384,
   -1, 2035,   -1,   -1,   -1,   -1,  391,   -1,  393,  394,
  395,  396,  397,  398,  399,  400,   -1,  402,  403,  404,
  405,  406,  407,  408,  409,  410,   -1,   -1,  413,  414,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  432,   -1,   -1,
  435,  436,   -1,   -1,  439,  440,  441,   -1,  443,  444,
   -1,  446,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  464,
  465,   -1,  467,  468,   -1,   -1,   -1,   -1,   -1,   -1,
 2124, 2125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  496,   -1, 2147, 2148,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  513,   -1,
   -1,   -1,  517,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  525,  526,   -1,  528,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1, 2186,   -1,   -1,   -1,  541,  542,  543,   -1,
   -1,  546,  547,  548,  549,  550,  551,  552,  553,   -1,
   -1, 2205,   -1,   -1,   -1,  560,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  568,   -1,   -1,   -1,   -1,   -1,   -1,
   -1, 2225, 2226,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  585,  586,  587,   -1,   -1,   -1,   -1, 2241, 2242,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2262,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1, 2278,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1, 2292, 2293,
  645,  646,   -1,   -1,  649,   -1,   -1,   -1,  653,  654,
  655, 2305, 2306,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  669,  670,  671,  672,  673,   -1,
   -1, 2325,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1, 2335,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1, 2346, 2347,   -1,   -1,   -1,   -1,   -1,   -1,
 2354, 2355,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  334,   -1,   -1, 2369,   -1,   -1,  340,  341,
  342,   -1, 2376,   -1,  346,   -1,   -1,   -1,   -1,   -1,
  352,  353,  354, 2387,   -1, 2389,   -1,   -1,  360,  361,
 2394,   -1,   -1,   -1,   -1,  367,  368,  369,  370,   -1,
   -1,   -1,   -1,   -1,   -1, 2409,  378,   -1,   -1, 2413,
   -1,   -1,  384,   -1,   -1,   -1,   -1,   -1,   -1,  391,
  392,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  340,  341,  342,   -1,   -1,
   -1,  346,   -1,   -1,   -1,   -1,   -1,  352,  353,  354,
   -1,  423,  424,  425,   -1,  360,  361,   -1,   -1,   -1,
   -1,   -1,  367,  368,  369,  370,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  378,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  392,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  475,  476,  477,  478,  479,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  487,  488,  489,  423,  424,
  425,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  509,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  532,  533,   -1,  535,  536,   -1,   -1,   -1,   -1,   -1,
  475,  476,  477,  478,  479,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  487,  488,  489,   -1,  558,  559,   -1,   -1,
   -1,   -1,   -1,   -1,  566,  567,   -1,   -1,   -1,   -1,
  572,   -1,  574,  575,  509,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  532,  533,   -1,
  535,  536,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  558,  559,   -1,   -1,   -1,   -1,   -1,
   -1,  566,  567,   -1,   -1,   -1,   -1,  572,   -1,  574,
  575,  617,  618,  619,  620,  621,  622,  623,  624,  625,
  626,  627,  628,  629,  630,  631,  632,  633,  634,  635,
  636,  637,  638,  639,  640,  641,  642,  643,  644,   -1,
   -1,   -1,   -1,   -1,  650,  617,  618,  619,  620,  621,
  622,  623,  624,  625,  626,  627,  628,  629,  630,  631,
  632,  633,  634,  635,  636,  637,  638,  639,  640,  641,
  642,  643,  644,   -1,   -1,   -1,   -1,   -1,  650,  617,
  618,  619,  620,  621,  622,  623,  624,  625,  626,  627,
  628,  629,  630,  631,  632,  633,  634,  635,  636,  637,
  638,  639,  640,  641,  642,  643,  644,   -1,   -1,   -1,
   -1,   -1,  650,  617,  618,  619,  620,  621,  622,  623,
  624,  625,  626,  627,  628,  629,  630,  631,  632,  633,
  634,  635,  636,  637,  638,  639,  640,  641,  642,  643,
  644,   -1,   -1,   -1,   -1,   -1,  650,  617,  618,  619,
  620,  621,  622,  623,  624,  625,  626,  627,  628,  629,
  630,  631,  632,  633,  634,  635,  636,  637,  638,  639,
  640,  641,  642,  643,  644,   -1,   -1,   -1,   -1,   -1,
  650,  617,  618,  619,  620,  621,  622,  623,  624,  625,
  626,  627,  628,  629,  630,  631,  632,  633,  634,  635,
  636,  637,  638,  639,  640,  641,  642,  643,  644,   -1,
   -1,   -1,   -1,   -1,  650,  617,  618,  619,  620,  621,
  622,  623,  624,  625,  626,  627,  628,  629,  630,  631,
  632,  633,  634,  635,  636,  637,  638,  639,  640,  641,
  642,  643,  644,   -1,   -1,   -1,   -1,   -1,  650,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 673
#define YYUNDFTOKEN 1180
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const AslCompilername[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"PARSEOP_ACCESSAS","PARSEOP_ACCESSATTRIB_BLOCK",
"PARSEOP_ACCESSATTRIB_BLOCK_CALL","PARSEOP_ACCESSATTRIB_BYTE",
"PARSEOP_ACCESSATTRIB_MULTIBYTE","PARSEOP_ACCESSATTRIB_QUICK",
"PARSEOP_ACCESSATTRIB_RAW_BYTES","PARSEOP_ACCESSATTRIB_RAW_PROCESS",
"PARSEOP_ACCESSATTRIB_SND_RCV","PARSEOP_ACCESSATTRIB_WORD",
"PARSEOP_ACCESSATTRIB_WORD_CALL","PARSEOP_ACCESSTYPE_ANY",
"PARSEOP_ACCESSTYPE_BUF","PARSEOP_ACCESSTYPE_BYTE","PARSEOP_ACCESSTYPE_DWORD",
"PARSEOP_ACCESSTYPE_QWORD","PARSEOP_ACCESSTYPE_WORD","PARSEOP_ACQUIRE",
"PARSEOP_ADD","PARSEOP_ADDRESSINGMODE_7BIT","PARSEOP_ADDRESSINGMODE_10BIT",
"PARSEOP_ADDRESSTYPE_ACPI","PARSEOP_ADDRESSTYPE_MEMORY",
"PARSEOP_ADDRESSTYPE_NVS","PARSEOP_ADDRESSTYPE_RESERVED","PARSEOP_ALIAS",
"PARSEOP_AND","PARSEOP_ARG0","PARSEOP_ARG1","PARSEOP_ARG2","PARSEOP_ARG3",
"PARSEOP_ARG4","PARSEOP_ARG5","PARSEOP_ARG6","PARSEOP_BANKFIELD",
"PARSEOP_BITSPERBYTE_EIGHT","PARSEOP_BITSPERBYTE_FIVE",
"PARSEOP_BITSPERBYTE_NINE","PARSEOP_BITSPERBYTE_SEVEN",
"PARSEOP_BITSPERBYTE_SIX","PARSEOP_BREAK","PARSEOP_BREAKPOINT","PARSEOP_BUFFER",
"PARSEOP_BUSMASTERTYPE_MASTER","PARSEOP_BUSMASTERTYPE_NOTMASTER",
"PARSEOP_BYTECONST","PARSEOP_CASE","PARSEOP_CLOCKPHASE_FIRST",
"PARSEOP_CLOCKPHASE_SECOND","PARSEOP_CLOCKPOLARITY_HIGH",
"PARSEOP_CLOCKPOLARITY_LOW","PARSEOP_CONCATENATE",
"PARSEOP_CONCATENATERESTEMPLATE","PARSEOP_CONDREFOF","PARSEOP_CONNECTION",
"PARSEOP_CONTINUE","PARSEOP_COPYOBJECT","PARSEOP_CREATEBITFIELD",
"PARSEOP_CREATEBYTEFIELD","PARSEOP_CREATEDWORDFIELD","PARSEOP_CREATEFIELD",
"PARSEOP_CREATEQWORDFIELD","PARSEOP_CREATEWORDFIELD","PARSEOP_DATABUFFER",
"PARSEOP_DATATABLEREGION","PARSEOP_DEBUG","PARSEOP_DECODETYPE_POS",
"PARSEOP_DECODETYPE_SUB","PARSEOP_DECREMENT","PARSEOP_DEFAULT",
"PARSEOP_DEFAULT_ARG","PARSEOP_DEFINITION_BLOCK","PARSEOP_DEREFOF",
"PARSEOP_DEVICE","PARSEOP_DEVICEPOLARITY_HIGH","PARSEOP_DEVICEPOLARITY_LOW",
"PARSEOP_DIVIDE","PARSEOP_DMA","PARSEOP_DMATYPE_A",
"PARSEOP_DMATYPE_COMPATIBILITY","PARSEOP_DMATYPE_B","PARSEOP_DMATYPE_F",
"PARSEOP_DWORDCONST","PARSEOP_DWORDIO","PARSEOP_DWORDMEMORY",
"PARSEOP_DWORDSPACE","PARSEOP_EISAID","PARSEOP_ELSE","PARSEOP_ELSEIF",
"PARSEOP_ENDDEPENDENTFN","PARSEOP_ENDIAN_BIG","PARSEOP_ENDIAN_LITTLE",
"PARSEOP_ENDTAG","PARSEOP_ERRORNODE","PARSEOP_EVENT","PARSEOP_EXTENDEDIO",
"PARSEOP_EXTENDEDMEMORY","PARSEOP_EXTENDEDSPACE","PARSEOP_EXTERNAL",
"PARSEOP_FATAL","PARSEOP_FIELD","PARSEOP_FINDSETLEFTBIT",
"PARSEOP_FINDSETRIGHTBIT","PARSEOP_FIXEDDMA","PARSEOP_FIXEDIO",
"PARSEOP_FLOWCONTROL_HW","PARSEOP_FLOWCONTROL_NONE","PARSEOP_FLOWCONTROL_SW",
"PARSEOP_FROMBCD","PARSEOP_FUNCTION","PARSEOP_GPIO_INT","PARSEOP_GPIO_IO",
"PARSEOP_I2C_SERIALBUS","PARSEOP_I2C_SERIALBUS_V2","PARSEOP_IF",
"PARSEOP_INCLUDE","PARSEOP_INCLUDE_END","PARSEOP_INCREMENT","PARSEOP_INDEX",
"PARSEOP_INDEXFIELD","PARSEOP_INTEGER","PARSEOP_INTERRUPT",
"PARSEOP_INTLEVEL_ACTIVEBOTH","PARSEOP_INTLEVEL_ACTIVEHIGH",
"PARSEOP_INTLEVEL_ACTIVELOW","PARSEOP_INTTYPE_EDGE","PARSEOP_INTTYPE_LEVEL",
"PARSEOP_IO","PARSEOP_IODECODETYPE_10","PARSEOP_IODECODETYPE_16",
"PARSEOP_IORESTRICT_IN","PARSEOP_IORESTRICT_NONE","PARSEOP_IORESTRICT_OUT",
"PARSEOP_IORESTRICT_PRESERVE","PARSEOP_IRQ","PARSEOP_IRQNOFLAGS","PARSEOP_LAND",
"PARSEOP_LEQUAL","PARSEOP_LGREATER","PARSEOP_LGREATEREQUAL","PARSEOP_LLESS",
"PARSEOP_LLESSEQUAL","PARSEOP_LNOT","PARSEOP_LNOTEQUAL","PARSEOP_LOAD",
"PARSEOP_LOADTABLE","PARSEOP_LOCAL0","PARSEOP_LOCAL1","PARSEOP_LOCAL2",
"PARSEOP_LOCAL3","PARSEOP_LOCAL4","PARSEOP_LOCAL5","PARSEOP_LOCAL6",
"PARSEOP_LOCAL7","PARSEOP_LOCKRULE_LOCK","PARSEOP_LOCKRULE_NOLOCK",
"PARSEOP_LOR","PARSEOP_MATCH","PARSEOP_MATCHTYPE_MEQ","PARSEOP_MATCHTYPE_MGE",
"PARSEOP_MATCHTYPE_MGT","PARSEOP_MATCHTYPE_MLE","PARSEOP_MATCHTYPE_MLT",
"PARSEOP_MATCHTYPE_MTR","PARSEOP_MAXTYPE_FIXED","PARSEOP_MAXTYPE_NOTFIXED",
"PARSEOP_MEMORY24","PARSEOP_MEMORY32","PARSEOP_MEMORY32FIXED",
"PARSEOP_MEMTYPE_CACHEABLE","PARSEOP_MEMTYPE_NONCACHEABLE",
"PARSEOP_MEMTYPE_PREFETCHABLE","PARSEOP_MEMTYPE_WRITECOMBINING",
"PARSEOP_METHOD","PARSEOP_METHODCALL","PARSEOP_MID","PARSEOP_MINTYPE_FIXED",
"PARSEOP_MINTYPE_NOTFIXED","PARSEOP_MOD","PARSEOP_MULTIPLY","PARSEOP_MUTEX",
"PARSEOP_NAME","PARSEOP_NAMESEG","PARSEOP_NAMESTRING","PARSEOP_NAND",
"PARSEOP_NOOP","PARSEOP_NOR","PARSEOP_NOT","PARSEOP_NOTIFY",
"PARSEOP_OBJECTTYPE","PARSEOP_OBJECTTYPE_BFF","PARSEOP_OBJECTTYPE_BUF",
"PARSEOP_OBJECTTYPE_DDB","PARSEOP_OBJECTTYPE_DEV","PARSEOP_OBJECTTYPE_EVT",
"PARSEOP_OBJECTTYPE_FLD","PARSEOP_OBJECTTYPE_INT","PARSEOP_OBJECTTYPE_MTH",
"PARSEOP_OBJECTTYPE_MTX","PARSEOP_OBJECTTYPE_OPR","PARSEOP_OBJECTTYPE_PKG",
"PARSEOP_OBJECTTYPE_POW","PARSEOP_OBJECTTYPE_PRO","PARSEOP_OBJECTTYPE_STR",
"PARSEOP_OBJECTTYPE_THZ","PARSEOP_OBJECTTYPE_UNK","PARSEOP_OFFSET",
"PARSEOP_ONE","PARSEOP_ONES","PARSEOP_OPERATIONREGION","PARSEOP_OR",
"PARSEOP_PACKAGE","PARSEOP_PACKAGE_LENGTH","PARSEOP_PARITYTYPE_EVEN",
"PARSEOP_PARITYTYPE_MARK","PARSEOP_PARITYTYPE_NONE","PARSEOP_PARITYTYPE_ODD",
"PARSEOP_PARITYTYPE_SPACE","PARSEOP_PINCONFIG","PARSEOP_PINFUNCTION",
"PARSEOP_PINGROUP","PARSEOP_PINGROUPCONFIG","PARSEOP_PINGROUPFUNCTION",
"PARSEOP_PIN_NOPULL","PARSEOP_PIN_PULLDEFAULT","PARSEOP_PIN_PULLDOWN",
"PARSEOP_PIN_PULLUP","PARSEOP_POWERRESOURCE","PARSEOP_PROCESSOR",
"PARSEOP_QWORDCONST","PARSEOP_QWORDIO","PARSEOP_QWORDMEMORY",
"PARSEOP_QWORDSPACE","PARSEOP_RANGETYPE_ENTIRE","PARSEOP_RANGETYPE_ISAONLY",
"PARSEOP_RANGETYPE_NONISAONLY","PARSEOP_RAW_DATA","PARSEOP_READWRITETYPE_BOTH",
"PARSEOP_READWRITETYPE_READONLY","PARSEOP_REFOF","PARSEOP_REGIONSPACE_CMOS",
"PARSEOP_REGIONSPACE_EC","PARSEOP_REGIONSPACE_FFIXEDHW",
"PARSEOP_REGIONSPACE_GPIO","PARSEOP_REGIONSPACE_GSBUS","PARSEOP_REGIONSPACE_IO",
"PARSEOP_REGIONSPACE_IPMI","PARSEOP_REGIONSPACE_MEM","PARSEOP_REGIONSPACE_PCC",
"PARSEOP_REGIONSPACE_PCI","PARSEOP_REGIONSPACE_PCIBAR",
"PARSEOP_REGIONSPACE_SMBUS","PARSEOP_REGISTER","PARSEOP_RELEASE",
"PARSEOP_RESERVED_BYTES","PARSEOP_RESET","PARSEOP_RESOURCETEMPLATE",
"PARSEOP_RESOURCETYPE_CONSUMER","PARSEOP_RESOURCETYPE_PRODUCER",
"PARSEOP_RETURN","PARSEOP_REVISION","PARSEOP_SCOPE",
"PARSEOP_SERIALIZERULE_NOTSERIAL","PARSEOP_SERIALIZERULE_SERIAL",
"PARSEOP_SHARETYPE_EXCLUSIVE","PARSEOP_SHARETYPE_EXCLUSIVEWAKE",
"PARSEOP_SHARETYPE_SHARED","PARSEOP_SHARETYPE_SHAREDWAKE","PARSEOP_SHIFTLEFT",
"PARSEOP_SHIFTRIGHT","PARSEOP_SIGNAL","PARSEOP_SIZEOF",
"PARSEOP_SLAVEMODE_CONTROLLERINIT","PARSEOP_SLAVEMODE_DEVICEINIT",
"PARSEOP_SLEEP","PARSEOP_SPI_SERIALBUS","PARSEOP_SPI_SERIALBUS_V2",
"PARSEOP_STALL","PARSEOP_STARTDEPENDENTFN","PARSEOP_STARTDEPENDENTFN_NOPRI",
"PARSEOP_STOPBITS_ONE","PARSEOP_STOPBITS_ONEPLUSHALF","PARSEOP_STOPBITS_TWO",
"PARSEOP_STOPBITS_ZERO","PARSEOP_STORE","PARSEOP_STRING_LITERAL",
"PARSEOP_SUBTRACT","PARSEOP_SWITCH","PARSEOP_THERMALZONE","PARSEOP_TIMER",
"PARSEOP_TOBCD","PARSEOP_TOBUFFER","PARSEOP_TODECIMALSTRING",
"PARSEOP_TOHEXSTRING","PARSEOP_TOINTEGER","PARSEOP_TOSTRING","PARSEOP_TOUUID",
"PARSEOP_TRANSLATIONTYPE_DENSE","PARSEOP_TRANSLATIONTYPE_SPARSE",
"PARSEOP_TYPE_STATIC","PARSEOP_TYPE_TRANSLATION","PARSEOP_UART_SERIALBUS",
"PARSEOP_UART_SERIALBUS_V2","PARSEOP_UNICODE","PARSEOP_UNLOAD",
"PARSEOP_UPDATERULE_ONES","PARSEOP_UPDATERULE_PRESERVE",
"PARSEOP_UPDATERULE_ZEROS","PARSEOP_VAR_PACKAGE","PARSEOP_VENDORLONG",
"PARSEOP_VENDORSHORT","PARSEOP_WAIT","PARSEOP_WHILE","PARSEOP_WIREMODE_FOUR",
"PARSEOP_WIREMODE_THREE","PARSEOP_WORDBUSNUMBER","PARSEOP_WORDCONST",
"PARSEOP_WORDIO","PARSEOP_WORDSPACE","PARSEOP_XFERSIZE_8","PARSEOP_XFERSIZE_16",
"PARSEOP_XFERSIZE_32","PARSEOP_XFERSIZE_64","PARSEOP_XFERSIZE_128",
"PARSEOP_XFERSIZE_256","PARSEOP_XFERTYPE_8","PARSEOP_XFERTYPE_8_16",
"PARSEOP_XFERTYPE_16","PARSEOP_XOR","PARSEOP_ZERO","PARSEOP_TOPLD",
"PARSEOP_PLD_REVISION","PARSEOP_PLD_IGNORECOLOR","PARSEOP_PLD_RED",
"PARSEOP_PLD_GREEN","PARSEOP_PLD_BLUE","PARSEOP_PLD_WIDTH","PARSEOP_PLD_HEIGHT",
"PARSEOP_PLD_USERVISIBLE","PARSEOP_PLD_DOCK","PARSEOP_PLD_LID",
"PARSEOP_PLD_PANEL","PARSEOP_PLD_VERTICALPOSITION",
"PARSEOP_PLD_HORIZONTALPOSITION","PARSEOP_PLD_SHAPE",
"PARSEOP_PLD_GROUPORIENTATION","PARSEOP_PLD_GROUPTOKEN",
"PARSEOP_PLD_GROUPPOSITION","PARSEOP_PLD_BAY","PARSEOP_PLD_EJECTABLE",
"PARSEOP_PLD_EJECTREQUIRED","PARSEOP_PLD_CABINETNUMBER",
"PARSEOP_PLD_CARDCAGENUMBER","PARSEOP_PLD_REFERENCE","PARSEOP_PLD_ROTATION",
"PARSEOP_PLD_ORDER","PARSEOP_PLD_RESERVED","PARSEOP_PLD_VERTICALOFFSET",
"PARSEOP_PLD_HORIZONTALOFFSET","PARSEOP_EXP_EQUALS","PARSEOP_EXP_ADD_EQ",
"PARSEOP_EXP_SUB_EQ","PARSEOP_EXP_MUL_EQ","PARSEOP_EXP_DIV_EQ",
"PARSEOP_EXP_MOD_EQ","PARSEOP_EXP_SHL_EQ","PARSEOP_EXP_SHR_EQ",
"PARSEOP_EXP_AND_EQ","PARSEOP_EXP_XOR_EQ","PARSEOP_EXP_OR_EQ",
"PARSEOP_EXP_LOGICAL_OR","PARSEOP_EXP_LOGICAL_AND","PARSEOP_EXP_OR",
"PARSEOP_EXP_XOR","PARSEOP_EXP_AND","PARSEOP_EXP_EQUAL","PARSEOP_EXP_NOT_EQUAL",
"PARSEOP_EXP_GREATER","PARSEOP_EXP_LESS","PARSEOP_EXP_GREATER_EQUAL",
"PARSEOP_EXP_LESS_EQUAL","PARSEOP_EXP_SHIFT_RIGHT","PARSEOP_EXP_SHIFT_LEFT",
"PARSEOP_EXP_ADD","PARSEOP_EXP_SUBTRACT","PARSEOP_EXP_MULTIPLY",
"PARSEOP_EXP_DIVIDE","PARSEOP_EXP_MODULO","PARSEOP_EXP_NOT",
"PARSEOP_EXP_LOGICAL_NOT","PARSEOP_EXP_INCREMENT","PARSEOP_EXP_DECREMENT",
"PARSEOP_OPEN_PAREN","PARSEOP_CLOSE_PAREN","PARSEOP_EXP_INDEX_LEFT",
"PARSEOP_EXP_INDEX_RIGHT","PARSEOP_PRINTF","PARSEOP_FPRINTF","PARSEOP_FOR",
"PARSEOP_STRUCTURE","PARSEOP_STRUCTURE_NAMESTRING","PARSEOP_STRUCTURE_TAG",
"PARSEOP_STRUCTURE_ELEMENT","PARSEOP_STRUCTURE_INSTANCE",
"PARSEOP_STRUCTURE_REFERENCE","PARSEOP_STRUCTURE_POINTER","PARSEOP_ASL_CODE",
"PARSEOP_INTEGER_TYPE","PARSEOP_STRING_TYPE","PARSEOP_BUFFER_TYPE",
"PARSEOP_PACKAGE_TYPE","PARSEOP_REFERENCE_TYPE","PARSEOP___DATE__",
"PARSEOP___FILE__","PARSEOP___LINE__","PARSEOP___PATH__","PARSEOP___METHOD__",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const AslCompilerrule[] = {
"$accept : AslCode",
"AslCode : DefinitionBlockList",
"AslCode : error",
"$$1 :",
"$$2 :",
"DefinitionBlockTerm : PARSEOP_DEFINITION_BLOCK PARSEOP_OPEN_PAREN $$1 String ',' String ',' ByteConst ',' String ',' String ',' DWordConst PARSEOP_CLOSE_PAREN $$2 '{' TermList '}'",
"DefinitionBlockList : DefinitionBlockTerm",
"DefinitionBlockList : DefinitionBlockTerm DefinitionBlockList",
"NameString : NameSeg",
"NameString : PARSEOP_NAMESTRING",
"NameString : PARSEOP_IO",
"NameString : PARSEOP_DMA",
"NameString : PARSEOP_IRQ",
"NameString : PARSEOP_FOR",
"NameSeg : PARSEOP_NAMESEG",
"Term : Object",
"Term : Type1Opcode",
"Term : Type2Opcode",
"Term : Type2IntegerOpcode",
"Term : Type2StringOpcode",
"Term : Type2BufferOpcode",
"Term : Type2BufferOrStringOpcode",
"Term : error",
"SuperName : SimpleName",
"SuperName : DebugTerm",
"SuperName : Type6Opcode",
"Target :",
"Target : ','",
"Target : ',' SuperName",
"RequiredTarget : ',' SuperName",
"TermArg : SimpleName",
"TermArg : Type2Opcode",
"TermArg : DataObject",
"TermArg : PARSEOP_OPEN_PAREN TermArg PARSEOP_CLOSE_PAREN",
"$$3 :",
"MethodInvocationTerm : NameString PARSEOP_OPEN_PAREN $$3 ArgList PARSEOP_CLOSE_PAREN",
"OptionalCount :",
"OptionalCount : ','",
"OptionalCount : ',' TermArg",
"OptionalDataCount :",
"OptionalDataCount : PARSEOP_OPEN_PAREN TermArg PARSEOP_CLOSE_PAREN",
"OptionalDataCount : PARSEOP_OPEN_PAREN PARSEOP_CLOSE_PAREN",
"OptionalDataCount : PARSEOP_EXP_EQUALS",
"OptionalDataCount : PARSEOP_OPEN_PAREN TermArg PARSEOP_CLOSE_PAREN PARSEOP_EXP_EQUALS",
"OptionalDataCount : PARSEOP_OPEN_PAREN PARSEOP_CLOSE_PAREN String PARSEOP_EXP_EQUALS",
"TermList :",
"TermList : TermList Term",
"TermList : TermList Term ';'",
"TermList : TermList ';' Term",
"TermList : TermList ';' Term ';'",
"ArgList :",
"ArgList : TermArg",
"ArgList : ArgList ','",
"ArgList : ArgList ',' TermArg",
"ByteList :",
"ByteList : ByteConstExpr",
"ByteList : ByteList ','",
"ByteList : ByteList ',' ByteConstExpr",
"DWordList :",
"DWordList : DWordConstExpr",
"DWordList : DWordList ','",
"DWordList : DWordList ',' DWordConstExpr",
"FieldUnitList :",
"FieldUnitList : FieldUnit",
"FieldUnitList : FieldUnitList ','",
"FieldUnitList : FieldUnitList ',' FieldUnit",
"FieldUnit : FieldUnitEntry",
"FieldUnit : OffsetTerm",
"FieldUnit : AccessAsTerm",
"FieldUnit : ConnectionTerm",
"FieldUnitEntry : ',' AmlPackageLengthTerm",
"FieldUnitEntry : NameSeg ',' AmlPackageLengthTerm",
"Object : CompilerDirective",
"Object : NamedObject",
"Object : NameSpaceModifier",
"PackageList :",
"PackageList : PackageElement",
"PackageList : PackageList ','",
"PackageList : PackageList ',' PackageElement",
"PackageElement : DataObject",
"PackageElement : NameString",
"ParameterTypePackage :",
"ParameterTypePackage : ObjectTypeKeyword",
"ParameterTypePackage : ParameterTypePackage ',' ObjectTypeKeyword",
"ParameterTypePackageList :",
"ParameterTypePackageList : ObjectTypeKeyword",
"ParameterTypePackageList : '{' ParameterTypePackage '}'",
"OptionalParameterTypePackage :",
"OptionalParameterTypePackage : ',' ParameterTypePackageList",
"ParameterTypesPackage : ParameterTypePackageList",
"ParameterTypesPackage : ParameterTypesPackage ',' ParameterTypePackageList",
"ParameterTypesPackageList :",
"ParameterTypesPackageList : ObjectTypeKeyword",
"ParameterTypesPackageList : '{' ParameterTypesPackage '}'",
"OptionalParameterTypesPackage :",
"OptionalParameterTypesPackage : ',' ParameterTypesPackageList",
"CaseDefaultTermList :",
"CaseDefaultTermList : CaseTerm",
"CaseDefaultTermList : DefaultTerm",
"CaseDefaultTermList : CaseDefaultTermList CaseTerm",
"CaseDefaultTermList : CaseDefaultTermList DefaultTerm",
"DataObject : BufferData",
"DataObject : PackageData",
"DataObject : IntegerData",
"DataObject : StringData",
"BufferData : Type5Opcode",
"BufferData : Type2BufferOrStringOpcode",
"BufferData : Type2BufferOpcode",
"BufferData : BufferTerm",
"PackageData : PackageTerm",
"IntegerData : Type2IntegerOpcode",
"IntegerData : Type3Opcode",
"IntegerData : Integer",
"IntegerData : ConstTerm",
"StringData : Type2StringOpcode",
"StringData : String",
"ByteConst : Integer",
"WordConst : Integer",
"DWordConst : Integer",
"QWordConst : Integer",
"ByteConstExpr : Type3Opcode",
"ByteConstExpr : Type2IntegerOpcode",
"ByteConstExpr : ConstExprTerm",
"ByteConstExpr : ByteConst",
"WordConstExpr : Type3Opcode",
"WordConstExpr : Type2IntegerOpcode",
"WordConstExpr : ConstExprTerm",
"WordConstExpr : WordConst",
"DWordConstExpr : Type3Opcode",
"DWordConstExpr : Type2IntegerOpcode",
"DWordConstExpr : ConstExprTerm",
"DWordConstExpr : DWordConst",
"QWordConstExpr : Type3Opcode",
"QWordConstExpr : Type2IntegerOpcode",
"QWordConstExpr : ConstExprTerm",
"QWordConstExpr : QWordConst",
"ConstTerm : ConstExprTerm",
"ConstTerm : PARSEOP_REVISION",
"ConstExprTerm : PARSEOP_ZERO",
"ConstExprTerm : PARSEOP_ONE",
"ConstExprTerm : PARSEOP_ONES",
"ConstExprTerm : PARSEOP___DATE__",
"ConstExprTerm : PARSEOP___FILE__",
"ConstExprTerm : PARSEOP___LINE__",
"ConstExprTerm : PARSEOP___PATH__",
"ConstExprTerm : PARSEOP___METHOD__",
"Integer : PARSEOP_INTEGER",
"String : PARSEOP_STRING_LITERAL",
"CompilerDirective : IncludeTerm",
"CompilerDirective : IncludeEndTerm",
"CompilerDirective : ExternalTerm",
"NamedObject : BankFieldTerm",
"NamedObject : CreateBitFieldTerm",
"NamedObject : CreateByteFieldTerm",
"NamedObject : CreateDWordFieldTerm",
"NamedObject : CreateFieldTerm",
"NamedObject : CreateQWordFieldTerm",
"NamedObject : CreateWordFieldTerm",
"NamedObject : DataRegionTerm",
"NamedObject : DeviceTerm",
"NamedObject : EventTerm",
"NamedObject : FieldTerm",
"NamedObject : FunctionTerm",
"NamedObject : IndexFieldTerm",
"NamedObject : MethodTerm",
"NamedObject : MutexTerm",
"NamedObject : OpRegionTerm",
"NamedObject : PowerResTerm",
"NamedObject : ProcessorTerm",
"NamedObject : ThermalZoneTerm",
"NameSpaceModifier : AliasTerm",
"NameSpaceModifier : NameTerm",
"NameSpaceModifier : ScopeTerm",
"SimpleName : NameString",
"SimpleName : LocalTerm",
"SimpleName : ArgTerm",
"ObjectTypeSource : SimpleName",
"ObjectTypeSource : DebugTerm",
"ObjectTypeSource : RefOfTerm",
"ObjectTypeSource : DerefOfTerm",
"ObjectTypeSource : IndexTerm",
"ObjectTypeSource : IndexExpTerm",
"DerefOfSource : SimpleName",
"DerefOfSource : RefOfTerm",
"DerefOfSource : DerefOfTerm",
"DerefOfSource : IndexTerm",
"DerefOfSource : IndexExpTerm",
"DerefOfSource : StoreTerm",
"DerefOfSource : EqualsTerm",
"DerefOfSource : MethodInvocationTerm",
"RefOfSource : SimpleName",
"RefOfSource : DebugTerm",
"RefOfSource : DerefOfTerm",
"RefOfSource : IndexTerm",
"RefOfSource : IndexExpTerm",
"CondRefOfSource : SimpleName",
"CondRefOfSource : DebugTerm",
"CondRefOfSource : DerefOfTerm",
"CondRefOfSource : IndexTerm",
"CondRefOfSource : IndexExpTerm",
"Type1Opcode : BreakTerm",
"Type1Opcode : BreakPointTerm",
"Type1Opcode : ContinueTerm",
"Type1Opcode : FatalTerm",
"Type1Opcode : ForTerm",
"Type1Opcode : ElseIfTerm",
"Type1Opcode : LoadTerm",
"Type1Opcode : NoOpTerm",
"Type1Opcode : NotifyTerm",
"Type1Opcode : ReleaseTerm",
"Type1Opcode : ResetTerm",
"Type1Opcode : ReturnTerm",
"Type1Opcode : SignalTerm",
"Type1Opcode : SleepTerm",
"Type1Opcode : StallTerm",
"Type1Opcode : SwitchTerm",
"Type1Opcode : UnloadTerm",
"Type1Opcode : WhileTerm",
"Type2Opcode : AcquireTerm",
"Type2Opcode : CondRefOfTerm",
"Type2Opcode : CopyObjectTerm",
"Type2Opcode : DerefOfTerm",
"Type2Opcode : ObjectTypeTerm",
"Type2Opcode : RefOfTerm",
"Type2Opcode : SizeOfTerm",
"Type2Opcode : StoreTerm",
"Type2Opcode : EqualsTerm",
"Type2Opcode : TimerTerm",
"Type2Opcode : WaitTerm",
"Type2Opcode : MethodInvocationTerm",
"Type2IntegerOpcode : Expression",
"Type2IntegerOpcode : AddTerm",
"Type2IntegerOpcode : AndTerm",
"Type2IntegerOpcode : DecTerm",
"Type2IntegerOpcode : DivideTerm",
"Type2IntegerOpcode : FindSetLeftBitTerm",
"Type2IntegerOpcode : FindSetRightBitTerm",
"Type2IntegerOpcode : FromBCDTerm",
"Type2IntegerOpcode : IncTerm",
"Type2IntegerOpcode : IndexTerm",
"Type2IntegerOpcode : LAndTerm",
"Type2IntegerOpcode : LEqualTerm",
"Type2IntegerOpcode : LGreaterTerm",
"Type2IntegerOpcode : LGreaterEqualTerm",
"Type2IntegerOpcode : LLessTerm",
"Type2IntegerOpcode : LLessEqualTerm",
"Type2IntegerOpcode : LNotTerm",
"Type2IntegerOpcode : LNotEqualTerm",
"Type2IntegerOpcode : LoadTableTerm",
"Type2IntegerOpcode : LOrTerm",
"Type2IntegerOpcode : MatchTerm",
"Type2IntegerOpcode : ModTerm",
"Type2IntegerOpcode : MultiplyTerm",
"Type2IntegerOpcode : NAndTerm",
"Type2IntegerOpcode : NOrTerm",
"Type2IntegerOpcode : NotTerm",
"Type2IntegerOpcode : OrTerm",
"Type2IntegerOpcode : ShiftLeftTerm",
"Type2IntegerOpcode : ShiftRightTerm",
"Type2IntegerOpcode : SubtractTerm",
"Type2IntegerOpcode : ToBCDTerm",
"Type2IntegerOpcode : ToIntegerTerm",
"Type2IntegerOpcode : XOrTerm",
"Type2StringOpcode : ToDecimalStringTerm",
"Type2StringOpcode : ToHexStringTerm",
"Type2StringOpcode : ToStringTerm",
"Type2BufferOpcode : ToBufferTerm",
"Type2BufferOpcode : ConcatResTerm",
"Type2BufferOrStringOpcode : ConcatTerm",
"Type2BufferOrStringOpcode : PrintfTerm",
"Type2BufferOrStringOpcode : FprintfTerm",
"Type2BufferOrStringOpcode : MidTerm",
"Type3Opcode : EISAIDTerm",
"Type5Opcode : ResourceTemplateTerm",
"Type5Opcode : UnicodeTerm",
"Type5Opcode : ToPLDTerm",
"Type5Opcode : ToUUIDTerm",
"Type6Opcode : RefOfTerm",
"Type6Opcode : DerefOfTerm",
"Type6Opcode : IndexTerm",
"Type6Opcode : IndexExpTerm",
"Type6Opcode : MethodInvocationTerm",
"AmlPackageLengthTerm : Integer",
"NameStringItem : ',' NameString",
"NameStringItem : ',' error",
"TermArgItem : ',' TermArg",
"TermArgItem : ',' error",
"OptionalReference :",
"OptionalReference : ','",
"OptionalReference : ',' TermArg",
"OptionalReturnArg :",
"OptionalReturnArg : TermArg",
"OptionalSerializeRuleKeyword :",
"OptionalSerializeRuleKeyword : ','",
"OptionalSerializeRuleKeyword : ',' SerializeRuleKeyword",
"OptionalTermArg :",
"OptionalTermArg : TermArg",
"OptionalWordConst :",
"OptionalWordConst : WordConst",
"AccessAsTerm : PARSEOP_ACCESSAS PARSEOP_OPEN_PAREN AccessTypeKeyword OptionalAccessAttribTerm PARSEOP_CLOSE_PAREN",
"AccessAsTerm : PARSEOP_ACCESSAS PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$4 :",
"AcquireTerm : PARSEOP_ACQUIRE PARSEOP_OPEN_PAREN $$4 SuperName ',' WordConstExpr PARSEOP_CLOSE_PAREN",
"AcquireTerm : PARSEOP_ACQUIRE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$5 :",
"AddTerm : PARSEOP_ADD PARSEOP_OPEN_PAREN $$5 TermArg TermArgItem Target PARSEOP_CLOSE_PAREN",
"AddTerm : PARSEOP_ADD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$6 :",
"AliasTerm : PARSEOP_ALIAS PARSEOP_OPEN_PAREN $$6 NameString NameStringItem PARSEOP_CLOSE_PAREN",
"AliasTerm : PARSEOP_ALIAS PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$7 :",
"AndTerm : PARSEOP_AND PARSEOP_OPEN_PAREN $$7 TermArg TermArgItem Target PARSEOP_CLOSE_PAREN",
"AndTerm : PARSEOP_AND PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"ArgTerm : PARSEOP_ARG0",
"ArgTerm : PARSEOP_ARG1",
"ArgTerm : PARSEOP_ARG2",
"ArgTerm : PARSEOP_ARG3",
"ArgTerm : PARSEOP_ARG4",
"ArgTerm : PARSEOP_ARG5",
"ArgTerm : PARSEOP_ARG6",
"$$8 :",
"BankFieldTerm : PARSEOP_BANKFIELD PARSEOP_OPEN_PAREN $$8 NameString NameStringItem TermArgItem ',' AccessTypeKeyword ',' LockRuleKeyword ',' UpdateRuleKeyword PARSEOP_CLOSE_PAREN '{' FieldUnitList '}'",
"BankFieldTerm : PARSEOP_BANKFIELD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN '{' error '}'",
"BreakTerm : PARSEOP_BREAK",
"BreakPointTerm : PARSEOP_BREAKPOINT",
"$$9 :",
"BufferTerm : PARSEOP_BUFFER $$9 OptionalDataCount '{' BufferTermData '}'",
"BufferTermData : ByteList",
"BufferTermData : StringData",
"$$10 :",
"CaseTerm : PARSEOP_CASE PARSEOP_OPEN_PAREN $$10 DataObject PARSEOP_CLOSE_PAREN '{' TermList '}'",
"CaseTerm : PARSEOP_CASE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$11 :",
"ConcatTerm : PARSEOP_CONCATENATE PARSEOP_OPEN_PAREN $$11 TermArg TermArgItem Target PARSEOP_CLOSE_PAREN",
"ConcatTerm : PARSEOP_CONCATENATE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$12 :",
"ConcatResTerm : PARSEOP_CONCATENATERESTEMPLATE PARSEOP_OPEN_PAREN $$12 TermArg TermArgItem Target PARSEOP_CLOSE_PAREN",
"ConcatResTerm : PARSEOP_CONCATENATERESTEMPLATE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$13 :",
"CondRefOfTerm : PARSEOP_CONDREFOF PARSEOP_OPEN_PAREN $$13 CondRefOfSource Target PARSEOP_CLOSE_PAREN",
"CondRefOfTerm : PARSEOP_CONDREFOF PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"ConnectionTerm : PARSEOP_CONNECTION PARSEOP_OPEN_PAREN NameString PARSEOP_CLOSE_PAREN",
"$$14 :",
"ConnectionTerm : PARSEOP_CONNECTION PARSEOP_OPEN_PAREN $$14 ResourceMacroTerm PARSEOP_CLOSE_PAREN",
"ConnectionTerm : PARSEOP_CONNECTION PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"ContinueTerm : PARSEOP_CONTINUE",
"$$15 :",
"CopyObjectTerm : PARSEOP_COPYOBJECT PARSEOP_OPEN_PAREN $$15 TermArg ',' SimpleName PARSEOP_CLOSE_PAREN",
"CopyObjectTerm : PARSEOP_COPYOBJECT PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$16 :",
"CreateBitFieldTerm : PARSEOP_CREATEBITFIELD PARSEOP_OPEN_PAREN $$16 TermArg TermArgItem NameStringItem PARSEOP_CLOSE_PAREN",
"CreateBitFieldTerm : PARSEOP_CREATEBITFIELD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$17 :",
"CreateByteFieldTerm : PARSEOP_CREATEBYTEFIELD PARSEOP_OPEN_PAREN $$17 TermArg TermArgItem NameStringItem PARSEOP_CLOSE_PAREN",
"CreateByteFieldTerm : PARSEOP_CREATEBYTEFIELD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$18 :",
"CreateDWordFieldTerm : PARSEOP_CREATEDWORDFIELD PARSEOP_OPEN_PAREN $$18 TermArg TermArgItem NameStringItem PARSEOP_CLOSE_PAREN",
"CreateDWordFieldTerm : PARSEOP_CREATEDWORDFIELD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$19 :",
"CreateFieldTerm : PARSEOP_CREATEFIELD PARSEOP_OPEN_PAREN $$19 TermArg TermArgItem TermArgItem NameStringItem PARSEOP_CLOSE_PAREN",
"CreateFieldTerm : PARSEOP_CREATEFIELD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$20 :",
"CreateQWordFieldTerm : PARSEOP_CREATEQWORDFIELD PARSEOP_OPEN_PAREN $$20 TermArg TermArgItem NameStringItem PARSEOP_CLOSE_PAREN",
"CreateQWordFieldTerm : PARSEOP_CREATEQWORDFIELD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$21 :",
"CreateWordFieldTerm : PARSEOP_CREATEWORDFIELD PARSEOP_OPEN_PAREN $$21 TermArg TermArgItem NameStringItem PARSEOP_CLOSE_PAREN",
"CreateWordFieldTerm : PARSEOP_CREATEWORDFIELD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$22 :",
"DataRegionTerm : PARSEOP_DATATABLEREGION PARSEOP_OPEN_PAREN $$22 NameString TermArgItem TermArgItem TermArgItem PARSEOP_CLOSE_PAREN",
"DataRegionTerm : PARSEOP_DATATABLEREGION PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"DebugTerm : PARSEOP_DEBUG",
"$$23 :",
"DecTerm : PARSEOP_DECREMENT PARSEOP_OPEN_PAREN $$23 SuperName PARSEOP_CLOSE_PAREN",
"DecTerm : PARSEOP_DECREMENT PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$24 :",
"DefaultTerm : PARSEOP_DEFAULT '{' $$24 TermList '}'",
"DefaultTerm : PARSEOP_DEFAULT '{' error '}'",
"$$25 :",
"DerefOfTerm : PARSEOP_DEREFOF PARSEOP_OPEN_PAREN $$25 DerefOfSource PARSEOP_CLOSE_PAREN",
"DerefOfTerm : PARSEOP_DEREFOF PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$26 :",
"DeviceTerm : PARSEOP_DEVICE PARSEOP_OPEN_PAREN $$26 NameString PARSEOP_CLOSE_PAREN '{' TermList '}'",
"DeviceTerm : PARSEOP_DEVICE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$27 :",
"DivideTerm : PARSEOP_DIVIDE PARSEOP_OPEN_PAREN $$27 TermArg TermArgItem Target Target PARSEOP_CLOSE_PAREN",
"DivideTerm : PARSEOP_DIVIDE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"EISAIDTerm : PARSEOP_EISAID PARSEOP_OPEN_PAREN StringData PARSEOP_CLOSE_PAREN",
"EISAIDTerm : PARSEOP_EISAID PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"ElseIfTerm : IfTerm ElseTerm",
"ElseTerm :",
"$$28 :",
"ElseTerm : PARSEOP_ELSE '{' TermList $$28 '}'",
"ElseTerm : PARSEOP_ELSE '{' error '}'",
"ElseTerm : PARSEOP_ELSE error",
"$$29 :",
"$$30 :",
"$$31 :",
"$$32 :",
"ElseTerm : PARSEOP_ELSEIF PARSEOP_OPEN_PAREN $$29 TermArg $$30 PARSEOP_CLOSE_PAREN '{' TermList '}' $$31 ElseTerm $$32",
"ElseTerm : PARSEOP_ELSEIF PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"ElseTerm : PARSEOP_ELSEIF error",
"$$33 :",
"EventTerm : PARSEOP_EVENT PARSEOP_OPEN_PAREN $$33 NameString PARSEOP_CLOSE_PAREN",
"EventTerm : PARSEOP_EVENT PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"ExternalTerm : PARSEOP_EXTERNAL PARSEOP_OPEN_PAREN NameString OptionalObjectTypeKeyword OptionalParameterTypePackage OptionalParameterTypesPackage PARSEOP_CLOSE_PAREN",
"ExternalTerm : PARSEOP_EXTERNAL PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$34 :",
"FatalTerm : PARSEOP_FATAL PARSEOP_OPEN_PAREN $$34 ByteConstExpr ',' DWordConstExpr TermArgItem PARSEOP_CLOSE_PAREN",
"FatalTerm : PARSEOP_FATAL PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$35 :",
"FieldTerm : PARSEOP_FIELD PARSEOP_OPEN_PAREN $$35 NameString ',' AccessTypeKeyword ',' LockRuleKeyword ',' UpdateRuleKeyword PARSEOP_CLOSE_PAREN '{' FieldUnitList '}'",
"FieldTerm : PARSEOP_FIELD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN '{' error '}'",
"$$36 :",
"FindSetLeftBitTerm : PARSEOP_FINDSETLEFTBIT PARSEOP_OPEN_PAREN $$36 TermArg Target PARSEOP_CLOSE_PAREN",
"FindSetLeftBitTerm : PARSEOP_FINDSETLEFTBIT PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$37 :",
"FindSetRightBitTerm : PARSEOP_FINDSETRIGHTBIT PARSEOP_OPEN_PAREN $$37 TermArg Target PARSEOP_CLOSE_PAREN",
"FindSetRightBitTerm : PARSEOP_FINDSETRIGHTBIT PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$38 :",
"$$39 :",
"$$40 :",
"$$41 :",
"ForTerm : PARSEOP_FOR PARSEOP_OPEN_PAREN $$38 OptionalTermArg ',' $$39 OptionalPredicate ',' OptionalTermArg $$40 PARSEOP_CLOSE_PAREN '{' TermList '}' $$41",
"OptionalPredicate :",
"OptionalPredicate : TermArg",
"$$42 :",
"FprintfTerm : PARSEOP_FPRINTF PARSEOP_OPEN_PAREN $$42 TermArg ',' StringData PrintfArgList PARSEOP_CLOSE_PAREN",
"FprintfTerm : PARSEOP_FPRINTF PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$43 :",
"FromBCDTerm : PARSEOP_FROMBCD PARSEOP_OPEN_PAREN $$43 TermArg Target PARSEOP_CLOSE_PAREN",
"FromBCDTerm : PARSEOP_FROMBCD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$44 :",
"$$45 :",
"FunctionTerm : PARSEOP_FUNCTION PARSEOP_OPEN_PAREN $$44 NameString OptionalParameterTypePackage OptionalParameterTypesPackage PARSEOP_CLOSE_PAREN '{' $$45 TermList '}'",
"FunctionTerm : PARSEOP_FUNCTION PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$46 :",
"IfTerm : PARSEOP_IF PARSEOP_OPEN_PAREN $$46 TermArg PARSEOP_CLOSE_PAREN '{' TermList '}'",
"IfTerm : PARSEOP_IF PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"IncludeTerm : PARSEOP_INCLUDE PARSEOP_OPEN_PAREN String PARSEOP_CLOSE_PAREN",
"IncludeEndTerm : PARSEOP_INCLUDE_END",
"$$47 :",
"IncTerm : PARSEOP_INCREMENT PARSEOP_OPEN_PAREN $$47 SuperName PARSEOP_CLOSE_PAREN",
"IncTerm : PARSEOP_INCREMENT PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$48 :",
"IndexFieldTerm : PARSEOP_INDEXFIELD PARSEOP_OPEN_PAREN $$48 NameString NameStringItem ',' AccessTypeKeyword ',' LockRuleKeyword ',' UpdateRuleKeyword PARSEOP_CLOSE_PAREN '{' FieldUnitList '}'",
"IndexFieldTerm : PARSEOP_INDEXFIELD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN '{' error '}'",
"$$49 :",
"IndexTerm : PARSEOP_INDEX PARSEOP_OPEN_PAREN $$49 TermArg TermArgItem Target PARSEOP_CLOSE_PAREN",
"IndexTerm : PARSEOP_INDEX PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$50 :",
"LAndTerm : PARSEOP_LAND PARSEOP_OPEN_PAREN $$50 TermArg TermArgItem PARSEOP_CLOSE_PAREN",
"LAndTerm : PARSEOP_LAND PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$51 :",
"LEqualTerm : PARSEOP_LEQUAL PARSEOP_OPEN_PAREN $$51 TermArg TermArgItem PARSEOP_CLOSE_PAREN",
"LEqualTerm : PARSEOP_LEQUAL PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$52 :",
"LGreaterEqualTerm : PARSEOP_LGREATEREQUAL PARSEOP_OPEN_PAREN $$52 TermArg TermArgItem PARSEOP_CLOSE_PAREN",
"LGreaterEqualTerm : PARSEOP_LGREATEREQUAL PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$53 :",
"LGreaterTerm : PARSEOP_LGREATER PARSEOP_OPEN_PAREN $$53 TermArg TermArgItem PARSEOP_CLOSE_PAREN",
"LGreaterTerm : PARSEOP_LGREATER PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$54 :",
"LLessEqualTerm : PARSEOP_LLESSEQUAL PARSEOP_OPEN_PAREN $$54 TermArg TermArgItem PARSEOP_CLOSE_PAREN",
"LLessEqualTerm : PARSEOP_LLESSEQUAL PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$55 :",
"LLessTerm : PARSEOP_LLESS PARSEOP_OPEN_PAREN $$55 TermArg TermArgItem PARSEOP_CLOSE_PAREN",
"LLessTerm : PARSEOP_LLESS PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$56 :",
"LNotEqualTerm : PARSEOP_LNOTEQUAL PARSEOP_OPEN_PAREN $$56 TermArg TermArgItem PARSEOP_CLOSE_PAREN",
"LNotEqualTerm : PARSEOP_LNOTEQUAL PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$57 :",
"LNotTerm : PARSEOP_LNOT PARSEOP_OPEN_PAREN $$57 TermArg PARSEOP_CLOSE_PAREN",
"LNotTerm : PARSEOP_LNOT PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$58 :",
"LoadTableTerm : PARSEOP_LOADTABLE PARSEOP_OPEN_PAREN $$58 TermArg TermArgItem TermArgItem OptionalListString OptionalListString OptionalReference PARSEOP_CLOSE_PAREN",
"LoadTableTerm : PARSEOP_LOADTABLE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$59 :",
"LoadTerm : PARSEOP_LOAD PARSEOP_OPEN_PAREN $$59 NameString RequiredTarget PARSEOP_CLOSE_PAREN",
"LoadTerm : PARSEOP_LOAD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"LocalTerm : PARSEOP_LOCAL0",
"LocalTerm : PARSEOP_LOCAL1",
"LocalTerm : PARSEOP_LOCAL2",
"LocalTerm : PARSEOP_LOCAL3",
"LocalTerm : PARSEOP_LOCAL4",
"LocalTerm : PARSEOP_LOCAL5",
"LocalTerm : PARSEOP_LOCAL6",
"LocalTerm : PARSEOP_LOCAL7",
"$$60 :",
"LOrTerm : PARSEOP_LOR PARSEOP_OPEN_PAREN $$60 TermArg TermArgItem PARSEOP_CLOSE_PAREN",
"LOrTerm : PARSEOP_LOR PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$61 :",
"MatchTerm : PARSEOP_MATCH PARSEOP_OPEN_PAREN $$61 TermArg ',' MatchOpKeyword TermArgItem ',' MatchOpKeyword TermArgItem TermArgItem PARSEOP_CLOSE_PAREN",
"MatchTerm : PARSEOP_MATCH PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$62 :",
"$$63 :",
"$$64 :",
"MethodTerm : PARSEOP_METHOD PARSEOP_OPEN_PAREN $$62 NameString OptionalByteConstExpr $$63 OptionalSerializeRuleKeyword OptionalByteConstExpr OptionalParameterTypePackage OptionalParameterTypesPackage PARSEOP_CLOSE_PAREN '{' $$64 TermList '}'",
"MethodTerm : PARSEOP_METHOD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$65 :",
"MidTerm : PARSEOP_MID PARSEOP_OPEN_PAREN $$65 TermArg TermArgItem TermArgItem Target PARSEOP_CLOSE_PAREN",
"MidTerm : PARSEOP_MID PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$66 :",
"ModTerm : PARSEOP_MOD PARSEOP_OPEN_PAREN $$66 TermArg TermArgItem Target PARSEOP_CLOSE_PAREN",
"ModTerm : PARSEOP_MOD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$67 :",
"MultiplyTerm : PARSEOP_MULTIPLY PARSEOP_OPEN_PAREN $$67 TermArg TermArgItem Target PARSEOP_CLOSE_PAREN",
"MultiplyTerm : PARSEOP_MULTIPLY PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$68 :",
"MutexTerm : PARSEOP_MUTEX PARSEOP_OPEN_PAREN $$68 NameString ',' ByteConstExpr PARSEOP_CLOSE_PAREN",
"MutexTerm : PARSEOP_MUTEX PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$69 :",
"NameTerm : PARSEOP_NAME PARSEOP_OPEN_PAREN $$69 NameString ',' DataObject PARSEOP_CLOSE_PAREN",
"NameTerm : PARSEOP_NAME PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$70 :",
"NAndTerm : PARSEOP_NAND PARSEOP_OPEN_PAREN $$70 TermArg TermArgItem Target PARSEOP_CLOSE_PAREN",
"NAndTerm : PARSEOP_NAND PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"NoOpTerm : PARSEOP_NOOP",
"$$71 :",
"NOrTerm : PARSEOP_NOR PARSEOP_OPEN_PAREN $$71 TermArg TermArgItem Target PARSEOP_CLOSE_PAREN",
"NOrTerm : PARSEOP_NOR PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$72 :",
"NotifyTerm : PARSEOP_NOTIFY PARSEOP_OPEN_PAREN $$72 SuperName TermArgItem PARSEOP_CLOSE_PAREN",
"NotifyTerm : PARSEOP_NOTIFY PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$73 :",
"NotTerm : PARSEOP_NOT PARSEOP_OPEN_PAREN $$73 TermArg Target PARSEOP_CLOSE_PAREN",
"NotTerm : PARSEOP_NOT PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$74 :",
"ObjectTypeTerm : PARSEOP_OBJECTTYPE PARSEOP_OPEN_PAREN $$74 ObjectTypeSource PARSEOP_CLOSE_PAREN",
"ObjectTypeTerm : PARSEOP_OBJECTTYPE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"OffsetTerm : PARSEOP_OFFSET PARSEOP_OPEN_PAREN AmlPackageLengthTerm PARSEOP_CLOSE_PAREN",
"OffsetTerm : PARSEOP_OFFSET PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$75 :",
"OpRegionTerm : PARSEOP_OPERATIONREGION PARSEOP_OPEN_PAREN $$75 NameString ',' OpRegionSpaceIdTerm TermArgItem TermArgItem PARSEOP_CLOSE_PAREN",
"OpRegionTerm : PARSEOP_OPERATIONREGION PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"OpRegionSpaceIdTerm : RegionSpaceKeyword",
"OpRegionSpaceIdTerm : ByteConst",
"$$76 :",
"OrTerm : PARSEOP_OR PARSEOP_OPEN_PAREN $$76 TermArg TermArgItem Target PARSEOP_CLOSE_PAREN",
"OrTerm : PARSEOP_OR PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$77 :",
"PackageTerm : PARSEOP_PACKAGE $$77 OptionalDataCount '{' PackageList '}'",
"$$78 :",
"PowerResTerm : PARSEOP_POWERRESOURCE PARSEOP_OPEN_PAREN $$78 NameString ',' ByteConstExpr ',' WordConstExpr PARSEOP_CLOSE_PAREN '{' TermList '}'",
"PowerResTerm : PARSEOP_POWERRESOURCE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$79 :",
"PrintfTerm : PARSEOP_PRINTF PARSEOP_OPEN_PAREN $$79 StringData PrintfArgList PARSEOP_CLOSE_PAREN",
"PrintfTerm : PARSEOP_PRINTF PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"PrintfArgList :",
"PrintfArgList : TermArg",
"PrintfArgList : PrintfArgList ',' TermArg",
"$$80 :",
"ProcessorTerm : PARSEOP_PROCESSOR PARSEOP_OPEN_PAREN $$80 NameString ',' ByteConstExpr OptionalDWordConstExpr OptionalByteConstExpr PARSEOP_CLOSE_PAREN '{' TermList '}'",
"ProcessorTerm : PARSEOP_PROCESSOR PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$81 :",
"RawDataBufferTerm : PARSEOP_DATABUFFER PARSEOP_OPEN_PAREN $$81 OptionalWordConst PARSEOP_CLOSE_PAREN '{' ByteList '}'",
"RawDataBufferTerm : PARSEOP_DATABUFFER PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$82 :",
"RefOfTerm : PARSEOP_REFOF PARSEOP_OPEN_PAREN $$82 RefOfSource PARSEOP_CLOSE_PAREN",
"RefOfTerm : PARSEOP_REFOF PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$83 :",
"ReleaseTerm : PARSEOP_RELEASE PARSEOP_OPEN_PAREN $$83 SuperName PARSEOP_CLOSE_PAREN",
"ReleaseTerm : PARSEOP_RELEASE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$84 :",
"ResetTerm : PARSEOP_RESET PARSEOP_OPEN_PAREN $$84 SuperName PARSEOP_CLOSE_PAREN",
"ResetTerm : PARSEOP_RESET PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$85 :",
"ReturnTerm : PARSEOP_RETURN PARSEOP_OPEN_PAREN $$85 OptionalReturnArg PARSEOP_CLOSE_PAREN",
"ReturnTerm : PARSEOP_RETURN",
"ReturnTerm : PARSEOP_RETURN PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$86 :",
"ScopeTerm : PARSEOP_SCOPE PARSEOP_OPEN_PAREN $$86 NameString PARSEOP_CLOSE_PAREN '{' TermList '}'",
"ScopeTerm : PARSEOP_SCOPE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$87 :",
"ShiftLeftTerm : PARSEOP_SHIFTLEFT PARSEOP_OPEN_PAREN $$87 TermArg TermArgItem Target PARSEOP_CLOSE_PAREN",
"ShiftLeftTerm : PARSEOP_SHIFTLEFT PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$88 :",
"ShiftRightTerm : PARSEOP_SHIFTRIGHT PARSEOP_OPEN_PAREN $$88 TermArg TermArgItem Target PARSEOP_CLOSE_PAREN",
"ShiftRightTerm : PARSEOP_SHIFTRIGHT PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$89 :",
"SignalTerm : PARSEOP_SIGNAL PARSEOP_OPEN_PAREN $$89 SuperName PARSEOP_CLOSE_PAREN",
"SignalTerm : PARSEOP_SIGNAL PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$90 :",
"SizeOfTerm : PARSEOP_SIZEOF PARSEOP_OPEN_PAREN $$90 SuperName PARSEOP_CLOSE_PAREN",
"SizeOfTerm : PARSEOP_SIZEOF PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$91 :",
"SleepTerm : PARSEOP_SLEEP PARSEOP_OPEN_PAREN $$91 TermArg PARSEOP_CLOSE_PAREN",
"SleepTerm : PARSEOP_SLEEP PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$92 :",
"StallTerm : PARSEOP_STALL PARSEOP_OPEN_PAREN $$92 TermArg PARSEOP_CLOSE_PAREN",
"StallTerm : PARSEOP_STALL PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$93 :",
"StoreTerm : PARSEOP_STORE PARSEOP_OPEN_PAREN $$93 TermArg ',' SuperName PARSEOP_CLOSE_PAREN",
"StoreTerm : PARSEOP_STORE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$94 :",
"SubtractTerm : PARSEOP_SUBTRACT PARSEOP_OPEN_PAREN $$94 TermArg TermArgItem Target PARSEOP_CLOSE_PAREN",
"SubtractTerm : PARSEOP_SUBTRACT PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$95 :",
"SwitchTerm : PARSEOP_SWITCH PARSEOP_OPEN_PAREN $$95 TermArg PARSEOP_CLOSE_PAREN '{' CaseDefaultTermList '}'",
"SwitchTerm : PARSEOP_SWITCH PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$96 :",
"ThermalZoneTerm : PARSEOP_THERMALZONE PARSEOP_OPEN_PAREN $$96 NameString PARSEOP_CLOSE_PAREN '{' TermList '}'",
"ThermalZoneTerm : PARSEOP_THERMALZONE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$97 :",
"TimerTerm : PARSEOP_TIMER PARSEOP_OPEN_PAREN $$97 PARSEOP_CLOSE_PAREN",
"TimerTerm : PARSEOP_TIMER",
"TimerTerm : PARSEOP_TIMER PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$98 :",
"ToBCDTerm : PARSEOP_TOBCD PARSEOP_OPEN_PAREN $$98 TermArg Target PARSEOP_CLOSE_PAREN",
"ToBCDTerm : PARSEOP_TOBCD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$99 :",
"ToBufferTerm : PARSEOP_TOBUFFER PARSEOP_OPEN_PAREN $$99 TermArg Target PARSEOP_CLOSE_PAREN",
"ToBufferTerm : PARSEOP_TOBUFFER PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$100 :",
"ToDecimalStringTerm : PARSEOP_TODECIMALSTRING PARSEOP_OPEN_PAREN $$100 TermArg Target PARSEOP_CLOSE_PAREN",
"ToDecimalStringTerm : PARSEOP_TODECIMALSTRING PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$101 :",
"ToHexStringTerm : PARSEOP_TOHEXSTRING PARSEOP_OPEN_PAREN $$101 TermArg Target PARSEOP_CLOSE_PAREN",
"ToHexStringTerm : PARSEOP_TOHEXSTRING PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$102 :",
"ToIntegerTerm : PARSEOP_TOINTEGER PARSEOP_OPEN_PAREN $$102 TermArg Target PARSEOP_CLOSE_PAREN",
"ToIntegerTerm : PARSEOP_TOINTEGER PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$103 :",
"ToPLDTerm : PARSEOP_TOPLD PARSEOP_OPEN_PAREN $$103 PldKeywordList PARSEOP_CLOSE_PAREN",
"ToPLDTerm : PARSEOP_TOPLD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"PldKeywordList :",
"PldKeywordList : PldKeyword PARSEOP_EXP_EQUALS Integer",
"PldKeywordList : PldKeyword PARSEOP_EXP_EQUALS String",
"PldKeywordList : PldKeywordList ','",
"PldKeywordList : PldKeywordList ',' PldKeyword PARSEOP_EXP_EQUALS Integer",
"PldKeywordList : PldKeywordList ',' PldKeyword PARSEOP_EXP_EQUALS String",
"$$104 :",
"ToStringTerm : PARSEOP_TOSTRING PARSEOP_OPEN_PAREN $$104 TermArg OptionalCount Target PARSEOP_CLOSE_PAREN",
"ToStringTerm : PARSEOP_TOSTRING PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"ToUUIDTerm : PARSEOP_TOUUID PARSEOP_OPEN_PAREN StringData PARSEOP_CLOSE_PAREN",
"ToUUIDTerm : PARSEOP_TOUUID PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$105 :",
"UnicodeTerm : PARSEOP_UNICODE PARSEOP_OPEN_PAREN $$105 StringData PARSEOP_CLOSE_PAREN",
"UnicodeTerm : PARSEOP_UNICODE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$106 :",
"UnloadTerm : PARSEOP_UNLOAD PARSEOP_OPEN_PAREN $$106 SuperName PARSEOP_CLOSE_PAREN",
"UnloadTerm : PARSEOP_UNLOAD PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$107 :",
"WaitTerm : PARSEOP_WAIT PARSEOP_OPEN_PAREN $$107 SuperName TermArgItem PARSEOP_CLOSE_PAREN",
"WaitTerm : PARSEOP_WAIT PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$108 :",
"XOrTerm : PARSEOP_XOR PARSEOP_OPEN_PAREN $$108 TermArg TermArgItem Target PARSEOP_CLOSE_PAREN",
"XOrTerm : PARSEOP_XOR PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$109 :",
"WhileTerm : PARSEOP_WHILE PARSEOP_OPEN_PAREN $$109 TermArg PARSEOP_CLOSE_PAREN '{' TermList '}'",
"WhileTerm : PARSEOP_WHILE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$110 :",
"Expression : PARSEOP_EXP_LOGICAL_NOT $$110 TermArg",
"$$111 :",
"Expression : PARSEOP_EXP_NOT $$111 TermArg",
"$$112 :",
"Expression : SuperName PARSEOP_EXP_INCREMENT $$112",
"$$113 :",
"Expression : SuperName PARSEOP_EXP_DECREMENT $$113",
"$$114 :",
"Expression : TermArg PARSEOP_EXP_ADD $$114 TermArg",
"$$115 :",
"Expression : TermArg PARSEOP_EXP_DIVIDE $$115 TermArg",
"$$116 :",
"Expression : TermArg PARSEOP_EXP_MODULO $$116 TermArg",
"$$117 :",
"Expression : TermArg PARSEOP_EXP_MULTIPLY $$117 TermArg",
"$$118 :",
"Expression : TermArg PARSEOP_EXP_SHIFT_LEFT $$118 TermArg",
"$$119 :",
"Expression : TermArg PARSEOP_EXP_SHIFT_RIGHT $$119 TermArg",
"$$120 :",
"Expression : TermArg PARSEOP_EXP_SUBTRACT $$120 TermArg",
"$$121 :",
"Expression : TermArg PARSEOP_EXP_AND $$121 TermArg",
"$$122 :",
"Expression : TermArg PARSEOP_EXP_OR $$122 TermArg",
"$$123 :",
"Expression : TermArg PARSEOP_EXP_XOR $$123 TermArg",
"$$124 :",
"Expression : TermArg PARSEOP_EXP_GREATER $$124 TermArg",
"$$125 :",
"Expression : TermArg PARSEOP_EXP_GREATER_EQUAL $$125 TermArg",
"$$126 :",
"Expression : TermArg PARSEOP_EXP_LESS $$126 TermArg",
"$$127 :",
"Expression : TermArg PARSEOP_EXP_LESS_EQUAL $$127 TermArg",
"$$128 :",
"Expression : TermArg PARSEOP_EXP_EQUAL $$128 TermArg",
"$$129 :",
"Expression : TermArg PARSEOP_EXP_NOT_EQUAL $$129 TermArg",
"$$130 :",
"Expression : TermArg PARSEOP_EXP_LOGICAL_AND $$130 TermArg",
"$$131 :",
"Expression : TermArg PARSEOP_EXP_LOGICAL_OR $$131 TermArg",
"Expression : PARSEOP_OPEN_PAREN Expression PARSEOP_CLOSE_PAREN",
"Expression : IndexExpTerm",
"IndexExpTerm : SuperName PARSEOP_EXP_INDEX_LEFT TermArg PARSEOP_EXP_INDEX_RIGHT",
"EqualsTerm : PARSEOP_OPEN_PAREN EqualsTerm PARSEOP_CLOSE_PAREN",
"EqualsTerm : SuperName PARSEOP_EXP_EQUALS TermArg",
"EqualsTerm : PARSEOP_OPEN_PAREN EqualsTerm PARSEOP_CLOSE_PAREN PARSEOP_EXP_EQUALS TermArg",
"$$132 :",
"EqualsTerm : TermArg PARSEOP_EXP_ADD_EQ $$132 TermArg",
"$$133 :",
"EqualsTerm : TermArg PARSEOP_EXP_DIV_EQ $$133 TermArg",
"$$134 :",
"EqualsTerm : TermArg PARSEOP_EXP_MOD_EQ $$134 TermArg",
"$$135 :",
"EqualsTerm : TermArg PARSEOP_EXP_MUL_EQ $$135 TermArg",
"$$136 :",
"EqualsTerm : TermArg PARSEOP_EXP_SHL_EQ $$136 TermArg",
"$$137 :",
"EqualsTerm : TermArg PARSEOP_EXP_SHR_EQ $$137 TermArg",
"$$138 :",
"EqualsTerm : TermArg PARSEOP_EXP_SUB_EQ $$138 TermArg",
"$$139 :",
"EqualsTerm : TermArg PARSEOP_EXP_AND_EQ $$139 TermArg",
"$$140 :",
"EqualsTerm : TermArg PARSEOP_EXP_OR_EQ $$140 TermArg",
"$$141 :",
"EqualsTerm : TermArg PARSEOP_EXP_XOR_EQ $$141 TermArg",
"AccessAttribKeyword : PARSEOP_ACCESSATTRIB_BLOCK",
"AccessAttribKeyword : PARSEOP_ACCESSATTRIB_BLOCK_CALL",
"AccessAttribKeyword : PARSEOP_ACCESSATTRIB_BYTE",
"AccessAttribKeyword : PARSEOP_ACCESSATTRIB_QUICK",
"AccessAttribKeyword : PARSEOP_ACCESSATTRIB_SND_RCV",
"AccessAttribKeyword : PARSEOP_ACCESSATTRIB_WORD",
"AccessAttribKeyword : PARSEOP_ACCESSATTRIB_WORD_CALL",
"$$142 :",
"AccessAttribKeyword : PARSEOP_ACCESSATTRIB_MULTIBYTE PARSEOP_OPEN_PAREN $$142 ByteConst PARSEOP_CLOSE_PAREN",
"$$143 :",
"AccessAttribKeyword : PARSEOP_ACCESSATTRIB_RAW_BYTES PARSEOP_OPEN_PAREN $$143 ByteConst PARSEOP_CLOSE_PAREN",
"$$144 :",
"AccessAttribKeyword : PARSEOP_ACCESSATTRIB_RAW_PROCESS PARSEOP_OPEN_PAREN $$144 ByteConst PARSEOP_CLOSE_PAREN",
"AccessTypeKeyword : PARSEOP_ACCESSTYPE_ANY",
"AccessTypeKeyword : PARSEOP_ACCESSTYPE_BYTE",
"AccessTypeKeyword : PARSEOP_ACCESSTYPE_WORD",
"AccessTypeKeyword : PARSEOP_ACCESSTYPE_DWORD",
"AccessTypeKeyword : PARSEOP_ACCESSTYPE_QWORD",
"AccessTypeKeyword : PARSEOP_ACCESSTYPE_BUF",
"AddressingModeKeyword : PARSEOP_ADDRESSINGMODE_7BIT",
"AddressingModeKeyword : PARSEOP_ADDRESSINGMODE_10BIT",
"AddressKeyword : PARSEOP_ADDRESSTYPE_MEMORY",
"AddressKeyword : PARSEOP_ADDRESSTYPE_RESERVED",
"AddressKeyword : PARSEOP_ADDRESSTYPE_NVS",
"AddressKeyword : PARSEOP_ADDRESSTYPE_ACPI",
"AddressSpaceKeyword : ByteConst",
"AddressSpaceKeyword : RegionSpaceKeyword",
"BitsPerByteKeyword : PARSEOP_BITSPERBYTE_FIVE",
"BitsPerByteKeyword : PARSEOP_BITSPERBYTE_SIX",
"BitsPerByteKeyword : PARSEOP_BITSPERBYTE_SEVEN",
"BitsPerByteKeyword : PARSEOP_BITSPERBYTE_EIGHT",
"BitsPerByteKeyword : PARSEOP_BITSPERBYTE_NINE",
"ClockPhaseKeyword : PARSEOP_CLOCKPHASE_FIRST",
"ClockPhaseKeyword : PARSEOP_CLOCKPHASE_SECOND",
"ClockPolarityKeyword : PARSEOP_CLOCKPOLARITY_LOW",
"ClockPolarityKeyword : PARSEOP_CLOCKPOLARITY_HIGH",
"DecodeKeyword : PARSEOP_DECODETYPE_POS",
"DecodeKeyword : PARSEOP_DECODETYPE_SUB",
"DevicePolarityKeyword : PARSEOP_DEVICEPOLARITY_LOW",
"DevicePolarityKeyword : PARSEOP_DEVICEPOLARITY_HIGH",
"DMATypeKeyword : PARSEOP_DMATYPE_A",
"DMATypeKeyword : PARSEOP_DMATYPE_COMPATIBILITY",
"DMATypeKeyword : PARSEOP_DMATYPE_B",
"DMATypeKeyword : PARSEOP_DMATYPE_F",
"EndianKeyword : PARSEOP_ENDIAN_LITTLE",
"EndianKeyword : PARSEOP_ENDIAN_BIG",
"FlowControlKeyword : PARSEOP_FLOWCONTROL_HW",
"FlowControlKeyword : PARSEOP_FLOWCONTROL_NONE",
"FlowControlKeyword : PARSEOP_FLOWCONTROL_SW",
"InterruptLevel : PARSEOP_INTLEVEL_ACTIVEBOTH",
"InterruptLevel : PARSEOP_INTLEVEL_ACTIVEHIGH",
"InterruptLevel : PARSEOP_INTLEVEL_ACTIVELOW",
"InterruptTypeKeyword : PARSEOP_INTTYPE_EDGE",
"InterruptTypeKeyword : PARSEOP_INTTYPE_LEVEL",
"IODecodeKeyword : PARSEOP_IODECODETYPE_16",
"IODecodeKeyword : PARSEOP_IODECODETYPE_10",
"IoRestrictionKeyword : PARSEOP_IORESTRICT_IN",
"IoRestrictionKeyword : PARSEOP_IORESTRICT_OUT",
"IoRestrictionKeyword : PARSEOP_IORESTRICT_NONE",
"IoRestrictionKeyword : PARSEOP_IORESTRICT_PRESERVE",
"LockRuleKeyword : PARSEOP_LOCKRULE_LOCK",
"LockRuleKeyword : PARSEOP_LOCKRULE_NOLOCK",
"MatchOpKeyword : PARSEOP_MATCHTYPE_MTR",
"MatchOpKeyword : PARSEOP_MATCHTYPE_MEQ",
"MatchOpKeyword : PARSEOP_MATCHTYPE_MLE",
"MatchOpKeyword : PARSEOP_MATCHTYPE_MLT",
"MatchOpKeyword : PARSEOP_MATCHTYPE_MGE",
"MatchOpKeyword : PARSEOP_MATCHTYPE_MGT",
"MaxKeyword : PARSEOP_MAXTYPE_FIXED",
"MaxKeyword : PARSEOP_MAXTYPE_NOTFIXED",
"MemTypeKeyword : PARSEOP_MEMTYPE_CACHEABLE",
"MemTypeKeyword : PARSEOP_MEMTYPE_WRITECOMBINING",
"MemTypeKeyword : PARSEOP_MEMTYPE_PREFETCHABLE",
"MemTypeKeyword : PARSEOP_MEMTYPE_NONCACHEABLE",
"MinKeyword : PARSEOP_MINTYPE_FIXED",
"MinKeyword : PARSEOP_MINTYPE_NOTFIXED",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_UNK",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_INT",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_STR",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_BUF",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_PKG",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_FLD",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_DEV",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_EVT",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_MTH",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_MTX",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_OPR",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_POW",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_PRO",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_THZ",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_BFF",
"ObjectTypeKeyword : PARSEOP_OBJECTTYPE_DDB",
"ParityTypeKeyword : PARSEOP_PARITYTYPE_SPACE",
"ParityTypeKeyword : PARSEOP_PARITYTYPE_MARK",
"ParityTypeKeyword : PARSEOP_PARITYTYPE_ODD",
"ParityTypeKeyword : PARSEOP_PARITYTYPE_EVEN",
"ParityTypeKeyword : PARSEOP_PARITYTYPE_NONE",
"PinConfigByte : PinConfigKeyword",
"PinConfigByte : ByteConstExpr",
"PinConfigKeyword : PARSEOP_PIN_NOPULL",
"PinConfigKeyword : PARSEOP_PIN_PULLDOWN",
"PinConfigKeyword : PARSEOP_PIN_PULLUP",
"PinConfigKeyword : PARSEOP_PIN_PULLDEFAULT",
"PldKeyword : PARSEOP_PLD_REVISION",
"PldKeyword : PARSEOP_PLD_IGNORECOLOR",
"PldKeyword : PARSEOP_PLD_RED",
"PldKeyword : PARSEOP_PLD_GREEN",
"PldKeyword : PARSEOP_PLD_BLUE",
"PldKeyword : PARSEOP_PLD_WIDTH",
"PldKeyword : PARSEOP_PLD_HEIGHT",
"PldKeyword : PARSEOP_PLD_USERVISIBLE",
"PldKeyword : PARSEOP_PLD_DOCK",
"PldKeyword : PARSEOP_PLD_LID",
"PldKeyword : PARSEOP_PLD_PANEL",
"PldKeyword : PARSEOP_PLD_VERTICALPOSITION",
"PldKeyword : PARSEOP_PLD_HORIZONTALPOSITION",
"PldKeyword : PARSEOP_PLD_SHAPE",
"PldKeyword : PARSEOP_PLD_GROUPORIENTATION",
"PldKeyword : PARSEOP_PLD_GROUPTOKEN",
"PldKeyword : PARSEOP_PLD_GROUPPOSITION",
"PldKeyword : PARSEOP_PLD_BAY",
"PldKeyword : PARSEOP_PLD_EJECTABLE",
"PldKeyword : PARSEOP_PLD_EJECTREQUIRED",
"PldKeyword : PARSEOP_PLD_CABINETNUMBER",
"PldKeyword : PARSEOP_PLD_CARDCAGENUMBER",
"PldKeyword : PARSEOP_PLD_REFERENCE",
"PldKeyword : PARSEOP_PLD_ROTATION",
"PldKeyword : PARSEOP_PLD_ORDER",
"PldKeyword : PARSEOP_PLD_RESERVED",
"PldKeyword : PARSEOP_PLD_VERTICALOFFSET",
"PldKeyword : PARSEOP_PLD_HORIZONTALOFFSET",
"RangeTypeKeyword : PARSEOP_RANGETYPE_ISAONLY",
"RangeTypeKeyword : PARSEOP_RANGETYPE_NONISAONLY",
"RangeTypeKeyword : PARSEOP_RANGETYPE_ENTIRE",
"RegionSpaceKeyword : PARSEOP_REGIONSPACE_IO",
"RegionSpaceKeyword : PARSEOP_REGIONSPACE_MEM",
"RegionSpaceKeyword : PARSEOP_REGIONSPACE_PCI",
"RegionSpaceKeyword : PARSEOP_REGIONSPACE_EC",
"RegionSpaceKeyword : PARSEOP_REGIONSPACE_SMBUS",
"RegionSpaceKeyword : PARSEOP_REGIONSPACE_CMOS",
"RegionSpaceKeyword : PARSEOP_REGIONSPACE_PCIBAR",
"RegionSpaceKeyword : PARSEOP_REGIONSPACE_IPMI",
"RegionSpaceKeyword : PARSEOP_REGIONSPACE_GPIO",
"RegionSpaceKeyword : PARSEOP_REGIONSPACE_GSBUS",
"RegionSpaceKeyword : PARSEOP_REGIONSPACE_PCC",
"RegionSpaceKeyword : PARSEOP_REGIONSPACE_FFIXEDHW",
"ResourceTypeKeyword : PARSEOP_RESOURCETYPE_CONSUMER",
"ResourceTypeKeyword : PARSEOP_RESOURCETYPE_PRODUCER",
"SerializeRuleKeyword : PARSEOP_SERIALIZERULE_SERIAL",
"SerializeRuleKeyword : PARSEOP_SERIALIZERULE_NOTSERIAL",
"ShareTypeKeyword : PARSEOP_SHARETYPE_SHARED",
"ShareTypeKeyword : PARSEOP_SHARETYPE_EXCLUSIVE",
"ShareTypeKeyword : PARSEOP_SHARETYPE_SHAREDWAKE",
"ShareTypeKeyword : PARSEOP_SHARETYPE_EXCLUSIVEWAKE",
"SlaveModeKeyword : PARSEOP_SLAVEMODE_CONTROLLERINIT",
"SlaveModeKeyword : PARSEOP_SLAVEMODE_DEVICEINIT",
"StopBitsKeyword : PARSEOP_STOPBITS_TWO",
"StopBitsKeyword : PARSEOP_STOPBITS_ONEPLUSHALF",
"StopBitsKeyword : PARSEOP_STOPBITS_ONE",
"StopBitsKeyword : PARSEOP_STOPBITS_ZERO",
"TranslationKeyword : PARSEOP_TRANSLATIONTYPE_SPARSE",
"TranslationKeyword : PARSEOP_TRANSLATIONTYPE_DENSE",
"TypeKeyword : PARSEOP_TYPE_TRANSLATION",
"TypeKeyword : PARSEOP_TYPE_STATIC",
"UpdateRuleKeyword : PARSEOP_UPDATERULE_PRESERVE",
"UpdateRuleKeyword : PARSEOP_UPDATERULE_ONES",
"UpdateRuleKeyword : PARSEOP_UPDATERULE_ZEROS",
"WireModeKeyword : PARSEOP_WIREMODE_FOUR",
"WireModeKeyword : PARSEOP_WIREMODE_THREE",
"XferSizeKeyword : PARSEOP_XFERSIZE_8",
"XferSizeKeyword : PARSEOP_XFERSIZE_16",
"XferSizeKeyword : PARSEOP_XFERSIZE_32",
"XferSizeKeyword : PARSEOP_XFERSIZE_64",
"XferSizeKeyword : PARSEOP_XFERSIZE_128",
"XferSizeKeyword : PARSEOP_XFERSIZE_256",
"XferTypeKeyword : PARSEOP_XFERTYPE_8",
"XferTypeKeyword : PARSEOP_XFERTYPE_8_16",
"XferTypeKeyword : PARSEOP_XFERTYPE_16",
"$$145 :",
"ResourceTemplateTerm : PARSEOP_RESOURCETEMPLATE $$145 OptionalParentheses '{' ResourceMacroList '}'",
"OptionalParentheses :",
"OptionalParentheses : PARSEOP_OPEN_PAREN PARSEOP_CLOSE_PAREN",
"ResourceMacroList :",
"ResourceMacroList : ResourceMacroList ResourceMacroTerm",
"ResourceMacroTerm : DMATerm",
"ResourceMacroTerm : DWordIOTerm",
"ResourceMacroTerm : DWordMemoryTerm",
"ResourceMacroTerm : DWordSpaceTerm",
"ResourceMacroTerm : EndDependentFnTerm",
"ResourceMacroTerm : ExtendedIOTerm",
"ResourceMacroTerm : ExtendedMemoryTerm",
"ResourceMacroTerm : ExtendedSpaceTerm",
"ResourceMacroTerm : FixedDmaTerm",
"ResourceMacroTerm : FixedIOTerm",
"ResourceMacroTerm : GpioIntTerm",
"ResourceMacroTerm : GpioIoTerm",
"ResourceMacroTerm : I2cSerialBusTerm",
"ResourceMacroTerm : I2cSerialBusTermV2",
"ResourceMacroTerm : InterruptTerm",
"ResourceMacroTerm : IOTerm",
"ResourceMacroTerm : IRQNoFlagsTerm",
"ResourceMacroTerm : IRQTerm",
"ResourceMacroTerm : Memory24Term",
"ResourceMacroTerm : Memory32FixedTerm",
"ResourceMacroTerm : Memory32Term",
"ResourceMacroTerm : PinConfigTerm",
"ResourceMacroTerm : PinFunctionTerm",
"ResourceMacroTerm : PinGroupTerm",
"ResourceMacroTerm : PinGroupConfigTerm",
"ResourceMacroTerm : PinGroupFunctionTerm",
"ResourceMacroTerm : QWordIOTerm",
"ResourceMacroTerm : QWordMemoryTerm",
"ResourceMacroTerm : QWordSpaceTerm",
"ResourceMacroTerm : RegisterTerm",
"ResourceMacroTerm : SpiSerialBusTerm",
"ResourceMacroTerm : SpiSerialBusTermV2",
"ResourceMacroTerm : StartDependentFnNoPriTerm",
"ResourceMacroTerm : StartDependentFnTerm",
"ResourceMacroTerm : UartSerialBusTerm",
"ResourceMacroTerm : UartSerialBusTermV2",
"ResourceMacroTerm : VendorLongTerm",
"ResourceMacroTerm : VendorShortTerm",
"ResourceMacroTerm : WordBusNumberTerm",
"ResourceMacroTerm : WordIOTerm",
"ResourceMacroTerm : WordSpaceTerm",
"$$146 :",
"DMATerm : PARSEOP_DMA PARSEOP_OPEN_PAREN $$146 DMATypeKeyword OptionalBusMasterKeyword ',' XferTypeKeyword OptionalNameString_Last PARSEOP_CLOSE_PAREN '{' ByteList '}'",
"DMATerm : PARSEOP_DMA PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$147 :",
"DWordIOTerm : PARSEOP_DWORDIO PARSEOP_OPEN_PAREN $$147 OptionalResourceType_First OptionalMinType OptionalMaxType OptionalDecodeType OptionalRangeType ',' DWordConstExpr ',' DWordConstExpr ',' DWordConstExpr ',' DWordConstExpr ',' DWordConstExpr OptionalByteConstExpr OptionalStringData OptionalNameString OptionalType OptionalTranslationType_Last PARSEOP_CLOSE_PAREN",
"DWordIOTerm : PARSEOP_DWORDIO PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$148 :",
"DWordMemoryTerm : PARSEOP_DWORDMEMORY PARSEOP_OPEN_PAREN $$148 OptionalResourceType_First OptionalDecodeType OptionalMinType OptionalMaxType OptionalMemType ',' OptionalReadWriteKeyword ',' DWordConstExpr ',' DWordConstExpr ',' DWordConstExpr ',' DWordConstExpr ',' DWordConstExpr OptionalByteConstExpr OptionalStringData OptionalNameString OptionalAddressRange OptionalType_Last PARSEOP_CLOSE_PAREN",
"DWordMemoryTerm : PARSEOP_DWORDMEMORY PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$149 :",
"$$150 :",
"DWordSpaceTerm : PARSEOP_DWORDSPACE PARSEOP_OPEN_PAREN $$149 ByteConstExpr $$150 OptionalResourceType OptionalDecodeType OptionalMinType OptionalMaxType ',' ByteConstExpr ',' DWordConstExpr ',' DWordConstExpr ',' DWordConstExpr ',' DWordConstExpr ',' DWordConstExpr OptionalByteConstExpr OptionalStringData OptionalNameString_Last PARSEOP_CLOSE_PAREN",
"DWordSpaceTerm : PARSEOP_DWORDSPACE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"EndDependentFnTerm : PARSEOP_ENDDEPENDENTFN PARSEOP_OPEN_PAREN PARSEOP_CLOSE_PAREN",
"EndDependentFnTerm : PARSEOP_ENDDEPENDENTFN PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$151 :",
"ExtendedIOTerm : PARSEOP_EXTENDEDIO PARSEOP_OPEN_PAREN $$151 OptionalResourceType_First OptionalMinType OptionalMaxType OptionalDecodeType OptionalRangeType ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr OptionalQWordConstExpr OptionalNameString OptionalType OptionalTranslationType_Last PARSEOP_CLOSE_PAREN",
"ExtendedIOTerm : PARSEOP_EXTENDEDIO PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$152 :",
"ExtendedMemoryTerm : PARSEOP_EXTENDEDMEMORY PARSEOP_OPEN_PAREN $$152 OptionalResourceType_First OptionalDecodeType OptionalMinType OptionalMaxType OptionalMemType ',' OptionalReadWriteKeyword ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr OptionalQWordConstExpr OptionalNameString OptionalAddressRange OptionalType_Last PARSEOP_CLOSE_PAREN",
"ExtendedMemoryTerm : PARSEOP_EXTENDEDMEMORY PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$153 :",
"$$154 :",
"ExtendedSpaceTerm : PARSEOP_EXTENDEDSPACE PARSEOP_OPEN_PAREN $$153 ByteConstExpr $$154 OptionalResourceType OptionalDecodeType OptionalMinType OptionalMaxType ',' ByteConstExpr ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr OptionalQWordConstExpr OptionalNameString_Last PARSEOP_CLOSE_PAREN",
"ExtendedSpaceTerm : PARSEOP_EXTENDEDSPACE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$155 :",
"FixedDmaTerm : PARSEOP_FIXEDDMA PARSEOP_OPEN_PAREN $$155 WordConstExpr ',' WordConstExpr OptionalXferSize OptionalNameString PARSEOP_CLOSE_PAREN",
"FixedDmaTerm : PARSEOP_FIXEDDMA PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$156 :",
"FixedIOTerm : PARSEOP_FIXEDIO PARSEOP_OPEN_PAREN $$156 WordConstExpr ',' ByteConstExpr OptionalNameString_Last PARSEOP_CLOSE_PAREN",
"FixedIOTerm : PARSEOP_FIXEDIO PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$157 :",
"GpioIntTerm : PARSEOP_GPIO_INT PARSEOP_OPEN_PAREN $$157 InterruptTypeKeyword ',' InterruptLevel OptionalShareType ',' PinConfigByte OptionalWordConstExpr ',' StringData OptionalByteConstExpr OptionalResourceType OptionalNameString OptionalBuffer_Last PARSEOP_CLOSE_PAREN '{' DWordConstExpr '}'",
"GpioIntTerm : PARSEOP_GPIO_INT PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$158 :",
"GpioIoTerm : PARSEOP_GPIO_IO PARSEOP_OPEN_PAREN $$158 OptionalShareType_First ',' PinConfigByte OptionalWordConstExpr OptionalWordConstExpr OptionalIoRestriction ',' StringData OptionalByteConstExpr OptionalResourceType OptionalNameString OptionalBuffer_Last PARSEOP_CLOSE_PAREN '{' DWordList '}'",
"GpioIoTerm : PARSEOP_GPIO_IO PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$159 :",
"I2cSerialBusTerm : PARSEOP_I2C_SERIALBUS PARSEOP_OPEN_PAREN $$159 WordConstExpr OptionalSlaveMode ',' DWordConstExpr OptionalAddressingMode ',' StringData OptionalByteConstExpr OptionalResourceType OptionalNameString OptionalBuffer_Last PARSEOP_CLOSE_PAREN",
"I2cSerialBusTerm : PARSEOP_I2C_SERIALBUS PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$160 :",
"I2cSerialBusTermV2 : PARSEOP_I2C_SERIALBUS_V2 PARSEOP_OPEN_PAREN $$160 WordConstExpr OptionalSlaveMode ',' DWordConstExpr OptionalAddressingMode ',' StringData OptionalByteConstExpr OptionalResourceType OptionalNameString OptionalShareType OptionalBuffer_Last PARSEOP_CLOSE_PAREN",
"I2cSerialBusTermV2 : PARSEOP_I2C_SERIALBUS_V2 PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$161 :",
"InterruptTerm : PARSEOP_INTERRUPT PARSEOP_OPEN_PAREN $$161 OptionalResourceType_First ',' InterruptTypeKeyword ',' InterruptLevel OptionalShareType OptionalByteConstExpr OptionalStringData OptionalNameString_Last PARSEOP_CLOSE_PAREN '{' DWordList '}'",
"InterruptTerm : PARSEOP_INTERRUPT PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$162 :",
"IOTerm : PARSEOP_IO PARSEOP_OPEN_PAREN $$162 IODecodeKeyword ',' WordConstExpr ',' WordConstExpr ',' ByteConstExpr ',' ByteConstExpr OptionalNameString_Last PARSEOP_CLOSE_PAREN",
"IOTerm : PARSEOP_IO PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$163 :",
"IRQNoFlagsTerm : PARSEOP_IRQNOFLAGS PARSEOP_OPEN_PAREN $$163 OptionalNameString_First PARSEOP_CLOSE_PAREN '{' ByteList '}'",
"IRQNoFlagsTerm : PARSEOP_IRQNOFLAGS PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$164 :",
"IRQTerm : PARSEOP_IRQ PARSEOP_OPEN_PAREN $$164 InterruptTypeKeyword ',' InterruptLevel OptionalShareType OptionalNameString_Last PARSEOP_CLOSE_PAREN '{' ByteList '}'",
"IRQTerm : PARSEOP_IRQ PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$165 :",
"Memory24Term : PARSEOP_MEMORY24 PARSEOP_OPEN_PAREN $$165 OptionalReadWriteKeyword ',' WordConstExpr ',' WordConstExpr ',' WordConstExpr ',' WordConstExpr OptionalNameString_Last PARSEOP_CLOSE_PAREN",
"Memory24Term : PARSEOP_MEMORY24 PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$166 :",
"Memory32FixedTerm : PARSEOP_MEMORY32FIXED PARSEOP_OPEN_PAREN $$166 OptionalReadWriteKeyword ',' DWordConstExpr ',' DWordConstExpr OptionalNameString_Last PARSEOP_CLOSE_PAREN",
"Memory32FixedTerm : PARSEOP_MEMORY32FIXED PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$167 :",
"Memory32Term : PARSEOP_MEMORY32 PARSEOP_OPEN_PAREN $$167 OptionalReadWriteKeyword ',' DWordConstExpr ',' DWordConstExpr ',' DWordConstExpr ',' DWordConstExpr OptionalNameString_Last PARSEOP_CLOSE_PAREN",
"Memory32Term : PARSEOP_MEMORY32 PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$168 :",
"PinConfigTerm : PARSEOP_PINCONFIG PARSEOP_OPEN_PAREN $$168 OptionalShareType_First ',' ByteConstExpr ',' DWordConstExpr ',' StringData OptionalByteConstExpr OptionalResourceType OptionalNameString OptionalBuffer_Last PARSEOP_CLOSE_PAREN '{' DWordList '}'",
"PinConfigTerm : PARSEOP_PINCONFIG PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$169 :",
"PinFunctionTerm : PARSEOP_PINFUNCTION PARSEOP_OPEN_PAREN $$169 OptionalShareType_First ',' PinConfigByte ',' WordConstExpr ',' StringData OptionalByteConstExpr OptionalResourceType OptionalNameString OptionalBuffer_Last PARSEOP_CLOSE_PAREN '{' DWordList '}'",
"PinFunctionTerm : PARSEOP_PINFUNCTION PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$170 :",
"PinGroupTerm : PARSEOP_PINGROUP PARSEOP_OPEN_PAREN $$170 StringData OptionalProducerResourceType OptionalNameString OptionalBuffer_Last PARSEOP_CLOSE_PAREN '{' DWordList '}'",
"PinGroupTerm : PARSEOP_PINGROUP PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$171 :",
"PinGroupConfigTerm : PARSEOP_PINGROUPCONFIG PARSEOP_OPEN_PAREN $$171 OptionalShareType_First ',' ByteConstExpr ',' DWordConstExpr ',' StringData OptionalByteConstExpr ',' StringData OptionalResourceType OptionalNameString OptionalBuffer_Last PARSEOP_CLOSE_PAREN",
"PinGroupConfigTerm : PARSEOP_PINGROUPCONFIG PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$172 :",
"PinGroupFunctionTerm : PARSEOP_PINGROUPFUNCTION PARSEOP_OPEN_PAREN $$172 OptionalShareType_First ',' WordConstExpr ',' StringData OptionalByteConstExpr ',' StringData OptionalResourceType OptionalNameString OptionalBuffer_Last PARSEOP_CLOSE_PAREN",
"PinGroupFunctionTerm : PARSEOP_PINGROUPFUNCTION PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$173 :",
"QWordIOTerm : PARSEOP_QWORDIO PARSEOP_OPEN_PAREN $$173 OptionalResourceType_First OptionalMinType OptionalMaxType OptionalDecodeType OptionalRangeType ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr OptionalByteConstExpr OptionalStringData OptionalNameString OptionalType OptionalTranslationType_Last PARSEOP_CLOSE_PAREN",
"QWordIOTerm : PARSEOP_QWORDIO PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$174 :",
"QWordMemoryTerm : PARSEOP_QWORDMEMORY PARSEOP_OPEN_PAREN $$174 OptionalResourceType_First OptionalDecodeType OptionalMinType OptionalMaxType OptionalMemType ',' OptionalReadWriteKeyword ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr OptionalByteConstExpr OptionalStringData OptionalNameString OptionalAddressRange OptionalType_Last PARSEOP_CLOSE_PAREN",
"QWordMemoryTerm : PARSEOP_QWORDMEMORY PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$175 :",
"$$176 :",
"QWordSpaceTerm : PARSEOP_QWORDSPACE PARSEOP_OPEN_PAREN $$175 ByteConstExpr $$176 OptionalResourceType OptionalDecodeType OptionalMinType OptionalMaxType ',' ByteConstExpr ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr ',' QWordConstExpr OptionalByteConstExpr OptionalStringData OptionalNameString_Last PARSEOP_CLOSE_PAREN",
"QWordSpaceTerm : PARSEOP_QWORDSPACE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$177 :",
"RegisterTerm : PARSEOP_REGISTER PARSEOP_OPEN_PAREN $$177 AddressSpaceKeyword ',' ByteConstExpr ',' ByteConstExpr ',' QWordConstExpr OptionalAccessSize OptionalNameString_Last PARSEOP_CLOSE_PAREN",
"RegisterTerm : PARSEOP_REGISTER PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$178 :",
"SpiSerialBusTerm : PARSEOP_SPI_SERIALBUS PARSEOP_OPEN_PAREN $$178 WordConstExpr OptionalDevicePolarity OptionalWireMode ',' ByteConstExpr OptionalSlaveMode ',' DWordConstExpr ',' ClockPolarityKeyword ',' ClockPhaseKeyword ',' StringData OptionalByteConstExpr OptionalResourceType OptionalNameString OptionalBuffer_Last PARSEOP_CLOSE_PAREN",
"SpiSerialBusTerm : PARSEOP_SPI_SERIALBUS PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$179 :",
"SpiSerialBusTermV2 : PARSEOP_SPI_SERIALBUS_V2 PARSEOP_OPEN_PAREN $$179 WordConstExpr OptionalDevicePolarity OptionalWireMode ',' ByteConstExpr OptionalSlaveMode ',' DWordConstExpr ',' ClockPolarityKeyword ',' ClockPhaseKeyword ',' StringData OptionalByteConstExpr OptionalResourceType OptionalNameString OptionalShareType OptionalBuffer_Last PARSEOP_CLOSE_PAREN",
"SpiSerialBusTermV2 : PARSEOP_SPI_SERIALBUS_V2 PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$180 :",
"StartDependentFnNoPriTerm : PARSEOP_STARTDEPENDENTFN_NOPRI PARSEOP_OPEN_PAREN $$180 PARSEOP_CLOSE_PAREN '{' ResourceMacroList '}'",
"StartDependentFnNoPriTerm : PARSEOP_STARTDEPENDENTFN_NOPRI PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$181 :",
"StartDependentFnTerm : PARSEOP_STARTDEPENDENTFN PARSEOP_OPEN_PAREN $$181 ByteConstExpr ',' ByteConstExpr PARSEOP_CLOSE_PAREN '{' ResourceMacroList '}'",
"StartDependentFnTerm : PARSEOP_STARTDEPENDENTFN PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$182 :",
"UartSerialBusTerm : PARSEOP_UART_SERIALBUS PARSEOP_OPEN_PAREN $$182 DWordConstExpr OptionalBitsPerByte OptionalStopBits ',' ByteConstExpr OptionalEndian OptionalParityType OptionalFlowControl ',' WordConstExpr ',' WordConstExpr ',' StringData OptionalByteConstExpr OptionalResourceType OptionalNameString OptionalBuffer_Last PARSEOP_CLOSE_PAREN",
"UartSerialBusTerm : PARSEOP_UART_SERIALBUS PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$183 :",
"UartSerialBusTermV2 : PARSEOP_UART_SERIALBUS_V2 PARSEOP_OPEN_PAREN $$183 DWordConstExpr OptionalBitsPerByte OptionalStopBits ',' ByteConstExpr OptionalEndian OptionalParityType OptionalFlowControl ',' WordConstExpr ',' WordConstExpr ',' StringData OptionalByteConstExpr OptionalResourceType OptionalNameString OptionalShareType OptionalBuffer_Last PARSEOP_CLOSE_PAREN",
"UartSerialBusTermV2 : PARSEOP_UART_SERIALBUS_V2 PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$184 :",
"VendorLongTerm : PARSEOP_VENDORLONG PARSEOP_OPEN_PAREN $$184 OptionalNameString_First PARSEOP_CLOSE_PAREN '{' ByteList '}'",
"VendorLongTerm : PARSEOP_VENDORLONG PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$185 :",
"VendorShortTerm : PARSEOP_VENDORSHORT PARSEOP_OPEN_PAREN $$185 OptionalNameString_First PARSEOP_CLOSE_PAREN '{' ByteList '}'",
"VendorShortTerm : PARSEOP_VENDORSHORT PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$186 :",
"WordBusNumberTerm : PARSEOP_WORDBUSNUMBER PARSEOP_OPEN_PAREN $$186 OptionalResourceType_First OptionalMinType OptionalMaxType OptionalDecodeType ',' WordConstExpr ',' WordConstExpr ',' WordConstExpr ',' WordConstExpr ',' WordConstExpr OptionalByteConstExpr OptionalStringData OptionalNameString_Last PARSEOP_CLOSE_PAREN",
"WordBusNumberTerm : PARSEOP_WORDBUSNUMBER PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$187 :",
"WordIOTerm : PARSEOP_WORDIO PARSEOP_OPEN_PAREN $$187 OptionalResourceType_First OptionalMinType OptionalMaxType OptionalDecodeType OptionalRangeType ',' WordConstExpr ',' WordConstExpr ',' WordConstExpr ',' WordConstExpr ',' WordConstExpr OptionalByteConstExpr OptionalStringData OptionalNameString OptionalType OptionalTranslationType_Last PARSEOP_CLOSE_PAREN",
"WordIOTerm : PARSEOP_WORDIO PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"$$188 :",
"$$189 :",
"WordSpaceTerm : PARSEOP_WORDSPACE PARSEOP_OPEN_PAREN $$188 ByteConstExpr $$189 OptionalResourceType OptionalDecodeType OptionalMinType OptionalMaxType ',' ByteConstExpr ',' WordConstExpr ',' WordConstExpr ',' WordConstExpr ',' WordConstExpr ',' WordConstExpr OptionalByteConstExpr OptionalStringData OptionalNameString_Last PARSEOP_CLOSE_PAREN",
"WordSpaceTerm : PARSEOP_WORDSPACE PARSEOP_OPEN_PAREN error PARSEOP_CLOSE_PAREN",
"OptionalBusMasterKeyword : ','",
"OptionalBusMasterKeyword : ',' PARSEOP_BUSMASTERTYPE_MASTER",
"OptionalBusMasterKeyword : ',' PARSEOP_BUSMASTERTYPE_NOTMASTER",
"OptionalAccessAttribTerm :",
"OptionalAccessAttribTerm : ','",
"OptionalAccessAttribTerm : ',' ByteConstExpr",
"OptionalAccessAttribTerm : ',' AccessAttribKeyword",
"OptionalAccessSize :",
"OptionalAccessSize : ','",
"OptionalAccessSize : ',' ByteConstExpr",
"OptionalAddressingMode : ','",
"OptionalAddressingMode : ',' AddressingModeKeyword",
"OptionalAddressRange :",
"OptionalAddressRange : ','",
"OptionalAddressRange : ',' AddressKeyword",
"OptionalBitsPerByte : ','",
"OptionalBitsPerByte : ',' BitsPerByteKeyword",
"OptionalBuffer_Last :",
"OptionalBuffer_Last : ','",
"OptionalBuffer_Last : ',' RawDataBufferTerm",
"OptionalByteConstExpr :",
"OptionalByteConstExpr : ','",
"OptionalByteConstExpr : ',' ByteConstExpr",
"OptionalDecodeType : ','",
"OptionalDecodeType : ',' DecodeKeyword",
"OptionalDevicePolarity : ','",
"OptionalDevicePolarity : ',' DevicePolarityKeyword",
"OptionalDWordConstExpr :",
"OptionalDWordConstExpr : ','",
"OptionalDWordConstExpr : ',' DWordConstExpr",
"OptionalEndian : ','",
"OptionalEndian : ',' EndianKeyword",
"OptionalFlowControl : ','",
"OptionalFlowControl : ',' FlowControlKeyword",
"OptionalIoRestriction : ','",
"OptionalIoRestriction : ',' IoRestrictionKeyword",
"OptionalListString :",
"OptionalListString : ','",
"OptionalListString : ',' TermArg",
"OptionalMaxType : ','",
"OptionalMaxType : ',' MaxKeyword",
"OptionalMemType : ','",
"OptionalMemType : ',' MemTypeKeyword",
"OptionalMinType : ','",
"OptionalMinType : ',' MinKeyword",
"OptionalNameString :",
"OptionalNameString : ','",
"OptionalNameString : ',' NameString",
"OptionalNameString_Last :",
"OptionalNameString_Last : ','",
"OptionalNameString_Last : ',' NameString",
"OptionalNameString_First :",
"OptionalNameString_First : NameString",
"OptionalObjectTypeKeyword :",
"OptionalObjectTypeKeyword : ',' ObjectTypeKeyword",
"OptionalParityType : ','",
"OptionalParityType : ',' ParityTypeKeyword",
"OptionalQWordConstExpr :",
"OptionalQWordConstExpr : ','",
"OptionalQWordConstExpr : ',' QWordConstExpr",
"OptionalRangeType : ','",
"OptionalRangeType : ',' RangeTypeKeyword",
"OptionalReadWriteKeyword :",
"OptionalReadWriteKeyword : PARSEOP_READWRITETYPE_BOTH",
"OptionalReadWriteKeyword : PARSEOP_READWRITETYPE_READONLY",
"OptionalResourceType_First :",
"OptionalResourceType_First : ResourceTypeKeyword",
"OptionalResourceType :",
"OptionalResourceType : ','",
"OptionalResourceType : ',' ResourceTypeKeyword",
"OptionalProducerResourceType :",
"OptionalProducerResourceType : ','",
"OptionalProducerResourceType : ',' ResourceTypeKeyword",
"OptionalSlaveMode : ','",
"OptionalSlaveMode : ',' SlaveModeKeyword",
"OptionalShareType :",
"OptionalShareType : ','",
"OptionalShareType : ',' ShareTypeKeyword",
"OptionalShareType_First :",
"OptionalShareType_First : ShareTypeKeyword",
"OptionalStopBits : ','",
"OptionalStopBits : ',' StopBitsKeyword",
"OptionalStringData :",
"OptionalStringData : ','",
"OptionalStringData : ',' StringData",
"OptionalTranslationType_Last :",
"OptionalTranslationType_Last : ','",
"OptionalTranslationType_Last : ',' TranslationKeyword",
"OptionalType :",
"OptionalType : ','",
"OptionalType : ',' TypeKeyword",
"OptionalType_Last :",
"OptionalType_Last : ','",
"OptionalType_Last : ',' TypeKeyword",
"OptionalWireMode : ','",
"OptionalWireMode : ',' WireModeKeyword",
"OptionalWordConstExpr : ','",
"OptionalWordConstExpr : ',' WordConstExpr",
"OptionalXferSize :",
"OptionalXferSize : ','",
"OptionalXferSize : ',' XferSizeKeyword",

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
#line 4804 "aslcompiler.y"

/*! [End] no source code translation !*/

/* Local support functions in C */



/******************************************************************************
 *
 * Local support functions
 *
 *****************************************************************************/

/*! [Begin] no source code translation */
int
AslCompilerwrap(void)
{
  return (1);
}
/*! [End] no source code translation !*/


void *
AslLocalAllocate (
    unsigned int        Size)
{
    void                *Mem;


    DbgPrint (ASL_PARSE_OUTPUT,
        "\nAslLocalAllocate: Expanding Stack to %u\n\n", Size);

    Mem = ACPI_ALLOCATE_ZEROED (Size);
    if (!Mem)
    {
        AslCommonError (ASL_ERROR, ASL_MSG_MEMORY_ALLOCATION,
            Gbl_CurrentLineNumber, Gbl_LogicalLineNumber,
            Gbl_InputByteCount, Gbl_CurrentColumn,
            Gbl_Files[ASL_FILE_INPUT].Filename, NULL);
        exit (1);
    }

    return (Mem);
}

ACPI_PARSE_OBJECT *
AslDoError (
    void)
{

    return (TrCreateLeafOp (PARSEOP_ERRORNODE));
}


/*******************************************************************************
 *
 * FUNCTION:    UtGetOpName
 *
 * PARAMETERS:  ParseOpcode         - Parser keyword ID
 *
 * RETURN:      Pointer to the opcode name
 *
 * DESCRIPTION: Get the ascii name of the parse opcode
 *
 ******************************************************************************/

char *
UtGetOpName (
    UINT32                  ParseOpcode)
{
#ifdef ASL_YYTNAME_START
    /*
     * First entries (ASL_YYTNAME_START) in yytname are special reserved names.
     * Ignore first 8 characters of the name
     */
    return ((char *) yytname
        [(ParseOpcode - ASL_FIRST_PARSE_OPCODE) + ASL_YYTNAME_START] + 8);
#else
    return ("[Unknown parser generator]");
#endif
}

#line 13795 "aslcompilerparse.c"

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
#line 1144 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (
                                        TrCreateLeafOp (PARSEOP_ASL_CODE),1, yystack.l_mark[0].n);}
break;
case 2:
#line 1146 "aslcompiler.y"
	{YYABORT; yyval.n = NULL;}
break;
case 3:
#line 1171 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DEFINITION_BLOCK); COMMENT_CAPTURE_OFF;}
break;
case 4:
#line 1178 "aslcompiler.y"
	{TrSetOpIntegerWidth (yystack.l_mark[-9].n,yystack.l_mark[-7].n);
                                        TrSetOpEndLineNumber (yystack.l_mark[-12].n); COMMENT_CAPTURE_ON;}
break;
case 5:
#line 1180 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-16].n,7,
                                        yystack.l_mark[-15].n,yystack.l_mark[-13].n,yystack.l_mark[-11].n,yystack.l_mark[-9].n,yystack.l_mark[-7].n,yystack.l_mark[-5].n,yystack.l_mark[-1].n);}
break;
case 7:
#line 1187 "aslcompiler.y"
	{yyval.n = TrLinkPeerOps (2, yystack.l_mark[-1].n,yystack.l_mark[0].n);}
break;
case 8:
#line 1196 "aslcompiler.y"
	{}
break;
case 9:
#line 1197 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_NAMESTRING, (ACPI_NATIVE_INT) yystack.l_mark[0].s);}
break;
case 10:
#line 1198 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_NAMESTRING, (ACPI_NATIVE_INT) "IO");}
break;
case 11:
#line 1199 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_NAMESTRING, (ACPI_NATIVE_INT) "DMA");}
break;
case 12:
#line 1200 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_NAMESTRING, (ACPI_NATIVE_INT) "IRQ");}
break;
case 13:
#line 1201 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_NAMESTRING, (ACPI_NATIVE_INT) "FOR");}
break;
case 14:
#line 1211 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_NAMESEG,
                                        (ACPI_NATIVE_INT) AslCompilerlval.s);}
break;
case 15:
#line 1219 "aslcompiler.y"
	{}
break;
case 16:
#line 1220 "aslcompiler.y"
	{}
break;
case 17:
#line 1221 "aslcompiler.y"
	{}
break;
case 18:
#line 1222 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);}
break;
case 19:
#line 1223 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);}
break;
case 20:
#line 1224 "aslcompiler.y"
	{}
break;
case 21:
#line 1225 "aslcompiler.y"
	{}
break;
case 22:
#line 1226 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 23:
#line 1230 "aslcompiler.y"
	{}
break;
case 24:
#line 1231 "aslcompiler.y"
	{}
break;
case 25:
#line 1232 "aslcompiler.y"
	{}
break;
case 26:
#line 1236 "aslcompiler.y"
	{yyval.n = TrCreateNullTargetOp ();}
break;
case 27:
#line 1237 "aslcompiler.y"
	{yyval.n = TrCreateNullTargetOp ();}
break;
case 28:
#line 1238 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_IS_TARGET);}
break;
case 29:
#line 1242 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_IS_TARGET);}
break;
case 30:
#line 1246 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_IS_TERM_ARG);}
break;
case 31:
#line 1247 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_IS_TERM_ARG);}
break;
case 32:
#line 1248 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_IS_TERM_ARG);}
break;
case 33:
#line 1251 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[-1].n, OP_IS_TERM_ARG);}
break;
case 34:
#line 1265 "aslcompiler.y"
	{TrSetOpIntegerValue (PARSEOP_METHODCALL, yystack.l_mark[-1].n); COMMENT_CAPTURE_OFF;}
break;
case 35:
#line 1267 "aslcompiler.y"
	{yyval.n = TrLinkChildOp (yystack.l_mark[-4].n,yystack.l_mark[-1].n); COMMENT_CAPTURE_ON;}
break;
case 36:
#line 1273 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ONES);}
break;
case 37:
#line 1274 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ONES);}
break;
case 38:
#line 1275 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 39:
#line 1285 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 40:
#line 1288 "aslcompiler.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 41:
#line 1290 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 42:
#line 1294 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 43:
#line 1299 "aslcompiler.y"
	{yyval.n = yystack.l_mark[-2].n;}
break;
case 44:
#line 1304 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 45:
#line 1313 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 46:
#line 1314 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (
                                        TrSetOpFlags (yystack.l_mark[-1].n, OP_RESULT_NOT_USED),yystack.l_mark[0].n);}
break;
case 47:
#line 1316 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (
                                        TrSetOpFlags (yystack.l_mark[-2].n, OP_RESULT_NOT_USED),yystack.l_mark[-1].n);}
break;
case 48:
#line 1318 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (
                                        TrSetOpFlags (yystack.l_mark[-2].n, OP_RESULT_NOT_USED),yystack.l_mark[0].n);}
break;
case 49:
#line 1320 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (
                                        TrSetOpFlags (yystack.l_mark[-3].n, OP_RESULT_NOT_USED),yystack.l_mark[-1].n);}
break;
case 50:
#line 1325 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 53:
#line 1329 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 54:
#line 1333 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 57:
#line 1337 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 58:
#line 1341 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 61:
#line 1345 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 62:
#line 1349 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 65:
#line 1353 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 66:
#line 1357 "aslcompiler.y"
	{}
break;
case 67:
#line 1358 "aslcompiler.y"
	{}
break;
case 68:
#line 1359 "aslcompiler.y"
	{}
break;
case 69:
#line 1360 "aslcompiler.y"
	{}
break;
case 70:
#line 1364 "aslcompiler.y"
	{yyval.n = TrCreateOp (PARSEOP_RESERVED_BYTES,1,yystack.l_mark[0].n);}
break;
case 71:
#line 1366 "aslcompiler.y"
	{yyval.n = TrLinkChildOp (yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 72:
#line 1370 "aslcompiler.y"
	{}
break;
case 73:
#line 1371 "aslcompiler.y"
	{}
break;
case 74:
#line 1372 "aslcompiler.y"
	{}
break;
case 75:
#line 1377 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 78:
#line 1381 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 79:
#line 1385 "aslcompiler.y"
	{}
break;
case 80:
#line 1386 "aslcompiler.y"
	{}
break;
case 81:
#line 1392 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 82:
#line 1393 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 83:
#line 1395 "aslcompiler.y"
	{yyval.n = TrLinkPeerOps (2,yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 84:
#line 1399 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 85:
#line 1400 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 86:
#line 1401 "aslcompiler.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 87:
#line 1405 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DEFAULT_ARG);}
break;
case 88:
#line 1406 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (
                                        TrCreateLeafOp (PARSEOP_DEFAULT_ARG),1,yystack.l_mark[0].n);}
break;
case 89:
#line 1413 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 90:
#line 1415 "aslcompiler.y"
	{yyval.n = TrLinkPeerOps (2,yystack.l_mark[-2].n,yystack.l_mark[0].n);}
break;
case 91:
#line 1419 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 92:
#line 1420 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 93:
#line 1421 "aslcompiler.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 94:
#line 1425 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DEFAULT_ARG);}
break;
case 95:
#line 1426 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (
                                        TrCreateLeafOp (PARSEOP_DEFAULT_ARG),1,yystack.l_mark[0].n);}
break;
case 96:
#line 1434 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 97:
#line 1435 "aslcompiler.y"
	{}
break;
case 98:
#line 1436 "aslcompiler.y"
	{}
break;
case 99:
#line 1438 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (yystack.l_mark[-1].n,yystack.l_mark[0].n);}
break;
case 100:
#line 1440 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (yystack.l_mark[-1].n,yystack.l_mark[0].n);}
break;
case 101:
#line 1470 "aslcompiler.y"
	{}
break;
case 102:
#line 1471 "aslcompiler.y"
	{}
break;
case 103:
#line 1472 "aslcompiler.y"
	{}
break;
case 104:
#line 1473 "aslcompiler.y"
	{}
break;
case 105:
#line 1477 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);}
break;
case 106:
#line 1478 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);}
break;
case 107:
#line 1479 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);}
break;
case 108:
#line 1480 "aslcompiler.y"
	{}
break;
case 109:
#line 1484 "aslcompiler.y"
	{}
break;
case 110:
#line 1488 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);}
break;
case 111:
#line 1489 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);}
break;
case 112:
#line 1490 "aslcompiler.y"
	{}
break;
case 113:
#line 1491 "aslcompiler.y"
	{}
break;
case 114:
#line 1495 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);}
break;
case 115:
#line 1496 "aslcompiler.y"
	{}
break;
case 116:
#line 1500 "aslcompiler.y"
	{yyval.n = TrSetOpIntegerValue (PARSEOP_BYTECONST, yystack.l_mark[0].n);}
break;
case 117:
#line 1504 "aslcompiler.y"
	{yyval.n = TrSetOpIntegerValue (PARSEOP_WORDCONST, yystack.l_mark[0].n);}
break;
case 118:
#line 1508 "aslcompiler.y"
	{yyval.n = TrSetOpIntegerValue (PARSEOP_DWORDCONST, yystack.l_mark[0].n);}
break;
case 119:
#line 1512 "aslcompiler.y"
	{yyval.n = TrSetOpIntegerValue (PARSEOP_QWORDCONST, yystack.l_mark[0].n);}
break;
case 120:
#line 1524 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);
                                        TrSetOpAmlLength (yystack.l_mark[0].n, 1);}
break;
case 121:
#line 1526 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);
                                        TrSetOpAmlLength (yystack.l_mark[0].n, 1);}
break;
case 122:
#line 1528 "aslcompiler.y"
	{yyval.n = TrSetOpIntegerValue (PARSEOP_BYTECONST, yystack.l_mark[0].n);}
break;
case 123:
#line 1529 "aslcompiler.y"
	{}
break;
case 124:
#line 1533 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);
                                        TrSetOpAmlLength (yystack.l_mark[0].n, 2);}
break;
case 125:
#line 1535 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);
                                        TrSetOpAmlLength (yystack.l_mark[0].n, 2);}
break;
case 126:
#line 1537 "aslcompiler.y"
	{yyval.n = TrSetOpIntegerValue (PARSEOP_WORDCONST, yystack.l_mark[0].n);}
break;
case 127:
#line 1538 "aslcompiler.y"
	{}
break;
case 128:
#line 1542 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);
                                        TrSetOpAmlLength (yystack.l_mark[0].n, 4);}
break;
case 129:
#line 1544 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);
                                        TrSetOpAmlLength (yystack.l_mark[0].n, 4);}
break;
case 130:
#line 1546 "aslcompiler.y"
	{yyval.n = TrSetOpIntegerValue (PARSEOP_DWORDCONST, yystack.l_mark[0].n);}
break;
case 131:
#line 1547 "aslcompiler.y"
	{}
break;
case 132:
#line 1551 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);
                                        TrSetOpAmlLength (yystack.l_mark[0].n, 8);}
break;
case 133:
#line 1553 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);
                                        TrSetOpAmlLength (yystack.l_mark[0].n, 8);}
break;
case 134:
#line 1555 "aslcompiler.y"
	{yyval.n = TrSetOpIntegerValue (PARSEOP_QWORDCONST, yystack.l_mark[0].n);}
break;
case 135:
#line 1556 "aslcompiler.y"
	{}
break;
case 136:
#line 1560 "aslcompiler.y"
	{}
break;
case 137:
#line 1561 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_REVISION);}
break;
case 138:
#line 1565 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_ZERO, 0);}
break;
case 139:
#line 1566 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_ONE, 1);}
break;
case 140:
#line 1567 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_ONES, ACPI_UINT64_MAX);}
break;
case 141:
#line 1568 "aslcompiler.y"
	{yyval.n = TrCreateConstantLeafOp (PARSEOP___DATE__);}
break;
case 142:
#line 1569 "aslcompiler.y"
	{yyval.n = TrCreateConstantLeafOp (PARSEOP___FILE__);}
break;
case 143:
#line 1570 "aslcompiler.y"
	{yyval.n = TrCreateConstantLeafOp (PARSEOP___LINE__);}
break;
case 144:
#line 1571 "aslcompiler.y"
	{yyval.n = TrCreateConstantLeafOp (PARSEOP___PATH__);}
break;
case 145:
#line 1572 "aslcompiler.y"
	{yyval.n = TrCreateConstantLeafOp (PARSEOP___METHOD__);}
break;
case 146:
#line 1576 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_INTEGER,
                                        AslCompilerlval.i);}
break;
case 147:
#line 1581 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_STRING_LITERAL,
                                        (ACPI_NATIVE_INT) AslCompilerlval.s);}
break;
case 148:
#line 1593 "aslcompiler.y"
	{}
break;
case 149:
#line 1594 "aslcompiler.y"
	{}
break;
case 150:
#line 1595 "aslcompiler.y"
	{}
break;
case 151:
#line 1599 "aslcompiler.y"
	{}
break;
case 152:
#line 1600 "aslcompiler.y"
	{}
break;
case 153:
#line 1601 "aslcompiler.y"
	{}
break;
case 154:
#line 1602 "aslcompiler.y"
	{}
break;
case 155:
#line 1603 "aslcompiler.y"
	{}
break;
case 156:
#line 1604 "aslcompiler.y"
	{}
break;
case 157:
#line 1605 "aslcompiler.y"
	{}
break;
case 158:
#line 1606 "aslcompiler.y"
	{}
break;
case 159:
#line 1607 "aslcompiler.y"
	{}
break;
case 160:
#line 1608 "aslcompiler.y"
	{}
break;
case 161:
#line 1609 "aslcompiler.y"
	{}
break;
case 162:
#line 1610 "aslcompiler.y"
	{}
break;
case 163:
#line 1611 "aslcompiler.y"
	{}
break;
case 164:
#line 1612 "aslcompiler.y"
	{}
break;
case 165:
#line 1613 "aslcompiler.y"
	{}
break;
case 166:
#line 1614 "aslcompiler.y"
	{}
break;
case 167:
#line 1615 "aslcompiler.y"
	{}
break;
case 168:
#line 1616 "aslcompiler.y"
	{}
break;
case 169:
#line 1617 "aslcompiler.y"
	{}
break;
case 170:
#line 1621 "aslcompiler.y"
	{}
break;
case 171:
#line 1622 "aslcompiler.y"
	{}
break;
case 172:
#line 1624 "aslcompiler.y"
	{}
break;
case 173:
#line 1628 "aslcompiler.y"
	{}
break;
case 174:
#line 1629 "aslcompiler.y"
	{}
break;
case 175:
#line 1630 "aslcompiler.y"
	{}
break;
case 176:
#line 1636 "aslcompiler.y"
	{}
break;
case 177:
#line 1637 "aslcompiler.y"
	{}
break;
case 178:
#line 1638 "aslcompiler.y"
	{}
break;
case 179:
#line 1639 "aslcompiler.y"
	{}
break;
case 180:
#line 1640 "aslcompiler.y"
	{}
break;
case 181:
#line 1641 "aslcompiler.y"
	{}
break;
case 182:
#line 1647 "aslcompiler.y"
	{}
break;
case 183:
#line 1648 "aslcompiler.y"
	{}
break;
case 184:
#line 1649 "aslcompiler.y"
	{}
break;
case 185:
#line 1650 "aslcompiler.y"
	{}
break;
case 186:
#line 1651 "aslcompiler.y"
	{}
break;
case 187:
#line 1652 "aslcompiler.y"
	{}
break;
case 188:
#line 1653 "aslcompiler.y"
	{}
break;
case 189:
#line 1654 "aslcompiler.y"
	{}
break;
case 190:
#line 1660 "aslcompiler.y"
	{}
break;
case 191:
#line 1661 "aslcompiler.y"
	{}
break;
case 192:
#line 1662 "aslcompiler.y"
	{}
break;
case 193:
#line 1663 "aslcompiler.y"
	{}
break;
case 194:
#line 1664 "aslcompiler.y"
	{}
break;
case 195:
#line 1670 "aslcompiler.y"
	{}
break;
case 196:
#line 1671 "aslcompiler.y"
	{}
break;
case 197:
#line 1672 "aslcompiler.y"
	{}
break;
case 198:
#line 1673 "aslcompiler.y"
	{}
break;
case 199:
#line 1674 "aslcompiler.y"
	{}
break;
case 200:
#line 1681 "aslcompiler.y"
	{}
break;
case 201:
#line 1682 "aslcompiler.y"
	{}
break;
case 202:
#line 1683 "aslcompiler.y"
	{}
break;
case 203:
#line 1684 "aslcompiler.y"
	{}
break;
case 204:
#line 1685 "aslcompiler.y"
	{}
break;
case 205:
#line 1686 "aslcompiler.y"
	{}
break;
case 206:
#line 1687 "aslcompiler.y"
	{}
break;
case 207:
#line 1688 "aslcompiler.y"
	{}
break;
case 208:
#line 1689 "aslcompiler.y"
	{}
break;
case 209:
#line 1690 "aslcompiler.y"
	{}
break;
case 210:
#line 1691 "aslcompiler.y"
	{}
break;
case 211:
#line 1692 "aslcompiler.y"
	{}
break;
case 212:
#line 1693 "aslcompiler.y"
	{}
break;
case 213:
#line 1694 "aslcompiler.y"
	{}
break;
case 214:
#line 1695 "aslcompiler.y"
	{}
break;
case 215:
#line 1696 "aslcompiler.y"
	{}
break;
case 216:
#line 1697 "aslcompiler.y"
	{}
break;
case 217:
#line 1698 "aslcompiler.y"
	{}
break;
case 218:
#line 1702 "aslcompiler.y"
	{}
break;
case 219:
#line 1703 "aslcompiler.y"
	{}
break;
case 220:
#line 1704 "aslcompiler.y"
	{}
break;
case 221:
#line 1705 "aslcompiler.y"
	{}
break;
case 222:
#line 1706 "aslcompiler.y"
	{}
break;
case 223:
#line 1707 "aslcompiler.y"
	{}
break;
case 224:
#line 1708 "aslcompiler.y"
	{}
break;
case 225:
#line 1709 "aslcompiler.y"
	{}
break;
case 226:
#line 1710 "aslcompiler.y"
	{}
break;
case 227:
#line 1711 "aslcompiler.y"
	{}
break;
case 228:
#line 1712 "aslcompiler.y"
	{}
break;
case 229:
#line 1713 "aslcompiler.y"
	{}
break;
case 230:
#line 1720 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);}
break;
case 231:
#line 1721 "aslcompiler.y"
	{}
break;
case 232:
#line 1722 "aslcompiler.y"
	{}
break;
case 233:
#line 1723 "aslcompiler.y"
	{}
break;
case 234:
#line 1724 "aslcompiler.y"
	{}
break;
case 235:
#line 1725 "aslcompiler.y"
	{}
break;
case 236:
#line 1726 "aslcompiler.y"
	{}
break;
case 237:
#line 1727 "aslcompiler.y"
	{}
break;
case 238:
#line 1728 "aslcompiler.y"
	{}
break;
case 239:
#line 1729 "aslcompiler.y"
	{}
break;
case 240:
#line 1732 "aslcompiler.y"
	{}
break;
case 241:
#line 1733 "aslcompiler.y"
	{}
break;
case 242:
#line 1734 "aslcompiler.y"
	{}
break;
case 243:
#line 1735 "aslcompiler.y"
	{}
break;
case 244:
#line 1736 "aslcompiler.y"
	{}
break;
case 245:
#line 1737 "aslcompiler.y"
	{}
break;
case 246:
#line 1738 "aslcompiler.y"
	{}
break;
case 247:
#line 1739 "aslcompiler.y"
	{}
break;
case 248:
#line 1740 "aslcompiler.y"
	{}
break;
case 249:
#line 1741 "aslcompiler.y"
	{}
break;
case 250:
#line 1742 "aslcompiler.y"
	{}
break;
case 251:
#line 1743 "aslcompiler.y"
	{}
break;
case 252:
#line 1744 "aslcompiler.y"
	{}
break;
case 253:
#line 1745 "aslcompiler.y"
	{}
break;
case 254:
#line 1746 "aslcompiler.y"
	{}
break;
case 255:
#line 1747 "aslcompiler.y"
	{}
break;
case 256:
#line 1748 "aslcompiler.y"
	{}
break;
case 257:
#line 1749 "aslcompiler.y"
	{}
break;
case 258:
#line 1750 "aslcompiler.y"
	{}
break;
case 259:
#line 1751 "aslcompiler.y"
	{}
break;
case 260:
#line 1752 "aslcompiler.y"
	{}
break;
case 261:
#line 1753 "aslcompiler.y"
	{}
break;
case 262:
#line 1754 "aslcompiler.y"
	{}
break;
case 263:
#line 1758 "aslcompiler.y"
	{}
break;
case 264:
#line 1759 "aslcompiler.y"
	{}
break;
case 265:
#line 1760 "aslcompiler.y"
	{}
break;
case 266:
#line 1764 "aslcompiler.y"
	{}
break;
case 267:
#line 1765 "aslcompiler.y"
	{}
break;
case 268:
#line 1769 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (yystack.l_mark[0].n, OP_COMPILE_TIME_CONST);}
break;
case 269:
#line 1770 "aslcompiler.y"
	{}
break;
case 270:
#line 1771 "aslcompiler.y"
	{}
break;
case 271:
#line 1772 "aslcompiler.y"
	{}
break;
case 272:
#line 1779 "aslcompiler.y"
	{}
break;
case 273:
#line 1795 "aslcompiler.y"
	{}
break;
case 274:
#line 1796 "aslcompiler.y"
	{}
break;
case 275:
#line 1797 "aslcompiler.y"
	{}
break;
case 276:
#line 1798 "aslcompiler.y"
	{}
break;
case 277:
#line 1802 "aslcompiler.y"
	{}
break;
case 278:
#line 1803 "aslcompiler.y"
	{}
break;
case 279:
#line 1804 "aslcompiler.y"
	{}
break;
case 280:
#line 1805 "aslcompiler.y"
	{}
break;
case 281:
#line 1808 "aslcompiler.y"
	{}
break;
case 282:
#line 1819 "aslcompiler.y"
	{yyval.n = TrSetOpIntegerValue (PARSEOP_PACKAGE_LENGTH,
                                        (ACPI_PARSE_OBJECT *) yystack.l_mark[0].n);}
break;
case 283:
#line 1824 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 284:
#line 1825 "aslcompiler.y"
	{yyval.n = AslDoError (); yyclearin;}
break;
case 285:
#line 1829 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 286:
#line 1830 "aslcompiler.y"
	{yyval.n = AslDoError (); yyclearin;}
break;
case 287:
#line 1834 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ZERO);}
break;
case 288:
#line 1835 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ZERO);}
break;
case 289:
#line 1836 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 290:
#line 1840 "aslcompiler.y"
	{yyval.n = TrSetOpFlags (TrCreateLeafOp (PARSEOP_ZERO),
                                            OP_IS_NULL_RETURN);}
break;
case 291:
#line 1842 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 292:
#line 1846 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 293:
#line 1847 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 294:
#line 1848 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 295:
#line 1852 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DEFAULT_ARG);}
break;
case 296:
#line 1853 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 297:
#line 1857 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 298:
#line 1858 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 299:
#line 1875 "aslcompiler.y"
	{yyval.n = TrCreateOp (PARSEOP_ACCESSAS,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 300:
#line 1878 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 301:
#line 1883 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp(PARSEOP_ACQUIRE);}
break;
case 302:
#line 1886 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,2,yystack.l_mark[-3].n,yystack.l_mark[-1].n);}
break;
case 303:
#line 1889 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 304:
#line 1894 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ADD);}
break;
case 305:
#line 1898 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 306:
#line 1901 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 307:
#line 1906 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ALIAS);}
break;
case 308:
#line 1909 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,
                                        TrSetOpFlags (yystack.l_mark[-1].n, OP_IS_NAME_DECLARATION));}
break;
case 309:
#line 1913 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 310:
#line 1918 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_AND);}
break;
case 311:
#line 1922 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 312:
#line 1925 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 313:
#line 1929 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ARG0);}
break;
case 314:
#line 1930 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ARG1);}
break;
case 315:
#line 1931 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ARG2);}
break;
case 316:
#line 1932 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ARG3);}
break;
case 317:
#line 1933 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ARG4);}
break;
case 318:
#line 1934 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ARG5);}
break;
case 319:
#line 1935 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ARG6);}
break;
case 320:
#line 1940 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_BANKFIELD);}
break;
case 321:
#line 1948 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-13].n,7,
                                        yystack.l_mark[-12].n,yystack.l_mark[-11].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 322:
#line 1953 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 323:
#line 1957 "aslcompiler.y"
	{yyval.n = TrCreateOp (PARSEOP_BREAK, 0);}
break;
case 324:
#line 1961 "aslcompiler.y"
	{yyval.n = TrCreateOp (PARSEOP_BREAKPOINT, 0);}
break;
case 325:
#line 1965 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_BUFFER); COMMENT_CAPTURE_OFF; }
break;
case 326:
#line 1967 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,2,yystack.l_mark[-3].n,yystack.l_mark[-1].n); COMMENT_CAPTURE_ON;}
break;
case 327:
#line 1971 "aslcompiler.y"
	{}
break;
case 328:
#line 1972 "aslcompiler.y"
	{}
break;
case 329:
#line 1977 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_CASE);}
break;
case 330:
#line 1980 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,2,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 331:
#line 1983 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 332:
#line 1988 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_CONCATENATE);}
break;
case 333:
#line 1992 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 334:
#line 1995 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 335:
#line 2000 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (
                                        PARSEOP_CONCATENATERESTEMPLATE);}
break;
case 336:
#line 2005 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 337:
#line 2008 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 338:
#line 2013 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_CONDREFOF);}
break;
case 339:
#line 2016 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 340:
#line 2019 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 341:
#line 2026 "aslcompiler.y"
	{yyval.n = TrCreateOp (PARSEOP_CONNECTION,1,yystack.l_mark[-1].n);}
break;
case 342:
#line 2028 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_CONNECTION);}
break;
case 343:
#line 2030 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n, 1,
                                        TrLinkOpChildren (
                                            TrCreateLeafOp (PARSEOP_RESOURCETEMPLATE), 3,
                                            TrCreateLeafOp (PARSEOP_DEFAULT_ARG),
                                            TrCreateLeafOp (PARSEOP_DEFAULT_ARG),
                                            yystack.l_mark[-1].n));}
break;
case 344:
#line 2038 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 345:
#line 2042 "aslcompiler.y"
	{yyval.n = TrCreateOp (PARSEOP_CONTINUE, 0);}
break;
case 346:
#line 2047 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_COPYOBJECT);}
break;
case 347:
#line 2050 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,2,yystack.l_mark[-3].n,
                                        TrSetOpFlags (yystack.l_mark[-1].n, OP_IS_TARGET));}
break;
case 348:
#line 2054 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 349:
#line 2059 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_CREATEBITFIELD);}
break;
case 350:
#line 2063 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,
                                        TrSetOpFlags (yystack.l_mark[-1].n, OP_IS_NAME_DECLARATION));}
break;
case 351:
#line 2067 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 352:
#line 2072 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_CREATEBYTEFIELD);}
break;
case 353:
#line 2076 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,
                                        TrSetOpFlags (yystack.l_mark[-1].n, OP_IS_NAME_DECLARATION));}
break;
case 354:
#line 2080 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 355:
#line 2085 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_CREATEDWORDFIELD);}
break;
case 356:
#line 2089 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,
                                        TrSetOpFlags (yystack.l_mark[-1].n, OP_IS_NAME_DECLARATION));}
break;
case 357:
#line 2093 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 358:
#line 2098 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_CREATEFIELD);}
break;
case 359:
#line 2103 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,4,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,
                                        TrSetOpFlags (yystack.l_mark[-1].n, OP_IS_NAME_DECLARATION));}
break;
case 360:
#line 2107 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 361:
#line 2112 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_CREATEQWORDFIELD);}
break;
case 362:
#line 2116 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,
                                        TrSetOpFlags (yystack.l_mark[-1].n, OP_IS_NAME_DECLARATION));}
break;
case 363:
#line 2120 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 364:
#line 2125 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_CREATEWORDFIELD);}
break;
case 365:
#line 2129 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,
                                        TrSetOpFlags (yystack.l_mark[-1].n, OP_IS_NAME_DECLARATION));}
break;
case 366:
#line 2133 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 367:
#line 2138 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DATATABLEREGION);}
break;
case 368:
#line 2143 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,4,
                                        TrSetOpFlags (yystack.l_mark[-4].n, OP_IS_NAME_DECLARATION),yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 369:
#line 2147 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 370:
#line 2151 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DEBUG);}
break;
case 371:
#line 2156 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DECREMENT);}
break;
case 372:
#line 2158 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 373:
#line 2161 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 374:
#line 2165 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DEFAULT);}
break;
case 375:
#line 2166 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 376:
#line 2168 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 377:
#line 2173 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DEREFOF);}
break;
case 378:
#line 2175 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 379:
#line 2178 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 380:
#line 2183 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DEVICE);}
break;
case 381:
#line 2186 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,2,
                                        TrSetOpFlags (yystack.l_mark[-4].n, OP_IS_NAME_DECLARATION),yystack.l_mark[-1].n);}
break;
case 382:
#line 2190 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 383:
#line 2195 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DIVIDE);}
break;
case 384:
#line 2200 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,4,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 385:
#line 2203 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 386:
#line 2210 "aslcompiler.y"
	{yyval.n = TrSetOpIntegerValue (PARSEOP_EISAID, yystack.l_mark[-1].n);}
break;
case 387:
#line 2213 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 388:
#line 2217 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (yystack.l_mark[-1].n,yystack.l_mark[0].n);}
break;
case 389:
#line 2221 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 390:
#line 2223 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ELSE);}
break;
case 391:
#line 2224 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,1,yystack.l_mark[-2].n);}
break;
case 392:
#line 2227 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 393:
#line 2230 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 394:
#line 2233 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ELSE);}
break;
case 395:
#line 2234 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_IF);}
break;
case 396:
#line 2236 "aslcompiler.y"
	{TrLinkOpChildren (yystack.l_mark[-4].n,2,yystack.l_mark[-5].n,yystack.l_mark[-1].n);}
break;
case 397:
#line 2237 "aslcompiler.y"
	{TrLinkPeerOp (yystack.l_mark[-6].n,yystack.l_mark[0].n);}
break;
case 398:
#line 2238 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-9].n,1,yystack.l_mark[-7].n);}
break;
case 399:
#line 2242 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 400:
#line 2245 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 401:
#line 2250 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_EVENT);}
break;
case 402:
#line 2252 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,
                                        TrSetOpFlags (yystack.l_mark[-1].n, OP_IS_NAME_DECLARATION));}
break;
case 403:
#line 2256 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 404:
#line 2266 "aslcompiler.y"
	{yyval.n = TrCreateOp (PARSEOP_EXTERNAL,4,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 405:
#line 2269 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 406:
#line 2274 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_FATAL);}
break;
case 407:
#line 2278 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,3,yystack.l_mark[-4].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 408:
#line 2281 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 409:
#line 2286 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_FIELD);}
break;
case 410:
#line 2292 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-11].n,5,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 411:
#line 2296 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 412:
#line 2301 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_FINDSETLEFTBIT);}
break;
case 413:
#line 2304 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 414:
#line 2307 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 415:
#line 2312 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_FINDSETRIGHTBIT);}
break;
case 416:
#line 2315 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 417:
#line 2318 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 418:
#line 2324 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_WHILE);}
break;
case 419:
#line 2325 "aslcompiler.y"
	{}
break;
case 420:
#line 2327 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (yystack.l_mark[-5].n,yystack.l_mark[-6].n);
                                            TrSetOpParent (yystack.l_mark[0].n,yystack.l_mark[-6].n);}
break;
case 421:
#line 2330 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-11].n,2,yystack.l_mark[-7].n,yystack.l_mark[-1].n);}
break;
case 422:
#line 2331 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (yystack.l_mark[-2].n,yystack.l_mark[-6].n);
                                        yyval.n = yystack.l_mark[-5].n;}
break;
case 423:
#line 2336 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_INTEGER, 1);}
break;
case 424:
#line 2337 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 425:
#line 2342 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_FPRINTF);}
break;
case 426:
#line 2346 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,3,yystack.l_mark[-4].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 427:
#line 2349 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 428:
#line 2354 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_FROMBCD);}
break;
case 429:
#line 2357 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 430:
#line 2360 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 431:
#line 2365 "aslcompiler.y"
	{COMMENT_CAPTURE_OFF; yyval.n = TrCreateLeafOp (PARSEOP_METHOD); }
break;
case 432:
#line 2369 "aslcompiler.y"
	{COMMENT_CAPTURE_ON; }
break;
case 433:
#line 2370 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-8].n,7,
                                        TrSetOpFlags (yystack.l_mark[-7].n, OP_IS_NAME_DECLARATION),
                                        TrCreateValuedLeafOp (PARSEOP_BYTECONST, 0),
                                        TrCreateLeafOp (PARSEOP_SERIALIZERULE_NOTSERIAL),
                                        TrCreateValuedLeafOp (PARSEOP_BYTECONST, 0),yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-1].n);}
break;
case 434:
#line 2377 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 435:
#line 2382 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_IF);}
break;
case 436:
#line 2385 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,2,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 437:
#line 2389 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 438:
#line 2396 "aslcompiler.y"
	{yyval.n = TrSetOpIntegerValue (PARSEOP_INCLUDE, yystack.l_mark[-1].n);
                                        FlOpenIncludeFile (yystack.l_mark[-1].n);}
break;
case 439:
#line 2401 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_INCLUDE_END);
                                        TrSetOpCurrentFilename (yyval.n);}
break;
case 440:
#line 2407 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_INCREMENT);}
break;
case 441:
#line 2409 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 442:
#line 2412 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 443:
#line 2417 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_INDEXFIELD);}
break;
case 444:
#line 2424 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-12].n,6,yystack.l_mark[-11].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 445:
#line 2428 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 446:
#line 2433 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_INDEX);}
break;
case 447:
#line 2437 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 448:
#line 2440 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 449:
#line 2445 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LAND);}
break;
case 450:
#line 2448 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 451:
#line 2451 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 452:
#line 2456 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LEQUAL);}
break;
case 453:
#line 2459 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 454:
#line 2462 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 455:
#line 2467 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LLESS);}
break;
case 456:
#line 2470 "aslcompiler.y"
	{yyval.n = TrCreateOp (PARSEOP_LNOT, 1,
                                        TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n));}
break;
case 457:
#line 2474 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 458:
#line 2479 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LGREATER);}
break;
case 459:
#line 2482 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 460:
#line 2485 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 461:
#line 2490 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LGREATER);}
break;
case 462:
#line 2493 "aslcompiler.y"
	{yyval.n = TrCreateOp (PARSEOP_LNOT, 1,
                                        TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n));}
break;
case 463:
#line 2497 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 464:
#line 2502 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LLESS);}
break;
case 465:
#line 2505 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 466:
#line 2508 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 467:
#line 2513 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LEQUAL);}
break;
case 468:
#line 2516 "aslcompiler.y"
	{yyval.n = TrCreateOp (PARSEOP_LNOT, 1,
                                        TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n));}
break;
case 469:
#line 2520 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 470:
#line 2525 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LNOT);}
break;
case 471:
#line 2527 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 472:
#line 2530 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 473:
#line 2535 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LOADTABLE);}
break;
case 474:
#line 2542 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-7].n,6,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 475:
#line 2545 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 476:
#line 2550 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LOAD);}
break;
case 477:
#line 2553 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 478:
#line 2556 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 479:
#line 2560 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LOCAL0);}
break;
case 480:
#line 2561 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LOCAL1);}
break;
case 481:
#line 2562 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LOCAL2);}
break;
case 482:
#line 2563 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LOCAL3);}
break;
case 483:
#line 2564 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LOCAL4);}
break;
case 484:
#line 2565 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LOCAL5);}
break;
case 485:
#line 2566 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LOCAL6);}
break;
case 486:
#line 2567 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LOCAL7);}
break;
case 487:
#line 2572 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LOR);}
break;
case 488:
#line 2575 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 489:
#line 2578 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 490:
#line 2583 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MATCH);}
break;
case 491:
#line 2590 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-9].n,6,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 492:
#line 2593 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 493:
#line 2598 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_METHOD); COMMENT_CAPTURE_OFF;}
break;
case 494:
#line 2600 "aslcompiler.y"
	{UtCheckIntegerRange (yystack.l_mark[0].n, 0, 7);}
break;
case 495:
#line 2605 "aslcompiler.y"
	{COMMENT_CAPTURE_ON;}
break;
case 496:
#line 2606 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-12].n,7,
                                        TrSetOpFlags (yystack.l_mark[-11].n, OP_IS_NAME_DECLARATION),
                                        yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-7].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-1].n);}
break;
case 497:
#line 2611 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 498:
#line 2616 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MID);}
break;
case 499:
#line 2621 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,4,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 500:
#line 2624 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 501:
#line 2629 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MOD);}
break;
case 502:
#line 2633 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 503:
#line 2636 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 504:
#line 2641 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MULTIPLY);}
break;
case 505:
#line 2645 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 506:
#line 2648 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 507:
#line 2653 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MUTEX);}
break;
case 508:
#line 2656 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,2,
                                        TrSetOpFlags (yystack.l_mark[-3].n, OP_IS_NAME_DECLARATION),yystack.l_mark[-1].n);}
break;
case 509:
#line 2660 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 510:
#line 2665 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_NAME);}
break;
case 511:
#line 2668 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,2,
                                        TrSetOpFlags (yystack.l_mark[-3].n, OP_IS_NAME_DECLARATION),yystack.l_mark[-1].n);}
break;
case 512:
#line 2672 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 513:
#line 2677 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_NAND);}
break;
case 514:
#line 2681 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 515:
#line 2684 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 516:
#line 2688 "aslcompiler.y"
	{yyval.n = TrCreateOp (PARSEOP_NOOP, 0);}
break;
case 517:
#line 2693 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_NOR);}
break;
case 518:
#line 2697 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 519:
#line 2700 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 520:
#line 2705 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_NOTIFY);}
break;
case 521:
#line 2708 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 522:
#line 2711 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 523:
#line 2716 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_NOT);}
break;
case 524:
#line 2719 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 525:
#line 2722 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 526:
#line 2727 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE);}
break;
case 527:
#line 2729 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 528:
#line 2732 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 529:
#line 2739 "aslcompiler.y"
	{yyval.n = TrCreateOp (PARSEOP_OFFSET,1,yystack.l_mark[-1].n);}
break;
case 530:
#line 2742 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 531:
#line 2747 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OPERATIONREGION);}
break;
case 532:
#line 2752 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-6].n,4,
                                        TrSetOpFlags (yystack.l_mark[-5].n, OP_IS_NAME_DECLARATION),
                                        yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 533:
#line 2757 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 534:
#line 2761 "aslcompiler.y"
	{}
break;
case 535:
#line 2762 "aslcompiler.y"
	{yyval.n = UtCheckIntegerRange (yystack.l_mark[0].n, 0x80, 0xFF);}
break;
case 536:
#line 2767 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OR);}
break;
case 537:
#line 2771 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 538:
#line 2774 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 539:
#line 2778 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_VAR_PACKAGE);}
break;
case 540:
#line 2780 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,2,yystack.l_mark[-3].n,yystack.l_mark[-1].n);}
break;
case 541:
#line 2784 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_POWERRESOURCE);}
break;
case 542:
#line 2789 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-9].n,4,
                                        TrSetOpFlags (yystack.l_mark[-8].n, OP_IS_NAME_DECLARATION),
                                        yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 543:
#line 2794 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 544:
#line 2799 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PRINTF);}
break;
case 545:
#line 2802 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 546:
#line 2805 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 547:
#line 2809 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 548:
#line 2810 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 549:
#line 2812 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 550:
#line 2817 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PROCESSOR);}
break;
case 551:
#line 2823 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-9].n,5,
                                        TrSetOpFlags (yystack.l_mark[-8].n, OP_IS_NAME_DECLARATION),
                                        yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 552:
#line 2828 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 553:
#line 2833 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DATABUFFER);}
break;
case 554:
#line 2836 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,2,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 555:
#line 2839 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 556:
#line 2848 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_REFOF);}
break;
case 557:
#line 2850 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,
                                        TrSetOpFlags (yystack.l_mark[-1].n, OP_IS_TARGET));}
break;
case 558:
#line 2854 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 559:
#line 2859 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_RELEASE);}
break;
case 560:
#line 2861 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 561:
#line 2864 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 562:
#line 2869 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_RESET);}
break;
case 563:
#line 2871 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 564:
#line 2874 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 565:
#line 2879 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_RETURN);}
break;
case 566:
#line 2881 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 567:
#line 2882 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (
                                        TrCreateLeafOp (PARSEOP_RETURN),1,
                                        TrSetOpFlags (TrCreateLeafOp (PARSEOP_ZERO),
                                            OP_IS_NULL_RETURN));}
break;
case 568:
#line 2888 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 569:
#line 2893 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SCOPE);}
break;
case 570:
#line 2896 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,2,
                                        TrSetOpFlags (yystack.l_mark[-4].n, OP_IS_NAME_DECLARATION),yystack.l_mark[-1].n);}
break;
case 571:
#line 2900 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 572:
#line 2905 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SHIFTLEFT);}
break;
case 573:
#line 2909 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 574:
#line 2912 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 575:
#line 2917 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SHIFTRIGHT);}
break;
case 576:
#line 2921 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 577:
#line 2924 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 578:
#line 2929 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SIGNAL);}
break;
case 579:
#line 2931 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 580:
#line 2934 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 581:
#line 2939 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SIZEOF);}
break;
case 582:
#line 2941 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 583:
#line 2944 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 584:
#line 2949 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SLEEP);}
break;
case 585:
#line 2951 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 586:
#line 2954 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 587:
#line 2959 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_STALL);}
break;
case 588:
#line 2961 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 589:
#line 2964 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 590:
#line 2969 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_STORE);}
break;
case 591:
#line 2972 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,2,yystack.l_mark[-3].n,
                                            TrSetOpFlags (yystack.l_mark[-1].n, OP_IS_TARGET));}
break;
case 592:
#line 2976 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 593:
#line 2981 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SUBTRACT);}
break;
case 594:
#line 2985 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 595:
#line 2988 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 596:
#line 2993 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SWITCH);}
break;
case 597:
#line 2996 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,2,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 598:
#line 2999 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 599:
#line 3004 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_THERMALZONE);}
break;
case 600:
#line 3007 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,2,
                                        TrSetOpFlags (yystack.l_mark[-4].n, OP_IS_NAME_DECLARATION),yystack.l_mark[-1].n);}
break;
case 601:
#line 3011 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 602:
#line 3016 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_TIMER);}
break;
case 603:
#line 3017 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,0);}
break;
case 604:
#line 3018 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (
                                        TrCreateLeafOp (PARSEOP_TIMER),0);}
break;
case 605:
#line 3022 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 606:
#line 3027 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_TOBCD);}
break;
case 607:
#line 3030 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 608:
#line 3033 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 609:
#line 3038 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_TOBUFFER);}
break;
case 610:
#line 3041 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 611:
#line 3044 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 612:
#line 3049 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_TODECIMALSTRING);}
break;
case 613:
#line 3052 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 614:
#line 3055 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 615:
#line 3060 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_TOHEXSTRING);}
break;
case 616:
#line 3063 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 617:
#line 3066 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 618:
#line 3071 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_TOINTEGER);}
break;
case 619:
#line 3074 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 620:
#line 3077 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 621:
#line 3082 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_TOPLD);}
break;
case 622:
#line 3084 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 623:
#line 3087 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 624:
#line 3091 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 625:
#line 3093 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[0].n);}
break;
case 626:
#line 3095 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[0].n);}
break;
case 628:
#line 3099 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (yystack.l_mark[-4].n,TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[0].n));}
break;
case 629:
#line 3102 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (yystack.l_mark[-4].n,TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[0].n));}
break;
case 630:
#line 3108 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_TOSTRING);}
break;
case 631:
#line 3112 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 632:
#line 3115 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 633:
#line 3122 "aslcompiler.y"
	{yyval.n = TrSetOpIntegerValue (PARSEOP_TOUUID, yystack.l_mark[-1].n);}
break;
case 634:
#line 3125 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 635:
#line 3130 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_UNICODE);}
break;
case 636:
#line 3132 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,2,0,yystack.l_mark[-1].n);}
break;
case 637:
#line 3135 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 638:
#line 3140 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_UNLOAD);}
break;
case 639:
#line 3142 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 640:
#line 3145 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 641:
#line 3150 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_WAIT);}
break;
case 642:
#line 3153 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-3].n,2,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 643:
#line 3156 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 644:
#line 3161 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_XOR);}
break;
case 645:
#line 3165 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,3,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 646:
#line 3168 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 647:
#line 3173 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_WHILE);}
break;
case 648:
#line 3176 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,2,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 649:
#line 3179 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 650:
#line 3233 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LNOT);}
break;
case 651:
#line 3234 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,1,yystack.l_mark[0].n);}
break;
case 652:
#line 3235 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_NOT);}
break;
case 653:
#line 3236 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,2,yystack.l_mark[0].n,TrCreateNullTargetOp ());}
break;
case 654:
#line 3238 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_INCREMENT);}
break;
case 655:
#line 3239 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[0].n,1,yystack.l_mark[-2].n);}
break;
case 656:
#line 3240 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DECREMENT);}
break;
case 657:
#line 3241 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[0].n,1,yystack.l_mark[-2].n);}
break;
case 658:
#line 3245 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ADD);}
break;
case 659:
#line 3246 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,TrCreateNullTargetOp ());}
break;
case 660:
#line 3247 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DIVIDE);}
break;
case 661:
#line 3248 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,4,yystack.l_mark[-3].n,yystack.l_mark[0].n,TrCreateNullTargetOp (),
                                            TrCreateNullTargetOp ());}
break;
case 662:
#line 3250 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MOD);}
break;
case 663:
#line 3251 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,TrCreateNullTargetOp ());}
break;
case 664:
#line 3252 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MULTIPLY);}
break;
case 665:
#line 3253 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,TrCreateNullTargetOp ());}
break;
case 666:
#line 3254 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SHIFTLEFT);}
break;
case 667:
#line 3255 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,TrCreateNullTargetOp ());}
break;
case 668:
#line 3256 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SHIFTRIGHT);}
break;
case 669:
#line 3257 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,TrCreateNullTargetOp ());}
break;
case 670:
#line 3258 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SUBTRACT);}
break;
case 671:
#line 3259 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,TrCreateNullTargetOp ());}
break;
case 672:
#line 3261 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_AND);}
break;
case 673:
#line 3262 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,TrCreateNullTargetOp ());}
break;
case 674:
#line 3263 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OR);}
break;
case 675:
#line 3264 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,TrCreateNullTargetOp ());}
break;
case 676:
#line 3265 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_XOR);}
break;
case 677:
#line 3266 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,TrCreateNullTargetOp ());}
break;
case 678:
#line 3268 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LGREATER);}
break;
case 679:
#line 3269 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,2,yystack.l_mark[-3].n,yystack.l_mark[0].n);}
break;
case 680:
#line 3270 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LGREATEREQUAL);}
break;
case 681:
#line 3271 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,2,yystack.l_mark[-3].n,yystack.l_mark[0].n);}
break;
case 682:
#line 3272 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LLESS);}
break;
case 683:
#line 3273 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,2,yystack.l_mark[-3].n,yystack.l_mark[0].n);}
break;
case 684:
#line 3274 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LLESSEQUAL);}
break;
case 685:
#line 3275 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,2,yystack.l_mark[-3].n,yystack.l_mark[0].n);}
break;
case 686:
#line 3277 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LEQUAL);}
break;
case 687:
#line 3278 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,2,yystack.l_mark[-3].n,yystack.l_mark[0].n);}
break;
case 688:
#line 3279 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LNOTEQUAL);}
break;
case 689:
#line 3280 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,2,yystack.l_mark[-3].n,yystack.l_mark[0].n);}
break;
case 690:
#line 3282 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LAND);}
break;
case 691:
#line 3283 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,2,yystack.l_mark[-3].n,yystack.l_mark[0].n);}
break;
case 692:
#line 3284 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LOR);}
break;
case 693:
#line 3285 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,2,yystack.l_mark[-3].n,yystack.l_mark[0].n);}
break;
case 694:
#line 3291 "aslcompiler.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 696:
#line 3312 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_INDEX);
                                        TrLinkOpChildren (yyval.n,3,yystack.l_mark[-3].n,yystack.l_mark[-1].n,TrCreateNullTargetOp ());}
break;
case 697:
#line 3330 "aslcompiler.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 698:
#line 3336 "aslcompiler.y"
	{yyval.n = TrCreateAssignmentOp (yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 699:
#line 3344 "aslcompiler.y"
	{yyval.n = TrCreateAssignmentOp (yystack.l_mark[-3].n, yystack.l_mark[0].n);}
break;
case 700:
#line 3348 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ADD);}
break;
case 701:
#line 3349 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,
                                            TrSetOpFlags (TrCreateTargetOp (yystack.l_mark[-3].n, NULL), OP_IS_TARGET));}
break;
case 702:
#line 3352 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DIVIDE);}
break;
case 703:
#line 3353 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,4,yystack.l_mark[-3].n,yystack.l_mark[0].n,TrCreateNullTargetOp (),
                                            TrSetOpFlags (TrCreateTargetOp (yystack.l_mark[-3].n, NULL), OP_IS_TARGET));}
break;
case 704:
#line 3356 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MOD);}
break;
case 705:
#line 3357 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,
                                            TrSetOpFlags (TrCreateTargetOp (yystack.l_mark[-3].n, NULL), OP_IS_TARGET));}
break;
case 706:
#line 3360 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MULTIPLY);}
break;
case 707:
#line 3361 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,
                                            TrSetOpFlags (TrCreateTargetOp (yystack.l_mark[-3].n, NULL), OP_IS_TARGET));}
break;
case 708:
#line 3364 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SHIFTLEFT);}
break;
case 709:
#line 3365 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,
                                            TrSetOpFlags (TrCreateTargetOp (yystack.l_mark[-3].n, NULL), OP_IS_TARGET));}
break;
case 710:
#line 3368 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SHIFTRIGHT);}
break;
case 711:
#line 3369 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,
                                            TrSetOpFlags (TrCreateTargetOp (yystack.l_mark[-3].n, NULL), OP_IS_TARGET));}
break;
case 712:
#line 3372 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SUBTRACT);}
break;
case 713:
#line 3373 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,
                                            TrSetOpFlags (TrCreateTargetOp (yystack.l_mark[-3].n, NULL), OP_IS_TARGET));}
break;
case 714:
#line 3376 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_AND);}
break;
case 715:
#line 3377 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,
                                            TrSetOpFlags (TrCreateTargetOp (yystack.l_mark[-3].n, NULL), OP_IS_TARGET));}
break;
case 716:
#line 3380 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OR);}
break;
case 717:
#line 3381 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,
                                            TrSetOpFlags (TrCreateTargetOp (yystack.l_mark[-3].n, NULL), OP_IS_TARGET));}
break;
case 718:
#line 3384 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_XOR);}
break;
case 719:
#line 3385 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-1].n,3,yystack.l_mark[-3].n,yystack.l_mark[0].n,
                                            TrSetOpFlags (TrCreateTargetOp (yystack.l_mark[-3].n, NULL), OP_IS_TARGET));}
break;
case 720:
#line 3398 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSATTRIB_BLOCK);}
break;
case 721:
#line 3399 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSATTRIB_BLOCK_CALL);}
break;
case 722:
#line 3400 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSATTRIB_BYTE);}
break;
case 723:
#line 3401 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSATTRIB_QUICK );}
break;
case 724:
#line 3402 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSATTRIB_SND_RCV);}
break;
case 725:
#line 3403 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSATTRIB_WORD);}
break;
case 726:
#line 3404 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSATTRIB_WORD_CALL);}
break;
case 727:
#line 3406 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSATTRIB_MULTIBYTE);}
break;
case 728:
#line 3408 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 729:
#line 3410 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSATTRIB_RAW_BYTES);}
break;
case 730:
#line 3412 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 731:
#line 3414 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSATTRIB_RAW_PROCESS);}
break;
case 732:
#line 3416 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-2].n,1,yystack.l_mark[-1].n);}
break;
case 733:
#line 3420 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSTYPE_ANY);}
break;
case 734:
#line 3421 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSTYPE_BYTE);}
break;
case 735:
#line 3422 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSTYPE_WORD);}
break;
case 736:
#line 3423 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSTYPE_DWORD);}
break;
case 737:
#line 3424 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSTYPE_QWORD);}
break;
case 738:
#line 3425 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ACCESSTYPE_BUF);}
break;
case 739:
#line 3429 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ADDRESSINGMODE_7BIT);}
break;
case 740:
#line 3430 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ADDRESSINGMODE_10BIT);}
break;
case 741:
#line 3434 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ADDRESSTYPE_MEMORY);}
break;
case 742:
#line 3435 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ADDRESSTYPE_RESERVED);}
break;
case 743:
#line 3436 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ADDRESSTYPE_NVS);}
break;
case 744:
#line 3437 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ADDRESSTYPE_ACPI);}
break;
case 745:
#line 3441 "aslcompiler.y"
	{yyval.n = UtCheckIntegerRange (yystack.l_mark[0].n, 0x0A, 0xFF);}
break;
case 746:
#line 3442 "aslcompiler.y"
	{}
break;
case 747:
#line 3446 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_BITSPERBYTE_FIVE);}
break;
case 748:
#line 3447 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_BITSPERBYTE_SIX);}
break;
case 749:
#line 3448 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_BITSPERBYTE_SEVEN);}
break;
case 750:
#line 3449 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_BITSPERBYTE_EIGHT);}
break;
case 751:
#line 3450 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_BITSPERBYTE_NINE);}
break;
case 752:
#line 3454 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_CLOCKPHASE_FIRST);}
break;
case 753:
#line 3455 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_CLOCKPHASE_SECOND);}
break;
case 754:
#line 3459 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_CLOCKPOLARITY_LOW);}
break;
case 755:
#line 3460 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_CLOCKPOLARITY_HIGH);}
break;
case 756:
#line 3464 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DECODETYPE_POS);}
break;
case 757:
#line 3465 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DECODETYPE_SUB);}
break;
case 758:
#line 3469 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DEVICEPOLARITY_LOW);}
break;
case 759:
#line 3470 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DEVICEPOLARITY_HIGH);}
break;
case 760:
#line 3474 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DMATYPE_A);}
break;
case 761:
#line 3475 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DMATYPE_COMPATIBILITY);}
break;
case 762:
#line 3476 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DMATYPE_B);}
break;
case 763:
#line 3477 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DMATYPE_F);}
break;
case 764:
#line 3481 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ENDIAN_LITTLE);}
break;
case 765:
#line 3482 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ENDIAN_BIG);}
break;
case 766:
#line 3486 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_FLOWCONTROL_HW);}
break;
case 767:
#line 3487 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_FLOWCONTROL_NONE);}
break;
case 768:
#line 3488 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_FLOWCONTROL_SW);}
break;
case 769:
#line 3492 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_INTLEVEL_ACTIVEBOTH);}
break;
case 770:
#line 3493 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_INTLEVEL_ACTIVEHIGH);}
break;
case 771:
#line 3494 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_INTLEVEL_ACTIVELOW);}
break;
case 772:
#line 3498 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_INTTYPE_EDGE);}
break;
case 773:
#line 3499 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_INTTYPE_LEVEL);}
break;
case 774:
#line 3503 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_IODECODETYPE_16);}
break;
case 775:
#line 3504 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_IODECODETYPE_10);}
break;
case 776:
#line 3508 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_IORESTRICT_IN);}
break;
case 777:
#line 3509 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_IORESTRICT_OUT);}
break;
case 778:
#line 3510 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_IORESTRICT_NONE);}
break;
case 779:
#line 3511 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_IORESTRICT_PRESERVE);}
break;
case 780:
#line 3515 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LOCKRULE_LOCK);}
break;
case 781:
#line 3516 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_LOCKRULE_NOLOCK);}
break;
case 782:
#line 3520 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MATCHTYPE_MTR);}
break;
case 783:
#line 3521 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MATCHTYPE_MEQ);}
break;
case 784:
#line 3522 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MATCHTYPE_MLE);}
break;
case 785:
#line 3523 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MATCHTYPE_MLT);}
break;
case 786:
#line 3524 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MATCHTYPE_MGE);}
break;
case 787:
#line 3525 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MATCHTYPE_MGT);}
break;
case 788:
#line 3529 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MAXTYPE_FIXED);}
break;
case 789:
#line 3530 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MAXTYPE_NOTFIXED);}
break;
case 790:
#line 3534 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MEMTYPE_CACHEABLE);}
break;
case 791:
#line 3535 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MEMTYPE_WRITECOMBINING);}
break;
case 792:
#line 3536 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MEMTYPE_PREFETCHABLE);}
break;
case 793:
#line 3537 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MEMTYPE_NONCACHEABLE);}
break;
case 794:
#line 3541 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MINTYPE_FIXED);}
break;
case 795:
#line 3542 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MINTYPE_NOTFIXED);}
break;
case 796:
#line 3546 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_UNK);}
break;
case 797:
#line 3547 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_INT);}
break;
case 798:
#line 3548 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_STR);}
break;
case 799:
#line 3549 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_BUF);}
break;
case 800:
#line 3550 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_PKG);}
break;
case 801:
#line 3551 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_FLD);}
break;
case 802:
#line 3552 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_DEV);}
break;
case 803:
#line 3553 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_EVT);}
break;
case 804:
#line 3554 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_MTH);}
break;
case 805:
#line 3555 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_MTX);}
break;
case 806:
#line 3556 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_OPR);}
break;
case 807:
#line 3557 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_POW);}
break;
case 808:
#line 3558 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_PRO);}
break;
case 809:
#line 3559 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_THZ);}
break;
case 810:
#line 3560 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_BFF);}
break;
case 811:
#line 3561 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_OBJECTTYPE_DDB);}
break;
case 812:
#line 3565 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PARITYTYPE_SPACE);}
break;
case 813:
#line 3566 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PARITYTYPE_MARK);}
break;
case 814:
#line 3567 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PARITYTYPE_ODD);}
break;
case 815:
#line 3568 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PARITYTYPE_EVEN);}
break;
case 816:
#line 3569 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PARITYTYPE_NONE);}
break;
case 817:
#line 3573 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 818:
#line 3574 "aslcompiler.y"
	{yyval.n = UtCheckIntegerRange (yystack.l_mark[0].n, 0x80, 0xFF);}
break;
case 819:
#line 3578 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PIN_NOPULL);}
break;
case 820:
#line 3579 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PIN_PULLDOWN);}
break;
case 821:
#line 3580 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PIN_PULLUP);}
break;
case 822:
#line 3581 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PIN_PULLDEFAULT);}
break;
case 823:
#line 3585 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_REVISION);}
break;
case 824:
#line 3586 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_IGNORECOLOR);}
break;
case 825:
#line 3587 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_RED);}
break;
case 826:
#line 3588 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_GREEN);}
break;
case 827:
#line 3589 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_BLUE);}
break;
case 828:
#line 3590 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_WIDTH);}
break;
case 829:
#line 3591 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_HEIGHT);}
break;
case 830:
#line 3592 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_USERVISIBLE);}
break;
case 831:
#line 3593 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_DOCK);}
break;
case 832:
#line 3594 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_LID);}
break;
case 833:
#line 3595 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_PANEL);}
break;
case 834:
#line 3596 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_VERTICALPOSITION);}
break;
case 835:
#line 3597 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_HORIZONTALPOSITION);}
break;
case 836:
#line 3598 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_SHAPE);}
break;
case 837:
#line 3599 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_GROUPORIENTATION);}
break;
case 838:
#line 3600 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_GROUPTOKEN);}
break;
case 839:
#line 3601 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_GROUPPOSITION);}
break;
case 840:
#line 3602 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_BAY);}
break;
case 841:
#line 3603 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_EJECTABLE);}
break;
case 842:
#line 3604 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_EJECTREQUIRED);}
break;
case 843:
#line 3605 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_CABINETNUMBER);}
break;
case 844:
#line 3606 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_CARDCAGENUMBER);}
break;
case 845:
#line 3607 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_REFERENCE);}
break;
case 846:
#line 3608 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_ROTATION);}
break;
case 847:
#line 3609 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_ORDER);}
break;
case 848:
#line 3610 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_RESERVED);}
break;
case 849:
#line 3611 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_VERTICALOFFSET);}
break;
case 850:
#line 3612 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PLD_HORIZONTALOFFSET);}
break;
case 851:
#line 3616 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_RANGETYPE_ISAONLY);}
break;
case 852:
#line 3617 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_RANGETYPE_NONISAONLY);}
break;
case 853:
#line 3618 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_RANGETYPE_ENTIRE);}
break;
case 854:
#line 3622 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_REGIONSPACE_IO);}
break;
case 855:
#line 3623 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_REGIONSPACE_MEM);}
break;
case 856:
#line 3624 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_REGIONSPACE_PCI);}
break;
case 857:
#line 3625 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_REGIONSPACE_EC);}
break;
case 858:
#line 3626 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_REGIONSPACE_SMBUS);}
break;
case 859:
#line 3627 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_REGIONSPACE_CMOS);}
break;
case 860:
#line 3628 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_REGIONSPACE_PCIBAR);}
break;
case 861:
#line 3629 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_REGIONSPACE_IPMI);}
break;
case 862:
#line 3630 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_REGIONSPACE_GPIO);}
break;
case 863:
#line 3631 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_REGIONSPACE_GSBUS);}
break;
case 864:
#line 3632 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_REGIONSPACE_PCC);}
break;
case 865:
#line 3633 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_REGIONSPACE_FFIXEDHW);}
break;
case 866:
#line 3637 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_RESOURCETYPE_CONSUMER);}
break;
case 867:
#line 3638 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_RESOURCETYPE_PRODUCER);}
break;
case 868:
#line 3642 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SERIALIZERULE_SERIAL);}
break;
case 869:
#line 3643 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SERIALIZERULE_NOTSERIAL);}
break;
case 870:
#line 3647 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SHARETYPE_SHARED);}
break;
case 871:
#line 3648 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SHARETYPE_EXCLUSIVE);}
break;
case 872:
#line 3649 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SHARETYPE_SHAREDWAKE);}
break;
case 873:
#line 3650 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SHARETYPE_EXCLUSIVEWAKE);}
break;
case 874:
#line 3654 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SLAVEMODE_CONTROLLERINIT);}
break;
case 875:
#line 3655 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SLAVEMODE_DEVICEINIT);}
break;
case 876:
#line 3659 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_STOPBITS_TWO);}
break;
case 877:
#line 3660 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_STOPBITS_ONEPLUSHALF);}
break;
case 878:
#line 3661 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_STOPBITS_ONE);}
break;
case 879:
#line 3662 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_STOPBITS_ZERO);}
break;
case 880:
#line 3666 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_TRANSLATIONTYPE_SPARSE);}
break;
case 881:
#line 3667 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_TRANSLATIONTYPE_DENSE);}
break;
case 882:
#line 3671 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_TYPE_TRANSLATION);}
break;
case 883:
#line 3672 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_TYPE_STATIC);}
break;
case 884:
#line 3676 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_UPDATERULE_PRESERVE);}
break;
case 885:
#line 3677 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_UPDATERULE_ONES);}
break;
case 886:
#line 3678 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_UPDATERULE_ZEROS);}
break;
case 887:
#line 3682 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_WIREMODE_FOUR);}
break;
case 888:
#line 3683 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_WIREMODE_THREE);}
break;
case 889:
#line 3687 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_XFERSIZE_8,   0);}
break;
case 890:
#line 3688 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_XFERSIZE_16,  1);}
break;
case 891:
#line 3689 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_XFERSIZE_32,  2);}
break;
case 892:
#line 3690 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_XFERSIZE_64,  3);}
break;
case 893:
#line 3691 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_XFERSIZE_128, 4);}
break;
case 894:
#line 3692 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (PARSEOP_XFERSIZE_256, 5);}
break;
case 895:
#line 3696 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_XFERTYPE_8);}
break;
case 896:
#line 3697 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_XFERTYPE_8_16);}
break;
case 897:
#line 3698 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_XFERTYPE_16);}
break;
case 898:
#line 3715 "aslcompiler.y"
	{COMMENT_CAPTURE_OFF;}
break;
case 899:
#line 3718 "aslcompiler.y"
	{yyval.n = TrCreateOp (PARSEOP_RESOURCETEMPLATE,4,
                                          TrCreateLeafOp (PARSEOP_DEFAULT_ARG),
                                          TrCreateLeafOp (PARSEOP_DEFAULT_ARG),
                                          yystack.l_mark[-1].n,
                                          TrCreateLeafOp (PARSEOP_ENDTAG));
                                     COMMENT_CAPTURE_ON;}
break;
case 900:
#line 3727 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 901:
#line 3729 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 902:
#line 3733 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 903:
#line 3735 "aslcompiler.y"
	{yyval.n = TrLinkPeerOp (yystack.l_mark[-1].n,yystack.l_mark[0].n);}
break;
case 904:
#line 3739 "aslcompiler.y"
	{}
break;
case 905:
#line 3740 "aslcompiler.y"
	{}
break;
case 906:
#line 3741 "aslcompiler.y"
	{}
break;
case 907:
#line 3742 "aslcompiler.y"
	{}
break;
case 908:
#line 3743 "aslcompiler.y"
	{}
break;
case 909:
#line 3744 "aslcompiler.y"
	{}
break;
case 910:
#line 3745 "aslcompiler.y"
	{}
break;
case 911:
#line 3746 "aslcompiler.y"
	{}
break;
case 912:
#line 3747 "aslcompiler.y"
	{}
break;
case 913:
#line 3748 "aslcompiler.y"
	{}
break;
case 914:
#line 3749 "aslcompiler.y"
	{}
break;
case 915:
#line 3750 "aslcompiler.y"
	{}
break;
case 916:
#line 3751 "aslcompiler.y"
	{}
break;
case 917:
#line 3752 "aslcompiler.y"
	{}
break;
case 918:
#line 3753 "aslcompiler.y"
	{}
break;
case 919:
#line 3754 "aslcompiler.y"
	{}
break;
case 920:
#line 3755 "aslcompiler.y"
	{}
break;
case 921:
#line 3756 "aslcompiler.y"
	{}
break;
case 922:
#line 3757 "aslcompiler.y"
	{}
break;
case 923:
#line 3758 "aslcompiler.y"
	{}
break;
case 924:
#line 3759 "aslcompiler.y"
	{}
break;
case 925:
#line 3760 "aslcompiler.y"
	{}
break;
case 926:
#line 3761 "aslcompiler.y"
	{}
break;
case 927:
#line 3762 "aslcompiler.y"
	{}
break;
case 928:
#line 3763 "aslcompiler.y"
	{}
break;
case 929:
#line 3764 "aslcompiler.y"
	{}
break;
case 930:
#line 3765 "aslcompiler.y"
	{}
break;
case 931:
#line 3766 "aslcompiler.y"
	{}
break;
case 932:
#line 3767 "aslcompiler.y"
	{}
break;
case 933:
#line 3768 "aslcompiler.y"
	{}
break;
case 934:
#line 3769 "aslcompiler.y"
	{}
break;
case 935:
#line 3770 "aslcompiler.y"
	{}
break;
case 936:
#line 3771 "aslcompiler.y"
	{}
break;
case 937:
#line 3772 "aslcompiler.y"
	{}
break;
case 938:
#line 3773 "aslcompiler.y"
	{}
break;
case 939:
#line 3774 "aslcompiler.y"
	{}
break;
case 940:
#line 3775 "aslcompiler.y"
	{}
break;
case 941:
#line 3776 "aslcompiler.y"
	{}
break;
case 942:
#line 3777 "aslcompiler.y"
	{}
break;
case 943:
#line 3778 "aslcompiler.y"
	{}
break;
case 944:
#line 3779 "aslcompiler.y"
	{}
break;
case 945:
#line 3784 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DMA);}
break;
case 946:
#line 3790 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-9].n,5,yystack.l_mark[-8].n,yystack.l_mark[-7].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 947:
#line 3793 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 948:
#line 3798 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DWORDIO);}
break;
case 949:
#line 3814 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-21].n,15,
                                        yystack.l_mark[-20].n,yystack.l_mark[-19].n,yystack.l_mark[-18].n,yystack.l_mark[-17].n,yystack.l_mark[-16].n,yystack.l_mark[-14].n,yystack.l_mark[-12].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 950:
#line 3818 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 951:
#line 3823 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DWORDMEMORY);}
break;
case 952:
#line 3840 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-23].n,16,
                                        yystack.l_mark[-22].n,yystack.l_mark[-21].n,yystack.l_mark[-20].n,yystack.l_mark[-19].n,yystack.l_mark[-18].n,yystack.l_mark[-16].n,yystack.l_mark[-14].n,yystack.l_mark[-12].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 953:
#line 3844 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 954:
#line 3849 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_DWORDSPACE);}
break;
case 955:
#line 3850 "aslcompiler.y"
	{UtCheckIntegerRange (yystack.l_mark[0].n, 0xC0, 0xFF);}
break;
case 956:
#line 3864 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-22].n,14,
                                        yystack.l_mark[-21].n,yystack.l_mark[-19].n,yystack.l_mark[-18].n,yystack.l_mark[-17].n,yystack.l_mark[-16].n,yystack.l_mark[-14].n,yystack.l_mark[-12].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 957:
#line 3868 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 958:
#line 3874 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_ENDDEPENDENTFN);}
break;
case 959:
#line 3877 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 960:
#line 3882 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_EXTENDEDIO);}
break;
case 961:
#line 3897 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-20].n,14,
                                        yystack.l_mark[-19].n,yystack.l_mark[-18].n,yystack.l_mark[-17].n,yystack.l_mark[-16].n,yystack.l_mark[-15].n,yystack.l_mark[-13].n,yystack.l_mark[-11].n,yystack.l_mark[-9].n,yystack.l_mark[-7].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 962:
#line 3901 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 963:
#line 3906 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_EXTENDEDMEMORY);}
break;
case 964:
#line 3922 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-22].n,15,
                                        yystack.l_mark[-21].n,yystack.l_mark[-20].n,yystack.l_mark[-19].n,yystack.l_mark[-18].n,yystack.l_mark[-17].n,yystack.l_mark[-15].n,yystack.l_mark[-13].n,yystack.l_mark[-11].n,yystack.l_mark[-9].n,yystack.l_mark[-7].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 965:
#line 3926 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 966:
#line 3930 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_EXTENDEDSPACE);}
break;
case 967:
#line 3931 "aslcompiler.y"
	{UtCheckIntegerRange (yystack.l_mark[0].n, 0xC0, 0xFF);}
break;
case 968:
#line 3944 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-21].n,13,
                                        yystack.l_mark[-20].n,yystack.l_mark[-18].n,yystack.l_mark[-17].n,yystack.l_mark[-16].n,yystack.l_mark[-15].n,yystack.l_mark[-13].n,yystack.l_mark[-11].n,yystack.l_mark[-9].n,yystack.l_mark[-7].n,yystack.l_mark[-5].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 969:
#line 3948 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 970:
#line 3953 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_FIXEDDMA);}
break;
case 971:
#line 3958 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-6].n,4,yystack.l_mark[-5].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 972:
#line 3961 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 973:
#line 3966 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_FIXEDIO);}
break;
case 974:
#line 3970 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,3,yystack.l_mark[-4].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 975:
#line 3973 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 976:
#line 3978 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_GPIO_INT);}
break;
case 977:
#line 3990 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-17].n,11,
                                        yystack.l_mark[-16].n,yystack.l_mark[-14].n,yystack.l_mark[-13].n,yystack.l_mark[-11].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-7].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 978:
#line 3994 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 979:
#line 3999 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_GPIO_IO);}
break;
case 980:
#line 4011 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-16].n,11,
                                        yystack.l_mark[-15].n,yystack.l_mark[-13].n,yystack.l_mark[-12].n,yystack.l_mark[-11].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-7].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 981:
#line 4015 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 982:
#line 4020 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_I2C_SERIALBUS);}
break;
case 983:
#line 4030 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-12].n,10,
                                        yystack.l_mark[-11].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-7].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,
                                        TrCreateLeafOp (PARSEOP_DEFAULT_ARG),yystack.l_mark[-1].n);}
break;
case 984:
#line 4035 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 985:
#line 4040 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_I2C_SERIALBUS_V2);}
break;
case 986:
#line 4051 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-13].n,10,
                                        yystack.l_mark[-12].n,yystack.l_mark[-11].n,yystack.l_mark[-9].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 987:
#line 4055 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 988:
#line 4060 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_INTERRUPT);}
break;
case 989:
#line 4069 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-13].n,8,
                                        yystack.l_mark[-12].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-7].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 990:
#line 4073 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 991:
#line 4078 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_IO);}
break;
case 992:
#line 4085 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-11].n,6,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 993:
#line 4088 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 994:
#line 4093 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_IRQNOFLAGS);}
break;
case 995:
#line 4096 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,2,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 996:
#line 4099 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 997:
#line 4104 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_IRQ);}
break;
case 998:
#line 4110 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-9].n,5,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 999:
#line 4113 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1000:
#line 4118 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MEMORY24);}
break;
case 1001:
#line 4125 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-11].n,6,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 1002:
#line 4128 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1003:
#line 4133 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MEMORY32FIXED);}
break;
case 1004:
#line 4138 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-7].n,4,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 1005:
#line 4141 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1006:
#line 4146 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_MEMORY32);}
break;
case 1007:
#line 4153 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-11].n,6,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 1008:
#line 4156 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1009:
#line 4161 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PINCONFIG);}
break;
case 1010:
#line 4171 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-15].n,9,
                                        yystack.l_mark[-14].n,yystack.l_mark[-12].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-7].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 1011:
#line 4175 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1012:
#line 4180 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PINFUNCTION);}
break;
case 1013:
#line 4190 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-15].n,9,
                                        yystack.l_mark[-14].n,yystack.l_mark[-12].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-7].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 1014:
#line 4194 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1015:
#line 4199 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PINGROUP);}
break;
case 1016:
#line 4205 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-8].n,5,yystack.l_mark[-7].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 1017:
#line 4208 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1018:
#line 4213 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PINGROUPCONFIG);}
break;
case 1019:
#line 4223 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-14].n,9,
                                        yystack.l_mark[-13].n,yystack.l_mark[-11].n,yystack.l_mark[-9].n,yystack.l_mark[-7].n,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 1020:
#line 4227 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1021:
#line 4232 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_PINGROUPFUNCTION);}
break;
case 1022:
#line 4241 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-12].n,8,
                                        yystack.l_mark[-11].n,yystack.l_mark[-9].n,yystack.l_mark[-7].n,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 1023:
#line 4245 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1024:
#line 4250 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_QWORDIO);}
break;
case 1025:
#line 4266 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-21].n,15,
                                        yystack.l_mark[-20].n,yystack.l_mark[-19].n,yystack.l_mark[-18].n,yystack.l_mark[-17].n,yystack.l_mark[-16].n,yystack.l_mark[-14].n,yystack.l_mark[-12].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 1026:
#line 4270 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1027:
#line 4275 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_QWORDMEMORY);}
break;
case 1028:
#line 4292 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-23].n,16,
                                        yystack.l_mark[-22].n,yystack.l_mark[-21].n,yystack.l_mark[-20].n,yystack.l_mark[-19].n,yystack.l_mark[-18].n,yystack.l_mark[-16].n,yystack.l_mark[-14].n,yystack.l_mark[-12].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 1029:
#line 4296 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1030:
#line 4301 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_QWORDSPACE);}
break;
case 1031:
#line 4302 "aslcompiler.y"
	{UtCheckIntegerRange (yystack.l_mark[0].n, 0xC0, 0xFF);}
break;
case 1032:
#line 4316 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-22].n,14,
                                        yystack.l_mark[-21].n,yystack.l_mark[-19].n,yystack.l_mark[-18].n,yystack.l_mark[-17].n,yystack.l_mark[-16].n,yystack.l_mark[-14].n,yystack.l_mark[-12].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 1033:
#line 4320 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1034:
#line 4325 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_REGISTER);}
break;
case 1035:
#line 4332 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-10].n,6,yystack.l_mark[-9].n,yystack.l_mark[-7].n,yystack.l_mark[-5].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 1036:
#line 4335 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1037:
#line 4340 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SPI_SERIALBUS);}
break;
case 1038:
#line 4354 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-19].n,14,
                                        yystack.l_mark[-18].n,yystack.l_mark[-17].n,yystack.l_mark[-16].n,yystack.l_mark[-14].n,yystack.l_mark[-13].n,yystack.l_mark[-11].n,yystack.l_mark[-9].n,yystack.l_mark[-7].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,
                                        TrCreateLeafOp (PARSEOP_DEFAULT_ARG),yystack.l_mark[-1].n);}
break;
case 1039:
#line 4359 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1040:
#line 4364 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_SPI_SERIALBUS_V2);}
break;
case 1041:
#line 4379 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-20].n,14,
                                        yystack.l_mark[-19].n,yystack.l_mark[-18].n,yystack.l_mark[-17].n,yystack.l_mark[-15].n,yystack.l_mark[-14].n,yystack.l_mark[-12].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 1042:
#line 4383 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1043:
#line 4388 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_STARTDEPENDENTFN_NOPRI);}
break;
case 1044:
#line 4390 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-4].n,1,yystack.l_mark[-1].n);}
break;
case 1045:
#line 4393 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1046:
#line 4398 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_STARTDEPENDENTFN);}
break;
case 1047:
#line 4402 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-7].n,3,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 1048:
#line 4405 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1049:
#line 4410 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_UART_SERIALBUS);}
break;
case 1050:
#line 4425 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-19].n,15,
                                        yystack.l_mark[-18].n,yystack.l_mark[-17].n,yystack.l_mark[-16].n,yystack.l_mark[-14].n,yystack.l_mark[-13].n,yystack.l_mark[-12].n,yystack.l_mark[-11].n,yystack.l_mark[-9].n,yystack.l_mark[-7].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,
                                        TrCreateLeafOp (PARSEOP_DEFAULT_ARG),yystack.l_mark[-1].n);}
break;
case 1051:
#line 4430 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1052:
#line 4435 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_UART_SERIALBUS_V2);}
break;
case 1053:
#line 4451 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-20].n,15,
                                        yystack.l_mark[-19].n,yystack.l_mark[-18].n,yystack.l_mark[-17].n,yystack.l_mark[-15].n,yystack.l_mark[-14].n,yystack.l_mark[-13].n,yystack.l_mark[-12].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 1054:
#line 4455 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1055:
#line 4460 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_VENDORLONG);}
break;
case 1056:
#line 4463 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,2,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 1057:
#line 4466 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1058:
#line 4471 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_VENDORSHORT);}
break;
case 1059:
#line 4474 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-5].n,2,yystack.l_mark[-4].n,yystack.l_mark[-1].n);}
break;
case 1060:
#line 4477 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1061:
#line 4482 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_WORDBUSNUMBER);}
break;
case 1062:
#line 4495 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-18].n,12,
                                        yystack.l_mark[-17].n,yystack.l_mark[-16].n,yystack.l_mark[-15].n,yystack.l_mark[-14].n,yystack.l_mark[-12].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 1063:
#line 4499 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1064:
#line 4504 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_WORDIO);}
break;
case 1065:
#line 4520 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-21].n,15,
                                        yystack.l_mark[-20].n,yystack.l_mark[-19].n,yystack.l_mark[-18].n,yystack.l_mark[-17].n,yystack.l_mark[-16].n,yystack.l_mark[-14].n,yystack.l_mark[-12].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-5].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 1066:
#line 4524 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1067:
#line 4529 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (PARSEOP_WORDSPACE);}
break;
case 1068:
#line 4530 "aslcompiler.y"
	{UtCheckIntegerRange (yystack.l_mark[0].n, 0xC0, 0xFF);}
break;
case 1069:
#line 4544 "aslcompiler.y"
	{yyval.n = TrLinkOpChildren (yystack.l_mark[-22].n,14,
                                        yystack.l_mark[-21].n,yystack.l_mark[-19].n,yystack.l_mark[-18].n,yystack.l_mark[-17].n,yystack.l_mark[-16].n,yystack.l_mark[-14].n,yystack.l_mark[-12].n,yystack.l_mark[-10].n,yystack.l_mark[-8].n,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n);}
break;
case 1070:
#line 4548 "aslcompiler.y"
	{yyval.n = AslDoError(); yyclearin;}
break;
case 1071:
#line 4561 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (
                                                PARSEOP_BUSMASTERTYPE_MASTER);}
break;
case 1072:
#line 4563 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (
                                                PARSEOP_BUSMASTERTYPE_MASTER);}
break;
case 1073:
#line 4565 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (
                                                PARSEOP_BUSMASTERTYPE_NOTMASTER);}
break;
case 1074:
#line 4570 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1075:
#line 4571 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1076:
#line 4572 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1077:
#line 4573 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1078:
#line 4577 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (
                                        PARSEOP_BYTECONST, 0);}
break;
case 1079:
#line 4579 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (
                                        PARSEOP_BYTECONST, 0);}
break;
case 1080:
#line 4581 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1081:
#line 4585 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1082:
#line 4586 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1083:
#line 4590 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1084:
#line 4591 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1085:
#line 4592 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1086:
#line 4596 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1087:
#line 4597 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1088:
#line 4601 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1089:
#line 4602 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1090:
#line 4603 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1091:
#line 4607 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1092:
#line 4608 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1093:
#line 4609 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1094:
#line 4613 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1095:
#line 4614 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1096:
#line 4618 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1097:
#line 4619 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1098:
#line 4623 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1099:
#line 4624 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1100:
#line 4625 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1101:
#line 4629 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1102:
#line 4630 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1103:
#line 4634 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1104:
#line 4635 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1105:
#line 4639 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1106:
#line 4640 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1107:
#line 4644 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (
                                        PARSEOP_STRING_LITERAL,
                                        ACPI_TO_INTEGER (""));}
break;
case 1108:
#line 4647 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (
                                        PARSEOP_STRING_LITERAL,
                                        ACPI_TO_INTEGER (""));}
break;
case 1109:
#line 4650 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1110:
#line 4654 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1111:
#line 4655 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1112:
#line 4659 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1113:
#line 4660 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1114:
#line 4664 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1115:
#line 4665 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1116:
#line 4669 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1117:
#line 4670 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1118:
#line 4671 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1119:
#line 4675 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1120:
#line 4676 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1121:
#line 4677 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1122:
#line 4681 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (
                                        PARSEOP_ZERO);}
break;
case 1123:
#line 4683 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1124:
#line 4687 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (
                                        PARSEOP_OBJECTTYPE_UNK);}
break;
case 1125:
#line 4689 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1126:
#line 4693 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1127:
#line 4694 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1128:
#line 4698 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1129:
#line 4699 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1130:
#line 4700 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1131:
#line 4704 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1132:
#line 4705 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1133:
#line 4709 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (
                                            PARSEOP_READWRITETYPE_BOTH);}
break;
case 1134:
#line 4711 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (
                                            PARSEOP_READWRITETYPE_BOTH);}
break;
case 1135:
#line 4713 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (
                                            PARSEOP_READWRITETYPE_READONLY);}
break;
case 1136:
#line 4718 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (
                                        PARSEOP_RESOURCETYPE_CONSUMER);}
break;
case 1137:
#line 4720 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1138:
#line 4724 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (
                                        PARSEOP_RESOURCETYPE_CONSUMER);}
break;
case 1139:
#line 4726 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (
                                        PARSEOP_RESOURCETYPE_CONSUMER);}
break;
case 1140:
#line 4728 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1141:
#line 4733 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (
                                        PARSEOP_RESOURCETYPE_PRODUCER);}
break;
case 1142:
#line 4735 "aslcompiler.y"
	{yyval.n = TrCreateLeafOp (
                                        PARSEOP_RESOURCETYPE_PRODUCER);}
break;
case 1143:
#line 4737 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1144:
#line 4741 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1145:
#line 4742 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1146:
#line 4746 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1147:
#line 4747 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1148:
#line 4748 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1149:
#line 4752 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1150:
#line 4753 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1151:
#line 4757 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1152:
#line 4758 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1153:
#line 4762 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1154:
#line 4763 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1155:
#line 4764 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1156:
#line 4768 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1157:
#line 4769 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1158:
#line 4770 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1159:
#line 4774 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1160:
#line 4775 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1161:
#line 4776 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1162:
#line 4780 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1163:
#line 4781 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1164:
#line 4782 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1165:
#line 4786 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1166:
#line 4787 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1167:
#line 4791 "aslcompiler.y"
	{yyval.n = NULL;}
break;
case 1168:
#line 4792 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 1169:
#line 4796 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (
                                        PARSEOP_XFERSIZE_32, 2);}
break;
case 1170:
#line 4798 "aslcompiler.y"
	{yyval.n = TrCreateValuedLeafOp (
                                        PARSEOP_XFERSIZE_32, 2);}
break;
case 1171:
#line 4800 "aslcompiler.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
#line 18761 "aslcompilerparse.c"
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
