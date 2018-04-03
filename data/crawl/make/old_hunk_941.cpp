	  p += 3;
	  while ((*p == ' ') || (*p == '\t'))
	    p++;
	  if (debug_flag)
	    printf ("BUILTIN CD %s\n", p);
	  if (chdir (p))
	    return 0;
	  else
