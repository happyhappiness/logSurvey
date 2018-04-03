	if (errno == ENOENT)
		return 0;
	/* .. but not some other error (who really cares what?) */
	return err(o, msg, path, _(": perhaps a D/F conflict?"));
}

static int update_file_flags(struct merge_options *o,
			     const struct object_id *oid,
			     unsigned mode,
			     const char *path,
			     int update_cache,
			     int update_wd)
{
	int ret = 0;

	if (o->call_depth)
		update_wd = 0;

