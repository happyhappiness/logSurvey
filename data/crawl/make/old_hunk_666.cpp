  int numbuffs = 0, numstrs = 0;
  int totsize = 0, avgsize, maxsize = 0, minsize = bufsize;
  int totfree = 0, avgfree, maxfree = 0, minfree = bufsize;
  const struct strcache *sp;

  for (sp = strcache; sp != NULL; sp = sp->next)
    {
      int bf = sp->bytesfree;
      int sz = (sp->end - sp->buffer) + bf;

      ++numbuffs;
      numstrs += sp->count;

      totsize += sz;
      maxsize = (sz > maxsize ? sz : maxsize);
      minsize = (sz < minsize ? sz : minsize);

      totfree += bf;
      maxfree = (bf > maxfree ? bf : maxfree);
      minfree = (bf < minfree ? bf : minfree);
    }

  avgsize = numbuffs ? (int)(totsize / numbuffs) : 0;
  avgfree = numbuffs ? (int)(totfree / numbuffs) : 0;

  printf (_("\n%s # of strings in strcache: %d\n"), prefix, numstrs);
  printf (_("%s # of strcache buffers: %d\n"), prefix, numbuffs);
  printf (_("%s strcache size: total = %d / max = %d / min = %d / avg = %d\n"),
          prefix, totsize, maxsize, minsize, avgsize);
  printf (_("%s strcache free: total = %d / max = %d / min = %d / avg = %d\n"),
          prefix, totfree, maxfree, minfree, avgfree);
}
