       /* Third: Get the system type */
       if (!opt.server_response)
         logprintf (LOG_VERBOSE, "==> SYST ... ");
-      err = ftp_syst (csock, &con->rs);
+      err = ftp_syst (csock, &con->rs, &con->rsu);
       /* FTPRERR */
       switch (err)
         {
