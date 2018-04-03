 logfileOpen(const char *path, size_t bufsz, int fatal_flag)
 {
     int fd;
-    Logfile *lf;
-    fd = file_open(path, O_WRONLY | O_CREAT | O_TEXT);
-
-    if (DISK_ERROR == fd) {
-        if (ENOENT == errno && fatal_flag) {
-            fatalf("Cannot open '%s' because\n"
-                   "\tthe parent directory does not exist.\n"
-                   "\tPlease create the directory.\n", path);
-        } else if (EACCES == errno && fatal_flag) {
-            fatalf("Cannot open '%s' for writing.\n"
-                   "\tThe parent directory must be writeable by the\n"
-                   "\tuser '%s', which is the cache_effective_user\n"
-                   "\tset in squid.conf.", path, Config.effectiveUser);
-        } else {
-            debug(50, 1) ("logfileOpen: %s: %s\n", path, xstrerror());
-            return NULL;
-        }
-    }
+    Logfile *lf = static_cast<Logfile *>(xcalloc(1, sizeof(*lf)));
 
-    lf = static_cast<Logfile *>(xcalloc(1, sizeof(*lf)));
-    lf->fd = fd;
+    xstrncpy(lf->path, path, MAXPATHLEN);
 
-    if (fatal_flag)
-        lf->flags.fatal = 1;
+    if (strcmp(path, "syslog") == 0) {
+        lf->flags.syslog = 1;
+        lf->syslog_priority = LOG_INFO;
+        lf->fd = -1;
+    } else {
+        fd = file_open(path, O_WRONLY | O_CREAT | O_TEXT);
+
+        if (DISK_ERROR == fd) {
+            if (ENOENT == errno && fatal_flag) {
+                fatalf("Cannot open '%s' because\n"
+                       "\tthe parent directory does not exist.\n"
+                       "\tPlease create the directory.\n", path);
+            } else if (EACCES == errno && fatal_flag) {
+                fatalf("Cannot open '%s' for writing.\n"
+                       "\tThe parent directory must be writeable by the\n"
+                       "\tuser '%s', which is the cache_effective_user\n"
+                       "\tset in squid.conf.", path, Config.effectiveUser);
+            } else {
+                debug(50, 1) ("logfileOpen: %s: %s\n", path, xstrerror());
+                return NULL;
+            }
+        }
 
-    xstrncpy(lf->path, path, MAXPATHLEN);
+        lf->fd = fd;
 
-    if (bufsz > 0) {
-        lf->buf = (char *) xmalloc(bufsz);
-        lf->bufsz = bufsz;
+        if (bufsz > 0) {
+            lf->buf = (char *) xmalloc(bufsz);
+            lf->bufsz = bufsz;
+        }
     }
 
+    if (fatal_flag)
+        lf->flags.fatal = 1;
+
     return lf;
 }
 
 void
 logfileClose(Logfile * lf)
 {
     logfileFlush(lf);
-    file_close(lf->fd);
+
+    if (lf->fd >= 0)
+        file_close(lf->fd);
 
     if (lf->buf)
         xfree(lf->buf);
