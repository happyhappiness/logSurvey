   return value;
 }
 #endif
+
+
+/* This code is stolen from gnulib.
+   If/when we abandon the requirement to work with K&R compilers, we can
+   remove this (and perhaps other parts of GNU make!) and migrate to using
+   gnulib directly.
+
+   This is called only through atexit(), which means die() has already been
+   invoked.  So, call exit() here directly.  Apparently that works...?
+*/
+
+/* Close standard output, exiting with status 'exit_failure' on failure.
+   If a program writes *anything* to stdout, that program should close
+   stdout and make sure that it succeeds before exiting.  Otherwise,
+   suppose that you go to the extreme of checking the return status
+   of every function that does an explicit write to stdout.  The last
+   printf can succeed in writing to the internal stream buffer, and yet
+   the fclose(stdout) could still fail (due e.g., to a disk full error)
+   when it tries to write out that buffered data.  Thus, you would be
+   left with an incomplete output file and the offending program would
+   exit successfully.  Even calling fflush is not always sufficient,
+   since some file systems (NFS and CODA) buffer written/flushed data
+   until an actual close call.
+
+   Besides, it's wasteful to check the return value from every call
+   that writes to stdout -- just let the internal stream state record
+   the failure.  That's what the ferror test is checking below.
+
+   It's important to detect such failures and exit nonzero because many
+   tools (most notably `make' and other build-management systems) depend
+   on being able to detect failure in other tools via their exit status.  */
+
+void
+close_stdout (void)
+{
+  int prev_fail = ferror (stdout);
+  int fclose_fail = fclose (stdout);
+
+  if (prev_fail || fclose_fail)
+    {
+      if (fclose_fail)
+        error (NILF, _("write error: %s"), strerror (errno));
+      else
+        error (NILF, _("write error"));
+      exit (EXIT_FAILURE);
+    }
+}
