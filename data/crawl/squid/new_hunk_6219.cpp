#endif

#if PURIFY
#define assert(EX) ((void)0)
#elif __STDC__
#define assert(EX)  ((EX)?((void)0):xassert( # EX , __FILE__, __LINE__))
#else
#define assert(EX)  ((EX)?((void)0):xassert("EX", __FILE__, __LINE__))
#endif

#if HAVE_UNISTD_H
