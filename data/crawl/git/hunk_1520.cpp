 	    !opts->revs->cmdline.rev->flags) {
 		struct commit *cmit;
 		if (prepare_revision_walk(opts->revs))
-			die(_("revision walk setup failed"));
+			return error(_("revision walk setup failed"));
 		cmit = get_revision(opts->revs);
 		if (!cmit || get_revision(opts->revs))
-			die("BUG: expected exactly one commit from walk");
+			return error("BUG: expected exactly one commit from walk");
 		return single_pick(cmit, opts);
 	}
 