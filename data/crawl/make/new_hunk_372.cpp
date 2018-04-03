  if (file->updated)
    {
      if (file->update_status > 0)
        {
          DBF (DB_VERBOSE,
               _("Recently tried and failed to update file '%s'.\n"));

          /* If the file we tried to make is marked no_diag then no message
