
static int default_refs;

static void fsck_handle_reflog_sha1(unsigned char *sha1)
{
	struct object *obj;

	if (!is_null_sha1(sha1)) {
		obj = lookup_object(sha1);
		if (obj) {
			obj->used = 1;
			mark_object_reachable(obj);
		}
	}
}

static int fsck_handle_reflog_ent(unsigned char *osha1, unsigned char *nsha1,
		const char *email, unsigned long timestamp, int tz,
		const char *message, void *cb_data)
{
	if (verbose)
		fprintf(stderr, "Checking reflog %s->%s\n",
			sha1_to_hex(osha1), sha1_to_hex(nsha1));

	fsck_handle_reflog_sha1(osha1);
	fsck_handle_reflog_sha1(nsha1);
	return 0;
}
