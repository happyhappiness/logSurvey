 		      "but I can't find it!", sha1_to_hex(new_sha1));
 		return "bad pack";
 	}
+	if (deny_deletes && is_null_sha1(new_sha1) &&
+	    !is_null_sha1(old_sha1) &&
+	    !prefixcmp(name, "refs/heads/")) {
+		error("denying ref deletion for %s", name);
+		return "deletion prohibited";
+	}
 	if (deny_non_fast_forwards && !is_null_sha1(new_sha1) &&
 	    !is_null_sha1(old_sha1) &&
 	    !prefixcmp(name, "refs/heads/")) {
