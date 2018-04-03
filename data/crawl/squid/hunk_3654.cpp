     storeAppendPrintf(entry, "\n");
 }
 
+static void
+free_memcachemode(SquidConfig * config)
+{
+    return;
+}
+
+static void
+parse_memcachemode(SquidConfig * config)
+{
+    char *token = strtok(NULL, w_space);
+    if (!token)
+	self_destruct();
+
+    if (strcmp(token, "always") == 0) {
+	Config.onoff.memory_cache_first = 1;
+	Config.onoff.memory_cache_disk = 1;
+    } else if (strcmp(token, "disk") == 0) {
+	Config.onoff.memory_cache_first = 0;
+	Config.onoff.memory_cache_disk = 1;
+    } else if (strncmp(token, "net", 3) == 0) {
+	Config.onoff.memory_cache_first = 1;
+	Config.onoff.memory_cache_disk = 0;
+    } else if (strcmp(token, "never") == 0) {
+	Config.onoff.memory_cache_first = 0;
+	Config.onoff.memory_cache_disk = 0;
+    } else
+	self_destruct();
+}
+
+static void
+dump_memcachemode(StoreEntry * entry, const char *name, SquidConfig &config)
+{
+    storeAppendPrintf(entry, "%s ", name);
+    if (Config.onoff.memory_cache_first && Config.onoff.memory_cache_disk)
+	storeAppendPrintf(entry, "always");
+    else if (!Config.onoff.memory_cache_first && Config.onoff.memory_cache_disk)
+	storeAppendPrintf(entry, "disk");
+    else if (Config.onoff.memory_cache_first && !Config.onoff.memory_cache_disk)
+	storeAppendPrintf(entry, "network");
+    else if (!Config.onoff.memory_cache_first && !Config.onoff.memory_cache_disk)
+	storeAppendPrintf(entry, "none");
+    storeAppendPrintf(entry, "\n");
+}
+
 #include "cf_parser.h"
 
 peer_t
