             }
 
             if (x != 0)
-                fprintf(stderr, "client: ERROR: Cannot send file.\n");
+                std::cerr << "ERROR: Cannot send file." << std::endl;
             else
-                fprintf(stderr, "done.\n");
+                debugVerbose(1, "done.");
         }
         /* Read the data */
 
