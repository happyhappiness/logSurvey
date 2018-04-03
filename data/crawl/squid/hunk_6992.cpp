 }
 
 static int
-fqdncache_compareLastRef(fqdncache_entry ** e1, fqdncache_entry ** e2)
+fqdncache_compareLastRef(const void *A, const void *B)
 {
-    if (!e1 || !e2)
-	fatal_dump(NULL);
+    fqdncache_entry *const *e1 = A;
+    fqdncache_entry *const *e2 = B;
+    assert(e1 != NULL && e2 != NULL);
     if ((*e1)->lastref > (*e2)->lastref)
 	return (1);
     if ((*e1)->lastref < (*e2)->lastref)
