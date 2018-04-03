 		strbuf_release(&sb);
 
 		*refs = get_submodule_ref_store(gitdir);
+	} else if (skip_prefix(argv[0], "worktree:", &gitdir)) {
+		struct worktree **p, **worktrees = get_worktrees(0);
+
+		for (p = worktrees; *p; p++) {
+			struct worktree *wt = *p;
+
+			if (!wt->id) {
+				/* special case for main worktree */
+				if (!strcmp(gitdir, "main"))
+					break;
+			} else if (!strcmp(gitdir, wt->id))
+				break;
+		}
+		if (!*p)
+			die("no such worktree: %s", gitdir);
+
+		*refs = get_worktree_ref_store(*p);
 	} else
 		die("unknown backend %s", argv[0]);
 
