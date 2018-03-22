      return;
    }

  /* In multi-volume mode. */
  /* ENXIO is for the UNIX PC.  */
  if (status < 0 && errno != ENOSPC && errno != EIO && errno != ENXIO)
    archive_write_error (status);

  if (!new_volume (ACCESS_WRITE))
    return;

