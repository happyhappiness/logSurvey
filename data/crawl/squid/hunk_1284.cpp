             return 1;
         }
 
-        service_name = xstrdup(c+1);
-        DispatchTable[0].lpServiceName=service_name;
-        strcat(REGKEY, service_name);
-        keys[4] = service_name;
+        service_name = SBuf(c+1);
+        const char *service = service_name.c_str();
+        DispatchTable[0].lpServiceName=service;
+        strcat(REGKEY, service);
+        keys[4] = service;
 
         if (!StartServiceCtrlDispatcher(DispatchTable)) {
             fprintf(stderr, "StartServiceCtrlDispatcher error = %ld\n",
