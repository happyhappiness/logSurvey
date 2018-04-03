  DEBUGP (("Closing fd %d\n", x));		\
} while (0)

/* Define a large integral type useful for storing large sizes that
   exceed sizes of one download, such as when printing the sum of all
   downloads.  Note that this has nothing to do with large file
   support, yet.

   We use a 64-bit integral type where available, `double' otherwise.
   It's hard to print LARGE_INT's portably, but fortunately it's
   rarely needed.  */

#if SIZEOF_LONG >= 8
/* Long is large enough: use it.  */
typedef long LARGE_INT;
# define LARGE_INT_FMT "%ld"
#else
# if SIZEOF_LONG_LONG == 8
/* Long long is large enough: use it.  */
typedef long long LARGE_INT;
#  define LARGE_INT_FMT "%lld"
# else
/* Use `double'. */
typedef double LARGE_INT;
#  define LARGE_INT_FMT "%.0f"
# endif
#endif

/* These are defined in cmpt.c if missing, therefore it's generally
   safe to declare their parameters.  */
