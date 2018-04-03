     }
 }
 
-wordlist *
+SBufList
 ACLExternal::dump() const
 {
     external_acl_data const *acl = data;
-    wordlist *result = NULL;
-    wordlist *arg;
-    MemBuf mb;
-    mb.init();
-    mb.Printf("%s", acl->def->name);
+    SBufList rv;
+    rv.push_back(SBuf(acl->def->name));
 
-    for (arg = acl->arguments; arg; arg = arg->next) {
-        mb.Printf(" %s", arg->key);
+    for (wordlist *arg = acl->arguments; arg; arg = arg->next) {
+        SBuf s;
+        s.Printf(" %s", arg->key);
+        rv.push_back(s);
     }
 
-    wordlistAdd(&result, mb.buf);
-    mb.clean();
-    return result;
+    return rv;
 }
 
 /******************************************************************
