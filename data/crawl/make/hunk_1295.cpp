   (! INTEGER_TYPE_SIGNED (t) ? (t) 0 : ~ (t) 0 << (sizeof (t) * CHAR_BIT - 1))
 #define INTEGER_TYPE_MAXIMUM(t) (~ (t) 0 - INTEGER_TYPE_MINIMUM (t))
 
-#ifdef	STAT_MACROS_BROKEN
-#ifdef	S_ISREG
-#undef	S_ISREG
-#endif
-#ifdef	S_ISDIR
-#undef	S_ISDIR
-#endif
-#endif	/* STAT_MACROS_BROKEN.  */
+#ifdef STAT_MACROS_BROKEN
+# ifdef S_ISREG
+#  undef S_ISREG
+# endif
+# ifdef S_ISDIR
+#  undef S_ISDIR
+# endif
+#endif  /* STAT_MACROS_BROKEN.  */
 
-#ifndef	S_ISREG
-#define	S_ISREG(mode)	(((mode) & S_IFMT) == S_IFREG)
+#ifndef S_ISREG
+# define S_ISREG(mode)  (((mode) & S_IFMT) == S_IFREG)
 #endif
-#ifndef	S_ISDIR
-#define	S_ISDIR(mode)	(((mode) & S_IFMT) == S_IFDIR)
+#ifndef S_ISDIR
+# define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
 #endif
 
 #ifdef VMS
-#include <stdio.h>
-#include <types.h>
-#include <unixlib.h>
-#include <unixio.h>
-#include <errno.h>
-#include <perror.h>
+# include <stdio.h>
+# include <types.h>
+# include <unixlib.h>
+# include <unixio.h>
+# include <errno.h>
+# include <perror.h>
 #endif
 
-#if	(defined (STDC_HEADERS) || defined (__GNU_LIBRARY__) || defined(VMS))
-#include <stdlib.h>
-#include <string.h>
-#define	ANSI_STRING
-#else	/* No standard headers.  */
-
-#ifdef HAVE_STRING_H
-#include <string.h>
-#define	ANSI_STRING
-#else
-#include <strings.h>
-#endif
-#ifdef	HAVE_MEMORY_H
-#include <memory.h>
+#ifndef __attribute__
+/* This feature is available in gcc versions 2.5 and later.  */
+# if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__
+#  define __attribute__(x)
+# endif
+/* The __-protected variants of `format' and `printf' attributes
+   are accepted by gcc versions 2.6.4 (effectively 2.7) and later.  */
+# if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 7)
+#  define __format__ format
+#  define __printf__ printf
+# endif
 #endif
 
+#if defined (STDC_HEADERS) || defined (__GNU_LIBRARY__)
+# include <stdlib.h>
+# include <string.h>
+# define ANSI_STRING 1
+#else   /* No standard headers.  */
+# ifdef HAVE_STRING_H
+#  include <string.h>
+#  define ANSI_STRING 1
+# else
+#  include <strings.h>
+# endif
+# ifdef HAVE_MEMORY_H
+#  include <memory.h>
+# endif
+# ifdef HAVE_STDLIB_H
+#  include <stdlib.h>
+# else
 extern char *malloc PARAMS ((int));
 extern char *realloc PARAMS ((char *, int));
 extern void free PARAMS ((char *));
 
-extern void abort PARAMS ((void));
-extern void exit PARAMS ((int));
+extern void abort PARAMS ((void)) __attribute__ ((noreturn));
+extern void exit PARAMS ((int)) __attribute__ ((noreturn));
+# endif /* HAVE_STDLIB_H.  */
 
-#endif	/* Standard headers.  */
+#endif /* Standard headers.  */
 
-#ifdef	ANSI_STRING
-
-#ifndef	index
-#define	index(s, c)	strchr((s), (c))
-#endif
-#ifndef	rindex
-#define	rindex(s, c)	strrchr((s), (c))
+#if ST_MTIM_NSEC
+# if HAVE_INTTYPES_H
+#  include <inttypes.h>
+# endif
+# define FILE_TIMESTAMP uintmax_t
+#else
+# define FILE_TIMESTAMP time_t
 #endif
 
-#ifndef	bcmp
-#define bcmp(s1, s2, n)	memcmp ((s1), (s2), (n))
-#endif
-#ifndef	bzero
-#define bzero(s, n)	memset ((s), 0, (n))
-#endif
-#if defined(HAVE_MEMMOVE) && !defined(bcopy)
-#define bcopy(s, d, n)	memmove ((d), (s), (n))
-#endif
+#ifdef  ANSI_STRING
 
-#else	/* Not ANSI_STRING.  */
+# ifndef index
+#  define index(s, c)       strchr((s), (c))
+# endif
+# ifndef rindex
+#  define rindex(s, c)      strrchr((s), (c))
+# endif
 
-#ifndef	bcmp
-extern int bcmp ();
-#endif
-#ifndef	bzero
-extern void bzero ();
-#endif
-#ifndef	bcopy
-extern void bcopy ();
+# ifndef bcmp
+#  define bcmp(s1, s2, n)   memcmp ((s1), (s2), (n))
+# endif
+# ifndef bzero
+#  define bzero(s, n)       memset ((s), 0, (n))
+# endif
+# if defined(HAVE_MEMMOVE) && !defined(bcopy)
+#  define bcopy(s, d, n)    memmove ((d), (s), (n))
+# endif
+
+#else   /* Not ANSI_STRING.  */
+
+# ifndef bcmp
+extern int bcmp PARAMS ((const char *, const char *, int));
+# endif
+# ifndef bzero
+extern void bzero PARAMS ((char *, int));
 #endif
