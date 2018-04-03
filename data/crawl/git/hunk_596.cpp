 {
 	if (!S_ISDIR(mode))
 		die("Root cannot be a non-directory");
-	hashclr(root->versions[0].sha1);
-	hashcpy(root->versions[1].sha1, sha1);
+	oidclr(&root->versions[0].oid);
+	hashcpy(root->versions[1].oid.hash, sha1);
 	if (root->tree)
 		release_tree_content_recursive(root->tree);
 	root->tree = newtree;
