 
 	obj_buf = lookup_object_buffer(obj);
 	if (!obj_buf)
-		die("Whoops! Cannot find object '%s'", sha1_to_hex(obj->sha1));
+		die("Whoops! Cannot find object '%s'", oid_to_hex(&obj->oid));
 	if (fsck_object(obj, obj_buf->buffer, obj_buf->size, &fsck_options))
 		die("Error in object");
 	fsck_options.walk = check_object;
 	if (fsck_walk(obj, NULL, &fsck_options))
-		die("Error on reachable objects of %s", sha1_to_hex(obj->sha1));
+		die("Error on reachable objects of %s", oid_to_hex(&obj->oid));
 	write_cached_object(obj, obj_buf);
 	return 0;
 }
