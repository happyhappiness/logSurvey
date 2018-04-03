      only because we don't want to actually shrink the table.  (But
      maybe that's wrong.)  */
 
-  int needed_size = prime_size (ht->count * 2);
+  int needed_size = prime_size (ht->count * 3);
   ht->size = MAX (old_size, needed_size);
 
-  ht->pairs = xmalloc (ht->size * sizeof (struct ht_pair));
-  memset (ht->pairs, '\0', ht->size * sizeof (struct ht_pair));
+  printf ("growing from %d to %d\n", old_size, ht->size);
+
+  ht->mappings = xmalloc (ht->size * sizeof (struct mapping));
+  memset (ht->mappings, '\0', ht->size * sizeof (struct mapping));
 
   /* Need to reset these two; hash_table_put will reinitialize them.  */
   ht->fullness = 0;
   ht->count    = 0;
   for (i = 0; i < old_size; i++)
     {
-      struct ht_pair *the_pair = old_pairs + i;
-      if (!EMPTY_ENTRY_P (the_pair->key)
-	  && !DELETED_ENTRY_P (the_pair->key))
-	hash_table_put (ht, the_pair->key, the_pair->value);
+      struct mapping *mp = old_mappings + i;
+      void *mp_key = mp->key;
+
+      if (!EMPTY_ENTRY_P (mp_key)
+	  && !DELETED_ENTRY_P (mp_key))
+	hash_table_put (ht, mp_key, mp->value);
     }
   assert (ht->count == old_count);
-  free (old_pairs);
+  free (old_mappings);
 }
 
 /* Put VALUE in the hash table HT under the key KEY.  This regrows the
