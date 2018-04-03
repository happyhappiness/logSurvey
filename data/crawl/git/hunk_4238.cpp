 
 	assert_sha1_type(tree, OBJ_TREE);
 
+	if (memchr(msg->buf, '\0', msg->len))
+		return error("a NUL byte in commit log message not allowed.");
+
 	/* Not having i18n.commitencoding is the same as having utf-8 */
 	encoding_is_utf8 = is_encoding_utf8(git_commit_encoding);
 
