    }
  return;
}

/* Set up IO redirection.  */

char *
vms_redirect (desc, fname, ibuf)
    struct dsc$descriptor_s *desc;
    char *fname;
    char *ibuf;
{
  char *fptr;
  extern char *vmsify ();

  ibuf++;
  while (isspace (*ibuf))
    ibuf++;
  fptr = ibuf;
  while (*ibuf && !isspace (*ibuf))
    ibuf++;
  *ibuf = 0;
  if (strcmp (fptr, "/dev/null") != 0)
    {
      strcpy (fname, vmsify (fptr, 0));
      if (strchr (fname, '.') == 0)
	strcat (fname, ".");
    }
  desc->dsc$w_length = strlen(fname);
  desc->dsc$a_pointer = fname;
  desc->dsc$b_dtype = DSC$K_DTYPE_T;
  desc->dsc$b_class = DSC$K_CLASS_S;

  if (*fname == 0)
    printf ("Warning: Empty redirection\n");
  return ibuf;
}


/*
   found apostrophe at (p-1)

   inc p until after closing apostrophe.  */

static char *
handle_apos (char *p)
{
  int alast;
  int inside;

#define SEPCHARS ",/()= "

  inside = 0;

  while (*p != 0)
    {
      if (*p == '"')
	{
	  if (inside)
	    {
	      while ((alast > 0)
		    && (*p == '"'))
		{
		  p++;
		  alast--;
		}
	      if (alast == 0)
		inside = 0;
	      else
		{
		  fprintf (stderr, "Syntax error, still inside '\"'\n");
		  exit (3);
		}
	    }
	  else
	    {
	      p++;
	      if (strchr (SEPCHARS, *p))
		break;
	      inside = 1;
	      alast = 1;
	      while (*p == '"')
		{
		  alast++;
		  p++;
		}
	    }
	}
      else
	p++;
    }

  return p;
}

#endif


