       switch (err)
 	{
 	case FTPRERR:
-	case FTPSRVERR :
+	case FTPSRVERR:
 	  logputs (LOG_VERBOSE, "\n");
 	  logputs (LOG_NOTQUIET, _("\
 Error in server response, closing control connection.\n"));
