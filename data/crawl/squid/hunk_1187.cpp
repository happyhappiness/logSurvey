     }
 }
 
+/// parses the protocol= option of the *_port directive, returning parsed value
+/// unsupported option values result in a fatal error message
+/// upper case values required; caller may convert for backward compatibility
+static AnyP::ProtocolVersion
+parsePortProtocol(const SBuf &value)
+{
+    // HTTP/1.0 not supported because we are version 1.1 which contains a superset of 1.0
+    // and RFC 2616 requires us to upgrade 1.0 to 1.1
+    if (value.cmp("HTTP") == 0 || value.cmp("HTTP/1.1") == 0)
+        return AnyP::ProtocolVersion(AnyP::PROTO_HTTP, 1,1);
+
+    if (value.cmp("HTTPS") == 0 || value.cmp("HTTPS/1.1") == 0)
+        return AnyP::ProtocolVersion(AnyP::PROTO_HTTPS, 1,1);
+
+    if (value.cmp("FTP") == 0)
+        return Ftp::ProtocolVersion();
+
+    fatalf("%s directive does not support protocol=" SQUIDSBUFPH "\n", cfg_directive, SQUIDSBUFPRINT(value));
+    return AnyP::ProtocolVersion(); // not reached
+}
+
 static void
 parse_port_option(AnyP::PortCfgPointer &s, char *token)
 {
     /* modes first */
 
     if (strcmp(token, "accel") == 0) {
         if (s->flags.isIntercepted()) {
-            debugs(3, DBG_CRITICAL, "FATAL: http(s)_port: Accelerator mode requires its own port. It cannot be shared with other modes.");
+            debugs(3, DBG_CRITICAL, "FATAL: " << cfg_directive << ": Accelerator mode requires its own port. It cannot be shared with other modes.");
             self_destruct();
         }
         s->flags.accelSurrogate = true;
         s->vhost = true;
     } else if (strcmp(token, "transparent") == 0 || strcmp(token, "intercept") == 0) {
         if (s->flags.accelSurrogate || s->flags.tproxyIntercept) {
-            debugs(3, DBG_CRITICAL, "FATAL: http(s)_port: Intercept mode requires its own interception port. It cannot be shared with other modes.");
+            debugs(3, DBG_CRITICAL, "FATAL: " << cfg_directive << ": Intercept mode requires its own interception port. It cannot be shared with other modes.");
             self_destruct();
         }
         s->flags.natIntercept = true;
