     if (storelog_fd < 0)
 	debug(20, 1) ("Store logging disabled\n");
     if (storeVerifyCacheDirs() < 0) {
-        xstrncpy(tmp_error_buf,
-            "\tFailed to verify one of the swap directories, Check cache.log\n"
-            "\tfor details.  Run 'squid -z' to create swap directories\n"
-            "\tif needed, or if running Squid for the first time.",
-            ERROR_BUF_SZ); 
-        fatal(tmp_error_buf);
-    }   
+	xstrncpy(tmp_error_buf,
+	    "\tFailed to verify one of the swap directories, Check cache.log\n"
+	    "\tfor details.  Run 'squid -z' to create swap directories\n"
+	    "\tif needed, or if running Squid for the first time.",
+	    ERROR_BUF_SZ);
+	fatal(tmp_error_buf);
+    }
     if (opt_convert) {
-    	storeDirOpenSwapLogs();
+	storeDirOpenSwapLogs();
 	storeConvert();
-	debug(0,0)("DONE Converting. Welcome to %s!\n", version_string);
-        storeDirCloseSwapLogs();
+	debug(0, 0) ("DONE Converting. Welcome to %s!\n", version_string);
+	storeDirCloseSwapLogs();
 	exit(0);
     }
-
     storeStartRebuildFromDisk();
     all_list.head = all_list.tail = NULL;
     inmem_list.head = inmem_list.tail = NULL;
