 	info.list = &info_list;
 	for (; argc; argc--, argv++) {
 		int i;
+		const char **url;
+		int url_nr;
 
 		get_remote_ref_states(*argv, &states, query_flag);
 
 		printf("* remote %s\n", *argv);
-		if (states.remote->url_nr) {
-			for (i=0; i < states.remote->url_nr; i++)
-				printf("  URL: %s\n", states.remote->url[i]);
-		} else
-			printf("  URL: %s\n", "(no URL)");
+		printf("  Fetch URL: %s\n", states.remote->url_nr > 0 ?
+			states.remote->url[0] : "(no URL)");
+		if (states.remote->pushurl_nr) {
+			url = states.remote->pushurl;
+			url_nr = states.remote->pushurl_nr;
+		} else {
+			url = states.remote->url;
+			url_nr = states.remote->url_nr;
+		}
+		for (i=0; i < url_nr; i++)
+			printf("  Push  URL: %s\n", url[i]);
+		if (!i)
+			printf("  Push  URL: %s\n", "(no URL)");
 		if (no_query)
 			printf("  HEAD branch: (not queried)\n");
 		else if (!states.heads.nr)
