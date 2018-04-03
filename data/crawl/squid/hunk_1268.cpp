     }
 
     const HttpRequestMethod method =
-        !cmd.caseCmp("APPE") || !cmd.caseCmp("STOR") || !cmd.caseCmp("STOU") ?
+        cmd == cmdAppe() || cmd == cmdStor() || cmd == cmdStou() ?
         Http::METHOD_PUT : Http::METHOD_GET;
 
-    const char *aPath = params.size() > 0 && CommandHasPathParameter(cmd) ?
-        params.termedBuf() : NULL;
-    calcUri(aPath);
-    char *newUri = xstrdup(uri.termedBuf());
+    const SBuf *path = params.length() && CommandHasPathParameter(cmd) ?
+        &params : NULL;
+    calcUri(path);
+    char *newUri = xstrdup(uri.c_str());
     HttpRequest *const request = HttpRequest::CreateFromUrlAndMethod(newUri, method);
     if (!request) {
         debugs(33, 5, "Invalid FTP URL: " << uri);
         writeEarlyReply(501, "Invalid host");
-        uri.clean();
+        uri.clear();
         safe_free(newUri);
         return NULL;
     }
 
+    ver = Http::ProtocolVersion(1, 1);
     request->flags.ftpNative = true;
     request->http_ver = ver;
 
     // Our fake Request-URIs are not distinctive enough for caching to work
     request->flags.cachable = false; // XXX: reset later by maybeCacheable()
     request->flags.noCache = true;
 
-    request->header.putStr(HDR_FTP_COMMAND, cmd.termedBuf());
-    request->header.putStr(HDR_FTP_ARGUMENTS, params.termedBuf() != NULL ?
-                           params.termedBuf() : "");
+    request->header.putStr(HDR_FTP_COMMAND, cmd.c_str());
+    request->header.putStr(HDR_FTP_ARGUMENTS, params.c_str()); // may be ""
     if (method == Http::METHOD_PUT) {
         request->header.putStr(HDR_EXPECT, "100-continue");
         request->header.putStr(HDR_TRANSFER_ENCODING, "chunked");
