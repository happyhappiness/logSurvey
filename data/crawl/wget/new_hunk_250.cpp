      if (!opt.server_response && err != FTPSRVERR)
        logputs (LOG_VERBOSE, _("done.    "));

      /* 2013-10-17 Andrea Urbani (matfanjol)
         According to the system type I choose which
         list command will be used.
         If I don't know that system, I will try, the
         first time of each session, "LIST -a" and
         "LIST". (see __LIST_A_EXPLANATION__ below) */
      switch (con->rs)
        {
        case ST_VMS:
          /* About ST_VMS there is an old note:
             2008-01-29  SMS.  For a VMS FTP server, where "LIST -a" may not
             fail, but will never do what is desired here,
             skip directly to the simple "LIST" command
             (assumed to be the last one in the list).  */
          DEBUGP (("\nVMS: I know it and I will use \"LIST\" as standard list command\n"));
          con->st |= LIST_AFTER_LIST_A_CHECK_DONE;
          con->st |= AVOID_LIST_A;
          break;
        case ST_UNIX:
          if (con->rsu == UST_MULTINET)
            {
              DEBUGP (("\nUNIX MultiNet: I know it and I will use \"LIST\" "
                       "as standard list command\n"));
              con->st |= LIST_AFTER_LIST_A_CHECK_DONE;
              con->st |= AVOID_LIST_A;
            }
          else if (con->rsu == UST_TYPE_L8)
            {
              DEBUGP (("\nUNIX TYPE L8: I know it and I will use \"LIST -a\" "
                       "as standard list command\n"));
              con->st |= LIST_AFTER_LIST_A_CHECK_DONE;
              con->st |= AVOID_LIST;
            }
          break;
        default:
          break;
        }

      /* Fourth: Find the initial ftp directory */

      if (!opt.server_response)
