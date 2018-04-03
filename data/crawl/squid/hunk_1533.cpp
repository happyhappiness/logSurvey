     return 0;
 }
 
-wordlist *
-ACLTimeData::dump()
+SBufList
+ACLTimeData::dump() const
 {
-    wordlist *W = NULL;
-    char buf[128];
-    ACLTimeData *t = this;
+    SBufList sl;
+    const ACLTimeData *t = this;
 
     while (t != NULL) {
-        snprintf(buf, sizeof(buf), "%c%c%c%c%c%c%c %02d:%02d-%02d:%02d",
+        SBuf s;
+        s.Printf("%c%c%c%c%c%c%c %02d:%02d-%02d:%02d",
                  t->weekbits & ACL_SUNDAY ? 'S' : '-',
                  t->weekbits & ACL_MONDAY ? 'M' : '-',
                  t->weekbits & ACL_TUESDAY ? 'T' : '-',
