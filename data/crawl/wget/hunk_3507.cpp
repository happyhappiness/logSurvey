     {
       if (opt.ftp_pasv > 0)
 	{
-	  char thost[256];
-	  unsigned short tport;
-
 	  if (!opt.server_response)
 	    logputs (LOG_VERBOSE, "==> PASV ... ");
 	  err = ftp_pasv (&con->rbuf, pasv_addr);
