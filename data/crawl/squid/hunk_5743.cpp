 peerDigestStatsReport(const PeerDigest * pd, StoreEntry * e)
 {
 #define f2s(flag) (pd->flags.flag ? "yes" : "no")
-#define appendTime(tm) storeAppendPrintf(e, "%s\t %10d\t %+d\t %+d\n", \
-    ""#tm, pd->times.tm, \
+#define appendTime(tm) storeAppendPrintf(e, "%s\t %10ld\t %+d\t %+d\n", \
+    ""#tm, (long int)pd->times.tm, \
     saneDiff(pd->times.tm - squid_curtime), \
     saneDiff(pd->times.tm - pd->times.initialized))
 
