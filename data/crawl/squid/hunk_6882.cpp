 	    break;
 	}
 	*t = '\0';
-	debug(0, 0) ("asnLoadRead: AS# %d '%s'\n", p->as, s);
+	debug(53, 4) ("asnLoadRead: AS# %d '%s'\n", p->as, s);
+	asndbAddNet(s, p->as);
 	s = t + 1;
 	while (*s && isspace(*s))
 	    s++;
     }
     if (*s) {
 	/* expect more */
-	debug(0, 0) ("asnLoadRead: AS# %d expecting more\n", p->as);
+	debug(53, 6) ("asnLoadRead: AS# %d expecting more\n", p->as);
 	xstrncpy(p->buf, s, p->bufsz);
 	p->offset = strlen(p->buf);
-	debug(0, 0) ("asnLoadRead: p->buf = '%s'\n", p->buf);
+	debug(53, 6) ("asnLoadRead: p->buf = '%s'\n", p->buf);
     } else {
 	p->offset = 0;
     }
     commSetSelect(fd, COMM_SELECT_READ, asnLoadRead, p, Config.Timeout.read);
 }
+
+
+/* initialize the radix tree structure */
+
+void
+asndbInit()
+{
+    extern int max_keylen;
+    max_keylen = 40;
+    rn_init();
+    rn_inithead((void **) &AS_tree_head, 8);
+
+}
+
+/* add a network (addr, mask) to the radix tree, with matching AS
+ * number */
+
+static int
+asndbAddNet(char *as_string, int as_number)
+{
+    rtentry *e = xmalloc(sizeof(rtentry));
+    struct radix_node *rn;
+    char dbg1[32], dbg2[32];
+    intlist **Tail = NULL;
+    intlist *q = NULL;
+    as_info *info = NULL;
+    struct in_addr in_a, in_m;
+    long mask, addr;
+    char *t;
+    int bitl;
+
+    t = index(as_string, '/');
+    if (t == NULL) {
+	debug(53, 3) ("asndbAddNet: failed, no network.\n");
+	return 0;
+    }
+    *t = '\0';
+    addr = inet_addr(as_string);
+    bitl = atoi(t + 1);
+    mask = (1 << bitl) - 1;
+
+    in_a.s_addr = addr;
+    in_m.s_addr = mask;
+    strcpy(dbg1, inet_ntoa(in_a));
+    strcpy(dbg2, inet_ntoa(in_m));
+    addr = ntohl(addr);
+    mask = ntohl(mask);
+    debug(53, 3) ("asndbAddNet: called for %s/%s (%x/%x)\n", dbg1, dbg2, addr, mask);
+    memset(e, '\0', sizeof(rtentry));
+    store_m_int(addr, e->e_addr);
+    store_m_int(mask, e->e_mask);
+    rn = rn_lookup(e->e_addr, e->e_mask, AS_tree_head);
+    if (rn != 0) {
+	debug(53, 3) ("Oops. Found a network with multiple AS numbers!\n");
+	info = ((rtentry *) rn)->e_info;
+	for (Tail = &(info->as_number); *Tail; Tail = &((*Tail)->next));
+	q = xcalloc(1, sizeof(intlist));
+	q->i = as_number;
+	*(Tail) = q;
+	e->e_info = info;
+    } else {
+	q = xcalloc(1, sizeof(intlist));
+	q->i = as_number;
+	/* *(Tail) = q;         */
+	info = xmalloc(sizeof(as_info));
+	info->as_number = q;
+	rn = rn_addroute(e->e_addr, e->e_mask, AS_tree_head, e->e_nodes);
+	rn = rn_match(e->e_addr, AS_tree_head);
+	if (rn == NULL)
+	    fatal_dump("cannot add entry...\n");
+	e->e_info = info;
+
+    }
+    if (rn == 0) {
+	xfree(e);
+	debug(53, 3) ("Could not add entry.\n");
+	return 0;
+    }
+    e->e_info = info;
+    debug(53, 3) ("added successfully.\n");
+    return 1;
+}