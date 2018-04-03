		       const char *committer, unsigned long timestamp,
		       int tz, const char *msg, void *cb_data)
{
	printf("%s %s %s %"PRItime" %d %s\n",
	       oid_to_hex(old_oid), oid_to_hex(new_oid),
	       committer, timestamp, tz, msg);
	return 0;
