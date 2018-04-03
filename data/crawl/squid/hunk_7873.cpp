 	disk_stats.total_pages_allocated++;
     }
     disk_stats.n_pages_in_use++;
-    if (page == NULL) {
-	debug(19, 0, "Null page pointer?");
-	fatal_dump(NULL);
-    }
+    debug(19, 5, "get_free_8k_page: Giving out %p, count=%d  %s:%d\n",
+	page, disk_stats.n_pages_in_use, file, line);
+    if (page == NULL)
+	fatal_dump("get_free_8k_page: Null page pointer?");
     return (page);
 }
 
-void put_free_8k_page(page)
+void put_free_8k_page(page, file, line)
      char *page;
+     char *file;
+     int line;
 {
     static stack_overflow_warning_toggle;
 
 #if USE_MEMALIGN
-    if ((int) page % DISK_PAGE_SIZE) {
-	debug(19, 0, "Someone tossed a string into the 8k page pool\n");
-	fatal_dump(NULL);
-    }
+    if ((int) page % DISK_PAGE_SIZE)
+	fatal_dump("Someone tossed a string into the 8k page pool");
 #endif
 
     if (full_stack(&disk_stats.free_page_stack)) {
