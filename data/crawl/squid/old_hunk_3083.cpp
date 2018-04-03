#define error(X...) \
                     fprintf(stderr, "%s(%d): pid=%ld :", __FILE__, __LINE__, (long)getpid() ); \
                     fprintf(stderr,X); \

#define warn(X...) \
                     fprintf(stderr, "%s(%d): pid=%ld :", __FILE__, __LINE__, (long)getpid() ); \
                     fprintf(stderr,X); \

#else /* __GNUC__ */

/* non-GCC compilers can't do the above macro define yet. */
