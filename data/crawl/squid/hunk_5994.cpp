     if (stat(path, &sb) < 0)
 	fatalf("%s: %s", path, xstrerror());
 }
-
-
