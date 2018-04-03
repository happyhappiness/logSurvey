void
touch (const char *file, time_t tm)
{
  struct utimbuf times;

  times.modtime = tm;
  times.actime = time (NULL);

  if (utime (file, &times) == -1)
    logprintf (LOG_NOTQUIET, "utime(%s): %s\n", file, strerror (errno));
}

/* Checks if FILE is a symbolic link, and removes it if it is.  Does
