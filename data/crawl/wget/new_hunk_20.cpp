#endif /* not O_EXCL */
}

/* fopen_stat() assumes that file_exists_p() was called earlier.
   file_stats_t passed to this function was returned from file_exists_p()
   This is to prevent TOCTTOU race condition.
   Details : FIO45-C from https://www.securecoding.cert.org/
   Note that for creating a new file, this check is not useful

   Input:
     fname  => Name of file to open
     mode   => File open mode
     fstats => Saved file_stats_t about file that was checked for existence

   Returns:
     NULL if there was an error
     FILE * of opened file stream
*/
FILE *
fopen_stat(const char *fname, const char *mode, file_stats_t *fstats)
{
  int fd;
  FILE *fp;
  struct stat fdstats;

  fp = fopen (fname, mode);
  if (fp == NULL)
  {
    logprintf (LOG_NOTQUIET, _("Failed to Fopen file %s\n"), fname);
    return NULL;
  }
  fd = fileno (fp);
  if (fd < 0)
  {
    logprintf (LOG_NOTQUIET, _("Failed to get FD for file %s\n"), fname);
    fclose (fp);
    return NULL;
  }
  memset(&fdstats, 0, sizeof(fdstats));
  if (fstat (fd, &fdstats) == -1)
  {
    logprintf (LOG_NOTQUIET, _("Failed to stat file %s, (check permissions)\n"), fname);
    fclose (fp);
    return NULL;
  }
#if !(defined(WINDOWS) || defined(__VMS))
  if (fstats != NULL &&
      (fdstats.st_dev != fstats->st_dev ||
       fdstats.st_ino != fstats->st_ino))
  {
    /* File changed since file_exists_p() : NOT SAFE */
    logprintf (LOG_NOTQUIET, _("File %s changed since the last check. Security check failed."), fname);
    fclose (fp);
    return NULL;
  }
#endif

  return fp;
}

/* open_stat assumes that file_exists_p() was called earlier to save file_stats
   file_stats_t passed to this function was returned from file_exists_p()
   This is to prevent TOCTTOU race condition.
   Details : FIO45-C from https://www.securecoding.cert.org/
   Note that for creating a new file, this check is not useful


   Input:
     fname  => Name of file to open
     flags  => File open flags
     mode   => File open mode
     fstats => Saved file_stats_t about file that was checked for existence

   Returns:
     -1 if there was an error
     file descriptor of opened file stream
*/
int
open_stat(const char *fname, int flags, mode_t mode, file_stats_t *fstats)
{
  int fd;
  struct stat fdstats;

  fd = open (fname, flags, mode);
  if (fd < 0)
  {
    logprintf (LOG_NOTQUIET, _("Failed to open file %s, reason :%s\n"), fname, strerror(errno));
    return -1;
  }
  memset(&fdstats, 0, sizeof(fdstats));
  if (fstat (fd, &fdstats) == -1)
  {
    logprintf (LOG_NOTQUIET, _("Failed to stat file %s, error: %s\n"), fname, strerror(errno));
    return -1;
  }
#if !(defined(WINDOWS) || defined(__VMS))
  if (fstats != NULL &&
      (fdstats.st_dev != fstats->st_dev ||
       fdstats.st_ino != fstats->st_ino))
  {
    /* File changed since file_exists_p() : NOT SAFE */
    logprintf (LOG_NOTQUIET, _("Trying to open file %s but it changed since last check. Security check failed."), fname);
    close (fd);
    return -1;
  }
#endif

  return fd;
}

/* Create DIRECTORY.  If some of the pathname components of DIRECTORY
   are missing, create them first.  In case any mkdir() call fails,
   return its error status.  Returns 0 on successful completion.
