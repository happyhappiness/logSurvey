             return 1;
         }
 
-        WIN32_Service_name = xstrdup(c+1);
-        DispatchTable[0].lpServiceName=WIN32_Service_name;
-        strcat(REGKEY, WIN32_Service_name);
-        keys[4] = WIN32_Service_name;
+        service_name = xstrdup(c+1);
+        DispatchTable[0].lpServiceName=service_name;
+        strcat(REGKEY, service_name);
+        keys[4] = service_name;
 
         if (!StartServiceCtrlDispatcher(DispatchTable)) {
             fprintf(stderr, "StartServiceCtrlDispatcher error = %ld\n",
