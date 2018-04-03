 		die("unable to write new_index file");
 
 	fd = hold_lock_file_for_update(&false_lock,
-				       git_path("next-index-%d", getpid()), 1);
+				       git_path("next-index-%"PRIuMAX, (uintmax_t) getpid()), 1);
 
 	create_base_index();
 	add_remove_files(&partial);
