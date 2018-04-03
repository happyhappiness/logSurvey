  DEBUGP (("Closing fd %d\n", x));		\
} while (0)

/* Define a "very long" type useful for storing large non-negative
   integers, e.g. the total number of bytes downloaded.  This needs to
   be an integral type at least 64 bits wide.  On the machines where
   `long' is 64-bit, we use long.  Otherwise, we check whether `long
   long' is available and if yes, use that.  Otherwise, we give up and
   just use `long'.  */
#if (SIZEOF_LONG >= 8) || !defined(HAVE_LONG_LONG)
# define VERY_LONG_TYPE   unsigned long
# define VERY_LONG_FORMAT "%lu"
#else  /* long is smaller than 8 bytes, but long long is available. */
# define VERY_LONG_TYPE   unsigned long long
# define VERY_LONG_FORMAT "%llu"
#endif /* use long long */

/* Defined in cmpt.c: */
