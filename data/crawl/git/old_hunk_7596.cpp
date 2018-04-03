	return 0;
}

static int fsck_handle_ref(const char *refname, const unsigned char *sha1, int flag, void *cb_data)
{
	struct object *obj;

	obj = lookup_object(sha1);
	if (!obj) {
		if (has_sha1_file(sha1)) {
			default_refs++;
			return 0; /* it is in a pack */
		}
		error("%s: invalid sha1 pointer %s", refname, sha1_to_hex(sha1));
		/* We'll continue with the rest despite the error.. */
		return 0;
	}
	default_refs++;
	obj->used = 1;
	mark_reachable(obj, REACHABLE);