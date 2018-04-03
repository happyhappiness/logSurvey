     while(ConfigParser::NextKvPair(key, value)) {
         if (strcasecmp(key, "on_timeout") == 0) {
             if (strcasecmp(value, "bypass") == 0)
-                Config.onUrlRewriteTimeout.action = toutActBypass;
+                config->action = toutActBypass;
             else if (strcasecmp(value, "fail") == 0)
-                Config.onUrlRewriteTimeout.action = toutActFail;
+                config->action = toutActFail;
             else if (strcasecmp(value, "retry") == 0)
-                Config.onUrlRewriteTimeout.action = toutActRetry;
+                config->action = toutActRetry;
             else if (strcasecmp(value, "use_configured_response") == 0) {
-                Config.onUrlRewriteTimeout.action = toutActUseConfiguredResponse;
+                config->action = toutActUseConfiguredResponse;
             } else {
                 debugs(3, DBG_CRITICAL, "FATAL: unsuported \"on_timeout\"  action:" << value);
                 self_destruct();
             }
         } else if (strcasecmp(key, "response") == 0) {
-            Config.onUrlRewriteTimeout.response = xstrdup(value);
+            config->response = xstrdup(value);
         } else {
             debugs(3, DBG_CRITICAL, "FATAL: unsuported option " << key);
             self_destruct();
         }
     }
 
-    if (Config.onUrlRewriteTimeout.action == toutActUseConfiguredResponse && !Config.onUrlRewriteTimeout.response) {
+    if (config->action == toutActUseConfiguredResponse && !config->response) {
         debugs(3, DBG_CRITICAL, "FATAL: Expected 'response=' option after 'on_timeout=use_configured_response' option");
         self_destruct();
     }
 
-    if (Config.onUrlRewriteTimeout.action != toutActUseConfiguredResponse && Config.onUrlRewriteTimeout.response) {
+    if (config->action != toutActUseConfiguredResponse && config->response) {
         debugs(3, DBG_CRITICAL, "FATAL: 'response=' option is valid only when used with the  'on_timeout=use_configured_response' option");
         self_destruct();
     }
 }
 
 static void
-dump_url_rewrite_timeout(StoreEntry *entry, const char *name, SquidConfig &config)
+dump_UrlHelperTimeout(StoreEntry *entry, const char *name, SquidConfig::UrlHelperTimeout &config)
 {
     const char  *onTimedOutActions[] = {"bypass", "fail", "retry", "use_configured_response"};
-    assert(Config.onUrlRewriteTimeout.action >= 0 && Config.onUrlRewriteTimeout.action <= toutActUseConfiguredResponse);
+    assert(config.action >= 0 && config.action <= toutActUseConfiguredResponse);
 
     dump_time_t(entry, name, Config.Timeout.urlRewrite);
-    storeAppendPrintf(entry, " on_timeout=%s", onTimedOutActions[Config.onUrlRewriteTimeout.action]);
+    storeAppendPrintf(entry, " on_timeout=%s", onTimedOutActions[config.action]);
 
-    if (Config.onUrlRewriteTimeout.response)
-        storeAppendPrintf(entry, " response=\"%s\"", Config.onUrlRewriteTimeout.response);
+    if (config.response)
+        storeAppendPrintf(entry, " response=\"%s\"", config.response);
 
     storeAppendPrintf(entry, "\n");
 }
 
 static void
-free_url_rewrite_timeout(SquidConfig *config)
+free_UrlHelperTimeout(SquidConfig::UrlHelperTimeout *config)
 {
     Config.Timeout.urlRewrite = 0;
-    Config.onUrlRewriteTimeout.action = 0;
-    xfree(Config.onUrlRewriteTimeout.response);
-    Config.onUrlRewriteTimeout.response = NULL;
+    config->action = 0;
+    safe_free(config->response);
 }
 
 static void
-parse_configuration_includes_quoted_values(bool *recognizeQuotedValues)
+parse_configuration_includes_quoted_values(bool *)
 {
     int val = 0;
     parse_onoff(&val);
