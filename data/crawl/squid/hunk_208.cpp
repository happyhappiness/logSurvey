     ll->fd = file_open(realpath, O_WRONLY | O_CREAT | O_TEXT);
 
     if (DISK_ERROR == ll->fd && lf->flags.fatal) {
-        debugs(50, DBG_CRITICAL, "ERROR: logfileRotate: " << lf->path << ": " << xstrerror());
-        fatalf("Cannot open %s: %s", lf->path, xstrerror());
+        int xerrno = errno;
+        debugs(50, DBG_CRITICAL, MYNAME << "ERROR: " << lf->path << ": " << xstrerr(xerrno));
+        fatalf("Cannot open %s: %s", lf->path, xstrerr(xerrno));
     }
 }
 
