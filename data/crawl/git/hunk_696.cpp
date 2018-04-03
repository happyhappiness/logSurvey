 	const struct object_id *tagged_oid = NULL;
 	struct object *obj;
 
-	if (sha1_array_lookup(points_at, oid->hash) >= 0)
+	if (sha1_array_lookup(points_at, oid) >= 0)
 		return oid;
 	obj = parse_object(oid->hash);
 	if (!obj)
 		die(_("malformed object at '%s'"), refname);
 	if (obj->type == OBJ_TAG)
 		tagged_oid = &((struct tag *)obj)->tagged->oid;
-	if (tagged_oid && sha1_array_lookup(points_at, tagged_oid->hash) >= 0)
+	if (tagged_oid && sha1_array_lookup(points_at, tagged_oid) >= 0)
 		return tagged_oid;
 	return NULL;
 }
