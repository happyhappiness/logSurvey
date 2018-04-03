          logprintf (LOG_VERBOSE, _("Connecting to %s|%s|:%d... "),
                     str ? str : escnonprint_uri (print), txt_addr, port);

					if (str)
					  xfree (str);
        }
      else
       {
           if (ip->family == AF_INET)
               logprintf (LOG_VERBOSE, _("Connecting to %s:%d... "), txt_addr, port);
#ifdef ENABLE_IPV6
           else if (ip->family == AF_INET6)
               logprintf (LOG_VERBOSE, _("Connecting to [%s]:%d... "), txt_addr, port);
#endif
       }
    }

  /* Store the sockaddr info to SA.  */
