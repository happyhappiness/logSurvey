	if (errno == ENOENT)
		return 0;
	/* .. but not some other error (who really cares what?) */
	return error(msg, path, _(": perhaps a D/F conflict?"));
}

static int update_file_flags(struct merge_options *o,
