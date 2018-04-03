 	unsigned size = nr * sizeof(uint32_t);
 	void *p;
 	if (!info->pool_count || info->free + size > info->end) {
+		if (size > POOL_SIZE)
+			die("BUG: pool size too small for %d in paint_alloc()",
+			    size);
 		info->pool_count++;
 		REALLOC_ARRAY(info->pools, info->pool_count);
 		info->free = xmalloc(POOL_SIZE);