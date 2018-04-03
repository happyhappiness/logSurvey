 
 const char *setup_temporary_shallow(const struct oid_array *extra)
 {
-	static struct tempfile temp;
+	struct tempfile *temp;
 	struct strbuf sb = STRBUF_INIT;
-	int fd;
 
 	if (write_shallow_commits(&sb, 0, extra)) {
-		fd = xmks_tempfile(&temp, git_path("shallow_XXXXXX"));
+		temp = xmks_tempfile(git_path("shallow_XXXXXX"));
 
-		if (write_in_full(fd, sb.buf, sb.len) != sb.len ||
-		    close_tempfile_gently(&temp) < 0)
+		if (write_in_full(temp->fd, sb.buf, sb.len) != sb.len ||
+		    close_tempfile_gently(temp) < 0)
 			die_errno("failed to write to %s",
-				  get_tempfile_path(&temp));
+				  get_tempfile_path(temp));
 		strbuf_release(&sb);
-		return get_tempfile_path(&temp);
+		return get_tempfile_path(temp);
 	}
 	/*
 	 * is_repository_shallow() sees empty string as "no shallow
