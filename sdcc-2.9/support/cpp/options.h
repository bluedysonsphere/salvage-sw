/* This file is auto-generated by opts.sh.  */

#ifndef OPTIONS_H
#define OPTIONS_H

extern int target_flags;

extern int flag_fatal_errors;
extern int warn_traditional;
extern int pedantic;
extern int inhibit_warnings;




#define CL_SDCPP      (1 << 0)

enum opt_code
{
  OPT__help,                                 /* --help */
  OPT__version,                              /* --version */
  OPT_A,                                     /* -A */
  OPT_C,                                     /* -C */
  OPT_CC,                                    /* -CC */
  OPT_D,                                     /* -D */
  OPT_H,                                     /* -H */
  OPT_I,                                     /* -I */
  OPT_M,                                     /* -M */
  OPT_MD,                                    /* -MD */
  OPT_MF,                                    /* -MF */
  OPT_MG,                                    /* -MG */
  OPT_MM,                                    /* -MM */
  OPT_MMD,                                   /* -MMD */
  OPT_MP,                                    /* -MP */
  OPT_MQ,                                    /* -MQ */
  OPT_MT,                                    /* -MT */
  OPT_P,                                     /* -P */
  OPT_U,                                     /* -U */
  OPT_Wall,                                  /* -Wall */
  OPT_Wcomment,                              /* -Wcomment */
  OPT_Wcomments,                             /* -Wcomments */
  OPT_Wdeprecated,                           /* -Wdeprecated */
  OPT_Wendif_labels,                         /* -Wendif-labels */
  OPT_Werror,                                /* -Werror */
  OPT_Wfatal_errors,                         /* -Wfatal-errors */
  OPT_Wimport,                               /* -Wimport */
  OPT_Wsystem_headers,                       /* -Wsystem-headers */
  OPT_Wtraditional,                          /* -Wtraditional */
  OPT_Wtrigraphs,                            /* -Wtrigraphs */
  OPT_Wundef,                                /* -Wundef */
  OPT_Wunused_macros,                        /* -Wunused-macros */
  OPT_Wvariadic_macros,                      /* -Wvariadic-macros */
  OPT_ansi,                                  /* -ansi */
  OPT_d,                                     /* -d */
  OPT_fdollars_in_identifiers,               /* -fdollars-in-identifiers */
  OPT_fexec_charset_,                        /* -fexec-charset= */
  OPT_finput_charset_,                       /* -finput-charset= */
  OPT_fpreprocessed,                         /* -fpreprocessed */
  OPT_fshow_column,                          /* -fshow-column */
  OPT_fsigned_char,                          /* -fsigned-char */
  OPT_ftabstop_,                             /* -ftabstop= */
  OPT_funsigned_char,                        /* -funsigned-char */
  OPT_fwide_exec_charset_,                   /* -fwide-exec-charset= */
  OPT_fworking_directory,                    /* -fworking-directory */
  OPT_idirafter,                             /* -idirafter */
  OPT_imacros,                               /* -imacros */
  OPT_imultilib,                             /* -imultilib */
  OPT_include,                               /* -include */
  OPT_iprefix,                               /* -iprefix */
  OPT_iquote,                                /* -iquote */
  OPT_isysroot,                              /* -isysroot */
  OPT_isystem,                               /* -isystem */
  OPT_iwithprefix,                           /* -iwithprefix */
  OPT_iwithprefixbefore,                     /* -iwithprefixbefore */
  OPT_lang_asm,                              /* -lang-asm */
  OPT_lang_objc,                             /* -lang-objc */
  OPT_nostdinc,                              /* -nostdinc */
  OPT_o,                                     /* -o */
  OPT_obj_ext_,                              /* -obj-ext= */
  OPT_pedantic,                              /* -pedantic */
  OPT_pedantic_errors,                       /* -pedantic-errors */
  OPT_pedantic_parse_number,                 /* -pedantic-parse-number */
  OPT_remap,                                 /* -remap */
  OPT_std_c89,                               /* -std=c89 */
  OPT_std_c99,                               /* -std=c99 */
  OPT_std_iso9899_1990,                      /* -std=iso9899:1990 */
  OPT_std_iso9899_199409,                    /* -std=iso9899:199409 */
  OPT_std_iso9899_1999,                      /* -std=iso9899:1999 */
  OPT_traditional_cpp,                       /* -traditional-cpp */
  OPT_trigraphs,                             /* -trigraphs */
  OPT_v,                                     /* -v */
  OPT_w,                                     /* -w */
  N_OPTS
};

#endif /* OPTIONS_H */
