	unsigned size = nr * sizeof(uint32_t);
	void *p;
	if (!info->pool_count || info->free + size > info->end) {
		info->pool_count++;
		REALLOC_ARRAY(info->pools, info->pool_count);
		info->free = xmalloc(POOL_SIZE);