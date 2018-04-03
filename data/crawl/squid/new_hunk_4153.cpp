    count++;
    hres_list=hres_list->ai_next;
  }
  rc = xgetnameinfo (hres->ai_addr, hres->ai_addrlen,hostname, sizeof (hostname), NULL, 0, 0);
  if (rc != 0) {
    fprintf(stderr, "%s| %s: error while resolving ip address with getnameinfo: %s\n", LogTime(), PROGRAM, xgai_strerror(rc));
    xfreeaddrinfo(hres);
    return NULL ;
  }

  xfreeaddrinfo(hres);
  hostname[sysconf(_SC_HOST_NAME_MAX)-1]='\0';
  return(xstrdup(hostname));
}

int check_gss_err(OM_uint32 major_status, OM_uint32 minor_status, const char* function, int debug, int log) {
  if (GSS_ERROR(major_status)) {
    OM_uint32 maj_stat,min_stat;
    OM_uint32 msg_ctx = 0;
