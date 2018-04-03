 fatal_error_signal (sig)
      int sig;
 {
-#if defined(__MSDOS__) || defined(_AMIGA)
+#ifdef __MSDOS__
+  extern int dos_status, dos_command_running;
+
+  if (dos_command_running)
+    {
+      /* That was the child who got the signal, not us.  */
+      dos_status |= (sig << 8);
+      return;
+    }
   remove_intermediates (1);
+  exit (1);
+#else /* not __MSDOS__ */
 #ifdef _AMIGA
+  remove_intermediates (1);
   if (sig == SIGINT)
      fputs ("*** Break.\n", stderr);
 
   exit (10);
-#else
-  exit (1);
-#endif
-#else	/* Not MSDOS.  */
+#else /* not Amiga */
   handling_fatal_signal = 1;
 
   /* Set the handling for this signal to the default.
