      if (opt.verbose)
        {
          char *hurl = url_string (u, true);
          
          if (count > 1) 
            {
              char tmp[256];
              sprintf (tmp, _("(try:%2d)"), count);
              logprintf (LOG_NOTQUIET, "--%s--  %s  %s\n\n",
                         tms, tmp, hurl);
            }
          else 
            {
              logprintf (LOG_NOTQUIET, "--%s--  %s\n\n",
                         tms, hurl);
            }
          
#ifdef WINDOWS
