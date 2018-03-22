	      if (status < 0)
		{
		  read_error (current_stat_info.file_name);
		  report_difference (NULL);
		}
	      else
		{
		  report_difference (ngettext ("Could only read %lu of %lu byte",
				     "Could only read %lu of %lu bytes",
				     chunk_size),
				     (unsigned long) status,
				     (unsigned long) chunk_size);
		}
	      break;
	    }
