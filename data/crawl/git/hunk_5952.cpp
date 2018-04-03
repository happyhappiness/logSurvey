 	const char *argv[10];
 	int arg = 0;
 
-	rev_list.proc = do_rev_list;
-	/* .data is just a boolean: any non-NULL value will do */
-	rev_list.data = create_full_pack ? &rev_list : NULL;
-	if (start_async(&rev_list))
-		die("git upload-pack: unable to fork git-rev-list");
+	if (shallow_nr) {
+		rev_list.proc = do_rev_list;
+		rev_list.data = 0;
+		if (start_async(&rev_list))
+			die("git upload-pack: unable to fork git-rev-list");
+		argv[arg++] = "pack-objects";
+	} else {
+		argv[arg++] = "pack-objects";
+		argv[arg++] = "--revs";
+		if (create_full_pack)
+			argv[arg++] = "--all";
+		else if (use_thin_pack)
+			argv[arg++] = "--thin";
+	}
 
-	argv[arg++] = "pack-objects";
 	argv[arg++] = "--stdout";
 	if (!no_progress)
 		argv[arg++] = "--progress";
