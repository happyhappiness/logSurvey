 void
 Auth::Config::registerWithCacheManager(void)
 {}
+
+void
+Auth::Config::parse(Auth::Config * scheme, int n_configured, char *param_str)
+{
+    if (strcmp(param_str, "key_extras") == 0) {
+        keyExtrasLine = ConfigParser::NextQuotedToken();
+        Format::Format *nlf =  new ::Format::Format(scheme->type());
+        if (!nlf->parse(keyExtrasLine.termedBuf())) {
+            debugs(29, DBG_CRITICAL, "FATAL: Failed parsing key_extras formatting value");
+            self_destruct();
+            return;
+        }
+        if (keyExtras)
+            delete keyExtras;
+
+        keyExtras = nlf;
+        
+        if (char *t = strtok(NULL, w_space)) {
+               debugs(29, DBG_CRITICAL, "FATAL: Unexpected argument '" << t << "' after request_format specification");
+               self_destruct();
+        }
+    } else {
+        debugs(29, DBG_CRITICAL, "Unrecognised " << scheme->type() << " auth scheme parameter '" << param_str << "'");
+    }
+}
+
+void
+Auth::Config::dump(StoreEntry *entry, const char *name, Auth::Config *scheme)
+{
+    if (keyExtrasLine.size() > 0)
+        storeAppendPrintf(entry, "%s %s key_extras \"%s\"\n", name, scheme->type(), keyExtrasLine.termedBuf());
+}
+
+void
+Auth::Config::done()
+{
+    delete keyExtras;
+    keyExtras = NULL; 
+    keyExtrasLine.clean();
+}
