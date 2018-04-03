	    continue;
	if (BIT_TEST(e->flag, KEY_PRIVATE))
	    continue;
	x = fprintf(fp, "%08x %08x %08x %08x %9d %s\n",
	    (int) e->swap_file_number,
	    (int) e->timestamp,
	    (int) e->expires,
	    (int) e->lastmod,
	    e->object_len,
	    e->url);
	if (x < 0) {
	    debug(50, 0, "storeWriteCleanLog: %s: %s\n", tmp_filename, xstrerror());
	    debug(20, 0, "storeWriteCleanLog: Current swap logfile not replaced.\n");
	    fclose(fp);
	    safeunlink(tmp_filename, 0);
	    return 0;
	}
