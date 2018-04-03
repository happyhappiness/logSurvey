       type_char = ftp_process_type (u->params);
       if (!opt.server_response)
 	logprintf (LOG_VERBOSE, "==> TYPE %c ... ", type_char);
-      err = ftp_type (&con->rbuf, type_char);
+      err = ftp_type (csock, type_char);
       /* FTPRERR, WRITEFAILED, FTPUNKNOWNTYPE */
       switch (err)
 	{
