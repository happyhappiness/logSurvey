      return WRITEFAILED;
    }
  logprintf (LOG_VERBOSE, _("%s request sent, awaiting response... "),
	     u->proxy ? "Proxy" : "HTTP");
  contlen = contrange = -1;
  type = NULL;
  statcode = -1;
