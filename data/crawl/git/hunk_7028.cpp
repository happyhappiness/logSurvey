 		die("diff_setup_done failed");
 
 	if (revs->grep_filter) {
-		revs->grep_filter->all_match = all_match;
 		compile_grep_patterns(revs->grep_filter);
 	}
 
