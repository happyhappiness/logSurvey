 
 #if USE_MEMALIGN
     if ((int) page % DISK_PAGE_SIZE) {
-	debug(0, "Someone tossed a string into the 8k page pool\n");
+	debug(0, 0, "Someone tossed a string into the 8k page pool\n");
 	fatal_dump(NULL);
     }
 #endif
 
     if (full_stack(&disk_stats.free_page_stack)) {
 	disk_stats.total_pages_allocated--;
 	if (!stack_overflow_warning_toggle) {
-	    debug(0, "Stack of free disk pages overflowed.  Resize it?");
+	    debug(0, 0, "Stack of free disk pages overflowed.  Resize it?");
 	    stack_overflow_warning_toggle++;
 	}
     }
