			 "--status-fd=1",
			 "--verify", temp.filename.buf, "-",
			 NULL);
	gpg.in = -1;
	gpg.out = -1;
	if (gpg_output)
		gpg.err = -1;
	if (start_command(&gpg)) {
		delete_tempfile(&temp);
		return error(_("could not run gpg."));
	}

	sigchain_push(SIGPIPE, SIG_IGN);
	write_in_full(gpg.in, payload, payload_size);
	close(gpg.in);

	if (gpg_output) {
		strbuf_read(gpg_output, gpg.err, 0);
		close(gpg.err);
	}
	if (!gpg_status)
		gpg_status = &buf;
	strbuf_read(gpg_status, gpg.out, 0);
	close(gpg.out);

	ret = finish_command(&gpg);
	sigchain_pop(SIGPIPE);

	delete_tempfile(&temp);