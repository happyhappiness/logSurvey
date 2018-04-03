 	return !!rv;
 }
 
-static const char *extract_remote_arg(int *ac, const char **av)
-{
-	int ix, iy, cnt = *ac;
-	int no_more_options = 0;
-	const char *remote = NULL;
-
-	for (ix = iy = 1; ix < cnt; ix++) {
-		const char *arg = av[ix];
-		if (!strcmp(arg, "--"))
-			no_more_options = 1;
-		if (!no_more_options) {
-			if (!prefixcmp(arg, "--remote=")) {
-				if (remote)
-					die("Multiple --remote specified");
-				remote = arg + 9;
-				continue;
-			} else if (!strcmp(arg, "--remote")) {
-				if (remote)
-					die("Multiple --remote specified");
-				if (++ix >= cnt)
-					die("option --remote requires a value");
-				remote = av[ix];
-				continue;
-			}
-			if (arg[0] != '-')
-				no_more_options = 1;
-		}
-		if (ix != iy)
-			av[iy] = arg;
-		iy++;
-	}
-	if (remote) {
-		av[--cnt] = NULL;
-		*ac = cnt;
-	}
-	return remote;
-}
+#define PARSE_OPT_KEEP_ALL ( PARSE_OPT_KEEP_DASHDASH | 	\
+			     PARSE_OPT_KEEP_ARGV0 | 	\
+			     PARSE_OPT_KEEP_UNKNOWN |	\
+			     PARSE_OPT_NO_INTERNAL_HELP	)
 
 int cmd_archive(int argc, const char **argv, const char *prefix)
 {
+	const char *exec = "git-upload-archive";
+	const char *output = NULL;
 	const char *remote = NULL;
+	struct option local_opts[] = {
+		OPT_STRING(0, "output", &output, "file",
+			"write the archive to this file"),
+		OPT_STRING(0, "remote", &remote, "repo",
+			"retrieve the archive from remote repository <repo>"),
+		OPT_STRING(0, "exec", &exec, "cmd",
+			"path to the remote git-upload-archive command"),
+		OPT_END()
+	};
+
+	argc = parse_options(argc, argv, local_opts, NULL, PARSE_OPT_KEEP_ALL);
+
+	if (output)
+		create_output_file(output);
 
-	remote = extract_remote_arg(&argc, argv);
 	if (remote)
-		return run_remote_archiver(remote, argc, argv);
+		return run_remote_archiver(argc, argv, remote, exec);
 
 	setvbuf(stderr, NULL, _IOLBF, BUFSIZ);
 