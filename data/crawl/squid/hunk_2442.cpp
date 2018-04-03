     storeAppendPrintf(entry, "\n");
 }
 
+void
+YesNoNone::configure(bool beSet)
+{
+    option = beSet ? +1 : -1;
+}
+
+YesNoNone::operator void*() const
+{
+    assert(option != 0); // must call configure() first
+    return option > 0 ? (void*)this : NULL;
+}
+
+
+inline void
+free_YesNoNone(YesNoNone *)
+{
+    // do nothing: no explicit cleanup is required
+}
+
+static void
+parse_YesNoNone(YesNoNone *option)
+{
+    int value = 0;
+    parse_onoff(&value);
+    option->configure(value > 0);
+}
+
+static void
+dump_YesNoNone(StoreEntry * entry, const char *name, YesNoNone &option)
+{
+    if (option.configured())
+        dump_onoff(entry, name, option ? 1 : 0);
+}
+
 static void
 free_memcachemode(SquidConfig * config)
 {
