 	return 0;
 }
 
-int create_symref(const char *refname, const char *target, const char *logmsg)
+static int create_ref_symlink(struct ref_lock *lock, const char *target)
 {
-	char *lockpath = NULL;
-	char buf[1000];
-	int fd, len, written;
-	char *ref_path = git_pathdup("%s", refname);
-	unsigned char old_sha1[20], new_sha1[20];
-	struct strbuf err = STRBUF_INIT;
-
-	if (logmsg && read_ref(refname, old_sha1))
-		hashclr(old_sha1);
-
-	if (safe_create_leading_directories(ref_path) < 0)
-		return error("unable to create directory for %s", ref_path);
-
+	int ret = -1;
 #ifndef NO_SYMLINK_HEAD
-	if (prefer_symlink_refs) {
-		unlink(ref_path);
-		if (!symlink(target, ref_path))
-			goto done;
+	char *ref_path = get_locked_file_path(lock->lk);
+	unlink(ref_path);
+	ret = symlink(target, ref_path);
+	free(ref_path);
+
+	if (ret)
 		fprintf(stderr, "no symlink - falling back to symbolic ref\n");
-	}
 #endif
+	return ret;
+}
 
-	len = snprintf(buf, sizeof(buf), "ref: %s\n", target);
-	if (sizeof(buf) <= len) {
-		error("refname too long: %s", target);
-		goto error_free_return;
-	}
-	lockpath = mkpathdup("%s.lock", ref_path);
-	fd = open(lockpath, O_CREAT | O_EXCL | O_WRONLY, 0666);
-	if (fd < 0) {
-		error("Unable to open %s for writing", lockpath);
-		goto error_free_return;
-	}
-	written = write_in_full(fd, buf, len);
-	if (close(fd) != 0 || written != len) {
-		error("Unable to write to %s", lockpath);
-		goto error_unlink_return;
-	}
-	if (rename(lockpath, ref_path) < 0) {
-		error("Unable to create %s", ref_path);
-		goto error_unlink_return;
-	}
-	if (adjust_shared_perm(ref_path)) {
-		error("Unable to fix permissions on %s", lockpath);
-	error_unlink_return:
-		unlink_or_warn(lockpath);
-	error_free_return:
-		free(lockpath);
-		free(ref_path);
-		return -1;
-	}
-	free(lockpath);
-
-#ifndef NO_SYMLINK_HEAD
-	done:
-#endif
+static void update_symref_reflog(struct ref_lock *lock, const char *refname,
+				 const char *target, const char *logmsg)
+{
+	struct strbuf err = STRBUF_INIT;
+	unsigned char new_sha1[20];
 	if (logmsg && !read_ref(target, new_sha1) &&
-		log_ref_write(refname, old_sha1, new_sha1, logmsg, 0, &err)) {
+	    log_ref_write(refname, lock->old_oid.hash, new_sha1, logmsg, 0, &err)) {
 		error("%s", err.buf);
 		strbuf_release(&err);
 	}
+}
 
-	free(ref_path);
+static int create_symref_locked(struct ref_lock *lock, const char *refname,
+				const char *target, const char *logmsg)
+{
+	if (prefer_symlink_refs && !create_ref_symlink(lock, target)) {
+		update_symref_reflog(lock, refname, target, logmsg);
+		return 0;
+	}
+
+	if (!fdopen_lock_file(lock->lk, "w"))
+		return error("unable to fdopen %s: %s",
+			     lock->lk->tempfile.filename.buf, strerror(errno));
+
+	/* no error check; commit_ref will check ferror */
+	fprintf(lock->lk->tempfile.fp, "ref: %s\n", target);
+	if (commit_ref(lock) < 0)
+		return error("unable to write symref for %s: %s", refname,
+			     strerror(errno));
+	update_symref_reflog(lock, refname, target, logmsg);
 	return 0;
 }
 
+int create_symref(const char *refname, const char *target, const char *logmsg)
+{
+	struct strbuf err = STRBUF_INIT;
+	struct ref_lock *lock;
+	int ret;
+
+	lock = lock_ref_sha1_basic(refname, NULL, NULL, NULL, REF_NODEREF, NULL,
+				   &err);
+	if (!lock) {
+		error("%s", err.buf);
+		strbuf_release(&err);
+		return -1;
+	}
+
+	ret = create_symref_locked(lock, refname, target, logmsg);
+	unlock_ref(lock);
+	return ret;
+}
+
 int reflog_exists(const char *refname)
 {
 	struct stat st;
