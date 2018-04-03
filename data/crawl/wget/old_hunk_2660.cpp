  else
    fp = output_stream;

  /* This confuses the timestamping code that checks for file size.
     #### The timestamping code should be smarter about file size.  */
  if (opt.save_headers && hs->restval == 0)
