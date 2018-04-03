
  host = gethostbyaddr ((char *)&permit.addr, sizeof(permit.addr), AF_INET);

  {
    const char *hnm = host ? host->h_name : inet_ntoa (permit.addr);
    size_t hlen = strlen (hnm);

    if (status != RPC_SUCCESS)
      {
        const char *err = Rpc_ErrorMessage (status);
        (void) close (retsock);
        (void) close (sock);
        error (NILF, hlen + strlen (err),
               "exporting to %s: %s", hnm, err);
        return 1;
      }
    else if (msg[0] != 'O' || msg[1] != 'k' || msg[2] != '\0')
      {
        (void) close (retsock);
        (void) close (sock);
        error (NILF, hlen + strlen (msg), "exporting to %s: %s", hnm, msg);
        return 1;
      }
    else
      {
        error (NILF, hlen + INTSTR_LENGTH,
               "*** exported to %s (id %u)", hnm, permit.id);
      }

    fflush (stdout);
    fflush (stderr);
  }

  pid = fork ();
  if (pid < 0)
