     }
 }
 
+/// parses list of integers form name=N1,N2,N3,...
+static bool
+parseNamedIntList(const char *data, const String &name, Vector<int> &list)
+{
+    if (data && (strncmp(data, name.rawBuf(), name.size()) == 0)) {
+        data += name.size();
+        if (*data == '=') {
+            while (true) {
+                ++data;
+                int value = 0;
+                if (!StringToInt(data, value, &data, 10))
+                    break;
+                list.push_back(value);
+                if (*data == '\0' || *data != ',')
+                    break;
+            }
+        }
+    }
+    return *data == '\0';
+}
+
+static void
+parse_CpuAffinityMap(CpuAffinityMap **const cpuAffinityMap) {
+#if !HAVE_CPU_AFFINITY
+    debugs(3, DBG_CRITICAL, "FATAL: Squid built with no CPU affinity " <<
+           "support, do not set 'cpu_affinity_map'");
+    self_destruct();
+#endif /* HAVE_CPU_AFFINITY */
+
+    if (!*cpuAffinityMap)
+        *cpuAffinityMap = new CpuAffinityMap;
+
+    const char *const pToken = strtok(NULL, w_space);
+    const char *const cToken = strtok(NULL, w_space);
+    Vector<int> processes, cores;
+    if (!parseNamedIntList(pToken, "process_numbers", processes)) {
+        debugs(3, DBG_CRITICAL, "FATAL: bad 'process_numbers' parameter " <<
+               "in 'cpu_affinity_map'");
+        self_destruct();
+    } else if (!parseNamedIntList(cToken, "cores", cores)) {
+        debugs(3, DBG_CRITICAL, "FATAL: bad 'cores' parameter in " <<
+               "'cpu_affinity_map'");
+        self_destruct();
+    } else if (!(*cpuAffinityMap)->add(processes, cores)) {
+        debugs(3, DBG_CRITICAL, "FATAL: bad 'cpu_affinity_map'; " <<
+               "process_numbers and cores lists differ in length or " <<
+               "contain numbers <= 0");
+        self_destruct();
+    }
+}
+
+static void
+dump_CpuAffinityMap(StoreEntry *const entry, const char *const name, const CpuAffinityMap *const cpuAffinityMap) {
+    if (cpuAffinityMap) {
+        storeAppendPrintf(entry, "%s process_numbers=", name);
+        for (size_t i = 0; i < cpuAffinityMap->processes().size(); ++i) {
+            storeAppendPrintf(entry, "%s%i", (i ? "," : ""),
+                              cpuAffinityMap->processes()[i]);
+        }
+        storeAppendPrintf(entry, " cores=");
+        for (size_t i = 0; i < cpuAffinityMap->processes().size(); ++i) {
+            storeAppendPrintf(entry, "%s%i", (i ? "," : ""),
+                              cpuAffinityMap->cores()[i]);
+        }
+        storeAppendPrintf(entry, "\n");
+    }
+}
+
+static void
+free_CpuAffinityMap(CpuAffinityMap **const cpuAffinityMap) {
+    delete *cpuAffinityMap;
+    *cpuAffinityMap = NULL;
+}
+
 #if USE_ADAPTATION
 
 static void
