 
 #define REQ_SZ 512
 
+static void
+lookup(const char *buf)
+{
+    const struct hostent *result = NULL;
+    int reverse = 0;
+    int ttl = 0;
+    int retry = 0;
+    int i;
+    struct in_addr addr;
+    if (0 == strcmp(buf, "$shutdown"))
+	exit(0);
+    if (0 == strcmp(buf, "$hello")) {
+	printf("$alive\n");
+	return;
+    }
+    /* check if it's already an IP address in text form. */
+    for (;;) {
+	if (safe_inet_addr(buf, &addr)) {
+	    reverse = 1;
+	    result = gethostbyaddr((char *) &addr.s_addr, 4, AF_INET);
+	} else {
+	    result = gethostbyname(buf);
+	}
+	if (NULL != result)
+	    break;
+	if (h_errno != TRY_AGAIN)
+	    break;
+	if (++retry == 3)
+	    break;
+	sleep(1);
+    }
+    if (NULL == result) {
+	if (h_errno == TRY_AGAIN) {
+	    printf("$fail Name Server for domain '%s' is unavailable.\n", buf);
+	} else {
+	    printf("$fail DNS Domain '%s' is invalid: %s.\n",
+		buf, my_h_msgs(h_errno));
+	}
+	return;
+    }
+#if LIBRESOLV_DNS_TTL_HACK
+    /* DNS TTL handling - bne@CareNet.hu
+     * for first try it's a dirty hack, by hacking getanswer
+     * to place the ttl in a global variable */
+    if (_dns_ttl_ > -1)
+	ttl = _dns_ttl_;
+#endif
+    if (reverse) {
+	printf("$name %d %s\n", ttl, result->h_name);
+	return;
+    }
+    printf("$addr %d", ttl);
+    for (i = 0; NULL != result->h_addr_list[i]; i++) {
+	if (32 == i)
+	    break;
+	xmemcpy(&addr, result->h_addr_list[i], sizeof(addr));
+	printf(" %s", inet_ntoa(addr));
+    }
+    printf("\n");
+}
+
+static void
+usage(void)
+{
+    fprintf(stderr, "usage: dnsserver -Dhv -s nameserver\n"
+	"\t-D             Enable resolver RES_DEFNAMES and RES_DNSRCH options\n"
+	"\t-h             Help\n"
+	"\t-v             Version\n"
+	"\t-s nameserver  Specify alternate name server(s).  'nameserver'\n"
+	"\t               must be an IP address, -s option may be repeated\n");
+}
+
 int
 main(int argc, char *argv[])
 {
     char request[512];
-    char msg[1024];
-    const struct hostent *result = NULL;
-    FILE *logfile = NULL;
-    long start;
-    long stop;
     char *t = NULL;
-    char buf[256];
-    int addr_count = 0;
-    int alias_count = 0;
-    int i;
     int c;
     int opt_s = 0;
     extern char *optarg;
