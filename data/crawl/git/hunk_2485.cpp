 			  void *cb_data)
 {
 	struct rev_list_info *info = cb_data;
-	if (obj->type == OBJ_BLOB && !has_sha1_file(obj->sha1))
-		die("missing blob object '%s'", sha1_to_hex(obj->sha1));
+	if (obj->type == OBJ_BLOB && !has_object_file(&obj->oid))
+		die("missing blob object '%s'", oid_to_hex(&obj->oid));
 	if (info->revs->verify_objects && !obj->parsed && obj->type != OBJ_COMMIT)
 		parse_object(get_object_hash(*obj));
 }
