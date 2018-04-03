int
main(int argc, char *argv[])
{
    CacheIndex *they = NULL;
    FileIterator **fis = NULL;
    const int fi_count = argc-1;
    int i, j;

    if (argc < 3)
	return usage(argv[0]);

    fis = xcalloc(fi_count, sizeof(FileIterator *));
    /* init iterators with files */
    fis[0] = fileIteratorCreate(argv[1], accessLogReader);
    for (i = 2; i < argc; ++i) {
	fis[i-1] = fileIteratorCreate(argv[i], swapStateReader);
    }
    /* read prefix to get start-up contents of peer cache */
    for (i = 1; i < fi_count; ++i) {
	fileIteratorScan(fis[i], swapStatePrefixScanner);
    }
    /* digest peer cache content */
    /* ...resetDigest() */
    /* iterate */
    cur_time = -1;
    for (i = 0; i < fi_count; ++i) {
	int next_i = -1;
	time_t next_time = -1;
	for (j = 0; j < fi_count; ++j) {
	    if (fis[j].inner_time > next_time) 
	}
    }
    /* cleaning */
    for (int i = 0; i < argc-1; ++i) {
	fileIteratorDestroy(fis[i]);
    }
    xfree(fis);

    return 0;
}