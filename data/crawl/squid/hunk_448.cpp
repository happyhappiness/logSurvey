         return;
 
     default:
-        fatal("Hit unreachable code in clientWriteComplete\n");
+        fatal("Hit unreachable code in ClientSocketContext::writeComplete\n");
     }
 }
 
 ClientSocketContext *
 ConnStateData::abortRequestParsing(const char *const uri)
 {
     ClientHttpRequest *http = new ClientHttpRequest(this);
-    http->req_sz = in.buf.length();
+    http->req_sz = inBuf.length();
     http->uri = xstrdup(uri);
     setLogUri (http, uri);
     ClientSocketContext *context = new ClientSocketContext(clientConnection, http);