+# ifndef bcopy
+extern void bcopy PARAMS ((const char *b1, char *b2, int));
+# endif
 
-#endif	/* ANSI_STRING.  */
-#undef	ANSI_STRING
+#endif  /* ANSI_STRING.  */
+#undef  ANSI_STRING
 
 /* SCO Xenix has a buggy macro definition in <string.h>.  */
-#undef	strerror
+#undef  strerror
 
 #if !defined(ANSI_STRING) && !defined(__DECC)
 extern char *strerror PARAMS ((int errnum));
 #endif
 
-#ifndef __attribute__
-# if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 5)
-#  define __attribute__(x)
-# endif
-#endif
-
-#ifdef	__GNUC__
-#undef	alloca
-#define	alloca(n)	__builtin_alloca (n)
-#else	/* Not GCC.  */
-#ifdef	HAVE_ALLOCA_H
-#include <alloca.h>
-#else	/* Not HAVE_ALLOCA_H.  */
-#ifndef	_AIX
+#ifdef __GNUC__
+# undef alloca
+# define alloca(n)      __builtin_alloca (n)
+#else   /* Not GCC.  */
+# ifdef HAVE_ALLOCA_H
+#  include <alloca.h>
+# else /* Not HAVE_ALLOCA_H.  */
+#  ifndef _AIX
 extern char *alloca ();
-#endif	/* Not AIX.  */
-#endif	/* HAVE_ALLOCA_H.  */
-#endif	/* GCC.  */
-
-#ifndef	iAPX286
-#define streq(a, b) \
-  ((a) == (b) || \
-   (*(a) == *(b) && (*(a) == '\0' || !strcmp ((a) + 1, (b) + 1))))
-#ifdef HAVE_CASE_INSENSITIVE_FS
-#define strieq(a, b) \
-  ((a) == (b) || \
-   (tolower(*(a)) == tolower(*(b)) && (*(a) == '\0' || !strcmpi ((a) + 1, (b) + 1))))
-#else
-#define strieq(a, b) \
-  ((a) == (b) || \
-   (*(a) == *(b) && (*(a) == '\0' || !strcmp ((a) + 1, (b) + 1))))
-#endif
+#  endif /* Not AIX.  */
+# endif /* HAVE_ALLOCA_H.  */
+#endif /* GCC.  */
+
+#ifndef iAPX286
+# define streq(a, b) \
+   ((a) == (b) || \
+    (*(a) == *(b) && (*(a) == '\0' || !strcmp ((a) + 1, (b) + 1))))
+# ifdef HAVE_CASE_INSENSITIVE_FS
+#  define strieq(a, b) \
+    ((a) == (b) || \
+     (tolower(*(a)) == tolower(*(b)) && (*(a) == '\0' || !strcmpi ((a) + 1, (b) + 1))))
+# else
+#  define strieq(a, b) \
+    ((a) == (b) || \
+     (*(a) == *(b) && (*(a) == '\0' || !strcmp ((a) + 1, (b) + 1))))
+# endif
 #else
 /* Buggy compiler can't handle this.  */
-#define streq(a, b) (strcmp ((a), (b)) == 0)
-#define strieq(a, b) (strcmp ((a), (b)) == 0)
+# define streq(a, b) (strcmp ((a), (b)) == 0)
+# define strieq(a, b) (strcmp ((a), (b)) == 0)
 #endif
 
 /* Add to VAR the hashing value of C, one character in a name.  */
-#define	HASH(var, c) \
+#define HASH(var, c) \
   ((var += (c)), (var = ((var) << 7) + ((var) >> 20)))
 #ifdef HAVE_CASE_INSENSITIVE_FS /* Fold filenames */
-#define HASHI(var, c) \
-  ((var += tolower((c))), (var = ((var) << 7) + ((var) >> 20)))
+# define HASHI(var, c) \
+   ((var += tolower((c))), (var = ((var) << 7) + ((var) >> 20)))
 #else
-#define HASHI(var, c) HASH(var,c)
+# define HASHI(var, c) HASH(var,c)
 #endif
 
 #if defined(__GNUC__) || defined(ENUM_BITFIELDS)
-#define	ENUM_BITFIELD(bits)	:bits
+# define ENUM_BITFIELD(bits)    :bits
 #else
-#define	ENUM_BITFIELD(bits)
+# define ENUM_BITFIELD(bits)
 #endif
 
 #if defined(__MSDOS__) || defined(WINDOWS32)
-#define PATH_SEPARATOR_CHAR ';'
-#else
-#if defined(VMS)
-#define PATH_SEPARATOR_CHAR ','
+# define PATH_SEPARATOR_CHAR ';'
 #else
-#define PATH_SEPARATOR_CHAR ':'
-#endif
+# if defined(VMS)
+#  define PATH_SEPARATOR_CHAR ','
+# else
+#  define PATH_SEPARATOR_CHAR ':'
+# endif
 #endif
 
 #ifdef WINDOWS32
-#include <fcntl.h>
-#include <malloc.h>
-#define pipe(p) _pipe(p, 512, O_BINARY)
-#define kill(pid,sig) w32_kill(pid,sig)
+# include <fcntl.h>
+# include <malloc.h>
+# define pipe(p) _pipe(p, 512, O_BINARY)
+# define kill(pid,sig) w32_kill(pid,sig)
 
 extern void sync_Path_environment(void);
 extern int kill(int pid, int sig);
 extern int safe_stat(char *file, struct stat *sb);
-extern char *end_of_token_w32();
+extern char *end_of_token_w32(char *s, char stopchar);
 extern int find_and_set_default_shell(char *token);
 
 /* indicates whether or not we have Bourne shell */
