     shut_down(0);
 }
 
+static const char *
+cachemgrActionProtection(const action_table *at)
+{
+    char *pwd;
+    assert(at);
+    pwd = cachemgrPasswdGet(Config.passwd_list, at->action);
+    if (!pwd)
+	return at->pw_req_flag ? "hidden" : "public";
+    if (!strcmp(pwd, "disable"))
+	return "disabled";
+    if (strcmp(pwd, "none") == 0)
+	return "public";
+    return "protected";
+}
+
 static void
 cachemgrMenu(StoreEntry *sentry)
 {
-	action_table *a;
-	for (a = ActionTable; a != NULL; a = a->next) {
-		storeAppendPrintf(sentry, " %-22s\t%s\n", a->action, a->desc);
-	}
+    action_table *a;
+    for (a = ActionTable; a != NULL; a = a->next) {
+	storeAppendPrintf(sentry, " %-22s\t%s\t%s\n",
+	    a->action, a->desc, cachemgrActionProtection(a));
+    }
 }
 
 static char *
