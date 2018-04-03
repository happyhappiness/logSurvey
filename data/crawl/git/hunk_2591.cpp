 	if (!obj)
 		die(_("malformed object at '%s'"), refname);
 	if (obj->type == OBJ_TAG)
-		tagged_sha1 = ((struct tag *)obj)->tagged->sha1;
+		tagged_sha1 = get_object_hash(*((struct tag *)obj)->tagged);
 	if (tagged_sha1 && sha1_array_lookup(points_at, tagged_sha1) >= 0)
 		return tagged_sha1;
 	return NULL;
