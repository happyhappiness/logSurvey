	args_gpg[0] = gpg_program;
	fd = git_mkstemp(path, PATH_MAX, ".git_vtag_tmpXXXXXX");
	if (fd < 0)
		return error_errno(_("could not create temporary file '%s'"), path);
	if (write_in_full(fd, signature, signature_size) < 0)
		return error_errno(_("failed writing detached signature to '%s'"), path);
	close(fd);

	gpg.argv = args_gpg;