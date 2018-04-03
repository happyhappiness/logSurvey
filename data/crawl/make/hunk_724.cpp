 
   exit (10);
 #else /* not Amiga */
+#ifdef WINDOWS32
+  extern HANDLE main_thread;
+
+  /* Windows creates a sperate thread for handling Ctrl+C, so we need
+     to suspend the main thread, or else we will have race conditions
+     when both threads call reap_children.  */
+  if (main_thread)
+    {
+      DWORD susp_count = SuspendThread (main_thread);
+
+      if (susp_count != 0)
+	fprintf (stderr, "SuspendThread: suspend count = %ld\n", susp_count);
+      else if (susp_count == (DWORD)-1)
+	{
+	  DWORD ierr = GetLastError ();
+
+	  fprintf (stderr, "SuspendThread: error %ld: %s\n",
+		   ierr, map_windows32_error_to_string (ierr));
+	}
+    }
+#endif
   handling_fatal_signal = 1;
 
   /* Set the handling for this signal to the default.
