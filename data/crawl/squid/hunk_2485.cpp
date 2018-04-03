                 char *name, *aliasname;
 
                 if ((name = strtok(buff + 5, WS)) == NULL) {
-                    printf("Error in input file\n");
+                    std::cerr << "Error in input file\n";
                     exit(1);
                 }
 
