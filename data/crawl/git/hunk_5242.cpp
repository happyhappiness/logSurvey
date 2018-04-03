 	return run_command_v_opt(fetch_argv, RUN_GIT_CMD);
 }
 
+static int remove_all_fetch_refspecs(const char *remote, const char *key)
+{
+	return git_config_set_multivar(key, NULL, NULL, 1);
+}
+
+static int add_branches(struct remote *remote, const char **branches,
+			const char *key)
+{
+	const char *remotename = remote->name;
+	int mirror = remote->mirror;
+	struct strbuf refspec = STRBUF_INIT;
+
+	for (; *branches; branches++)
+		if (add_branch(key, *branches, remotename, mirror, &refspec)) {
+			strbuf_release(&refspec);
+			return 1;
+		}
+
+	strbuf_release(&refspec);
+	return 0;
+}
+
+static int set_remote_branches(const char *remotename, const char **branches,
+				int add_mode)
+{
+	struct strbuf key = STRBUF_INIT;
+	struct remote *remote;
+
+	strbuf_addf(&key, "remote.%s.fetch", remotename);
+
+	if (!remote_is_configured(remotename))
+		die("No such remote '%s'", remotename);
+	remote = remote_get(remotename);
+
+	if (!add_mode && remove_all_fetch_refspecs(remotename, key.buf)) {
+		strbuf_release(&key);
+		return 1;
+	}
+	if (add_branches(remote, branches, key.buf)) {
+		strbuf_release(&key);
+		return 1;
+	}
+
+	strbuf_release(&key);
+	return 0;
+}
+
+static int set_branches(int argc, const char **argv)
+{
+	int add_mode = 0;
+	struct option options[] = {
+		OPT_BOOLEAN('\0', "add", &add_mode, "add branch"),
+		OPT_END()
+	};
+
+	argc = parse_options(argc, argv, NULL, options,
+			     builtin_remote_setbranches_usage, 0);
+	if (argc == 0) {
+		error("no remote specified");
+		usage_with_options(builtin_remote_seturl_usage, options);
+	}
+	argv[argc] = NULL;
+
+	return set_remote_branches(argv[0], argv + 1, add_mode);
+}
+
 static int set_url(int argc, const char **argv)
 {
 	int i, push_mode = 0, add_mode = 0, delete_mode = 0;
