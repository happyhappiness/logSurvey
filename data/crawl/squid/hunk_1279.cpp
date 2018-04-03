     if (!schSCManager)
         fprintf(stderr, "OpenSCManager failed\n");
     else {
-        schService = OpenService(schSCManager, service_name, SERVICE_ALL_ACCESS);
+        schService = OpenService(schSCManager, service, SERVICE_ALL_ACCESS);
 
         if (schService == NULL)
             fprintf(stderr, "OpenService failed\n");
