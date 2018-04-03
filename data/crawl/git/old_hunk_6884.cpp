 * We move everything up by one, since the new "deleted" will
 * be one higher.
 */
static void remove_child(pid_t pid, unsigned deleted, unsigned spawned)
{
	struct child n;

	deleted %= MAX_CHILDREN;
	spawned %= MAX_CHILDREN;
	if (live_child[deleted].pid == pid) {
		live_child[deleted].pid = -1;
		return;
	}
	n = live_child[deleted];
	for (;;) {
		struct child m;
		deleted = (deleted + 1) % MAX_CHILDREN;
		if (deleted == spawned)
			die("could not find dead child %d\n", pid);
		m = live_child[deleted];
		live_child[deleted] = n;
		if (m.pid == pid)
			return;
		n = m;
	}
}

/*
 * This gets called if the number of connections grows
 * past "max_connections".
 *
 * We _should_ start off by searching for connections
 * from the same IP, and if there is some address wth
 * multiple connections, we should kill that first.
 *
 * As it is, we just "randomly" kill 25% of the connections,
 * and our pseudo-random generator sucks too. I have no
 * shame.
 *
 * Really, this is just a place-holder for a _real_ algorithm.
 */
static void kill_some_children(int signo, unsigned start, unsigned stop)
{
	start %= MAX_CHILDREN;
	stop %= MAX_CHILDREN;
	while (start != stop) {
		if (!(start & 3))
			kill(live_child[start].pid, signo);
		start = (start + 1) % MAX_CHILDREN;
	}
}

static void check_dead_children(void)
{
	unsigned spawned, reaped, deleted;

	for (;;) {
		int status;
		pid_t pid = waitpid(-1, &status, WNOHANG);

		if (pid > 0) {
			unsigned reaped = children_reaped;
			if (!WIFEXITED(status) || WEXITSTATUS(status) > 0)
				pid = -pid;
			dead_child[reaped % MAX_CHILDREN] = pid;
			children_reaped = reaped + 1;
			continue;
		}
		break;
	}

	spawned = children_spawned;
	reaped = children_reaped;
	deleted = children_deleted;

	while (deleted < reaped) {
		pid_t pid = dead_child[deleted % MAX_CHILDREN];
		const char *dead = pid < 0 ? " (with error)" : "";

		if (pid < 0)
			pid = -pid;

		/* XXX: Custom logging, since we don't wanna getpid() */
		if (verbose) {
			if (log_syslog)
				syslog(LOG_INFO, "[%d] Disconnected%s",
						pid, dead);
			else
				fprintf(stderr, "[%d] Disconnected%s\n",
						pid, dead);
		}
		remove_child(pid, deleted, spawned);
		deleted++;
	}
	children_deleted = deleted;
}

static void check_max_connections(void)
{
	for (;;) {
		int active;
		unsigned spawned, deleted;

		check_dead_children();

		spawned = children_spawned;
		deleted = children_deleted;

		active = spawned - deleted;
		if (active <= max_connections)
			break;

		/* Kill some unstarted connections with SIGTERM */
		kill_some_children(SIGTERM, deleted, spawned);
		if (active <= max_connections << 1)
			break;

		/* If the SIGTERM thing isn't helping use SIGKILL */
		kill_some_children(SIGKILL, deleted, spawned);
		sleep(1);
	}
}

static void handle(int incoming, struct sockaddr *addr, int addrlen)
{
	pid_t pid = fork();

	if (pid) {
		unsigned idx;

		close(incoming);
		if (pid < 0)
			return;

		idx = children_spawned % MAX_CHILDREN;
		children_spawned++;
		add_child(idx, pid, addr, addrlen);

		check_max_connections();
		return;
	}

