    logprintf (LOG_NOTQUIET, "futimens(%s): %s\n", file, strerror (errno));

  close (fd);
}

/* Checks if FILE is a symbolic link, and removes it if it is.  Does
