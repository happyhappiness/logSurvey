      StoreEntry *e;
 {
     debug(20, 3, "destroy_StoreEntry: destroying %p\n", e);
-    if (!e)
-	fatal_dump("destroy_StoreEntry: NULL Entry");
+    if (!e) {
+	debug_trap("destroy_StoreEntry: NULL Entry");
+	return;
+    }
     if (e->mem_obj)
 	destroy_MemObject(e->mem_obj);
     if (e->url) {
