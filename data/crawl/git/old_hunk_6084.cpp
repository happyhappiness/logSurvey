		} else {
			path = git_path("%s", refname);
		}
		err = unlink(path);
		if (err && errno != ENOENT) {
			ret = 1;
			error("unlink(%s) failed: %s",
			      path, strerror(errno));
		}
		if (!(delopt & REF_NODEREF))
			lock->lk->filename[i] = '.';
	}
