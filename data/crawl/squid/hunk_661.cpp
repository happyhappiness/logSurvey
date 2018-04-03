             fatalf("Unable to find SSL engine '%s'\n", Config.SSL.ssl_engine);
 
         if (!ENGINE_set_default(e, ENGINE_METHOD_ALL)) {
-            int ssl_error = ERR_get_error();
+            const int ssl_error = ERR_get_error();
             fatalf("Failed to initialise SSL engine: %s\n", ERR_error_string(ssl_error, NULL));
         }
     }
