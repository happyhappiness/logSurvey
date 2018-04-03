opendir (dspec)
     char *dspec;
{
  static struct FAB *dfab;
  struct NAM *dnam;
  char *searchspec;

  dfab = (struct FAB *) xmalloc (sizeof (struct FAB));
  if (! dfab)
    {
      printf ("Error mallocing for FAB\n");
      return (NULL);
    }

  dnam = (struct NAM *) xmalloc (sizeof (struct NAM));
  if (! dnam)
    {
      printf ("Error mallocing for NAM\n");
      free (dfab);
      return (NULL);
    }

  searchspec = (char *) xmalloc (MAXNAMLEN + 1);
  if (! searchspec)
    {
      printf ("Error mallocing for searchspec\n");
      free (dfab);
      free (dnam);
      return (NULL);
    }

  sprintf (searchspec, "%s*.*;", dspec);

  *dfab = cc$rms_fab;
  dfab->fab$l_fna = searchspec;
  dfab->fab$b_fns = strlen (searchspec);
  dfab->fab$l_nam = dnam;
