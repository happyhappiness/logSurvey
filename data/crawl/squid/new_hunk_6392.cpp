    exit(1);
}

/* printf-style interface for fatal */
#ifdef __STDC__
void
fatalf(const char *fmt,...)
{
    va_list args;
    va_start(args, fmt);
#else
void
fatalf(va_alist)
     va_dcl
{
    va_list args;
    const char *fmt = NULL;
    va_start(args);
    fmt = va_arg(args, char *);
#endif
    fatalvf(fmt, args);
    va_end(args);
}


/* used by fatalf */
static void
fatalvf(const char *fmt, va_list args)
{
    static char fatal_str[BUFSIZ];
    vsnprintf(fatal_str, sizeof(fatal_str), fmt, args);
    fatal(fatal_str);
}

/* fatal with dumping core */
void
fatal_dump(const char *message)
