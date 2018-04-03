 		OPT__DRY_RUN(&dry_run),
 		OPT_END()
 	};
-	struct ref_states states;
-	const char *dangling_msg;
 
 	argc = parse_options(argc, argv, options, builtin_remote_usage, 0);
 
 	if (argc < 1)
 		usage_with_options(builtin_remote_usage, options);
 
-	dangling_msg = (dry_run
-			? " %s will become dangling!\n"
-			: " %s has become dangling!\n");
+	for (; argc; argc--, argv++)
+		result |= prune_remote(*argv, dry_run);
 
-	memset(&states, 0, sizeof(states));
-	for (; argc; argc--, argv++) {
-		int i;
-
-		get_remote_ref_states(*argv, &states, 1);
+	return result;
+}
 
-		if (states.stale.nr) {
-			printf("Pruning %s\n", *argv);
-			printf("URL: %s\n",
-			       states.remote->url_nr
-			       ? states.remote->url[0]
-			       : "(no URL)");
-		}
+static int prune_remote(const char *remote, int dry_run)
+{
+	int result = 0, i;
+	struct ref_states states;
+	const char *dangling_msg = dry_run
+		? " %s will become dangling!\n"
+		: " %s has become dangling!\n";
 
-		for (i = 0; i < states.stale.nr; i++) {
-			const char *refname = states.stale.items[i].util;
+	memset(&states, 0, sizeof(states));
+	get_remote_ref_states(remote, &states, GET_REF_STATES);
+
+	if (states.stale.nr) {
+		printf("Pruning %s\n", remote);
+		printf("URL: %s\n",
+		       states.remote->url_nr
+		       ? states.remote->url[0]
+		       : "(no URL)");
+	}
 
-			if (!dry_run)
-				result |= delete_ref(refname, NULL, 0);
+	for (i = 0; i < states.stale.nr; i++) {
+		const char *refname = states.stale.items[i].util;
 
-			printf(" * [%s] %s\n", dry_run ? "would prune" : "pruned",
-			       abbrev_ref(refname, "refs/remotes/"));
-			warn_dangling_symref(dangling_msg, refname);
-		}
+		if (!dry_run)
+			result |= delete_ref(refname, NULL, 0);
 
-		/* NEEDSWORK: free remote */
-		string_list_clear(&states.new, 0);
-		string_list_clear(&states.stale, 0);
-		string_list_clear(&states.tracked, 0);
+		printf(" * [%s] %s\n", dry_run ? "would prune" : "pruned",
+		       abbrev_ref(refname, "refs/remotes/"));
+		warn_dangling_symref(dangling_msg, refname);
 	}
 
+	free_remote_ref_states(&states);
 	return result;
 }
 
