 	httpd_accel_mode);
 
     /* end of stats */
-    storeAppendPrintf(sentry, "}\n");
+    storeAppendPrintf(sentry, close_bracket);
 }
 
 
-void log_append(obj, url, id, size, action, method, http_code, msec, ident)
+void log_append(obj, url, id, size, action, method, http_code, msec, ident, hier)
      cacheinfo *obj;
      char *url;
      char *id;
