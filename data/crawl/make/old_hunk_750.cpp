#endif /* VMS */
}

#ifdef VMS
/* Wait for nchildren children to terminate */
static void
vmsWaitForChildren(int *status)
{
  while (1)
    {
      if (!vms_jobsefnmask)
	{
	  *status = 0;
	  return;
	}

      *status = sys$wflor (32, vms_jobsefnmask);
    }
  return;
}

/* Set up IO redirection.  */

char *
vms_redirect (struct dsc$descriptor_s *desc, char *fname, char *ibuf)
{
  char *fptr;
  extern char *vmsify ();

  ibuf++;
  while (isspace ((unsigned char)*ibuf))
    ibuf++;
  fptr = ibuf;
  while (*ibuf && !isspace ((unsigned char)*ibuf))
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
    printf (_("Warning: Empty redirection\n"));
  return ibuf;
}


/* found apostrophe at (p-1)
   inc p until after closing apostrophe.
 */

static char *
vms_handle_apos (char *p)
{
  int alast;

#define SEPCHARS ",/()= "

  alast = 0;

  while (*p != 0)
    {
      if (*p == '"')
	{
          if (alast)
            {
              alast = 0;
              p++;
	    }
	  else
	    {
	      p++;
	      if (strchr (SEPCHARS, *p))
		break;
	      alast = 1;
	    }
	}
      else
	p++;
    }

  return p;
}

#endif


/* Handle a dead child.  This handler may or may not ever be installed.

