 	debug(50, 1, "%s: %s\n", swaplog_path, xstrerror());
 	fatal("storeDirCloseTmpSwapLog: Failed to open swap log.");
     }
+    safe_free(swaplog_path);
+    safe_free(new_path);
     SD->swaplog_fd = fd;
+    debug(20, 3, "Cache Dir #%d log opened on FD %d\n", i, fd);
 }
 
 void