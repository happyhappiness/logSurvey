    }
  /* Now weed out the files that do not match our globbing pattern.
     If we are dealing with a globbing pattern, that is.  */
  if (*u->file)
    {
      if (action == GLOB_GLOBALL)
        {
          int (*matcher) (const char *, const char *, int)
            = opt.ignore_case ? fnmatch_nocase : fnmatch;
          int matchres = 0;

          f = start;
          while (f)
            {
              matchres = matcher (u->file, f->name, 0);
              if (matchres == -1)
                {
                  logprintf (LOG_NOTQUIET, _("Error matching %s against %s: %s\n"),
                             u->file, escnonprint (f->name), strerror (errno));
                  break;
                }
              if (matchres == FNM_NOMATCH)
                f = delelement (f, &start); /* delete the element from the list */
              else
                f = f->next;        /* leave the element in the list */
            }
          if (matchres == -1)
            {
              freefileinfo (start);
              return RETRBADPATTERN;
            }
        }
      else if (action == GLOB_GETONE)
        {
          int (*cmp) (const char *, const char *)
            = opt.ignore_case ? strcasecmp : strcmp;
          f = start;
          while (f)
            {
              if (0 != cmp(u->file, f->name))
                f = delelement (f, &start);
              else
                f = f->next;
            }
        }
    }
  if (start)
