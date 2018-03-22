void
list_archive (void)
{
  off_t block_ordinal = current_block_ordinal ();
  /* Print the header block.  */

  decode_header (current_header, &current_stat_info, &current_format, 0);
  if (verbose_option)
    print_header (&current_stat_info, block_ordinal);
  
  if (incremental_option)
    {
      if (verbose_option > 2)
	{
	  if (current_stat_info.dumpdir)
	    list_dumpdir (current_stat_info.dumpdir,
			  dumpdir_size (current_stat_info.dumpdir));
	}
    }

  if (multi_volume_option)
