
  /* Determine the local filename if needed. Notice that if -O is used 
   * hstat.local_file is set by http_loop to the argument of -O. */
  if (!hs->local_file)     
    {
      /* Honor Content-Disposition whether possible. */
      if (!resp_header_copy (resp, "Content-Disposition", hdrval, sizeof (hdrval))
          || !parse_content_disposition (hdrval, &hs->local_file))
        {
          /* Choose filename according to URL name. */
          hs->local_file = url_file_name (u);
        }
    }
  
  /* TODO: perform this check only once. */
  if (opt.noclobber && file_exists_p (hs->local_file))
    {
      /* If opt.noclobber is turned on and file already exists, do not
         retrieve the file */
      logprintf (LOG_VERBOSE, _("\
File `%s' already there; not retrieving.\n\n"), hs->local_file);
      /* If the file is there, we suppose it's retrieved OK.  */
      *dt |= RETROKF;

      /* #### Bogusness alert.  */
      /* If its suffix is "html" or "htm" or similar, assume text/html.  */
      if (has_html_suffix_p (hs->local_file))
        *dt |= TEXTHTML;

      return RETROK;
    }

  /* Support timestamping */
