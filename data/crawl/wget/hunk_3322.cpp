   	  unsigned short passive_port;
 	  if (!opt.server_response)
 	    logputs (LOG_VERBOSE, "==> PASV ... ");
-	  err = ftp_pasv (&con->rbuf, &passive_addr, &passive_port);
+	  err = ftp_do_pasv (&con->rbuf, &passive_addr, &passive_port);
 	  /* FTPRERR, WRITEFAILED, FTPNOPASV, FTPINVPASV */
 	  switch (err)
 	    {
