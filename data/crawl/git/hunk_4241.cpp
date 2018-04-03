 
 	track = git_branch_track;
 
-	head = resolve_ref("HEAD", head_sha1, 0, NULL);
+	head = resolve_refdup("HEAD", head_sha1, 0, NULL);
 	if (!head)
 		die(_("Failed to resolve HEAD as a valid ref."));
-	head = xstrdup(head);
 	if (!strcmp(head, "HEAD")) {
 		detached = 1;
 	} else {
