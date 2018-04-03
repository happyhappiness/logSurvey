 		die("bad tree object");
 	if (obj->flags & (UNINTERESTING | SEEN))
 		return;
-	if (parse_tree(tree) < 0)
+	if (parse_tree(tree) < 0) {
+		if (revs->ignore_missing_links)
+			return;
 		die("bad tree object %s", sha1_to_hex(obj->sha1));
+	}
 	obj->flags |= SEEN;
 	show(obj, path, name, cb_data);
 	me.up = path;
