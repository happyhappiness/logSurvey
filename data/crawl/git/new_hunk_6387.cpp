	if (!(flags & TRANSPORT_PUSH_FORCE))
		args[i++] = "--ignore-existing";
	args[i++] = temp_dir.buf;
	args[i++] = rsync_url(transport->url);
	args[i++] = NULL;
	if (run_command(&rsync))
		result = error("Could not push to %s",
				rsync_url(transport->url));

	if (remove_dir_recursively(&temp_dir, 0))
		warning ("Could not remove temporary directory %s.",
