 	po.out = fd;
 	po.git_cmd = 1;
 	if (start_command(&po))
-		die("git pack-objects failed (%s)", strerror(errno));
+		die_errno("git pack-objects failed");
 
 	/*
 	 * We feed the pack-objects we just spawned with revision
