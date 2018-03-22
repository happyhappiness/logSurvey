
      /* Good block.  Decode file size and return.  */

      if (header->header.typeflag == XHDTYPE
	  || header->header.typeflag == XGLTYPE)
	{
	  xheader_read (header, OFF_FROM_HEADER (header->header.size));
	  continue;
	}
      
      if (header->header.typeflag == LNKTYPE)
	current_stat_info.stat.st_size = 0;	/* links 0 size on tape */
      else
	current_stat_info.stat.st_size = OFF_FROM_HEADER (header->header.size);

      if (header->header.typeflag == GNUTYPE_LONGNAME
	  || header->header.typeflag == GNUTYPE_LONGLINK)
	{
	  if (raw_extended_headers)
	    return HEADER_SUCCESS_EXTENDED;
	  else
	    {
	      size_t name_size = current_stat_info.stat.st_size;
	      size = name_size - name_size % BLOCKSIZE + 2 * BLOCKSIZE;
	      if (name_size != current_stat_info.stat.st_size || size < name_size)
		xalloc_die ();
	    }

	  header_copy = xmalloc (size + 1);

	  if (header->header.typeflag == GNUTYPE_LONGNAME)
	    {
	      if (next_long_name)
		free (next_long_name);
	      next_long_name = header_copy;
	      next_long_name_blocks = size / BLOCKSIZE;
	    }
	  else
	    {
	      if (next_long_link)
		free (next_long_link);
	      next_long_link = header_copy;
	      next_long_link_blocks = size / BLOCKSIZE;
	    }

	  set_next_block_after (header);
	  *header_copy = *header;
	  bp = header_copy->buffer + BLOCKSIZE;

	  for (size -= BLOCKSIZE; size > 0; size -= written)
	    {
	      data_block = find_next_block ();
	      if (! data_block)
		{
		  ERROR ((0, 0, _("Unexpected EOF in archive")));
		  break;
		}
	      written = available_space_after (data_block);
	      if (written > size)
		written = size;

	      memcpy (bp, data_block->buffer, written);
	      bp += written;
	      set_next_block_after ((union block *)
				    (data_block->buffer + written - 1));
	    }

	  *bp = '\0';

	  /* Loop!  */

	}
