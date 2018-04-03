/* $Id: ipcache.cc,v 1.28 1996/05/03 22:56:29 wessels Exp $ */

/*
 * DEBUG: Section 14          ipcache: IP Cache
 */

#include "squid.h"


#define MAX_LINELEN (4096)
char ipcache_status_char _PARAMS((ipcache_entry *));
int ipcache_hash_entry_count();

#define MAX_IP		 1024	/* Maximum cached IP */
#define IP_LOW_WATER       70
#define IP_HIGH_WATER      90
#define MAX_HOST_NAME	  256
#define IP_INBUF	 4096

long ipcache_low = 180;
long ipcache_high = 200;

typedef struct _ip_pending {
    int fd;
    IPH handler;
    void *data;
    struct _ip_pending *next;
} IpPending;


typedef struct _ipcache_list {
    ipcache_entry *entry;
    struct _ipcache_list *next;
} ipcache_list;


typedef struct _dnsserver_entry {
    int id;
    int alive;
    int inpipe;
    int outpipe;
    int pending_count;		/* counter of outstanding request */
    long lastcall;
    long answer;
    unsigned int offset;
    unsigned int size;
    char *ip_inbuf;
    /* global ipcache_entry list for pending entry */
    ipcache_list *global_pending;
    ipcache_list *global_pending_tail;
} dnsserver_entry;

typedef struct _line_entry {
    char *line;
    struct _line_entry *next;
} line_entry;

static dnsserver_entry **dns_child_table = NULL;
static int last_dns_dispatched = 2;
static struct hostent *static_result = NULL;
static int dns_child_alive = 0;

char *dns_error_message = NULL;	/* possible error message */
HashID ip_table = 0;

extern int do_dns_test;
extern int getMaxFD();
extern int getDnsChildren();
extern void fatal_dump _PARAMS((char *));
extern int file_update_open _PARAMS((int, char *));

void update_dns_child_alive()
{
    int i;
    int N = getDnsChildren();

    dns_child_alive = 0;
    for (i = 0; i < N; ++i) {
	if (dns_child_table[i]->alive) {
	    dns_child_alive = 1;
	    break;
	}
    }
}

int ipcache_testname()
{
    wordlist *w = NULL;
    debug(14, 1, "Performing DNS Tests...\n");
    if ((w = getDnsTestnameList()) == NULL)
	return 1;
    for (; w; w = w->next) {
	if (gethostbyname(w->key) != NULL)
	    return 1;
    }
    return 0;
}


/*
 * open a UNIX domain socket for rendevouing with dnsservers
 */
