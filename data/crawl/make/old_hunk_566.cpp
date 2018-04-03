  ht->ht_vec = (void**) CALLOC (struct token *, ht->ht_size);
  if (ht->ht_vec == 0)
    {
      fprintf (stderr, _("can't allocate %ld bytes for hash table: memory exhausted"),
	       ht->ht_size * sizeof(struct token *));
      exit (1);
    }

