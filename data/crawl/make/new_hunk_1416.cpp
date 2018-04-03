	       in updating or could not be found at all.  */
	    int any_failed = 0;
	    register unsigned int i;
            struct dep *d;

	    for (i = 0, d = read_makefiles; d != 0; ++i, d = d->next)
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
              else
                /* This makefile was not found at all.  */
                if (! (d->changed & RM_DONTCARE))
                  {
                    /* This is a makefile we care about.  See how much.  */
                    if (d->changed & RM_INCLUDED)
                      /* An included makefile.  We don't need
                         to die, but we do want to complain.  */
                      error ("Included makefile `%s' was not found.",
                             dep_name (d));
                    else
                      {
                        /* A normal makefile.  We must die later.  */
                        error ("Makefile `%s' was not found", dep_name (d));
                        any_failed = 1;
                      }
                  }

	    if (any_remade)
	      goto re_exec;
