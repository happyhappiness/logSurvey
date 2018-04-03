 	struct branch *current_branch = branch_get(NULL);
 	const char *pretty_ref = prettify_refname(ref->name);
 
-	type = sha1_object_info(ref->new_sha1, NULL);
+	type = sha1_object_info(ref->new_oid.hash, NULL);
 	if (type < 0)
-		die(_("object %s not found"), sha1_to_hex(ref->new_sha1));
+		die(_("object %s not found"), oid_to_hex(&ref->new_oid));
 
-	if (!hashcmp(ref->old_sha1, ref->new_sha1)) {
+	if (!oidcmp(&ref->old_oid, &ref->new_oid)) {
 		if (verbosity > 0)
 			strbuf_addf(display, "= %-*s %-*s -> %s",
 				    TRANSPORT_SUMMARY(_("[up to date]")),
