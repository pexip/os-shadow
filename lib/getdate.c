/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "getdate.y"

/*
**  Originally written by Steven M. Bellovin <smb@research.att.com> while
**  at the University of North Carolina at Chapel Hill.  Later tweaked by
**  a couple of people on Usenet.  Completely overhauled by Rich $alz
**  <rsalz@bbn.com> and Jim Berets <jberets@bbn.com> in August, 1990;
**
**  This grammar has 13 shift/reduce conflicts.
**
**  This code is in the public domain and has no copyright.
*/

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

/* Since the code of getdate.y is not included in the Emacs executable
   itself, there is no need to #define static in this file.  Even if
   the code were included in the Emacs executable, it probably
   wouldn't do any harm to #undef it here; this will only cause
   problems if we try to write to a static variable, which I don't
   think this code needs to do.  */
#ifdef emacs
# undef static
#endif

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "attr.h"
#include "getdate.h"
#include "string/strcmp/streq.h"
#include "string/strspn/stpspn.h"


/* Some old versions of bison generate parsers that use bcopy.
   That loses on systems that don't provide the function, so we have
   to redefine it here.  */
#if !defined (HAVE_BCOPY) && !defined (bcopy)
# define bcopy(from, to, len) memcpy ((to), (from), (len))
#endif

/* Remap normal yacc parser interface names (yyparse, yylex, yyerror, etc),
   as well as gratuitously global symbol names, so we can have multiple
   yacc generated parsers in the same program.  Note that these are only
   the variables produced by yacc.  If other parser generators (bison,
   byacc, etc) produce additional global names that conflict at link time,
   then those parser generators need to be fixed instead of adding those
   names to this list. */

#define yymaxdepth gd_maxdepth
#define yyparse gd_parse
#define yylex   gd_lex
#define yyerror gd_error
#define yylval  gd_lval
#define yychar  gd_char
#define yydebug gd_debug
#define yypact  gd_pact
#define yyr1    gd_r1
#define yyr2    gd_r2
#define yydef   gd_def
#define yychk   gd_chk
#define yypgo   gd_pgo
#define yyact   gd_act
#define yyexca  gd_exca
#define yyerrflag gd_errflag
#define yynerrs gd_nerrs
#define yyps    gd_ps
#define yypv    gd_pv
#define yys     gd_s
#define yy_yys  gd_yys
#define yystate gd_state
#define yytmp   gd_tmp
#define yyv     gd_v
#define yy_yyv  gd_yyv
#define yyval   gd_val
#define yylloc  gd_lloc
#define yyreds  gd_reds          /* With YYDEBUG defined */
#define yytoks  gd_toks          /* With YYDEBUG defined */
#define yylhs   gd_yylhs
#define yylen   gd_yylen
#define yydefred gd_yydefred
#define yydgoto gd_yydgoto
#define yysindex gd_yysindex
#define yyrindex gd_yyrindex
#define yygindex gd_yygindex
#define yytable  gd_yytable
#define yycheck  gd_yycheck

static int yylex (void);
static int yyerror (const char *s);


#define MAX_BUFF_LEN    128   /* size of buffer to read the date into */

/*
**  An entry in the lexical lookup table.
*/
typedef struct _TABLE {
    const char	*name;
    int		type;
    int		value;
} TABLE;


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
static const char	*yyInput;
static int	yyDayOrdinal;
static int	yyDayNumber;
static int	yyHaveDate;
static int	yyHaveDay;
static int	yyHaveRel;
static int	yyHaveTime;
static int	yyDay;
static int	yyHour;
static int	yyMinutes;
static int	yyMonth;
static int	yySeconds;
static int	yyYear;
static MERIDIAN	yyMeridian;
static int	yyRelDay;
static int	yyRelHour;
static int	yyRelMinutes;
static int	yyRelMonth;
static int	yyRelSeconds;
static int	yyRelYear;


