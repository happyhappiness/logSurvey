 	if (e->object_len <= 0)
 	    continue;
 	storeSwapFullPath(e->swap_file_number, swapfilename);
-	x = fprintf(fp, "%s %s %d %d %d\n",
-	    swapfilename, e->url, (int) e->expires, (int) e->timestamp,
-	    e->object_len);
+	x = fprintf(fp, "%08x %08x %08x %08x %9d %s\n",
+	    (int) e->swap_file_number,
+	    (int) e->timestamp,
+	    (int) e->expires,
+	    (int) e->lastmod,
+	    e->object_len,
+	    e->url);
 	if (x < 0) {
 	    debug(20, 0, "storeWriteCleanLog: %s: %s", tmp_filename, xstrerror());
 	    debug(20, 0, "storeWriteCleanLog: Current swap logfile not replaced.\n");