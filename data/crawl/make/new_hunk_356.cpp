      static int lossage = -1;
      /* Complain only once for the same error.  */
      if (lossage == -1 || errno != lossage)
        {
          if (errno == 0)
            /* An errno value of zero means getloadavg is just unsupported.  */
            error (NILF,
                   _("cannot enforce load limits on this operating system"));
          else
            perror_with_name (_("cannot enforce load limit: "), "getloadavg");
        }
      lossage = errno;
      load = 0;
    }
