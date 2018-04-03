 	const unsigned char *ptree_sha1;
 
 	if (parse_commit(commit))
-		return error(_("Could not parse commit %s\n"),
+		return error(_("could not parse commit %s\n"),
 			     oid_to_hex(&commit->object.oid));
 	if (commit->parents) {
 		struct commit *parent = commit->parents->item;
 		if (parse_commit(parent))
-			return error(_("Could not parse parent commit %s\n"),
+			return error(_("could not parse parent commit %s\n"),
 				oid_to_hex(&parent->object.oid));
 		ptree_sha1 = parent->tree->object.oid.hash;
 	} else {
