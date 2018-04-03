 	struct dir_struct dir;
 	struct lock_file *lock_file = xcalloc(1, sizeof(struct lock_file));
 
-	if (read_cache_unmerged())
-		die("you need to resolve your current index first");
 	refresh_cache(REFRESH_QUIET);
 
 	fd = hold_locked_index(lock_file, 1);
