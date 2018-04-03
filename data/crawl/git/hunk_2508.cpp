 	if (parse_tree_gently(tree, revs->ignore_missing_links) < 0) {
 		if (revs->ignore_missing_links)
 			return;
-		die("bad tree object %s", sha1_to_hex(obj->sha1));
+		die("bad tree object %s", oid_to_hex(&obj->oid));
 	}
 	obj->flags |= SEEN;
 	show(obj, path, name, cb_data);
