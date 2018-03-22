
  if (!multi_volume_option)
    {
      if (!use_compress_program_option)
	{
	  bool shortfile;
	  enum compress_type type = check_compressed_archive (&shortfile);

	  switch (type)
	    {
	    case ct_tar:
	      if (shortfile)
		ERROR ((0, 0, _("This does not look like a tar archive")));
	      return archive;
      
	    case ct_none:
	      if (shortfile)
		ERROR ((0, 0, _("This does not look like a tar archive")));
	      set_comression_program_by_suffix (archive_name_array[0], NULL);
	      if (!use_compress_program_option)
		return archive;
	      break;

	    default:
	      use_compress_program_option = compress_program (type);
	      break;
	    }
	}
      
      /* FD is not needed any more */
