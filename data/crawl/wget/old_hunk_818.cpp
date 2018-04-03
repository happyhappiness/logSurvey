      print_server_response (resp, "  ");
    }

  /* Determine the local filename if needed. Notice that if -O is used 
   * hstat.local_file is set by http_loop to the argument of -O. */
  if (!hs->local_file)
