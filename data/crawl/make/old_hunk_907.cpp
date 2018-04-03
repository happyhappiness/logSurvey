                        error (NILF, _("Failed to remake makefile `%s'."),
                               d->file->name);
                        mtime = file_mtime_no_search (d->file);
                        any_remade |= (mtime != (FILE_TIMESTAMP) -1
                                       && mtime != makefile_mtimes[i]);
                      }
                  }
