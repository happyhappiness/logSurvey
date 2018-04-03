     HttpRequest *r = err->request;
     MemBuf str;
     const char *p = NULL;	/* takes priority over mb if set */
+    char ntoabuf[MAX_IPSTRLEN];
+
     str.reset();
     /* email subject line */
     str.Printf("CacheErrorInfo - %s", errorPageName(err->type));
