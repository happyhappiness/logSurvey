      }
    al = address_list_from_addrinfo (res);
    freeaddrinfo (res);
  }
#else
  {
