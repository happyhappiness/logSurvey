
NORETURN void unable_to_lock_index_die(const char *path, int err)
{
	if (err == EEXIST) {
		die("Unable to create '%s.lock': %s.\n\n"
		    "If no other git process is currently running, this probably means a\n"
		    "git process crashed in this repository earlier. Make sure no other git\n"
