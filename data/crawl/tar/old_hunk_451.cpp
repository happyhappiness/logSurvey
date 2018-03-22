
	    if (count == bufsize)
	      continue;
	    ERROR ((0, 0, _("File %s shrunk by %d bytes, padding with zeros"),
		    p, sizeleft));
	    goto padit;		/* short read */
	  }

      if (multi_volume_option)
