     }
 };
 
+/**
+ * Pre-parse TLS options= parameter to be applied when the TLS objects created.
+ * Options must not used in the case of peek or stare bump mode.
+ */
 long
-Security::ParseOptions(const char *options)
+Security::PeerOptions::parseOptions()
 {
     long op = 0;
-    char *tmp;
-    char *option;
-
-    if (options) {
-
-    tmp = xstrdup(options);
-    option = strtok(tmp, ":,");
-
-    while (option) {
+    ::Parser::Tokenizer tok(sslOptions);
 
+    do {
         enum {
             MODE_ADD, MODE_REMOVE
         } mode;
 
-        switch (*option) {
-
-        case '!':
-
-        case '-':
+        if (tok.skip('-') || tok.skip('!'))
             mode = MODE_REMOVE;
-            ++option;
-            break;
-
-        case '+':
+        else {
+            (void)tok.skip('+'); // default action is add. ignore if missing operator
             mode = MODE_ADD;
-            ++option;
-            break;
+        }
 
-        default:
-            mode = MODE_ADD;
-            break;
+        static const CharacterSet optChars = CharacterSet("TLS-option", "_") + CharacterSet::ALPHA + CharacterSet::DIGIT;
+        int64_t hex = 0;
+        SBuf option;
+        long value = 0;
+
+        if (tok.int64(hex, 16, false)) {
+            /* Special case.. hex specification */
+            value = hex;
         }
 
-        struct ssl_option *opt = NULL;
-        for (struct ssl_option *opttmp = ssl_options; opttmp->name; ++opttmp) {
-            if (strcmp(opttmp->name, option) == 0) {
-                opt = opttmp;
-                break;
+        else if (tok.prefix(option, optChars)) {
+            // find the named option in our supported set
+            for (struct ssl_option *opttmp = ssl_options; opttmp->name; ++opttmp) {
+                if (option.cmp(opttmp->name) == 0) {
+                    value = opttmp->value;
+                    break;
+                }
             }
         }
 
-        long value = 0;
-        if (opt)
-            value = opt->value;
-        else if (strncmp(option, "0x", 2) == 0) {
-            /* Special case.. hex specification */
-            value = strtol(option + 2, NULL, 16);
-        } else {
-            fatalf("Unknown TLS option '%s'", option);
-            value = 0;      /* Keep GCC happy */
+        if (!value) {
+            fatalf("Unknown TLS option '" SQUIDSBUFPH "'", SQUIDSBUFPRINT(option));
         }
 
         switch (mode) {
