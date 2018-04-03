 		if (!quiet)
 			error("object %s is a %s, not a %s",
 			      oid_to_hex(&obj->oid),
-			      typename(obj->type), typename(type));
+			      type_name(obj->type), type_name(type));
 		return NULL;
 	}
 }
