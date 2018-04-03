	return NULL;
}

void setup_work_tree(void) {
	const char *work_tree = get_git_work_tree();
	const char *git_dir = get_git_dir();
	if (!is_absolute_path(git_dir))
		set_git_dir(make_absolute_path(git_dir));
	if (!work_tree || chdir(work_tree))
		die("This operation must be run in a work tree");
}

/*
 * We cannot decide in this function whether we are in the work tree or
 * not, since the config can only be read _after_ this function was called.