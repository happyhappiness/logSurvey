	printf("page faults           : %d\n", (int)myusage.ru_majflt);
}

int
size2id(size_t sz)
{
	int j;
	for(j=0;j<size2id_len;j++)
		if (size2id_array[0][j]==sz) {
			size2id_array[1][j]++;
			return j;
		}
	size2id_len++;
	if (size2id_len==1) {
		size2id_alloc=100;
