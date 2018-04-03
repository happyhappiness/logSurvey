         fprintf(stderr, "Invalid config line: %s\n", s);
         return false;
     }
+
     // Keep the initial value on cfgparam. The ConfigParser  methods will write on cfgline
-    strcpy(cfgparam, tmp+1);
+    strncpy(cfgparam, tmp+1, sizeof(cfgparam)-1);
+    cfgparam[sizeof(cfgparam)-1] = '\0';
 
     // Initialize parser to point to the start of quoted string
     strtok(cfgline, w_space);
