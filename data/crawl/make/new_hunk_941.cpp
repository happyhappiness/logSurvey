	  p += 3;
	  while ((*p == ' ') || (*p == '\t'))
	    p++;
	  DB (DB_JOBS, (_("BUILTIN CD %s\n"), p));
	  if (chdir (p))
	    return 0;
	  else
