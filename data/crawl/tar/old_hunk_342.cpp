	    data_block = find_next_block ();
	    if (! data_block)
	      {
		ERROR ((0, 0, _("Unexpected EOF on archive file")));
		break;		/* FIXME: What happens, then?  */
	      }

