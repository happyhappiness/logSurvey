                 return false;
 
             if (porta > 0 && porta <= 0xFFFF) // max uint16_t
-                originalClient.port(static_cast<uint16_t>(porta));
+                originalClient.port(ntohs(static_cast<uint16_t>(porta)));
             else
                 return proxyProtocolError(true);
 
             if (portb > 0 && portb <= 0xFFFF) // max uint16_t
-                originalDest.port(static_cast<uint16_t>(portb));
+                originalDest.port(ntohs(static_cast<uint16_t>(portb)));
             else
                 return proxyProtocolError(true);
 
             in.buf = tok.remaining(); // sync buffers
             needProxyProtocolHeader_ = false; // found successfully
 
             // we have original client and destination details now
-            // replace the tcpClient connection values
+            // replace the client connection values
             debugs(33, 5, "PROXY protocol on connection " << clientConnection);
             clientConnection->local = originalDest;
             clientConnection->remote = originalClient;
