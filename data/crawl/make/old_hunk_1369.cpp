		     len, (Rpc_Opaque) waybill,
		     sizeof(msg), (Rpc_Opaque) msg,
		     1, &timeout);
  if (status != RPC_SUCCESS)
    {
      (void) close (retsock);
      (void) close (sock);
      error ("exporting: %s", Rpc_ErrorMessage (status));
      return 1;
    }
  else if (msg[0] != 'O' || msg[1] != 'k' || msg[2] != '\0')
    {
      (void) close (retsock);
      (void) close (sock);
      error ("CUSTOMS_IMPORT: %s", msg);
      return 1;
    }
  else if (debug_flag)
    {
      struct hostent *host = gethostbyaddr (&permit.addr, sizeof (permit.addr),
					    AF_INET);
      printf ("Job exported to %s ID %u\n",
	      host == 0 ? inet_ntoa (permit.addr) : host->h_name,
	      permit.id);
    }

