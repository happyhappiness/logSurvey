	return -1;
}

static int max_connections = 32;

static unsigned int live_children;

static struct child {
	struct child *next;
	pid_t pid;
	struct sockaddr_storage address;
} *firstborn;

static void add_child(pid_t pid, struct sockaddr *addr, int addrlen)
{
	struct child *newborn;
	newborn = xcalloc(1, sizeof *newborn);
	if (newborn) {
		struct child **cradle;

		live_children++;
		newborn->pid = pid;
		memcpy(&newborn->address, addr, addrlen);
		for (cradle = &firstborn; *cradle; cradle = &(*cradle)->next)
			if (!memcmp(&(*cradle)->address, &newborn->address,
				   sizeof newborn->address))
				break;
		newborn->next = *cradle;
		*cradle = newborn;
	}
	else
		logerror("Out of memory spawning new child");
}

/*
