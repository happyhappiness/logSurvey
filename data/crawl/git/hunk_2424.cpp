 			oid_to_hex(&local->object.oid),
 			sha1_to_hex(base_sha1));
 
-	if (!hashcmp(get_object_hash(remote->object), base_sha1)) {
+	if (!hashcmp(remote->object.oid.hash, base_sha1)) {
 		/* Already merged; result == local commit */
 		if (o->verbosity >= 2)
 			printf("Already up-to-date!\n");
-		hashcpy(result_sha1, get_object_hash(local->object));
+		hashcpy(result_sha1, local->object.oid.hash);
 		goto found_result;
 	}
-	if (!hashcmp(get_object_hash(local->object), base_sha1)) {
+	if (!hashcmp(local->object.oid.hash, base_sha1)) {
 		/* Fast-forward; result == remote commit */
 		if (o->verbosity >= 2)
 			printf("Fast-forward\n");
-		hashcpy(result_sha1, get_object_hash(remote->object));
+		hashcpy(result_sha1, remote->object.oid.hash);
 		goto found_result;
 	}
 
-	result = merge_from_diffs(o, base_tree_sha1, get_object_hash(local->tree->object),
-				  get_object_hash(remote->tree->object), local_tree);
+	result = merge_from_diffs(o, base_tree_sha1, local->tree->object.oid.hash,
+				  remote->tree->object.oid.hash, local_tree);
 
 	if (result != 0) { /* non-trivial merge (with or without conflicts) */
 		/* Commit (partial) result */
