      && FILE_TIMESTAMP_STAT_MODTIME (file->name, st) != file->last_mtime)
    {
      if (on_behalf_of)
        OSS (error, NILF,
             _("*** [%s] Deleting file '%s'"), on_behalf_of, file->name);
      else
        OS (error, NILF, _("*** Deleting file '%s'"), file->name);
      if (unlink (file->name) < 0
          && errno != ENOENT)   /* It disappeared; so what.  */
        perror_with_name ("unlink: ", file->name);
