 		const char **pathspec = get_pathspec(prefix, argv);
 
 		if (!pathspec)
-			die("invalid path specification");
+			die(_("invalid path specification"));
 
 		if (patch_mode)
 			return interactive_checkout(new.name, pathspec, &opts);
 
 		/* Checkout paths */
 		if (opts.new_branch) {
 			if (argc == 1) {
-				die("git checkout: updating paths is incompatible with switching branches.\nDid you intend to checkout '%s' which can not be resolved as commit?", argv[0]);
+				die(_("git checkout: updating paths is incompatible with switching branches.\nDid you intend to checkout '%s' which can not be resolved as commit?"), argv[0]);
 			} else {
-				die("git checkout: updating paths is incompatible with switching branches.");
+				die(_("git checkout: updating paths is incompatible with switching branches."));
 			}
 		}
 
 		if (1 < !!opts.writeout_stage + !!opts.force + !!opts.merge)
-			die("git checkout: --ours/--theirs, --force and --merge are incompatible when\nchecking out of the index.");
+			die(_("git checkout: --ours/--theirs, --force and --merge are incompatible when\nchecking out of the index."));
 
 		return checkout_paths(source_tree, pathspec, &opts);
 	}
