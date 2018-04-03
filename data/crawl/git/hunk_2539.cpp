 	}
 	return error("Unable to determine requirements "
 		     "of type %s for %s",
-		     typename(obj->type), sha1_to_hex(obj->sha1));
+		     typename(obj->type), oid_to_hex(&obj->oid));
 }
 
 static int process(struct walker *walker, struct object *obj)
