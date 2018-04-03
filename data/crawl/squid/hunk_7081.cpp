 }
 
 static void
-dump_onoff(int var)
+dump_onoff(StoreEntry *entry, const char *name, int var)
 {
-    printf(var ? "on" : "off");
+    storeAppendPrintf(entry, "%s %s\n", name, var ? "on" : "off");
 }
 
 static void
