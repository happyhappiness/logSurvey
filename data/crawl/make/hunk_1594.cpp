 child_handler (sig)
      int sig;
 {
-  child_died = 1;
+  ++dead_children;
+
+  if (debug_flag)
+    printf ("Got a SIGCHLD; %d unreaped children.\n", dead_children);
+
   return 0;
 }
 