int ipcache_create_dnsserver(command)
     char *command;
{
    int pid;
    struct sockaddr_un addr;
    static int n_dnsserver = 0;
    char *socketname = NULL;
    int cfd;			/* socket for child (dnsserver) */
    int sfd;			/* socket for server (squid) */
    int fd;

    if ((cfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
	debug(14, 0, "ipcache_create_dnsserver: socket: %s\n", xstrerror());
	return -1;
    }
    fdstat_open(cfd, Socket);
    fd_note(cfd, "socket to dnsserver");
    memset(&addr, '\0', sizeof(addr));
    addr.sun_family = AF_UNIX;
    socketname = tempnam(NULL, "dns");
    /* sprintf(socketname, "dns/dns%d.%d", (int) getpid(), n_dnsserver++); */
    strcpy(addr.sun_path, socketname);
    debug(14, 4, "ipcache_create_dnsserver: path is %s\n", addr.sun_path);

    if (bind(cfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
	close(cfd);
	debug(14, 0, "ipcache_create_dnsserver: bind: %s\n", xstrerror());
	xfree(socketname);
	return -1;
    }
    debug(14, 4, "ipcache_create_dnsserver: bind to local host.\n");
    listen(cfd, 1);

    if ((pid = fork()) < 0) {
	debug(14, 0, "ipcache_create_dnsserver: fork: %s\n", xstrerror());
	close(cfd);
	xfree(socketname);
	return -1;
    }
    if (pid > 0) {		/* parent */
	close(cfd);		/* close shared socket with child */

	/* open new socket for parent process */
	if ((sfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
	    debug(14, 0, "ipcache_create_dnsserver: socket: %s\n", xstrerror());
	    xfree(socketname);
	    return -1;
	}
	fcntl(sfd, F_SETFD, 1);	/* set close-on-exec */
	memset(&addr, '\0', sizeof(addr));
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path, socketname);
	xfree(socketname);
	if (connect(sfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
	    close(sfd);
	    debug(14, 0, "ipcache_create_dnsserver: connect: %s\n", xstrerror());
	    return -1;
	}
	debug(14, 4, "ipcache_create_dnsserver: FD %d connected to %s #%d.\n",
	    sfd, command, n_dnsserver);
	return sfd;
    }
    /* child */

    /* give up extra priviliges */
    no_suid();

    /* setup filedescriptors */
    dup2(cfd, 3);
    for (fd = getMaxFD(); fd > 3; fd--) {
	(void) close(fd);
    }

    execlp(command, "(dnsserver)", "-p", socketname, NULL);
    debug(14, 0, "ipcache_create_dnsserver: %s: %s\n", command, xstrerror());
    _exit(1);
    return (0);			/* NOTREACHED */
}


/* removes the given ipcache entry */
int ipcache_release(e)
     ipcache_entry *e;
{
    ipcache_entry *result = 0;
    int i;

    debug(14, 5, "ipcache_release: ipcache_count before: %d \n", meta_data.ipcache_count);

    if (e != NULL && ip_table) {	/* sometimes called with NULL e */
	hash_link *table_entry = hash_lookup(ip_table, e->name);
	if (table_entry) {
	    result = (ipcache_entry *) table_entry;
	    debug(14, 5, "HASH table count before delete: %d\n", ipcache_hash_entry_count());
	    if (hash_remove_link(ip_table, table_entry)) {
		debug(14, 3, "ipcache_release: Cannot delete '%s' from hash table %d\n", e->name, ip_table);
	    }
	    debug(14, 5, "HASH table count after delete: %d\n", ipcache_hash_entry_count());
	    if (result) {
		if (result->status == PENDING) {
		    debug(14, 1, "ipcache_release: Try to release entry with PENDING status. ignored.\n");
		    debug(14, 5, "ipcache_release: ipcache_count: %d \n", meta_data.ipcache_count);
		    return -1;
		}
		if (result->status == CACHED) {
		    if (result->addr_count)
			for (i = 0; i < (int) result->addr_count; i++)
			    safe_free(result->entry.h_addr_list[i]);
		    if (result->entry.h_addr_list)
			safe_free(result->entry.h_addr_list);
		    if (result->alias_count)
			for (i = 0; i < (int) result->alias_count; i++)
			    safe_free(result->entry.h_aliases[i]);
		    if (result->entry.h_aliases)
			safe_free(result->entry.h_aliases);
		    safe_free(result->entry.h_name);
		    debug(14, 5, "ipcache_release: Released IP cached record for '%s'.\n", e->name);
		}
		/* XXX: we're having mem mgmt problems; zero, then free */
		safe_free(result->name);
		memset(result, '\0', sizeof(ipcache_entry));
		safe_free(result);
	    }
	    --meta_data.ipcache_count;
	    debug(14, 5, "ipcache_release: ipcache_count when return: %d \n", meta_data.ipcache_count);
	    return meta_data.ipcache_count;
	}
    }
    debug(14, 3, "ipcache_release: can't delete entry\n");
    return -1;			/* can't delete entry */
}

/* return match for given name */
ipcache_entry *ipcache_get(name)
     char *name;
{
    hash_link *e;
    static ipcache_entry *result;

    result = NULL;
    if (ip_table) {
	if ((e = hash_lookup(ip_table, name)) != NULL)
	    result = (ipcache_entry *) e;
    }
    if (result == NULL)
	return NULL;

    if (((result->timestamp + result->ttl) < squid_curtime) &&
	(result->status != PENDING)) {	/* expired? */
	ipcache_release(result);
	return NULL;
    }
    return result;
}


/* get the first ip entry in the storage */
ipcache_entry *ipcache_GetFirst()
{
    static hash_link *entryPtr;

    if ((!ip_table) || ((entryPtr = hash_first(ip_table)) == NULL))
	return NULL;
    return ((ipcache_entry *) entryPtr);
}


/* get the next ip entry in the storage for a given search pointer */
ipcache_entry *ipcache_GetNext()
{
    static hash_link *entryPtr;

    if ((!ip_table) || ((entryPtr = hash_next(ip_table)) == NULL))
	return NULL;
    return ((ipcache_entry *) entryPtr);
}

int ipcache_compareLastRef(e1, e2)
     ipcache_entry **e1, **e2;
{
    if (!e1 || !e2)
	fatal_dump(NULL);

    if ((*e1)->lastref > (*e2)->lastref)
	return (1);

    if ((*e1)->lastref < (*e2)->lastref)
	return (-1);

    return (0);
}



/* finds the LRU and deletes */
int ipcache_purgelru()
{
    ipcache_entry *e;
    int local_ip_count = 0;
    int local_ip_notpending_count = 0;
    int removed = 0;
    int i;
    ipcache_entry **LRU_list;
    int LRU_list_count = 0;
    int LRU_cur_size = meta_data.ipcache_count;

    LRU_list = (ipcache_entry **) xcalloc(LRU_cur_size, sizeof(ipcache_entry *));

    e = NULL;

    for (e = ipcache_GetFirst(); e; e = ipcache_GetNext()) {
	local_ip_count++;

	if (LRU_list_count >= LRU_cur_size) {
	    /* have to realloc  */
	    LRU_cur_size += 16;
	    debug(14, 3, "ipcache_purgelru: Have to grow LRU_list to %d. This shouldn't happen.\n",
		LRU_cur_size);
	    LRU_list = (ipcache_entry **) xrealloc((char *) LRU_list,
		LRU_cur_size * sizeof(ipcache_entry *));
	}
	if ((e->status != PENDING) && (e->pending_head == NULL)) {
	    local_ip_notpending_count++;
	    LRU_list[LRU_list_count++] = e;
	}
    }

    debug(14, 3, "ipcache_purgelru: ipcache_count: %5d\n", meta_data.ipcache_count);
    debug(14, 3, "                  actual count : %5d\n", local_ip_count);
    debug(14, 3, "                  high W mark  : %5d\n", ipcache_high);
    debug(14, 3, "                  low  W mark  : %5d\n", ipcache_low);
    debug(14, 3, "                  not pending  : %5d\n", local_ip_notpending_count);
    debug(14, 3, "              LRU candidated   : %5d\n", LRU_list_count);

    /* sort LRU candidate list */
    qsort((char *) LRU_list, LRU_list_count, sizeof(e), (int (*)(const void *, const void *)) ipcache_compareLastRef);

    for (i = 0; LRU_list[i] && (meta_data.ipcache_count > ipcache_low)
	&& i < LRU_list_count;
	++i) {
	ipcache_release(LRU_list[i]);
	removed++;
    }

    debug(14, 3, "                   removed      : %5d\n", removed);
    safe_free(LRU_list);
    return (removed > 0) ? 0 : -1;
}


/* create blank ipcache_entry */
ipcache_entry *ipcache_create()
{
    static ipcache_entry *ipe;
    static ipcache_entry *new;
    debug(14, 5, "ipcache_create: when enter. ipcache_count == %d\n", meta_data.ipcache_count);

    if (meta_data.ipcache_count > ipcache_high) {
	if (ipcache_purgelru() < 0) {
	    debug(14, 1, "ipcache_create: Cannot release needed IP entry via LRU: %d > %d, removing first entry...\n", meta_data.ipcache_count, MAX_IP);
	    ipe = ipcache_GetFirst();
	    if (!ipe) {
		debug(14, 1, "ipcache_create: First entry is a null pointer ???\n");
		/* have to let it grow beyond limit here */
	    } else if (ipe && ipe->status != PENDING) {
		ipcache_release(ipe);
	    } else {
		debug(14, 1, "ipcache_create: First entry is also PENDING entry.\n");
		/* have to let it grow beyond limit here */
	    }
	}
    }
    meta_data.ipcache_count++;
    debug(14, 5, "ipcache_create: before return. ipcache_count == %d\n", meta_data.ipcache_count);
    new = (ipcache_entry *) xcalloc(1, sizeof(ipcache_entry));
    /* set default to 4, in case parser fail to get token $h_length from
     * dnsserver. */
    new->entry.h_length = 4;
    return new;

}

void ipcache_add_to_hash(e)
     ipcache_entry *e;
{
    if (hash_join(ip_table, (hash_link *) e)) {
	debug(14, 1, "ipcache_add_to_hash: Cannot add %s (%p) to hash table %d.\n",
	    e->name, e, ip_table);
    }
    debug(14, 5, "ipcache_add_to_hash: name <%s>\n", e->name);
    debug(14, 5, "                     ipcache_count: %d\n", meta_data.ipcache_count);
}


void ipcache_add(name, e, data, cached)
     char *name;
     ipcache_entry *e;
     struct hostent *data;
     int cached;
{
    int addr_count, alias_count, i;

    debug(14, 10, "ipcache_add: Adding name '%s' (%s).\n", name,
	cached ? "cached" : "not cached");

    e->name = xstrdup(name);
    if (cached) {

	/* count for IPs */
	addr_count = 0;
	while ((addr_count < 255) && data->h_addr_list[addr_count])
	    ++addr_count;

	e->addr_count = addr_count;

	/* count for Alias */
	alias_count = 0;
	if (data->h_aliases)
	    while ((alias_count < 255) && data->h_aliases[alias_count])
		++alias_count;

	e->alias_count = alias_count;

	/* copy ip addresses information */
	e->entry.h_addr_list = (char **) xcalloc(addr_count + 1, sizeof(char *));
	for (i = 0; i < addr_count; i++) {
	    e->entry.h_addr_list[i] = (char *) xcalloc(1, data->h_length);
	    memcpy(e->entry.h_addr_list[i], data->h_addr_list[i], data->h_length);
	}

	if (alias_count) {
	    /* copy aliases information */
	    e->entry.h_aliases = (char **) xcalloc(alias_count + 1, sizeof(char *));
	    for (i = 0; i < alias_count; i++) {
		e->entry.h_aliases[i] = (char *) xcalloc(1, strlen(data->h_aliases[i]) + 1);
		strcpy(e->entry.h_aliases[i], data->h_aliases[i]);
	    }
	}
	e->entry.h_length = data->h_length;
	e->entry.h_name = xstrdup(data->h_name);
	e->lastref = e->timestamp = squid_curtime;
	e->status = CACHED;
	e->ttl = DnsPositiveTtl;
    } else {
	e->lastref = e->timestamp = squid_curtime;
	e->status = NEGATIVE_CACHED;
	e->ttl = getNegativeDNSTTL();
    }

    ipcache_add_to_hash(e);
}


/* exactly the same to ipcache_add, 
 * except it does NOT
 * - create entry->name (assume it's there already.)
 * - add the entry to the hash (it's should be in hash table already.).
 * 
 * Intend to be used by ipcache_cleanup_pendinglist.
 */
void ipcache_update_content(name, e, data, cached)
     char *name;
     ipcache_entry *e;
     struct hostent *data;
     int cached;
{
    int addr_count, alias_count, i;

    debug(14, 10, "ipcache_update: Updating name '%s' (%s).\n", name,
	cached ? "cached" : "not cached");

    if (cached) {

	/* count for IPs */
	addr_count = 0;
	while ((addr_count < 255) && data->h_addr_list[addr_count])
	    ++addr_count;

	e->addr_count = addr_count;

	/* count for Alias */
	alias_count = 0;
	while ((alias_count < 255) && data->h_aliases[alias_count])
	    ++alias_count;

	e->alias_count = alias_count;

	/* copy ip addresses information */
	e->entry.h_addr_list = (char **) xcalloc(addr_count + 1, sizeof(char *));
	for (i = 0; i < addr_count; i++) {
	    e->entry.h_addr_list[i] = (char *) xcalloc(1, data->h_length);
	    memcpy(e->entry.h_addr_list[i], data->h_addr_list[i], data->h_length);
	}

	/* copy aliases information */
	e->entry.h_aliases = (char **) xcalloc(alias_count + 1, sizeof(char *));
	for (i = 0; i < alias_count; i++) {
	    e->entry.h_aliases[i] = (char *) xcalloc(1, strlen(data->h_aliases[i]) + 1);
	    strcpy(e->entry.h_aliases[i], data->h_aliases[i]);
	}

	e->entry.h_length = data->h_length;
	e->entry.h_name = xstrdup(data->h_name);
	e->lastref = e->timestamp = squid_curtime;
	e->status = CACHED;
	e->ttl = DnsPositiveTtl;
    } else {
	e->lastref = e->timestamp = squid_curtime;
	e->status = NEGATIVE_CACHED;
	e->ttl = getNegativeDNSTTL();
    }

}



/* walks down the pending list, calling handlers */
void ipcache_call_pending(entry)
     ipcache_entry *entry;
{
    IpPending *p;
    int nhandler = 0;

    entry->lastref = squid_curtime;

    while (entry->pending_head != NULL) {
	p = entry->pending_head;
	entry->pending_head = entry->pending_head->next;
	if (entry->pending_head == NULL)
	    entry->pending_tail = NULL;
	if (p->handler != NULL) {
	    nhandler++;
	    p->handler(p->fd, (entry->status == CACHED) ?
		&(entry->entry) : NULL, p->data);
	}
	memset(p, '\0', sizeof(IpPending));
	safe_free(p);
    }
    entry->pending_head = entry->pending_tail = NULL;	/* nuke list */
    debug(14, 10, "ipcache_call_pending: Called %d handlers.\n", nhandler);
}

void ipcache_call_pending_badname(fd, handler, data)
     int fd;
     IPH handler;
     void *data;
{
    debug(14, 4, "ipcache_call_pending_badname: Bad Name: Calling handler with NULL result.\n");
    handler(fd, NULL, data);
}


/* call when dnsserver is broken, have to switch to blocking mode. 
 * All pending lookup will be looked up by blocking call.
 */
int ipcache_cleanup_pendinglist(data)
     dnsserver_entry *data;
{
    ipcache_list *p;
    struct hostent *s_result = NULL;

    while (data->global_pending != NULL) {
	s_result = gethostbyname(data->global_pending->entry->name);
	ipcache_update_content(data->global_pending->entry->name,
	    data->global_pending->entry, s_result, s_result ? 1 : 0);
	ipcache_call_pending(data->global_pending->entry);
	p = data->global_pending;
	data->global_pending = data->global_pending->next;
	/* XXX: we're having mem mgmt problems; zero, then free */
	memset(p, '\0', sizeof(ipcache_list));
	safe_free(p);
    }
    data->global_pending = data->global_pending_tail = NULL;	/* nuke */
    return 0;
}

/* free all lines in the list */
void free_lines(line)
     line_entry *line;
{
    line_entry *tmp;
