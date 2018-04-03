     only because we don't want to actually shrink the table.  (But
     maybe that's wrong.)  */

  int needed_size = prime_size (ht->count * 3);
  ht->size = MAX (old_size, needed_size);

  printf ("growing from %d to %d\n", old_size, ht->size);

  ht->mappings = xmalloc (ht->size * sizeof (struct mapping));
  memset (ht->mappings, '\0', ht->size * sizeof (struct mapping));

  /* Need to reset these two; hash_table_put will reinitialize them.  */
  ht->fullness = 0;
  ht->count    = 0;
  for (i = 0; i < old_size; i++)
    {
      struct mapping *mp = old_mappings + i;
      void *mp_key = mp->key;

      if (!EMPTY_ENTRY_P (mp_key)
	  && !DELETED_ENTRY_P (mp_key))
	hash_table_put (ht, mp_key, mp->value);
    }
  assert (ht->count == old_count);
  free (old_mappings);
}

/* Put VALUE in the hash table HT under the key KEY.  This regrows the
