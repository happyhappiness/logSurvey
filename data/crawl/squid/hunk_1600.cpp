                 password = getpass("Proxy password: ");
 #endif
             if (!password) {
-                fprintf(stderr, "ERROR: Proxy password missing\n");
+                std::cerr << "ERROR: Proxy password missing" << std::endl;
                 exit(1);
             }
             snprintf(buf, BUFSIZ, "%s:%s", user, password);
