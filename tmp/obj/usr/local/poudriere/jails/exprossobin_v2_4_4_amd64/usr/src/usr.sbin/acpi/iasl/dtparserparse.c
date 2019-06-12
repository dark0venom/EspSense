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
#define yyparse    DtParserparse
#endif /* yyparse */

#ifndef yylex
#define yylex      DtParserlex
#endif /* yylex */

#ifndef yyerror
#define yyerror    DtParsererror
#endif /* yyerror */

#ifndef yychar
#define yychar     DtParserchar
#endif /* yychar */

#ifndef yyval
#define yyval      DtParserval
#endif /* yyval */

#ifndef yylval
#define yylval     DtParserlval
#endif /* yylval */

#ifndef yydebug
#define yydebug    DtParserdebug
#endif /* yydebug */

#ifndef yynerrs
#define yynerrs    DtParsernerrs
#endif /* yynerrs */

#ifndef yyerrflag
#define yyerrflag  DtParsererrflag
#endif /* yyerrflag */

#ifndef yylhs
#define yylhs      DtParserlhs
#endif /* yylhs */

#ifndef yylen
#define yylen      DtParserlen
#endif /* yylen */

#ifndef yydefred
#define yydefred   DtParserdefred
#endif /* yydefred */

#ifndef yydgoto
#define yydgoto    DtParserdgoto
#endif /* yydgoto */

#ifndef yysindex
#define yysindex   DtParsersindex
#endif /* yysindex */

#ifndef yyrindex
#define yyrindex   DtParserrindex
#endif /* yyrindex */

#ifndef yygindex
#define yygindex   DtParsergindex
#endif /* yygindex */

#ifndef yytable
#define yytable    DtParsertable
#endif /* yytable */

#ifndef yycheck
#define yycheck    DtParsercheck
#endif /* yycheck */

#ifndef yyname
#define yyname     DtParsername
#endif /* yyname */

#ifndef yyrule
#define yyrule     DtParserrule
#endif /* yyrule */
#define YYPREFIX "DtParser"

#define YYPURE 0

#line 2 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
/******************************************************************************
 *
 * Module Name: dtparser.y - Bison input file for table compiler parser
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

#define _COMPONENT          DT_COMPILER
        ACPI_MODULE_NAME    ("dtparser")

void *                      AslLocalAllocate (unsigned int Size);

/* Bison/yacc configuration */

#undef alloca
#define alloca              AslLocalAllocate

int                         DtParserlex (void);
int                         DtParserparse (void);
void                        DtParsererror (char const *msg);
extern char                 *DtParsertext;
extern DT_FIELD             *Gbl_CurrentField;

UINT64                      DtParserResult; /* Expression return value */

/* Bison/yacc configuration */

#define yytname             DtParsername
#define YYDEBUG             1               /* Enable debug output */
#define YYERROR_VERBOSE     1               /* Verbose error messages */
#define YYFLAG              -32768

/* Define YYMALLOC/YYFREE to prevent redefinition errors  */

