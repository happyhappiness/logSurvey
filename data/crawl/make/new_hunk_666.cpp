  int numbuffs = 0, numstrs = 0;
  int totsize = 0, avgsize, maxsize = 0, minsize = bufsize;
  int totfree = 0, avgfree, maxfree = 0, minfree = bufsize;
  int lastused = 0, lastfree = 0;

  if (strcache)
    {
      const struct strcache *sp;

      /* Count the first buffer separately since it's not full.  */
      lastused = strcache->end - strcache->buffer;
      lastfree = strcache->bytesfree;

      for (sp = strcache->next; sp != NULL; sp = sp->next)
        {
          int bf = sp->bytesfree;
          int sz = sp->end - sp->buffer;

          ++numbuffs;
          numstrs += sp->count;

          totsize += sz;
          maxsize = (sz > maxsize ? sz : maxsize);
          minsize = (sz < minsize ? sz : minsize);

          totfree += bf;
          maxfree = (bf > maxfree ? bf : maxfree);
          minfree = (bf < minfree ? bf : minfree);
        }
    }

  avgsize = numbuffs ? (int)(totsize / numbuffs) : 0;
  avgfree = numbuffs ? (int)(totfree / numbuffs) : 0;

  printf (_("\n%s # of strings in strcache: %d / lookups = %lu / hits = %lu\n"),
          prefix, numstrs, total_adds, (total_adds - numstrs));
  printf (_("%s # of strcache buffers: %d (* %d B/buffer = %d B)\n"),
          prefix, (numbuffs + 1), bufsize, ((numbuffs + 1) * bufsize));
  printf (_("%s strcache used: total = %d (%d) / max = %d / min = %d / avg = %d\n"),
          prefix, totsize, lastused, maxsize, minsize, avgsize);
  printf (_("%s strcache free: total = %d (%d) / max = %d / min = %d / avg = %d\n"),
          prefix, totfree, lastfree, maxfree, minfree, avgfree);

  fputs (_("\n# strcache hash-table stats:\n# "), stdout);
  hash_print_stats (&strings, stdout);
}
