 			continue;
 		if (!pathspec_match(pattern, m, ce->name, 0))
 			continue;
-		path_list_insert(ce->name, list);
+		string_list_insert(ce->name, list);
 	}
 
 	return report_path_error(m, pattern, prefix ? strlen(prefix) : 0);
 }
 
-static void add_remove_files(struct path_list *list)
+static void add_remove_files(struct string_list *list)
 {
 	int i;
 	for (i = 0; i < list->nr; i++) {
 		struct stat st;
-		struct path_list_item *p = &(list->items[i]);
+		struct string_list_item *p = &(list->items[i]);
 
-		if (!lstat(p->path, &st)) {
-			if (add_to_cache(p->path, &st, 0))
+		if (!lstat(p->string, &st)) {
+			if (add_to_cache(p->string, &st, 0))
 				die("updating files failed");
 		} else
-			remove_file_from_cache(p->path);
+			remove_file_from_cache(p->string);
 	}
 }
 
