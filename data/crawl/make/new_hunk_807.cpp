
  /* < 0 only if dup() failed */
  if (save_stdin < 0)
    fatal (NILF, _("no more file handles: could not duplicate stdin\n"));
  if (save_stdout < 0)
    fatal (NILF, _("no more file handles: could not duplicate stdout\n"));

  /* Close unnecessary file handles for the child.  */
  if (save_stdin != 0)
