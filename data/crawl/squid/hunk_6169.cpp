 	HttpHeaderStats[0].parsedCount);
     storeAppendPrintf(e, "Hdr Fields Parsed: %d\n", HeaderEntryParsedCount);
 }
+
+int
+httpHeaderIdByName(const char *name, int name_len, const HttpHeaderFieldInfo * info, int end)
+{
+    int i;
+    for (i = 0; i < end; ++i) {
+        if (name_len >= 0 && name_len != strLen(info[i].name))
+            continue;
+        if (!strncasecmp(name, strBuf(info[i].name),
+                name_len < 0 ? strLen(info[i].name) + 1 : name_len))
+            return i;
+    }
+    return -1;
+}
+
+int
+httpHeaderIdByNameDef(const char *name, int name_len)
+{
+   if (!Headers)
+       Headers = httpHeaderBuildFieldsInfo(HeadersAttrs, HDR_ENUM_END);
+   return httpHeaderIdByName(name, name_len, Headers, HDR_ENUM_END);
+}
+
