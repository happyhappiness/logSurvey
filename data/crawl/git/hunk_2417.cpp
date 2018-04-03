 	unsigned mode;
 	unsigned char sha1[20];
 
-	if (get_tree_entry(get_object_hash(commit->object), spec->path,
+	if (get_tree_entry(commit->object.oid.hash, spec->path,
 			   sha1, &mode))
 		die("There is no path %s in the commit", spec->path);
 	fill_filespec(spec, sha1, 1, mode);
