 	return commit_lock_file(&packlock);
 }
 
-int delete_ref(const char *refname, const unsigned char *sha1)
+int delete_ref(const char *refname, const unsigned char *sha1, int delopt)
 {
 	struct ref_lock *lock;
-	int err, i, ret = 0, flag = 0;
+	int err, i = 0, ret = 0, flag = 0;
 
 	lock = lock_ref_sha1_basic(refname, sha1, 0, &flag);
 	if (!lock)
 		return 1;
 	if (!(flag & REF_ISPACKED)) {
 		/* loose */
-		i = strlen(lock->lk->filename) - 5; /* .lock */
-		lock->lk->filename[i] = 0;
-		err = unlink(lock->lk->filename);
+		const char *path;
+
+		if (!(delopt & REF_NODEREF)) {
+			i = strlen(lock->lk->filename) - 5; /* .lock */
+			lock->lk->filename[i] = 0;
+			path = lock->lk->filename;
+		} else {
+			path = git_path(refname);
+		}
+		err = unlink(path);
 		if (err && errno != ENOENT) {
 			ret = 1;
 			error("unlink(%s) failed: %s",
-			      lock->lk->filename, strerror(errno));
+			      path, strerror(errno));
 		}
-		lock->lk->filename[i] = '.';
+		if (!(delopt & REF_NODEREF))
+			lock->lk->filename[i] = '.';
 	}
 	/* removing the loose one could have resurrected an earlier
 	 * packed one.  Also, if it was not loose we need to repack
