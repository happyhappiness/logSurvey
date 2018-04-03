     for (node = list; node; node = node->next) {
         storeAppendPrintf(sentry, "%s %s", name, node->name);
 
-        if (!node->local_addr.IsIPv6())
+        if (!node->local_addr.isIPv6())
             storeAppendPrintf(sentry, " ipv4");
         else
             storeAppendPrintf(sentry, " ipv6");
