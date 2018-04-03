   return ENOTSUP;
 }
 
+int plugin_flush (const char *plugin, cdtime_t timeout, const char *identifier)
+{
+  return ENOTSUP;
+}
+
+static data_source_t magic_ds[] = {{ "value", DS_TYPE_DERIVE, 0.0, NAN }};
+static data_set_t magic = { "MAGIC", 1, magic_ds };
+const data_set_t *plugin_get_ds (const char *name)
+{
+  if (strcmp (name, "MAGIC"))
+    return NULL;
+
+  return &magic;
+}
+
 void plugin_log (int level, char const *format, ...)
 {
   char buffer[1024];