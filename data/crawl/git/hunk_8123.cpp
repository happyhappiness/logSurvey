 		"* %s: forcing update to non-fast forward %s\n",
 		name, note);
 	fprintf(stderr, "  old...new: %s...%s\n", oldh, newh);
-	return update_ref("forced-update", name, sha1_new, sha1_old);
+	return update_ref_env("forced-update", name, sha1_new, sha1_old);
 }
 
 static int append_fetch_head(FILE *fp,
