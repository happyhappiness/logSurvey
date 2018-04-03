 		struct diff_options *opt, void *data)
 {
 	int i;
+	int intent_to_add = *(int *)data;
 
 	for (i = 0; i < q->nr; i++) {
 		struct diff_filespec *one = q->queue[i]->one;
-		if (one->mode && !is_null_sha1(one->sha1)) {
-			struct cache_entry *ce;
-			ce = make_cache_entry(one->mode, one->sha1, one->path,
-				0, 0);
-			if (!ce)
-				die(_("make_cache_entry failed for path '%s'"),
-				    one->path);
-			add_cache_entry(ce, ADD_CACHE_OK_TO_ADD |
-				ADD_CACHE_OK_TO_REPLACE);
-		} else
+		int is_missing = !(one->mode && !is_null_sha1(one->sha1));
+		struct cache_entry *ce;
+
+		if (is_missing && !intent_to_add) {
 			remove_file_from_cache(one->path);
+			continue;
+		}
+
+		ce = make_cache_entry(one->mode, one->sha1, one->path,
+				      0, 0);
+		if (!ce)
+			die(_("make_cache_entry failed for path '%s'"),
+			    one->path);
+		if (is_missing) {
+			ce->ce_flags |= CE_INTENT_TO_ADD;
+			set_object_name_for_intent_to_add_entry(ce);
+		}
+		add_cache_entry(ce, ADD_CACHE_OK_TO_ADD | ADD_CACHE_OK_TO_REPLACE);
 	}
 }
 
 static int read_from_tree(const struct pathspec *pathspec,
-			  unsigned char *tree_sha1)
+			  unsigned char *tree_sha1,
+			  int intent_to_add)
 {
 	struct diff_options opt;
 
 	memset(&opt, 0, sizeof(opt));
 	copy_pathspec(&opt.pathspec, pathspec);
 	opt.output_format = DIFF_FORMAT_CALLBACK;
 	opt.format_callback = update_index_from_diff;
+	opt.format_callback_data = &intent_to_add;
 
 	if (do_diff_cache(tree_sha1, &opt))
 		return 1;
