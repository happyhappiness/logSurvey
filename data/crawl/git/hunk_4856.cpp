 	return hunk_no;
 }
 
-static int find_conflict(struct string_list *conflict)
+static int check_one_conflict(int i, int *type)
 {
-	int i;
-	if (read_cache() < 0)
-		return error("Could not read index");
-	for (i = 0; i+1 < active_nr; i++) {
+	struct cache_entry *e = active_cache[i];
+
+	if (!ce_stage(e)) {
+		*type = RESOLVED;
+		return i + 1;
+	}
+
+	*type = PUNTED;
+	if (ce_stage(e) == 1) {
+		if (active_nr <= ++i)
+			return i + 1;
+	}
+
+	/* Only handle regular files with both stages #2 and #3 */
+	if (i + 1 < active_nr) {
 		struct cache_entry *e2 = active_cache[i];
-		struct cache_entry *e3 = active_cache[i+1];
+		struct cache_entry *e3 = active_cache[i + 1];
 		if (ce_stage(e2) == 2 &&
 		    ce_stage(e3) == 3 &&
-		    ce_same_name(e2, e3) &&
+		    ce_same_name(e, e3) &&
 		    S_ISREG(e2->ce_mode) &&
-		    S_ISREG(e3->ce_mode)) {
-			string_list_insert(conflict, (const char *)e2->name);
-			i++; /* skip over both #2 and #3 */
+		    S_ISREG(e3->ce_mode))
+			*type = THREE_STAGED;
+	}
+
+	/* Skip the entries with the same name */
+	while (i < active_nr && ce_same_name(e, active_cache[i]))
+		i++;
+	return i;
+}
+
+static int find_conflict(struct string_list *conflict)
+{
+	int i;
+	if (read_cache() < 0)
+		return error("Could not read index");
+
+	for (i = 0; i < active_nr;) {
+		int conflict_type;
+		struct cache_entry *e = active_cache[i];
+		i = check_one_conflict(i, &conflict_type);
+		if (conflict_type == THREE_STAGED)
+			string_list_insert(conflict, (const char *)e->name);
+	}
+	return 0;
+}
+
+int rerere_remaining(struct string_list *merge_rr)
+{
+	int i;
+	if (read_cache() < 0)
+		return error("Could not read index");
+
+	for (i = 0; i < active_nr;) {
+		int conflict_type;
+		struct cache_entry *e = active_cache[i];
+		i = check_one_conflict(i, &conflict_type);
+		if (conflict_type == PUNTED)
+			string_list_insert(merge_rr, (const char *)e->name);
+		else if (conflict_type == RESOLVED) {
+			struct string_list_item *it;
+			it = string_list_lookup(merge_rr, (const char *)e->name);
+			if (it != NULL) {
+				free(it->util);
+				it->util = RERERE_RESOLVED;
+			}
 		}
 	}
 	return 0;
