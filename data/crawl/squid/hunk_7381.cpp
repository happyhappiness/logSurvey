 	    continue;
 	if (BIT_TEST(e->flag, KEY_PRIVATE))
 	    continue;
-	x = fprintf(fp, "%08x %08x %08x %08x %9d %s\n",
+	sprintf(line, "%08x %08x %08x %08x %9d %s\n",
 	    (int) e->swap_file_number,
 	    (int) e->timestamp,
 	    (int) e->expires,
 	    (int) e->lastmod,
 	    e->object_len,
 	    e->url);
-	if (x < 0) {
+	if (write(fd, line, strlen(line)) < 0) {
 	    debug(50, 0, "storeWriteCleanLog: %s: %s\n", tmp_filename, xstrerror());
 	    debug(20, 0, "storeWriteCleanLog: Current swap logfile not replaced.\n");
-	    fclose(fp);
+	    close(fd);
 	    safeunlink(tmp_filename, 0);
 	    return 0;
 	}
