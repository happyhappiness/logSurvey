static void
grow_hash_table (struct hash_table *ht)
{
  struct mapping *old_mappings = ht->mappings;
  struct mapping *old_end      = ht->mappings + ht->size;
  struct mapping *mp;
  int old_count = ht->count;	/* for assert() below */

#if 0
  printf ("growing from %d to %d\n", ht->size, prime_size (ht->size * 2));
#endif

  ht->size = prime_size (ht->size * 2);

  ht->mappings = xmalloc (ht->size * sizeof (struct mapping));
  memset (ht->mappings, '\0', ht->size * sizeof (struct mapping));

  /* Need to reset this; hash_table_put will reinitialize it.  */
  ht->count    = 0;

  for (mp = old_mappings; mp < old_end; mp++)
    if (!EMPTY_MAPPING_P (mp))
      hash_table_put (ht, mp->key, mp->value);

  assert (ht->count == old_count);
  xfree (old_mappings);
}
