	    }
	  else if (cmdleft != 0)
	    /* Found one.  Cut the line short there before expanding it.  */
	    *cmdleft = '\0';

	  collapse_continuations (lb.buffer);

	  /* Expand variable and function references before doing anything
	     else so that special characters can be inside variables.  */
	  p = variable_expand (lb.buffer);

	  if (cmdleft == 0)
	    /* Look for a semicolon in the expanded line.  */
	    cmdleft = find_char_unquote (p, ";", 0);

	  if (cmdleft != 0)
	    /* Cut the line short at the semicolon.  */
	    *cmdleft = '\0';

	  p2 = next_token (p);
	  if (*p2 == '\0')
	    {
	      if (cmdleft != 0)
		makefile_fatal (filename, lineno,
				"missing rule before commands");
	      else
		/* This line contained a variable reference that
		   expanded to nothing but whitespace.  */
		continue;
	    }
	  else if (*p2 == ':')
	    {
	      /* We accept and ignore rules without targets for
		 compatibility with SunOS 4 make.  */
	      no_targets = 1;
	      continue;
	    }

	  filenames = multi_glob (parse_file_seq (&p2, ':',
						  sizeof (struct nameseq),
						  1),
				  sizeof (struct nameseq));
	  if (*p2++ == '\0')
	    makefile_fatal (filename, lineno, "missing separator");
	  /* Is this a one-colon or two-colon entry?  */
	  two_colon = *p2 == ':';
	  if (two_colon)
	    p2++;

	  /* We have some targets, so don't ignore the following commands.  */
	  no_targets = 0;

	  /* Is this a static pattern rule: `target: %targ: %dep; ...'?  */
	  p = index (p2, ':');
	  while (p != 0 && p[-1] == '\\')
