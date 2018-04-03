 	if (run_diff_files(&rev, 0))
 		die(_("Could not write patch"));
 
-	launch_editor(file, NULL, NULL);
+	if (launch_editor(file, NULL, NULL))
+		die(_("editing patch failed"));
 
 	if (stat(file, &st))
 		die_errno(_("Could not stat '%s'"), file);
