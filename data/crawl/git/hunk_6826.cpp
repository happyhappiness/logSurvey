 	return (struct commit *)object;
 }
 
-int merge_recursive_generic(const char **base_list,
-		const unsigned char *head_sha1, const char *head_name,
-		const unsigned char *next_sha1, const char *next_name)
+int merge_recursive_generic(struct merge_options *o,
+			    const unsigned char *head,
+			    const unsigned char *merge,
+			    int num_base_list,
+			    const unsigned char **base_list,
+			    struct commit **result)
 {
 	int clean, index_fd;
 	struct lock_file *lock = xcalloc(1, sizeof(struct lock_file));
-	struct commit *result;
-	struct commit *head_commit = get_ref(head_sha1, head_name);
-	struct commit *next_commit = get_ref(next_sha1, next_name);
+	struct commit *head_commit = get_ref(head, o->branch1);
+	struct commit *next_commit = get_ref(merge, o->branch2);
 	struct commit_list *ca = NULL;
 
 	if (base_list) {
 		int i;
-		for (i = 0; base_list[i]; ++i) {
-			unsigned char sha[20];
+		for (i = 0; i < num_base_list; ++i) {
 			struct commit *base;
-			if (get_sha1(base_list[i], sha))
-				return error("Could not resolve ref '%s'",
-								base_list[i]);
-			if (!(base = get_ref(sha, base_list[i])))
+			if (!(base = get_ref(base_list[i], sha1_to_hex(base_list[i]))))
 				return error("Could not parse object '%s'",
-								base_list[i]);
+					sha1_to_hex(base_list[i]));
 			commit_list_insert(base, &ca);
 		}
 	}
 
 	index_fd = hold_locked_index(lock, 1);
-	clean = merge_recursive(head_commit, next_commit,
-				head_name, next_name, ca, &result);
+	clean = merge_recursive(o, head_commit, next_commit, ca,
+			result);
 	if (active_cache_changed &&
 			(write_cache(index_fd, active_cache, active_nr) ||
 			 commit_locked_index(lock)))
