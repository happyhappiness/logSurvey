 	setup_git_directory();
 
 	if (strbuf_read(&buf, 0, 4096) < 0) {
-		die("could not read from stdin");
+		die_errno("could not read from stdin");
 	}
 
 	/* Verify it for some basic sanity: it needs to start with
