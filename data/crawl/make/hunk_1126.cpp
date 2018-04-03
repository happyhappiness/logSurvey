 #ifdef WINDOWS32
   if (suspend_flag) {
         fprintf(stderr, "%s (pid = %d)\n", argv[0], GetCurrentProcessId());
-        fprintf(stderr, "%s is suspending for 30 seconds...", argv[0]);
+        fprintf(stderr, _("%s is suspending for 30 seconds..."), argv[0]);
         Sleep(30 * 1000);
-        fprintf(stderr, "done sleep(30). Continuing.\n");
+        fprintf(stderr, _("done sleep(30). Continuing.\n"));
   }
 #endif
 
