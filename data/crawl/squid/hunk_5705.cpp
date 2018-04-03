 	incoming_http_interval >> INCOMING_FACTOR);
     storeAppendPrintf(sentry, "\n");
     storeAppendPrintf(sentry, "Histogram of events per incoming socket type\n");
-#ifdef HAVE_POLL
-    storeAppendPrintf(sentry, "ICP Messages handled per comm_poll_icp_incoming() call:\n");
-#else
     storeAppendPrintf(sentry, "ICP Messages handled per comm_select_icp_incoming() call:\n");
-#endif
     statHistDump(&f->comm_icp_incoming, sentry, statHistIntDumper);
-#ifdef HAVE_POLL
-    storeAppendPrintf(sentry, "DNS Messages handled per comm_poll_dns_incoming() call:\n");
-#else
     storeAppendPrintf(sentry, "DNS Messages handled per comm_select_dns_incoming() call:\n");
-#endif
     statHistDump(&f->comm_dns_incoming, sentry, statHistIntDumper);
-#ifdef HAVE_POLL
-    storeAppendPrintf(sentry, "HTTP Messages handled per comm_poll_http_incoming() call:\n");
-#else
     storeAppendPrintf(sentry, "HTTP Messages handled per comm_select_http_incoming() call:\n");
-#endif
     statHistDump(&f->comm_http_incoming, sentry, statHistIntDumper);
 }
 
