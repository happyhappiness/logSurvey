     if (!lf->flags.fatal)
         return;
 
-    fatalf("logfileWrite (stdio): %s: %s\n", lf->path, xstrerror());
+    fatalf("logfileWrite: %s: %s\n", lf->path, xstrerror());
 }
 
 static void
