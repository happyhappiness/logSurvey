      return 1;
    }

  /* Create the return socket.  */
  retsock = Rpc_UdpCreate (True, 0);
  if (retsock < 0)
