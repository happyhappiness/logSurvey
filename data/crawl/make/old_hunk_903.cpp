
  if (stat (file->name, &st) == 0
      && S_ISREG (st.st_mode)
      && FILE_TIMESTAMP_STAT_MODTIME (st) != file->last_mtime)
    {
      if (on_behalf_of)
	error (NILF, _("*** [%s] Deleting file `%s'"), on_behalf_of, file->name);
