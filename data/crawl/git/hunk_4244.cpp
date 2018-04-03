 	else {
 		if (*branch == '\0') {
 			unsigned char sha1[20];
-			const char *head = resolve_ref("HEAD", sha1, 0, NULL);
-			if (!head)
-				die ("No current branch");
 			free(branch);
-			branch = xstrdup(head);
+			branch = resolve_refdup("HEAD", sha1, 0, NULL);
+			if (!branch)
+				die ("No current branch");
+
 		}
 		reflogs = read_complete_reflog(branch);
 		if (!reflogs || reflogs->nr == 0) {
