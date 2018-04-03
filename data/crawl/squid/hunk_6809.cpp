     LOCAL_ARRAY(char, url, MAX_URL);
     char *buf;
     const cache_key *key;
+    const char *type = mimeGetContentType(icon);
+    if (type == NULL)
+	fatal("Unknown icon format while reading mime.conf\n");
     snprintf(url, MAX_URL, "http://internal.squid/icons/%s", icon);
     key = storeKeyPublic(url, METHOD_GET);
     if (storeGet(key))
