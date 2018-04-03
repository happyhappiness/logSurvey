 		} else
 			usage_with_options(cat_file_usage, options);
 	}
-	if (batch.enabled && (opt || argc)) {
-		usage_with_options(cat_file_usage, options);
+	if (batch.enabled) {
+		if (batch.cmdmode != opt || argc)
+			usage_with_options(cat_file_usage, options);
+		if (batch.cmdmode && batch.all_objects)
+			die("--batch-all-objects cannot be combined with "
+			    "--textconv nor with --filters");
 	}
 
 	if ((batch.follow_symlinks || batch.all_objects) && !batch.enabled) {
