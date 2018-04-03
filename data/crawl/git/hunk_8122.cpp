 		fprintf(stderr, "* %s: fast forward to %s\n",
 			name, note);
 		fprintf(stderr, "  old..new: %s..%s\n", oldh, newh);
-		return update_ref("fast forward", name, sha1_new, sha1_old);
+		return update_ref_env("fast forward", name, sha1_new, sha1_old);
 	}
 	if (!force) {
 		fprintf(stderr,
