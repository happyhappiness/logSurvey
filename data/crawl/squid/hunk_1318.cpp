 }
 
 /**
- * Perform forwarded_access ACL tests on the client which
+ * Perform proxy_protocol_access ACL tests on the client which
  * connected to PROXY protocol port to see if we trust the
  * sender enough to accept their PROXY header claim.
  */
 bool
 ConnStateData::proxyProtocolValidateClient()
 {
-    ACLFilledChecklist ch(Config.accessList.followXFF, NULL, clientConnection->rfc931);
+    if (!Config.accessList.proxyProtocol)
+        return proxyProtocolError("PROXY client not permitted by default ACL");
+
+    ACLFilledChecklist ch(Config.accessList.proxyProtocol, NULL, clientConnection->rfc931);
     ch.src_addr = clientConnection->remote;
     ch.my_addr = clientConnection->local;
     ch.conn(this);