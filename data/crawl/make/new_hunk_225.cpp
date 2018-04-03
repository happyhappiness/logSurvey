
#define NILF ((gmk_floc *)0)

#define CSTRLEN(_s)           (sizeof (_s)-1)
#define STRING_SIZE_TUPLE(_s) (_s), CSTRLEN(_s)

/* The number of bytes needed to represent the largest integer as a string.  */
#define INTSTR_LENGTH         CSTRLEN ("18446744073709551616")


const char *concat (unsigned int, ...);
void message (int prefix, size_t length, const char *fmt, ...)
              __attribute__ ((__format__ (__printf__, 3, 4)));
void error (const gmk_floc *flocp, size_t length, const char *fmt, ...)
            __attribute__ ((__format__ (__printf__, 3, 4)));
void fatal (const gmk_floc *flocp, size_t length, const char *fmt, ...)
                   __attribute__ ((noreturn, __format__ (__printf__, 3, 4)));

#define O(_t,_a,_f)           _t((_a), 0, (_f))
#define OS(_t,_a,_f,_s)       _t((_a), strlen (_s), (_f), (_s))
#define OSS(_t,_a,_f,_s1,_s2) _t((_a), strlen (_s1) + strlen (_s2), \
                                 (_f), (_s1), (_s2))
#define OSSS(_t,_a,_f,_s1,_s2,_s3) _t((_a), strlen (_s1) + strlen (_s2) + strlen (_s3), \
                                      (_f), (_s1), (_s2), (_s3))
#define ON(_t,_a,_f,_n)       _t((_a), INTSTR_LENGTH, (_f), (_n))
#define ONN(_t,_a,_f,_n1,_n2) _t((_a), INTSTR_LENGTH*2, (_f), (_n1), (_n2))

#define OSN(_t,_a,_f,_s,_n)   _t((_a), strlen (_s) + INTSTR_LENGTH, \
                                 (_f), (_s), (_n))
#define ONS(_t,_a,_f,_n,_s)   _t((_a), INTSTR_LENGTH + strlen (_s), \
                                 (_f), (_n), (_s))

#define OUT_OF_MEM() O (fatal, NILF, _("virtual memory exhausted"))

void die (int) __attribute__ ((noreturn));
void pfatal_with_name (const char *) __attribute__ ((noreturn));
