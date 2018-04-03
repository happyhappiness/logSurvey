 
       if (!link_has_scheme)
 	{
-	  /* We have no base, and the link does not have a host
-	     attached to it.  Nothing we can do.  */
-	  /* #### Should we print a warning here?  Wget 1.5.x used to.  */
+	  /* Base URL is unavailable, and the link does not have a
+	     location attached to it -- we have to give up.  Since
+	     this can only happen when using `--force-html -i', print
+	     a warning.  */
+	  logprintf (LOG_NOTQUIET,
+		     _("%s: Cannot resolve relative link %s.\n"),
+		     ctx->document_file, link_uri);
 	  return NULL;
 	}
 
