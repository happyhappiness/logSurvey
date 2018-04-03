      p = cmd + 8;

      if ((*(p) == 'c')
	  && (*(p+1) == 'd')
	  && ((*(p+2) == ' ') || (*(p+2) == '\t')))
	{
	  p += 3;
	  while ((*p == ' ') || (*p == '\t'))
	    p++;
	  DB (DB_JOBS, (_("BUILTIN CD %s\n"), p));
	  if (chdir (p))
	    return 0;
	  else
	    return 1;
	}
      else if ((*(p) == 'r')
	  && (*(p+1) == 'm')
	  && ((*(p+2) == ' ') || (*(p+2) == '\t')))
	{
	  int in_arg;

	  /* rm  */
	  p += 3;
	  while ((*p == ' ') || (*p == '\t'))
	    p++;
	  in_arg = 1;

	  DB (DB_JOBS, (_("BUILTIN RM %s\n"), p));
	  while (*p)
	    {
	      switch (*p)
		{
		  case ' ':
		  case '\t':
		    if (in_arg)
		      {
			*p++ = ';';
			in_arg = 0;
		      }
		    break;
		  default:
		    break;
		}
	      p++;
	    }
	}
      else
	{
	  printf(_("Unknown builtin command '%s'\n"), cmd);
	  fflush(stdout);
	  return 0;
	}
    }

  /* Create a *.com file if either the command is too long for
