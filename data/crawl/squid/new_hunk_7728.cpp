/*
 * $Id: ipcache.cc,v 1.29 1996/07/09 03:41:31 wessels Exp $
 *
 * DEBUG: section 14    IP Cache
 * AUTHOR: Harvest Derived
 *
 * SQUID Internet Object Cache  http://www.nlanr.net/Squid/
 * --------------------------------------------------------
 *
 *  Squid is the result of efforts by numerous individuals from the
 *  Internet community.  Development is led by Duane Wessels of the
 *  National Laboratory for Applied Network Research and funded by
 *  the National Science Foundation.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *  
 */

/*
 * Copyright (c) 1994, 1995.  All rights reserved.
 *  
 *   The Harvest software was developed by the Internet Research Task
 *   Force Research Group on Resource Discovery (IRTF-RD):
 *  
 *         Mic Bowman of Transarc Corporation.
 *         Peter Danzig of the University of Southern California.
 *         Darren R. Hardy of the University of Colorado at Boulder.
 *         Udi Manber of the University of Arizona.
 *         Michael F. Schwartz of the University of Colorado at Boulder.
 *         Duane Wessels of the University of Colorado at Boulder.
 *  
 *   This copyright notice applies to software in the Harvest
 *   ``src/'' directory only.  Users should consult the individual
 *   copyright notices in the ``components/'' subdirectories for
 *   copyright information about other software bundled with the
 *   Harvest source code distribution.
 *  
 * TERMS OF USE
 *   
 *   The Harvest software may be used and re-distributed without
 *   charge, provided that the software origin and research team are
 *   cited in any use of the system.  Most commonly this is
 *   accomplished by including a link to the Harvest Home Page
 *   (http://harvest.cs.colorado.edu/) from the query page of any
 *   Broker you deploy, as well as in the query result pages.  These
 *   links are generated automatically by the standard Broker
 *   software distribution.
 *   
 *   The Harvest software is provided ``as is'', without express or
 *   implied warranty, and with no support nor obligation to assist
 *   in its use, correction, modification or enhancement.  We assume
 *   no liability with respect to the infringement of copyrights,
 *   trade secrets, or any patents, and are not responsible for
 *   consequential damages.  Proper use of the Harvest software is
 *   entirely the responsibility of the user.
 *  
 * DERIVATIVE WORKS
 *  
 *   Users may make derivative works from the Harvest software, subject 
 *   to the following constraints:
 *  
 *     - You must include the above copyright notice and these 
 *       accompanying paragraphs in all forms of derivative works, 
 *       and any documentation and other materials related to such 
 *       distribution and use acknowledge that the software was 
 *       developed at the above institutions.
 *  
 *     - You must notify IRTF-RD regarding your distribution of 
 *       the derivative work.
 *  
 *     - You must clearly notify users that your are distributing 
 *       a modified version and not the original Harvest software.
 *  
 *     - Any derivative product is also subject to these copyright 
 *       and use restrictions.
 *  
 *   Note that the Harvest software is NOT in the public domain.  We
 *   retain copyright, as specified above.
 *  
 * HISTORY OF FREE SOFTWARE STATUS
 *  
 *   Originally we required sites to license the software in cases
 *   where they were going to build commercial products/services
 *   around Harvest.  In June 1995 we changed this policy.  We now
 *   allow people to use the core Harvest software (the code found in
 *   the Harvest ``src/'' directory) for free.  We made this change
 *   in the interest of encouraging the widest possible deployment of
 *   the technology.  The Harvest software is really a reference
 *   implementation of a set of protocols and formats, some of which
 *   we intend to standardize.  We encourage commercial
 *   re-implementations of code complying to this set of standards.  
 */

#include "squid.h"

#define MAX_LINELEN (4096)

#define MAX_IP		 1024	/* Maximum cached IP */
#define IP_LOW_WATER       90
#define IP_HIGH_WATER      95
#define MAX_HOST_NAME	  256
#define IP_INBUF_SZ	 4096

struct _ip_pending {
    int fd;
    IPH handler;
    void *handlerData;
    struct _ip_pending *next;
};

#define DNS_FLAG_ALIVE		0x01
#define DNS_FLAG_BUSY		0x02
#define DNS_FLAG_CLOSING	0x04

typedef struct _dnsserver {
    int id;
    int flags;
    int inpipe;
    int outpipe;
    time_t lastcall;
    time_t answer;
    unsigned int offset;
    unsigned int size;
    char *ip_inbuf;
    struct timeval dispatch_time;
    ipcache_entry *ip_entry;
} dnsserver_t;

static struct {
    int requests;
    int hits;
    int misses;
    int pending_hits;
    int negative_hits;
    int dnsserver_requests;
    int dnsserver_replies;
    int errors;
    int avg_svc_time;
    int ghbn_calls;		/* # calls to blocking gethostbyname() */
    int dnsserver_hist[DefaultDnsChildrenMax];
} IpcacheStats;

