	return -1;
}


/*
 * We count spawned/reaped separately, just to avoid any
 * races when updating them from signals. The SIGCHLD handler
 * will only update children_reaped, and the fork logic will
 * only update children_spawned.
 *
 * MAX_CHILDREN should be a power-of-two to make the modulus
 * operation cheap. It should also be at least twice
 * the maximum number of connections we will ever allow.
 */
#define MAX_CHILDREN 128

static int max_connections = 25;

/* These are updated by the signal handler */
static volatile unsigned int children_reaped;
static pid_t dead_child[MAX_CHILDREN];

/* These are updated by the main loop */
static unsigned int children_spawned;
static unsigned int children_deleted;

static struct child {
	pid_t pid;
	int addrlen;
	struct sockaddr_storage address;
} live_child[MAX_CHILDREN];

static void add_child(int idx, pid_t pid, struct sockaddr *addr, int addrlen)
{
	live_child[idx].pid = pid;
	live_child[idx].addrlen = addrlen;
	memcpy(&live_child[idx].address, addr, addrlen);
}

/*
