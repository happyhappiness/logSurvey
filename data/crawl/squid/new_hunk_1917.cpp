                    ((__foo=strrchr(__FILE__,'/'))==NULL?__FILE__:__foo+1),\
                    __LINE__);\
                    fprintf(stderr,X); }
#else /* __GNUC__ */
static void
debug(char *format,...)
{
    if (debug_enabled) {
        va_list args;

