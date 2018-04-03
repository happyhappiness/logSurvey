  struct mapping *mp, *mappings;
  int newsize;

  newsize = prime_size (ht->size * 2);
#if 0
  printf ("growing from %d to %d\n", ht->size, newsize);
#endif

  ht->size = newsize;
