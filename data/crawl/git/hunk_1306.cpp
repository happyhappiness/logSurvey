 			struct commit *commit = get_merge_parent(argv[i]);
 			if (!commit)
 				help_unknown_ref(argv[i], "merge",
-						 "not something we can merge");
+						 _("not something we can merge"));
 			remotes = &commit_list_insert(commit, remotes)->next;
 		}
 		remoteheads = reduce_parents(head_commit, head_subsumed, remoteheads);
