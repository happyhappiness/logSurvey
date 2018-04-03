 void
 Ip::Intercept::StopTransparency(const char *str)
 {
-    if (transparent_active) {
+    if (transparentActive_) {
         debugs(89, DBG_IMPORTANT, "Stopping full transparency: " << str);
-        transparent_active = 0;
+        transparentActive_ = 0;
     }
 }
 
 void
 Ip::Intercept::StopInterception(const char *str)
 {
-    if (intercept_active) {
+    if (interceptActive_) {
         debugs(89, DBG_IMPORTANT, "Stopping IP interception: " << str);
-        intercept_active = 0;
+        interceptActive_ = 0;
     }
 }
 
-int
-Ip::Intercept::NetfilterInterception(int fd, const Ip::Address &me, Ip::Address &dst, int silent)
+bool
+Ip::Intercept::NetfilterInterception(const Comm::ConnectionPointer &newConn, int silent)
 {
 #if LINUX_NETFILTER
-    struct addrinfo *lookup = NULL;
-
-    dst.GetAddrInfo(lookup,AF_INET);
+    struct sockaddr_in lookup;
+    socklen_t len = sizeof(struct sockaddr_in);
+    newConn->local.GetSockAddr(lookup);
 
     /** \par
      * Try NAT lookup for REDIRECT or DNAT targets. */
-    if ( getsockopt(fd, IPPROTO_IP, SO_ORIGINAL_DST, lookup->ai_addr, &lookup->ai_addrlen) != 0) {
+    if ( getsockopt(newConn->fd, IPPROTO_IP, SO_ORIGINAL_DST, &lookup, &len) != 0) {
         if (!silent) {
-            debugs(89, DBG_IMPORTANT, HERE << " NF getsockopt(SO_ORIGINAL_DST) failed on FD " << fd << ": " << xstrerror());
-            last_reported = squid_curtime;
+            debugs(89, DBG_IMPORTANT, HERE << " NF getsockopt(SO_ORIGINAL_DST) failed on " << newConn << ": " << xstrerror());
+            lastReported_ = squid_curtime;
         }
+        debugs(89, 9, HERE << "address: " << newConn);
+        return false;
     } else {
-        dst = *lookup;
-    }
-
-    Address::FreeAddrInfo(lookup);
-
-    if (me != dst) {
-        debugs(89, 5, HERE << "address NAT: me= " << me << ", dst= " << dst);
-        return 0;
+        newConn->local = lookup;
+        debugs(89, 5, HERE << "address NAT: " << newConn);
+        return true;
     }
-
-    debugs(89, 9, HERE << "address: me= " << me << ", dst= " << dst);
 #endif
-    return -1;
+    return false;
 }
 
-int
-Ip::Intercept::NetfilterTransparent(int fd, const Ip::Address &me, Ip::Address &client, int silent)
+bool
+Ip::Intercept::NetfilterTransparent(const Comm::ConnectionPointer &newConn, int silent)
 {
 #if LINUX_NETFILTER
-
     /* Trust the user configured properly. If not no harm done.
      * We will simply attempt a bind outgoing on our own IP.
      */
-    if (fd_table[fd].flags.transparent) {
-        client.SetPort(0); // allow random outgoing port to prevent address clashes
-        debugs(89, 5, HERE << "address TPROXY: me= " << me << ", client= " << client);
-        return 0;
-    }
-
-    debugs(89, 9, HERE << "address: me= " << me << ", client= " << client);
+    newConn->remote.SetPort(0); // allow random outgoing port to prevent address clashes
+    debugs(89, 5, HERE << "address TPROXY: " << newConn);
+    return true;
+#else
+    return false;
 #endif
-    return -1;
 }
 
-int
-Ip::Intercept::IpfwInterception(int fd, const Ip::Address &me, Ip::Address &dst, int silent)
+bool
+Ip::Intercept::IpfwInterception(const Comm::ConnectionPointer &newConn, int silent)
 {
 #if IPFW_TRANSPARENT
-    struct addrinfo *lookup = NULL;
-
-    dst.GetAddrInfo(lookup,AF_INET);
+    struct sockaddr_storage lookup;
+    socklen_t len = sizeof(struct sockaddr_storage);
+    newConn->local.GetSockAddr(lookup, AF_INET);
 
     /** \par
      * Try lookup for IPFW interception. */
-    if ( getsockname(fd, lookup->ai_addr, &lookup->ai_addrlen) != 0 ) {
+    if ( getsockname(newConn->fd, (struct sockaddr*)&lookup, &len) != 0 ) {
         if ( !silent ) {
             debugs(89, DBG_IMPORTANT, HERE << " IPFW getsockname(...) failed: " << xstrerror());
-            last_reported = squid_curtime;
+            lastReported_ = squid_curtime;
         }
+        debugs(89, 9, HERE << "address: " << newConn);
+        return false;
     } else {
-        dst = *lookup;
-    }
-
-    Address::FreeAddrInfo(lookup);
-
-    if (me != dst) {
-        debugs(89, 5, HERE << "address NAT: me= " << me << ", dst= " << dst);
-        return 0;
+        newConn->local = lookup;
+        debugs(89, 5, HERE << "address NAT: " << newConn);
+        return true;
     }
-
-    debugs(89, 9, HERE << "address: me= " << me << ", dst= " << dst);
 #endif
-    return -1;
+    return false;
 }
 
-int
-Ip::Intercept::IpfInterception(int fd, const Ip::Address &me, Ip::Address &client, Ip::Address &dst, int silent)
+bool
+Ip::Intercept::IpfInterception(const Comm::ConnectionPointer &newConn, int silent)
 {
 #if IPF_TRANSPARENT  /* --enable-ipf-transparent */
 
