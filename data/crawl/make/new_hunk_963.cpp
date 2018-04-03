  while (0)

struct direct *
readdir (dir)
     DIR * dir;
{
  struct FAB *dfab = &dir->fab;
  struct NAM *dnam = (struct NAM *)(dfab->fab$l_nam);
  struct direct *dentry = &dir->dir;
  int i;

  memset (dentry, 0, sizeof *dentry);

  dnam->nam$l_rsa = dir->d_result;
  dnam->nam$b_rss = MAXNAMLEN;

  if (debug_flag)
    printf (".");

  if (!((i = sys$search (dfab)) & 1))
    {
      if (debug_flag)
	printf ("sys$search failed with %d\n", i);
      return (NULL);
    }

  dentry->d_off = 0;
  if (dnam->nam$w_fid == 0)
    dentry->d_fileno = 1;
  else
    dentry->d_fileno = dnam->nam$w_fid[0] + (dnam->nam$w_fid[1] << 16);

  dentry->d_reclen = sizeof (struct direct);
  dentry->d_namlen = dnam->nam$b_name + dnam->nam$b_type;
  strncpy (dentry->d_name, dnam->nam$l_name, dentry->d_namlen);
  dentry->d_name[dentry->d_namlen] = '\0';
  uppercasify (dentry->d_name);

  return (dentry);
}

int
closedir (dir)
     DIR *dir;
{
  if (dir != NULL)
    {
      struct FAB *dfab = &dir->fab;
      struct NAM *dnam = (struct NAM *)(dfab->fab$l_nam);
      if (dnam != NULL)
	free (dnam->nam$l_esa);
      free (dnam);
      free (dir);
    }

  return 0;
}
#endif /* compiled for OpenVMS prior to V7.x */

