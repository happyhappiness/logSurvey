 	return run_command_v_opt(argv_show_branch, RUN_GIT_CMD);
 }
 
-static struct commit *get_commit_reference(const unsigned char *sha1)
+static struct commit *get_commit_reference(const struct object_id *oid)
 {
-	struct commit *r = lookup_commit_reference(sha1);
+	struct commit *r = lookup_commit_reference(oid->hash);
 	if (!r)
-		die(_("Not a valid commit name %s"), sha1_to_hex(sha1));
+		die(_("Not a valid commit name %s"), oid_to_hex(oid));
 	return r;
 }
 
