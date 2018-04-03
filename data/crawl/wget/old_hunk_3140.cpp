  else
    {
      logprintf (LOG_VERBOSE, "\n");
      print_server_response (resp);
    }

  hs->statcode = statcode;
  if (statcode == -1)
