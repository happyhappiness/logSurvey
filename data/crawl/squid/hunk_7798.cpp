 	stat_init(&CacheInfo, getAccessLogFile());
 	storeInit();
 	stmemInit();
-	writePidFile();
 
+	if (getEffectiveUser()) {
+	    /* we were probably started as root, so cd to a swap
+	     * directory in case we dump core */
+	    if (chdir(swappath(0)) < 0) {
+		debug(1, 0, "%s: %s\n", swappath(0), xstrerror());
+		fatal_dump("Cannot cd to swap directory?");
+	    }
+	}
 	/* after this point we want to see the mallinfo() output */
 	do_mallinfo = 1;
     }
