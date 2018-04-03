 /**** PUBLIC FUNCTIONS ****/
 
 
-void redirectStart(url, fd, handler, data)
-     char *url;
-     int fd;
+void redirectStart(cfd, icpState, handler, data)
+     int cfd;
+     icpStateData *icpState;
      RH handler;
      void *data;
 {
     redirectStateData *r = NULL;
     redirector_t *redirector = NULL;
     if (!handler)
 	fatal_dump("redirectStart: NULL handler");
+    if (!icpState)
+	fatal_dump("redirectStart: NULL icpState");
     if (Config.Program.redirect == NULL) {
 	(*handler) (data, NULL);
 	return;
     }
     r = xcalloc(1, sizeof(redirectStateData));
-    r->fd = fd;
-    r->orig_url = url;
+    r->fd = cfd;
+    r->orig_url = icpState->url;
+    r->client_addr = icpState->log_addr;
+    if (icpState->ident == NULL || *icpState->ident == '\0') {
+	r->client_ident = dash_str;
+    } else {
+	r->client_ident = icpState->ident;
+    }
+    r->method_s = RequestMethodStr[icpState->request->method];
     r->handler = handler;
     r->data = data;
     if ((redirector = GetFirstAvailable()))