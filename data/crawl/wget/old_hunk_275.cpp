
  if (!replaced_filename)
    {
      /* Add the file name. */
      if (fnres.tail)
	append_char ('/', &fnres);
      u_file = *u->file ? u->file : index_filename;
      append_uri_pathel (u_file, u_file + strlen (u_file), false, &fnres);

      /* Append "?query" to the file name, even if empty */
      if (u->query)
	{
	  append_char (FN_QUERY_SEP, &fnres);
	  append_uri_pathel (u->query, u->query + strlen (u->query),
			     true, &fnres);
	}
    }
  else
    {
      if (fnres.tail)
	append_char ('/', &fnres);
      u_file = replaced_filename;
      append_uri_pathel (u_file, u_file + strlen (u_file), false, &fnres);
    }

  /* Zero-terminate the file name. */
  append_char ('\0', &fnres);

  fname = fnres.base;

  /* Check the cases in which the unique extensions are not used:
     1) Clobbering is turned off (-nc).
     2) Retrieval with regetting.
