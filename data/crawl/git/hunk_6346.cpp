 			gen_message_id(&rev, sha1_to_hex(commit->object.sha1));
 		}
 
-		get_patch_filename(numbered_files ? NULL : commit, rev.nr,
-				    fmt_patch_suffix, &patch_filename);
-		if (!use_stdout && reopen_stdout(patch_filename.buf, &rev))
+		if (!use_stdout && reopen_stdout(numbered_files ? NULL : commit,
+						 &rev))
 			die("Failed to create output files");
-		strbuf_setlen(&patch_filename, 0);
 		shown = log_tree_commit(&rev, commit);
 		free(commit->buffer);
 		commit->buffer = NULL;
