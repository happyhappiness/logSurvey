                 curr->loc = xstrdup("none");
                 state = sDOC;
             } else {
-                printf("Error on line %d\n", linenum);
-                printf("--> %s\n", buff);
+                std::cerr << "Error on line " << linenum << std::endl <<
+                    "--> " << buff << std::endl;
                 exit(1);
             }
 
