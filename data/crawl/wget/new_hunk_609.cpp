ftp_parse_vms_ls (const char *file)
{
  FILE *fp;
  int dt, i, j, len;
  int perms;
  time_t timenow;
  struct tm timestruct;
  char date_str[ 32];

  char *line, *tok;		 /* tokenizer */
  struct fileinfo *dir, *l, cur; /* list creation */

  fp = fopen (file, "r");
  if (!fp)
    {
      logprintf (LOG_NOTQUIET, "%s: %s\n", file, strerror (errno));
