 	return fd;
 }
 
-FILE *fdopen_lock_file(struct lock_file *lk, const char *mode)
-{
-	if (!lk->active)
-		die("BUG: fdopen_lock_file() called for unlocked object");
-	if (lk->fp)
-		die("BUG: fdopen_lock_file() called twice for file '%s'", lk->filename.buf);
-
-	lk->fp = fdopen(lk->fd, mode);
-	return lk->fp;
-}
-
-const char *get_lock_file_path(struct lock_file *lk)
-{
-	if (!lk->active)
-		die("BUG: get_lock_file_path() called for unlocked object");
-	return lk->filename.buf;
-}
-
-int get_lock_file_fd(struct lock_file *lk)
-{
-	if (!lk->active)
-		die("BUG: get_lock_file_fd() called for unlocked object");
-	return lk->fd;
-}
-
-FILE *get_lock_file_fp(struct lock_file *lk)
-{
-	if (!lk->active)
-		die("BUG: get_lock_file_fp() called for unlocked object");
-	return lk->fp;
-}
-
 char *get_locked_file_path(struct lock_file *lk)
 {
-	if (!lk->active)
-		die("BUG: get_locked_file_path() called for unlocked object");
-	if (lk->filename.len <= LOCK_SUFFIX_LEN ||
-	    strcmp(lk->filename.buf + lk->filename.len - LOCK_SUFFIX_LEN, LOCK_SUFFIX))
+	struct strbuf ret = STRBUF_INIT;
+
+	strbuf_addstr(&ret, get_tempfile_path(&lk->tempfile));
+	if (ret.len <= LOCK_SUFFIX_LEN ||
+	    strcmp(ret.buf + ret.len - LOCK_SUFFIX_LEN, LOCK_SUFFIX))
 		die("BUG: get_locked_file_path() called for malformed lock object");
 	/* remove ".lock": */
-	return xmemdupz(lk->filename.buf, lk->filename.len - LOCK_SUFFIX_LEN);
-}
-
-int close_lock_file(struct lock_file *lk)
-{
-	int fd = lk->fd;
-	FILE *fp = lk->fp;
-	int err;
-
-	if (fd < 0)
-		return 0;
-
-	lk->fd = -1;
-	if (fp) {
-		lk->fp = NULL;
-
-		/*
-		 * Note: no short-circuiting here; we want to fclose()
-		 * in any case!
-		 */
-		err = ferror(fp) | fclose(fp);
-	} else {
-		err = close(fd);
-	}
-
-	if (err) {
-		int save_errno = errno;
-		rollback_lock_file(lk);
-		errno = save_errno;
-		return -1;
-	}
-
-	return 0;
-}
-
-int reopen_lock_file(struct lock_file *lk)
-{
-	if (0 <= lk->fd)
-		die(_("BUG: reopen a lockfile that is still open"));
-	if (!lk->active)
-		die(_("BUG: reopen a lockfile that has been committed"));
-	lk->fd = open(lk->filename.buf, O_WRONLY);
-	return lk->fd;
-}
-
-int commit_lock_file_to(struct lock_file *lk, const char *path)
-{
-	if (!lk->active)
-		die("BUG: attempt to commit unlocked object to \"%s\"", path);
-
-	if (close_lock_file(lk))
-		return -1;
-
-	if (rename(lk->filename.buf, path)) {
-		int save_errno = errno;
-		rollback_lock_file(lk);
-		errno = save_errno;
-		return -1;
-	}
-
-	lk->active = 0;
-	strbuf_reset(&lk->filename);
-	return 0;
+	strbuf_setlen(&ret, ret.len - LOCK_SUFFIX_LEN);
+	return strbuf_detach(&ret, NULL);
 }
 
 int commit_lock_file(struct lock_file *lk)
