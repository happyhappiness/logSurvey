 	return ret ? error("Fetch failed.") : 0;
 }
 
+static int fetch_git(struct discovery *heads,
+	int nr_heads, struct ref **to_fetch)
+{
+	struct rpc_state rpc;
+	char *depth_arg = NULL;
+	const char **argv;
+	int argc = 0, i, err;
+
+	argv = xmalloc((15 + nr_heads) * sizeof(char*));
+	argv[argc++] = "fetch-pack";
+	argv[argc++] = "--stateless-rpc";
+	argv[argc++] = "--lock-pack";
+	if (options.followtags)
+		argv[argc++] = "--include-tag";
+	if (options.thin)
+		argv[argc++] = "--thin";
+	if (options.verbosity >= 3) {
+		argv[argc++] = "-v";
+		argv[argc++] = "-v";
+	}
+	if (!options.progress)
+		argv[argc++] = "--no-progress";
+	if (options.depth) {
+		struct strbuf buf = STRBUF_INIT;
+		strbuf_addf(&buf, "--depth=%lu", options.depth);
+		depth_arg = strbuf_detach(&buf, NULL);
+		argv[argc++] = depth_arg;
+	}
+	argv[argc++] = url;
+	for (i = 0; i < nr_heads; i++) {
+		struct ref *ref = to_fetch[i];
+		if (!ref->name || !*ref->name)
+			die("cannot fetch by sha1 over smart http");
+		argv[argc++] = ref->name;
+	}
+	argv[argc++] = NULL;
+
+	memset(&rpc, 0, sizeof(rpc));
+	rpc.service_name = "git-upload-pack",
+	rpc.argv = argv;
+
+	err = rpc_service(&rpc, heads);
+	if (rpc.result.len)
+		safe_write(1, rpc.result.buf, rpc.result.len);
+	strbuf_release(&rpc.result);
+	free(argv);
+	free(depth_arg);
+	return err;
+}
+
+static int fetch(int nr_heads, struct ref **to_fetch)
+{
+	struct discovery *d = discover_refs("git-upload-pack");
+	if (d->proto_git)
+		return fetch_git(d, nr_heads, to_fetch);
+	else
+		return fetch_dumb(nr_heads, to_fetch);
+}
+
 static void parse_fetch(struct strbuf *buf)
 {
 	struct ref **to_fetch = NULL;
