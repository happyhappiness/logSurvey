 
     if (use_global) {
         if ((machinedomain = GetDomainName()) == NULL) {
-            fprintf(stderr, "%s Can't read machine domain\n", myname);
+            fprintf(stderr, "%s: FATAL: Can't read machine domain\n", program_name);
             exit(1);
         }
         strlwr(machinedomain);
