 	if (!two)
 		die("not a tree-ish %s", av[2]);
 
-	shift_tree(get_object_hash(one->object), get_object_hash(two->object), shifted, -1);
+	shift_tree(one->object.oid.hash, two->object.oid.hash, shifted, -1);
 	printf("shifted: %s\n", sha1_to_hex(shifted));
 
 	exit(0);
