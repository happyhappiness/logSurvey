 		return objerror(&commit->object, "could not load commit's tree %s", tree_sha1);
 	if (!commit->parents && show_root)
 		printf("root %s\n", sha1_to_hex(commit->object.sha1));
-	if (!commit->date)
-		printf("bad commit date in %s\n",
-		       sha1_to_hex(commit->object.sha1));
 	return 0;
 }
 