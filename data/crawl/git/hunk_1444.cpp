 	for (i = 1; i < argc; i++) {
 		const char *arg = argv[i];
 		if (!strcmp(arg, "-p")) {
-			unsigned char sha1[20];
+			struct object_id oid;
 			if (argc <= ++i)
 				usage(commit_tree_usage);
-			if (get_sha1_commit(argv[i], sha1))
+			if (get_sha1_commit(argv[i], oid.hash))
 				die("Not a valid object name %s", argv[i]);
-			assert_sha1_type(sha1, OBJ_COMMIT);
-			new_parent(lookup_commit(sha1), &parents);
+			assert_sha1_type(oid.hash, OBJ_COMMIT);
+			new_parent(lookup_commit(oid.hash), &parents);
 			continue;
 		}
 
