                 lineAdd(&curr->default_if_none, ptr);
             } else if (!strncmp(buff, "LOC:", 4)) {
                 if ((ptr = strtok(buff + 4, WS)) == NULL) {
-                    printf("Error on line %d\n", linenum);
+                    std::cerr << "Error on line " << linenum << std::endl;
                     exit(1);
                 }
 
                 curr->loc = xstrdup(ptr);
             } else if (!strncmp(buff, "TYPE:", 5)) {
                 if ((ptr = strtok(buff + 5, WS)) == NULL) {
-                    printf("Error on line %d\n", linenum);
+                    std::cerr << "Error on line " << linenum << std::endl;
                     exit(1);
                 }
 
