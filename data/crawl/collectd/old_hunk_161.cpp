  (c)->errbuf[sizeof ((c)->errbuf) - 1] = 0; \
} while (0)

#if COLLECT_DEBUG
# define LCC_DEBUG(...) printf (__VA_ARGS__)
#else
# define LCC_DEBUG(...) /**/
#endif

/*
 * Types
 */
