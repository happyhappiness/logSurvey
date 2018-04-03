 	struct object_id oid;
 
 	if (unset) {
-		sha1_array_clear(opt->value);
+		oid_array_clear(opt->value);
 		return 0;
 	}
 	if (!arg)
 		return -1;
 	if (get_oid(arg, &oid))
 		return error(_("malformed object name '%s'"), arg);
-	sha1_array_append(opt->value, &oid);
+	oid_array_append(opt->value, &oid);
 	return 0;
 }
 
