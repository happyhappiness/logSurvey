      file->cmds = default_file->cmds;
    }

  /* Update all non-intermediate files we depend on, if necessary,
     and see whether any of them is more recent than this file.  */

  lastd = 0;
  d = file->deps;
  while (d != 0)
    {
      FILE_TIMESTAMP mtime;
      int maybe_make;
      int dontcare = 0;

      check_renamed (d->file);

      mtime = file_mtime (d->file);
      check_renamed (d->file);

      if (is_updating (d->file))
	{
	  error (NILF, _("Circular %s <- %s dependency dropped."),
		 file->name, d->file->name);
	  /* We cannot free D here because our the caller will still have
	     a reference to it when we were called recursively via
	     check_dep below.  */
	  if (lastd == 0)
	    file->deps = d->next;
	  else
	    lastd->next = d->next;
	  d = d->next;
	  continue;
	}

      d->file->parent = file;
      maybe_make = must_make;

      /* Inherit dontcare flag from our parent. */
      if (rebuilding_makefiles)
        {
          dontcare = d->file->dontcare;
          d->file->dontcare = file->dontcare;
        }


      dep_status |= check_dep (d->file, depth, this_mtime, &maybe_make);

      /* Restore original dontcare flag. */
      if (rebuilding_makefiles)
        d->file->dontcare = dontcare;

      if (! d->ignore_mtime)
        must_make = maybe_make;

      check_renamed (d->file);

      {
	register struct file *f = d->file;
	if (f->double_colon)
	  f = f->double_colon;
	do
	  {
	    running |= (f->command_state == cs_running
			|| f->command_state == cs_deps_running);
	    f = f->prev;
	  }
	while (f != 0);
      }

      if (dep_status != 0 && !keep_going_flag)
	break;

      if (!running)
        /* The prereq is considered changed if the timestamp has changed while
           it was built, OR it doesn't exist.  */
	d->changed = ((file_mtime (d->file) != mtime)
                      || (mtime == NONEXISTENT_MTIME));

      lastd = d;
      d = d->next;
    }

  /* Now we know whether this target needs updating.
