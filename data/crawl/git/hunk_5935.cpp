 
 	fd = mkstemp(template);
 	if (fd < 0)
-		die("Unable to create temporary file: %s", strerror(errno));
+		die_errno("Unable to create temporary file");
 	return fd;
 }
 
