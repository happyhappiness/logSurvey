 
 	case 's':
 		oi.sizep = &size;
-		if (sha1_object_info_extended(sha1, &oi, flags) < 0)
+		if (sha1_object_info_extended(oid.hash, &oi, flags) < 0)
 			die("git cat-file: could not get object info");
 		printf("%lu\n", size);
 		return 0;
 
 	case 'e':
-		return !has_sha1_file(sha1);
+		return !has_object_file(&oid);
 
 	case 'c':
 		if (!obj_context.path[0])
 			die("git cat-file --textconv %s: <object> must be <sha1:path>",
 			    obj_name);
 
-		if (textconv_object(obj_context.path, obj_context.mode, sha1, 1, &buf, &size))
+		if (textconv_object(obj_context.path, obj_context.mode, oid.hash, 1, &buf, &size))
 			break;
 
 	case 'p':
-		type = sha1_object_info(sha1, NULL);
+		type = sha1_object_info(oid.hash, NULL);
 		if (type < 0)
 			die("Not a valid object name %s", obj_name);
 
