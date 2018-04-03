 	struct ref_lock *lock;
 	struct stat loginfo;
 	int log = !lstat(git_path("logs/%s", oldref), &loginfo);
+	const char *symref = NULL;
+	int is_symref = 0;
 
 	if (S_ISLNK(loginfo.st_mode))
 		return error("reflog for %s is a symlink", oldref);
 
-	if (!resolve_ref(oldref, orig_sha1, 1, &flag))
+	symref = resolve_ref(oldref, orig_sha1, 1, &flag);
+	if (flag & REF_ISSYMREF)
+		is_symref = 1;
+	if (!symref)
 		return error("refname %s not found", oldref);
 
 	if (!is_refname_available(newref, oldref, get_packed_refs(), 0))
