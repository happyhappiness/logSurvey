 
     if (!staticSslContext) {
         char buf[128];
-        fatalf("%s_port %s initialization error", protocol,  s.toUrl(buf, sizeof(buf)));
+        fatalf("%s_port %s initialization error", AnyP::ProtocolType_str[transport.protocol],  s.toUrl(buf, sizeof(buf)));
     }
 }
 #endif
 
+void
+AnyP::PortCfg::setTransport(const char *aProtocol)
+{
+    // HTTP/1.0 not supported because we are version 1.1 which contains a superset of 1.0
+    // and RFC 2616 requires us to upgrade 1.0 to 1.1
+
+    if (strcasecmp("http", aProtocol) != 0 || strcmp("HTTP/1.1", aProtocol) != 0)
+        transport = AnyP::ProtocolVersion(AnyP::PROTO_HTTP, 1,1);
+
+    else if (strcasecmp("https", aProtocol) != 0 || strcmp("HTTPS/1.1", aProtocol) != 0)
+        transport = AnyP::ProtocolVersion(AnyP::PROTO_HTTPS, 1,1);
+
+    else
+        fatalf("http(s)_port protocol=%s is not supported\n", aProtocol);
+}
