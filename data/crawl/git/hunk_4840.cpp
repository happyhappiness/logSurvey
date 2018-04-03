 	/* Sanity check options */
 	if (amend && initial_commit)
 		die("You have nothing to amend.");
-	if (amend && in_merge)
-		die("You are in the middle of a merge -- cannot amend.");
+	if (amend && whence != FROM_COMMIT)
+		die("You are in the middle of a %s -- cannot amend.", whence_s());
 	if (fixup_message && squash_message)
 		die("Options --squash and --fixup cannot be used together");
 	if (use_message)
