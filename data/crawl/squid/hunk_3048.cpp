 // returns: true, if every subdir && action was successful.
 {
     struct dirent* entry;
-    if ( debug & 0x01 )
+    if ( debugFlag & 0x01 )
         fprintf( stderr, "# [2] %s\n", directory );
 
     DIR* dir = opendir( directory );