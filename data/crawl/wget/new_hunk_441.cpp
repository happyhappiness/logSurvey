          if (!opt.server_response)
            logprintf (LOG_VERBOSE, "==> CWD (%d) %s ... ", cwd_count,
                       quotearg_style (escape_quoting_style, target));
          err = ftp_cwd (csock, targ);
          /* FTPRERR, WRITEFAILED, FTPNSFOD */
          switch (err)
            {
