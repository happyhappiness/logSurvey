#endif

  if (utime (file, &times) == -1)
    logprintf (LOG_NOTQUIET, "utime: %s\n", strerror (errno));
}

/* Checks if FILE is a symbolic link, and removes it if it is.  Does
