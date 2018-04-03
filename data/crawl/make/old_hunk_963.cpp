  while (0)

struct direct *
readdir (dfd)
     DIR * dfd;
{
  static struct direct *dentry;
  static char resultspec[MAXNAMLEN + 1];
  int i;

  dentry = (struct direct *) xmalloc (sizeof (struct direct));
  if (! dentry)
    {
      printf ("Error mallocing for direct\n");
      return (NULL);
    }

  dfd->fab$l_nam->nam$l_rsa = resultspec;
  dfd->fab$l_nam->nam$b_rss = MAXNAMLEN;

  DB (DB_EXTRA, ("."));

  if (!((i = sys$search (dfd)) & 1))
    {
      DB (DB_EXTRA, ("sys$search failed with %d\n", i));
      free (dentry);
      return (NULL);
    }

  dentry->d_off = 0;
  if (dfd->fab$l_nam->nam$w_fid == 0)
    dentry->d_fileno = 1;
  else
    dentry->d_fileno = dfd->fab$l_nam->nam$w_fid[0]
      + dfd->fab$l_nam->nam$w_fid[1] << 16;
  dentry->d_reclen = sizeof (struct direct);
#if 0
  if (!strcmp(dfd->fab$l_nam->nam$l_type, ".DIR"))
    dentry->d_namlen = dfd->fab$l_nam->nam$b_name;
  else
#endif
  dentry->d_namlen = dfd->fab$l_nam->nam$b_name + dfd->fab$l_nam->nam$b_type;
  strncpy (dentry->d_name, dfd->fab$l_nam->nam$l_name, dentry->d_namlen);
  dentry->d_name[dentry->d_namlen] = '\0';
  uppercasify (dentry->d_name);
#if 0
  uvUnFixRCSSeparator(dentry->d_name);
#endif

  return (dentry);
}

closedir (dfd)
     DIR *dfd;
{
  if (dfd)
    {
      if (dfd->fab$l_nam)
	free (dfd->fab$l_nam->nam$l_esa);
      free (dfd->fab$l_nam);
      free (dfd);
    }
}
#endif /* compiled for OpenVMS prior to V7.x */

