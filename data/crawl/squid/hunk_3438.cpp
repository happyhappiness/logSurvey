     if (p->options.mcast_responder)
         storeAppendPrintf(sentry, " multicast-responder");
 
+#if PEER_MULTICAST_SIBLINGS
+    if (p->options.mcast_siblings)
+        storeAppendPrintf(sentry, " multicast-siblings");
+#endif
+
     if (p->weight != 1)
         storeAppendPrintf(sentry, " weight=%d", p->weight);
 
