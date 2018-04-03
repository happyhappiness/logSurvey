  return file;
}

static int parse_line PARAMS ((const char *, char **, char **, int *));
static int setval_internal PARAMS ((int, const char *, const char *));

/* Initialize variables from a wgetrc file.  */

static void
run_wgetrc (const char *file)
{
  FILE *fp;
  char *line;
  int ln;

  fp = fopen (file, "rb");
  if (!fp)
    {
      fprintf (stderr, _("%s: Cannot read %s (%s).\n"), exec_name,
	       file, strerror (errno));
      return;
    }
  enable_tilde_expansion = 1;
  ln = 1;
  while ((line = read_whole_line (fp)) != NULL)
    {
      char *com, *val;
      int comind, status;

      /* Parse the line.  */
      status = parse_line (line, &com, &val, &comind);
      xfree (line);
      /* If everything is OK, set the value.  */
      if (status == 1)
	{
	  if (!setval_internal (comind, com, val))
	    fprintf (stderr, _("%s: Error in %s at line %d.\n"), exec_name,
		     file, ln);
	  xfree (com);
	  xfree (val);
	}
      else if (status == 0)
	fprintf (stderr, _("%s: Error in %s at line %d.\n"), exec_name,
		 file, ln);
      ++ln;
    }
  enable_tilde_expansion = 0;
  fclose (fp);
}

/* Initialize the defaults and run the system wgetrc and user's own
