   decode_env_switches ("MFLAGS", 6);
 #endif
   decode_switches (argc, argv, 0);
+#ifdef WIN32
+  if (suspend_flag) {
+        fprintf(stderr, "%s (pid = %d)\n", argv[0], GetCurrentProcessId());
+        fprintf(stderr, "%s is suspending for 30 seconds...", argv[0]);
+        Sleep(30 * 1000);
+        fprintf(stderr, "done sleep(30). Continuing.\n");
+  }
+#endif
 
   /* Print version information.  */
 