#line 215 "getdate.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tAGO = 258,                    /* tAGO  */
    tDAY = 259,                    /* tDAY  */
    tDAY_UNIT = 260,               /* tDAY_UNIT  */
    tHOUR_UNIT = 261,              /* tHOUR_UNIT  */
    tID = 262,                     /* tID  */
    tMERIDIAN = 263,               /* tMERIDIAN  */
    tMINUTE_UNIT = 264,            /* tMINUTE_UNIT  */
    tMONTH = 265,                  /* tMONTH  */
    tMONTH_UNIT = 266,             /* tMONTH_UNIT  */
    tSEC_UNIT = 267,               /* tSEC_UNIT  */
    tSNUMBER = 268,                /* tSNUMBER  */
    tUNUMBER = 269,                /* tUNUMBER  */
    tYEAR_UNIT = 270               /* tYEAR_UNIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define tAGO 258
#define tDAY 259
#define tDAY_UNIT 260
#define tHOUR_UNIT 261
#define tID 262
#define tMERIDIAN 263
#define tMINUTE_UNIT 264
#define tMONTH 265
#define tMONTH_UNIT 266
#define tSEC_UNIT 267
#define tSNUMBER 268
#define tUNUMBER 269
#define tYEAR_UNIT 270

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 145 "getdate.y"

    int			Number;
    enum _MERIDIAN	Meridian;

#line 300 "getdate.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tAGO = 3,                       /* tAGO  */
  YYSYMBOL_tDAY = 4,                       /* tDAY  */
  YYSYMBOL_tDAY_UNIT = 5,                  /* tDAY_UNIT  */
  YYSYMBOL_tHOUR_UNIT = 6,                 /* tHOUR_UNIT  */
  YYSYMBOL_tID = 7,                        /* tID  */
  YYSYMBOL_tMERIDIAN = 8,                  /* tMERIDIAN  */
  YYSYMBOL_tMINUTE_UNIT = 9,               /* tMINUTE_UNIT  */
  YYSYMBOL_tMONTH = 10,                    /* tMONTH  */
  YYSYMBOL_tMONTH_UNIT = 11,               /* tMONTH_UNIT  */
  YYSYMBOL_tSEC_UNIT = 12,                 /* tSEC_UNIT  */
  YYSYMBOL_tSNUMBER = 13,                  /* tSNUMBER  */
  YYSYMBOL_tUNUMBER = 14,                  /* tUNUMBER  */
  YYSYMBOL_tYEAR_UNIT = 15,                /* tYEAR_UNIT  */
  YYSYMBOL_16_ = 16,                       /* ':'  */
  YYSYMBOL_17_ = 17,                       /* ','  */
  YYSYMBOL_18_ = 18,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 19,                  /* $accept  */
  YYSYMBOL_spec = 20,                      /* spec  */
  YYSYMBOL_item = 21,                      /* item  */
  YYSYMBOL_time = 22,                      /* time  */
  YYSYMBOL_day = 23,                       /* day  */
  YYSYMBOL_date = 24,                      /* date  */
  YYSYMBOL_rel = 25,                       /* rel  */
  YYSYMBOL_relunit = 26,                   /* relunit  */
  YYSYMBOL_number = 27,                    /* number  */
  YYSYMBOL_o_merid = 28                    /* o_merid  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   46

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  19
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  55

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   270


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    17,     2,     2,    18,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    16,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   161,   161,   162,   165,   168,   171,   174,   177,   180,
     186,   192,   197,   203,   211,   215,   219,   225,   229,   247,
     253,   259,   263,   268,   272,   279,   287,   290,   293,   296,
     299,   302,   305,   308,   311,   314,   317,   320,   323,   326,
     329,   332,   335,   338,   341,   346,   380,   383
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tAGO", "tDAY",
  "tDAY_UNIT", "tHOUR_UNIT", "tID", "tMERIDIAN", "tMINUTE_UNIT", "tMONTH",
  "tMONTH_UNIT", "tSEC_UNIT", "tSNUMBER", "tUNUMBER", "tYEAR_UNIT", "':'",
  "','", "'/'", "$accept", "spec", "item", "time", "day", "date", "rel",
  "relunit", "number", "o_merid", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-15)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -15,     0,   -15,   -14,   -15,   -15,   -15,    -7,   -15,   -15,
      26,    12,   -15,   -15,   -15,   -15,   -15,   -15,     5,   -15,
     -15,     2,   -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,
     -15,   -15,   -15,   -12,   -15,   -15,    16,   -15,    19,    22,
     -15,    25,   -15,   -15,   -15,    18,    24,   -15,   -15,    29,
     -15,    30,    32,   -15,   -15
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    14,    35,    38,    41,     0,    32,    44,
       0,    45,    29,     3,     4,     6,     5,     7,    26,     8,
      15,    21,    34,    37,    40,    31,    43,    28,    16,    33,
      36,     9,    39,    23,    30,    42,     0,    27,     0,     0,
      25,     0,    20,    24,    19,    11,    17,    22,    47,     0,
      10,     0,    13,    18,    12
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,    -6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    13,    14,    15,    16,    17,    18,    19,    50
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       2,    42,    43,    20,     3,     4,     5,    21,    40,     6,
       7,     8,     9,    10,    11,    12,    28,    29,    30,    41,
      31,    32,    33,    34,    35,    36,    48,    37,    38,    44,
      39,    22,    23,    45,    49,    24,    46,    25,    26,    47,
      48,    27,    51,    52,    53,     0,    54
};

static const yytype_int8 yycheck[] =
{
       0,    13,    14,    17,     4,     5,     6,    14,     3,     9,
      10,    11,    12,    13,    14,    15,     4,     5,     6,    17,
       8,     9,    10,    11,    12,    13,     8,    15,    16,    13,
      18,     5,     6,    14,    16,     9,    14,    11,    12,    14,
       8,    15,    18,    14,    14,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    20,     0,     4,     5,     6,     9,    10,    11,    12,
      13,    14,    15,    21,    22,    23,    24,    25,    26,    27,
      17,    14,     5,     6,     9,    11,    12,    15,     4,     5,
       6,     8,     9,    10,    11,    12,    13,    15,    16,    18,
       3,    17,    13,    14,    13,    14,    14,    14,     8,    16,
      28,    18,    14,    14,    28
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    19,    20,    20,    21,    21,    21,    21,    21,    22,
      22,    22,    22,    22,    23,    23,    23,    24,    24,    24,
      24,    24,    24,    24,    24,    25,    25,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    27,    28,    28
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     2,
       4,     3,     6,     5,     1,     2,     2,     3,     5,     3,
       3,     2,     4,     2,     3,     2,     1,     2,     2,     1,
       2,     2,     1,     2,     2,     1,     2,     2,     1,     2,
       2,     1,     2,     2,     1,     1,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* item: time  */
