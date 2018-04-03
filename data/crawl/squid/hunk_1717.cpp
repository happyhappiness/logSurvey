     str.Printf("TimeStamp: %s\r\n\r\n", mkrfc1123(squid_curtime));
 
     /* - IP stuff */
-    str.Printf("ClientIP: %s\r\n", src_addr.NtoA(ntoabuf,MAX_IPSTRLEN));
+    str.Printf("ClientIP: %s\r\n", src_addr.toStr(ntoabuf,MAX_IPSTRLEN));
 
     if (request && request->hier.host[0] != '\0') {
         str.Printf("ServerIP: %s\r\n", request->hier.host);
