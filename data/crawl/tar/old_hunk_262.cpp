	  remaining_size -= status;
	  set_next_block_after (data_block);
	  data_block = find_next_block ();
	}
      if (status = read (diff_handle, buffer, (size_t) chunk_size),
	  status != chunk_size)
	{
	  if (status < 0)
	    {
	      WARN ((0, errno, _("Cannot read %s"), current_file_name));
	      report_difference (NULL);
	    }
	  else
	    {
	      char message[MESSAGE_BUFFER_SIZE];

	      sprintf (message, _("Could only read %d of %ld bytes"),
		       status, chunk_size);
	      report_difference (message);
	    }
	  break;
	}

      if (memcmp (buffer, data_block->buffer, (size_t) chunk_size))
	{
	  different = 1;
	  break;
