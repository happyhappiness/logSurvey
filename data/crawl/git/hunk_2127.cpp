 		const char *name = argv[i++];
 		if (get_sha1(name, sha1))
 			had_error = !!error("tag '%s' not found.", name);
-		else if (verify_tag(sha1, name, flags))
+		else if (gpg_verify_tag(sha1, name, flags))
 			had_error = 1;
 	}
 	return had_error;