#define YYMALLOC            malloc
#define YYFREE              free
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 186 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
typedef union
{
     UINT64                 value;
     UINT32                 op;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 297 "dtparserparse.c"

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

#define EXPOP_EOF 257
#define EXPOP_NEW_LINE 258
#define EXPOP_NUMBER 259
#define EXPOP_HEX_NUMBER 260
#define EXPOP_DECIMAL_NUMBER 261
#define EXPOP_LABEL 262
#define EXPOP_PAREN_OPEN 263
#define EXPOP_PAREN_CLOSE 264
#define EXPOP_LOGICAL_OR 265
#define EXPOP_LOGICAL_AND 266
#define EXPOP_OR 267
#define EXPOP_XOR 268
#define EXPOP_AND 269
#define EXPOP_EQUAL 270
#define EXPOP_NOT_EQUAL 271
#define EXPOP_GREATER 272
#define EXPOP_LESS 273
#define EXPOP_GREATER_EQUAL 274
#define EXPOP_LESS_EQUAL 275
#define EXPOP_SHIFT_RIGHT 276
#define EXPOP_SHIFT_LEFT 277
#define EXPOP_ADD 278
#define EXPOP_SUBTRACT 279
#define EXPOP_MULTIPLY 280
#define EXPOP_DIVIDE 281
#define EXPOP_MODULO 282
#define EXPOP_ONES_COMPLIMENT 283
#define EXPOP_LOGICAL_NOT 284
#define YYERRCODE 256
typedef int YYINT;
static const YYINT DtParserlhs[] = {                     -1,
    0,    0,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,
};
static const YYINT DtParserlen[] = {                      2,
    2,    2,    2,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    1,    1,    1,    1,
};
static const YYINT DtParserdefred[] = {                   0,
   25,   26,   27,   24,    0,    0,    0,    0,    0,    0,
    4,    3,    2,    1,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   23,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    5,    6,
    7,
};
static const YYINT DtParserdgoto[] = {                    8,
    9,
};
static const YYINT DtParsersindex[] = {                -228,
    0,    0,    0,    0, -228, -228, -228,    0, -229, -119,
    0,    0,    0,    0, -228, -228, -228, -228, -228, -228,
 -228, -228, -228, -228, -228, -228, -228, -228, -228, -228,
 -228, -228,    0,  -26,  -10,    5,   49,   62,   98,   98,
 -273, -273, -273, -273, -219, -219, -198, -198,    0,    0,
    0,
};
static const YYINT DtParserrindex[] = {                   0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  138,  128,  124,  101,   88,   31,   46,
  -93,  -74,  -55,  -36, -154, -133, -200, -177,    0,    0,
    0,
};
static const YYINT DtParsergindex[] = {                   0,
   -5,
};
#define YYTABLESIZE 403
static const YYINT DtParsertable[] = {                   10,
   11,   12,   26,   27,   28,   29,   30,   31,   32,   34,
   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,
   45,   46,   47,   48,   49,   50,   51,   13,   14,    0,
    1,    2,    3,    4,    5,   15,   16,   17,   18,   19,
   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
   30,   31,   32,    0,    6,    7,    8,    8,   28,   29,
   30,   31,   32,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    9,
    9,   30,   31,   32,    0,    0,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,   10,   10,    0,    0,    0,    0,    0,   10,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   10,   11,   11,    0,    0,    0,    0,    0,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   33,   15,   16,   17,   18,   19,
   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
   30,   31,   32,   12,   12,    0,    0,    0,    0,    0,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   13,   13,    0,    0,    0,    0,    0,   13,
   13,   13,   13,   13,   13,   13,   13,   13,   13,   13,
   13,   14,   14,    0,    0,    0,    0,    0,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   15,   15,    0,    0,    0,    0,    0,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   15,   16,
   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
   27,   28,   29,   30,   31,   32,   17,   18,   19,   20,
   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
   31,   32,   18,   19,   20,   21,   22,   23,   24,   25,
   26,   27,   28,   29,   30,   31,   32,   16,   16,    0,
    0,    0,    0,    0,   16,   16,   16,   16,   16,   16,
   16,   16,   17,   17,    0,    0,    0,    0,    0,   17,
   17,   17,   17,   17,   17,   17,   17,   19,   20,   21,
   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   20,   21,   22,   23,   24,   25,   26,   27,   28,
   29,   30,   31,   32,   18,   18,    0,    0,    0,    0,
    0,   18,   18,   18,   18,   18,   18,   19,   19,    0,
    0,    0,    0,    0,   19,   19,   19,   19,   19,   22,
   23,   24,   25,   26,   27,   28,   29,   30,   31,   32,
   20,   20,    0,    0,   21,   21,    0,   20,   20,   20,
   20,   21,   21,   21,   22,   22,    0,    0,    0,    0,
    0,   22,   22,
};
static const YYINT DtParsercheck[] = {                    5,
    6,    7,  276,  277,  278,  279,  280,  281,  282,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,
   26,   27,   28,   29,   30,   31,   32,  257,  258,   -1,
  259,  260,  261,  262,  263,  265,  266,  267,  268,  269,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
  280,  281,  282,   -1,  283,  284,  257,  258,  278,  279,
  280,  281,  282,  264,  265,  266,  267,  268,  269,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  257,
  258,  280,  281,  282,   -1,   -1,  264,  265,  266,  267,
  268,  269,  270,  271,  272,  273,  274,  275,  276,  277,
  278,  279,  257,  258,   -1,   -1,   -1,   -1,   -1,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,
  275,  276,  277,  257,  258,   -1,   -1,   -1,   -1,   -1,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  264,  265,  266,  267,  268,  269,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
  280,  281,  282,  257,  258,   -1,   -1,   -1,   -1,   -1,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,  275,  257,  258,   -1,   -1,   -1,   -1,   -1,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,
  275,  257,  258,   -1,   -1,   -1,   -1,   -1,  264,  265,
  266,  267,  268,  269,  270,  271,  272,  273,  274,  275,
  257,  258,   -1,   -1,   -1,   -1,   -1,  264,  265,  266,
  267,  268,  269,  270,  271,  272,  273,  274,  275,  266,
  267,  268,  269,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,  281,  282,  267,  268,  269,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  268,  269,  270,  271,  272,  273,  274,  275,
  276,  277,  278,  279,  280,  281,  282,  257,  258,   -1,
   -1,   -1,   -1,   -1,  264,  265,  266,  267,  268,  269,
  270,  271,  257,  258,   -1,   -1,   -1,   -1,   -1,  264,
  265,  266,  267,  268,  269,  270,  271,  269,  270,  271,
  272,  273,  274,  275,  276,  277,  278,  279,  280,  281,
  282,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  281,  282,  257,  258,   -1,   -1,   -1,   -1,
   -1,  264,  265,  266,  267,  268,  269,  257,  258,   -1,
   -1,   -1,   -1,   -1,  264,  265,  266,  267,  268,  272,
  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  257,  258,   -1,   -1,  257,  258,   -1,  264,  265,  266,
  267,  264,  265,  266,  257,  258,   -1,   -1,   -1,   -1,
   -1,  264,  265,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 284
#define YYUNDFTOKEN 288
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const DtParsername[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"EXPOP_EOF","EXPOP_NEW_LINE",
"EXPOP_NUMBER","EXPOP_HEX_NUMBER","EXPOP_DECIMAL_NUMBER","EXPOP_LABEL",
"EXPOP_PAREN_OPEN","EXPOP_PAREN_CLOSE","EXPOP_LOGICAL_OR","EXPOP_LOGICAL_AND",
"EXPOP_OR","EXPOP_XOR","EXPOP_AND","EXPOP_EQUAL","EXPOP_NOT_EQUAL",
"EXPOP_GREATER","EXPOP_LESS","EXPOP_GREATER_EQUAL","EXPOP_LESS_EQUAL",
"EXPOP_SHIFT_RIGHT","EXPOP_SHIFT_LEFT","EXPOP_ADD","EXPOP_SUBTRACT",
"EXPOP_MULTIPLY","EXPOP_DIVIDE","EXPOP_MODULO","EXPOP_ONES_COMPLIMENT",
"EXPOP_LOGICAL_NOT",0,0,0,"illegal-symbol",
};
static const char *const DtParserrule[] = {
"$accept : Value",
"Value : Expression EXPOP_NEW_LINE",
"Value : Expression EXPOP_EOF",
"Expression : EXPOP_LOGICAL_NOT Expression",
"Expression : EXPOP_ONES_COMPLIMENT Expression",
"Expression : Expression EXPOP_MULTIPLY Expression",
"Expression : Expression EXPOP_DIVIDE Expression",
"Expression : Expression EXPOP_MODULO Expression",
"Expression : Expression EXPOP_ADD Expression",
"Expression : Expression EXPOP_SUBTRACT Expression",
"Expression : Expression EXPOP_SHIFT_RIGHT Expression",
"Expression : Expression EXPOP_SHIFT_LEFT Expression",
"Expression : Expression EXPOP_GREATER Expression",
"Expression : Expression EXPOP_LESS Expression",
"Expression : Expression EXPOP_GREATER_EQUAL Expression",
"Expression : Expression EXPOP_LESS_EQUAL Expression",
"Expression : Expression EXPOP_EQUAL Expression",
"Expression : Expression EXPOP_NOT_EQUAL Expression",
"Expression : Expression EXPOP_AND Expression",
"Expression : Expression EXPOP_XOR Expression",
"Expression : Expression EXPOP_OR Expression",
"Expression : Expression EXPOP_LOGICAL_AND Expression",
"Expression : Expression EXPOP_LOGICAL_OR Expression",
"Expression : EXPOP_PAREN_OPEN Expression EXPOP_PAREN_CLOSE",
"Expression : EXPOP_LABEL",
"Expression : EXPOP_NUMBER",
"Expression : EXPOP_HEX_NUMBER",
"Expression : EXPOP_DECIMAL_NUMBER",

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
#line 297 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"

/*! [End] no source code translation !*/

/*
 * Local support functions, including parser entry point
 */
#define PR_FIRST_PARSE_OPCODE   EXPOP_EOF
#define PR_YYTNAME_START        3


/******************************************************************************
 *
 * FUNCTION:    DtParsererror
 *
 * PARAMETERS:  Message             - Parser-generated error message
 *
 * RETURN:      None
 *
 * DESCRIPTION: Handler for parser errors
 *
 *****************************************************************************/

void
DtParsererror (
    char const              *Message)
{
    DtError (ASL_ERROR, ASL_MSG_SYNTAX,
        Gbl_CurrentField, (char *) Message);
}


/******************************************************************************
 *
 * FUNCTION:    DtGetOpName
 *
 * PARAMETERS:  ParseOpcode         - Parser token (EXPOP_*)
 *
 * RETURN:      Pointer to the opcode name
 *
 * DESCRIPTION: Get the ascii name of the parse opcode for debug output
 *
 *****************************************************************************/

char *
DtGetOpName (
    UINT32                  ParseOpcode)
{
#ifdef ASL_YYTNAME_START
    /*
     * First entries (PR_YYTNAME_START) in yytname are special reserved names.
     * Ignore first 6 characters of name (EXPOP_)
     */
    return ((char *) yytname
        [(ParseOpcode - PR_FIRST_PARSE_OPCODE) + PR_YYTNAME_START] + 6);
#else
    return ("[Unknown parser generator]");
#endif
}


/******************************************************************************
 *
 * FUNCTION:    DtEvaluateExpression
 *
 * PARAMETERS:  ExprString          - Expression to be evaluated. Must be
 *                                    terminated by either a newline or a NUL
 *                                    string terminator
 *
 * RETURN:      64-bit value for the expression
 *
 * DESCRIPTION: Main entry point for the DT expression parser
 *
 *****************************************************************************/

UINT64
DtEvaluateExpression (
    char                    *ExprString)
{

    DbgPrint (ASL_DEBUG_OUTPUT,
        "**** Input expression: %s  (Base 16)\n", ExprString);

    /* Point lexer to the input string */

    if (DtInitLexer (ExprString))
    {
        DtError (ASL_ERROR, ASL_MSG_COMPILER_INTERNAL,
            Gbl_CurrentField, "Could not initialize lexer");
        return (0);
    }

    /* Parse/Evaluate the input string (value returned in DtParserResult) */

    DtParserparse ();
    DtTerminateLexer ();

    DbgPrint (ASL_DEBUG_OUTPUT,
        "**** Parser returned value: %u (%8.8X%8.8X)\n",
        (UINT32) DtParserResult, ACPI_FORMAT_UINT64 (DtParserResult));

    return (DtParserResult);
}
#line 681 "dtparserparse.c"

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
#line 236 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ DtParserResult=yystack.l_mark[-1].value; return 0; }
break;
case 2:
#line 237 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ DtParserResult=yystack.l_mark[-1].value; return 0; }
break;
case 3:
#line 244 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[0].value, EXPOP_LOGICAL_NOT,     yystack.l_mark[0].value);}
break;
case 4:
#line 245 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[0].value, EXPOP_ONES_COMPLIMENT, yystack.l_mark[0].value);}
break;
case 5:
#line 249 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_MULTIPLY,        yystack.l_mark[0].value);}
break;
case 6:
#line 250 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_DIVIDE,          yystack.l_mark[0].value);}
break;
case 7:
#line 251 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_MODULO,          yystack.l_mark[0].value);}
break;
case 8:
#line 252 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_ADD,             yystack.l_mark[0].value);}
break;
case 9:
#line 253 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_SUBTRACT,        yystack.l_mark[0].value);}
break;
case 10:
#line 254 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_SHIFT_RIGHT,     yystack.l_mark[0].value);}
break;
case 11:
#line 255 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_SHIFT_LEFT,      yystack.l_mark[0].value);}
break;
case 12:
#line 256 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_GREATER,         yystack.l_mark[0].value);}
break;
case 13:
#line 257 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_LESS,            yystack.l_mark[0].value);}
break;
case 14:
#line 258 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_GREATER_EQUAL,   yystack.l_mark[0].value);}
break;
case 15:
#line 259 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_LESS_EQUAL,      yystack.l_mark[0].value);}
break;
case 16:
#line 260 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_EQUAL,           yystack.l_mark[0].value);}
break;
case 17:
#line 261 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_NOT_EQUAL,       yystack.l_mark[0].value);}
break;
case 18:
#line 262 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_AND,             yystack.l_mark[0].value);}
break;
case 19:
#line 263 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_XOR,             yystack.l_mark[0].value);}
break;
case 20:
#line 264 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_OR,              yystack.l_mark[0].value);}
break;
case 21:
#line 265 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_LOGICAL_AND,     yystack.l_mark[0].value);}
break;
case 22:
#line 266 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoOperator (yystack.l_mark[-2].value, EXPOP_LOGICAL_OR,      yystack.l_mark[0].value);}
break;
case 23:
#line 271 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = yystack.l_mark[-1].value;}
break;
case 24:
#line 275 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtResolveLabel (DtParsertext);}
break;
case 25:
#line 286 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoConstant (DtParsertext);}
break;
case 26:
#line 290 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoConstant (DtParsertext);}
break;
case 27:
#line 294 "/usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/sys/contrib/dev/acpica/compiler/dtparser.y"
	{ yyval.value = DtDoConstant (DtParsertext);}
break;
#line 988 "dtparserparse.c"
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
