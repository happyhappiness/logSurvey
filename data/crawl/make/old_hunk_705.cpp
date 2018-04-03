  avgsize = numbuffs ? (int)(totsize / numbuffs) : 0;
  avgfree = numbuffs ? (int)(totfree / numbuffs) : 0;

  printf ("\n%s # of strings in strcache: %d\n", prefix, numstrs);
  printf ("%s # of strcache buffers: %d\n", prefix, numbuffs);
  printf ("%s strcache size: total = %d / max = %d / min = %d / avg = %d\n",
          prefix, totsize, maxsize, minsize, avgsize);
  printf ("%s strcache free: total = %d / max = %d / min = %d / avg = %d\n",
          prefix, totfree, maxfree, minfree, avgfree);
}
