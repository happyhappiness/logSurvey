
/* Write data in BUF to OUT.  However, if *SKIP is non-zero, skip that
   amount of data and decrease SKIP.  Increment *TOTAL by the amount
   of data written.  */

static int
write_data (FILE *out, const char *buf, int bufsize, wgint *skip,
            wgint *written)
{
  if (!out)
    return 1;
  if (*skip > bufsize)
    {
