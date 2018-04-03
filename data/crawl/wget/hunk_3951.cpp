 #include <string.h>
 
 int
-print_hash_table_mapper (const void *key, void *value, void *count)
+print_hash_table_mapper (void *key, void *value, void *count)
 {
   ++*(int *)count;
   printf ("%s: %s\n", (const char *)key, (char *)value);
