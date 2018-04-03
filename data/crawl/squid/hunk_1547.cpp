     return 0;
 }
 
-wordlist *
+SBufList
 ACLTimeData::dump()
 {
-    wordlist *W = NULL;
-    char buf[128];
+    SBufList sl;
     ACLTimeData *t = this;
 
     while (t != NULL) {
-        snprintf(buf, sizeof(buf), "%c%c%c%c%c%c%c %02d:%02d-%02d:%02d",
+        SBuf s;
+        s.Printf("%c%c%c%c%c%c%c %02d:%02d-%02d:%02d",
                  t->weekbits & ACL_SUNDAY ? 'S' : '-',
                  t->weekbits & ACL_MONDAY ? 'M' : '-',
                  t->weekbits & ACL_TUESDAY ? 'T' : '-',
