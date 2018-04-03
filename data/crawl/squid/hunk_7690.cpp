     new->mem_free_data_upto = memFreeDataUpto;
     new->mem_append = memAppend;
     new->mem_copy = memCopy;
+#ifdef UNUSED_CODE
     new->mem_grep = memGrep;
+#endif
     return new;
 }
 
-void *get_free_request_t()
+static void *get_free_thing(thing)
+	stmem_stats *thing;
 {
-    void *req = NULL;
-    if (!empty_stack(&request_pool.free_page_stack)) {
-	req = pop(&request_pool.free_page_stack);
+    void *p = NULL;
+    if (!empty_stack(&thing->free_page_stack)) {
+        p = pop(&thing->free_page_stack);
+        if (p == NULL)
+	    fatal_dump("get_free_thing: NULL pointer?");
     } else {
-	req = xmalloc(sizeof(request_t));
-	request_pool.total_pages_allocated++;
+        p = xmalloc(thing->page_size);
+	thing->total_pages_allocated++;
     }
-    request_pool.n_pages_in_use++;
-    if (req == NULL)
-	fatal_dump("get_free_request_t: Null pointer?");
-    memset(req, '\0', sizeof(request_t));
-    return (req);
+    thing->n_pages_in_use++;
+    memset(p, '\0', thing->page_size);
+    return p;
 }
 
-void put_free_request_t(req)
-     void *req;
+void *get_free_request_t()
 {
-    if (full_stack(&request_pool.free_page_stack))
-	request_pool.total_pages_allocated--;
-    request_pool.n_pages_in_use--;
-    push(&request_pool.free_page_stack, req);
+    return get_free_thing(&request_pool);
 }
 
 void *get_free_mem_obj()
 {
-    void *mem = NULL;
-    if (!empty_stack(&mem_obj_pool.free_page_stack)) {
-	mem = pop(&mem_obj_pool.free_page_stack);
-    } else {
-	mem = xmalloc(sizeof(MemObject));
-	mem_obj_pool.total_pages_allocated++;
-    }
-    mem_obj_pool.n_pages_in_use++;
-    if (mem == NULL)
-	fatal_dump("get_free_mem_obj: Null pointer?");
-    memset(mem, '\0', sizeof(MemObject));
-    return (mem);
+    return get_free_thing(&mem_obj_pool);
 }
 
-void put_free_mem_obj(mem)
-     void *mem;
+char *get_free_4k_page()
 {
-    if (full_stack(&mem_obj_pool.free_page_stack))
-	mem_obj_pool.total_pages_allocated--;
-    mem_obj_pool.n_pages_in_use--;
-    push(&mem_obj_pool.free_page_stack, mem);
+    return get_free_thing(&sm_stats);
 }
 
+char *get_free_8k_page()
+{
+    return get_free_thing(&disk_stats);
+}
 
-/* PBD 12/95: Memory allocator routines for saving and reallocating fixed 
- * size blocks rather than mallocing and freeing them */
-char *get_free_4k_page()
+static void put_free_thing(thing, p)
+	stmem_stats *thing;
+	void *p;
 {
-    char *page = NULL;
-    if (!empty_stack(&sm_stats.free_page_stack)) {
-	page = pop(&sm_stats.free_page_stack);
+    thing->n_pages_in_use--;
+    if (thing->total_pages_allocated > thing->max_pages) {
+	xfree(p);
+	thing->total_pages_allocated--;
+    } else if (full_stack(&thing->free_page_stack)) {
+	xfree(p);
+	thing->total_pages_allocated--;
     } else {
-#if USE_MEMALIGN
-	page = memalign(SM_PAGE_SIZE, SM_PAGE_SIZE);
-	if (!page)
-	    fatal_dump(NULL);
-#else
-	page = xmalloc(SM_PAGE_SIZE);
-#endif
-	sm_stats.total_pages_allocated++;
+        push(&thing->free_page_stack, p);
     }
-    sm_stats.n_pages_in_use++;
-    if (page == NULL)
-	fatal_dump("get_free_4k_page: Null page pointer?");
-    return (page);
 }
 
-void put_free_4k_page(page)
-     char *page;
+void put_free_request_t(req)
+     void *req;
 {
-#if USE_MEMALIGN
-    if ((int) page % SM_PAGE_SIZE)
-	fatal_dump("Someone tossed a string into the 4k page pool");
-#endif
-    if (full_stack(&sm_stats.free_page_stack))
-	sm_stats.total_pages_allocated--;
-    sm_stats.n_pages_in_use--;
-    push(&sm_stats.free_page_stack, page);
+    put_free_thing(&request_pool, req);
 }
 
-char *get_free_8k_page()
+void put_free_mem_obj(mem)
+     void *mem;
 {
-    char *page = NULL;
-    if (!empty_stack(&disk_stats.free_page_stack)) {
-	page = pop(&disk_stats.free_page_stack);
-    } else {
-#if USE_MEMALIGN
-	page = memalign(DISK_PAGE_SIZE, DISK_PAGE_SIZE);
-	if (!page)
-	    fatal_dump(NULL);
-#else
-	page = xmalloc(DISK_PAGE_SIZE);
-#endif
-	disk_stats.total_pages_allocated++;
-    }
-    disk_stats.n_pages_in_use++;
-    if (page == NULL)
-	fatal_dump("get_free_8k_page: Null page pointer?");
-    return (page);
+    put_free_thing(&mem_obj_pool, mem);
+}
+
+void put_free_4k_page(page)
+     char *page;
+{
+    put_free_thing(&sm_stats, page);
 }
 
 void put_free_8k_page(page)
      char *page;
 {
-#if USE_MEMALIGN
-    if ((int) page % DISK_PAGE_SIZE)
-	fatal_dump("Someone tossed a string into the 8k page pool");
-#endif
-    if (full_stack(&disk_stats.free_page_stack))
-	disk_stats.total_pages_allocated--;
-    disk_stats.n_pages_in_use--;
-    push(&disk_stats.free_page_stack, page);
+    put_free_thing(&disk_stats, page);
 }
 
 void stmemInit()
