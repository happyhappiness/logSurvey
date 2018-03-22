     possible, real problems are unlikely.  Doing any better would require a
     convention, GNU-wide, for all programs doing backups.  */

  assign_string (&after_backup_name, NULL);
  after_backup_name = find_backup_file_name (path);
  if (after_backup_name == NULL)
    FATAL_ERROR ((0, 0, "Virtual memory exhausted"));

  if (rename (before_backup_name, after_backup_name) == 0)
    {
      if (verbose_option)
	fprintf (stdlis, _("Renaming previous `%s' to `%s'\n"),
		 before_backup_name, after_backup_name);
      return 1;
    }

  /* The backup operation failed.  */

  ERROR ((0, errno, _("%s: Cannot rename for backup"), before_backup_name));
  assign_string (&after_backup_name, NULL);
  return 0;
}

/*-----------------------------------------------------------------------.
| Try to restore the recently backed up file to its original name.  This |
| is usually only needed after a failed extraction.			 |
`-----------------------------------------------------------------------*/

void
undo_last_backup (void)
{
  if (after_backup_name)
    {
      if (rename (after_backup_name, before_backup_name) != 0)
	ERROR ((0, errno, _("%s: Cannot rename from backup"),
		before_backup_name));
      if (verbose_option)
	fprintf (stdlis, _("Renaming `%s' back to `%s'\n"),
		 after_backup_name, before_backup_name);
      assign_string (&after_backup_name, NULL);
    }
}
