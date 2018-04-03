
          ++fp;
          if (fp == ep)
            OS (fatal, flocp, _("Empty symbol name for load: %s"), *ldname);

          /* Make a copy of the ldname part.  */
          memcpy (new, *ldname, l);
