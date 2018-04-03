 	    strlen(patch->new_sha1_prefix) != 40 ||
 	    get_oid_hex(patch->old_sha1_prefix, &oid) ||
 	    get_oid_hex(patch->new_sha1_prefix, &oid))
-		return error("cannot apply binary patch to '%s' "
-			     "without full index line", name);
+		return error(_("cannot apply binary patch to '%s' "
+			       "without full index line"), name);
 
 	if (patch->old_name) {
 		/*
