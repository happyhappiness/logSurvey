 
     case 'm':
         if (building_deny_info_url) break;
+#if USE_AUTH
         p = auth_user_request->denyMessage("[not available]");
+#else
+        p = "-";
+#endif
         break;
 
     case 'M':
