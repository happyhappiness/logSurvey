 	return 0;
 }
 
+struct status_cb {
+	const char *prefix;
+	unsigned int flags;
+};
+
+#define STATUS_CB_INIT { NULL, 0 }
+
+static void print_status(unsigned int flags, char state, const char *path,
+			 const struct object_id *oid, const char *displaypath)
+{
+	if (flags & OPT_QUIET)
+		return;
+
+	printf("%c%s %s", state, oid_to_hex(oid), displaypath);
+
+	if (state == ' ' || state == '+')
+		printf(" (%s)", compute_rev_name(path, oid_to_hex(oid)));
+
+	printf("\n");
+}
+
+static int handle_submodule_head_ref(const char *refname,
+				     const struct object_id *oid, int flags,
+				     void *cb_data)
+{
+	struct object_id *output = cb_data;
+	if (oid)
+		oidcpy(output, oid);
+
+	return 0;
+}
+
+static void status_submodule(const char *path, const struct object_id *ce_oid,
+			     unsigned int ce_flags, const char *prefix,
+			     unsigned int flags)
+{
+	char *displaypath;
+	struct argv_array diff_files_args = ARGV_ARRAY_INIT;
+	struct rev_info rev;
+	int diff_files_result;
+
+	if (!submodule_from_path(&null_oid, path))
+		die(_("no submodule mapping found in .gitmodules for path '%s'"),
+		      path);
+
+	displaypath = get_submodule_displaypath(path, prefix);
+
+	if ((CE_STAGEMASK & ce_flags) >> CE_STAGESHIFT) {
+		print_status(flags, 'U', path, &null_oid, displaypath);
+		goto cleanup;
+	}
+
+	if (!is_submodule_active(the_repository, path)) {
+		print_status(flags, '-', path, ce_oid, displaypath);
+		goto cleanup;
+	}
+
+	argv_array_pushl(&diff_files_args, "diff-files",
+			 "--ignore-submodules=dirty", "--quiet", "--",
+			 path, NULL);
+
+	git_config(git_diff_basic_config, NULL);
+	init_revisions(&rev, prefix);
+	rev.abbrev = 0;
+	diff_files_args.argc = setup_revisions(diff_files_args.argc,
+					       diff_files_args.argv,
+					       &rev, NULL);
+	diff_files_result = run_diff_files(&rev, 0);
+
+	if (!diff_result_code(&rev.diffopt, diff_files_result)) {
+		print_status(flags, ' ', path, ce_oid,
+			     displaypath);
+	} else if (!(flags & OPT_CACHED)) {
+		struct object_id oid;
+
+		if (refs_head_ref(get_submodule_ref_store(path),
+				  handle_submodule_head_ref, &oid))
+			die(_("could not resolve HEAD ref inside the"
+			      "submodule '%s'"), path);
+
+		print_status(flags, '+', path, &oid, displaypath);
+	} else {
+		print_status(flags, '+', path, ce_oid, displaypath);
+	}
+
+	if (flags & OPT_RECURSIVE) {
+		struct child_process cpr = CHILD_PROCESS_INIT;
+
+		cpr.git_cmd = 1;
+		cpr.dir = path;
+		prepare_submodule_repo_env(&cpr.env_array);
+
+		argv_array_push(&cpr.args, "--super-prefix");
+		argv_array_pushf(&cpr.args, "%s/", displaypath);
+		argv_array_pushl(&cpr.args, "submodule--helper", "status",
+				 "--recursive", NULL);
+
+		if (flags & OPT_CACHED)
+			argv_array_push(&cpr.args, "--cached");
+
+		if (flags & OPT_QUIET)
+			argv_array_push(&cpr.args, "--quiet");
+
+		if (run_command(&cpr))
+			die(_("failed to recurse into submodule '%s'"), path);
+	}
+
+cleanup:
+	argv_array_clear(&diff_files_args);
+	free(displaypath);
+}
+
+static void status_submodule_cb(const struct cache_entry *list_item,
+				void *cb_data)
+{
+	struct status_cb *info = cb_data;
+	status_submodule(list_item->name, &list_item->oid, list_item->ce_flags,
+			 info->prefix, info->flags);
+}
+
+static int module_status(int argc, const char **argv, const char *prefix)
+{
+	struct status_cb info = STATUS_CB_INIT;
+	struct pathspec pathspec;
+	struct module_list list = MODULE_LIST_INIT;
+	int quiet = 0;
+
+	struct option module_status_options[] = {
+		OPT__QUIET(&quiet, N_("Suppress submodule status output")),
+		OPT_BIT(0, "cached", &info.flags, N_("Use commit stored in the index instead of the one stored in the submodule HEAD"), OPT_CACHED),
+		OPT_BIT(0, "recursive", &info.flags, N_("recurse into nested submodules"), OPT_RECURSIVE),
+		OPT_END()
+	};
+
+	const char *const git_submodule_helper_usage[] = {
+		N_("git submodule status [--quiet] [--cached] [--recursive] [<path>...]"),
+		NULL
+	};
+
+	argc = parse_options(argc, argv, prefix, module_status_options,
+			     git_submodule_helper_usage, 0);
+
+	if (module_list_compute(argc, argv, prefix, &pathspec, &list) < 0)
+		return 1;
+
+	info.prefix = prefix;
+	if (quiet)
+		info.flags |= OPT_QUIET;
+
+	for_each_listed_submodule(&list, status_submodule_cb, &info);
+
+	return 0;
+}
+
 static int module_name(int argc, const char **argv, const char *prefix)
 {
 	const struct submodule *sub;
