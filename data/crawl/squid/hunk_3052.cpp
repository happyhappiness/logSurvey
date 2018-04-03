                         return 0;
                     } else {
                         // parent mode
-                        if ( ::debug ) printf( "forked child %d\n", (int) child[i] );
+                        if ( ::debugFlag ) printf( "forked child %d\n", (int) child[i] );
                     }
                 }
             }
