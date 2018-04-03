          /* If opt.noclobber is turned on and file already exists, do not
             retrieve the file */
          logprintf (LOG_VERBOSE, _("\
File %s already there; not retrieving.\n\n"), quote (hs->local_file));
          /* If the file is there, we suppose it's retrieved OK.  */
          *dt |= RETROKF;

