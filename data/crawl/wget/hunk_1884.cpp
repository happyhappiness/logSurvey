    && (c_isspace (line[sizeof (string_constant) - 1])                      \
        || !line[sizeof (string_constant) - 1]))
 
+#ifdef __VMS
+#define SET_USER_AGENT(req) do {                                         \
+  if (!opt.useragent)                                                    \
+    request_set_header (req, "User-Agent",                               \
+                        aprintf ("Wget/%s (VMS %s %s)",                  \
+                        VERSION_STRING, vms_arch(), vms_vers()),         \
+                        rel_value);                                      \
+  else if (*opt.useragent)                                               \
+    request_set_header (req, "User-Agent", opt.useragent, rel_none);     \
+} while (0)
+#else /* def __VMS */
 #define SET_USER_AGENT(req) do {                                         \
   if (!opt.useragent)                                                    \
     request_set_header (req, "User-Agent",                               \
-                        aprintf ("Wget/%s", version_string), rel_value); \
+                        aprintf ("Wget/%s (%s)",                         \
+                        VERSION_STRING, OS_TYPE),                        \
+                        rel_value);                                      \
   else if (*opt.useragent)                                               \
     request_set_header (req, "User-Agent", opt.useragent, rel_none);     \
 } while (0)
+#endif /* def __VMS [else] */
 
 /* The flags that allow clobbering the file (opening with "wb").
    Defined here to avoid repetition later.  #### This will require
