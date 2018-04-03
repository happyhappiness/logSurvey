 			hashclr(sha1);
 		if (check_local_mod(sha1, index_only))
 			exit(1);
+	} else if (!index_only) {
+		if (check_submodules_use_gitfiles())
+			exit(1);
 	}
 
 	/*
 	 * First remove the names from the index: we won't commit
 	 * the index unless all of them succeed.
 	 */
 	for (i = 0; i < list.nr; i++) {
-		const char *path = list.name[i];
+		const char *path = list.entry[i].name;
 		if (!quiet)
 			printf("rm '%s'\n", path);
 
