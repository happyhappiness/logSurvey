					  xfree (str);
        }
      else
       {
           if (ip->family == AF_INET)
               logprintf (LOG_VERBOSE, _("Connecting to %s:%d... "), txt_addr, port);
           else if (ip->family == AF_INET6)
               logprintf (LOG_VERBOSE, _("Connecting to [%s]:%d... "), txt_addr, port);
       }
    }

  /* Store the sockaddr info to SA.  */
