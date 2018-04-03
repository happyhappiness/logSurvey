 }
 
 static void
-dump_memcachemode(StoreEntry * entry, const char *name, SquidConfig &config)
+dump_memcachemode(StoreEntry * entry, const char *name, SquidConfig &)
 {
     storeAppendPrintf(entry, "%s ", name);
     if (Config.onoff.memory_cache_first && Config.onoff.memory_cache_disk)
