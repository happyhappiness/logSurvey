	return status;
}

int edit_patch(int argc, const char **argv, const char *prefix)
{
	char *file = xstrdup(git_path("ADD_EDIT.patch"));
	const char *apply_argv[] = { "apply", "--recount", "--cached",
		file, NULL };
	struct child_process child;
	struct rev_info rev;
	int out;
	struct stat st;

	git_config(git_diff_basic_config, NULL); /* no "diff" UI options */

	if (read_cache() < 0)
		die ("Could not read the index");

	init_revisions(&rev, prefix);
	rev.diffopt.context = 7;

	argc = setup_revisions(argc, argv, &rev, NULL);
	rev.diffopt.output_format = DIFF_FORMAT_PATCH;
	out = open(file, O_CREAT | O_WRONLY, 0644);
	if (out < 0)
		die ("Could not open '%s' for writing.", file);
	rev.diffopt.file = fdopen(out, "w");
	rev.diffopt.close_file = 1;
	if (run_diff_files(&rev, 0))
		die ("Could not write patch");

	launch_editor(file, NULL, NULL);

	if (stat(file, &st))
		die("Could not stat '%s'", file);
	if (!st.st_size)
		die("Empty patch. Aborted.");

	memset(&child, 0, sizeof(child));
	child.git_cmd = 1;
	child.argv = apply_argv;
	if (run_command(&child))
		die ("Could not apply '%s'", file);

	unlink(file);
	return 0;
}

static struct lock_file lock_file;

static const char ignore_error[] =
