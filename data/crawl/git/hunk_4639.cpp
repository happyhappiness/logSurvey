 
 	if (all) {
 		if (argc == 1)
-			die("fetch --all does not take a repository argument");
+			die(_("fetch --all does not take a repository argument"));
 		else if (argc > 1)
-			die("fetch --all does not make sense with refspecs");
+			die(_("fetch --all does not make sense with refspecs"));
 		(void) for_each_remote(get_one_remote_for_fetch, &list);
 		result = fetch_multiple(&list);
 	} else if (argc == 0) {
