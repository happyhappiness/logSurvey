  return 1;
}

/*------------------------------------------------------------------------.
| Some other routine wants SIZE bytes in the archive.  For each chunk of  |
| the archive, call PROCESSOR with the size of the chunk, and the address |
| of the chunk it can work with.  The PROCESSOR should return nonzero for |
| success.  It it return error once, continue skipping without calling    |
| PROCESSOR anymore.                                                      |
`------------------------------------------------------------------------*/

static void
read_and_process (long size, int (*processor) (long, char *))
{
  union block *data_block;
  long data_size;

  if (multi_volume_option)
    save_sizeleft = size;
  while (size)
    {
      data_block = find_next_block ();
      if (data_block == NULL)
	{
	  ERROR ((0, 0, _("Unexpected EOF on archive file")));
	  return;
	}

