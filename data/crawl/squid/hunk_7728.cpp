-/* $Id: ipcache.cc,v 1.28 1996/05/03 22:56:29 wessels Exp $ */
+/*
+ * $Id: ipcache.cc,v 1.29 1996/07/09 03:41:31 wessels Exp $
+ *
+ * DEBUG: section 14    IP Cache
+ * AUTHOR: Harvest Derived
+ *
+ * SQUID Internet Object Cache  http://www.nlanr.net/Squid/
+ * --------------------------------------------------------
+ *
+ *  Squid is the result of efforts by numerous individuals from the
+ *  Internet community.  Development is led by Duane Wessels of the
+ *  National Laboratory for Applied Network Research and funded by
+ *  the National Science Foundation.
+ *
+ *  This program is free software; you can redistribute it and/or modify
+ *  it under the terms of the GNU General Public License as published by
+ *  the Free Software Foundation; either version 2 of the License, or
+ *  (at your option) any later version.
+ *  
+ *  This program is distributed in the hope that it will be useful,
+ *  but WITHOUT ANY WARRANTY; without even the implied warranty of
+ *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ *  GNU General Public License for more details.
+ *  
+ *  You should have received a copy of the GNU General Public License
+ *  along with this program; if not, write to the Free Software
+ *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
+ *  
+ */
 
 /*
- * DEBUG: Section 14          ipcache: IP Cache
+ * Copyright (c) 1994, 1995.  All rights reserved.
+ *  
+ *   The Harvest software was developed by the Internet Research Task
+ *   Force Research Group on Resource Discovery (IRTF-RD):
+ *  
+ *         Mic Bowman of Transarc Corporation.
+ *         Peter Danzig of the University of Southern California.
+ *         Darren R. Hardy of the University of Colorado at Boulder.
+ *         Udi Manber of the University of Arizona.
+ *         Michael F. Schwartz of the University of Colorado at Boulder.
+ *         Duane Wessels of the University of Colorado at Boulder.
+ *  
+ *   This copyright notice applies to software in the Harvest
+ *   ``src/'' directory only.  Users should consult the individual
+ *   copyright notices in the ``components/'' subdirectories for
+ *   copyright information about other software bundled with the
+ *   Harvest source code distribution.
+ *  
+ * TERMS OF USE
+ *   
+ *   The Harvest software may be used and re-distributed without
+ *   charge, provided that the software origin and research team are
+ *   cited in any use of the system.  Most commonly this is
+ *   accomplished by including a link to the Harvest Home Page
+ *   (http://harvest.cs.colorado.edu/) from the query page of any
+ *   Broker you deploy, as well as in the query result pages.  These
+ *   links are generated automatically by the standard Broker
+ *   software distribution.
+ *   
+ *   The Harvest software is provided ``as is'', without express or
+ *   implied warranty, and with no support nor obligation to assist
+ *   in its use, correction, modification or enhancement.  We assume
+ *   no liability with respect to the infringement of copyrights,
+ *   trade secrets, or any patents, and are not responsible for
+ *   consequential damages.  Proper use of the Harvest software is
+ *   entirely the responsibility of the user.
+ *  
+ * DERIVATIVE WORKS
+ *  
+ *   Users may make derivative works from the Harvest software, subject 
+ *   to the following constraints:
+ *  
+ *     - You must include the above copyright notice and these 
+ *       accompanying paragraphs in all forms of derivative works, 
+ *       and any documentation and other materials related to such 
+ *       distribution and use acknowledge that the software was 
+ *       developed at the above institutions.
+ *  
+ *     - You must notify IRTF-RD regarding your distribution of 
+ *       the derivative work.
+ *  
+ *     - You must clearly notify users that your are distributing 
+ *       a modified version and not the original Harvest software.
+ *  
+ *     - Any derivative product is also subject to these copyright 
+ *       and use restrictions.
+ *  
+ *   Note that the Harvest software is NOT in the public domain.  We
+ *   retain copyright, as specified above.
+ *  
+ * HISTORY OF FREE SOFTWARE STATUS
+ *  
+ *   Originally we required sites to license the software in cases
+ *   where they were going to build commercial products/services
+ *   around Harvest.  In June 1995 we changed this policy.  We now
+ *   allow people to use the core Harvest software (the code found in
+ *   the Harvest ``src/'' directory) for free.  We made this change
+ *   in the interest of encouraging the widest possible deployment of
+ *   the technology.  The Harvest software is really a reference
+ *   implementation of a set of protocols and formats, some of which
+ *   we intend to standardize.  We encourage commercial
+ *   re-implementations of code complying to this set of standards.  
  */
 
 #include "squid.h"
 
-
 #define MAX_LINELEN (4096)
