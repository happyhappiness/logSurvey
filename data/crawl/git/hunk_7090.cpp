 	for (; argc; argc--, argv++) {
 		int i;
 
-		get_remote_ref_states(*argv, &states, !no_query);
+		get_remote_ref_states(*argv, &states, 1);
+
+		printf("Pruning %s\n", *argv);
+		if (states.stale.nr)
+			printf("URL: %s\n",
+			       states.remote->url_nr
+			       ? states.remote->url[0]
+			       : "(no URL)");
 
 		for (i = 0; i < states.stale.nr; i++) {
 			const char *refname = states.stale.items[i].util;
-			result |= delete_ref(refname, NULL);
+
+			if (!dry_run)
+				result |= delete_ref(refname, NULL);
+
+			printf(" * [%s] %s\n", dry_run ? "would prune" : "pruned",
+			       skip_prefix(refname, "refs/remotes/"));
 		}
 
 		/* NEEDSWORK: free remote */
