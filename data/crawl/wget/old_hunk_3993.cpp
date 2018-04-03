  /* Retrieve the URLs from argument list.  */
  for (t = url; *t; t++)
    {
      char *filename, *new_file;
      int dt;

      status = retrieve_url (*t, &filename, &new_file, NULL, &dt);
      if (opt.recursive && status == RETROK && (dt & TEXTHTML))
	status = recursive_retrieve (filename, new_file ? new_file : *t);
      FREE_MAYBE (new_file);
      FREE_MAYBE (filename);
    }

