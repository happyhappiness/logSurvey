 			usage(cat_file_usage);
 
 		if (!exp_type) {
-			if (batch_check) {
-				error("git-cat-file: Can't specify a type (\"%s\") with --batch-check", arg);
+			if (batch || batch_check) {
+				error("git-cat-file: Can't specify a type (\"%s\") with %s", arg, batch ? "--batch" : "--batch-check");
 				usage(cat_file_usage);
 			}
 
