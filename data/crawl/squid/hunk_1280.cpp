             if (DeleteService(schService) == 0)
                 fprintf(stderr, "DeleteService failed.\n");
             else
-                printf("Service %s deleted successfully.\n", service_name);
+                printf("Service " SQUIDSBUFPH " deleted successfully.\n", SQUIDSBUFPRINT(service_name));
 
             CloseServiceHandle(schService);
         }
