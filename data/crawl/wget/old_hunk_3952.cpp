      if (len <= 1)
	continue;
      line[--len] = '\0';
      hash_table_put (ht, strdup (line), "here I am!");
      if (len % 2)
	hash_table_remove (ht, line);
    }
  print_hash (ht);
#if 0
  printf ("%d %d %d\n", ht->count, ht->fullness, ht->size);
#endif
  return 0;
