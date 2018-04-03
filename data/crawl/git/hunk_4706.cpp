 	if (opts.new_branch) {
 		struct strbuf buf = STRBUF_INIT;
 		if (strbuf_check_branch_ref(&buf, opts.new_branch))
-			die("git checkout: we do not like '%s' as a branch name.",
+			die(_("git checkout: we do not like '%s' as a branch name."),
 			    opts.new_branch);
 		if (!get_sha1(buf.buf, rev)) {
 			opts.branch_exists = 1;
 			if (!opts.new_branch_force)
-				die("git checkout: branch %s already exists",
+				die(_("git checkout: branch %s already exists"),
 				    opts.new_branch);
 		}
 		strbuf_release(&buf);
 	}
 
 	if (new.name && !new.commit) {
-		die("Cannot switch branch to a non-commit.");
+		die(_("Cannot switch branch to a non-commit."));
 	}
 	if (opts.writeout_stage)
-		die("--ours/--theirs is incompatible with switching branches.");
+		die(_("--ours/--theirs is incompatible with switching branches."));
 
 	return switch_branches(&opts, &new);
 }