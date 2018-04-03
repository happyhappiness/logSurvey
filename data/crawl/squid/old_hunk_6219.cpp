#endif

#if PURIFY
/* disable assert() under purify */
#define NODEBUG
#endif

#if HAVE_UNISTD_H
