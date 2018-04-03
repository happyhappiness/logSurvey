       if (len <= 1)
 	continue;
       line[--len] = '\0';
-      hash_table_put (ht, strdup (line), "here I am!");
-      if (len % 2)
-	hash_table_remove (ht, line);
+      if (!hash_table_exists (ht, line))
+	hash_table_put (ht, strdup (line), "here I am!");
+#if 1
+      if (len % 3)
+	{
+	  char *line_copy;
+	  if (hash_table_get_pair (ht, line, &line_copy, NULL))
+	    {
+	      hash_table_remove (ht, line);
+	      free (line_copy);
+	    }
+	}
+#endif
     }
-  print_hash (ht);
 #if 0
+  print_hash (ht);
+#endif
+#if 1
   printf ("%d %d %d\n", ht->count, ht->fullness, ht->size);
 #endif
   return 0;
