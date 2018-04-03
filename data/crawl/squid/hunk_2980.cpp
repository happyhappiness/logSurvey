 #include "squid.h"
 
-#if USE_ZPH_QOS
-
 #include "ip/QosConfig.h"
 #include "Store.h"
 
-Ip::QosConfig::QosConfig() :
-        tos_local_hit(0),
-        tos_sibling_hit(0),
-        tos_parent_hit(0),
-        preserve_miss_tos(1),
-        preserve_miss_tos_mask(255)
+
+void
+Ip::Qos::getTosFromServer(fde *clientFde, const int server_fd)
+{
+#if USE_QOS_TOS
+    fatal ("Not implemented");
+#endif
+}
+
+void Ip::Qos::getNfmarkFromServer(const fde *clientFde, const fde *servFde, const int server_fd)
+{
+#if USE_QOS_NFMARK
+    fatal ("Not implemented");
+#endif
+}
+
+#if USE_QOS_NFMARK
+int
+Ip::Qos::GetNfMarkCallback(enum nf_conntrack_msg_type type,
+              struct nf_conntrack *ct,
+              void *data)
 {
-    ;
+    fatal ("Not implemented");
+}
+#endif
+
+tos_t
+Ip::Qos::doTosLocalMiss(const int fd, const hier_code hierCode) const
+{
+    fatal ("Not implemented");
+}
+
+int
+Ip::Qos::doNfmarkLocalMiss(const int fd, const hier_code hierCode) const
+{
+    fatal ("Not implemented");
+}
+
+int
+Ip::Qos::doTosLocalHit(const int fd) const
+{
+    fatal ("Not implemented");
+}
+ 
+int
+Ip::Qos::doNfmarkLocalHit(const int fd) const
+{
+    fatal ("Not implemented");
+}
+
+Ip::Qos::Config()
+{
+    fatal ("Not implemented");
+}
+
+Ip::Qos::~Config()
+{
+    fatal ("Not implemented");
 }
 
 void
-Ip::QosConfig::parseConfigLine()
-{
-    // %i honors 0 and 0x prefixes, which are important for things like umask
-    /* parse options ... */
-    char *token;
-    while ( (token = strtok(NULL, w_space)) ) {
-
-        if (strncmp(token, "local-hit=",10) == 0) {
-            sscanf(&token[10], "%i", &tos_local_hit);
-        } else if (strncmp(token, "sibling-hit=",12) == 0) {
-            sscanf(&token[12], "%i", &tos_sibling_hit);
-        } else if (strncmp(token, "parent-hit=",11) == 0) {
-            sscanf(&token[11], "%i", &tos_parent_hit);
-        } else if (strcmp(token, "disable-preserve-miss") == 0) {
-            preserve_miss_tos = 0;
-            preserve_miss_tos_mask = 0;
-        } else if (preserve_miss_tos && strncmp(token, "miss-mask=",10) == 0) {
-            sscanf(&token[10], "%i", &preserve_miss_tos_mask);
-        }
-    }
+Ip::Qos::parseConfigLine()
+{
+    fatal ("Not implemented");
 }
 
 void
-Ip::QosConfig::dumpConfigLine(char *entry, const char *name) const
+Ip::Qos::dumpConfigLine(char *entry, const char *name)
 {
-    ; /* Not needed in stub */
+    fatal ("Not implemented");
 }
 
-#endif /* USE_ZPH_QOS */
+#if !_USE_INLINE_
+#include "Qos.cci"
+#endif
