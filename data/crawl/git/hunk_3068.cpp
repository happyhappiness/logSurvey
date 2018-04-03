 		   real_path(get_git_common_dir()), name);
 	/*
 	 * This is to keep resolve_ref() happy. We need a valid HEAD
-	 * or is_git_directory() will reject the directory. Any valid
-	 * value would do because this value will be ignored and
-	 * replaced at the next (real) checkout.
+	 * or is_git_directory() will reject the directory. Moreover, HEAD
+	 * in the new worktree must resolve to the same value as HEAD in
+	 * the current tree since the command invoked to populate the new
+	 * worktree will be handed the branch/ref specified by the user.
+	 * For instance, if the user asks for the new worktree to be based
+	 * at HEAD~5, then the resolved HEAD~5 in the new worktree must
+	 * match the resolved HEAD~5 in the current tree in order to match
+	 * the user's expectation.
 	 */
+	if (!resolve_ref_unsafe("HEAD", 0, rev, NULL))
+		die(_("unable to resolve HEAD"));
 	strbuf_reset(&sb);
 	strbuf_addf(&sb, "%s/HEAD", sb_repo.buf);
-	write_file(sb.buf, 1, "%s\n", sha1_to_hex(new->commit->object.sha1));
+	write_file(sb.buf, 1, "%s\n", sha1_to_hex(rev));
 	strbuf_reset(&sb);
 	strbuf_addf(&sb, "%s/commondir", sb_repo.buf);
 	write_file(sb.buf, 1, "../..\n");
