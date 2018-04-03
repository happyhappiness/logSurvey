      int dt;

      if ((opt.recursive || opt.page_requisites)
          && (url_scheme (*t) != SCHEME_FTP || opt.use_proxy))
        {
          int old_follow_ftp = opt.follow_ftp;

          /* Turn opt.follow_ftp on in case of recursive FTP retrieval */
          if (url_scheme (*t) == SCHEME_FTP) 
            opt.follow_ftp = 1;
          
          status = retrieve_tree (*t);

          opt.follow_ftp = old_follow_ftp;
        }
      else
        status = retrieve_url (*t, &filename, &redirected_URL, NULL, &dt, opt.recursive);

      if (opt.delete_after && file_exists_p(filename))
        {
          DEBUGP (("Removing file due to --delete-after in main():\n"));
          logprintf (LOG_VERBOSE, _("Removing %s.\n"), filename);
          if (unlink (filename))
            logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
        }

      xfree_null (redirected_URL);
      xfree_null (filename);
