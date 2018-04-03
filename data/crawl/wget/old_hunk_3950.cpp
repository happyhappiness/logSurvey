     only because we don't want to actually shrink the table.  (But
     maybe that's wrong.)  */

  int needed_size = prime_size (ht->count * 2);
  ht->size = MAX (old_size, needed_size);

  ht->pairs = xmalloc (ht->size * sizeof (struct ht_pair));
  memset (ht->pairs, '\0', ht->size * sizeof (struct ht_pair));

  /* Need to reset these two; hash_table_put will reinitialize them.  */
  ht->fullness = 0;
  ht->count    = 0;
  for (i = 0; i < old_size; i++)
    {
      struct ht_pair *the_pair = old_pairs + i;
      if (!EMPTY_ENTRY_P (the_pair->key)
	  && !DELETED_ENTRY_P (the_pair->key))
	hash_table_put (ht, the_pair->key, the_pair->value);
    }
  assert (ht->count == old_count);
  free (old_pairs);
}

/* Put VALUE in the hash table HT under the key KEY.  This regrows the
