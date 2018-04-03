
  /* Determine the local filename if needed. Notice that if -O is used 
   * hstat.local_file is set by http_loop to the argument of -O. */
  if (!hs->local_file)
    {
      /* Honor Content-Disposition whether possible. */
      if (!opt.content_disposition
          || !resp_header_copy (resp, "Content-Disposition", 
                                hdrval, sizeof (hdrval))
          || !parse_content_disposition (hdrval, &hs->local_file))
        {
          /* The Content-Disposition header is missing or broken. 
           * Choose unique file name according to given URL. */
          hs->local_file = url_file_name (u);
        }
    }
  
  DEBUGP (("hs->local_file is: %s %s\n", hs->local_file,
          file_exists_p (hs->local_file) ? "(existing)" : "(not existing)"));
  
  /* TODO: perform this check only once. */
  if (file_exists_p (hs->local_file))
    {
      if (opt.noclobber)
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
      else
        {
          char *unique = unique_name (hs->local_file, true);
          if (unique != hs->local_file)
            xfree (hs->local_file);
          hs->local_file = unique;
        }
    }

  /* Support timestamping */
