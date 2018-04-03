     storeAppendPrintf(sentry, "unlink\t%d\t%d\n", squidaio_counts.unlink_start, squidaio_counts.unlink_finish);
     storeAppendPrintf(sentry, "check_callback\t%d\t-\n", squidaio_counts.check_callback);
     storeAppendPrintf(sentry, "queue\t%d\t-\n", squidaio_get_queue_len());
+    squidaio_stats(sentry);
 }
 
 DiskThreadsIOStrategy DiskThreadsIOStrategy::Instance;
