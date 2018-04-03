
static void remove_locks(void)
{
	struct remote_lock *lock = remote->locks;

	fprintf(stderr, "Removing remote locks...\n");
	while (lock) {
