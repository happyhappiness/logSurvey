 			st.st_mtime = 0;
 	}
 
-	if (sought->nr) {
-		sort_string_list(sought);
-		string_list_remove_duplicates(sought, 0);
-	}
+	if (nr_sought)
+		nr_sought = remove_duplicates_in_refs(sought, nr_sought);
 
 	if (!ref) {
 		packet_flush(fd[1]);
 		die("no matching remote head");
 	}
-	ref_cpy = do_fetch_pack(args, fd, ref, sought, pack_lockfile);
+	ref_cpy = do_fetch_pack(args, fd, ref, sought, nr_sought, pack_lockfile);
 
 	if (args->depth > 0) {
 		static struct lock_file lock;
