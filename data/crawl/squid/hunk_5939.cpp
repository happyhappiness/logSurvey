     memFree(buf, MEM_4K_BUF);
 #else
     httpReplyReset(reply);
-    httpReplySetHeaders(reply, 1.0, HTTP_BAD_REQUEST, "Bad Request",
+    httpBuildVersion(&version,1,0);
+    httpReplySetHeaders(reply, version, HTTP_BAD_REQUEST, "Bad Request",
 	NULL, -1, squid_curtime, -2);
     storeAppendPrintf(s, "NETDB support not compiled into this Squid cache.\n");
 #endif