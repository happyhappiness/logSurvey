void
strcache_print_stats (const char *prefix)
{
  const struct strcache *sp;
  unsigned long numbuffs = 0, fullbuffs = 0;
  unsigned long totfree = 0, maxfree = 0, minfree = bufsize;

  if (! strcache)
    {
      printf(_("\n%s No strcache buffers\n"), prefix);
      return;
    }

  /* Count the first buffer separately since it's not full.  */
  for (sp = strcache->next; sp != NULL; sp = sp->next)
    {
      sc_buflen_t bf = sp->bytesfree;

      totfree += bf;
      maxfree = (bf > maxfree ? bf : maxfree);
      minfree = (bf < minfree ? bf : minfree);

      ++numbuffs;
    }
  for (sp = fullcache; sp != NULL; sp = sp->next)
    {
      sc_buflen_t bf = sp->bytesfree;

      totfree += bf;
      maxfree = (bf > maxfree ? bf : maxfree);
      minfree = (bf < minfree ? bf : minfree);

      ++numbuffs;
      ++fullbuffs;
    }

  /* Make sure we didn't lose any buffers.  */
  assert (total_buffers == numbuffs + 1);

  printf (_("\n%s strcache buffers: %lu (%lu) / strings = %lu / storage = %lu B / avg = %lu B\n"),
          prefix, numbuffs + 1, fullbuffs, total_strings, total_size,
          (total_size / total_strings));

  printf (_("%s current buf: size = %hu B / used = %hu B / count = %hu / avg = %hu B\n"),
          prefix, bufsize, strcache->end, strcache->count,
          (strcache->end / strcache->count));

  if (numbuffs)
    {
      unsigned long sz = total_size - bufsize;
      unsigned long cnt = total_strings - strcache->count;
      sc_buflen_t avgfree = totfree / numbuffs;

      printf (_("%s other used: total = %lu B / count = %lu / avg = %lu B\n"),
              prefix, sz, cnt, sz / cnt);

      printf (_("%s other free: total = %lu B / max = %lu B / min = %lu B / avg = %hu B\n"),
              prefix, totfree, maxfree, minfree, avgfree);
    }

  printf (_("\n%s strcache performance: lookups = %lu / hit rate = %lu%%\n"),
          prefix, total_adds, (long unsigned)(100.0 * (total_adds - total_strings) / total_adds));
  fputs (_("# hash-table stats:\n# "), stdout);
  hash_print_stats (&strings, stdout);
}
