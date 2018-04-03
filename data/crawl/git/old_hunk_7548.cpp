	unlink(git_path("MERGE_HEAD"));
	unlink(git_path("MERGE_MSG"));

	commit_index_files();

	rerere();
	run_hook(get_index_file(), "post-commit", NULL);