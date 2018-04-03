       /* Third: Get the system type */
       if (!opt.server_response)
 	logprintf (LOG_VERBOSE, "==> SYST ... ");
-      err = ftp_syst (&con->rbuf, &host_type);
+      err = ftp_syst (&con->rbuf, &con->rs);
       /* FTPRERR */
       switch (err)
 	{
