void
touch (const char *file, time_t tm)
{
  struct timeval timevals[2];

  timevals[0].tv_sec = time (NULL);
  timevals[0].tv_usec = 0L;
  timevals[1].tv_sec = tm;
  timevals[1].tv_usec = 0L;

  if (utimes (file, timevals) == -1)
    logprintf (LOG_NOTQUIET, "utimes(%s): %s\n", file, strerror (errno));
}

/* Checks if FILE is a symbolic link, and removes it if it is.  Does
