 
 	if (!(obj->flags & FLAG_CHECKED)) {
 		unsigned long size;
-		int type = sha1_object_info(get_object_hash(*obj), &size);
+		int type = sha1_object_info(obj->oid.hash, &size);
 		if (type <= 0)
 			die(_("did not receive expected object %s"),
 			      oid_to_hex(&obj->oid));
