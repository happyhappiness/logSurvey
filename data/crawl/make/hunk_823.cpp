 }
 
 void
-hash_print_stats (ht, out_FILE)
-     struct hash_table *ht;
-     FILE *out_FILE;
+hash_print_stats (struct hash_table *ht, FILE *out_FILE)
 {
   /* GKM FIXME: honor NO_FLOAT */
   fprintf (out_FILE, _("Load=%ld/%ld=%.0f%%, "), ht->ht_fill, ht->ht_size,
