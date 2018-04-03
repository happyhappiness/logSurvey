
		return EXISTS_IN_WORKTREE;
	} else if ((errno != ENOENT) && (errno != ENOTDIR)) {
		return error_errno("%s", new_name);
	}
	return 0;
}
