{
	unsigned char head_sha1[20];

	if (!file_exists(git_path("CHERRY_PICK_HEAD")) &&
	    !file_exists(git_path("REVERT_HEAD")))
		return error(_("no cherry-pick or revert in progress"));
	if (read_ref_full("HEAD", 0, head_sha1, NULL))
		return error(_("cannot resolve HEAD"));
