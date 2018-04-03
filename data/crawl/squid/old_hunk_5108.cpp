#else
#define assert(EX)  ((EX)?((void)0):xassert("EX", __FILE__, __LINE__))
#endif

#if HAVE_UNISTD_H
#include <unistd.h>
