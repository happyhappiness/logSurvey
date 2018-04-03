        {
          /* If opt.noclobber is turned on and file already exists, do not
             retrieve the file. But if the output_document was given, then this
             test was already done and the file didn't exist. Hence the !opt.output_document */
          logprintf (LOG_VERBOSE, _("\
File `%s' already there; not retrieving.\n\n"), hs->local_file);
          /* If the file is there, we suppose it's retrieved OK.  */
