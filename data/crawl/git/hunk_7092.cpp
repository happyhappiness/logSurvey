 
 	argc = parse_options(argc, argv, options, builtin_remote_usage, 0);
 
-	if (argc < 1) {
-		if (!prune)
-			return show_all();
-		usage_with_options(builtin_remote_usage, options);
-	}
+	if (argc < 1)
+		return show_all();
 
 	memset(&states, 0, sizeof(states));
 	for (; argc; argc--, argv++) {
-		struct transport *transport;
-		const struct ref *ref;
 		struct strbuf buf;
 		int i;
 
-		states.remote = remote_get(*argv);
-		if (!states.remote)
-			return error("No such remote: %s", *argv);
-
-		read_branches();
-
-		if (!no_query) {
-			transport = transport_get(NULL,
-				states.remote->url_nr > 0 ?
-				states.remote->url[0] : NULL);
-			ref = transport_get_remote_refs(transport);
-			transport_disconnect(transport);
-
-			get_ref_states(ref, &states);
-		}
-
-		if (prune) {
-			for (i = 0; i < states.stale.nr; i++) {
-				const char *refname = states.stale.items[i].util;
-				result |= delete_ref(refname, NULL);
-			}
-			goto cleanup_states;
-		}
+		get_remote_ref_states(*argv, &states, !no_query);
 
 		printf("* remote %s\n  URL: %s\n", *argv,
 			states.remote->url_nr > 0 ?
