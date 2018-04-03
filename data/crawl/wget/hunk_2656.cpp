 	    }
 	}
 
-      if (opt.delete_after || (file && !acceptable (file)))
+      if (file 
+          && (opt.delete_after 
+              || opt.spider /* opt.recursive is implicitely true */
+              || !acceptable (file)))
 	{
 	  /* Either --delete-after was specified, or we loaded this
-	     otherwise rejected (e.g. by -R) HTML file just so we
-	     could harvest its hyperlinks -- in either case, delete
-	     the local file. */
+	     (otherwise unneeded because of --spider or rejected by -R) 
+	     HTML file just to harvest its hyperlinks -- in either case, 
+	     delete the local file. */
 	  DEBUGP (("Removing file due to %s in recursive_retrieve():\n",
 		   opt.delete_after ? "--delete-after" :
-		   "recursive rejection criteria"));
+		   (opt.spider ? "--spider" : 
+		    "recursive rejection criteria")));
 	  logprintf (LOG_VERBOSE,
-		     (opt.delete_after
+		     (opt.delete_after || opt.spider
 		      ? _("Removing %s.\n")
 		      : _("Removing %s since it should be rejected.\n")),
 		     file);
