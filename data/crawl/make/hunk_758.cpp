 # define REAP_MORE dead_children
 #endif
 
+  if (reap_lock)
+    fatal (NILF, _("INTERNAL: reap_children invoked while reap_lock set."));
+
   /* As long as:
 
        We have at least one child outstanding OR a shell function in progress,
