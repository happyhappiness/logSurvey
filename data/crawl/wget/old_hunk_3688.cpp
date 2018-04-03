static void
grow_hash_table (struct hash_table *ht)
{
  int i;
  struct mapping *old_mappings = ht->mappings;
  int old_count = ht->count;	/* for assert() below */
  int old_size = ht->size;

  /* To minimize the number of regrowth, we'd like to resize the hash
     table exponentially.  Normally, this would be done by doubling
     ht->size (and round it to next prime) on each regrow:

         ht->size = prime_size (ht->size * 2);

     But it is possible that the table has large fullness because of
     the many deleted entries.  If that is the case, we don't want to
     blindly grow the table; we just want to rehash it.  For that
     reason, we use ht->count as the relevant parameter.  MAX is used
     only because we don't want to actually shrink the table.  (But
     maybe that's wrong.)  */

  int needed_size = prime_size (ht->count * 3);
  ht->size = MAX (old_size, needed_size);

#if 0
  printf ("growing from %d to %d\n", old_size, ht->size);
#endif

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
  xfree (old_mappings);
}
