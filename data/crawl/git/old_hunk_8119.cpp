		find_unique_abbrev(sha1_new, DEFAULT_ABBREV));
}

static int update_ref(const char *action,
		      const char *refname,
		      unsigned char *sha1,
		      unsigned char *oldval)
{
	char msg[1024];
	char *rla = getenv("GIT_REFLOG_ACTION");
	static struct ref_lock *lock;

	if (!rla)
		rla = "(reflog update)";
	snprintf(msg, sizeof(msg), "%s: %s", rla, action);
	lock = lock_any_ref_for_update(refname, oldval, 0);
	if (!lock)
		return 1;
	if (write_ref_sha1(lock, sha1, msg) < 0)
		return 1;
	return 0;
}

static int update_local_ref(const char *name,
