	if (check_repository_format_gently(gitdir, nongit_ok))
		return NULL;

	/* #16.2, #17.2, #20.2, #21.2, #24, #25, #28, #29 (see t1510) */
	if (is_bare_repository_cfg > 0) {
		set_git_dir(offset == len ? gitdir : make_absolute_path(gitdir));
