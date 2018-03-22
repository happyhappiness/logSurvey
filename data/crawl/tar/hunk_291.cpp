   /* Print the block from current_header and current_stat.  */
 
   if (verbose_option)
-    print_header ();
-
-  /* Check for fully specified file names and other atrocities.  */
-
-  skipcrud = 0;
-  if (! absolute_names_option)
-    {
-      if (contains_dot_dot (CURRENT_FILE_NAME))
-	{
-	  ERROR ((0, 0, _("%s: Member name contains `..'"),
-		  quotearg_colon (CURRENT_FILE_NAME)));
-	  skip_member ();
-	  return;
-	}
+    print_header (-1);
 
-      skipcrud = FILESYSTEM_PREFIX_LEN (current_file_name);
-      while (ISSLASH (CURRENT_FILE_NAME[0]))
-	skipcrud++;
+  file_name = safer_name_suffix (current_file_name, 0);
 
-      if (skipcrud)
-	{
-	  static int warned_once;
-	  
-	  if (!warned_once)
-	    {
-	      warned_once = 1;
-	      WARN ((0, 0, _("Removing leading `%.*s' from member names"),
-		     (int) skipcrud, current_file_name));
-	    }
-	}
-    }
-
-  apply_nonancestor_delayed_set_stat (CURRENT_FILE_NAME, 0);
+  apply_nonancestor_delayed_set_stat (file_name, 0);
 
   /* Take a safety backup of a previously existing file.  */
 
   if (backup_option && !to_stdout_option)
-    if (!maybe_backup_file (CURRENT_FILE_NAME, 0))
+    if (!maybe_backup_file (file_name, 0))
       {
 	int e = errno;
 	ERROR ((0, e, _("%s: Was unable to backup this file"),
-		quotearg_colon (CURRENT_FILE_NAME)));
+		quotearg_colon (file_name)));
 	skip_member ();
 	return;
       }
