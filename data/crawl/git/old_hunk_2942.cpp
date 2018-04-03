	switch (patch_format) {
	case PATCH_FORMAT_MBOX:
		return split_mail_mbox(state, paths, keep_cr);
	default:
		die("BUG: invalid patch_format");
	}
