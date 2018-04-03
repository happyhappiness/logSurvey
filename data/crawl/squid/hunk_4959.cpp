 {
     MemBuf mb;
     wordlist **W = static_cast<wordlist **>(state);
-    memBufDefInit(&mb);
-    memBufPrintf(&mb, "%s", inet_ntoa(ip->addr1));
+    mb.init();
+    mb.Printf("%s", inet_ntoa(ip->addr1));
 
     if (ip->addr2.s_addr != any_addr.s_addr)
-        memBufPrintf(&mb, "-%s", inet_ntoa(ip->addr2));
+        mb.Printf("-%s", inet_ntoa(ip->addr2));
 
     if (ip->mask.s_addr != no_addr.s_addr)
-        memBufPrintf(&mb, "/%s", inet_ntoa(ip->mask));
+        mb.Printf("/%s", inet_ntoa(ip->mask));
 
     wordlistAdd(W, mb.buf);
 
-    memBufClean(&mb);
+    mb.clean();
 }
 
 /*
