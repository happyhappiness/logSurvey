 	return 0;
 }
 
-static struct tempfile temporary_sharedindex;
-
 static int write_shared_index(struct index_state *istate,
 			      struct lock_file *lock, unsigned flags)
 {
+	struct tempfile *temp;
 	struct split_index *si = istate->split_index;
-	int fd, ret;
+	int ret;
 
-	fd = mks_tempfile(&temporary_sharedindex, git_path("sharedindex_XXXXXX"));
-	if (fd < 0) {
+	temp = mks_tempfile(git_path("sharedindex_XXXXXX"));
+	if (!temp) {
 		hashclr(si->base_sha1);
 		return do_write_locked_index(istate, lock, flags);
 	}
 	move_cache_to_base_index(istate);
-	ret = do_write_index(si->base, &temporary_sharedindex, 1);
+	ret = do_write_index(si->base, temp, 1);
 	if (ret) {
-		delete_tempfile(&temporary_sharedindex);
+		delete_tempfile(&temp);
 		return ret;
 	}
-	ret = adjust_shared_perm(get_tempfile_path(&temporary_sharedindex));
+	ret = adjust_shared_perm(get_tempfile_path(temp));
 	if (ret) {
 		int save_errno = errno;
-		error("cannot fix permission bits on %s", get_tempfile_path(&temporary_sharedindex));
-		delete_tempfile(&temporary_sharedindex);
+		error("cannot fix permission bits on %s", get_tempfile_path(temp));
+		delete_tempfile(&temp);
 		errno = save_errno;
 		return ret;
 	}
-	ret = rename_tempfile(&temporary_sharedindex,
+	ret = rename_tempfile(&temp,
 			      git_path("sharedindex.%s", sha1_to_hex(si->base->sha1)));
 	if (!ret) {
 		hashcpy(si->base_sha1, si->base->sha1);
