 	if (commit->util)
 		printf("virtual %s\n", merge_remote_util(commit)->name);
 	else {
-		printf("%s ", find_unique_abbrev(commit->object.sha1, DEFAULT_ABBREV));
+		printf("%s ", find_unique_abbrev(get_object_hash(commit->object), DEFAULT_ABBREV));
 		if (parse_commit(commit) != 0)
 			printf(_("(bad commit)\n"));
 		else {