typedef struct _line_entry {
    char *line;
    struct _line_entry *next;
} line_entry;

struct dnsQueueData {
    struct dnsQueueData *next;
    ipcache_entry *ip_entry;
};

static int ipcache_testname _PARAMS((void));
static dnsserver_t *dnsGetFirstAvailable _PARAMS((void));
static int ipcache_compareLastRef _PARAMS((ipcache_entry **, ipcache_entry **));
static int ipcache_create_dnsserver _PARAMS((char *command));
static int ipcache_dnsHandleRead _PARAMS((int, dnsserver_t *));
static int ipcache_parsebuffer _PARAMS((char *buf, unsigned int offset, dnsserver_t *));
static int ipcache_purgelru _PARAMS((void));
static void ipcache_release _PARAMS((ipcache_entry *));
static ipcache_entry *ipcache_GetFirst _PARAMS((void));
static ipcache_entry *ipcache_GetNext _PARAMS((void));
static ipcache_entry *ipcache_create _PARAMS((void));
static void free_lines _PARAMS((line_entry *));
static void ipcache_add_to_hash _PARAMS((ipcache_entry *));
static void ipcache_call_pending _PARAMS((ipcache_entry *));
static void ipcache_call_pending_badname _PARAMS((int fd, IPH handler, void *));
static void ipcache_add _PARAMS((char *, ipcache_entry *, struct hostent *, int));
static ipcache_entry *dnsDequeue _PARAMS(());
static void dnsEnqueue _PARAMS((ipcache_entry *));
static void dnsDispatch _PARAMS((dnsserver_t *, ipcache_entry *));
static int ipcacheHasPending _PARAMS((ipcache_entry *));
static ipcache_entry *ipcache_get _PARAMS((char *));
static int dummy_handler _PARAMS((int, struct hostent * hp, void *));
static int ipcacheExpiredEntry _PARAMS((ipcache_entry *));
static void ipcacheAddPending _PARAMS((ipcache_entry *, int fd, IPH, void *));

static dnsserver_t **dns_child_table = NULL;
static struct hostent *static_result = NULL;
static int NDnsServersAlloc = 0;
static struct dnsQueueData *dnsQueueHead = NULL;
static struct dnsQueueData **dnsQueueTailP = &dnsQueueHead;
static HashID ip_table = 0;
char *dns_error_message = NULL;	/* possible error message */
long ipcache_low = 180;
long ipcache_high = 200;

static char ipcache_status_char[] =
{
    'C',
    'N',
    'P',
    'D'
};

static int ipcache_testname()
{
    wordlist *w = NULL;
    debug(14, 1, "Performing DNS Tests...\n");
    if ((w = getDnsTestnameList()) == NULL)
	return 1;
    for (; w; w = w->next) {
	IpcacheStats.ghbn_calls++;
	if (gethostbyname(w->key) != NULL)
	    return 1;
    }
    return 0;
}

/* TCP SOCKET VERSION */
static int ipcache_create_dnsserver(command)
     char *command;
{
    int pid;
    u_short port;
    struct sockaddr_in S;
    int cfd;
    int sfd;
    int len;
    int fd;

    cfd = comm_open(COMM_NOCLOEXEC,
	local_addr,
	0,
	"socket to dnsserver");
    if (cfd == COMM_ERROR) {
	debug(14, 0, "ipcache_create_dnsserver: Failed to create dnsserver\n");
	return -1;
    }
    len = sizeof(S);
    memset(&S, '\0', len);
    if (getsockname(cfd, (struct sockaddr *) &S, &len) < 0) {
	debug(14, 0, "ipcache_create_dnsserver: getsockname: %s\n", xstrerror());
	comm_close(cfd);
	return -1;
    }
    port = ntohs(S.sin_port);
    debug(14, 4, "ipcache_create_dnsserver: bind to local host.\n");
    listen(cfd, 1);
    if ((pid = fork()) < 0) {
	debug(14, 0, "ipcache_create_dnsserver: fork: %s\n", xstrerror());
	comm_close(cfd);
	return -1;
    }
    if (pid > 0) {		/* parent */
	comm_close(cfd);	/* close shared socket with child */
	/* open new socket for parent process */
	sfd = comm_open(0, local_addr, 0, NULL);	/* blocking! */
	if (sfd == COMM_ERROR)
	    return -1;
	if (comm_connect(sfd, localhost, port) == COMM_ERROR) {
	    comm_close(sfd);
	    return -1;
	}
	comm_set_fd_lifetime(sfd, -1);
	return sfd;
    }
    /* child */

    no_suid();			/* give up extra priviliges */
    dup2(cfd, 3);
    for (fd = FD_SETSIZE; fd > 3; fd--)
	close(fd);
    execlp(command, "(dnsserver)", "-t", NULL);
    debug(14, 0, "ipcache_create_dnsserver: %s: %s\n", command, xstrerror());
    _exit(1);
    return 0;
}

