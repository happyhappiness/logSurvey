                        url);
 
     if (sock == COMM_ERROR) {
-        debugs(26, 4, "sslStart: Failed because we're out of sockets.");
+        debugs(26, 4, "tunnelStart: Failed because we're out of sockets.");
         err = errorCon(ERR_SOCKET_FAILURE, HTTP_INTERNAL_SERVER_ERROR, request);
         *status_ptr = HTTP_INTERNAL_SERVER_ERROR;
         err->xerrno = errno;
         errorSend(fd, err);
         return;
     }
 
-    sslState = new SslStateData;
+    tunnelState = new SslStateData;
 #if DELAY_POOLS
 
-    sslState->server.setDelayId(DelayId::DelayClient(http));
+    tunnelState->server.setDelayId(DelayId::DelayClient(http));
 #endif
 
-    sslState->url = xstrdup(url);
-    sslState->request = HTTPMSGLOCK(request);
-    sslState->server.size_ptr = size_ptr;
-    sslState->status_ptr = status_ptr;
-    sslState->client.fd(fd);
-    sslState->server.fd(sock);
-    comm_add_close_handler(sslState->server.fd(),
-                           sslServerClosed,
-                           sslState);
-    comm_add_close_handler(sslState->client.fd(),
-                           sslClientClosed,
-                           sslState);
-    commSetTimeout(sslState->client.fd(),
+    tunnelState->url = xstrdup(url);
+    tunnelState->request = HTTPMSGLOCK(request);
+    tunnelState->server.size_ptr = size_ptr;
+    tunnelState->status_ptr = status_ptr;
+    tunnelState->client.fd(fd);
+    tunnelState->server.fd(sock);
+    comm_add_close_handler(tunnelState->server.fd(),
+                           tunnelServerClosed,
+                           tunnelState);
+    comm_add_close_handler(tunnelState->client.fd(),
+                           tunnelClientClosed,
+                           tunnelState);
+    commSetTimeout(tunnelState->client.fd(),
                    Config.Timeout.lifetime,
-                   sslTimeout,
-                   sslState);
-    commSetTimeout(sslState->server.fd(),
+                   tunnelTimeout,
+                   tunnelState);
+    commSetTimeout(tunnelState->server.fd(),
                    Config.Timeout.connect,
-                   sslConnectTimeout,
-                   sslState);
+                   tunnelConnectTimeout,
+                   tunnelState);
     peerSelect(request,
                NULL,
-               sslPeerSelectComplete,
-               sslState);
+               tunnelPeerSelectComplete,
+               tunnelState);
     /*
      * Disable the client read handler until peer selection is complete
      * Take control away from client_side.c.
      */
-    commSetSelect(sslState->client.fd(), COMM_SELECT_READ, NULL, NULL, 0);
+    commSetSelect(tunnelState->client.fd(), COMM_SELECT_READ, NULL, NULL, 0);
 }
 
 static void
-sslProxyConnected(int fd, void *data)
+tunnelProxyConnected(int fd, void *data)
 {
-    SslStateData *sslState = (SslStateData *)data;
+    SslStateData *tunnelState = (SslStateData *)data;
     HttpHeader hdr_out(hoRequest);
     Packer p;
     http_state_flags flags;
-    debugs(26, 3, "sslProxyConnected: FD " << fd << " sslState=" << sslState);
+    debugs(26, 3, "tunnelProxyConnected: FD " << fd << " tunnelState=" << tunnelState);
     memset(&flags, '\0', sizeof(flags));
-    flags.proxying = sslState->request->flags.proxying;
+    flags.proxying = tunnelState->request->flags.proxying;
     MemBuf mb;
     mb.init();
-    mb.Printf("CONNECT %s HTTP/1.0\r\n", sslState->url);
-    HttpStateData::httpBuildRequestHeader(sslState->request,
-                                          sslState->request,
+    mb.Printf("CONNECT %s HTTP/1.0\r\n", tunnelState->url);
+    HttpStateData::httpBuildRequestHeader(tunnelState->request,
+                                          tunnelState->request,
                                           NULL,			/* StoreEntry */
                                           &hdr_out,
                                           flags);			/* flags */
