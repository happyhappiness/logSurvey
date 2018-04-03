 }
 
 static int
-ipcache_compareLastRef(ipcache_entry ** e1, ipcache_entry ** e2)
+ipcache_compareLastRef(const void *A, const void *B)
 {
-    if (!e1 || !e2)
-	fatal_dump(NULL);
+    const ipcache_entry *const *e1 = A;
+    const ipcache_entry *const *e2 = B;
+    assert(e1 != NULL && e2 != NULL);
     if ((*e1)->lastref > (*e2)->lastref)
 	return (1);
     if ((*e1)->lastref < (*e2)->lastref)
