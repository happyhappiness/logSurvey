         } else if ( debug & 0x02 ) {
             fprintf( stderr, "# creating %s\n", filename );
         }
-        *t++ = '/';
+        *t = '/';
+        ++t;
     }
 
     // create file
