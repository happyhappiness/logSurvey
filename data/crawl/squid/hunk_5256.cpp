 
             }
 
+#if USE_WIN32_SERVICE
+
+        case 'n':
+            xfree(WIN32_Service_name);
+
+            WIN32_Service_name = xstrdup(optarg);
+
+            opt_signal_service = TRUE;
+
+            break;
+
+        case 'r':
+            opt_remove_service = TRUE;
+
+            break;
+
+#endif
+
         case 's':
 #if HAVE_SYSLOG
 
             opt_syslog_enable = 1;
+
             break;
+
 #else
 
             fatal("Logging to syslog not available on this platform");
+
             /* NOTREACHED */
 #endif
 
