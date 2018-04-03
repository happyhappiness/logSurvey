 	if (p != NULL)
 		strbuf_setlen(&sb, p - sb.buf + 1);
 
-	stripspace(&sb, 1);
+	if (cleanup_mode != CLEANUP_NONE)
+		stripspace(&sb, cleanup_mode == CLEANUP_ALL);
 	if (sb.len < header_len || message_is_empty(&sb, header_len)) {
 		rollback_index_files();
 		die("no commit message?  aborting commit.");
