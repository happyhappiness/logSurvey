 	if (obj->flags & (UNINTERESTING | SEEN))
 		return p;
 	if (parse_tree(tree) < 0)
-		die("bad tree object %s", sha1_to_hex(obj->sha1));
+		die("bad tree object %s", oid_to_hex(&obj->oid));
 
 	obj->flags |= SEEN;
 	name = xstrdup(name);
