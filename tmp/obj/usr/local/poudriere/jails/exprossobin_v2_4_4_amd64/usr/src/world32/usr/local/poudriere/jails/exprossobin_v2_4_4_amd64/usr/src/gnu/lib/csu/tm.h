#ifndef GCC_TM_H
#define GCC_TM_H
#ifdef IN_GCC
# include "options.h"
# include "i386/biarch64.h"
# include "i386/i386.h"
# include "i386/unix.h"
# include "i386/att.h"
# include "dbxelf.h"
# include "elfos-undef.h"
# include "elfos.h"
# include "freebsd-native.h"
# include "freebsd-spec.h"
# include "freebsd.h"
# include "i386/x86-64.h"
# include "i386/freebsd.h"
# include "i386/freebsd64.h"
# include "defaults.h"
#endif
#if defined IN_GCC && !defined GENERATOR_FILE && !defined USED_FOR_TARGET
# include "insn-constants.h"
# include "insn-flags.h"
#endif
#endif /* GCC_TM_H */
#define EXTRA_MODES_FILE "i386/i386-modes.def"
