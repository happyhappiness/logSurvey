 #include "dep.h"
 #include "debug.h"
 
-/* Variadic functions.  We go through contortions to allow proper function
-   prototypes for both ANSI and pre-ANSI C compilers, and also for those
-   which support stdarg.h vs. varargs.h, and finally those which have
-   vfprintf(), etc. and those who have _doprnt... or nothing.
-
-   This fancy stuff all came from GNU fileutils, except for the VA_PRINTF and
-   VA_END macros used here since we have multiple print functions.  */
-
-#if USE_VARIADIC
-# if HAVE_STDARG_H
-#  include <stdarg.h>
-#  define VA_START(args, lastarg) va_start(args, lastarg)
-# else
-#  include <varargs.h>
-#  define VA_START(args, lastarg) va_start(args)
-# endif
-# if HAVE_VPRINTF
-#  define VA_PRINTF(fp, lastarg, args) vfprintf((fp), (lastarg), (args))
-# else
-#  define VA_PRINTF(fp, lastarg, args) _doprnt((lastarg), (args), (fp))
-# endif
-# define VA_END(args) va_end(args)
-#else
-/* We can't use any variadic interface! */
-# define va_alist a1, a2, a3, a4, a5, a6, a7, a8
-# define va_dcl char *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8;
-# define VA_START(args, lastarg)
-# define VA_PRINTF(fp, lastarg, args) fprintf((fp), (lastarg), va_alist)
-# define VA_END(args)
-#endif
+/* GNU make no longer supports pre-ANSI89 environments.  */
+
+#include <stdarg.h>
 
 
 /* Compare strings *S1 and *S2.
