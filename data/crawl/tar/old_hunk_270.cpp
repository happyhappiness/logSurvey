
      previous_status = status;
    }

  if (logical_status != HEADER_SUCCESS)
    {
      write_eot ();
      close_archive ();
      names_notfound ();
      return;
    }

  write_archive_to_stdout = 0;
  new_record = (union block *) xmalloc ((size_t) record_size);

  /* Save away blocks before this one in this record.  */

  new_blocks = current_block - record_start;
  blocks_needed = blocking_factor - new_blocks;
  if (new_blocks)
    memcpy ((void *) new_record, (void *) record_start,
	   (size_t) (new_blocks * BLOCKSIZE));

#if 0
  /* FIXME: Old code, before the goto was inserted.  To be redesigned.  */
  set_next_block_after (current_header);
  if (current_header->oldgnu_header.isextended)
    skip_extended_headers ();
  skip_file ((long) (current_stat.st_size));
#endif
  logical_status = HEADER_STILL_UNREAD;
  goto flush_file;

  /* FIXME: Solaris 2.4 Sun cc (the ANSI one, not the old K&R) says:
       "delete.c", line 223: warning: loop not entered at top
     Reported by Bruno Haible.  */
  while (1)
    {
      enum read_header status;

      /* Fill in a record.  */

      if (current_block == record_end)
	{
	  flush_archive ();
	  records_read++;
	}
      status = read_header ();

      if (status == HEADER_ZERO_BLOCK && ignore_zeros_option)
	{
	  set_next_block_after (current_header);
	  continue;
	}
      if (status == HEADER_END_OF_FILE || status == HEADER_ZERO_BLOCK)
	{
	  logical_status = HEADER_END_OF_FILE;
	  memset (new_record[new_blocks].buffer, 0,
		 (size_t) (BLOCKSIZE * blocks_needed));
	  new_blocks += blocks_needed;
	  blocks_needed = 0;
	  write_record (0);
	  break;
	}

      if (status == HEADER_FAILURE)
	{
	  ERROR ((0, 0, _("Deleting non-header from archive")));
	  set_next_block_after (current_header);
	  continue;
	}

      /* Found another header.  */

      if (name = name_scan (current_file_name), name)
	{
	  name->found = 1;
	flush_file:
	  set_next_block_after (current_header);
	  blocks_to_skip = (current_stat.st_size + BLOCKSIZE - 1) / BLOCKSIZE;

	  while (record_end - current_block <= blocks_to_skip)
	    {
	      blocks_to_skip -= (record_end - current_block);
	      flush_archive ();
	      records_read++;
	    }
	  current_block += blocks_to_skip;
	  blocks_to_skip = 0;
	  continue;
	}

      /* Copy header.  */

      new_record[new_blocks] = *current_header;
      new_blocks++;
      blocks_needed--;
      blocks_to_keep
	= (current_stat.st_size + BLOCKSIZE - 1) / BLOCKSIZE;
      set_next_block_after (current_header);
      if (blocks_needed == 0)
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
	      records_read++;
	      current_block = record_start;
	      kept_blocks_in_record = blocking_factor;
	      if (kept_blocks_in_record > blocks_to_keep)
		kept_blocks_in_record = blocks_to_keep;
	    }
	  count = kept_blocks_in_record;
	  if (count > blocks_needed)
	    count = blocks_needed;

	  memcpy ((void *) (new_record + new_blocks),
		  (void *) current_block,
		  (size_t) (count * BLOCKSIZE));
	  new_blocks += count;
	  blocks_needed -= count;
	  current_block += count;
	  blocks_to_keep -= count;
	  kept_blocks_in_record -= count;

	  if (blocks_needed == 0)
	    write_record (1);
	}
    }

  write_eot ();
  close_archive ();
  names_notfound ();
}
