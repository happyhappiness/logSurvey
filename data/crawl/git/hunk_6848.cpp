 	if (new.name && !new.commit) {
 		die("Cannot switch branch to a non-commit.");
 	}
+	if (opts.writeout_stage)
+		die("--ours/--theirs is incompatible with switching branches.");
 
 	return switch_branches(&opts, &new);
 }
