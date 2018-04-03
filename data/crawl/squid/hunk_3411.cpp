     flags.proxying = tunnelState->request->flags.proxying;
     MemBuf mb;
     mb.init();
-    mb.Printf("CONNECT %s HTTP/1.0\r\n", tunnelState->url);
+    mb.Printf("CONNECT %s HTTP/1.1\r\n", tunnelState->url);
     HttpStateData::httpBuildRequestHeader(tunnelState->request,
                                           tunnelState->request,
                                           NULL,			/* StoreEntry */