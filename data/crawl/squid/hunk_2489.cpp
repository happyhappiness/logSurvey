                 entries = curr;
                 state = sSTART;
             } else {
-                printf("Error on line %d\n", linenum);
+                std::cerr << "Error on line " << linenum << std::endl;
                 exit(1);
             }
 
