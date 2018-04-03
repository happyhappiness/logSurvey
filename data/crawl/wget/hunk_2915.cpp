     {
       if (!can_validate)
 	{
-	  logprintf (LOG_NOTQUIET, "Warrining validation of Server Cert not possible!\n");
+	  logputs (LOG_NOTQUIET,
+		   _("Warning: validation of server certificate not possible!\n"));
 	  verify = SSL_VERIFY_NONE;
 	}
      else
 	{
-	  /* break handshake if server cert is not valid but allow NO-Cert mode */
+	  /* break handshake if server cert is not valid but allow
+	     NO-Cert mode */
 	  verify = SSL_VERIFY_PEER;
 	}
     }
