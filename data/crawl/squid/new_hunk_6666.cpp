	printf("page faults           : %d\n", (int)myusage.ru_majflt);
}

void
size2id(size_t sz,memitem *mi)
{
	int j;
	for(j=0;j<size2id_len;j++)
		if (size2id_array[0][j]==sz) {
			size2id_array[1][j]++;
			mi->id=j;
			return;
		}

	/* we have a different size, so we need a new pool */

	mi->id=size2id_len;
#ifdef WITH_LIB
	mi->pool = memPoolCreate(size2id_len, sz);
#endif
	size2id_len++;
	if (size2id_len==1) {
		size2id_alloc=100;
