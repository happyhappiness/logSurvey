}

static int each_reflog(struct object_id *old_oid, struct object_id *new_oid,
		       const char *committer, unsigned long timestamp,
		       int tz, const char *msg, void *cb_data)
{
	printf("%s %s %s %"PRItime" %d %s\n",
