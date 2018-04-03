             break;
 
         case 'd':
-            ::debugFlag = optarg ? 0 : strtoul( optarg, 0, 0 );
+            if ( !optarg || !*optarg ) {
+                fprintf( stderr, "%c expects a mask parameter. Debug disabled.\n", option );
+                ::debugFlag = 0;
+            } else
+                ::debugFlag = (strtoul(optarg, NULL, 0) & 0xFFFFFFFF);
             break;
 
         case 'E':