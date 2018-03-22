	  remaining_size -= status;
	  set_next_block_after (data_block);
	  data_block = find_next_block ();
	  if (!data_block)
	    FATAL_ERROR ((0, 0, _("Unexpected EOF in archive")));
	}
      if (status = safe_read (diff_handle, buffer, chunk_size),
	  status != chunk_size)
	{
	  if (status < 0)
	    {
	      read_error (current_stat_info.file_name);
	      report_difference (0);
	    }
	  else
	    {
	      char message[MESSAGE_BUFFER_SIZE];

	      sprintf (message, _("Could only read %lu of %lu bytes"),
		       (unsigned long) status, (unsigned long) chunk_size);
	      report_difference (message);
	    }
	  break;
	}

      if (memcmp (buffer, data_block->buffer, chunk_size))
	{
	  different = 1;
	  break;
