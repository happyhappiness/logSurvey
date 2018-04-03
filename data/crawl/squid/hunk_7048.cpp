     debug(20, i) ("  %6d were purged\n", n_purged);
     debug(20, i) ("  %6d were released\n", n_released);
     xfree(list);
+#endif
+
+    debug(20, 0) ("storeGetMemSpace stats:\n");
+    debug(20, 0) ("  %6d HOT objects\n", meta_data.hot_vm);
+    debug(20, 0) ("  %6d were purged\n", n_purged);
+    debug(20, 0) ("  %6d were released\n", n_released);
 }
 
+#if OLD_CODE
 static int
 compareSize(StoreEntry ** e1, StoreEntry ** e2)
 {
     if (!e1 || !e2)
 	fatal_dump(NULL);
-    if ((*e1)->mem_obj->e_current_len > (*e2)->mem_obj->e_current_len)
+    if ((*e1)->mem_obj->inmem_hi > (*e2)->mem_obj->inmem_hi)
 	return (1);
-    if ((*e1)->mem_obj->e_current_len < (*e2)->mem_obj->e_current_len)
+    if ((*e1)->mem_obj->inmem_hi < (*e2)->mem_obj->inmem_hi)
 	return (-1);
     return (0);
 }
+#endif
 
 static int
 compareLastRef(StoreEntry ** e1, StoreEntry ** e2)
