    }
  else
    {
      /* FILE is an intermediate file.  */
      time_t mtime;

      if (!file->phony && file->cmds == 0 && !file->tried_implicit
	  && file->secondary)
	{
	  if (try_implicit_rule (file, depth))
	    DEBUGPR ("Found an implicit rule for `%s'.\n");
	  else
	    DEBUGPR ("No implicit rule found for `%s'.\n");
	  file->tried_implicit = 1;
	}
      if (file->cmds == 0 && !file->is_target && file->secondary
	  && default_file != 0 && default_file->cmds != 0)
	{
	  DEBUGPR ("Using default commands for `%s'.\n");
	  file->cmds = default_file->cmds;
	}

      /* If the intermediate file actually exists
	 and is newer, then we should remake from it.  */
      check_renamed (file);
      mtime = file_mtime (file);
      check_renamed (file);
      if (mtime > this_mtime)
	*must_make_ptr = 1;
	  /* Otherwise, update all non-intermediate files we depend on,
	     if necessary, and see whether any of them is more
	     recent than the file on whose behalf we are checking.  */
      else
	{
	  register struct dep *lastd;

	  lastd = 0;
	  d = file->deps;
	  while (d != 0)
	    {
	      if (d->file->updating)
		{
		  error ("Circular %s <- %s dependency dropped.",
			 file->name, d->file->name);
		  if (lastd == 0)
		    {
		      file->deps = d->next;
		      free ((char *) d);
		      d = file->deps;
		    }
		  else
		    {
		      lastd->next = d->next;
		      free ((char *) d);
		      d = lastd->next;
		    }
		  continue;
		}

	      d->file->parent = file;
	      dep_status |= check_dep (d->file, depth, this_mtime, must_make_ptr);
	      check_renamed (d->file);
	      if (dep_status != 0 && !keep_going_flag)
		break;

	      if (d->file->command_state == cs_running
		  || d->file->command_state == cs_deps_running)
		/* Record that some of FILE's dependencies are still being made.
		   This tells the upper levels to wait on processing it until
		   the commands are finished.  */
		set_command_state (file, cs_deps_running);

	      lastd = d;
	      d = d->next;
	    }
	}
    }

