 
 	if (unmerged_cache()) {
 		int i;
-		output(o, 0, "There are unmerged index entries:");
+		fprintf(stderr, "BUG: There are unmerged index entries:\n");
 		for (i = 0; i < active_nr; i++) {
 			struct cache_entry *ce = active_cache[i];
 			if (ce_stage(ce))
-				output(o, 0, "%d %.*s", ce_stage(ce),
-				       (int)ce_namelen(ce), ce->name);
+				fprintf(stderr, "BUG: %d %.*s", ce_stage(ce),
+					(int)ce_namelen(ce), ce->name);
 		}
-		return NULL;
+		die("Bug in merge-recursive.c");
 	}
 
 	if (!active_cache_tree)