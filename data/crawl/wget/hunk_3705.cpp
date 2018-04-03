       err = ftp_pwd(&con->rbuf, &con->id);
       /* FTPRERR */
       switch (err)
-      {
-	case FTPRERR || FTPSRVERR :
+	{
+	case FTPRERR:
+	case FTPSRVERR :
 	  logputs (LOG_VERBOSE, "\n");
 	  logputs (LOG_NOTQUIET, _("\
 Error in server response, closing control connection.\n"));
