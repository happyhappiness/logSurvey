     fatal(fatal_str);
 }
 
+#ifdef IPACL_IN_ADDR
+int ip_acl_match(c, a)
+     struct in_addr c;
+     ip_acl *a;
+{
+    static struct in_addr h;
+
+    h.s_addr = c.s_addr & a->mask.s_addr;
+    if (h.s_addr == a->addr.s_addr)
+	return 1;
+    else
+	return 0;
+}
+
+
+ip_access_type
+ip_access_check(address, list)
+     struct in_addr address;
+     ip_acl *list;
+{
+    static struct in_addr localhost =
+    {0};
+    ip_acl *p;
+    struct in_addr naddr;	/* network byte-order IP addr */
+    static char buf[100];
+
+
+    if (!list)
+	return IP_ALLOW;
+
+    if (!localhost.s_addr)
+	localhost.s_addr = inet_addr("127.0.0.1");
+
+    naddr.s_addr = address.s_addr;
+    if (naddr.s_addr == localhost.s_addr)
+	return IP_ALLOW;
+
+    debug(3, 1, "IP access check using: %s\n", inet_ntoa(naddr));
+
+    for (p = list; p; p = p->next) {
+	sprintf(buf, "%s", inet_ntoa(naddr));
+	sprintf(&buf[strlen(buf)], " vs %s", inet_ntoa(p->addr));
+	sprintf(&buf[strlen(buf)], "/%s\n", inet_ntoa(p->mask));
+	debug(3, 1, "IP access check  %s\n", buf);
+
+	if (ip_acl_match(naddr, p))
+	    return p->access;
+    }
+    return IP_ALLOW;
+}
+
+
+void addToIPACL(list, ip_str, access)
+     ip_acl **list;
+     char *ip_str;
+     ip_access_type access;
+{
+    ip_acl *p, *q;
+    int a1, a2, a3, a4;
+    int m1, m2, m3, m4;
+    struct in_addr lmask;
+    int c;
+
+    if (!ip_str) {
+	return;
+    }
+    if (!(*list)) {
+	/* empty list */
+	*list = (ip_acl *) xcalloc(1, sizeof(ip_acl));
+	(*list)->next = NULL;
+	q = *list;
+    } else {
+	/* find end of list */
+	p = *list;
+	while (p->next)
+	    p = p->next;
+	q = (ip_acl *) xcalloc(1, sizeof(ip_acl));
+	q->next = NULL;
+	p->next = q;
+    }
+
+
+    /* decode ip address */
+    if (!strcasecmp(ip_str, "all")) {
+	a1 = a2 = a3 = a4 = 0;
+	lmask.s_addr = 0;
+    } else {
+	a1 = a2 = a3 = a4 = 0;
+	c = sscanf(ip_str, "%d.%d.%d.%d/%d.%d.%d.%d", &a1, &a2, &a3, &a4,
+	    &m1, &m2, &m3, &m4);
+
+	switch (c) {
+	case 4:
+	    if (a3 == 0 && a4 == 0)
+		lmask.s_addr = 0xffff0000;
+	    else if (a4 == 0)
+		lmask.s_addr = 0xffffff00;
+	    else
+		lmask.s_addr = 0xffffffff;
+	    break;
+
+	case 5:
+	    if (m1 < 0 || m1 > 32) {
+		fprintf(stderr,
+		    "cached.conf error in IP acl line %s (ignored)\n",
+		    ip_str);
+		return;
+	    }
+	    lmask.s_addr = htonl(0xffffffff << (32 - m1));
+	    break;
+
+	case 8:
+	    lmask.s_addr = htonl(m1 * 0x1000000 + m2 * 0x10000 + m3 * 0x100 + m4);
+	    break;
+
+	default:
+	    fprintf(stderr,
+		"cached.conf error in IP acl line %s (ignored)\n", ip_str);
+	    return;
+	}
+    }
+
+    q->access = access;
+    q->addr.s_addr = htonl(a1 * 0x1000000 + a2 * 0x10000 + a3 * 0x100 + a4);
+    q->mask.s_addr = lmask.s_addr;
+}
+#else /* original code using ints */
+
 int ip_acl_match(c1, c2, c3, c4, a1, a2, a3, a4)
      int c1;
      int c2;
