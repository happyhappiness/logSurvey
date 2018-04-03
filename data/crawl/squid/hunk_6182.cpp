     assert(mem->inmem_hi == 0);
     storeBuffer(entry);
     rep = errorBuildReply(err);
+    /* Add authentication header */
+    switch (err->http_status) {
+    case HTTP_PROXY_AUTHENTICATION_REQUIRED:
+	/* Proxy authorisation needed */
+	httpHeaderPutStrf(&rep->header, HDR_PROXY_AUTHENTICATE,
+	    proxy_auth_challenge_fmt, Config.proxyAuthRealm);
+	break;
+    case HTTP_UNAUTHORIZED:
+	/* WWW Authorisation needed */
+	httpHeaderPutStrf(&rep->header, HDR_WWW_AUTHENTICATE,
+	    proxy_auth_challenge_fmt, Config.proxyAuthRealm);
+	break;
+    default:
+	/* Keep GCC happy */
+	break;
+    }
     httpReplySwapOut(rep, entry);
     httpReplyDestroy(rep);
     mem->reply->sline.status = err->http_status;
