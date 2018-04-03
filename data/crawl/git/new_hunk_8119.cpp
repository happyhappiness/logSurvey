		find_unique_abbrev(sha1_new, DEFAULT_ABBREV));
}

static int update_ref_env(const char *action,
		      const char *refname,
		      unsigned char *sha1,
		      unsigned char *oldval)
{
	char msg[1024];
	char *rla = getenv("GIT_REFLOG_ACTION");

	if (!rla)
		rla = "(reflog update)";
	if (snprintf(msg, sizeof(msg), "%s: %s", rla, action) >= sizeof(msg))
		warning("reflog message too long: %.*s...", 50, msg);
	return update_ref(msg, refname, sha1, oldval, 0, QUIET_ON_ERR);
}

static int update_local_ref(const char *name,
