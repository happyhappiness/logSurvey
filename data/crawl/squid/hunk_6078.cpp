     return PEER_SIBLING;
 }
 
+static void
+parse_sockaddr_in_list(sockaddr_in_list ** head)
+{
+    char *token;
+    char *t;
+    char *host = NULL;
+    const struct hostent *hp;
+    int i;
+    sockaddr_in_list *s;
+    while ((token = strtok(NULL, w_space))) {
+	if ((t = strchr(token, ':'))) {
+	    /* host:port */
+	    host = token;
+	    *t = '\0';
+	    i = atoi(t + 1);
+	    if (i <= 0)
+		self_destruct();
+	} else if ((i = atoi(token)) > 0) {
+	    /* port */
+	} else {
+	    self_destruct();
+	}
+	s = xcalloc(1, sizeof(*s));
+	s->s.sin_port = htons(i);
+	if (NULL == host)
+	    s->s.sin_addr = any_addr;
+	else if (1 == safe_inet_addr(host, &s->s.sin_addr))
+	    (void) 0;
+	else if ((hp = gethostbyname(token)))	/* dont use ipcache */
+	    s->s.sin_addr = inaddrFromHostent(hp);
+	else
+	    self_destruct();
+	while (*head)
+	    head = &(*head)->next;
+	*head = s;
+    }
+}
+
+static void
+dump_sockaddr_in_list(StoreEntry * e, const char *n, const sockaddr_in_list * s)
+{
+    while (s) {
+	storeAppendPrintf(e, "%s %s:%d\n",
+	    n,
+	    inet_ntoa(s->s.sin_addr),
+	    ntohs(s->s.sin_port));
+	s = s->next;
+    }
+}
+
+static void
+free_sockaddr_in_list(sockaddr_in_list ** head)
+{
+    sockaddr_in_list *s;
+    while ((s = *head) != NULL) {
+	*head = s->next;
+	xfree(s);
+    }
+}
+
+static int
+check_null_sockaddr_in_list(const sockaddr_in_list * s)
+{
+    return NULL == s;
+}
+
 void
 configFreeMemory(void)
 {
