 	  break;
 	}
 #ifdef HAVE_SSL
-     if (u->proto==URLHTTPS) if (connect_ssl(&ssl,ssl_ctx,sock)!=0) {
-  	    logputs (LOG_VERBOSE, "\n");
-	    logprintf (LOG_NOTQUIET, _("Unable to establish SSL connection.\n"));
-  	    CLOSE (sock);
-	    return CONSSLERR;
-	  }
+     if (u->proto == URLHTTPS)
+       if (connect_ssl (&ssl, ssl_ctx,sock) != 0)
+	 {
+	   logputs (LOG_VERBOSE, "\n");
+	   logprintf (LOG_NOTQUIET, _("Unable to establish SSL connection.\n"));
+	   CLOSE (sock);
+	   return CONSSLERR;
+	 }
 #endif /* HAVE_SSL */
     }
   else
