 	}
 }
 
-static int check_ignore(const char *prefix, const char **pathspec)
+static int check_ignore(struct path_exclude_check *check,
+			const char *prefix, const char **pathspec)
 {
-	struct dir_struct dir;
 	const char *path, *full_path;
 	char *seen;
 	int num_ignored = 0, dtype = DT_UNKNOWN, i;
-	struct path_exclude_check check;
 	struct exclude *exclude;
 
-	/* read_cache() is only necessary so we can watch out for submodules. */
-	if (read_cache() < 0)
-		die(_("index file corrupt"));
-
-	memset(&dir, 0, sizeof(dir));
-	dir.flags |= DIR_COLLECT_IGNORED;
-	setup_standard_excludes(&dir);
-
 	if (!pathspec || !*pathspec) {
 		if (!quiet)
 			fprintf(stderr, "no pathspec given.\n");
 		return 0;
 	}
 
-	path_exclude_check_init(&check, &dir);
 	/*
 	 * look for pathspecs matching entries in the index, since these
 	 * should not be ignored, in order to be consistent with
