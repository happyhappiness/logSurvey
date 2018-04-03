#include <stdio.h>
#include <string.h>

void
print_hash (struct hash_table *sht)
{
  hash_table_iterator iter;
  int count = 0;

  for (hash_table_iterate (sht, &iter); hash_table_iter_next (&iter);
       ++count)
    printf ("%s: %s\n", iter.key, iter.value);
  assert (count == sht->count);
}

int
