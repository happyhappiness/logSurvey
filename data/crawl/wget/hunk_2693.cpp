 #include <stdio.h>
 #include <string.h>
 
-int
-print_hash_table_mapper (void *key, void *value, void *count)
-{
-  ++*(int *)count;
-  printf ("%s: %s\n", (const char *)key, (char *)value);
-  return 0;
-}
-
 void
 print_hash (struct hash_table *sht)
 {
-  int debug_count = 0;
-  hash_table_map (sht, print_hash_table_mapper, &debug_count);
-  assert (debug_count == sht->count);
+  hash_table_iterator iter;
+  int count = 0;
+
+  for (hash_table_iterate (sht, &iter); hash_table_iter_next (&iter);
+       ++count)
+    printf ("%s: %s\n", iter.key, iter.value);
+  assert (count == sht->count);
 }
 
 int
