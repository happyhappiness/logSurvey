   else if (pid != 0)
     {
       /* parent, no error */
-      printf (_("Continuing in background.\n"));
+      printf (_("Continuing in background, pid %d.\n"), (int)pid);
       if (changedp)
 	printf (_("Output will be written to `%s'.\n"), opt.lfilename);
-      exit (0);
+      exit (0);			/* #### should we use _exit()? */
     }
-  /* child: keep running */
+
+  /* child: give up the privileges and keep running. */
+  setsid ();
+  freopen ("/dev/null", "r", stdin);
+  freopen ("/dev/null", "w", stdout);
+  freopen ("/dev/null", "w", stderr);
 }
 #endif /* not WINDOWS */
 
