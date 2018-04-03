 	}
       /* Third: Set type to Image (binary).  */
       if (!opt.server_response)
-	logprintf (LOG_VERBOSE, "==> TYPE %c ... ", toupper (u->ftp_type));
-      err = ftp_type (&con->rbuf, toupper (u->ftp_type));
+	logprintf (LOG_VERBOSE, "==> TYPE %c ... ", TOUPPER (u->ftp_type));
+      err = ftp_type (&con->rbuf, TOUPPER (u->ftp_type));
       /* FTPRERR, WRITEFAILED, FTPUNKNOWNTYPE */
       switch (err)
 	{
