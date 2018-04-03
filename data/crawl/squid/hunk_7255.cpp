 
 
 void
-redirectStart(int cfd, icpStateData * icpState, RH * handler, void *data)
+redirectStart(clientHttpRequest * http, RH * handler, void *data)
 {
+    ConnStateData *conn = http->conn;
     redirectStateData *r = NULL;
     redirector_t *redirector = NULL;
-    debug(29, 5, "redirectStart: '%s'\n", icpState->url);
+    if (!http)
+	fatal_dump("redirectStart: NULL clientHttpRequest");
     if (!handler)
 	fatal_dump("redirectStart: NULL handler");
-    if (!icpState)
-	fatal_dump("redirectStart: NULL icpState");
+    debug(29, 5, "redirectStart: '%s'\n", http->url);
     if (Config.Program.redirect == NULL) {
 	handler(data, NULL);
 	return;
     }
     r = xcalloc(1, sizeof(redirectStateData));
-    r->fd = cfd;
-    r->orig_url = xstrdup(icpState->url);
-    r->client_addr = icpState->log_addr;
-    if (icpState->ident.ident == NULL || *icpState->ident.ident == '\0') {
+    r->orig_url = xstrdup(http->url);
+    r->client_addr = conn->log_addr;
+    if (conn->ident.ident == NULL || *conn->ident.ident == '\0') {
 	r->client_ident = dash_str;
     } else {
-	r->client_ident = icpState->ident.ident;
+	r->client_ident = conn->ident.ident;
     }
-    r->method_s = RequestMethodStr[icpState->request->method];
+    r->method_s = RequestMethodStr[http->request->method];
     r->handler = handler;
     r->data = data;
     if ((redirector = GetFirstAvailable()))
