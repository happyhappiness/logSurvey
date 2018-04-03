 #include "protos.h"
 #include "globals.h"
 
-/* Exclude CPPUnit tests from the below restriction. */
-/* BSD implementation uses these still */
-#if !defined(SQUID_UNIT_TEST)
-/*
- * Squid source files should not call these functions directly.
- * Use xmalloc, xfree, xcalloc, snprintf, and xstrdup instead.
- * Also use xmemcpy, xisspace, ...
- */
-#ifndef malloc
-#define malloc +
-#endif
-template <class V>
-void free(V x) { fatal("Do not use ::free()"); }
-#ifndef calloc
-#define calloc +
-#endif
-#ifndef sprintf
-#define sprintf +
-#endif
-#ifndef strdup
-#define strdup +
-#endif
-#endif /* !SQUID_UNIT_TEST */
-
-/*
- * Hey dummy, don't be tempted to move this to lib/config.h.in
- * again.  O_NONBLOCK will not be defined there because you didn't
- * #include <fcntl.h> yet.
- */
-#if defined(_SQUID_SUNOS_)
-/*
- * We assume O_NONBLOCK is broken, or does not exist, on SunOS.
- */
-#define SQUID_NONBLOCK O_NDELAY
-#elif defined(O_NONBLOCK)
-/*
-* We used to assume O_NONBLOCK was broken on Solaris, but evidence
-* now indicates that its fine on Solaris 8, and in fact required for
-* properly detecting EOF on FIFOs.  So now we assume that if
-* its defined, it works correctly on all operating systems.
-*/
-#define SQUID_NONBLOCK O_NONBLOCK
-/*
-* O_NDELAY is our fallback.
-*/
-#else
-#define SQUID_NONBLOCK O_NDELAY
-#endif
-
 /*
  * I'm sick of having to keep doing this ..
  */
