	    continue;
	if (BIT_TEST(e->flag, KEY_PRIVATE))
	    continue;
	storeSwapFullPath(e->swap_file_number, swapfilename);
	x = fprintf(fp, "%08x %08x %08x %08x %9d %s\n",
	    (int) e->swap_file_number,
	    (int) e->timestamp,
