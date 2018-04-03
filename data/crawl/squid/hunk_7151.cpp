 	*var = 0;
 }
 
-static void
-dump_pathname_check(char path[])
-{
-    printf("%s", path);
-}
+#define free_onoff free_int
+#define dump_pathname_stat dump_string
+#define free_pathname_stat free_string
 
 static void
-parse_pathname_check(char *path[])
+parse_pathname_stat(char **path)
 {
     struct stat sb;
-
     parse_string(path);
-
     if (stat(*path, &sb) < 0) {
-	debug(50, 1) ("parse_pathname_check: %s: %s\n", *path, xstrerror());
+	debug(50, 1) ("parse_pathname_stat: %s: %s\n", *path, xstrerror());
 	self_destruct();
     }
 }
 
-static void
-dump_proxy(peer * E)
-{
-    debug(0,0)("XXX need to fix\n");
-}
-
-static void
-parse_proxy(peer ** E)
-{
-    char *token;
-    char *t;
-    peer *e;
-    token = strtok(NULL, w_space);
-    if (token == NULL)
-	self_destruct();
-    if (*E) {
-	peerDestroy(*E);
-	*E = NULL;
-    }
-    e = xcalloc(1, sizeof(peer));
-    if ((t = strchr(token, ':'))) {
-	*t++ = '\0';
-	e->http_port = atoi(t);
-    }
-    e->host = xstrdup(token);
-    e->tcp_up = 1;
-    *E = e;
-}
-
-#if USE_PROXY_AUTH
-static void
-dump_proxyauth(void)
-{
-    debug(0,0)("XXX need to fix\n");
-}
-
-static void
-parse_proxyauth(void)
-{
-    char *token;
-    token = strtok(NULL, w_space);
-    if (token == NULL)
-	self_destruct();
-    safe_free(Config.proxyAuth.File);
-    aclDestroyRegexList(Config.proxyAuth.IgnoreDomains);
-    Config.proxyAuth.IgnoreDomains = NULL;
-    Config.proxyAuth.File = xstrdup(token);
-    aclParseRegexList(&Config.proxyAuth.IgnoreDomains, 1);
-}
-#endif /* USE_PROXY_AUTH */
-
-static void
-dump_quickabort(void)
-{
-    debug(0,0)("XXX need to fix\n");
-}
-
-static void
-parse_quickabort(void)
-{
-    char *token;
-    int i;
-    token = strtok(NULL, w_space);
-    if (!strcasecmp(token, "on")) {
-	Config.quickAbort.min = 10 << 10;	/* 10k */
-	Config.quickAbort.pct = 64;	/* 50% */
-	Config.quickAbort.max = 100 << 10;	/* 100k */
-    } else if (!strcasecmp(token, "off")) {
-	Config.quickAbort.min = -1;
-	Config.quickAbort.pct = 0;
-	Config.quickAbort.max = 0;
-    } else {
-	if (sscanf(token, "%d", &i) != 1)
-	    self_destruct();
-	Config.quickAbort.min = i * 1024;
-	GetInteger(i);
-	Config.quickAbort.pct = i * 128 / 100;	/* 128 is full scale */
-	GetInteger(i);
-	Config.quickAbort.max = i * 1024;
-    }
-}
-
 static void
 dump_refreshpattern(void)
 {
