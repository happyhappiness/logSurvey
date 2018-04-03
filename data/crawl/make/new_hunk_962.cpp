opendir (dspec)
     char *dspec;
{
  struct DIR *dir  = (struct DIR *)xmalloc (sizeof (struct DIR));
  struct NAM *dnam = (struct NAM *)xmalloc (sizeof (struct NAM));
  struct FAB *dfab = &dir->fab;
  char *searchspec = (char *)xmalloc (MAXNAMLEN + 1);

  memset (dir, 0, sizeof *dir);

  *dfab = cc$rms_fab;
  *dnam = cc$rms_nam;
  sprintf (searchspec, "%s*.*;", dspec);

  dfab->fab$l_fna = searchspec;
  dfab->fab$b_fns = strlen (searchspec);
  dfab->fab$l_nam = dnam;
