            struct dep *d;

	    for (i = 0, d = read_makefiles; d != 0; ++i, d = d->next)
              {
                /* Reset the considered flag; we may need to look at the file
                   again to print an error.  */
                d->file->considered = 0;

                if (d->file->updated)
                  {
                    /* This makefile was updated.  */
                    if (d->file->update_status == 0)
                      {
                        /* It was successfully updated.  */
                        any_remade |= (file_mtime_no_search (d->file)
                                       != makefile_mtimes[i]);
                      }
                    else if (! (d->changed & RM_DONTCARE))
                      {
                        FILE_TIMESTAMP mtime;
                        /* The update failed and this makefile was not
                           from the MAKEFILES variable, so we care.  */
                        error (NILF, "Failed to remake makefile `%s'.",
                               d->file->name);
                        mtime = file_mtime_no_search (d->file);
                        any_remade |= (mtime != (FILE_TIMESTAMP) -1
                                       && mtime != makefile_mtimes[i]);
                      }
                  }
                else
                  /* This makefile was not found at all.  */
                  if (! (d->changed & RM_DONTCARE))
                    {
                      /* This is a makefile we care about.  See how much.  */
                      if (d->changed & RM_INCLUDED)
                        /* An included makefile.  We don't need
                           to die, but we do want to complain.  */
                        error (NILF, "Included makefile `%s' was not found.",
                               dep_name (d));
                      else
                        {
                          /* A normal makefile.  We must die later.  */
                          error (NILF, "Makefile `%s' was not found",
                                 dep_name (d));
                          any_failed = 1;
                        }
                    }
              }
            /* Reset this to empty so we get the right error message below.  */
            read_makefiles = 0;

