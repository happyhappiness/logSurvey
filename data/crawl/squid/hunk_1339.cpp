     char szPath[512];
     int lenpath;
 
-    if (!service_name)
-        service_name = xstrdup(APP_SHORTNAME);
+    if (service_name.isEmpty())
+        service_name = SBuf(APP_SHORTNAME);
 
-    strcat(REGKEY, service_name);
+    const char *service = service_name.c_str();
+    strcat(REGKEY, service);
 
-    keys[4] = service_name;
+    keys[4] = service;
 
     if ((lenpath = GetModuleFileName(NULL, ServicePath, 512)) == 0) {
         fprintf(stderr, "Can't get executable path\n");
         exit(1);
     }
 
-    snprintf(szPath, sizeof(szPath), "%s %s:%s", ServicePath, _WIN_SQUID_SERVICE_OPTION, service_name);
+    snprintf(szPath, sizeof(szPath), "%s %s:" SQUIDSBUFPH, ServicePath, _WIN_SQUID_SERVICE_OPTION, SQUIDSBUFPRINT(service_name));
     schSCManager = OpenSCManager(NULL,	/* machine (NULL == local)    */
                                  NULL,			/* database (NULL == default) */
                                  SC_MANAGER_ALL_ACCESS	/* access required            */