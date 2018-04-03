		struct stat st;

		if (!exist_ok && !stat(git_dir, &st))
			die("%s already exists", git_dir);

		if (!exist_ok && !stat(real_git_dir, &st))
			die("%s already exists", real_git_dir);

		/*
		 * make sure symlinks are resolved because we'll be
