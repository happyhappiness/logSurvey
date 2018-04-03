 xprof_show_item(StoreEntry * sentry, const char *name, xprof_stats_data * hist)
 {
     storeAppendPrintf(sentry,
-                      "%s\t %llu\t %llu\t %llu\t %llu\t %llu\t %.2f\t %6.3f\t\n",
+                      "%s\t %" PRIu64 "\t %" PRIu64 "\t %" PRIu64 "\t %" PRIu64 "\t %" PRIu64 "\t %.2f\t %6.3f\t\n",
                       name,
                       hist->count,
                       hist->summ,
