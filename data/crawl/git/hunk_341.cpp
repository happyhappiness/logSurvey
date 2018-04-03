 		if (!cached)
 			setup_work_tree();
 
-		hit = grep_cache(&opt, &pathspec, cached);
+		hit = grep_cache(&opt, the_repository, &pathspec, cached);
 	} else {
 		if (cached)
 			die(_("both --cached and trees are given."));
-		hit = grep_objects(&opt, &pathspec, &list);
+
+		hit = grep_objects(&opt, &pathspec, the_repository, &list);
 	}
 
 	if (num_threads)
