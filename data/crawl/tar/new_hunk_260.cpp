  return 1;
}

/* Some other routine wants SIZE bytes in the archive.  For each chunk
   of the archive, call PROCESSOR with the size of the chunk, and the
   address of the chunk it can work with.  The PROCESSOR should return
   nonzero for success.  It it return error once, continue skipping
   without calling PROCESSOR anymore.  */
static void
read_and_process (off_t size, int (*processor) (size_t, char *))
{
  union block *data_block;
  size_t data_size;

  if (multi_volume_option)
    save_sizeleft = size;
  while (size)
    {
      data_block = find_next_block ();
      if (! data_block)
	{
	  ERROR ((0, 0, _("Unexpected EOF in archive")));
	  return;
	}

