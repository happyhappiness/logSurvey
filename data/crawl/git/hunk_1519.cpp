 		if (!get_sha1(name, sha1)) {
 			if (!lookup_commit_reference_gently(sha1, 1)) {
 				enum object_type type = sha1_object_info(sha1, NULL);
-				die(_("%s: can't cherry-pick a %s"), name, typename(type));
+				return error(_("%s: can't cherry-pick a %s"),
+					name, typename(type));
 			}
 		} else
-			die(_("%s: bad revision"), name);
+			return error(_("%s: bad revision"), name);
 	}
 
 	/*
