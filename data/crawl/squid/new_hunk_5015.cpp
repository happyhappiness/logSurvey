#ifndef PRIu64 /* ISO C99 Standard printf() macro for 64 bit unsigned int */
#ifdef _SQUID_MSWIN_ /* Windows native port using MSVCRT */
#define PRIu64 "I64u"
/* FIXME: Temporary hack to allow the build on Digital/Compaq/HP Tru64 Unix.
   Long term solution: add type size detect in configure like Squid 2.5 and
   define PRIu64 according to the size of long int and int64_t.      
 */
#elif defined(__alpha) && defined(_SQUID_OSF_)
#define PRIu64 "lu"
#else
#define PRIu64 "llu"
#endif /* _SQUID_MSWIN_ */
