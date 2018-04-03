    count++;
    hres_list=hres_list->ai_next;
  }
  rc = xgetnameinfo(hres->ai_addr, hres->ai_addrlen,hostname, sizeof (hostname), NULL, 0, 0);
  if (rc != 0) {
    fprintf(stderr, "%s| %s: error while resolving ip address with getnameinfo: %s\n", LogTime(), PROGRAM, xgai_strerror(rc));
    xfreeaddrinfo(hres);
    return NULL ;
  }

  xfreeaddrinfo(hres);
  hostname[MAXHOSTNAMELEN]='\0';
  return(strdup(hostname));
}
