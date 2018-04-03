      res = ftp_get_listing (u, &con, &f);

      if (res == RETROK)
        {
          if (opt.htmlify && !opt.spider)
            {
              char *filename = (opt.output_document
                                ? xstrdup (opt.output_document)
                                : (con.target ? xstrdup (con.target)
                                   : url_file_name (u)));
              res = ftp_index (filename, u, f);
              if (res == FTPOK && opt.verbose)
                {
                  if (!opt.output_document)
                    {
                      struct_stat st;
                      wgint sz;
                      if (stat (filename, &st) == 0)
                        sz = st.st_size;
                      else
                        sz = -1;
                      logprintf (LOG_NOTQUIET,
                                 _("Wrote HTML-ized index to `%s' [%s].\n"),
                                 filename, number_to_static_string (sz));
                    }
                  else
                    logprintf (LOG_NOTQUIET,
                               _("Wrote HTML-ized index to `%s'.\n"),
                               filename);
                }
              xfree (filename);
            }
          freefileinfo (f);
        }
    }
  else
    {
      bool ispattern = false;
      if (glob)
        {
          /* Treat the URL as a pattern if the file name part of the
             URL path contains wildcards.  (Don't check for u->file
             because it is unescaped and therefore doesn't leave users
             the option to escape literal '*' as %2A.)  */
          char *file_part = strrchr (u->path, '/');
          if (!file_part)
            file_part = u->path;
          ispattern = has_wildcards_p (file_part);
        }
      if (ispattern || recursive || opt.timestamping)
        {
          /* ftp_retrieve_glob is a catch-all function that gets called
             if we need globbing, time-stamping or recursion.  Its
             third argument is just what we really need.  */
          res = ftp_retrieve_glob (u, &con,
                                   ispattern ? GLOB_GLOBALL : GLOB_GETONE);
        }
      else
        res = ftp_loop_internal (u, NULL, &con);
    }
  if (res == FTPOK)
    res = RETROK;