#line 165 "getdate.y"
               {
	    yyHaveTime++;
	}
#line 1335 "getdate.c"
    break;

  case 5: /* item: date  */
#line 168 "getdate.y"
               {
	    yyHaveDate++;
	}
#line 1343 "getdate.c"
    break;

  case 6: /* item: day  */
#line 171 "getdate.y"
              {
	    yyHaveDay++;
	}
#line 1351 "getdate.c"
    break;

  case 7: /* item: rel  */
#line 174 "getdate.y"
              {
	    yyHaveRel++;
	}
#line 1359 "getdate.c"
    break;

  case 9: /* time: tUNUMBER tMERIDIAN  */
#line 180 "getdate.y"
                             {
	    yyHour = (yyvsp[-1].Number);
	    yyMinutes = 0;
	    yySeconds = 0;
	    yyMeridian = (yyvsp[0].Meridian);
	}
#line 1370 "getdate.c"
    break;

  case 10: /* time: tUNUMBER ':' tUNUMBER o_merid  */
#line 186 "getdate.y"
                                        {
	    yyHour = (yyvsp[-3].Number);
	    yyMinutes = (yyvsp[-1].Number);
	    yySeconds = 0;
	    yyMeridian = (yyvsp[0].Meridian);
	}
#line 1381 "getdate.c"
    break;

  case 11: /* time: tUNUMBER ':' tUNUMBER  */
