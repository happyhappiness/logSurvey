	return lk->fd;
}

static char *unable_to_lock_message(const char *path, int err)
{
	struct strbuf buf = STRBUF_INIT;

	if (err == EEXIST) {
		strbuf_addf(&buf, "Unable to create '%s.lock': %s.\n\n"
		    "If no other git process is currently running, this probably means a\n"
		    "git process crashed in this repository earlier. Make sure no other git\n"
		    "process is running and remove the file manually to continue.",
		    path, strerror(err));
	} else
		strbuf_addf(&buf, "Unable to create '%s.lock': %s", path, strerror(err));
	return strbuf_detach(&buf, NULL);
}

int unable_to_lock_error(const char *path, int err)
{
	char *msg = unable_to_lock_message(path, err);
	error("%s", msg);
	free(msg);
	return -1;
}

NORETURN void unable_to_lock_index_die(const char *path, int err)
{
	die("%s", unable_to_lock_message(path, err));
}

int hold_lock_file_for_update(struct lock_file *lk, const char *path, int flags)
