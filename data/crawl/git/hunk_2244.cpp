 	if (!socket_path)
 		usage_with_options(usage, options);
 
+	if (!is_absolute_path(socket_path))
+		die("socket directory must be an absolute path");
+
 	init_socket_directory(socket_path);
 	register_tempfile(&socket_file, socket_path);
 