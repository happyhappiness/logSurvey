 	if (start_command(&pack_objects))
 		die("git upload-pack: unable to fork git-pack-objects");
 
-	/* pass on revisions we (don't) want */
-	if (!shallow_nr) {
+	if (shallow_nr) {
+		memset(&rev_list, 0, sizeof(rev_list));
+		rev_list.proc = do_rev_list;
+		rev_list.out = pack_objects.in;
+		if (start_async(&rev_list))
+			die("git upload-pack: unable to fork git-rev-list");
+	}
+	else {
 		FILE *pipe_fd = xfdopen(pack_objects.in, "w");
 		if (!create_full_pack) {
 			int i;