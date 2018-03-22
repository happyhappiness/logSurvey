    }
}

static void
extract_sparse_file (int fd, off_t *sizeleft, off_t totalsize, char *name)
{
  int sparse_ind = 0;

  /* assuming sizeleft is initially totalsize */

  while (*sizeleft > 0)
    {
      size_t written;
      size_t count;
