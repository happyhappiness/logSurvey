 static int parse_mail_rebase(struct am_state *state, const char *mail)
 {
 	struct commit *commit;
-	unsigned char commit_sha1[GIT_SHA1_RAWSZ];
+	struct object_id commit_oid;
 
-	if (get_mail_commit_sha1(commit_sha1, mail) < 0)
+	if (get_mail_commit_oid(&commit_oid, mail) < 0)
 		die(_("could not parse %s"), mail);
 
-	commit = lookup_commit_or_die(commit_sha1, mail);
+	commit = lookup_commit_or_die(commit_oid.hash, mail);
 
 	get_commit_info(state, commit);
 
 	write_commit_patch(state, commit);
 
-	hashcpy(state->orig_commit, commit_sha1);
-	write_state_text(state, "original-commit", sha1_to_hex(commit_sha1));
+	oidcpy(&state->orig_commit, &commit_oid);
+	write_state_text(state, "original-commit", oid_to_hex(&commit_oid));
 
 	return 0;
 }
