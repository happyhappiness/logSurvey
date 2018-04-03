     }
 }
 
+/// parses the protocol= option of the *_port directive, returning parsed value
+/// unsupported option values result in a fatal error message
+static AnyP::ProtocolVersion
+parsePortProtocol(const char *value)
+{
+    // HTTP/1.0 not supported because we are version 1.1 which contains a superset of 1.0
+    // and RFC 2616 requires us to upgrade 1.0 to 1.1
+    if (strcasecmp("http", value) == 0 || strcmp("HTTP/1.1", value) == 0)
+        return AnyP::ProtocolVersion(AnyP::PROTO_HTTP, 1,1);
+
+    if (strcasecmp("https", value) == 0 || strcmp("HTTPS/1.1", value) == 0)
+        return AnyP::ProtocolVersion(AnyP::PROTO_HTTPS, 1,1);
+
+    if (strcasecmp("ftp", value) == 0)
+        return AnyP::ProtocolVersion(AnyP::PROTO_FTP,
+            Ftp::ProtocolVersion().major, Ftp::ProtocolVersion().minor);
+
+    fatalf("%s directive does not support protocol=%s\n", cfg_directive, value);
+    return AnyP::ProtocolVersion(); // not reached
+}
+
 static void
 parse_port_option(AnyP::PortCfgPointer &s, char *token)
 {
