 	return result;
 }
 
-static void show_list(const char *title, struct string_list *list,
-		      const char *extra_arg)
+void clear_push_info(void *util, const char *string)
 {
-	int i;
+	struct push_info *info = util;
+	free(info->dest);
+	free(info);
+}
 
-	if (!list->nr)
-		return;
+static void free_remote_ref_states(struct ref_states *states)
+{
+	string_list_clear(&states->new, 0);
+	string_list_clear(&states->stale, 0);
+	string_list_clear(&states->tracked, 0);
+	string_list_clear(&states->heads, 0);
+	string_list_clear_func(&states->push, clear_push_info);
+}
 
-	printf(title, list->nr > 1 ? "es" : "", extra_arg);
-	printf("\n");
-	for (i = 0; i < list->nr; i++)
-		printf("    %s\n", list->items[i].string);
+static int append_ref_to_tracked_list(const char *refname,
+	const unsigned char *sha1, int flags, void *cb_data)
+{
+	struct ref_states *states = cb_data;
+	struct refspec refspec;
+
+	if (flags & REF_ISSYMREF)
+		return 0;
+
+	memset(&refspec, 0, sizeof(refspec));
+	refspec.dst = (char *)refname;
+	if (!remote_find_tracking(states->remote, &refspec))
+		string_list_append(abbrev_branch(refspec.src), &states->tracked);
+
+	return 0;
 }
 
 static int get_remote_ref_states(const char *name,
 				 struct ref_states *states,
 				 int query)
 {
 	struct transport *transport;
-	const struct ref *ref;
+	const struct ref *remote_refs;
 
 	states->remote = remote_get(name);
 	if (!states->remote)
