 	if (depth)
 		return -1;
 
-	for (i = 0, ref = ref_map; ref; ref = ref->next)
-		i++;
-	if (!i)
+	if (!ref_map)
 		return 0;
 
-	argv = xmalloc(sizeof(*argv) * (i + 6));
-	i = 0;
-	argv[i++] = xstrdup("rev-list");
-	argv[i++] = xstrdup("--quiet");
-	argv[i++] = xstrdup("--objects");
-	for (ref = ref_map; ref; ref = ref->next)
-		argv[i++] = xstrdup(sha1_to_hex(ref->old_sha1));
-	argv[i++] = xstrdup("--not");
-	argv[i++] = xstrdup("--all");
-	argv[i++] = NULL;
-
 	memset(&revlist, 0, sizeof(revlist));
-	revlist.argv = (const char**)argv;
+	revlist.argv = argv;
 	revlist.git_cmd = 1;
-	revlist.no_stdin = 1;
 	revlist.no_stdout = 1;
 	revlist.no_stderr = 1;
-	err = run_command(&revlist);
+	revlist.in = -1;
+
+	err = start_command(&revlist);
+	if (err) {
+		error("could not run rev-list");
+		return err;
+	}
+
+	/*
+	 * If rev-list --stdin encounters an unknown commit, it terminates,
+	 * which will cause SIGPIPE in the write loop below.
+	 */
+	sigchain_push(SIGPIPE, SIG_IGN);
+
+	for (ref = ref_map; ref; ref = ref->next) {
+		if (write_in_full(revlist.in, sha1_to_hex(ref->old_sha1), 40) < 0 ||
+		    write_in_full(revlist.in, "\n", 1) < 0) {
+			if (errno != EPIPE && errno != EINVAL)
+				error("failed write to rev-list: %s", strerror(errno));
+			err = -1;
+			break;
+		}
+	}
+
+	if (close(revlist.in)) {
+		error("failed to close rev-list's stdin: %s", strerror(errno));
+		err = -1;
+	}
+
+	sigchain_pop(SIGPIPE);
 
-	for (i = 0; argv[i]; i++)
-		free(argv[i]);
-	free(argv);
-	return err;
+	return finish_command(&revlist) || err;
 }
 
 static int fetch_refs(struct transport *transport, struct ref *ref_map)