/* removes the given ipcache entry */
static void ipcache_release(i)
     ipcache_entry *i;
{
    ipcache_entry *result = 0;
    hash_link *table_entry = NULL;
    int k;

    if ((table_entry = hash_lookup(ip_table, i->name)) == NULL) {
	debug(14, 0, "ipcache_release: Could not find key '%s'\n", i->name);
	return;
    }
    result = (ipcache_entry *) table_entry;
    if (i != result)
	fatal_dump("ipcache_release: expected i == result!");
    if (i->status == IP_PENDING) {
	debug(14, 1, "ipcache_release: Someone called on a PENDING entry\n");
	return;
    }
    if (i->status == IP_DISPATCHED) {
	debug(14, 1, "ipcache_release: Someone called on a DISPATCHED entry\n");
	return;
    }
    if (hash_remove_link(ip_table, table_entry)) {
	debug(14, 0, "ipcache_release: hash_remove_link() failed for '%s'\n",
	    result->name);
	return;
    }
    if (result->status == IP_CACHED) {
	for (k = 0; k < (int) result->addr_count; k++)
	    safe_free(result->entry.h_addr_list[k]);
	safe_free(result->entry.h_addr_list);
	for (k = 0; k < (int) result->alias_count; k++)
	    safe_free(result->entry.h_aliases[k]);
	if (result->entry.h_aliases)
	    safe_free(result->entry.h_aliases);
	safe_free(result->entry.h_name);
	debug(14, 5, "ipcache_release: Released IP cached record for '%s'.\n",
	    result->name);
    }
    safe_free(result->name);
    safe_free(result->error_message);
    memset(result, '\0', sizeof(ipcache_entry));
    safe_free(result);
    --meta_data.ipcache_count;
    return;
}

/* return match for given name */
static ipcache_entry *ipcache_get(name)
     char *name;
{
    hash_link *e;
    static ipcache_entry *i;

    i = NULL;
    if (ip_table) {
	if ((e = hash_lookup(ip_table, name)) != NULL)
	    i = (ipcache_entry *) e;
    }
    return i;
}

/* get the first ip entry in the storage */
static ipcache_entry *ipcache_GetFirst()
{
    return (ipcache_entry *) hash_first(ip_table);
}

/* get the next ip entry in the storage for a given search pointer */
static ipcache_entry *ipcache_GetNext()
{
    return (ipcache_entry *) hash_next(ip_table);
}

static int ipcache_compareLastRef(e1, e2)
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

static int ipcacheExpiredEntry(i)
     ipcache_entry *i;
{
    if (i->lock)
	return 0;
    if (i->status == IP_PENDING)
	return 0;
    if (i->status == IP_DISPATCHED)
	return 0;
    if (i->ttl + i->lastref > squid_curtime)
	return 0;
    return 1;
}

/* finds the LRU and deletes */
static int ipcache_purgelru()
{
    ipcache_entry *i = NULL;
    int local_ip_count = 0;
    int local_ip_notpending_count = 0;
    int removed = 0;
    int k;
    ipcache_entry **LRU_list = NULL;
    int LRU_list_count = 0;
    int LRU_cur_size = meta_data.ipcache_count;

    LRU_list = xcalloc(LRU_cur_size, sizeof(ipcache_entry *));

    for (i = ipcache_GetFirst(); i; i = ipcache_GetNext()) {
	if (ipcacheExpiredEntry(i)) {
	    ipcache_release(i);
	    removed++;
	    continue;
	}
	local_ip_count++;

	if (LRU_list_count >= LRU_cur_size) {
	    /* have to realloc  */
	    LRU_cur_size += 16;
	    debug(14, 3, "ipcache_purgelru: Have to grow LRU_list to %d. This shouldn't happen.\n",
		LRU_cur_size);
	    LRU_list = xrealloc((char *) LRU_list,
		LRU_cur_size * sizeof(ipcache_entry *));
	}
	if (i->status == IP_PENDING)
	    continue;
	if (i->status == IP_DISPATCHED)
	    continue;
	if (i->lock)
	    continue;
	local_ip_notpending_count++;
	LRU_list[LRU_list_count++] = i;
    }

    debug(14, 3, "ipcache_purgelru: ipcache_count: %5d\n", meta_data.ipcache_count);
    debug(14, 3, "                  actual count : %5d\n", local_ip_count);
    debug(14, 3, "                   high W mark : %5d\n", ipcache_high);
    debug(14, 3, "                   low  W mark : %5d\n", ipcache_low);
    debug(14, 3, "                   not pending : %5d\n", local_ip_notpending_count);
    debug(14, 3, "                LRU candidates : %5d\n", LRU_list_count);

    /* sort LRU candidate list */
    qsort((char *) LRU_list,
	LRU_list_count,
	sizeof(i),
	(int (*)(const void *, const void *)) ipcache_compareLastRef);
    for (k = 0; LRU_list[k] && (meta_data.ipcache_count > ipcache_low)
	&& k < LRU_list_count;
	++k) {
	ipcache_release(LRU_list[k]);
	removed++;
    }

    debug(14, 3, "                       removed : %5d\n", removed);
    safe_free(LRU_list);
    return (removed > 0) ? 0 : -1;
}


