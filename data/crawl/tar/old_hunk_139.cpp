void
list_archive (void)
{
  /* Print the header block.  */

  decode_header (current_header, &current_stat_info, &current_format, 0);
  if (verbose_option)
    print_header (&current_stat_info, -1);
  
  if (incremental_option && current_header->header.typeflag == GNUTYPE_DUMPDIR)
    {
      off_t size;
      size_t written, check;
      union block *data_block;

      set_next_block_after (current_header);
      if (multi_volume_option)
	{
	  assign_string (&save_name, current_stat_info.orig_file_name);
	  save_totsize = current_stat_info.stat.st_size;
	}
      for (size = current_stat_info.stat.st_size; size > 0; size -= written)
	{
	  if (multi_volume_option)
	    save_sizeleft = size;
	  data_block = find_next_block ();
	  if (!data_block)
	    {
	      ERROR ((0, 0, _("Unexpected EOF in archive")));
	      break;		/* FIXME: What happens, then?  */
	    }
	  written = available_space_after (data_block);
	  if (written > size)
	    written = size;
	  set_next_block_after ((union block *)
				(data_block->buffer + written - 1));
	  if (verbose_option > 2)
	    list_dumpdir (data_block->buffer, written);
	}
      if (multi_volume_option)
	assign_string (&save_name, 0);

      return;
    }

  if (multi_volume_option)
