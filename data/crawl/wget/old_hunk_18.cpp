for details.\n\n"));
          opt.timestamping = false;
        }
      if (opt.noclobber && file_exists_p(opt.output_document))
           {
              /* Check if output file exists; if it does, exit. */
              logprintf (LOG_VERBOSE,
