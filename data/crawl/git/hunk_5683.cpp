 			verify_filename(prefix, argv[j]);
 	}
 
-	if (i < argc) {
+	if (i < argc)
 		paths = get_pathspec(prefix, argv + i);
-		if (opt.prefix_length && opt.relative) {
-			/* Make sure we do not get outside of paths */
-			for (i = 0; paths[i]; i++)
-				if (strncmp(prefix, paths[i], opt.prefix_length))
-					die("git grep: cannot generate relative filenames containing '..'");
-		}
-	}
 	else if (prefix) {
 		paths = xcalloc(2, sizeof(const char *));
 		paths[0] = prefix;
