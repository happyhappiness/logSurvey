   else /* do not CWD */
     logputs (LOG_VERBOSE, _("==> CWD not required.\n"));
 
+  if ((cmd & DO_RETR) && restval && *len == 0)
+    {
+      if (opt.verbose)
+	{
+          if (!opt.server_response)
+	    logprintf (LOG_VERBOSE, "==> SIZE %s ... ", u->file);
+	}
+
+      err = ftp_size(&con->rbuf, u->file, len);
+      /* FTPRERR */
+      switch (err)
+	{
+	case FTPRERR:
+	case FTPSRVERR :
+	  logputs (LOG_VERBOSE, "\n");
+	  logputs (LOG_NOTQUIET, _("\
+Error in server response, closing control connection.\n"));
+	  CLOSE (csock);
+	  rbuf_uninitialize (&con->rbuf);
+	  return err;
+	  break;
+	case FTPOK:
+	  /* Everything is OK.  */
+	  break;
+	default:
+	  abort ();
+	  break;
+	}
+	if (!opt.server_response)
+	  logputs (LOG_VERBOSE, _("done.\n"));
+    }
+
   /* If anything is to be retrieved, PORT (or PASV) must be sent.  */
   if (cmd & (DO_LIST | DO_RETR))
     {
