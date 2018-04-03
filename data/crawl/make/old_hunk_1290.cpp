                    }
                  else if (! (d->changed & RM_DONTCARE))
                    {
                      time_t mtime;
                      /* The update failed and this makefile was not
                         from the MAKEFILES variable, so we care.  */
                      error ("Failed to remake makefile `%s'.",
                             d->file->name);
                      mtime = file_mtime_no_search (d->file);
                      any_remade |= (mtime != (time_t) -1
                                     && mtime != makefile_mtimes[i]);
                    }
                }
