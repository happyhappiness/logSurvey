     char szPath[512];
     int lenpath;
 
-    if (!WIN32_Service_name)
-        WIN32_Service_name = xstrdup(_WIN_SQUID_DEFAULT_SERVICE_NAME);
+    if (!service_name)
+        service_name = xstrdup(APP_SHORTNAME);
 
-    strcat(REGKEY, WIN32_Service_name);
+    strcat(REGKEY, service_name);
 
-    keys[4] = WIN32_Service_name;
+    keys[4] = service_name;
 
     if ((lenpath = GetModuleFileName(NULL, ServicePath, 512)) == 0) {
         fprintf(stderr, "Can't get executable path\n");
         exit(1);
     }
 
-    snprintf(szPath, sizeof(szPath), "%s %s:%s", ServicePath, _WIN_SQUID_SERVICE_OPTION, WIN32_Service_name);
+    snprintf(szPath, sizeof(szPath), "%s %s:%s", ServicePath, _WIN_SQUID_SERVICE_OPTION, service_name);
     schSCManager = OpenSCManager(NULL,	/* machine (NULL == local)    */
                                  NULL,			/* database (NULL == default) */
                                  SC_MANAGER_ALL_ACCESS	/* access required            */
