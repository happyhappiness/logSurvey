static void
extract_sparse_file (int fd, off_t *sizeleft, off_t totalsize, char *name)
{
  int sparse_ind = 0;
  size_t written;
  ssize_t count;

  /* assuming sizeleft is initially totalsize */

  while (*sizeleft > 0)
    {
      union block *data_block = find_next_block ();
      if (data_block == NULL)
	{
	  ERROR ((0, 0, _("Unexpected EOF on archive file")));
	  return;
	}
      if (lseek (fd, sparsearray[sparse_ind].offset, SEEK_SET) < 0)
	{
	  char buf[UINTMAX_STRSIZE_BOUND];
	  ERROR ((0, errno, _("%s: lseek error at byte %s"),
		  STRINGIFY_BIGINT (sparsearray[sparse_ind].offset, buf),
		  name));
	  return;
	}
      written = sparsearray[sparse_ind++].numbytes;
      while (written > BLOCKSIZE)
	{
