  return;
}

/* Set up IO redirection.  */

static char *
vms_redirect (struct dsc$descriptor_s *desc, char *fname, char *ibuf)
{
  char *fptr;
  char saved;

  ibuf++;
  while (isspace ((unsigned char)*ibuf))
    ibuf++;
  fptr = ibuf;
  while (*ibuf && !isspace ((unsigned char)*ibuf))
    ibuf++;
  saved = *ibuf;
  *ibuf = 0;
  if (strcmp (fptr, "/dev/null") != 0)
    {
      strcpy (fname, vmsify (fptr, 0));
      if (strchr (fname, '.') == 0)
        strcat (fname, ".");
    }
  desc->dsc$w_length = strlen (fname);
  desc->dsc$a_pointer = fname;
  desc->dsc$b_dtype = DSC$K_DTYPE_T;
  desc->dsc$b_class = DSC$K_CLASS_S;

  if (*fname == 0)
    printf (_("Warning: Empty redirection\n"));
  if (saved=='\0')
    return ibuf;
  *ibuf = saved;
  return --ibuf;
}


/* found apostrophe at (p-1)
   inc p until after closing apostrophe.
*/

static char *
vms_handle_apos (char *p)
{
  int alast;
  alast = 0;

  while (*p != 0)
    if (*p == '"')
      if (alast)
        {
          alast = 0;
          p++;
        }
      else
        {
          p++;
          if (*p!='"')
            break;
          alast = 1;
        }
    else
      p++;

  return p;
}

static int ctrlYPressed= 0;
/* This is called at main or AST level. It is at AST level for DONTWAITFORCHILD
   and at main level otherwise. In any case it is called when a child process
