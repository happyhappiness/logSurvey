#ifdef DEBUG
/* The same as logprintf(), but does anything only if opt.debug is
   non-zero.  */
#ifdef USE_STDARG
void
debug_logprintf (const char *fmt, ...)
#else  /* not USE_STDARG */
void
debug_logprintf (va_alist)
     va_dcl
#endif /* not USE_STDARG */
{
  if (opt.debug)
    {
      va_list args;
#ifndef USE_STDARG
      const char *fmt;
#endif

#ifdef USE_STDARG
      va_start (args, fmt);
#else
      va_start (args);
