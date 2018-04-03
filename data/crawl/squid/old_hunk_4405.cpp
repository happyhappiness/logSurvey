      fprintf(stderr, "%s| %s: error while resolving hostname '%s'\n", LogTime(), PROGRAM, hostname);
      return NULL;
    }
  rc = getaddrinfo(hostname,NULL,NULL,&hres);
  if (rc != 0) {
    fprintf(stderr, "%s| %s: error while resolving hostname with getaddrinfo: %s\n", LogTime(), PROGRAM, gai_strerror(rc));
    return NULL;
  }
  hres_list=hres;
