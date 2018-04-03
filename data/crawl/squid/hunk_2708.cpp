     Must(fd >= 0);
     Must(aggrAction != NULL);
 
-    std::auto_ptr<HttpReply> reply(new HttpReply);
-    reply->setHeaders(HTTP_OK, NULL, "text/plain", -1, squid_curtime, squid_curtime);
-    reply->header.putStr(HDR_CONNECTION, "close"); // until we chunk response
-    std::auto_ptr<MemBuf> replyBuf(reply->pack());
+    std::auto_ptr<MemBuf> replyBuf;
+    if (strands.empty()) {
+        LOCAL_ARRAY(char, url, MAX_URL);
+        snprintf(url, MAX_URL, "%s", aggrAction->command().params.httpUri.termedBuf());
+        HttpRequest *req = HttpRequest::CreateFromUrl(url);
+        ErrorState *err = errorCon(ERR_INVALID_URL, HTTP_NOT_FOUND, req);
+        std::auto_ptr<HttpReply> reply(err->BuildHttpReply());
+        replyBuf.reset(reply->pack());
+        errorStateFree(err);
+    }
+    else {
+        std::auto_ptr<HttpReply> reply(new HttpReply);
+        reply->setHeaders(HTTP_OK, NULL, "text/plain", -1, squid_curtime, squid_curtime);
+        reply->header.putStr(HDR_CONNECTION, "close"); // until we chunk response
+        replyBuf.reset(reply->pack());
+    }
     writer = asyncCall(16, 5, "Mgr::Inquirer::noteWroteHeader",
                        CommCbMemFunT<Inquirer, CommIoCbParams>(this, &Inquirer::noteWroteHeader));
     Comm::Write(fd, replyBuf.get(), writer);