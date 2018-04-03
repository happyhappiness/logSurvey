 	    ce_stage(active_cache[pos+2]) != 3)
 		return error("path '%s' does not have all 3 versions", path);
 
-	fill_mm(active_cache[pos]->sha1, &ancestor);
-	fill_mm(active_cache[pos+1]->sha1, &ours);
-	fill_mm(active_cache[pos+2]->sha1, &theirs);
+	read_mmblob(&ancestor, active_cache[pos]->sha1);
+	read_mmblob(&ours, active_cache[pos+1]->sha1);
+	read_mmblob(&theirs, active_cache[pos+2]->sha1);
 
 	status = ll_merge(&result_buf, path, &ancestor,
 			  &ours, "ours", &theirs, "theirs", 0);
