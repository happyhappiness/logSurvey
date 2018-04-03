 		enum update_mode mode = modes[i];
 		int pos;
 		if (show_only || verbose)
-			printf("Renaming %s to %s\n", src, dst);
+			printf(_("Renaming %s to %s\n"), src, dst);
 		if (!show_only && mode != INDEX &&
 				rename(src, dst) < 0 && !ignore_errors)
-			die_errno ("renaming '%s' failed", src);
+			die_errno (_("renaming '%s' failed"), src);
 
 		if (mode == WORKING_DIRECTORY)
 			continue;
