	return fsck_obj(obj);
}

static int default_refs;

static void fsck_handle_reflog_sha1(const char *refname, unsigned char *sha1)
