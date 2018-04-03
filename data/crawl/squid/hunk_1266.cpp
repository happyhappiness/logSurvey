     assert(http != NULL);
     assert(http->storeEntry() == NULL);
 
-    HttpReply *const reply = new HttpReply;
-    reply->sline.set(Http::ProtocolVersion(1, 1), Http::scNoContent);
-    HttpHeader &header = reply->header;
-    header.putTime(HDR_DATE, squid_curtime);
-    {
-        HttpHdrCc cc;
-        cc.Private();
-        header.putCc(&cc);
-    }
-    header.putInt64(HDR_CONTENT_LENGTH, 0);
-    header.putInt(HDR_FTP_STATUS, code);
-    header.putStr(HDR_FTP_REASON, msg);
-    reply->hdrCacheInit();
+    HttpReply *const reply = Ftp::HttpReplyWrapper(code, msg, Http::scNoContent, 0);
 
     setLogUri(http, urlCanonicalClean(http->request));
 
