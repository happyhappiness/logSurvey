 
 		get_remote_ref_states(*argv, &states, 1);
 
-		printf("Pruning %s\n", *argv);
-		if (states.stale.nr)
+		if (states.stale.nr) {
+			printf("Pruning %s\n", *argv);
 			printf("URL: %s\n",
 			       states.remote->url_nr
 			       ? states.remote->url[0]
 			       : "(no URL)");
+		}
 
 		for (i = 0; i < states.stale.nr; i++) {
 			const char *refname = states.stale.items[i].util;