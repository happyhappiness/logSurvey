 	reap_children (1, 0);
 
       if (batch_filename) {
-	if (debug_flag)
-	  printf(_("Cleaning up temporary batch file %s\n"), batch_filename);
+	DB (DB_EXTRA, (_("Cleaning up temporary batch file %s\n"),
+                       batch_filename));
 	remove(batch_filename);
 	free(batch_filename);
       }