/* create blank ipcache_entry */
static ipcache_entry *ipcache_create()
{
    static ipcache_entry *new;

    if (meta_data.ipcache_count > ipcache_high) {
	if (ipcache_purgelru() < 0)
	    debug(14, 0, "HELP!! IP Cache is overflowing!\n");
    }
    meta_data.ipcache_count++;
    new = xcalloc(1, sizeof(ipcache_entry));
    /* set default to 4, in case parser fail to get token $h_length from
     * dnsserver. */
    new->entry.h_length = 4;
    return new;

}

static void ipcache_add_to_hash(i)
     ipcache_entry *i;
{
    if (hash_join(ip_table, (hash_link *) i)) {
	debug(14, 1, "ipcache_add_to_hash: Cannot add %s (%p) to hash table %d.\n",
	    i->name, i, ip_table);
    }
    debug(14, 5, "ipcache_add_to_hash: name <%s>\n", i->name);
}


static void ipcache_add(name, i, hp, cached)
     char *name;
     ipcache_entry *i;
     struct hostent *hp;
     int cached;
{
    int addr_count;
    int alias_count;
    int k;

    if (ipcache_get(name))
	fatal_dump("ipcache_add: somebody adding a duplicate!");
    debug(14, 10, "ipcache_add: Adding name '%s' (%s).\n", name,
	cached ? "cached" : "not cached");
    i->name = xstrdup(name);
    if (cached) {
	/* count for IPs */
	addr_count = 0;
	while ((addr_count < 255) && hp->h_addr_list[addr_count])
	    ++addr_count;

	i->addr_count = addr_count;

	/* count for Alias */
	alias_count = 0;
	if (hp->h_aliases)
	    while ((alias_count < 255) && hp->h_aliases[alias_count])
		++alias_count;

	i->alias_count = alias_count;

	/* copy ip addresses information */
	i->entry.h_addr_list = xcalloc(addr_count + 1, sizeof(char *));
	for (k = 0; k < addr_count; k++) {
	    i->entry.h_addr_list[k] = xcalloc(1, hp->h_length);
	    xmemcpy(i->entry.h_addr_list[k], hp->h_addr_list[k], hp->h_length);
	}

	if (alias_count) {
	    /* copy aliases information */
	    i->entry.h_aliases = xcalloc(alias_count + 1, sizeof(char *));
	    for (k = 0; k < alias_count; k++) {
		i->entry.h_aliases[k] = xcalloc(1, strlen(hp->h_aliases[k]) + 1);
		strcpy(i->entry.h_aliases[k], hp->h_aliases[k]);
	    }
	}
	i->entry.h_length = hp->h_length;
	i->entry.h_name = xstrdup(hp->h_name);
	i->lastref = i->timestamp = squid_curtime;
	i->status = IP_CACHED;
	i->ttl = DnsPositiveTtl;
    } else {
	i->lastref = i->timestamp = squid_curtime;
	i->status = IP_NEGATIVE_CACHED;
	i->ttl = getNegativeDNSTTL();
    }
    ipcache_add_to_hash(i);
}




/* walks down the pending list, calling handlers */
static void ipcache_call_pending(i)
     ipcache_entry *i;
{
    struct _ip_pending *p = NULL;
    int nhandler = 0;

    i->lastref = squid_curtime;

    while (i->pending_head != NULL) {
	p = i->pending_head;
	i->pending_head = p->next;
	if (p->handler) {
	    nhandler++;
	    dns_error_message = i->error_message;
	    p->handler(p->fd,
		(i->status == IP_CACHED) ? &(i->entry) : NULL,
		p->handlerData);
	}
	memset(p, '\0', sizeof(struct _ip_pending));
	safe_free(p);
    }
    i->pending_head = NULL;	/* nuke list */
    debug(14, 10, "ipcache_call_pending: Called %d handlers.\n", nhandler);
}

static void ipcache_call_pending_badname(fd, handler, data)
     int fd;
     IPH handler;
     void *data;
{
    debug(14, 0, "ipcache_call_pending_badname: Bad Name: Calling handler with NULL result.\n");
    handler(fd, NULL, data);
}

/* free all lines in the list */
static void free_lines(line)
     line_entry *line;
{
    line_entry *tmp;
