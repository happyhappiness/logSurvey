 
 	if (parse_commit(commit))
 		return error(_("Could not parse commit %s\n"),
-			     sha1_to_hex(commit->object.sha1));
+			     oid_to_hex(&commit->object.oid));
 	if (commit->parents) {
 		struct commit *parent = commit->parents->item;
 		if (parse_commit(parent))
 			return error(_("Could not parse parent commit %s\n"),
-				sha1_to_hex(parent->object.sha1));
+				oid_to_hex(&parent->object.oid));
 		ptree_sha1 = get_object_hash(parent->tree->object);
 	} else {
 		ptree_sha1 = EMPTY_TREE_SHA1_BIN; /* commit is root */
