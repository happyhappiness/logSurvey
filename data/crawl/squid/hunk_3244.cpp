         pid = waitpid(-1, &status, 0);
 
 #endif
-
-        time(&stop);
-
-        if (WIFEXITED(status)) {
-            syslog(LOG_NOTICE,
-                   "Squid Parent: child process %d exited with status %d",
-                   pid, WEXITSTATUS(status));
-        } else if (WIFSIGNALED(status)) {
-            syslog(LOG_NOTICE,
-                   "Squid Parent: child process %d exited due to signal %d with status %d",
-                   pid, WTERMSIG(status), WEXITSTATUS(status));
-        } else {
-            syslog(LOG_NOTICE, "Squid Parent: child process %d exited", pid);
+        // Loop to collect all stopped kids before we go to sleep below.
+        do {
+            Kid* kid = TheKids.find(pid);
+            if (kid) {
+                kid->stop(status);
+                if (kid->calledExit()) {
+                    syslog(LOG_NOTICE,
+                           "Squid Parent: child process %d exited with status %d",
+                           kid->getPid(), kid->exitStatus());
+                } else if (kid->signaled()) {
+                    syslog(LOG_NOTICE,
+                           "Squid Parent: child process %d exited due to signal %d with status %d",
+                           kid->getPid(), kid->termSignal(), kid->exitStatus());
+                } else {
+                    syslog(LOG_NOTICE, "Squid Parent: child process %d exited", kid->getPid());
+                }
+            } else {
+                syslog(LOG_NOTICE, "Squid Parent: unknown child process %d exited", pid);
+            }
+#ifdef _SQUID_NEXT_
+        } while ((pid = wait3(&status, WNOHANG, NULL)) > 0);
+#else
         }
+        while ((pid = waitpid(-1, &status, WNOHANG)) > 0);
+#endif
 
-        if (stop - start < 10)
-            failcount++;
-        else
-            failcount = 0;
+        if (TheKids.allExitedHappy()) {
+            exit(0);
+        }
 
-        if (failcount == 5) {
+        if (TheKids.allHopeless()) {
             syslog(LOG_ALERT, "Exiting due to repeated, frequent failures");
             exit(1);
         }
 
-        if (WIFEXITED(status))
-            if (WEXITSTATUS(status) == 0)
-                exit(0);
-
-        if (WIFSIGNALED(status)) {
-            switch (WTERMSIG(status)) {
-
-            case SIGKILL:
-                exit(0);
-                break;
-
-            case SIGINT:
-            case SIGTERM:
-                syslog(LOG_ALERT, "Exiting due to unexpected forced shutdown");
-                exit(1);
-                break;
+        if (TheKids.allSignaled(SIGKILL)) {
+            exit(0);
+        }
 
-            default:
-                break;
-            }
+        if (TheKids.allSignaled(SIGINT) || TheKids.allSignaled(SIGTERM)) {
+            syslog(LOG_ALERT, "Exiting due to unexpected forced shutdown");
+            exit(1);
         }
 
         squid_signal(SIGINT, SIG_DFL, SA_RESTART);
