     if (!lf->flags.fatal)
         return;
 
-    fatalf("logfileWrite: %s: %s\n", lf->path, xstrerror());
+    fatalf("logfileWrite: %s: %s\n", lf->path, xstrerr(xerrno));
 }
 
 static void
