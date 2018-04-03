	  break;
	}

      /* Try getting content-length.  */
      if (contlen == -1 && !opt.ignore_length)
	if (header_process (hdr, "Content-Length", header_extract_number,
