struct fileinfo *
ftp_parse_ls (const char *file, const enum stype system_type)
{
  if (system_type == ST_UNIX)
    {
      return ftp_parse_unix_ls (file);
    }
  else
    {
#ifdef HAVE_FTPPARSE
      return ftp_parse_nonunix_ls (file);
#else
