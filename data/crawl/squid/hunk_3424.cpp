             fprintf(stderr, "default SPN is HTTP/fqdn@DEFAULT_REALM\n");
             exit(0);
         default:
-            fprintf(stderr, "%s| %s: unknown option: -%c.\n", LogTime(),
+            fprintf(stderr, "%s| %s: WARNING: unknown option: -%c.\n", LogTime(),
                     PROGRAM, opt);
         }
     }
 
     if (debug)
-        fprintf(stderr, "%s| %s: Starting version %s\n", LogTime(), PROGRAM,
+        fprintf(stderr, "%s| %s: INFO: Starting version %s\n", LogTime(), PROGRAM,
                 SQUID_KERB_AUTH_VERSION);
     if (service_principal && strcasecmp(service_principal, "GSS_C_NO_NAME")) {
         service.value = service_principal;
