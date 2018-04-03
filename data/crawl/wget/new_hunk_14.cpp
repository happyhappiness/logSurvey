  /* If we receive .listing file it is necessary to determine system type of the ftp
     server even if opn.noclobber is given. Thus we must ignore opt.noclobber in
     order to establish connection with the server and get system type. */
  if (opt.noclobber && !opt.output_document && file_exists_p (con->target, NULL)
      && !((con->cmd & DO_LIST) && !(con->cmd & DO_RETR)))
    {
      logprintf (LOG_VERBOSE,
