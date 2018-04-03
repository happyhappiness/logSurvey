		cutoff_resolve = git_config_int(var, value);
	else if (!strcmp(var, "gc.rerereunresolved"))
		cutoff_noresolve = git_config_int(var, value);
	else
		return git_default_config(var, value);
	return 0;
}

int cmd_rerere(int argc, const char **argv, const char *prefix)
{
	struct path_list merge_rr = { NULL, 0, 0, 1 };
	int i, fd = -1;
	struct stat st;

	if (stat(git_path("rr-cache"), &st) || !S_ISDIR(st.st_mode))
		return 0;

	git_config(git_rerere_config);

	merge_rr_path = xstrdup(git_path("rr-cache/MERGE_RR"));
	fd = hold_lock_file_for_update(&write_lock, merge_rr_path, 1);
