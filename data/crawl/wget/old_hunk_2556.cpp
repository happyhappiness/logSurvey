  newsize = prime_size (ht->size * HASH_RESIZE_FACTOR, &ht->prime_offset);
#if 0
  printf ("growing from %d to %d; fullness %.2f%% to %.2f%%\n",
	  ht->size, newsize,
	  100.0 * ht->count / ht->size,
	  100.0 * ht->count / newsize);
#endif

  ht->size = newsize;
