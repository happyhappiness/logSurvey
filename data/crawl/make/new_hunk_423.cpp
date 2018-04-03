                  }
              }
            *t = '\0';

	    /* Create an argv list for the shell command line.  */
	    {
	      int n = 0;

	      new_argv = xmalloc ((4 + sflags_len/2) * sizeof (char *));
	      new_argv[n++] = xstrdup (shell);

	      /* Chop up the shellflags (if any) and assign them.  */
	      if (! shellflags)
		new_argv[n++] = xstrdup ("");
	      else
		{
		  const char *s = shellflags;
		  char *t;
		  unsigned int len;
		  while ((t = find_next_token (&s, &len)) != 0)
		    new_argv[n++] = xstrndup (t, len);
		}

	      /* Set the command to invoke.  */
	      new_argv[n++] = line;
	      new_argv[n++] = NULL;
	    }
          }
#ifdef WINDOWS32
	else	/* non-Posix shell */
	  {
            const char *f = line;
            char *t = line;
	    char *tstart = t;
	    int temp_fd;
	    FILE* batch = NULL;
	    int id = GetCurrentProcessId();
	    PATH_VAR(fbuf);

	    /* Generate a file name for the temporary batch file.  */
	    sprintf(fbuf, "make%d", id);
	    *batch_filename = create_batch_file (fbuf, 0, &temp_fd);
	    DB (DB_JOBS, (_("Creating temporary batch file %s\n"),
			  *batch_filename));

	    /* Create a FILE object for the batch file, and write to it the
	       commands to be executed.  Put the batch file in TEXT mode.  */
	    _setmode (temp_fd, _O_TEXT);
	    batch = _fdopen (temp_fd, "wt");
	    fputs ("@echo off\n", batch);
	    DB (DB_JOBS, (_("Batch file contents:\n\t@echo off\n")));

            /* Copy the recipe, removing and ignoring interior prefix chars
               [@+-]: they're meaningless in .ONESHELL mode.  */
            while (*f != '\0')
              {
                /* This is the start of a new recipe line.
                   Skip whitespace and prefix characters.  */
                while (isblank (*f) || *f == '-' || *f == '@' || *f == '+')
                  ++f;

                /* Copy until we get to the next logical recipe line.  */
                while (*f != '\0')
                  {
		    /* Remove the escaped newlines in the command, and
		       the whitespace that follows them.  Windows
		       shells cannot handle escaped newlines.  */
		    if (*f == '\\' && f[1] == '\n')
		      {
			f += 2;
			while (isblank (*f))
			  ++f;
		      }
                    *(t++) = *(f++);
		    /* On an unescaped newline, we're done with this
		       line.  */
		    if (f[-1] == '\n')
		      break;
                  }
		/* Write another line into the batch file.  */
		if (t > tstart)
		  {
		    int c = *t;
		    *t = '\0';
		    fputs (tstart, batch);
		    DB (DB_JOBS, ("\t%s", tstart));
		    tstart = t;
		    *t = c;
		  }
	      }
	    DB (DB_JOBS, ("\n"));
	    fclose (batch);

	    /* Create an argv list for the shell command line that
	       will run the batch file.  */
	    new_argv = xmalloc (2 * sizeof (char *));
	    new_argv[0] = xstrdup (*batch_filename);
	    new_argv[1] = NULL;
	  }
#endif  /* WINDOWS32 */
	return new_argv;
      }

