 	else {
 		if (!quiet)
 			error("object %s is a %s, not a %s",
-			      sha1_to_hex(obj->sha1),
+			      oid_to_hex(&obj->oid),
 			      typename(obj->type), typename(type));
 		return NULL;
 	}