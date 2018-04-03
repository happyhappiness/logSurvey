      dlthis = true;
      if (opt.timestamping && f->type == FT_PLAINFILE)
        {
          struct_stat st;
          /* If conversion of HTML files retrieved via FTP is ever implemented,
             we'll need to stat() <file>.orig here when -K has been specified.
             I'm not implementing it now since files on an FTP server are much
             more likely than files on an HTTP server to legitimately have a
             .orig suffix. */
          if (!stat (con->target, &st))
            {
              bool eq_size;
              bool cor_val;
              /* Else, get it from the file.  */
              local_size = st.st_size;
              tml = st.st_mtime;
#ifdef WINDOWS
              /* Modification time granularity is 2 seconds for Windows, so
                 increase local time by 1 second for later comparison. */
              tml++;
#endif
              /* Compare file sizes only for servers that tell us correct
                 values. Assume sizes being equal for servers that lie
                 about file size.  */
              cor_val = (con->rs == ST_UNIX || con->rs == ST_WINNT);
              eq_size = cor_val ? (local_size == f->size) : true;
              if (f->tstamp <= tml && eq_size)
                {
                  /* Remote file is older, file sizes can be compared and
                     are both equal. */
                  logprintf (LOG_VERBOSE, _("\
Remote file no newer than local file `%s' -- not retrieving.\n"), con->target);
                  dlthis = false;
                }
              else if (eq_size)
                {
                  /* Remote file is newer or sizes cannot be matched */
                  logprintf (LOG_VERBOSE, _("\
