 	pack_objects.argv = argv;
 
 	if (start_command(&pack_objects))
-		die("git-upload-pack: unable to fork git-pack-objects");
+		die("git upload-pack: unable to fork git-pack-objects");
 
 	/* We read from pack_objects.err to capture stderr output for
 	 * progress bar, and pack_objects.out to capture the pack data.
