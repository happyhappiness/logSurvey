#ifdef DEBUG
/* The same as logprintf(), but does anything only if opt.debug is
   non-zero.  */
void
debug_logprintf (const char *fmt, ...)
{
  if (opt.debug)
    {
      va_list args;
      struct logvprintf_state lpstate;
      int done;

