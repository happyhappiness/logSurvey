 bool Adaptation::Config::Enabled = false;
 char *Adaptation::Config::masterx_shared_name = NULL;
 int Adaptation::Config::service_iteration_limit = 16;
+int Adaptation::Config::send_client_ip = false;
+int Adaptation::Config::send_username = false;
+int Adaptation::Config::use_indirect_client = true;
+
+
+Adaptation::ServiceConfig*
+Adaptation::Config::newServiceConfig() const
+{
+    return new ServiceConfig();
+}
 
 void
 Adaptation::Config::parseService()
 {
-    ServiceConfig *cfg = new ServiceConfig;
+    ServiceConfigPointer cfg = newServiceConfig();
     if (!cfg->parse()) {
         fatalf("%s:%d: malformed adaptation service configuration",
                cfg_filename, config_lineno);
