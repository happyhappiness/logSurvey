	}
	git_work_tree_initialized = 1;
	work_tree = xstrdup(real_path(new_work_tree));
}

const char *get_git_work_tree(void)
