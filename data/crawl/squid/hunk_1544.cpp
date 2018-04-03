     return asnMatchIp(data, toMatch);
 }
 
-wordlist *
+SBufList
 ACLASN::dump()
 {
-    wordlist *W = NULL;
-    char buf[32];
+    SBufList sl;
+
     CbDataList<int> *ldata = data;
 
     while (ldata != NULL) {
-        snprintf(buf, sizeof(buf), "%d", ldata->element);
-        wordlistAdd(&W, buf);
+        SBuf s;
+        s.Printf("%d", ldata->element);
+        sl.push_back(s);
         ldata = ldata->next;
     }
 
-    return W;
+    return sl;
 }
 
 bool
