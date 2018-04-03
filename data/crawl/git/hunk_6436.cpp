 	return 0;
 }
 
+struct show_info {
+	struct string_list *list;
+	struct ref_states *states;
+	int width;
+	int any_rebase;
+};
+
+int add_remote_to_show_info(struct string_list_item *item, void *cb_data)
+{
+	struct show_info *info = cb_data;
+	int n = strlen(item->string);
+	if (n > info->width)
+		info->width = n;
+	string_list_insert(item->string, info->list);
+	return 0;
+}
+
+int show_remote_info_item(struct string_list_item *item, void *cb_data)
+{
+	struct show_info *info = cb_data;
+	struct ref_states *states = info->states;
+	const char *name = item->string;
+
+	if (states->queried) {
+		const char *fmt = "%s";
+		const char *arg = "";
+		if (string_list_has_string(&states->new, name)) {
+			fmt = " new (next fetch will store in remotes/%s)";
+			arg = states->remote->name;
+		} else if (string_list_has_string(&states->tracked, name))
+			arg = " tracked";
+		else if (string_list_has_string(&states->stale, name))
+			arg = " stale (use 'git remote prune' to remove)";
+		else
+			arg = " ???";
+		printf("    %-*s", info->width, name);
+		printf(fmt, arg);
+		printf("\n");
+	} else
+		printf("    %s\n", name);
+
+	return 0;
+}
+
+int add_local_to_show_info(struct string_list_item *branch_item, void *cb_data)
+{
+	struct show_info *show_info = cb_data;
+	struct ref_states *states = show_info->states;
+	struct branch_info *branch_info = branch_item->util;
+	struct string_list_item *item;
+	int n;
+
+	if (!branch_info->merge.nr || !branch_info->remote_name ||
+	    strcmp(states->remote->name, branch_info->remote_name))
+		return 0;
+	if ((n = strlen(branch_item->string)) > show_info->width)
+		show_info->width = n;
+	if (branch_info->rebase)
+		show_info->any_rebase = 1;
+
+	item = string_list_insert(branch_item->string, show_info->list);
+	item->util = branch_info;
+
+	return 0;
+}
+
+int show_local_info_item(struct string_list_item *item, void *cb_data)
+{
+	struct show_info *show_info = cb_data;
+	struct branch_info *branch_info = item->util;
+	struct string_list *merge = &branch_info->merge;
+	const char *also;
+	int i;
+
+	if (branch_info->rebase && branch_info->merge.nr > 1) {
+		error("invalid branch.%s.merge; cannot rebase onto > 1 branch",
+			item->string);
+		return 0;
+	}
+
+	printf("    %-*s ", show_info->width, item->string);
+	if (branch_info->rebase) {
+		printf("rebases onto remote %s\n", merge->items[0].string);
+		return 0;
+	} else if (show_info->any_rebase) {
+		printf(" merges with remote %s\n", merge->items[0].string);
+		also = "    and with remote";
+	} else {
+		printf("merges with remote %s\n", merge->items[0].string);
+		also = "   and with remote";
+	}
+	for (i = 1; i < merge->nr; i++)
+		printf("    %-*s %s %s\n", show_info->width, "", also,
+		       merge->items[i].string);
+
+	return 0;
+}
+
 static int show(int argc, const char **argv)
 {
 	int no_query = 0, result = 0, query_flag = 0;
