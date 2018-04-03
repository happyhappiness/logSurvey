  rc = xgetaddrinfo(hostname,NULL,NULL,&hres);
  if (rc != 0) {
    fprintf(stderr, "%s| %s: error while resolving hostname with getaddrinfo: %s\n", LogTime(), PROGRAM, xgai_strerror(rc));
    xfreeaddrinfo(hres);
    return NULL;
  }
  hres_list=hres;
