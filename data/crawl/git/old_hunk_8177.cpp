		break;
	}

	if (require_work_tree &&
			(!is_inside_work_tree() || is_inside_git_dir()))
		die("This operation must be run in a work tree");

	pathspec = get_pathspec(prefix, argv + i);

