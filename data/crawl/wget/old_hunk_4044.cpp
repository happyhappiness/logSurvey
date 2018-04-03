  /* ...to a buffer.  */
  load_file (fp, &buf, &size);
  fclose (fp);
  if (opt.backup_converted)
    /* Rather than just writing over the original .html file with the converted
       version, save the former to *.orig. */
    {
      /* Construct the backup filename as the original name plus ".orig". */
      size_t filename_len = strlen(file);
      char*  filename_plus_orig_suffix = malloc(filename_len + sizeof(".orig"));
      int    already_wrote_backup_file = 0;
      slist* converted_file_ptr;

      strcpy(filename_plus_orig_suffix, file);
      strcpy(filename_plus_orig_suffix + filename_len, ".orig");

      /* We can get called twice on the same URL thanks to the
	 convert_all_links() call in main().  If we write the .orig file each
	 time in such a case, it'll end up containing the first-pass conversion,
	 not the original file. */
      converted_file_ptr = converted_files;
      while (converted_file_ptr != NULL)
	if (strcmp(converted_file_ptr->string, file) == 0)
	  {
	    already_wrote_backup_file = 1;
	    break;
	  }
	else
