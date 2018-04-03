  DEBUGP (("Closing fd %d\n", x));		\
} while (0)

/* Define a large ("very long") type useful for storing large
   non-negative quantities that exceed sizes of normal download, such
   as the *total* number of bytes downloaded.  To fit today's needs,
   this needs to be an integral type at least 64 bits wide.  On the
   machines where `long' is 64-bit, we use long.  Otherwise, we check
   whether `long long' is available and if yes, use that.  If long
   long is unavailable, we give up and just use `long'.

   This check could be smarter and moved to configure, which could
   check for a bunch of non-standard types such as uint64_t.  But I
   don't see the need for it -- the current test will work on all
   modern architectures, and if it fails, nothing bad happens, we just
   end up with long.

   Note: you cannot use VERY_LONG_TYPE along with printf().  When you
   need to print it, use very_long_to_string().  */

#if (SIZEOF_LONG >= 8) || !defined(HAVE_LONG_LONG)
/* either long is "big enough", or long long is unavailable which
   leaves long as the only choice. */ 
# define VERY_LONG_TYPE   unsigned long
#else  /* use long long */
/* long is smaller than 8 bytes, but long long is available. */
# define VERY_LONG_TYPE   unsigned long long
#endif /* use long long */

/* Defined in cmpt.c: */
