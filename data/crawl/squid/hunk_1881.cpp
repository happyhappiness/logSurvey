 
     if (fp == NULL) {
         debugs(50, DBG_CRITICAL, "ERROR: while opening " << swaplog_path << ": " << xstrerror());
-        fatal("Failed to open swap log for reading");
+        fatalf("Failed to open swap log for reading %s", swaplog_path);
     }
 
     memset(&clean_sb, '\0', sizeof(struct stat));