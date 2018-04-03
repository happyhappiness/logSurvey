 }
 
 static char *create_authorization_line (const char *, const char *,
-					const char *, const char *,
-					const char *, bool *);
+                                        const char *, const char *,
+                                        const char *, bool *);
 static char *basic_authentication_encode (const char *, const char *);
 static bool known_authentication_scheme_p (const char *, const char *);
+static void load_cookies (void);
 
-#define BEGINS_WITH(line, string_constant)				\
-  (!strncasecmp (line, string_constant, sizeof (string_constant) - 1)	\
-   && (ISSPACE (line[sizeof (string_constant) - 1])			\
+#define BEGINS_WITH(line, string_constant)                               \
+  (!strncasecmp (line, string_constant, sizeof (string_constant) - 1)    \
+   && (ISSPACE (line[sizeof (string_constant) - 1])                      \
        || !line[sizeof (string_constant) - 1]))
 
-#define SET_USER_AGENT(req) do {					\
-  if (!opt.useragent)							\
-    request_set_header (req, "User-Agent",				\
-			aprintf ("Wget/%s", version_string), rel_value); \
-  else if (*opt.useragent)						\
-    request_set_header (req, "User-Agent", opt.useragent, rel_none);	\
+#define SET_USER_AGENT(req) do {                                         \
+  if (!opt.useragent)                                                    \
+    request_set_header (req, "User-Agent",                               \
+                        aprintf ("Wget/%s", version_string), rel_value); \
+  else if (*opt.useragent)                                               \
+    request_set_header (req, "User-Agent", opt.useragent, rel_none);     \
 } while (0)
 
 /* The flags that allow clobbering the file (opening with "wb").
    Defined here to avoid repetition later.  #### This will require
    rework.  */
 #define ALLOW_CLOBBER (opt.noclobber || opt.always_rest || opt.timestamping \
-		       || opt.dirstruct || opt.output_document)
+                       || opt.dirstruct || opt.output_document)
 
 /* Retrieve a document through HTTP protocol.  It recognizes status
    code, and correctly handles redirections.  It closes the network