-char ipcache_status_char _PARAMS((ipcache_entry *));
-int ipcache_hash_entry_count();
 
 #define MAX_IP		 1024	/* Maximum cached IP */
-#define IP_LOW_WATER       70
-#define IP_HIGH_WATER      90
+#define IP_LOW_WATER       90
+#define IP_HIGH_WATER      95
 #define MAX_HOST_NAME	  256
-#define IP_INBUF	 4096
+#define IP_INBUF_SZ	 4096
 
-long ipcache_low = 180;
-long ipcache_high = 200;
-
-typedef struct _ip_pending {
+struct _ip_pending {
     int fd;
     IPH handler;
-    void *data;
+    void *handlerData;
     struct _ip_pending *next;
-} IpPending;
-
+};
 
-typedef struct _ipcache_list {
-    ipcache_entry *entry;
-    struct _ipcache_list *next;
-} ipcache_list;
+#define DNS_FLAG_ALIVE		0x01
+#define DNS_FLAG_BUSY		0x02
+#define DNS_FLAG_CLOSING	0x04
 
-
-typedef struct _dnsserver_entry {
+typedef struct _dnsserver {
     int id;
-    int alive;
+    int flags;
     int inpipe;
     int outpipe;
-    int pending_count;		/* counter of outstanding request */
-    long lastcall;
-    long answer;
+    time_t lastcall;
+    time_t answer;
     unsigned int offset;
     unsigned int size;
     char *ip_inbuf;
-    /* global ipcache_entry list for pending entry */
-    ipcache_list *global_pending;
-    ipcache_list *global_pending_tail;
-} dnsserver_entry;
+    struct timeval dispatch_time;
+    ipcache_entry *ip_entry;
+} dnsserver_t;
+
+static struct {
+    int requests;
+    int hits;
+    int misses;
+    int pending_hits;
+    int negative_hits;
+    int dnsserver_requests;
+    int dnsserver_replies;
+    int errors;
+    int avg_svc_time;
+    int ghbn_calls;		/* # calls to blocking gethostbyname() */
+    int dnsserver_hist[DefaultDnsChildrenMax];
+} IpcacheStats;
 
 typedef struct _line_entry {
     char *line;
     struct _line_entry *next;
 } line_entry;
 
-static dnsserver_entry **dns_child_table = NULL;
-static int last_dns_dispatched = 2;
+struct dnsQueueData {
+    struct dnsQueueData *next;
+    ipcache_entry *ip_entry;
+};
+
+static int ipcache_testname _PARAMS((void));
+static dnsserver_t *dnsGetFirstAvailable _PARAMS((void));
+static int ipcache_compareLastRef _PARAMS((ipcache_entry **, ipcache_entry **));
+static int ipcache_create_dnsserver _PARAMS((char *command));
+static int ipcache_dnsHandleRead _PARAMS((int, dnsserver_t *));
+static int ipcache_parsebuffer _PARAMS((char *buf, unsigned int offset, dnsserver_t *));
+static int ipcache_purgelru _PARAMS((void));
+static void ipcache_release _PARAMS((ipcache_entry *));
+static ipcache_entry *ipcache_GetFirst _PARAMS((void));
+static ipcache_entry *ipcache_GetNext _PARAMS((void));
+static ipcache_entry *ipcache_create _PARAMS((void));
+static void free_lines _PARAMS((line_entry *));
+static void ipcache_add_to_hash _PARAMS((ipcache_entry *));
+static void ipcache_call_pending _PARAMS((ipcache_entry *));
+static void ipcache_call_pending_badname _PARAMS((int fd, IPH handler, void *));
+static void ipcache_add _PARAMS((char *, ipcache_entry *, struct hostent *, int));
+static ipcache_entry *dnsDequeue _PARAMS(());
+static void dnsEnqueue _PARAMS((ipcache_entry *));
+static void dnsDispatch _PARAMS((dnsserver_t *, ipcache_entry *));
+static int ipcacheHasPending _PARAMS((ipcache_entry *));
+static ipcache_entry *ipcache_get _PARAMS((char *));
+static int dummy_handler _PARAMS((int, struct hostent * hp, void *));
+static int ipcacheExpiredEntry _PARAMS((ipcache_entry *));
+static void ipcacheAddPending _PARAMS((ipcache_entry *, int fd, IPH, void *));
+
+static dnsserver_t **dns_child_table = NULL;
 static struct hostent *static_result = NULL;
-static int dns_child_alive = 0;
-
+static int NDnsServersAlloc = 0;
+static struct dnsQueueData *dnsQueueHead = NULL;
+static struct dnsQueueData **dnsQueueTailP = &dnsQueueHead;
+static HashID ip_table = 0;
 char *dns_error_message = NULL;	/* possible error message */
