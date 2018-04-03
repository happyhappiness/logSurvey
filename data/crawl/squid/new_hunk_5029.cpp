#define IPPROTO_TCP 0
#endif

#ifndef PRIu64 /* ISO C99 Standard printf() macro for 64 bit unsigned int */
#ifdef _SQUID_MSWIN_ /* Windows native port using MSVCRT */
#define PRIu64 "I64u"
#else
#define PRIu64 "llu"
#endif /* _SQUID_MSWIN_ */
#endif /* PRIu64 */

#endif /* SQUID_H */