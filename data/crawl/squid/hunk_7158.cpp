 }
 
 static void
-parseMcastGroupLine(void)
+dump_announceto(void)
 {
-    char *token = NULL;
-    while ((token = strtok(NULL, w_space)))
-	wordlistAdd(&Config.mcast_group_list, token);
+    debug(0,0)("XXX need to fix\n");
 }
 
 static void
-parseHttpPortLine(void)
+parse_announceto(void)
 {
     char *token;
     int i;
-    if (Config.Port.n_http == MAXHTTPPORTS) {
-	sprintf(fatal_str, "Limit of %d HTTP Ports exceeded, redefine MAXHTTPPORTS.\n",
-	    MAXHTTPPORTS);
-	fatal(fatal_str);
+
+    token = strtok(NULL, w_space);
+    if (token == NULL)
+	self_destruct();
+    safe_free(Config.Announce.host);
+    Config.Announce.host = xstrdup(token);
+    if ((token = strchr(Config.Announce.host, ':'))) {
+	*token++ = '\0';
+	if (sscanf(token, "%d", &i) != 1)
+	    Config.Announce.port = i;
     }
-    GetInteger(i);
-    if (i < 0)
-	i = 0;
-    Config.Port.http[Config.Port.n_http++] = (u_short) i;
+    token = strtok(NULL, w_space);
+    if (token == NULL)
+	return;
+    safe_free(Config.Announce.file);
+    Config.Announce.file = xstrdup(token);
 }
 
 static void
-parseIcpPortLine(void)
+dump_appenddomain(void)
 {
-    char *token;
-    int i;
-    GetInteger(i);
-    if (i < 0)
-	i = 0;
-    Config.Port.icp = (u_short) i;
+    debug(0,0)("XXX need to fix\n");
 }
 
 static void
-parseDebugOptionsLine(void)
+parse_appenddomain(void)
 {
-    char *token;
-    token = strtok(NULL, null_string);
-    safe_free(Config.debugOptions);
-    if (token == NULL) {
-	Config.debugOptions = NULL;
-	return;
-    }
-    Config.debugOptions = xstrdup(token);
-}
+    char *token = strtok(NULL, w_space);
 
-static void
-parseVisibleHostnameLine(void)
-{
-    char *token;
-    token = strtok(NULL, w_space);
-    safe_free(Config.visibleHostname);
     if (token == NULL)
 	self_destruct();
-    Config.visibleHostname = xstrdup(token);
+    if (*token != '.')
+	self_destruct();
+    safe_free(Config.appendDomain);
+    Config.appendDomain = xstrdup(token);
+}
+
+static void
+dump_cacheannounce(void)
+{
+    debug(0,0)("XXX need to fix\n");
 }
 
 static void
-parseCacheAnnounceLine(void)
+parse_cacheannounce(void)
 {
     char *token;
     int i;
