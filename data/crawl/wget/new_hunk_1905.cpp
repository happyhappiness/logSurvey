
  printf (_("Continuing in background, pid %lu.\n"), pi.dwProcessId);
  if (info->logfile_changed)
    printf (_("Output will be written to %s.\n"), quote (info->lfilename));

  UnmapViewOfFile (info);

