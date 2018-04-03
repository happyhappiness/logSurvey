 
         if (!ENGINE_set_default(e, ENGINE_METHOD_ALL)) {
             const int ssl_error = ERR_get_error();
-            fatalf("Failed to initialise SSL engine: %s\n", ERR_error_string(ssl_error, NULL));
+            fatalf("Failed to initialise SSL engine: %s\n", Security::ErrorString(ssl_error));
         }
     }
 #else
