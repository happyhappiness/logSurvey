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
	  converted_file_ptr = converted_file_ptr->next;

      if (!already_wrote_backup_file)
	{
	  /* Rename <file> to <file>.orig before former gets written over. */
	  if (rename(file, filename_plus_orig_suffix) != 0)
	    logprintf (LOG_NOTQUIET, _("Cannot back up %s as %s: %s\n"),
		       file, filename_plus_orig_suffix, strerror (errno));

	  /* Remember that we've already written a .orig backup for this file.
	     Note that we never free this memory since we need it till the
	     convert_all_links() call, which is one of the last things the
	     program does before terminating.  BTW, I'm not sure if it would be
	     safe to just set converted_file_ptr->string to file below, rather
	     than making a copy of the string... */
	  converted_file_ptr = malloc(sizeof(slist));
	  converted_file_ptr->string = strdup(file);
	  converted_file_ptr->next = converted_files;
	  converted_files = converted_file_ptr;
	}

      free(filename_plus_orig_suffix);
    }
  /* Now open the file for writing.  */
  fp = fopen (file, "wb");
  if (!fp)
