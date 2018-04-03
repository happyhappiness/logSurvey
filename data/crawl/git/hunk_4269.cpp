  */
 #define TMP_RENAMED_LOG  "logs/refs/.tmp-renamed-log"
 
-int rename_ref(const char *oldref, const char *newref, const char *logmsg)
+int rename_ref(const char *oldrefname, const char *newrefname, const char *logmsg)
 {
 	unsigned char sha1[20], orig_sha1[20];
 	int flag = 0, logmoved = 0;
 	struct ref_lock *lock;
 	struct stat loginfo;
-	int log = !lstat(git_path("logs/%s", oldref), &loginfo);
+	int log = !lstat(git_path("logs/%s", oldrefname), &loginfo);
 	const char *symref = NULL;
 
 	if (log && S_ISLNK(loginfo.st_mode))
-		return error("reflog for %s is a symlink", oldref);
+		return error("reflog for %s is a symlink", oldrefname);
 
-	symref = resolve_ref(oldref, orig_sha1, 1, &flag);
+	symref = resolve_ref(oldrefname, orig_sha1, 1, &flag);
 	if (flag & REF_ISSYMREF)
 		return error("refname %s is a symbolic ref, renaming it is not supported",
-			oldref);
+			oldrefname);
 	if (!symref)
-		return error("refname %s not found", oldref);
+		return error("refname %s not found", oldrefname);
 
-	if (!is_refname_available(newref, oldref, get_packed_refs(NULL), 0))
+	if (!is_refname_available(newrefname, oldrefname, get_packed_refs(NULL), 0))
 		return 1;
 
-	if (!is_refname_available(newref, oldref, get_loose_refs(NULL), 0))
+	if (!is_refname_available(newrefname, oldrefname, get_loose_refs(NULL), 0))
 		return 1;
 
-	if (log && rename(git_path("logs/%s", oldref), git_path(TMP_RENAMED_LOG)))
+	if (log && rename(git_path("logs/%s", oldrefname), git_path(TMP_RENAMED_LOG)))
 		return error("unable to move logfile logs/%s to "TMP_RENAMED_LOG": %s",
-			oldref, strerror(errno));
+			oldrefname, strerror(errno));
 
-	if (delete_ref(oldref, orig_sha1, REF_NODEREF)) {
-		error("unable to delete old %s", oldref);
+	if (delete_ref(oldrefname, orig_sha1, REF_NODEREF)) {
+		error("unable to delete old %s", oldrefname);
 		goto rollback;
 	}
 
-	if (!read_ref_full(newref, sha1, 1, &flag) &&
-	    delete_ref(newref, sha1, REF_NODEREF)) {
+	if (!read_ref_full(newrefname, sha1, 1, &flag) &&
+	    delete_ref(newrefname, sha1, REF_NODEREF)) {
 		if (errno==EISDIR) {
-			if (remove_empty_directories(git_path("%s", newref))) {
-				error("Directory not empty: %s", newref);
+			if (remove_empty_directories(git_path("%s", newrefname))) {
+				error("Directory not empty: %s", newrefname);
 				goto rollback;
 			}
 		} else {
-			error("unable to delete existing %s", newref);
+			error("unable to delete existing %s", newrefname);
 			goto rollback;
 		}
 	}
 
-	if (log && safe_create_leading_directories(git_path("logs/%s", newref))) {
-		error("unable to create directory for %s", newref);
+	if (log && safe_create_leading_directories(git_path("logs/%s", newrefname))) {
+		error("unable to create directory for %s", newrefname);
 		goto rollback;
 	}
 
  retry:
-	if (log && rename(git_path(TMP_RENAMED_LOG), git_path("logs/%s", newref))) {
+	if (log && rename(git_path(TMP_RENAMED_LOG), git_path("logs/%s", newrefname))) {
 		if (errno==EISDIR || errno==ENOTDIR) {
 			/*
 			 * rename(a, b) when b is an existing
 			 * directory ought to result in ISDIR, but
 			 * Solaris 5.8 gives ENOTDIR.  Sheesh.
 			 */
-			if (remove_empty_directories(git_path("logs/%s", newref))) {
-				error("Directory not empty: logs/%s", newref);
+			if (remove_empty_directories(git_path("logs/%s", newrefname))) {
+				error("Directory not empty: logs/%s", newrefname);
 				goto rollback;
 			}
 			goto retry;
 		} else {
 			error("unable to move logfile "TMP_RENAMED_LOG" to logs/%s: %s",
-				newref, strerror(errno));
+				newrefname, strerror(errno));
 			goto rollback;
 		}
 	}
 	logmoved = log;
 
-	lock = lock_ref_sha1_basic(newref, NULL, 0, NULL);
+	lock = lock_ref_sha1_basic(newrefname, NULL, 0, NULL);
 	if (!lock) {
-		error("unable to lock %s for update", newref);
+		error("unable to lock %s for update", newrefname);
 		goto rollback;
 	}
 	lock->force_write = 1;
 	hashcpy(lock->old_sha1, orig_sha1);
 	if (write_ref_sha1(lock, orig_sha1, logmsg)) {
-		error("unable to write current sha1 into %s", newref);
+		error("unable to write current sha1 into %s", newrefname);
 		goto rollback;
 	}
 
 	return 0;
 
  rollback:
-	lock = lock_ref_sha1_basic(oldref, NULL, 0, NULL);
+	lock = lock_ref_sha1_basic(oldrefname, NULL, 0, NULL);
 	if (!lock) {
-		error("unable to lock %s for rollback", oldref);
+		error("unable to lock %s for rollback", oldrefname);
 		goto rollbacklog;
 	}
 
 	lock->force_write = 1;
 	flag = log_all_ref_updates;
 	log_all_ref_updates = 0;
 	if (write_ref_sha1(lock, orig_sha1, NULL))
-		error("unable to write current sha1 into %s", oldref);
+		error("unable to write current sha1 into %s", oldrefname);
 	log_all_ref_updates = flag;
 
  rollbacklog:
-	if (logmoved && rename(git_path("logs/%s", newref), git_path("logs/%s", oldref)))
+	if (logmoved && rename(git_path("logs/%s", newrefname), git_path("logs/%s", oldrefname)))
 		error("unable to restore logfile %s from %s: %s",
-			oldref, newref, strerror(errno));
+			oldrefname, newrefname, strerror(errno));
 	if (!logmoved && log &&
-	    rename(git_path(TMP_RENAMED_LOG), git_path("logs/%s", oldref)))
+	    rename(git_path(TMP_RENAMED_LOG), git_path("logs/%s", oldrefname)))
 		error("unable to restore logfile %s from "TMP_RENAMED_LOG": %s",
-			oldref, strerror(errno));
+			oldrefname, strerror(errno));
 
 	return 1;
 }
