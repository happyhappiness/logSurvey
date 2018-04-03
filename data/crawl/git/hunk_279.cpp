 int reopen_tempfile(struct tempfile *tempfile)
 {
 	if (!is_tempfile_active(tempfile))
-		die("BUG: reopen_tempfile called for an inactive object");
+		BUG("reopen_tempfile called for an inactive object");
 	if (0 <= tempfile->fd)
-		die("BUG: reopen_tempfile called for an open object");
+		BUG("reopen_tempfile called for an open object");
 	tempfile->fd = open(tempfile->filename.buf, O_WRONLY);
 	return tempfile->fd;
 }
 
 int rename_tempfile(struct tempfile *tempfile, const char *path)
 {
 	if (!is_tempfile_active(tempfile))
-		die("BUG: rename_tempfile called for inactive object");
+		BUG("rename_tempfile called for inactive object");
 
 	if (close_tempfile_gently(tempfile)) {
 		delete_tempfile(tempfile);