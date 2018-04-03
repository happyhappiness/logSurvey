 {
 	struct child_process c;
 	int force = 0, detach = 0;
+	const char *new_branch = NULL, *new_branch_force = NULL;
 	const char *path, *branch;
 	struct argv_array cmd = ARGV_ARRAY_INIT;
 	struct option options[] = {
 		OPT__FORCE(&force, N_("checkout <branch> even if already checked out in other worktree")),
+		OPT_STRING('b', NULL, &new_branch, N_("branch"),
+			   N_("create a new branch")),
+		OPT_STRING('B', NULL, &new_branch_force, N_("branch"),
+			   N_("create or reset a branch")),
 		OPT_BOOL(0, "detach", &detach, N_("detach HEAD at named commit")),
 		OPT_END()
 	};
 
 	ac = parse_options(ac, av, prefix, options, worktree_usage, 0);
+	if (new_branch && new_branch_force)
+		die(_("-b and -B are mutually exclusive"));
 	if (ac != 2)
 		usage_with_options(worktree_usage, options);
 
