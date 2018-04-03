         snprintf(from, MAXPATHLEN, "%s.%d", path, i - 1);
         snprintf(to, MAXPATHLEN, "%s.%d", path, i);
 #if _SQUID_OS2_ || _SQUID_WINDOWS_
-        remove(to);
+        if (remove(to) < 0) {
+            fprintf(stderr, "WARNING: remove '%s' failure: %s\n", to, xstrerror());
+        }
 #endif
-        rename(from, to);
+        if (rename(path, to) < 0 && errno != ENOENT) {
+            fprintf(stderr, "WARNING: rename '%s' to '%s' failure: %s\n", path, to, xstrerror());
+        }
     }
     if (rotate_count > 0) {
         snprintf(to, MAXPATHLEN, "%s.%d", path, 0);
 #if _SQUID_OS2_ || _SQUID_WINDOWS_
-        remove(to);
+        if (remove(to) < 0) {
+            fprintf(stderr, "WARNING: remove '%s' failure: %s\n", to, xstrerror());
+        }
 #endif
-        rename(path, to);
+        if (rename(path, to) < 0 && errno != ENOENT) {
+            fprintf(stderr, "WARNING: rename %s to %s failure: %s\n", path, to, xstrerror());
+        }
     }
 }
 
