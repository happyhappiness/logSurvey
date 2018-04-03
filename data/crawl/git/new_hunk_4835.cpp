	 */
	commit_style = COMMIT_PARTIAL;

	if (whence != FROM_COMMIT)
		die("cannot do a partial commit during a %s.", whence_s());

	memset(&partial, 0, sizeof(partial));
	partial.strdup_strings = 1;
