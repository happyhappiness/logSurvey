 		int hit, len;
 
 		grep_read_lock();
-		data = read_object_with_reference(obj->sha1, tree_type,
+		data = read_object_with_reference(obj->oid.hash, tree_type,
 						  &size, NULL);
 		grep_read_unlock();
 
 		if (!data)
-			die(_("unable to read tree (%s)"), sha1_to_hex(obj->sha1));
+			die(_("unable to read tree (%s)"), oid_to_hex(&obj->oid));
 
 		len = name ? strlen(name) : 0;
 		strbuf_init(&base, PATH_MAX + len + 1);
