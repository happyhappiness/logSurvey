-/* $Id: send-announce.cc,v 1.4 1996/03/27 01:46:18 wessels Exp $ */
+/* $Id: send-announce.cc,v 1.5 1996/04/09 18:18:50 wessels Exp $ */
 
-#include "config.h"
+/*
+ * DEBUG: Section 27		send-announce
+ */
 
-#include <stdio.h>
-#include <stdlib.h>
-#include <unistd.h>
-#include <string.h>
-#include <sys/types.h>
-#include <sys/socket.h>
-#include <netinet/in.h>
-#include <arpa/inet.h>
-#include <netdb.h>
+#include "squid.h"
 
-#include "util.h"
 
-
-char *databuf = NULL;
-int quiet = 0;
-int debug = 0;
-char *announce_to_host = "sd.cache.nlanr.net";
-int announce_to_port = 3131;
-
-int http_port = CACHE_HTTP_PORT;
-int icp_port = CACHE_ICP_PORT;
-
-
-int read_config(fname)
-     char *fname;
-{
-    FILE *fp = NULL;
-    char buf[BUFSIZ];
-    char munge[BUFSIZ];
-    char *t = NULL;
-    char *tag = NULL;
-    char *w_space = " \t\n";
-
-    if ((fp = fopen(fname, "r")) == (FILE *) NULL)
-	return 0;
-
-    while (fgets(buf, BUFSIZ, fp)) {
-	if ((t = strchr(buf, '#')))
-	    *t = '\0';
-	if (buf[0] == '\0')
-	    continue;
-	strcpy(munge, buf);
-	if ((tag = strtok(munge, w_space)) == NULL)
-	    continue;
-	if (!strcasecmp(tag, "cache_announce")) {
-	    if ((t = strtok(NULL, w_space)) == NULL)
-		exit(0);
-	    if (strcasecmp(t, "on"))
-		exit(0);
-	} else if (!strcasecmp(tag, "announce_to")) {
-	    if ((t = strtok(NULL, w_space)) == NULL)
-		continue;
-	    announce_to_host = xstrdup(t);
-	    if ((t = strchr(announce_to_host, ':'))) {
-		announce_to_port = atoi(t + 1);
-		*t = '\0';
-	    }
-	} else if (!strncasecmp(tag, "announce_", 9)) {
-	    strcat(databuf, buf);
-	} else if (!strcasecmp(tag, "ascii_port")) {
-	    if ((t = strtok(NULL, w_space)))
-		http_port = atoi(t);
-	} else if (!strcasecmp(tag, "udp_port")) {
-	    if ((t = strtok(NULL, w_space)))
-		icp_port = atoi(t);
-	}
-    }
-    fclose(fp);
-    return 1;
-}
-
-
-int send_packet(host, port)
-     char *host;
-     int port;
+void send_announce()
 {
-    char buf[256];
-    time_t t;
-    int s;
-    struct sockaddr_in R;
-    struct sockaddr_in L;
+    static char tbuf[256];
+    static char sndbuf[BUFSIZ];
+    icpUdpData *qdata = NULL;
     struct hostent *hp = NULL;
-
-    sprintf(buf, "cache_version HARVEST/%s\n", SQUID_VERSION);
-    strcat(databuf, buf);
-    sprintf(buf, "Running on %s %d %d\n",
-	getfullhostname(),
-	http_port,
-	icp_port);
-    strcat(databuf, buf);
-    t = time(NULL);
-    sprintf(buf, "generated %d [%s]\n",
-	(int) t, mkhttpdlogtime(&t));
-    strcat(databuf, buf);
-
-    if ((hp = gethostbyname(host)) == NULL) {
-	if (!quiet)
-	    fprintf(stderr, "%s: Unknown host\n", host);
-	return 0;
+    char *host = NULL;
+    char *file = NULL;
+    int port;
+    int fd;
+    int l;
+    int n;
+
+    sndbuf[0] = '\0';
+
+    sprintf(tbuf, "cache_version HARVEST/%s\n", SQUID_VERSION);
+    strcat(sndbuf, tbuf);
+    sprintf(tbuf, "Running on %s %d %d\n",
+	getMyHostname(),
+	getAsciiPortNum(),
+	getUdpPortNum());
+    strcat(sndbuf, tbuf);
+    sprintf(tbuf, "generated %d [%s]\n",
+	(int) cached_curtime,
+	mkhttpdlogtime(&cached_curtime));
+    strcat(sndbuf, tbuf);
+    l = strlen(buf);
+
+    host = getAnnounceHost();
+    port = getAnnouncePort();
+
+    if ((hp = ipcache_gethostbyname(host))== NULL) {
+	debug(27,1,"send_announce: Unknown host '%s'\n", host);
+	return;
     }
-    memset(&L, '\0', sizeof(L));
-    L.sin_family = AF_INET;
-    L.sin_port = 0;
-    L.sin_addr.s_addr = INADDR_ANY;
-
-    if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
-	if (!quiet)
-	    perror("socket");
-	return 0;
-    }
-    if (bind(s, (struct sockaddr *) &L, sizeof(L)) < 0) {
-	if (!quiet)
-	    perror("bind");
-	return 0;
-    }
-    memset(&R, '\0', sizeof(R));
-    R.sin_family = AF_INET;
-    R.sin_port = htons(port);
-    memcpy(&R.sin_addr, hp->h_addr_list[0], 4);
-
-    if (debug) {
-	close(s);
-	printf("This would be sent to %s [%s] port %d\n",
-	    host, inet_ntoa(R.sin_addr), port);
-	puts(databuf);
-	return 0;
-    }
-    if (sendto(s, databuf, strlen(databuf), 0, (struct sockaddr *) &R, sizeof(R)) < 0) {
-	if (!quiet)
-	    perror(host);
-	return 0;
-    }
-    close(s);
-    return 1;
-}
-
-
-main(argc, argv)
-     int argc;
-     char *argv[];
-
-{
-    char config[256];
-    char *s = NULL;
-    int c;
-    extern int optind;
-    while ((c = getopt(argc, argv, "dqh")) != -1) {
-	switch (c) {
-	case 'd':
-	    debug = 1;
-	    break;
-	case 'q':
-	    quiet = 1;
-	    break;
-	case 'h':
-	    fprintf(stderr, "usage: %s -d -q -h [cached.conf]\n",
-		argv[0]);
-	    exit(0);
-	    break;
+    if ((file = getAnnounceFile())) {
+	/* XXX could block */
+	fd = file_open(file, NULL, O_RDONLY);
+	if (fd > -1 && (n = read(fd, sndbuf+l, BUFSIZ-l-1)) > 0);
+		l += n;
+		sndbuf[l] = '\0';
+	} else {
+		debug(27,1,"send_announce: %s: %s\n", file, xstrerror());
 	}
     }
-    argv += (optind - 1);
-    argc -= (optind - 1);
 
-    if (argc > 1) {
-	strcpy(config, argv[1]);
-    } else if ((s = getenv("HARVEST_HOME"))) {
-	sprintf(config, "%s/lib/cached.conf", s);
-    } else {
-	strcpy(config, "/usr/local/harvest/lib/cached.conf");
-    }
-
-    databuf = (char *) xcalloc(8192, 1);
-    if (!read_config(config)) {
-	if (!quiet)
-	    perror(config);
-	exit(1);
-    }
-    send_packet(announce_to_host, announce_to_port);
-    return 0;
+    qdata = (icpUdpData *) xcalloc(1, sizeof(icpUdpData));
+    qdata->msg = xstrdup(sndbuf);
+    qdata->len = strlen(sndbuf)+1;
+    qdata->address.sin_family = AF_INET;
+    qdata->address.sin_port = htons(port);
+    memcpy(&qdata->address.sin_addr, hp->h_addr_list[0], hp->h_length);
+    AppendUdp(qdata);
+    comm_set_select_handler(theUdpConnection,
+	COMM_SELECT_WRITE,
+	(PF) icpUdpReply,
+        (void *) qdata);
 }
