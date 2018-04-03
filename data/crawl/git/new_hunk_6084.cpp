		} else {
			path = git_path("%s", refname);
		}
		err = unlink_or_warn(path);
		if (err && errno != ENOENT)
			ret = 1;

		if (!(delopt & REF_NODEREF))
			lock->lk->filename[i] = '.';
	}
