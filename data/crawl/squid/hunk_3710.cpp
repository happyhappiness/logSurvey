 
 bool Adaptation::Config::Enabled = false;
 char *Adaptation::Config::masterx_shared_name = NULL;
+int Adaptation::Config::service_iteration_limit = 16;
 
 void
 Adaptation::Config::parseService()
 {
     ServiceConfig *cfg = new ServiceConfig;
-    cfg->parse();
+    if (!cfg->parse()) {
+        fatalf("%s:%d: malformed adaptation service configuration",
+            cfg_filename, config_lineno);
+    }
     serviceConfigs.push_back(cfg);
 }
 
