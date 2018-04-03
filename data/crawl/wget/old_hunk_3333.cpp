  DEBUGP (("Closing fd %d\n", x));		\
} while (0)

/* Define a large ("very long") type useful for storing large
   non-negative quantities that exceed sizes of normal download.  Note
   that this has nothing to do with large file support.  For example,
   one should be able to say `--quota=10G', large files
   notwithstanding.

   On the machines where `long' is 64-bit, we use long.  Otherwise, we
   check whether `long long' is available and if yes, use that.  If
   long long is unavailable, we give up and just use `long'.

   Note: you cannot use VERY_LONG_TYPE along with printf().  When you
   need to print it, use very_long_to_string().  */

#if SIZEOF_LONG >= 8 || SIZEOF_LONG_LONG == 0
/* either long is "big enough", or long long is unavailable which
   leaves long as the only choice. */ 
# define VERY_LONG_TYPE   unsigned long
#else  /* use long long */
/* long is smaller than 8 bytes, but long long is available. */
# define VERY_LONG_TYPE   unsigned long long
#endif /* use long long */

/* These are defined in cmpt.c if missing, therefore it's generally
   safe to declare their parameters.  */
