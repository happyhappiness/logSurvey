 		n = slash1 - p;
 	else
 		n = strlen(p);
+	if (!slash1 && !n) {
+		if (!S_ISDIR(mode))
+			die("Root cannot be a non-directory");
+		hashcpy(root->versions[1].sha1, sha1);
+		if (root->tree)
+			release_tree_content_recursive(root->tree);
+		root->tree = subtree;
+		return 1;
+	}
 	if (!n)
 		die("Empty path component found in input");
 	if (!slash1 && !S_ISDIR(mode) && subtree)
