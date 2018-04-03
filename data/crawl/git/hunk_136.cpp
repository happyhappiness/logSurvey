 	if (*subpath)
 		subpath++;
 
-	buf = read_sha1_file(hash1, &type, &sz);
+	buf = read_sha1_file(oid1->hash, &type, &sz);
 	if (!buf)
-		die("cannot read tree %s", sha1_to_hex(hash1));
+		die("cannot read tree %s", oid_to_hex(oid1));
 	init_tree_desc(&desc, buf, sz);
 
 	rewrite_here = NULL;
