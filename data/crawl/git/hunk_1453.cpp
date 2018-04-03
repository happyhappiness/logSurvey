 	strbuf_addf(&sb, "%s: %.*s", reflog_msg, linelen(state->msg),
 			state->msg);
 
-	update_ref(sb.buf, "HEAD", commit, ptr, 0, UPDATE_REFS_DIE_ON_ERR);
+	update_ref_oid(sb.buf, "HEAD", &commit, old_oid, 0,
+			UPDATE_REFS_DIE_ON_ERR);
 
 	if (state->rebasing) {
 		FILE *fp = xfopen(am_path(state, "rewritten"), "a");
 
-		assert(!is_null_sha1(state->orig_commit));
-		fprintf(fp, "%s ", sha1_to_hex(state->orig_commit));
-		fprintf(fp, "%s\n", sha1_to_hex(commit));
+		assert(!is_null_oid(&state->orig_commit));
+		fprintf(fp, "%s ", oid_to_hex(&state->orig_commit));
+		fprintf(fp, "%s\n", oid_to_hex(&commit));
 		fclose(fp);
 	}
 
