 	}
 
 	if (is_rebase_i(opts)) {
-		struct strbuf buf = STRBUF_INIT;
+		struct strbuf head_ref = STRBUF_INIT, buf = STRBUF_INIT;
 
 		/* Stopped in the middle, as planned? */
 		if (todo_list->current < todo_list->nr)
 			return 0;
 
+		if (read_oneliner(&head_ref, rebase_path_head_name(), 0) &&
+				starts_with(head_ref.buf, "refs/")) {
+			unsigned char head[20], orig[20];
+			int res;
+
+			if (get_sha1("HEAD", head)) {
+				res = error(_("cannot read HEAD"));
+cleanup_head_ref:
+				strbuf_release(&head_ref);
+				strbuf_release(&buf);
+				return res;
+			}
+			if (!read_oneliner(&buf, rebase_path_orig_head(), 0) ||
+					get_sha1_hex(buf.buf, orig)) {
+				res = error(_("could not read orig-head"));
+				goto cleanup_head_ref;
+			}
+			strbuf_addf(&buf, "rebase -i (finish): %s onto ",
+				head_ref.buf);
+			if (!read_oneliner(&buf, rebase_path_onto(), 0)) {
+				res = error(_("could not read 'onto'"));
+				goto cleanup_head_ref;
+			}
+			if (update_ref(buf.buf, head_ref.buf, head, orig,
+					REF_NODEREF, UPDATE_REFS_MSG_ON_ERR)) {
+				res = error(_("could not update %s"),
+					head_ref.buf);
+				goto cleanup_head_ref;
+			}
+			strbuf_reset(&buf);
+			strbuf_addf(&buf,
+				"rebase -i (finish): returning to %s",
+				head_ref.buf);
+			if (create_symref("HEAD", head_ref.buf, buf.buf)) {
+				res = error(_("could not update HEAD to %s"),
+					head_ref.buf);
+				goto cleanup_head_ref;
+			}
+			strbuf_reset(&buf);
+		}
+
 		if (opts->verbose) {
 			struct rev_info log_tree_opt;
 			struct object_id orig, head;
