	report("chmod %cx '%s'", flip, path);
	return;
 fail:
	die("git-update-index: cannot chmod %cx '%s'", flip, path);
}

static void update_one(const char *path, const char *prefix, int prefix_length)
