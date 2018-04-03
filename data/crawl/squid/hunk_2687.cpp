     file_close(ll->fd);		/* always close */
 
     if (Config.Log.rotateNumber > 0) {
-        snprintf(to, MAXPATHLEN, "%s.%d", lf->path, 0);
-        xrename(lf->path, to);
+        snprintf(to, MAXPATHLEN, "%s.%d", realpath, 0);
+        xrename(realpath, to);
     }
     /* Reopen the log.  It may have been renamed "manually" */
-    ll->fd = file_open(lf->path, O_WRONLY | O_CREAT | O_TEXT);
+    ll->fd = file_open(realpath, O_WRONLY | O_CREAT | O_TEXT);
 
     if (DISK_ERROR == ll->fd && lf->flags.fatal) {
-        debugs(50, DBG_CRITICAL, "logfileRotate (stdio): " << lf->path << ": " << xstrerror());
+        debugs(50, DBG_CRITICAL, "ERROR: logfileRotate: " << lf->path << ": " << xstrerror());
         fatalf("Cannot open %s: %s", lf->path, xstrerror());
     }
 }
