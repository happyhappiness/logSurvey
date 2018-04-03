	printf("Created %scommit ", initial_commit ? "initial " : "");

	log_tree_commit(&rev, commit);
}

int git_commit_config(const char *k, const char *v)