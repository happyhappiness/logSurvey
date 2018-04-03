 {
   int i;
   if (malloc_count - free_count > SZ)
-    abort ();
+    {
+      fprintf (stderr, "Increase SZ to a larger value and recompile.\n");
+      fflush (stderr);
+      abort ();
+    }
 
   i = ptr_position (ptr);
   malloc_table[i].ptr = ptr;
