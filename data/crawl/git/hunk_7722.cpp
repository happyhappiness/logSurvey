 	}
 
 	if (is_null_sha1(new_sha1)) {
+		if (!parse_object(old_sha1)) {
+			warning ("Allowing deletion of corrupt ref.");
+			old_sha1 = NULL;
+		}
 		if (delete_ref(name, old_sha1)) {
 			error("failed to delete %s", name);
 			return "failed to delete";
