 Auth::User::BuildUserKey(const char *username, const char *realm)
 {
     SBuf key;
-    key.Printf("%s:%s", username, realm);
+    if (realm)
+        key.Printf("%s:%s", username, realm);
+    else
+        key.append(username, strlen(username));
     return key;
 }
 
