
#ifdef ENABLE_DEBUG
/* The same as logprintf(), but does anything only if opt.debug is
   non-zero.  */
void
debug_logprintf (const char *fmt, ...)
{
