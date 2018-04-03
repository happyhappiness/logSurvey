		if (!one->sha1_valid) {
			struct stat st;
			if (one->is_stdin) {
				hashclr(one->sha1);
				return;
			}
			if (lstat(one->path, &st) < 0)
				die_errno("stat '%s'", one->path);
			if (index_path(one->sha1, one->path, &st, 0))
				die("cannot hash %s", one->path);
		}
	}
	else
		hashclr(one->sha1);
}

static void strip_prefix(int prefix_length, const char **namep, const char **otherp)
