      if (outfile == 0)
	pfatal_with_name (comname);

      fprintf (outfile, "$ ");
      c = cmd;

      while (c)
	{
	  p = strchr (c, ',');
	  if ((p == NULL) || (p-c > MAXCMDLEN))
	    p = strchr (c, ' ');
	  if (p != NULL)
	    {
	      p++;
	      tmp = *p;
	      *p = '\0';
	    }
	  else
	    tmp = '\0';
	  fprintf (outfile, "%s%s\n", c, (tmp == '\0')?"":" -");
	  if (p != NULL)
	    *p = tmp;
	  c = p;
	}

      fclose (outfile);

