 	string_list_clear(&new_refs, 0);
 }
 
+static void check_not_current_branch(struct ref *ref_map)
+{
+	struct branch *current_branch = branch_get(NULL);
+
+	if (is_bare_repository() || !current_branch)
+		return;
+
+	for (; ref_map; ref_map = ref_map->next)
+		if (ref_map->peer_ref && !strcmp(current_branch->refname,
+					ref_map->peer_ref->name))
+			die("Refusing to fetch into current branch");
+}
+
 static int do_fetch(struct transport *transport,
 		    struct refspec *refs, int ref_count)
 {
