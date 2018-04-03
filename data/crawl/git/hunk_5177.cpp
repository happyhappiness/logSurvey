 	}
 
 	if (!use_index) {
-		int hit;
 		if (cached)
 			die("--cached cannot be used with --no-index.");
 		if (list.nr)
 			die("--no-index cannot be used with revs.");
 		hit = grep_directory(&opt, paths);
-		if (use_threads)
-			hit |= wait_all();
-		return !hit;
-	}
-
-	if (!list.nr) {
-		int hit;
+	} else if (!list.nr) {
 		if (!cached)
 			setup_work_tree();
 
 		hit = grep_cache(&opt, paths, cached);
-		if (use_threads)
-			hit |= wait_all();
-		return !hit;
+	} else {
+		if (cached)
+			die("both --cached and trees are given.");
+		hit = grep_objects(&opt, paths, &list);
 	}
 
-	if (cached)
-		die("both --cached and trees are given.");
-	hit = grep_objects(&opt, paths, &list);
-
 	if (use_threads)
 		hit |= wait_all();
 	free_grep_patterns(&opt);