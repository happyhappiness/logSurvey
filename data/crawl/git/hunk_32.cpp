 	if (!result->data)
 		bad_object(delta_obj->idx.offset, _("failed to apply delta"));
 	hash_sha1_file(result->data, result->size,
-		       typename(delta_obj->real_type),
+		       type_name(delta_obj->real_type),
 		       delta_obj->idx.oid.hash);
 	sha1_object(result->data, NULL, result->size, delta_obj->real_type,
 		    &delta_obj->idx.oid);
