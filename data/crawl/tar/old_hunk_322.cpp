	  data_block = find_next_block ();
	  if (!data_block)
	    {
	      ERROR ((0, 0, _("EOF in archive file")));
	      break;		/* FIXME: What happens, then?  */
	    }
	  written = available_space_after (data_block);
