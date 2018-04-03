 	{
 	  if (!opt.server_response)
 	    logputs (LOG_VERBOSE, "==> PORT ... ");
-	  err = ftp_port (&con->rbuf);
+	  err = ftp_do_port (&con->rbuf);
 	  /* FTPRERR, WRITEFAILED, bindport (CONSOCKERR, CONPORTERR, BINDERR,
 	     LISTENERR), HOSTERR, FTPPORTERR */
 	  switch (err)
