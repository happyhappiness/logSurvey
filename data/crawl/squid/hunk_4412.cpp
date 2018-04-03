 }
 
 static void
-
-dump_address(StoreEntry * entry, const char *name, struct IN_ADDR addr)
+dump_address(StoreEntry * entry, const char *name, IPAddress &addr)
 {
-    storeAppendPrintf(entry, "%s %s\n", name, inet_ntoa(addr));
+    char buf[MAX_IPSTRLEN];
+    storeAppendPrintf(entry, "%s %s\n", name, addr.NtoA(buf,MAX_IPSTRLEN) );
 }
 
 static void
-
-parse_address(struct IN_ADDR *addr)
+parse_address(IPAddress *addr)
 {
-
-    const struct hostent *hp;
     char *token = strtok(NULL, w_space);
 
     if (!token) {
         self_destruct();
         return;
     }
 
-    if (safe_inet_addr(token, addr) == 1)
-        (void) 0;
-    else if ((hp = gethostbyname(token)))	/* dont use ipcache */
-        *addr = inaddrFromHostent(hp);
+    if (!strcmp(token,"any_addr"))
+    {
+        addr->SetAnyAddr();
+	(void) 0;
+    }
+    else if ( (!strcmp(token,"no_addr")) || (!strcmp(token,"full_mask")) )
+    {
+        addr->SetNoAddr();
+	(void) 0;
+    }
     else
-        self_destruct();
+        *addr = token;
 }
 
 static void
-
-free_address(struct IN_ADDR *addr)
+free_address(IPAddress *addr)
 {
-
-    memset(addr, '\0', sizeof(struct IN_ADDR));
+    addr->SetEmpty();
 }
 
 CBDATA_TYPE(acl_address);
 
 static void
 dump_acl_address(StoreEntry * entry, const char *name, acl_address * head)
 {
+    char buf[MAX_IPSTRLEN];
     acl_address *l;
 
     for (l = head; l; l = l->next) {
-        if (l->addr.s_addr != INADDR_ANY)
-            storeAppendPrintf(entry, "%s %s", name, inet_ntoa(l->addr));
+        if (!l->addr.IsAnyAddr())
+            storeAppendPrintf(entry, "%s %s", name, l->addr.NtoA(buf,MAX_IPSTRLEN));
         else
             storeAppendPrintf(entry, "%s autoselect", name);
 
