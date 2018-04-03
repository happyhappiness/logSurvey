 	struct child_process cp;
 	struct argv_array child_env = ARGV_ARRAY_INIT;
 	int counter = 0, len, ret;
+	struct strbuf symref = STRBUF_INIT;
+	struct commit *commit = NULL;
 	unsigned char rev[20];
 
 	if (file_exists(path) && !is_empty_dir(path))
 		die(_("'%s' already exists"), path);
 
+	/* is 'refname' a branch or commit? */
+	if (opts->force_new_branch) /* definitely a branch */
+		;
+	else if (!opts->detach && !strbuf_check_branch_ref(&symref, refname) &&
+		 ref_exists(symref.buf)) { /* it's a branch */
+		if (!opts->force)
+			die_if_checked_out(symref.buf);
+	} else { /* must be a commit */
+		commit = lookup_commit_reference_by_name(refname);
+		if (!commit)
+			die(_("invalid reference: %s"), refname);
+	}
+
 	name = worktree_basename(path, &len);
 	strbuf_addstr(&sb_repo,
 		      git_path("worktrees/%.*s", (int)(path + len - name), name));
