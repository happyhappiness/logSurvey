	}
	git_work_tree_initialized = 1;
	work_tree = xstrdup(real_path(new_work_tree));
	if (setenv(GIT_WORK_TREE_ENVIRONMENT, work_tree, 1))
		die("could not set GIT_WORK_TREE to '%s'", work_tree);
}

const char *get_git_work_tree(void)
