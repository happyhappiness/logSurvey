hash_print_stats (struct hash_table *ht, FILE *out_FILE)
{
  /* GKM FIXME: honor NO_FLOAT */
  fprintf (out_FILE, _("Load=%lu/%lu=%.0f%%, "), ht->ht_fill, ht->ht_size,
	   100.0 * (double) ht->ht_fill / (double) ht->ht_size);
  fprintf (out_FILE, _("Rehash=%u, "), ht->ht_rehashes);
  fprintf (out_FILE, _("Collisions=%lu/%lu=%.0f%%"), ht->ht_collisions, ht->ht_lookups,
	   (ht->ht_lookups
	    ? (100.0 * (double) ht->ht_collisions / (double) ht->ht_lookups)
	    : 0));
