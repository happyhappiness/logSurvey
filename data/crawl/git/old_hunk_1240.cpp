	if (verify_index_match(ce, &st))
		return error(_("%s: does not match index"), name);

	status = load_patch_target(&buf, ce, &st, name, mode);
	if (status < 0)
		return status;
	else if (status)
