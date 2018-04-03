     }
 }
 
-wordlist *
+SBufList
 ACLMaxUserIP::dump() const
 {
+    SBufList sl;
     if (!maximum)
-        return NULL;
-
-    wordlist *W = NULL;
-
-    char buf[128];
-
-    snprintf(buf, sizeof(buf), "%lu", (unsigned long int) maximum);
-
-    wordlistAdd(&W, buf);
-
-    return W;
+        return sl;
+    SBuf s;
+    s.Printf("%lu", (unsigned long int) maximum);
+    sl.push_back(s);
+    return sl;
 }
