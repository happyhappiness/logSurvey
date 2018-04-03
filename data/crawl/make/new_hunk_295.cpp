
/* Write a string to the current STDOUT or STDERR.  */
static void
_outputs (struct output *out, int is_err, const char *msg)
{
  if (! out || ! out->syncout)
    {
      FILE *f = is_err ? stderr : stdout;
      fputs (msg, f);
