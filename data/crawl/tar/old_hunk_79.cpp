
  if (!multi_volume_option)
    {
      bool shortfile;
      enum compress_type type = check_compressed_archive (&shortfile);

      if (type == ct_none)
	{
	  if (shortfile)
	    ERROR ((0, 0, _("This does not look like a tar archive")));
	  return archive;
	}
      
      /* FD is not needed any more */
