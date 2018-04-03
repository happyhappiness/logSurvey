       unsigned int mm_idx = 0;
       char **nargv = argv;
       int nargc = argc;
+      int orig_db_level = db_level;
 
-      if (debug_flag)
-	puts (_("Updating makefiles...."));
+      if (! ISDB (DB_MAKEFILES))
+        db_level = DB_NONE;
+
+      DB (DB_BASIC, (_("Updating makefiles....\n")));
 
       /* Remove any makefiles we don't want to try to update.
 	 Also record the current modtimes so we can compare them later.  */
