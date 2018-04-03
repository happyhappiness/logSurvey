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
	    return new_argv;
	  }
#endif /* WINDOWS32 */
        /* Create an argv list for the shell command line.  */
        {
