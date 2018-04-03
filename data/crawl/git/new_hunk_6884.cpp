 * We move everything up by one, since the new "deleted" will
 * be one higher.
 */
static void remove_child(pid_t pid)
{
	struct child **cradle, *blanket;

	for (cradle = &firstborn; (blanket = *cradle); cradle = &blanket->next)
		if (blanket->pid == pid) {
			*cradle = blanket->next;
			live_children--;
			free(blanket);
			break;
		}
}

/*
 * This gets called if the number of connections grows
 * past "max_connections".
 *
 * We kill the newest connection from a duplicate IP.
 */
static void kill_some_child(void)
{
	const struct child *blanket;

	if ((blanket = firstborn)) {
		const struct child *next;

		for (; (next = blanket->next); blanket = next)
			if (!memcmp(&blanket->address, &next->address,
				   sizeof next->address)) {
				kill(blanket->pid, SIGTERM);
				break;
			}
	}
}

static void check_dead_children(void)
{
	int status;
	pid_t pid;

	while ((pid = waitpid(-1, &status, WNOHANG))>0) {
		const char *dead = "";
		remove_child(pid);
		if (!WIFEXITED(status) || WEXITSTATUS(status) > 0)
			dead = " (with error)";
		loginfo("[%d] Disconnected%s", (int)pid, dead);
	}
}

static void handle(int incoming, struct sockaddr *addr, int addrlen)
{
	pid_t pid;

	if (max_connections && live_children >= max_connections) {
		kill_some_child();
		sleep(1);			 /* give it some time to die */
		check_dead_children();
		if (live_children >= max_connections) {
			close(incoming);
			logerror("Too many children, dropping connection");
			return;
		}
	}

	if ((pid = fork())) {
		close(incoming);
		if (pid < 0) {
			logerror("Couldn't fork %s", strerror(errno));
			return;
		}

		add_child(pid, addr, addrlen);
		return;
	}

