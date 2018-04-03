 #endif
     if (EBIT_TEST(p->options, NEIGHBOR_NO_NETDB_EXCHANGE))
 	storeAppendPrintf(sentry, " no-netdb-exchange");
+#if DELAY_POOLS
+    if (EBIT_TEST(p->options, NEIGHBOR_NO_DELAY))
+	storeAppendPrintf(sentry, " no-delay");
+#endif
     if (p->mcast.ttl > 0)
 	storeAppendPrintf(sentry, " ttl=%d", p->mcast.ttl);
     storeAppendPrintf(sentry, "\n");
