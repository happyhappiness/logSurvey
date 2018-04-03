 	} else {
 		struct object *obj;
 		int eaten;
-		hash_sha1_file(buf, size, typename(type), obj_list[nr].oid.hash);
+		hash_sha1_file(buf, size, type_name(type), obj_list[nr].oid.hash);
 		added_object(nr, type, buf, size);
 		obj = parse_object_buffer(&obj_list[nr].oid, type, size, buf,
 					  &eaten);
 		if (!obj)
-			die("invalid %s", typename(type));
+			die("invalid %s", type_name(type));
 		add_object_buffer(obj, buf, size);
 		obj->flags |= FLAG_OPEN;
 		obj_list[nr].obj = obj;
