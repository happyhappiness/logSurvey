    }
  logprintf (LOG_VERBOSE, _("%s request sent, awaiting response... "),
	     proxy ? "Proxy" : "HTTP");
  contlen = contrange = -1;
  type = NULL;
  statcode = -1;
  *dt &= ~RETROKF;
