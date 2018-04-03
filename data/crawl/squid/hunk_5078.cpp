 }
 
 #define free_onoff free_int
-#define dump_eol dump_string
-#define free_eol free_string
-#define dump_debug dump_string
-#define free_debug free_string
+
+static void
+dump_tristate(StoreEntry * entry, const char *name, int var)
+{
+    const char *state;
+
+    if (var > 0)
+        state = "on";
+    else if (var < 0)
+        state = "warn";
+    else
+        state = "off";
+
+    storeAppendPrintf(entry, "%s %s\n", name, state);
+}
+
+static void
+parse_tristate(int *var)
+{
+    char *token = strtok(NULL, w_space);
+
+    if (token == NULL)
+        self_destruct();
+
+    if (!strcasecmp(token, "on") || !strcasecmp(token, "enable"))
+        *var = 1;
+    else if (!strcasecmp(token, "warn"))
+        *var = -1;
+    else
+        *var = 0;
+}
+
+#define free_tristate free_int
 
 static void
 dump_refreshpattern(StoreEntry * entry, const char *name, refresh_t * head)
