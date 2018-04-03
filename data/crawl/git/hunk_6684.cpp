 
 	read_directory(&dir, ".", "", 0, NULL);
 	for(i = 0; i < dir.nr; i++) {
-		/* check for matching entry, which is unmerged; lifted from
-		 * builtin-ls-files:show_other_files */
 		struct dir_entry *ent = dir.entries[i];
-		int pos = cache_name_pos(ent->name, ent->len);
-		struct cache_entry *ce;
-		if (0 <= pos)
-			die("bug in wt_status_print_untracked");
-		pos = -pos - 1;
-		if (pos < active_nr) {
-			ce = active_cache[pos];
-			if (ce_namelen(ce) == ent->len &&
-			    !memcmp(ce->name, ent->name, ent->len))
-				continue;
-		}
+		if (!cache_name_is_other(ent->name, ent->len))
+			continue;
 		if (!shown_header) {
 			s->workdir_untracked = 1;
 			wt_status_print_header(s, "Untracked files",