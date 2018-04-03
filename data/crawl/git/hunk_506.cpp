 	if (obj->type == OBJ_BLOB && !has_object_file(&obj->oid))
 		die("missing blob object '%s'", oid_to_hex(&obj->oid));
 	if (info->revs->verify_objects && !obj->parsed && obj->type != OBJ_COMMIT)
-		parse_object(obj->oid.hash);
+		parse_object(&obj->oid);
 }
 
 static void show_object(struct object *obj, const char *name, void *cb_data)
