 {
   struct mapping *old_mappings = ht->mappings;
   struct mapping *old_end      = ht->mappings + ht->size;
-  struct mapping *mp;
-  int old_count = ht->count;	/* for assert() below */
+  struct mapping *mp, *mappings;
+  int newsize;
 
+  newsize = prime_size (ht->size * 2);
 #if 0
-  printf ("growing from %d to %d\n", ht->size, prime_size (ht->size * 2));
+  printf ("growing from %d to %d\n", ht->size, newsize);
 #endif
 
-  ht->size = prime_size (ht->size * 2);
-
-  ht->mappings = xmalloc (ht->size * sizeof (struct mapping));
-  memset (ht->mappings, '\0', ht->size * sizeof (struct mapping));
+  ht->size = newsize;
+  ht->resize_threshold = newsize * 3 / 4;
 
-  /* Need to reset this; hash_table_put will reinitialize it.  */
-  ht->count    = 0;
+  mappings = xmalloc (ht->size * sizeof (struct mapping));
+  memset (mappings, '\0', ht->size * sizeof (struct mapping));
+  ht->mappings = mappings;
 
   for (mp = old_mappings; mp < old_end; mp++)
     if (!EMPTY_MAPPING_P (mp))
-      hash_table_put (ht, mp->key, mp->value);
+      {
+	struct mapping *new_mp = mappings + HASH_POSITION (ht, mp->key);
+	/* We don't need to call test function and worry about
+	   collisions because all the keys come from the hash table
+	   and are therefore guaranteed to be unique.  */
+	LOOP_NON_EMPTY (new_mp, mappings, newsize)
+	  ;
+	*new_mp = *mp;
+      }
 
-  assert (ht->count == old_count);
   xfree (old_mappings);
 }
 
