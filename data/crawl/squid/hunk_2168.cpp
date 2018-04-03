         if (_SQUID_RES_NSADDR_COUNT == MAXNS) {
             fprintf(stderr, "Too many -s options, only %d are allowed\n", MAXNS);
         } else {
-            _SQUID_RES_NSADDR_COUNT++;
+            ++ _SQUID_RES_NSADDR_COUNT;
             memcpy(&_SQUID_RES_NSADDR6_LIST(_SQUID_RES_NSADDR6_COUNT++), &((struct sockaddr_in6*)AI->ai_addr)->sin6_addr, sizeof(struct in6_addr));
         }
 #else
