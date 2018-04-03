 void
 ACLIP::DumpIpListWalkee(acl_ip_data * const & ip, void *state)
 {
+    char tmpbuf[MAX_IPSTRLEN];
     MemBuf mb;
     wordlist **W = static_cast<wordlist **>(state);
     mb.init();
-    mb.Printf("%s", inet_ntoa(ip->addr1));
+    mb.Printf("%s", ip->addr1.NtoA(tmpbuf,MAX_IPSTRLEN));
 
-    if (ip->addr2.s_addr != any_addr.s_addr)
-        mb.Printf("-%s", inet_ntoa(ip->addr2));
+    if (!ip->addr2.IsAnyAddr())
+        mb.Printf("-%s", ip->addr2.NtoA(tmpbuf,MAX_IPSTRLEN));
 
-    if (ip->mask.s_addr != no_addr.s_addr)
-        mb.Printf("/%s", inet_ntoa(ip->mask));
+    if (!ip->mask.IsNoAddr())
+        mb.Printf("/%s", ip->mask.NtoA(tmpbuf,MAX_IPSTRLEN));
 
     wordlistAdd(W, mb.buf);
 
