ftp_parse_vms_ls (const char *file)
{
  FILE *fp;
  /* #### A third copy of more-or-less the same array ? */
  static const char *months[] = {
    "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
    "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
  };
  int i;
  int year, month, day;          /* for time analysis */
  int hour, min, sec;
  struct tm timestruct;

  char *line, *tok;              /* tokenizer */
  struct fileinfo *dir, *l, cur; /* list creation */

  fp = fopen (file, "rb");
  if (!fp)
    {
      logprintf (LOG_NOTQUIET, "%s: %s\n", file, strerror (errno));
