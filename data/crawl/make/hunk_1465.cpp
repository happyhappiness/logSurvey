     error ("*** [%s] %s%s",
 	   target_name, strsignal (exit_sig),
 	   coredump ? " (core dumped)" : "");
+#endif
 }
 
 static unsigned int dead_children = 0;
 
+#ifdef VMS
+/* Wait for nchildren children to terminate */
+static void
+vmsWaitForChildren(int *status)
+{
+  while (1)
+    {
+      if (!vms_jobsefnmask)
+	{
+	  *status = 0;
+	  return;
+	}
+
+      *status = sys$wflor (32, vms_jobsefnmask);
+    }
+  return;
+}
+#endif
+
+
 /* Notice that a child died.
    reap_children should be called when convenient.  */
 RETSIGTYPE
