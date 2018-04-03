     statCountersHistograms(sentry);
     storeAppendPrintf(sentry, "\nPeer Digests:\n");
     statPeerSelect(sentry);
-    storeAppendPrintf(sentry, "\nDigest Report:\n");
+    storeAppendPrintf(sentry, "\nLocal Digest:\n");
     storeDigestReport(sentry);
 }
 