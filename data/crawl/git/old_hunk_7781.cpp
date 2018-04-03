        free(seen);
}

static int git_add_config(const char *var, const char *value)
{
	if (!strcmp(var, "core.excludesfile")) {
		if (!value)
			die("core.excludesfile without value");
		excludes_file = xstrdup(value);
		return 0;
	}

	return git_default_config(var, value);
}

static struct lock_file lock_file;

static const char ignore_error[] =
