 	for (i = 0; i < argc; i++) {
 		struct commit *commit = get_merge_parent(argv[i]);
 		if (!commit)
-			die(_("%s - not something we can merge"), argv[i]);
+			help_unknown_ref(argv[i], "merge",
+					 "not something we can merge");
 		remotes = &commit_list_insert(commit, remotes)->next;
 	}
 	*remotes = NULL;