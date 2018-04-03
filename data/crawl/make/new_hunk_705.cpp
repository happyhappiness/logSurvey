  avgsize = numbuffs ? (int)(totsize / numbuffs) : 0;
  avgfree = numbuffs ? (int)(totfree / numbuffs) : 0;

  printf (_("\n%s # of strings in strcache: %d\n"), prefix, numstrs);
  printf (_("%s # of strcache buffers: %d\n"), prefix, numbuffs);
  printf (_("%s strcache size: total = %d / max = %d / min = %d / avg = %d\n"),
          prefix, totsize, maxsize, minsize, avgsize);
  printf (_("%s strcache free: total = %d / max = %d / min = %d / avg = %d\n"),
          prefix, totfree, maxfree, minfree, avgfree);
}
