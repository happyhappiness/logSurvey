    return -1;

#ifdef SO_REUSEADDR
  setsockopt (sock, SOL_SOCKET, SO_REUSEADDR, setopt_ptr, setopt_size);
#endif

  xzero (ss);
