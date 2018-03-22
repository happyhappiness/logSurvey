static void
extract_sparse_file (int fd, off_t *sizeleft, off_t totalsize, char *name)
{
  union block *data_block;
  int sparse_ind = 0;
  size_t written;
  ssize_t count;

  /* FIXME: `data_block' might be used uninitialized in this function.
     Reported by Bruno Haible.  */

  /* assuming sizeleft is initially totalsize */

  while (*sizeleft > 0)
    {
      data_block = find_next_block ();
      if (data_block == NULL)
	{
	  ERROR ((0, 0, _("Unexpected EOF on archive file")));
	  return;
	}
      lseek (fd, sparsearray[sparse_ind].offset, 0);
      written = sparsearray[sparse_ind++].numbytes;
      while (written > BLOCKSIZE)
	{
