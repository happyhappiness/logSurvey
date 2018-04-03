 
 	strbuf_addstr(&temp_dir, git_path("rsync-refs-XXXXXX"));
 	if (!mkdtemp(temp_dir.buf))
-		die ("Could not make temporary directory");
+		die_errno ("Could not make temporary directory");
 	strbuf_addch(&temp_dir, '/');
 
 	if (flags & TRANSPORT_PUSH_ALL) {
