     {
       if (opt.ftp_pasv > 0)
 	{
-  	  ip_address     passive_addr;
-  	  unsigned short passive_port;
-	  if (!opt.server_response)
-	    logputs (LOG_VERBOSE, "==> PASV ... ");
+  	  ip_address passive_addr;
+  	  int        passive_port;
 	  err = ftp_do_pasv (&con->rbuf, &passive_addr, &passive_port);
 	  /* FTPRERR, WRITEFAILED, FTPNOPASV, FTPINVPASV */
 	  switch (err)