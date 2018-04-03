         path = pathbuf;
     }
 
-    if (stat(path, &sb) < 0)
-        fatalf("%s %s: %s", name, path, xstrerror());
+    if (stat(path, &sb) < 0) {
+        if (opt_send_signal == -1 || opt_send_signal == SIGHUP)
+            fatalf("%s %s: %s", name, path, xstrerror());
+        else
+            fprintf(stderr, "WARNING: %s %s: %s\n", name, path, xstrerror());
+    }
 }
 
 char *
