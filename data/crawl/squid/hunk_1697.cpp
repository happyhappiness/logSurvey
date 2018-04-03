         if (s->defaultsite)
             storeAppendPrintf(e, " defaultsite=%s", s->defaultsite);
 
-        if (s->protocol && strcmp(s->protocol,"http") != 0)
-            storeAppendPrintf(e, " protocol=%s", s->protocol);
+        // TODO: compare against prefix of 'n' instead of assuming http_port
+        if (s->transport.protocol != AnyP::PROTO_HTTP)
+            storeAppendPrintf(e, " protocol=%s", URLScheme(s->transport.protocol).const_str());
 
         if (s->allow_direct)
             storeAppendPrintf(e, " allow-direct");
