 
 	if (incremental || (output_option & OUTPUT_PORCELAIN)) {
 		if (show_progress > 0)
-			die("--progress can't be used with --incremental or porcelain formats");
+			die(_("--progress can't be used with --incremental or porcelain formats"));
 		show_progress = 0;
 	} else if (show_progress < 0)
 		show_progress = isatty(2);
