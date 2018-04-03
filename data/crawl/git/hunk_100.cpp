 	p = short_commit_name(commit);
 	if (write_message(p, strlen(p), rebase_path_stopped_sha(), 1) < 0)
 		return -1;
+	if (update_ref("rebase", "REBASE_HEAD", &commit->object.oid,
+		       NULL, REF_NO_DEREF, UPDATE_REFS_MSG_ON_ERR))
+		res |= error(_("could not update %s"), "REBASE_HEAD");
 
 	strbuf_addf(&buf, "%s/patch", get_dir(opts));
 	memset(&log_tree_opt, 0, sizeof(log_tree_opt));
