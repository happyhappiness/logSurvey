void
hash_print_stats (struct hash_table *ht, FILE *out_FILE)
{
  fprintf (out_FILE, _("Load=%lu/%lu=%.0f%%, "), ht->ht_fill, ht->ht_size,
	   100.0 * (double) ht->ht_fill / (double) ht->ht_size);
  fprintf (out_FILE, _("Rehash=%u, "), ht->ht_rehashes);