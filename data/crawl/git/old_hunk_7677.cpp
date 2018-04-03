	rev.verbose_header = 1;
	rev.show_root_diff = 1;
	rev.commit_format = get_commit_format("format:%h: %s");
	rev.always_show_header = 1;

	printf("Created %scommit ", initial_commit ? "initial " : "");

	log_tree_commit(&rev, commit);
	printf("\n");
}

int git_commit_config(const char *k, const char *v)