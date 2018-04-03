              DEBUGP (("  Unix: '%s'\n  VMS: '%s'\n", target, ntarget));
              target = ntarget;
            }

          if (!opt.server_response)
            logprintf (LOG_VERBOSE, "==> CWD %s ... ", escnonprint (target));
          err = ftp_cwd (csock, target);
          /* FTPRERR, WRITEFAILED, FTPNSFOD */
          switch (err)
            {
