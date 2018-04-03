          /* If opt.noclobber is turned on and file already exists, do not
             retrieve the file. But if the output_document was given, then this
             test was already done and the file didn't exist. Hence the !opt.output_document */
          get_file_flags (hs->local_file, dt);
          xfree (head);
          xfree_null (message);
          return RETRUNNEEDED;
