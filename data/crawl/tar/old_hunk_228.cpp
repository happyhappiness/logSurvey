    }
}

/* Translate the sparse information on the header, and in any
   subsequent extended headers, into an array of structures with true
   numbers, as opposed to character strings.  Return nonzero if
   successful.

   This function invalidates current_header.  */

bool
fill_in_sparse_array (void)
{
  off_t sparse_data_size = current_stat_info.stat.st_size;
  off_t file_size = OFF_FROM_HEADER (current_header->oldgnu_header.realsize);
  int sparses;
  int counter;
  union block *h = current_header;

  init_sparsearray ();

  for (sparses = 0; sparses < SPARSES_IN_OLDGNU_HEADER; sparses++)
    {
      struct sparse const *s = &h->oldgnu_header.sp[sparses];
      off_t offset;
      size_t numbytes;
      if (s->numbytes[0] == '\0')
	break;
      sparsearray[sparses].offset = offset = OFF_FROM_HEADER (s->offset);
      sparsearray[sparses].numbytes = numbytes =
	SIZE_FROM_HEADER (s->numbytes);
      sparse_data_size -= numbytes;
      if (offset < 0 || file_size < offset + numbytes || sparse_data_size < 0)
	goto invalid_member;
    }

  if (h->oldgnu_header.isextended)
    do
      {
	h = find_next_block ();
	if (! h)
	  {
	    ERROR ((0, 0, _("Unexpected EOF in archive")));
	    return 0;
	  }

	for (counter = 0; counter < SPARSES_IN_SPARSE_HEADER; counter++)
	  {
	    struct sparse const *s = &h->sparse_header.sp[counter];
	    off_t offset;
	    size_t numbytes;
	    if (s->numbytes[0] == '\0')
	      break;

	    if (sparses == sp_array_size)
	      {
		sp_array_size *= 2;
		sparsearray =
		  xrealloc (sparsearray,
			    sp_array_size * sizeof *sparsearray);
	      }

	    sparsearray[sparses].offset = offset =
	      OFF_FROM_HEADER (s->offset);
	    sparsearray[sparses].numbytes = numbytes =
	      SIZE_FROM_HEADER (s->numbytes);
	    sparse_data_size -= numbytes;
	    if (offset < 0 || file_size < offset + numbytes
		|| sparse_data_size < 0)
	      goto invalid_member;
	    sparses++;
	  }
	
	set_next_block_after (h);
	
      } while (h->sparse_header.isextended);

  return 1;

 invalid_member:
  ERROR ((0, 0, _("%s: invalid sparse archive member"),
	  current_stat_info.file_name));
  return 0;
}


static off_t
extract_sparse_file (int fd, char const *name,
		     off_t sizeleft, off_t file_size)
{
  int sparse_ind = 0;

  while (sizeleft != 0)
    {
      size_t written;
      size_t count;
      union block *data_block = find_next_block ();
      if (! data_block)
	{
	  ERROR ((0, 0, _("Unexpected EOF in archive")));
	  return sizeleft;
	}
      if (lseek (fd, sparsearray[sparse_ind].offset, SEEK_SET) < 0)
	{
	  seek_error_details (name, sparsearray[sparse_ind].offset);
	  return sizeleft;
	}
      written = sparsearray[sparse_ind++].numbytes;
      while (written > BLOCKSIZE)
	{
	  count = full_write (fd, data_block->buffer, BLOCKSIZE);
	  written -= count;
	  sizeleft -= count;
	  if (count != BLOCKSIZE)
	    {
	      write_error_details (name, count, BLOCKSIZE);
	      return sizeleft;
	    }
	  set_next_block_after (data_block);
	  data_block = find_next_block ();
	  if (! data_block)
	    {
	      ERROR ((0, 0, _("Unexpected EOF in archive")));
	      return sizeleft;
	    }
	}

      count = full_write (fd, data_block->buffer, written);
      sizeleft -= count;

      if (count != written)
	{
	  write_error_details (name, count, written);
	  return sizeleft;
	}

      set_next_block_after (data_block);
    }

  if (ftruncate (fd, file_size) != 0)
    truncate_error (name);

  return 0;
}

/* Fix the statuses of all directories whose statuses need fixing, and
   which are not ancestors of FILE_NAME.  If AFTER_SYMLINKS is
   nonzero, do this for all such directories; otherwise, stop at the
