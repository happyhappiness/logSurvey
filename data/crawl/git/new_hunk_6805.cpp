		if (retval && chdir(retval))
			die ("Could not jump back into original cwd");
		rel = get_relative_cwd(buffer, PATH_MAX, get_git_work_tree());
		if (rel && *rel && chdir(get_git_work_tree()))
			die ("Could not jump to working directory");
		return rel && *rel ? strcat(rel, "/") : NULL;
	}
