     abort();
 }
 
-/* fatal with dumping core */
 void
-_debug_trap(const char *message)
+debug_trap(const char *message)
 {
     if (!opt_catch_signals)
 	fatal_dump(message);
-    _db_print(0, 0, "WARNING: %s\n", message);
+    _db_level = 0;
+    _db_print("WARNING: %s\n", message);
 }
 
 void
