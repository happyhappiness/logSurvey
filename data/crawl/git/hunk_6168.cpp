 	}
 	dir = opendir(template_path);
 	if (!dir) {
-		fprintf(stderr, "warning: templates not found %s\n",
-			template_dir);
+		warning("templates not found %s", template_dir);
 		return;
 	}
 