#line 192 "getdate.y"
                                {
	    yyHour = (yyvsp[-2].Number);
	    yyMinutes = (yyvsp[0].Number);
	    yyMeridian = MER24;
	}
#line 1391 "getdate.c"
    break;

  case 12: /* time: tUNUMBER ':' tUNUMBER ':' tUNUMBER o_merid  */
#line 197 "getdate.y"
                                                     {
	    yyHour = (yyvsp[-5].Number);
	    yyMinutes = (yyvsp[-3].Number);
	    yySeconds = (yyvsp[-1].Number);
	    yyMeridian = (yyvsp[0].Meridian);
	}
#line 1402 "getdate.c"
    break;

  case 13: /* time: tUNUMBER ':' tUNUMBER ':' tUNUMBER  */
#line 203 "getdate.y"
                                             {
	    yyHour = (yyvsp[-4].Number);
	    yyMinutes = (yyvsp[-2].Number);
	    yySeconds = (yyvsp[0].Number);
	    yyMeridian = MER24;
	}
#line 1413 "getdate.c"
    break;

  case 14: /* day: tDAY  */
#line 211 "getdate.y"
               {
	    yyDayOrdinal = 1;
	    yyDayNumber = (yyvsp[0].Number);
	}
#line 1422 "getdate.c"
    break;

  case 15: /* day: tDAY ','  */
#line 215 "getdate.y"
                   {
	    yyDayOrdinal = 1;
	    yyDayNumber = (yyvsp[-1].Number);
	}
#line 1431 "getdate.c"
    break;

  case 16: /* day: tUNUMBER tDAY  */
#line 219 "getdate.y"
                        {
	    yyDayOrdinal = (yyvsp[-1].Number);
	    yyDayNumber = (yyvsp[0].Number);
	}
#line 1440 "getdate.c"
    break;

  case 17: /* date: tUNUMBER '/' tUNUMBER  */
#line 225 "getdate.y"
                                {
	    yyMonth = (yyvsp[-2].Number);
	    yyDay = (yyvsp[0].Number);
	}
#line 1449 "getdate.c"
    break;

  case 18: /* date: tUNUMBER '/' tUNUMBER '/' tUNUMBER  */
#line 229 "getdate.y"
                                             {
	  /* Interpret as YYYY/MM/DD if $1 >= 1000, otherwise as MM/DD/YY.
	     The goal in recognizing YYYY/MM/DD is solely to support legacy
	     machine-generated dates like those in an RCS log listing.  If
	     you want portability, use the ISO 8601 format.  */
	  if ((yyvsp[-4].Number) >= 1000)
	    {
	      yyYear = (yyvsp[-4].Number);
	      yyMonth = (yyvsp[-2].Number);
	      yyDay = (yyvsp[0].Number);
	    }
	  else
	    {
	      yyMonth = (yyvsp[-4].Number);
	      yyDay = (yyvsp[-2].Number);
	      yyYear = (yyvsp[0].Number);
	    }
	}
#line 1472 "getdate.c"
    break;

  case 19: /* date: tUNUMBER tSNUMBER tSNUMBER  */
#line 247 "getdate.y"
                                     {
	    /* ISO 8601 format.  yyyy-mm-dd.  */
	    yyYear = (yyvsp[-2].Number);
	    yyMonth = -(yyvsp[-1].Number);
	    yyDay = -(yyvsp[0].Number);
	}
