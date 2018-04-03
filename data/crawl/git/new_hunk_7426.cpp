	if (finish_command(&gpg) || !len || len < 0)
		return error("gpg failed to sign the tag");

	return 0;
}
