 	debug(20, 0, "%s", storeToString(e));
 	fatal_dump(NULL);
     }
-    /* free up memory data */
-    if (e->mem_obj->data) {
-	e->mem_obj->data->mem_free(e->mem_obj->data);
-	e->mem_obj->data = NULL;
-	--meta_data.hot_vm;
-    }
-    store_mem_size -= e->object_len - e->mem_obj->e_lowest_offset;
+    destroy_MemObjectData(e->mem_obj);
+    e->mem_obj->data = NULL;
     debug(20, 8, "storePurgeMem: Freeing %d in-memory bytes\n",
 	e->object_len);
     debug(20, 8, "storePurgeMem: store_mem_size = %d\n", store_mem_size);
