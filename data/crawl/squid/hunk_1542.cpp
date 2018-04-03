     return clientdbEstablished(Filled(checklist)->src_addr, 0) > limit ? 1 : 0;
 }
 
-wordlist *
+SBufList
 ACLMaxConnection::dump() const
 {
+    SBufList sl;
     if (!limit)
-        return NULL;
+        return sl;
 
-    wordlist *W = NULL;
-
-    char buf[32];
-
-    snprintf(buf, sizeof(buf), "%d", limit);
-
-    wordlistAdd(&W, buf);
-
-    return W;
+    SBuf s;
+    s.Printf("%d", limit);
+    sl.push_back(s);
+    return sl;
 }
 
 void
