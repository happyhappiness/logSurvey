	args_gpg[2] = path;
	if (start_command(&gpg)) {
		unlink(path);
		return error(_("could not run gpg."));
	}

	write_in_full(gpg.in, payload, payload_size);