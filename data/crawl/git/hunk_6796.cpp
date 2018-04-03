 	/* .data is just a boolean: any non-NULL value will do */
 	rev_list.data = create_full_pack ? &rev_list : NULL;
 	if (start_async(&rev_list))
-		die("git-upload-pack: unable to fork git-rev-list");
+		die("git upload-pack: unable to fork git-rev-list");
 
 	argv[arg++] = "pack-objects";
 	argv[arg++] = "--stdout";
