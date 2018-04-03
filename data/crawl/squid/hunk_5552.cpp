     EBIT_SET(e->flags, ENTRY_SPECIAL);
     storeSetPublicKey(e);
     storeBuffer(e);
-    e->mem_obj->request = requestLink(urlParse(METHOD_GET, url));
+    r = urlParse(METHOD_GET, url);
+    if (NULL == r)
+	fatal("mimeLoadIcon: cannot parse internal URL");
+    e->mem_obj->request = requestLink(r);
     httpReplyReset(reply = e->mem_obj->reply);
     httpBuildVersion(&version, 1, 0);
     httpReplySetHeaders(reply, version, HTTP_OK, NULL,