 		int eaten;
 		hash_sha1_file(buf, size, typename(type), obj_list[nr].oid.hash);
 		added_object(nr, type, buf, size);
-		obj = parse_object_buffer(obj_list[nr].oid.hash, type, size, buf, &eaten);
+		obj = parse_object_buffer(&obj_list[nr].oid, type, size, buf,
+					  &eaten);
 		if (!obj)
 			die("invalid %s", typename(type));
 		add_object_buffer(obj, buf, size);
