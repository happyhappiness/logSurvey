 		die("Could not parse object '%s'.", rev);
 	hashcpy(sha1, commit->object.sha1);
 
+	if (patch_mode) {
+		if (reset_type != NONE)
+			die("--patch is incompatible with --{hard,mixed,soft}");
+		return interactive_reset(rev, argv + i, prefix);
+	}
+
 	/* git reset tree [--] paths... can be used to
 	 * load chosen paths from the tree into the index without
 	 * affecting the working tree nor HEAD. */
