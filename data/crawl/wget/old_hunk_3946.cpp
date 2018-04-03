  return dir;
}

/* This function is just a stub.  It should actually accept some kind
   of information what system it is running on -- e.g. FPL_UNIX,
   FPL_DOS, FPL_NT, FPL_VMS, etc. and a "guess-me" value, like
   FPL_GUESS.  Then it would call the appropriate parsers to fill up
   fileinfos.

   Since we currently support only the Unix FTP servers, this function
   simply returns the result of ftp_parse_unix_ls().  */
struct fileinfo *
ftp_parse_ls (const char *file)
{
  return ftp_parse_unix_ls (file);
}

/* Stuff for creating FTP index. */
