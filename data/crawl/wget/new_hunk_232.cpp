    fp = output_stream;

  /* Print fetch message, if opt.verbose.  */
      logprintf (LOG_VERBOSE, _("Saving to: %s\n"),
                 HYPHENP (hs->local_file) ? quote ("STDOUT") : quote (hs->local_file));


  err = read_response_body (hs, sock, fp, contlen, contrange,
