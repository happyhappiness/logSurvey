     ch.my_addr = clientConnection->local;
     ch.conn(this);
 
-    if (ch.fastCheck() != ACCESS_ALLOWED) {
-        mustStop("PROXY client not permitted by ACLs");
-        return false;
-    }
+    if (ch.fastCheck() != ACCESS_ALLOWED)
+        return proxyProtocolError("PROXY client not permitted by ACLs");
+
     return true;
 }
 
