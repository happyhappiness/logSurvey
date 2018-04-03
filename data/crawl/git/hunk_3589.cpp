 
 static int repack_without_ref(const char *refname)
 {
-	int fd;
 	struct ref_dir *packed;
 	struct string_list refs_to_delete = STRING_LIST_INIT_DUP;
 	struct string_list_item *ref_to_delete;
 
 	if (!get_packed_ref(refname))
 		return 0; /* refname does not exist in packed refs */
 
-	fd = hold_lock_file_for_update(&packlock, git_path("packed-refs"), 0);
-	if (fd < 0) {
+	if (lock_packed_refs(0)) {
 		unable_to_lock_error(git_path("packed-refs"), errno);
 		return error("cannot delete '%s' from packed refs", refname);
 	}
-	clear_packed_ref_cache(&ref_cache);
 	packed = get_packed_refs(&ref_cache);
 
 	/* Remove refname from the cache: */
