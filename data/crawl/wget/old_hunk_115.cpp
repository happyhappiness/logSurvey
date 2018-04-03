  local_sock = -1;
  con->dltime = 0;

  if (!(cmd & DO_LOGIN))
    csock = con->csock;
  else                          /* cmd & DO_LOGIN */
    {
      char    *host = con->proxy ? con->proxy->host : u->host;