#line 1483 "getdate.c"
    break;

  case 20: /* date: tUNUMBER tMONTH tSNUMBER  */
#line 253 "getdate.y"
                                   {
	    /* e.g. 17-JUN-1992.  */
	    yyDay = (yyvsp[-2].Number);
	    yyMonth = (yyvsp[-1].Number);
	    yyYear = -(yyvsp[0].Number);
	}
#line 1494 "getdate.c"
    break;

  case 21: /* date: tMONTH tUNUMBER  */
#line 259 "getdate.y"
                          {
	    yyMonth = (yyvsp[-1].Number);
	    yyDay = (yyvsp[0].Number);
	}
#line 1503 "getdate.c"
    break;

  case 22: /* date: tMONTH tUNUMBER ',' tUNUMBER  */
#line 263 "getdate.y"
                                       {
	    yyMonth = (yyvsp[-3].Number);
	    yyDay = (yyvsp[-2].Number);
	    yyYear = (yyvsp[0].Number);
	}
#line 1513 "getdate.c"
    break;

  case 23: /* date: tUNUMBER tMONTH  */
#line 268 "getdate.y"
                          {
	    yyMonth = (yyvsp[0].Number);
	    yyDay = (yyvsp[-1].Number);
	}
#line 1522 "getdate.c"
    break;

  case 24: /* date: tUNUMBER tMONTH tUNUMBER  */
#line 272 "getdate.y"
                                   {
	    yyMonth = (yyvsp[-1].Number);
	    yyDay = (yyvsp[-2].Number);
	    yyYear = (yyvsp[0].Number);
	}
#line 1532 "getdate.c"
    break;

  case 25: /* rel: relunit tAGO  */
#line 279 "getdate.y"
                       {
	    yyRelSeconds = -yyRelSeconds;
	    yyRelMinutes = -yyRelMinutes;
	    yyRelHour = -yyRelHour;
	    yyRelDay = -yyRelDay;
	    yyRelMonth = -yyRelMonth;
	    yyRelYear = -yyRelYear;
	}
#line 1545 "getdate.c"
    break;

  case 27: /* relunit: tUNUMBER tYEAR_UNIT  */
