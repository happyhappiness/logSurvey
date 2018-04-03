                {"negotiate", negotiate_parms, 1}
              };
 
-    for (unsigned scheme=0; scheme < 4; scheme++)
-        setup_scheme(getConfig(params[scheme].name), params[scheme].params, params[scheme].paramlength);
+    for (unsigned scheme=0; scheme < 4; scheme++) {
+        AuthConfig *schemeConfig;
+        schemeConfig = getConfig(params[scheme].name);
+        if (schemeConfig != NULL)
+            setup_scheme (schemeConfig, params[scheme].params, 
+                params[scheme].paramlength);
+		else
+            fprintf(stderr,"Skipping unknown authentication scheme '%s'.\n", 
+                params[scheme].name);
+    }
 
     authenticateInit(&config);
 
