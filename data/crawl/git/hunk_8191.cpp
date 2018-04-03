 	store.key[i] = 0;
 
 	/*
-	 * The lock_file serves a purpose in addition to locking: the new
+	 * The lock serves a purpose in addition to locking: the new
 	 * contents of .git/config will be written into it.
 	 */
-	fd = open(lock_file, O_WRONLY | O_CREAT | O_EXCL, 0666);
-	if (fd < 0 || adjust_shared_perm(lock_file)) {
+	lock = xcalloc(sizeof(struct lock_file), 1);
+	fd = hold_lock_file_for_update(lock, config_filename, 0);
+	if (fd < 0) {
 		fprintf(stderr, "could not lock config file\n");
 		free(store.key);
 		ret = -1;
