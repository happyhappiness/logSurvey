 	keep_fd = open(name, O_RDWR|O_CREAT|O_EXCL, 0600);
 	if (keep_fd < 0)
 		die("cannot create keep file");
-	write(keep_fd, keep_msg, strlen(keep_msg));
-	close(keep_fd);
+	write_or_die(keep_fd, keep_msg, strlen(keep_msg));
+	if (close(keep_fd))
+		die("failed to write keep file");
 
 	snprintf(name, sizeof(name), "%s/pack/pack-%s.pack",
 		 get_object_directory(), sha1_to_hex(pack_data->sha1));