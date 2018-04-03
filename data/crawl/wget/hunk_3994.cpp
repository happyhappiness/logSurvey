 	  else
 	    DEBUGP (("%s is not text/html so we don't chase.\n",
 		     filename ? filename: "(null)"));
-	  /* If an suffix-rejected file was loaded only because it was HTML,
-	     undo the error now */
+
 	  if (opt.delete_after || (filename && !acceptable (filename)))
+	    /* Either --delete-after was specified, or we loaded this otherwise
+	       rejected (e.g. by -R) HTML file just so we could harvest its
+	       hyperlinks -- in either case, delete the local file. */
 	    {
+	      DEBUGP (("Removing file due to %s in recursive_retrieve():\n",
+		       opt.delete_after ? "--delete-after" :
+		       "recursive rejection criteria"));
 	      logprintf (LOG_VERBOSE,
 			 (opt.delete_after ? _("Removing %s.\n")
 			  : _("Removing %s since it should be rejected.\n")),
