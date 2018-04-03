     {
       /* Initialize the SSL context.  After this has once been done,
 	 it becomes a no-op.  */
-      switch (ssl_init ())
+      if (!ssl_init ())
 	{
-	case SSLERRCTXCREATE:
-	  /* this is fatal */
-	  logprintf (LOG_NOTQUIET, _("Failed to set up an SSL context\n"));
-	  return SSLERRCTXCREATE;
-	case SSLERRCERTFILE:
-	  /* try without certfile */
+	  scheme_disable (SCHEME_HTTPS);
 	  logprintf (LOG_NOTQUIET,
-		     _("Failed to load certificates from %s\n"),
-		     opt.cert_file);
-	  logprintf (LOG_NOTQUIET,
-		     _("Trying without the specified certificate\n"));
-	  break;
-	case SSLERRCERTKEY:
-	  logprintf (LOG_NOTQUIET,
-		     _("Failed to get private key from %s\n"),
-		     opt.private_key);
-	  logprintf (LOG_NOTQUIET,
-		     _("Trying without the specified certificate\n"));
-	  break;
-	default:
-	  break;
+		     _("Disabling SSL due to encountered errors.\n"));
+	  return SSLINITFAILED;
 	}
     }
 #endif /* HAVE_SSL */
