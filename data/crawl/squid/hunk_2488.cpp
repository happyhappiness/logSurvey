                 curr->type = xstrdup(ptr);
             } else if (!strncmp(buff, "IFDEF:", 6)) {
                 if ((ptr = strtok(buff + 6, WS)) == NULL) {
-                    printf("Error on line %d\n", linenum);
+                    std::cerr << "Error on line " << linenum << std::endl;
                     exit(1);
                 }
 
