 	return r;
 }
 
+static int show_octopus_merge_bases(int count, const char **args, int show_all)
+{
+	struct commit_list *revs = NULL;
+	struct commit_list *result;
+	int i;
+
+	for (i = count - 1; i >= 0; i++)
+		commit_list_insert(get_commit_reference(args[i]), &revs);
+	result = get_octopus_merge_bases(revs);
+
+	if (!result)
+		return 1;
+
+	while (result) {
+		printf("%s\n", sha1_to_hex(result->item->object.sha1));
+		if (!show_all)
+			return 0;
+		result = result->next;
+	}
+
+	return 0;
+}
+
 int cmd_merge_base(int argc, const char **argv, const char *prefix)
 {
 	struct commit **rev;
 	int rev_nr = 0;
 	int show_all = 0;
+	int octopus = 0;
 
 	struct option options[] = {
-		OPT_BOOLEAN('a', "all", &show_all, "outputs all common ancestors"),
+		OPT_BOOLEAN('a', "all", &show_all, "output all common ancestors"),
+		OPT_BOOLEAN(0, "octopus", &octopus, "find ancestors for a single n-way merge"),
 		OPT_END()
 	};
 
 	git_config(git_default_config, NULL);
 	argc = parse_options(argc, argv, prefix, options, merge_base_usage, 0);
-	if (argc < 2)
+	if (!octopus && argc < 2)
 		usage_with_options(merge_base_usage, options);
+
+	if (octopus)
+		return show_octopus_merge_bases(argc, argv, show_all);
+
 	rev = xmalloc(argc * sizeof(*rev));
 	while (argc-- > 0)
 		rev[rev_nr++] = get_commit_reference(*argv++);
