 		usage_with_options(cat_file_usage, options);
 	}
 
+	if (force_path && opt != 'c' && opt != 'w') {
+		error("--path=<path> needs --textconv or --filters");
+		usage_with_options(cat_file_usage, options);
+	}
+
 	if (batch.buffer_output < 0)
 		batch.buffer_output = batch.all_objects;
 
