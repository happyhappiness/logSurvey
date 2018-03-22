  typeflag = current_header->header.typeflag;
  switch (typeflag)
    {
      /* JK - What we want to do if the file is sparse is loop through
	 the array of sparse structures in the header and read in and
	 translate the character strings representing 1) the offset at
	 which to write and 2) how many bytes to write into numbers,
	 which we store into the scratch array, "sparsearray".  This
	 array makes our life easier the same way it did in creating the
	 tar file that had to deal with a sparse file.

	 After we read in the first five (at most) sparse structures, we
	 check to see if the file has an extended header, i.e., if more
	 sparse structures are needed to describe the contents of the new
	 file.  If so, we read in the extended headers and continue to
	 store their contents into the sparsearray.  */

    case GNUTYPE_SPARSE:
      sp_array_size = 10;
      sparsearray =
	xmalloc (sp_array_size * sizeof (struct sp_array));

      for (counter = 0; counter < SPARSES_IN_OLDGNU_HEADER; counter++)
	{
	  struct sparse const *s = &current_header->oldgnu_header.sp[counter];
	  sparsearray[counter].offset = OFF_FROM_HEADER (s->offset);
	  sparsearray[counter].numbytes = SIZE_FROM_HEADER (s->numbytes);
	  if (!sparsearray[counter].numbytes)
	    break;
	}

      if (current_header->oldgnu_header.isextended)
	{
	  /* Read in the list of extended headers and translate them
	     into the sparsearray as before.  Note that this
	     invalidates current_header.  */

	  /* static */ int ind = SPARSES_IN_OLDGNU_HEADER;

	  while (1)
	    {
	      exhdr = find_next_block ();
	      if (! exhdr)
		{
		  ERROR ((0, 0, _("Unexpected EOF in archive")));
		  return;
		}
	      for (counter = 0; counter < SPARSES_IN_SPARSE_HEADER; counter++)
		{
		  struct sparse const *s = &exhdr->sparse_header.sp[counter];
		  if (counter + ind > sp_array_size - 1)
		    {
		      /* Realloc the scratch area since we've run out of
			 room.  */

		      sp_array_size *= 2;
		      sparsearray =
			xrealloc (sparsearray,
				  sp_array_size * sizeof (struct sp_array));
		    }
		  if (s->numbytes[0] == 0)
		    break;
		  sparsearray[counter + ind].offset =
		    OFF_FROM_HEADER (s->offset);
		  sparsearray[counter + ind].numbytes =
		    SIZE_FROM_HEADER (s->numbytes);
		}
	      if (!exhdr->sparse_header.isextended)
		break;
	      else
		{
		  ind += SPARSES_IN_SPARSE_HEADER;
		  set_next_block_after (exhdr);
		}
	    }
	  set_next_block_after (exhdr);
	}
      /* Fall through.  */

    case AREGTYPE:
