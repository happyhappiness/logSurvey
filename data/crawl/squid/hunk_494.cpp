 void
 Ftp::Server::handleFeatReply(const HttpReply *reply, StoreIOBuffer)
 {
-    if (getCurrentContext()->http->request->errType != ERR_NONE) {
+    if (pipeline.front()->http->request->errType != ERR_NONE) {
         writeCustomReply(502, "Server does not support FEAT", reply);
         return;
     }
