 	}
 	if (argc != 3)
 		usage(merge_base_usage);
-	if (get_sha1(argv[1], rev1key))
-		die("Not a valid object name %s", argv[1]);
-	if (get_sha1(argv[2], rev2key))
-		die("Not a valid object name %s", argv[2]);
-	rev1 = lookup_commit_reference(rev1key);
-	rev2 = lookup_commit_reference(rev2key);
-	if (!rev1 || !rev2)
-		return 1;
+	rev1 = get_commit_reference(argv[1]);
+	rev2 = get_commit_reference(argv[2]);
+
 	return show_merge_base(rev1, rev2, show_all);
 }