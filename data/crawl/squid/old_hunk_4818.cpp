#else
#define assert(EX)  ((EX)?((void)0):xassert("EX", __FILE__, __LINE__))
#endif
extern void xassert(const char *, const char *, int);

#endif