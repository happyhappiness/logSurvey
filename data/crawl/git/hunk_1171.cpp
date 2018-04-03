 		usage_with_options(cat_file_usage, options);
 	}
 
+	if (force_path && batch.enabled) {
+		error("--path=<path> incompatible with --batch");
+		usage_with_options(cat_file_usage, options);
+	}
+
 	if (batch.buffer_output < 0)
 		batch.buffer_output = batch.all_objects;
 
