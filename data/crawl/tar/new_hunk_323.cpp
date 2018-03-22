				(data_block->buffer + written - 1));
	  if (check != written)
	    {
	      write_error_details (current_file_name, check, written);
	      skip_file (size - written);
	      break;
	    }
