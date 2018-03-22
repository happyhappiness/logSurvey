
      previous_status = status;
    }
  while (logical_status == HEADER_STILL_UNREAD);

  records_skipped = records_read - 1;
  new_record = xmalloc (record_size);

  if (logical_status == HEADER_SUCCESS
      || logical_status == HEADER_SUCCESS_EXTENDED)
    {
      write_archive_to_stdout = 0;

      /* Save away blocks before this one in this record.  */

      new_blocks = current_block - record_start;
      if (new_blocks)
	memcpy (new_record, record_start, new_blocks * BLOCKSIZE);

      if (logical_status == HEADER_SUCCESS)
	{
	  /* FIXME: Pheew!  This is crufty code!  */
	  logical_status = HEADER_STILL_UNREAD;
	  goto flush_file;
	}

      /* FIXME: Solaris 2.4 Sun cc (the ANSI one, not the old K&R) says:
	 "delete.c", line 223: warning: loop not entered at top
	 Reported by Bruno Haible.  */
      while (1)
	{
	  enum read_header status;

	  /* Fill in a record.  */

	  if (current_block == record_end)
	    flush_archive ();
	  status = read_header (0);

	  if (status == HEADER_ZERO_BLOCK && ignore_zeros_option)
	    {
	      set_next_block_after (current_header);
	      continue;
	    }
	  if (status == HEADER_END_OF_FILE || status == HEADER_ZERO_BLOCK)
	    {
	      logical_status = HEADER_END_OF_FILE;
	      break;
	    }

	  if (status == HEADER_FAILURE)
	    {
	      ERROR ((0, 0, _("Deleting non-header from archive")));
	      set_next_block_after (current_header);
	      continue;
	    }

	  /* Found another header.  */

	  if (name = name_scan (current_stat_info.file_name), name)
	    {
	      name->found = 1;
	    flush_file:
	      set_next_block_after (current_header);
	      blocks_to_skip = (current_stat_info.stat.st_size + BLOCKSIZE - 1) / BLOCKSIZE;

	      while (record_end - current_block <= blocks_to_skip)
		{
		  blocks_to_skip -= (record_end - current_block);
		  flush_archive ();
		}
	      current_block += blocks_to_skip;
	      blocks_to_skip = 0;
	      continue;
	    }

	  /* Copy header.  */

	  write_recent_blocks (recent_long_name, recent_long_name_blocks);
	  write_recent_blocks (recent_long_link, recent_long_link_blocks);
	  new_record[new_blocks] = *current_header;
	  new_blocks++;
	  blocks_to_keep
	    = (current_stat_info.stat.st_size + BLOCKSIZE - 1) / BLOCKSIZE;
	  set_next_block_after (current_header);
	  if (new_blocks == blocking_factor)
	    write_record (1);

	  /* Copy data.  */

	  kept_blocks_in_record = record_end - current_block;
	  if (kept_blocks_in_record > blocks_to_keep)
	    kept_blocks_in_record = blocks_to_keep;

	  while (blocks_to_keep)
	    {
	      int count;

	      if (current_block == record_end)
		{
		  flush_read ();
		  current_block = record_start;
		  kept_blocks_in_record = blocking_factor;
		  if (kept_blocks_in_record > blocks_to_keep)
		    kept_blocks_in_record = blocks_to_keep;
		}
	      count = kept_blocks_in_record;
	      if (blocking_factor - new_blocks < count)
		count = blocking_factor - new_blocks;

	      if (! count)
		abort ();

	      memcpy (new_record + new_blocks, current_block, count * BLOCKSIZE);
	      new_blocks += count;
	      current_block += count;
	      blocks_to_keep -= count;
	      kept_blocks_in_record -= count;

	      if (new_blocks == blocking_factor)
		write_record (1);
	    }
	}
    }

  if (logical_status == HEADER_END_OF_FILE)
    {
      /* Write the end of tape.  FIXME: we can't use write_eot here,
	 as it gets confused when the input is at end of file.  */

      int total_zero_blocks = 0;

      do
	{
	  int zero_blocks = blocking_factor - new_blocks;
	  memset (new_record + new_blocks, 0, BLOCKSIZE * zero_blocks);
	  total_zero_blocks += zero_blocks;
	  write_record (total_zero_blocks < 2);
	}
      while (total_zero_blocks < 2);
    }

  free (new_record);

  if (! acting_as_filter && ! _isrmt (archive))
    {
#if MSDOS
      int status = write (archive, "", 0);
#else
      off_t pos = lseek (archive, (off_t) 0, SEEK_CUR);
      int status = pos < 0 ? -1 : ftruncate (archive, pos);
#endif
      if (status != 0)
	truncate_warn (archive_name_array[0]);
    }

  close_archive ();
  names_notfound ();
}
