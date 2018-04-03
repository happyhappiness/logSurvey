 	struct commit *c = lookup_commit_reference(sha1);
 	if (!c)
 		die(_("could not parse %s"), ref_name);
-	if (hashcmp(sha1, c->object.sha1)) {
+	if (hashcmp(sha1, get_object_hash(c->object))) {
 		warning(_("%s %s is not a commit!"),
 			ref_name, sha1_to_hex(sha1));
 	}
