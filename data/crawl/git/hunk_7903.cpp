 	const char *argv[10];
 	int arg = 0;
 
-	if (pipe(lp_pipe) < 0)
-		die("git-upload-pack: unable to create pipe");
-	pid_rev_list = fork();
-	if (pid_rev_list < 0)
+	rev_list.proc = do_rev_list;
+	/* .data is just a boolean: any non-NULL value will do */
+	rev_list.data = create_full_pack ? &rev_list : NULL;
+	if (start_async(&rev_list))
 		die("git-upload-pack: unable to fork git-rev-list");
 
-	if (!pid_rev_list) {
-		close(lp_pipe[0]);
-		pack_pipe = fdopen(lp_pipe[1], "w");
-		do_rev_list(create_full_pack);
-		exit(0);
-	}
-
-	/* writable pipe end must not be inherited by pack_objects */
-	close(lp_pipe[1]);
-
 	argv[arg++] = "pack-objects";
 	argv[arg++] = "--stdout";
 	if (!no_progress)
