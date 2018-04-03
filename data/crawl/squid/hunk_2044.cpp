                         ||
                         (strncasecmp(value, "Kerberos", 8) == 0 &&
                          (value[8] == '\0' || value[8] == ' '))) {
-                    if (request->flags.connectionAuthDisabled()) {
+                    if (request->flags.connection_auth_disabled) {
                         hdr->delAt(pos, connection_auth_blocked);
                         continue;
                     }
-                    request->flags.setMustKeepalive();
-                    if (!request->flags.accelerated() && !request->flags.intercepted()) {
+                    request->flags.must_keepalive = 1;
+                    if (!request->flags.accelerated && !request->flags.intercepted) {
                         httpHeaderPutStrf(hdr, HDR_PROXY_SUPPORT, "Session-Based-Authentication");
                         /*
                           We send "[Proxy-]Connection: Proxy-Support" header to mark
