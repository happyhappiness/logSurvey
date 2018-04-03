         return;
 
     default:
-        fatal("Hit unreachable code in ClientSocketContext::writeComplete\n");
+        fatal("Hit unreachable code in Http::StreamContext::writeComplete\n");
     }
 }
 
-ClientSocketContext *
+Http::StreamContext *
 ConnStateData::abortRequestParsing(const char *const uri)
 {
     ClientHttpRequest *http = new ClientHttpRequest(this);
     http->req_sz = inBuf.length();
     http->uri = xstrdup(uri);
     setLogUri (http, uri);
-    ClientSocketContext *context = new ClientSocketContext(clientConnection, http);
+    auto *context = new Http::StreamContext(clientConnection, http);
     StoreIOBuffer tempBuffer;
     tempBuffer.data = context->reqbuf;
     tempBuffer.length = HTTP_REQBUF_SZ;
