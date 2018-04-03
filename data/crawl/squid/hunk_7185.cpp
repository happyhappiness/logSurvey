 static void
 storePutUnusedFileno(int fileno)
 {
-    if (!storeDirMapBitTest(fileno))
-	fatal_dump("storePutUnusedFileno: fileno not in use");
+    assert(storeDirMapBitTest(fileno));
     storeDirMapBitReset(fileno);
     if (fileno_stack_count < FILENO_STACK_SIZE)
 	fileno_stack[fileno_stack_count++] = fileno;