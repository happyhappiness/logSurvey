                             fdwControl,	/* control value to send  */
                             &ssStatus)) {	/* address of status info */
             fprintf(stderr, "%s: ERROR: Could not Control Service %s\n",
-                    APP_SHORTNAME, WIN32_Service_name);
+                    APP_SHORTNAME, service_name);
             exit(1);
         } else {
             /* Print the service status. */
-            printf("\nStatus of %s Service:\n", WIN32_Service_name);
+            printf("\nStatus of %s Service:\n", service_name);
             printf("  Service Type: 0x%lx\n", ssStatus.dwServiceType);
             printf("  Current State: 0x%lx\n", ssStatus.dwCurrentState);
             printf("  Controls Accepted: 0x%lx\n", ssStatus.dwControlsAccepted);
