 
     // show results
     if ( showme ) {
-        printf( "#\n# Currently active values for %s:\n# %s\n",
-                ::programname, ::RCS_ID );
+        printf( "#\n# Currently active values for %s:\n",
+                ::programname);
         printf( "# Debug level       : " );
         if ( ::debugFlag ) printf( "%#6.4x", ::debugFlag );
         else printf( "production level" ); // printf omits 0x prefix for 0!
