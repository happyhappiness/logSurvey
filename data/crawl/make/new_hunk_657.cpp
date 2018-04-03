            {
              nargv = xmalloc ((nargc + 2) * sizeof (char *));
              memcpy (nargv, argv, argc * sizeof (char *));
              nargv[nargc++] = xstrdup (concat ("-o", stdin_nm, ""));
              nargv[nargc] = 0;
            }

	  if (directories != 0 && directories->idx > 0)
	    {
	      int bad = 1;
	      if (directory_before_chdir != 0)
		{
		  if (chdir (directory_before_chdir) < 0)
		      perror_with_name ("chdir", "");
		  else
		    bad = 0;
		}
	      if (bad)
		fatal (NILF, _("Couldn't change back to original directory."));
	    }
