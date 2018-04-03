	return dirty_submodule;
}

int submodule_uses_gitfile(const char *path)
{
	struct child_process cp;
	const char *argv[] = {
		"submodule",
		"foreach",
		"--quiet",
		"--recursive",
		"test -f .git",
		NULL,
	};
	struct strbuf buf = STRBUF_INIT;
	const char *git_dir;

	strbuf_addf(&buf, "%s/.git", path);
	git_dir = read_gitfile(buf.buf);
	if (!git_dir) {
		strbuf_release(&buf);
		return 0;
	}
	strbuf_release(&buf);

	/* Now test that all nested submodules use a gitfile too */
	memset(&cp, 0, sizeof(cp));
	cp.argv = argv;
	cp.env = local_repo_env;
	cp.git_cmd = 1;
	cp.no_stdin = 1;
	cp.no_stderr = 1;
	cp.no_stdout = 1;
	cp.dir = path;
	if (run_command(&cp))
		return 0;

	return 1;
}

int ok_to_remove_submodule(const char *path)
{
	struct stat st;
	ssize_t len;
	struct child_process cp;
	const char *argv[] = {
		"status",
		"--porcelain",
		"-u",
		"--ignore-submodules=none",
		NULL,
	};
	struct strbuf buf = STRBUF_INIT;
	int ok_to_remove = 1;

	if ((lstat(path, &st) < 0) || is_empty_dir(path))
		return 1;

	if (!submodule_uses_gitfile(path))
		return 0;

	memset(&cp, 0, sizeof(cp));
	cp.argv = argv;
	cp.env = local_repo_env;
	cp.git_cmd = 1;
	cp.no_stdin = 1;
	cp.out = -1;
	cp.dir = path;
	if (start_command(&cp))
		die("Could not run 'git status --porcelain -uall --ignore-submodules=none' in submodule %s", path);

	len = strbuf_read(&buf, cp.out, 1024);
	if (len > 2)
		ok_to_remove = 0;
	close(cp.out);

	if (finish_command(&cp))
		die("'git status --porcelain -uall --ignore-submodules=none' failed in submodule %s", path);

	strbuf_release(&buf);
	return ok_to_remove;
}

static int find_first_merges(struct object_array *result, const char *path,
		struct commit *a, struct commit *b)
{
