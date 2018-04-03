    {
      fprintf (stderr, _("can't allocate %lu bytes for hash table: memory exhausted"),
	       ht->ht_size * (unsigned long) sizeof (struct token *));
      exit (MAKE_TROUBLE);
    }

  ht->ht_capacity = ht->ht_size - (ht->ht_size / 16); /* 93.75% loading factor */
