     for (k = 0; k < NDnsServersAlloc; k++) {
 	dns = *(dns_child_table + k);
 	storeAppendPrintf(sentry, "{dnsserver #%d:}\n", k + 1);
-	storeAppendPrintf(sentry, "{    Flags: %c%c%c}\n",
+	storeAppendPrintf(sentry, "{    Flags: %c%c%c%c}\n",
 	    EBIT_TEST(dns->flags, HELPER_ALIVE) ? 'A' : ' ',
 	    EBIT_TEST(dns->flags, HELPER_BUSY) ? 'B' : ' ',
-	    EBIT_TEST(dns->flags, HELPER_CLOSING) ? 'C' : ' ');
+	    EBIT_TEST(dns->flags, HELPER_CLOSING) ? 'C' : ' ',
+	    EBIT_TEST(dns->flags, HELPER_SHUTDOWN) ? 'S' : ' ');
 	storeAppendPrintf(sentry, "{    FDs (in/out): %d/%d}\n",
 	    dns->inpipe, dns->outpipe);
 	storeAppendPrintf(sentry, "{    Alive since: %s}\n",
