                 password = getpass("WWW password: ");
 #endif
             if (!password) {
-                fprintf(stderr, "ERROR: WWW password missing\n");
+                std::cerr << "ERROR: WWW password missing" << std::endl;
                 exit(1);
             }
             snprintf(buf, BUFSIZ, "%s:%s", user, password);
