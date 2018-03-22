
  if (!multi_volume_option)
    {
      enum compress_type type = check_compressed_archive ();

      if (type == ct_none)
	return archive;

      /* FD is not needed any more */
      rmtclose (archive);

