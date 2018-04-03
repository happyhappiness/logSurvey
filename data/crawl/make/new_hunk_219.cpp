  if (!goals)
    {
      if (read_files == 0)
        O (fatal, NILF, _("No targets specified and no makefile found"));

      O (fatal, NILF, _("No targets"));
    }

  /* Update the goals.  */
