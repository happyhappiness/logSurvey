             }
             break;
         case 'P':
+            if ( !optarg || !*optarg ) {
+                fprintf( stderr, "%c requires a mode argument!\n", option );
+                exit(1);
+            }
             ::purgeMode = ( strtol( optarg, 0, 0 ) & 0x07 );
             break;
         case 's':