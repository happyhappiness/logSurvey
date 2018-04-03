   struct mapping *mp, *mappings;
   int newsize;
 
-  newsize = prime_size (ht->size * 2);
+  newsize = prime_size (ht->size * 2, &ht->prime_offset);
 #if 0
-  printf ("growing from %d to %d\n", ht->size, newsize);
+  printf ("growing from %d to %d; fullness %.2f%% to %.2f%%\n",
+	  ht->size, newsize,
+	  (double)100 * ht->count / ht->size,
+	  (double)100 * ht->count / newsize);
 #endif
 
   ht->size = newsize;
