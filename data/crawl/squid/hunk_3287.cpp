         if ( rc != SASL_OK ) {
 #if SASL_VERSION_MAJOR < 2
             if ( errstr ) {
-                fprintf( stderr, "errstr %s\n", errstr );
+                debug("errstr %s\n", errstr);
             }
             if ( rc != SASL_BADAUTH ) {
-                fprintf( stderr, "error %d %s\n", rc, sasl_errstring(rc, NULL, NULL ));
-            }
+                debug("ERROR: %d %s\n", rc, sasl_errstring(rc, NULL, NULL));
+                SEND_ERR(sasl_errstring(rc, NULL, NULL));
+            } else
 #endif
-            fprintf( stdout, "ERR\n" );
+                SEND_ERR("");
         } else {
-            fprintf( stdout, "OK\n" );
+            SEND_OK("");
         }
-
     }
 
-    sasl_dispose( &conn );
+    sasl_dispose(&conn);
     sasl_done();
-
     return 0;
 }
