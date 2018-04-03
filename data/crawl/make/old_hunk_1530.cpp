	  ++this_bucket;

	  for (f = file; f != 0; f = f->prev)
	    {
	      putchar ('\n');
	      if (!f->is_target)
		puts ("# Not a target:");
	      printf ("%s:%s", f->name, f->double_colon ? ":" : "");
	      
	      for (d = f->deps; d != 0; d = d->next)
		printf (" %s", dep_name (d));
	      putchar ('\n');
	      
	      if (f->precious)
		puts ("#  Precious file (dependency of .PRECIOUS).");
	      if (f->phony)
		puts ("#  Phony target (dependency of .PHONY).");
	      if (f->cmd_target)
		puts ("#  Command-line target.");
	      if (f->dontcare)
		puts ("#  A default or MAKEFILES makefile.");
	      printf ("#  Implicit rule search has%s been done.\n",
		      f->tried_implicit ? "" : " not");
	      if (f->stem != 0)
		printf ("#  Implicit/static pattern stem: `%s'\n", f->stem);
	      if (f->intermediate)
		puts ("#  File is an intermediate dependency.");
	      if (f->also_make != 0)
		{
		  fputs ("#  Also makes:", stdout);
		  for (d = f->also_make; d != 0; d = d->next)
		    printf (" %s", dep_name (d));
		  putchar ('\n');
		}
	      if (f->last_mtime == (time_t) 0)
		puts ("#  Modification time never checked.");
	      else if (f->last_mtime == (time_t) -1)
		puts ("#  File does not exist.");
	      else
		printf ("#  Last modified %.24s (%ld)\n",
			ctime (&f->last_mtime), (long int) f->last_mtime);
	      printf ("#  File has%s been updated.\n",
		      f->updated ? "" : " not");
	      switch (f->command_state)
		{
		case cs_running:
		  puts ("#  Commands currently running (THIS IS A BUG).");
		  break;
		case cs_deps_running:
		  puts ("#  Dependencies commands running (THIS IS A BUG).");
		  break;
		case cs_not_started:
		case cs_finished:
		  switch (f->update_status)
		    {
		    case -1:
		      break;
		    case 0:
		      puts ("#  Successfully updated.");
		      break;
		    case 1:
		      puts ("#  Failed to be updated.");
		      break;
		    default:
		      puts ("#  Invalid value in `update_status' member!");
		      fflush (stdout);
		      fflush (stderr);
		      abort ();
		    }
		  break;
		default:
		  puts ("#  Invalid value in `command_state' member!");
		  fflush (stdout);
		  fflush (stderr);
		  abort ();
		}

	      if (f->variables != 0)
		print_file_variables (file);

	      if (f->cmds != 0)
		print_commands (f->cmds);
	    }
	}

      nfiles += this_bucket;
