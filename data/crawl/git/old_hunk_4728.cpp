	rev.diffopt.output_format = DIFF_FORMAT_PATCH;
	out = open(file, O_CREAT | O_WRONLY, 0644);
	if (out < 0)
		die ("Could not open '%s' for writing.", file);
	rev.diffopt.file = xfdopen(out, "w");
	rev.diffopt.close_file = 1;
	if (run_diff_files(&rev, 0))
		die ("Could not write patch");

	launch_editor(file, NULL, NULL);

	if (stat(file, &st))
		die_errno("Could not stat '%s'", file);
	if (!st.st_size)
		die("Empty patch. Aborted.");

	memset(&child, 0, sizeof(child));
	child.git_cmd = 1;
	child.argv = apply_argv;
	if (run_command(&child))
		die ("Could not apply '%s'", file);

	unlink(file);
	return 0;
