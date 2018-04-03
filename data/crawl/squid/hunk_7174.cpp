     storeAppendPrintf(sentry, close_bracket);
 }
 
-
-/* return total bytes of all registered and known objects.
- * may not reflect the retrieving object....
- * something need to be done here to get more accurate cache size */
-static int
-cache_size_get(const cacheinfo * obj)
-{
-    int size = 0;
-    protocol_t proto_id;
-    /* sum all size, exclude total */
-    for (proto_id = PROTO_NONE; proto_id < PROTO_MAX; proto_id++)
-	size += obj->proto_stat_data[proto_id].kb.now;
-    return size;
-}
-
 static const char *
 describeStatuses(const StoreEntry * entry)
 {
