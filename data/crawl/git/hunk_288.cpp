 	int argcount;
 
 	if (submodule) {
+		/*
+		 * We need some something like get_submodule_worktrees()
+		 * before we can go through all worktrees of a submodule,
+		 * .e.g with adding all HEADs from --all, which is not
+		 * supported right now, so stick to single worktree.
+		 */
+		if (!revs->single_worktree)
+			die("BUG: --single-worktree cannot be used together with submodule");
 		refs = get_submodule_ref_store(submodule);
 	} else
 		refs = get_main_ref_store();
