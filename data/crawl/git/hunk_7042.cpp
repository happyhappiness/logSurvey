 
 	check_valid(tree_sha1, OBJ_TREE);
 	for (i = 2; i < argc; i += 2) {
+		unsigned char sha1[20];
 		const char *a, *b;
 		a = argv[i]; b = argv[i+1];
 		if (!b || strcmp(a, "-p"))
 			usage(commit_tree_usage);
 
-		if (parents >= MAXPARENT)
-			die("Too many parents (%d max)", MAXPARENT);
-		if (get_sha1(b, parent_sha1[parents]))
+		if (get_sha1(b, sha1))
 			die("Not a valid object name %s", b);
-		check_valid(parent_sha1[parents], OBJ_COMMIT);
-		if (new_parent(parents))
-			parents++;
+		check_valid(sha1, OBJ_COMMIT);
+		new_parent(lookup_commit(sha1), &parents);
 	}
 
 	/* Not having i18n.commitencoding is the same as having utf-8 */
