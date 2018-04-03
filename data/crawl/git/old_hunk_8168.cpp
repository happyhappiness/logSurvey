	struct child_process rls;
	FILE *rls_fout;

	/*
	 * NEEDSWORK: this should use something like lock-file
	 * to create temporary that is cleaned up upon error.
	 */
	bundle_fd = (!strcmp(path, "-") ? 1 :
			open(path, O_CREAT | O_EXCL | O_WRONLY, 0666));
	if (bundle_fd < 0)
		return error("Could not create '%s': %s", path, strerror(errno));

	/* write signature */
	write_or_die(bundle_fd, bundle_signature, strlen(bundle_signature));
