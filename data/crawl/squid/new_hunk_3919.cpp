#else
#define assert(EX)  ((EX)?((void)0):xassert("EX", __FILE__, __LINE__))
#endif

#ifdef __cplusplus
extern "C" void
#else
extern void
#endif
xassert(const char *, const char *, int);

#endif /* SQUID_ASSERT_H */
