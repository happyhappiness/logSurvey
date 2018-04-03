     }
     /* NOTREACHED */
 }
-
-static void
-commIncomingStats(StoreEntry * sentry)
-{
-    StatCounters *f = &Counter;
-    storeAppendPrintf(sentry, "Current incoming_interval: %d\n",
-	incoming_interval >> 4);
-    storeAppendPrintf(sentry, "\n");
-    storeAppendPrintf(sentry, "Histogram of number of incoming sockets or\n");
-    storeAppendPrintf(sentry, "Messages handled per comm_incoming() call:\n");
-    statHistDump(&f->comm_incoming, sentry, statHistIntDumper);
-}
