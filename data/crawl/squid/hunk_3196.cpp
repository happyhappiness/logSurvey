             break;
 #endif
         case 'd':
-            debug_mode++;
+            debug_enabled = 1;
             break;
         default:
             fprintf(stderr, PROGRAM_NAME ": ERROR: Unknown command line option '%c'\n", option);
