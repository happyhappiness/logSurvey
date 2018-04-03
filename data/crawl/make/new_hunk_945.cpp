
  if (!(status & 1))
    {
      printf (_("Error spawning, %d\n") ,status);
      fflush (stdout);
    }

  if (comname[0] && !ISDB (DB_JOBS))
    unlink (comname);

  return (status & 1);
