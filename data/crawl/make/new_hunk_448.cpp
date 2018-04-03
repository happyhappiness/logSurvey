
  if (!goals)
    {
      if (read_files == 0)
        fatal (NILF, _("No targets specified and no makefile found"));

      fatal (NILF, _("No targets"));
