     if (result != NULL)
         fatal("AclLookupProxyAuthDone: Old code floating around somewhere.\nMake clean and if that doesn't work, report a bug to the squid developers.\n");
 
-    if (!authenticateValidateUser(checklist->auth_user_request) || checklist->conn() == NULL) {
+    if (checklist->auth_user_request == NULL || !checklist->auth_user_request->valid() || checklist->conn() == NULL) {
         /* credentials could not be checked either way
          * restart the whole process */
         /* OR the connection was closed, there's no way to continue */
-        AUTHUSERREQUESTUNLOCK(checklist->auth_user_request, "ProxyAuthLookup");
+        checklist->auth_user_request = NULL;
 
         if (checklist->conn() != NULL) {
-            AUTHUSERREQUESTUNLOCK(checklist->conn()->auth_user_request, "conn via ProxyAuthLookup");	// DPW discomfort
-            checklist->conn()->auth_type = AUTH_BROKEN;
+            checklist->conn()->auth_user_request = NULL;
         }
     }
 
