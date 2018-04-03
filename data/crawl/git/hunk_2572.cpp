 
 	if (!(obj->flags & FLAG_OPEN)) {
 		unsigned long size;
-		int type = sha1_object_info(obj->sha1, &size);
+		int type = sha1_object_info(get_object_hash(*obj), &size);
 		if (type != obj->type || type <= 0)
 			die("object of unexpected type");
 		obj->flags |= FLAG_WRITTEN;
