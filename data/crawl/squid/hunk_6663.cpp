     assert(k != NULL);
     /* Add to the given hash table 'hid' */
     new = calloc(1, sizeof(hash_link));
+    if (!new) {
+	fprintf(stderr,"calloc failed!\n");
+	print_stats();
+	exit(1);
+    }
     new->item = item;
     new->key = (char *) k;
     i = hid->hash(k, hid->size);