-HashID ip_table = 0;
-
-extern int do_dns_test;
-extern int getMaxFD();
-extern int getDnsChildren();
-extern void fatal_dump _PARAMS((char *));
-extern int file_update_open _PARAMS((int, char *));
+long ipcache_low = 180;
+long ipcache_high = 200;
 
-void update_dns_child_alive()
+static char ipcache_status_char[] =
 {
-    int i;
-    int N = getDnsChildren();
-
-    dns_child_alive = 0;
-    for (i = 0; i < N; ++i) {
-	if (dns_child_table[i]->alive) {
-	    dns_child_alive = 1;
-	    break;
-	}
-    }
-}
+    'C',
+    'N',
+    'P',
+    'D'
+};
 
-int ipcache_testname()
+static int ipcache_testname()
 {
     wordlist *w = NULL;
     debug(14, 1, "Performing DNS Tests...\n");
     if ((w = getDnsTestnameList()) == NULL)
 	return 1;
     for (; w; w = w->next) {
+	IpcacheStats.ghbn_calls++;
 	if (gethostbyname(w->key) != NULL)
 	    return 1;
     }
     return 0;
 }
 
-
-/*
- * open a UNIX domain socket for rendevouing with dnsservers
- */
-int ipcache_create_dnsserver(command)
+/* TCP SOCKET VERSION */
+static int ipcache_create_dnsserver(command)
      char *command;
 {
     int pid;
-    struct sockaddr_un addr;
-    static int n_dnsserver = 0;
-    char *socketname = NULL;
-    int cfd;			/* socket for child (dnsserver) */
-    int sfd;			/* socket for server (squid) */
+    u_short port;
+    struct sockaddr_in S;
+    int cfd;
+    int sfd;
+    int len;
     int fd;
 
-    if ((cfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
-	debug(14, 0, "ipcache_create_dnsserver: socket: %s\n", xstrerror());
+    cfd = comm_open(COMM_NOCLOEXEC,
+	local_addr,
+	0,
+	"socket to dnsserver");
+    if (cfd == COMM_ERROR) {
+	debug(14, 0, "ipcache_create_dnsserver: Failed to create dnsserver\n");
 	return -1;
     }
-    fdstat_open(cfd, Socket);
-    fd_note(cfd, "socket to dnsserver");
-    memset(&addr, '\0', sizeof(addr));
-    addr.sun_family = AF_UNIX;
-    socketname = tempnam(NULL, "dns");
-    /* sprintf(socketname, "dns/dns%d.%d", (int) getpid(), n_dnsserver++); */
-    strcpy(addr.sun_path, socketname);
-    debug(14, 4, "ipcache_create_dnsserver: path is %s\n", addr.sun_path);
-
-    if (bind(cfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
-	close(cfd);
-	debug(14, 0, "ipcache_create_dnsserver: bind: %s\n", xstrerror());
-	xfree(socketname);
+    len = sizeof(S);
+    memset(&S, '\0', len);
+    if (getsockname(cfd, (struct sockaddr *) &S, &len) < 0) {
+	debug(14, 0, "ipcache_create_dnsserver: getsockname: %s\n", xstrerror());
+	comm_close(cfd);
 	return -1;
     }
+    port = ntohs(S.sin_port);
     debug(14, 4, "ipcache_create_dnsserver: bind to local host.\n");
     listen(cfd, 1);
-
     if ((pid = fork()) < 0) {
 	debug(14, 0, "ipcache_create_dnsserver: fork: %s\n", xstrerror());
-	close(cfd);
-	xfree(socketname);
+	comm_close(cfd);
 	return -1;
     }
     if (pid > 0) {		/* parent */
-	close(cfd);		/* close shared socket with child */
-
+	comm_close(cfd);	/* close shared socket with child */
 	/* open new socket for parent process */
-	if ((sfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
-	    debug(14, 0, "ipcache_create_dnsserver: socket: %s\n", xstrerror());
-	    xfree(socketname);
+	sfd = comm_open(0, local_addr, 0, NULL);	/* blocking! */
+	if (sfd == COMM_ERROR)
 	    return -1;
-	}
-	fcntl(sfd, F_SETFD, 1);	/* set close-on-exec */
-	memset(&addr, '\0', sizeof(addr));
-	addr.sun_family = AF_UNIX;
-	strcpy(addr.sun_path, socketname);
-	xfree(socketname);
-	if (connect(sfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
-	    close(sfd);
-	    debug(14, 0, "ipcache_create_dnsserver: connect: %s\n", xstrerror());
+	if (comm_connect(sfd, localhost, port) == COMM_ERROR) {
+	    comm_close(sfd);
 	    return -1;
 	}
-	debug(14, 4, "ipcache_create_dnsserver: FD %d connected to %s #%d.\n",
-	    sfd, command, n_dnsserver);
+	comm_set_fd_lifetime(sfd, -1);
 	return sfd;
     }
     /* child */
 
-    /* give up extra priviliges */
-    no_suid();
-
-    /* setup filedescriptors */
+    no_suid();			/* give up extra priviliges */
     dup2(cfd, 3);
-    for (fd = getMaxFD(); fd > 3; fd--) {
-	(void) close(fd);
-    }
-
-    execlp(command, "(dnsserver)", "-p", socketname, NULL);
+    for (fd = FD_SETSIZE; fd > 3; fd--)
+	close(fd);
+    execlp(command, "(dnsserver)", "-t", NULL);
     debug(14, 0, "ipcache_create_dnsserver: %s: %s\n", command, xstrerror());
     _exit(1);
-    return (0);			/* NOTREACHED */
+    return 0;
 }
 
-
 /* removes the given ipcache entry */
-int ipcache_release(e)
-     ipcache_entry *e;
+static void ipcache_release(i)
+     ipcache_entry *i;
 {
     ipcache_entry *result = 0;
-    int i;
+    hash_link *table_entry = NULL;
+    int k;
 
-    debug(14, 5, "ipcache_release: ipcache_count before: %d \n", meta_data.ipcache_count);
-
-    if (e != NULL && ip_table) {	/* sometimes called with NULL e */
-	hash_link *table_entry = hash_lookup(ip_table, e->name);
-	if (table_entry) {
-	    result = (ipcache_entry *) table_entry;
-	    debug(14, 5, "HASH table count before delete: %d\n", ipcache_hash_entry_count());
-	    if (hash_remove_link(ip_table, table_entry)) {
-		debug(14, 3, "ipcache_release: Cannot delete '%s' from hash table %d\n", e->name, ip_table);
-	    }
-	    debug(14, 5, "HASH table count after delete: %d\n", ipcache_hash_entry_count());
-	    if (result) {
-		if (result->status == PENDING) {
-		    debug(14, 1, "ipcache_release: Try to release entry with PENDING status. ignored.\n");
-		    debug(14, 5, "ipcache_release: ipcache_count: %d \n", meta_data.ipcache_count);
-		    return -1;
-		}
-		if (result->status == CACHED) {
-		    if (result->addr_count)
-			for (i = 0; i < (int) result->addr_count; i++)
-			    safe_free(result->entry.h_addr_list[i]);
-		    if (result->entry.h_addr_list)
-			safe_free(result->entry.h_addr_list);
-		    if (result->alias_count)
-			for (i = 0; i < (int) result->alias_count; i++)
-			    safe_free(result->entry.h_aliases[i]);
-		    if (result->entry.h_aliases)
-			safe_free(result->entry.h_aliases);
-		    safe_free(result->entry.h_name);
-		    debug(14, 5, "ipcache_release: Released IP cached record for '%s'.\n", e->name);
-		}
-		/* XXX: we're having mem mgmt problems; zero, then free */
-		safe_free(result->name);
-		memset(result, '\0', sizeof(ipcache_entry));
-		safe_free(result);
-	    }
-	    --meta_data.ipcache_count;
-	    debug(14, 5, "ipcache_release: ipcache_count when return: %d \n", meta_data.ipcache_count);
-	    return meta_data.ipcache_count;
-	}
+    if ((table_entry = hash_lookup(ip_table, i->name)) == NULL) {
+	debug(14, 0, "ipcache_release: Could not find key '%s'\n", i->name);
+	return;
+    }
+    result = (ipcache_entry *) table_entry;
+    if (i != result)
+	fatal_dump("ipcache_release: expected i == result!");
+    if (i->status == IP_PENDING) {
+	debug(14, 1, "ipcache_release: Someone called on a PENDING entry\n");
+	return;
+    }
+    if (i->status == IP_DISPATCHED) {
+	debug(14, 1, "ipcache_release: Someone called on a DISPATCHED entry\n");
+	return;
     }
-    debug(14, 3, "ipcache_release: can't delete entry\n");
-    return -1;			/* can't delete entry */
+    if (hash_remove_link(ip_table, table_entry)) {
+	debug(14, 0, "ipcache_release: hash_remove_link() failed for '%s'\n",
+	    result->name);
+	return;
+    }
+    if (result->status == IP_CACHED) {
+	for (k = 0; k < (int) result->addr_count; k++)
+	    safe_free(result->entry.h_addr_list[k]);
+	safe_free(result->entry.h_addr_list);
+	for (k = 0; k < (int) result->alias_count; k++)
+	    safe_free(result->entry.h_aliases[k]);
+	if (result->entry.h_aliases)
+	    safe_free(result->entry.h_aliases);
+	safe_free(result->entry.h_name);
+	debug(14, 5, "ipcache_release: Released IP cached record for '%s'.\n",
+	    result->name);
+    }
+    safe_free(result->name);
+    safe_free(result->error_message);
+    memset(result, '\0', sizeof(ipcache_entry));
+    safe_free(result);
+    --meta_data.ipcache_count;
+    return;
 }
 
 /* return match for given name */
-ipcache_entry *ipcache_get(name)
+static ipcache_entry *ipcache_get(name)
      char *name;
 {
     hash_link *e;
-    static ipcache_entry *result;
+    static ipcache_entry *i;
 
-    result = NULL;
+    i = NULL;
     if (ip_table) {
 	if ((e = hash_lookup(ip_table, name)) != NULL)
-	    result = (ipcache_entry *) e;
-    }
-    if (result == NULL)
-	return NULL;
-
-    if (((result->timestamp + result->ttl) < squid_curtime) &&
-	(result->status != PENDING)) {	/* expired? */
-	ipcache_release(result);
-	return NULL;
+	    i = (ipcache_entry *) e;
     }
-    return result;
+    return i;
 }
 
-
 /* get the first ip entry in the storage */
-ipcache_entry *ipcache_GetFirst()
+static ipcache_entry *ipcache_GetFirst()
 {
-    static hash_link *entryPtr;
-
-    if ((!ip_table) || ((entryPtr = hash_first(ip_table)) == NULL))
-	return NULL;
-    return ((ipcache_entry *) entryPtr);
+    return (ipcache_entry *) hash_first(ip_table);
 }
 
-
 /* get the next ip entry in the storage for a given search pointer */
-ipcache_entry *ipcache_GetNext()
+static ipcache_entry *ipcache_GetNext()
 {
-    static hash_link *entryPtr;
-
-    if ((!ip_table) || ((entryPtr = hash_next(ip_table)) == NULL))
-	return NULL;
-    return ((ipcache_entry *) entryPtr);
+    return (ipcache_entry *) hash_next(ip_table);
 }
 
-int ipcache_compareLastRef(e1, e2)
+static int ipcache_compareLastRef(e1, e2)
      ipcache_entry **e1, **e2;
 {
     if (!e1 || !e2)
 	fatal_dump(NULL);
-
     if ((*e1)->lastref > (*e2)->lastref)
 	return (1);
-
     if ((*e1)->lastref < (*e2)->lastref)
 	return (-1);
-
     return (0);
 }
 
-
+static int ipcacheExpiredEntry(i)
+     ipcache_entry *i;
+{
+    if (i->lock)
+	return 0;
+    if (i->status == IP_PENDING)
+	return 0;
+    if (i->status == IP_DISPATCHED)
+	return 0;
+    if (i->ttl + i->lastref > squid_curtime)
+	return 0;
+    return 1;
+}
 
 /* finds the LRU and deletes */
-int ipcache_purgelru()
+static int ipcache_purgelru()
 {
-    ipcache_entry *e;
+    ipcache_entry *i = NULL;
     int local_ip_count = 0;
     int local_ip_notpending_count = 0;
     int removed = 0;
-    int i;
-    ipcache_entry **LRU_list;
+    int k;
+    ipcache_entry **LRU_list = NULL;
     int LRU_list_count = 0;
     int LRU_cur_size = meta_data.ipcache_count;
 
-    LRU_list = (ipcache_entry **) xcalloc(LRU_cur_size, sizeof(ipcache_entry *));
+    LRU_list = xcalloc(LRU_cur_size, sizeof(ipcache_entry *));
 
-    e = NULL;
-
-    for (e = ipcache_GetFirst(); e; e = ipcache_GetNext()) {
+    for (i = ipcache_GetFirst(); i; i = ipcache_GetNext()) {
+	if (ipcacheExpiredEntry(i)) {
+	    ipcache_release(i);
+	    removed++;
+	    continue;
+	}
 	local_ip_count++;
 
 	if (LRU_list_count >= LRU_cur_size) {
 	    /* have to realloc  */
 	    LRU_cur_size += 16;
 	    debug(14, 3, "ipcache_purgelru: Have to grow LRU_list to %d. This shouldn't happen.\n",
 		LRU_cur_size);
-	    LRU_list = (ipcache_entry **) xrealloc((char *) LRU_list,
+	    LRU_list = xrealloc((char *) LRU_list,
 		LRU_cur_size * sizeof(ipcache_entry *));
 	}
-	if ((e->status != PENDING) && (e->pending_head == NULL)) {
-	    local_ip_notpending_count++;
-	    LRU_list[LRU_list_count++] = e;
-	}
+	if (i->status == IP_PENDING)
+	    continue;
+	if (i->status == IP_DISPATCHED)
+	    continue;
+	if (i->lock)
+	    continue;
+	local_ip_notpending_count++;
+	LRU_list[LRU_list_count++] = i;
     }
 
     debug(14, 3, "ipcache_purgelru: ipcache_count: %5d\n", meta_data.ipcache_count);
     debug(14, 3, "                  actual count : %5d\n", local_ip_count);
-    debug(14, 3, "                  high W mark  : %5d\n", ipcache_high);
-    debug(14, 3, "                  low  W mark  : %5d\n", ipcache_low);
-    debug(14, 3, "                  not pending  : %5d\n", local_ip_notpending_count);
-    debug(14, 3, "              LRU candidated   : %5d\n", LRU_list_count);
+    debug(14, 3, "                   high W mark : %5d\n", ipcache_high);
+    debug(14, 3, "                   low  W mark : %5d\n", ipcache_low);
+    debug(14, 3, "                   not pending : %5d\n", local_ip_notpending_count);
+    debug(14, 3, "                LRU candidates : %5d\n", LRU_list_count);
 
     /* sort LRU candidate list */
-    qsort((char *) LRU_list, LRU_list_count, sizeof(e), (int (*)(const void *, const void *)) ipcache_compareLastRef);
-
-    for (i = 0; LRU_list[i] && (meta_data.ipcache_count > ipcache_low)
-	&& i < LRU_list_count;
-	++i) {
-	ipcache_release(LRU_list[i]);
+    qsort((char *) LRU_list,
+	LRU_list_count,
+	sizeof(i),
+	(int (*)(const void *, const void *)) ipcache_compareLastRef);
+    for (k = 0; LRU_list[k] && (meta_data.ipcache_count > ipcache_low)
+	&& k < LRU_list_count;
+	++k) {
+	ipcache_release(LRU_list[k]);
 	removed++;
     }
 
-    debug(14, 3, "                   removed      : %5d\n", removed);
+    debug(14, 3, "                       removed : %5d\n", removed);
     safe_free(LRU_list);
     return (removed > 0) ? 0 : -1;
 }
 
 
 /* create blank ipcache_entry */
-ipcache_entry *ipcache_create()
+static ipcache_entry *ipcache_create()
 {
-    static ipcache_entry *ipe;
     static ipcache_entry *new;
-    debug(14, 5, "ipcache_create: when enter. ipcache_count == %d\n", meta_data.ipcache_count);
 
     if (meta_data.ipcache_count > ipcache_high) {
-	if (ipcache_purgelru() < 0) {
-	    debug(14, 1, "ipcache_create: Cannot release needed IP entry via LRU: %d > %d, removing first entry...\n", meta_data.ipcache_count, MAX_IP);
-	    ipe = ipcache_GetFirst();
-	    if (!ipe) {
-		debug(14, 1, "ipcache_create: First entry is a null pointer ???\n");
-		/* have to let it grow beyond limit here */
-	    } else if (ipe && ipe->status != PENDING) {
-		ipcache_release(ipe);
-	    } else {
-		debug(14, 1, "ipcache_create: First entry is also PENDING entry.\n");
-		/* have to let it grow beyond limit here */
-	    }
-	}
+	if (ipcache_purgelru() < 0)
+	    debug(14, 0, "HELP!! IP Cache is overflowing!\n");
     }
     meta_data.ipcache_count++;
-    debug(14, 5, "ipcache_create: before return. ipcache_count == %d\n", meta_data.ipcache_count);
-    new = (ipcache_entry *) xcalloc(1, sizeof(ipcache_entry));
+    new = xcalloc(1, sizeof(ipcache_entry));
     /* set default to 4, in case parser fail to get token $h_length from
      * dnsserver. */
     new->entry.h_length = 4;
     return new;
 
 }
 
-void ipcache_add_to_hash(e)
-     ipcache_entry *e;
+static void ipcache_add_to_hash(i)
+     ipcache_entry *i;
 {
-    if (hash_join(ip_table, (hash_link *) e)) {
+    if (hash_join(ip_table, (hash_link *) i)) {
 	debug(14, 1, "ipcache_add_to_hash: Cannot add %s (%p) to hash table %d.\n",
-	    e->name, e, ip_table);
+	    i->name, i, ip_table);
     }
-    debug(14, 5, "ipcache_add_to_hash: name <%s>\n", e->name);
-    debug(14, 5, "                     ipcache_count: %d\n", meta_data.ipcache_count);
+    debug(14, 5, "ipcache_add_to_hash: name <%s>\n", i->name);
 }
 
 
-void ipcache_add(name, e, data, cached)
+static void ipcache_add(name, i, hp, cached)
      char *name;
-     ipcache_entry *e;
-     struct hostent *data;
+     ipcache_entry *i;
+     struct hostent *hp;
      int cached;
 {
-    int addr_count, alias_count, i;
+    int addr_count;
+    int alias_count;
+    int k;
 
+    if (ipcache_get(name))
+	fatal_dump("ipcache_add: somebody adding a duplicate!");
     debug(14, 10, "ipcache_add: Adding name '%s' (%s).\n", name,
 	cached ? "cached" : "not cached");
-
-    e->name = xstrdup(name);
+    i->name = xstrdup(name);
     if (cached) {
-
 	/* count for IPs */
 	addr_count = 0;
-	while ((addr_count < 255) && data->h_addr_list[addr_count])
+	while ((addr_count < 255) && hp->h_addr_list[addr_count])
 	    ++addr_count;
 
-	e->addr_count = addr_count;
+	i->addr_count = addr_count;
 
 	/* count for Alias */
 	alias_count = 0;
-	if (data->h_aliases)
-	    while ((alias_count < 255) && data->h_aliases[alias_count])
+	if (hp->h_aliases)
+	    while ((alias_count < 255) && hp->h_aliases[alias_count])
 		++alias_count;
 
-	e->alias_count = alias_count;
+	i->alias_count = alias_count;
 
 	/* copy ip addresses information */
-	e->entry.h_addr_list = (char **) xcalloc(addr_count + 1, sizeof(char *));
-	for (i = 0; i < addr_count; i++) {
-	    e->entry.h_addr_list[i] = (char *) xcalloc(1, data->h_length);
-	    memcpy(e->entry.h_addr_list[i], data->h_addr_list[i], data->h_length);
+	i->entry.h_addr_list = xcalloc(addr_count + 1, sizeof(char *));
+	for (k = 0; k < addr_count; k++) {
+	    i->entry.h_addr_list[k] = xcalloc(1, hp->h_length);
+	    xmemcpy(i->entry.h_addr_list[k], hp->h_addr_list[k], hp->h_length);
 	}
 
 	if (alias_count) {
 	    /* copy aliases information */
-	    e->entry.h_aliases = (char **) xcalloc(alias_count + 1, sizeof(char *));
-	    for (i = 0; i < alias_count; i++) {
-		e->entry.h_aliases[i] = (char *) xcalloc(1, strlen(data->h_aliases[i]) + 1);
-		strcpy(e->entry.h_aliases[i], data->h_aliases[i]);
+	    i->entry.h_aliases = xcalloc(alias_count + 1, sizeof(char *));
+	    for (k = 0; k < alias_count; k++) {
+		i->entry.h_aliases[k] = xcalloc(1, strlen(hp->h_aliases[k]) + 1);
+		strcpy(i->entry.h_aliases[k], hp->h_aliases[k]);
 	    }
 	}
-	e->entry.h_length = data->h_length;
-	e->entry.h_name = xstrdup(data->h_name);
-	e->lastref = e->timestamp = squid_curtime;
-	e->status = CACHED;
-	e->ttl = DnsPositiveTtl;
+	i->entry.h_length = hp->h_length;
+	i->entry.h_name = xstrdup(hp->h_name);
+	i->lastref = i->timestamp = squid_curtime;
+	i->status = IP_CACHED;
+	i->ttl = DnsPositiveTtl;
     } else {
-	e->lastref = e->timestamp = squid_curtime;
-	e->status = NEGATIVE_CACHED;
-	e->ttl = getNegativeDNSTTL();
+	i->lastref = i->timestamp = squid_curtime;
+	i->status = IP_NEGATIVE_CACHED;
+	i->ttl = getNegativeDNSTTL();
     }
-
-    ipcache_add_to_hash(e);
+    ipcache_add_to_hash(i);
 }
 
 
-/* exactly the same to ipcache_add, 
- * except it does NOT
- * - create entry->name (assume it's there already.)
- * - add the entry to the hash (it's should be in hash table already.).
- * 
- * Intend to be used by ipcache_cleanup_pendinglist.
- */
-void ipcache_update_content(name, e, data, cached)
-     char *name;
-     ipcache_entry *e;
-     struct hostent *data;
-     int cached;
-{
-    int addr_count, alias_count, i;
-
-    debug(14, 10, "ipcache_update: Updating name '%s' (%s).\n", name,
-	cached ? "cached" : "not cached");
-
-    if (cached) {
-
-	/* count for IPs */
-	addr_count = 0;
-	while ((addr_count < 255) && data->h_addr_list[addr_count])
-	    ++addr_count;
-
-	e->addr_count = addr_count;
-
-	/* count for Alias */
-	alias_count = 0;
-	while ((alias_count < 255) && data->h_aliases[alias_count])
-	    ++alias_count;
-
-	e->alias_count = alias_count;
-
-	/* copy ip addresses information */
-	e->entry.h_addr_list = (char **) xcalloc(addr_count + 1, sizeof(char *));
-	for (i = 0; i < addr_count; i++) {
-	    e->entry.h_addr_list[i] = (char *) xcalloc(1, data->h_length);
-	    memcpy(e->entry.h_addr_list[i], data->h_addr_list[i], data->h_length);
-	}
-
-	/* copy aliases information */
-	e->entry.h_aliases = (char **) xcalloc(alias_count + 1, sizeof(char *));
-	for (i = 0; i < alias_count; i++) {
-	    e->entry.h_aliases[i] = (char *) xcalloc(1, strlen(data->h_aliases[i]) + 1);
-	    strcpy(e->entry.h_aliases[i], data->h_aliases[i]);
-	}
-
-	e->entry.h_length = data->h_length;
-	e->entry.h_name = xstrdup(data->h_name);
-	e->lastref = e->timestamp = squid_curtime;
-	e->status = CACHED;
-	e->ttl = DnsPositiveTtl;
-    } else {
-	e->lastref = e->timestamp = squid_curtime;
-	e->status = NEGATIVE_CACHED;
-	e->ttl = getNegativeDNSTTL();
-    }
-
-}
-
 
 
 /* walks down the pending list, calling handlers */
-void ipcache_call_pending(entry)
-     ipcache_entry *entry;
+static void ipcache_call_pending(i)
+     ipcache_entry *i;
 {
-    IpPending *p;
+    struct _ip_pending *p = NULL;
     int nhandler = 0;
 
-    entry->lastref = squid_curtime;
+    i->lastref = squid_curtime;
 
-    while (entry->pending_head != NULL) {
-	p = entry->pending_head;
-	entry->pending_head = entry->pending_head->next;
-	if (entry->pending_head == NULL)
-	    entry->pending_tail = NULL;
-	if (p->handler != NULL) {
+    while (i->pending_head != NULL) {
+	p = i->pending_head;
+	i->pending_head = p->next;
+	if (p->handler) {
 	    nhandler++;
-	    p->handler(p->fd, (entry->status == CACHED) ?
-		&(entry->entry) : NULL, p->data);
+	    dns_error_message = i->error_message;
+	    p->handler(p->fd,
+		(i->status == IP_CACHED) ? &(i->entry) : NULL,
+		p->handlerData);
 	}
-	memset(p, '\0', sizeof(IpPending));
+	memset(p, '\0', sizeof(struct _ip_pending));
 	safe_free(p);
     }
-    entry->pending_head = entry->pending_tail = NULL;	/* nuke list */
+    i->pending_head = NULL;	/* nuke list */
     debug(14, 10, "ipcache_call_pending: Called %d handlers.\n", nhandler);
 }
 
-void ipcache_call_pending_badname(fd, handler, data)
+static void ipcache_call_pending_badname(fd, handler, data)
      int fd;
      IPH handler;
      void *data;
 {
-    debug(14, 4, "ipcache_call_pending_badname: Bad Name: Calling handler with NULL result.\n");
+    debug(14, 0, "ipcache_call_pending_badname: Bad Name: Calling handler with NULL result.\n");
     handler(fd, NULL, data);
 }
 
-
-/* call when dnsserver is broken, have to switch to blocking mode. 
- * All pending lookup will be looked up by blocking call.
- */
-int ipcache_cleanup_pendinglist(data)
-     dnsserver_entry *data;
-{
-    ipcache_list *p;
-    struct hostent *s_result = NULL;
-
-    while (data->global_pending != NULL) {
-	s_result = gethostbyname(data->global_pending->entry->name);
-	ipcache_update_content(data->global_pending->entry->name,
-	    data->global_pending->entry, s_result, s_result ? 1 : 0);
-	ipcache_call_pending(data->global_pending->entry);
-	p = data->global_pending;
-	data->global_pending = data->global_pending->next;
-	/* XXX: we're having mem mgmt problems; zero, then free */
-	memset(p, '\0', sizeof(ipcache_list));
-	safe_free(p);
-    }
-    data->global_pending = data->global_pending_tail = NULL;	/* nuke */
-    return 0;
-}
-
 /* free all lines in the list */
-void free_lines(line)
+static void free_lines(line)
      line_entry *line;
 {
     line_entry *tmp;