#line 290 "getdate.y"
                              {
	    yyRelYear += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1553 "getdate.c"
    break;

  case 28: /* relunit: tSNUMBER tYEAR_UNIT  */
#line 293 "getdate.y"
                              {
	    yyRelYear += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1561 "getdate.c"
    break;

  case 29: /* relunit: tYEAR_UNIT  */
#line 296 "getdate.y"
                     {
	    yyRelYear += (yyvsp[0].Number);
	}
#line 1569 "getdate.c"
    break;

  case 30: /* relunit: tUNUMBER tMONTH_UNIT  */
#line 299 "getdate.y"
                               {
	    yyRelMonth += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1577 "getdate.c"
    break;

  case 31: /* relunit: tSNUMBER tMONTH_UNIT  */
#line 302 "getdate.y"
                               {
	    yyRelMonth += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1585 "getdate.c"
    break;

  case 32: /* relunit: tMONTH_UNIT  */
#line 305 "getdate.y"
                      {
	    yyRelMonth += (yyvsp[0].Number);
	}
#line 1593 "getdate.c"
    break;

  case 33: /* relunit: tUNUMBER tDAY_UNIT  */
#line 308 "getdate.y"
                             {
	    yyRelDay += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1601 "getdate.c"
    break;

  case 34: /* relunit: tSNUMBER tDAY_UNIT  */
#line 311 "getdate.y"
                             {
	    yyRelDay += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1609 "getdate.c"
    break;

  case 35: /* relunit: tDAY_UNIT  */
#line 314 "getdate.y"
                    {
	    yyRelDay += (yyvsp[0].Number);
	}
#line 1617 "getdate.c"
    break;

  case 36: /* relunit: tUNUMBER tHOUR_UNIT  */
#line 317 "getdate.y"
                              {
	    yyRelHour += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1625 "getdate.c"
    break;

  case 37: /* relunit: tSNUMBER tHOUR_UNIT  */
#line 320 "getdate.y"
                              {
	    yyRelHour += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1633 "getdate.c"
    break;

  case 38: /* relunit: tHOUR_UNIT  */
#line 323 "getdate.y"
                     {
	    yyRelHour += (yyvsp[0].Number);
	}
#line 1641 "getdate.c"
    break;

  case 39: /* relunit: tUNUMBER tMINUTE_UNIT  */
#line 326 "getdate.y"
                                {
	    yyRelMinutes += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1649 "getdate.c"
    break;

  case 40: /* relunit: tSNUMBER tMINUTE_UNIT  */
#line 329 "getdate.y"
                                {
	    yyRelMinutes += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1657 "getdate.c"
    break;

  case 41: /* relunit: tMINUTE_UNIT  */
#line 332 "getdate.y"
                       {
	    yyRelMinutes += (yyvsp[0].Number);
	}
#line 1665 "getdate.c"
    break;

  case 42: /* relunit: tUNUMBER tSEC_UNIT  */
#line 335 "getdate.y"
                             {
	    yyRelSeconds += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1673 "getdate.c"
    break;

  case 43: /* relunit: tSNUMBER tSEC_UNIT  */
#line 338 "getdate.y"
                             {
	    yyRelSeconds += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1681 "getdate.c"
    break;

  case 44: /* relunit: tSEC_UNIT  */
#line 341 "getdate.y"
                    {
	    yyRelSeconds += (yyvsp[0].Number);
	}
#line 1689 "getdate.c"
    break;

  case 45: /* number: tUNUMBER  */
#line 347 "getdate.y"
          {
	    if ((yyHaveTime != 0) && (yyHaveDate != 0) && (yyHaveRel == 0))
	      yyYear = (yyvsp[0].Number);
	    else
	      {
		if ((yyvsp[0].Number)>10000)
		  {
		    yyHaveDate++;
		    yyDay= ((yyvsp[0].Number))%100;
		    yyMonth= ((yyvsp[0].Number)/100)%100;
		    yyYear = (yyvsp[0].Number)/10000;
		  }
		else
		  {
		    yyHaveTime++;
		    if ((yyvsp[0].Number) < 100)
		      {
			yyHour = (yyvsp[0].Number);
			yyMinutes = 0;
		      }
		    else
		      {
		    	yyHour = (yyvsp[0].Number) / 100;
		    	yyMinutes = (yyvsp[0].Number) % 100;
		      }
		    yySeconds = 0;
		    yyMeridian = MER24;
		  }
	      }
	  }
#line 1724 "getdate.c"
    break;

  case 46: /* o_merid: %empty  */
#line 380 "getdate.y"
          {
	    (yyval.Meridian) = MER24;
	  }
#line 1732 "getdate.c"
    break;

  case 47: /* o_merid: tMERIDIAN  */
#line 384 "getdate.y"
          {
	    (yyval.Meridian) = (yyvsp[0].Meridian);
	  }
#line 1740 "getdate.c"
    break;


#line 1744 "getdate.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 389 "getdate.y"


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
    { NULL, 0, 0 }
};

/* Time units table. */
static TABLE const UnitsTable[] = {
    { "year",		tYEAR_UNIT,	1 },
    { "month",		tMONTH_UNIT,	1 },
    { "fortnight",	tDAY_UNIT,	14 },
    { "week",		tDAY_UNIT,	7 },
    { "day",		tDAY_UNIT,	1 },
    { "hour",		tHOUR_UNIT,	1 },
    { "minute",		tMINUTE_UNIT,	1 },
    { "min",		tMINUTE_UNIT,	1 },
    { "second",		tSEC_UNIT,	1 },
    { "sec",		tSEC_UNIT,	1 },
    { NULL, 0, 0 }
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
    { "ago",		tAGO,	1 },
    { NULL, 0, 0 }
};




static int yyerror (MAYBE_UNUSED const char *s)
{
  return 0;
}

static int ToHour (int Hours, MERIDIAN Meridian)
{
  switch (Meridian)
    {
    case MER24:
      if (Hours < 0 || Hours > 23)
	return -1;
      return Hours;
    case MERam:
      if (Hours < 1 || Hours > 12)
	return -1;
      if (Hours == 12)
	Hours = 0;
      return Hours;
    case MERpm:
      if (Hours < 1 || Hours > 12)
	return -1;
      if (Hours == 12)
	Hours = 0;
      return Hours + 12;
    default:
      abort ();
    }
  /* NOTREACHED */
}

static int ToYear (int Year)
{
  if (Year < 0)
    Year = -Year;

  /* XPG4 suggests that years 00-68 map to 2000-2068, and
     years 69-99 map to 1969-1999.  */
  if (Year < 69)
    Year += 2000;
  else if (Year < 100)
    Year += 1900;

  return Year;
}

static int LookupWord (char *buff)
{
  register char *p;
  register const TABLE *tp;
  int i;
  bool abbrev;

  /* Make it lowercase. */
  for (p = buff; !streq(p, ""); p++)
    if (isupper (*p))
      *p = tolower (*p);

  if (streq(buff, "am") || streq(buff, "a.m."))
    {
      yylval.Meridian = MERam;
      return tMERIDIAN;
    }
  if (streq(buff, "pm") || streq(buff, "p.m."))
    {
      yylval.Meridian = MERpm;
      return tMERIDIAN;
    }

  /* See if we have an abbreviation for a month. */
  if (strlen (buff) == 3)
    abbrev = true;
  else if (strlen (buff) == 4 && buff[3] == '.')
    {
      abbrev = true;
      stpcpy(&buff[3], "");
    }
  else
    abbrev = false;

  for (tp = MonthDayTable; tp->name; tp++)
    {
      if (abbrev)
	{
	  if (strncmp (buff, tp->name, 3) == 0)
	    {
	      yylval.Number = tp->value;
	      return tp->type;
	    }
	}
      else if (streq(buff, tp->name))
	{
	  yylval.Number = tp->value;
	  return tp->type;
	}
    }

  for (tp = UnitsTable; tp->name; tp++)
    if (streq(buff, tp->name))
      {
	yylval.Number = tp->value;
	return tp->type;
      }

  /* Strip off any plural and try the units table again. */
  i = strlen (buff) - 1;
  if (buff[i] == 's')
    {
      stpcpy(&buff[i], "");
      for (tp = UnitsTable; tp->name; tp++)
	if (streq(buff, tp->name))
	  {
	    yylval.Number = tp->value;
	    return tp->type;
	  }
      buff[i] = 's';		/* Put back for "this" in OtherTable. */
    }

  for (tp = OtherTable; tp->name; tp++)
    if (streq(buff, tp->name))
      {
	yylval.Number = tp->value;
	return tp->type;
      }

  return tID;
}

static int
yylex (void)
{
  register char c;
  register char *p;
  char buff[20];
  int Count;
  int sign;

  for (;;)
    {
      yyInput = stpspn(yyInput, " \t");

      if (isdigit (c = *yyInput) || c == '-' || c == '+')
	{
	  if (c == '-' || c == '+')
	    {
	      sign = c == '-' ? -1 : 1;
	      if (!isdigit (*++yyInput))
		/* skip the '-' sign */
		continue;
	    }
	  else
	    sign = 0;
	  for (yylval.Number = 0; isdigit (c = *yyInput++);)
	    yylval.Number = 10 * yylval.Number + c - '0';
	  yyInput--;
	  if (sign < 0)
	    yylval.Number = -yylval.Number;
	  return (0 != sign) ? tSNUMBER : tUNUMBER;
	}
      if (isalpha (c))
	{
	  for (p = buff; (c = *yyInput++, isalpha (c)) || c == '.';)
	    if (p < &buff[sizeof buff - 1])
	      *p++ = c;
          stpcpy(p, "");
	  yyInput--;
	  return LookupWord (buff);
	}
      if (c != '(')
	return *yyInput++;
      Count = 0;
      do
	{
	  c = *yyInput++;
	  if (c == '\0')
	    return c;
	  if (c == '(')
	    Count++;
	  else if (c == ')')
	    Count--;
	}
      while (Count > 0);
    }
}

#define TM_YEAR_ORIGIN 1900

time_t get_date (const char *p, const time_t *now)
{
  struct tm  tm, *tmp;
  time_t Start;

  yyInput = p;
  Start = now ? *now : time(NULL);
  tmp = gmtime(&Start);
  yyYear = tmp->tm_year + TM_YEAR_ORIGIN;
  yyMonth = tmp->tm_mon + 1;
  yyDay = tmp->tm_mday;
  yyHour = tmp->tm_hour;
  yyMinutes = tmp->tm_min;
  yySeconds = tmp->tm_sec;
  yyMeridian = MER24;
  yyRelSeconds = 0;
  yyRelMinutes = 0;
  yyRelHour = 0;
  yyRelDay = 0;
  yyRelMonth = 0;
  yyRelYear = 0;
  yyHaveDate = 0;
  yyHaveDay = 0;
  yyHaveRel = 0;
  yyHaveTime = 0;

  if (yyparse ()
      || yyHaveTime > 1 || yyHaveDate > 1 || yyHaveDay > 1)
    return -1;

  tm.tm_year = ToYear (yyYear) - TM_YEAR_ORIGIN + yyRelYear;
  tm.tm_mon = yyMonth - 1 + yyRelMonth;
  tm.tm_mday = yyDay + yyRelDay;
  if ((yyHaveTime != 0) ||
      ( (yyHaveRel != 0) && (yyHaveDate == 0) && (yyHaveDay == 0) ))
    {
      tm.tm_hour = ToHour (yyHour, yyMeridian);
      if (tm.tm_hour < 0)
	return -1;
      tm.tm_min = yyMinutes;
      tm.tm_sec = yySeconds;
    }
  else
    {
      tm.tm_hour = tm.tm_min = tm.tm_sec = 0;
    }
  tm.tm_hour += yyRelHour;
  tm.tm_min += yyRelMinutes;
  tm.tm_sec += yyRelSeconds;
  tm.tm_isdst = 0;

  Start = timegm(&tm);

  if (Start == (time_t) -1)
    {
	return Start;
    }

  if (yyHaveDay && !yyHaveDate)
    {
      tm.tm_mday += ((yyDayNumber - tm.tm_wday + 7) % 7
		     + 7 * (yyDayOrdinal - (0 < yyDayOrdinal)));
      Start = timegm(&tm);
      if (Start == (time_t) -1)
	return Start;
    }

  return Start;
}

#if	defined (TEST)

int
main(void)
{
  char buff[MAX_BUFF_LEN + 1];
  time_t d;

  (void) printf ("Enter date, or blank line to exit.\n\t> ");
  (void) fflush (stdout);

  buff[MAX_BUFF_LEN] = 0;
  while (fgets (buff, MAX_BUFF_LEN, stdin) && buff[0])
    {
      d = get_date(buff, NULL);
      if (d == -1)
	(void) printf ("Bad format - couldn't convert.\n");
      else
	(void) printf ("%s", ctime (&d));
      (void) printf ("\t> ");
      (void) fflush (stdout);
    }
  exit (0);
  /* NOTREACHED */
}
#endif /* defined (TEST) */
