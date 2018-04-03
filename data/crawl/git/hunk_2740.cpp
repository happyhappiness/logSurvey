 	}
 
 	diff_ranges_init(&diff);
-	collect_diff(&file_parent, &file_target, &diff);
+	if (collect_diff(&file_parent, &file_target, &diff))
+		die("unable to generate diff for %s", pair->one->path);
 
 	/* NEEDSWORK should apply some heuristics to prevent mismatches */
 	free(rg->path);
