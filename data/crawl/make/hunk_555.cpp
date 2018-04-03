 void
 strcache_print_stats (const char *prefix)
 {
-  int numbuffs = 0, numstrs = 0;
-  int totsize = 0, avgsize, maxsize = 0, minsize = bufsize;
-  int totfree = 0, avgfree, maxfree = 0, minfree = bufsize;
-  int lastused = 0, lastfree = 0;
+  const struct strcache *sp;
+  unsigned long numbuffs = 0, fullbuffs = 0;
+  unsigned long totfree = 0, maxfree = 0, minfree = bufsize;
 
-  if (strcache)
+  if (! strcache)
     {
-      const struct strcache *sp;
+      printf(_("\n%s No strcache buffers\n"), prefix);
+      return;
+    }
 
-      /* Count the first buffer separately since it's not full.  */
-      lastused = strcache->end - strcache->buffer;
-      lastfree = strcache->bytesfree;
+  /* Count the first buffer separately since it's not full.  */
+  for (sp = strcache->next; sp != NULL; sp = sp->next)
+    {
+      sc_buflen_t bf = sp->bytesfree;
 
-      for (sp = strcache->next; sp != NULL; sp = sp->next)
-        {
-          int bf = sp->bytesfree;
-          int sz = sp->end - sp->buffer;
+      totfree += bf;
+      maxfree = (bf > maxfree ? bf : maxfree);
+      minfree = (bf < minfree ? bf : minfree);
 
-          ++numbuffs;
-          numstrs += sp->count;
+      ++numbuffs;
+    }
+  for (sp = fullcache; sp != NULL; sp = sp->next)
+    {
+      sc_buflen_t bf = sp->bytesfree;
 
-          totsize += sz;
-          maxsize = (sz > maxsize ? sz : maxsize);
-          minsize = (sz < minsize ? sz : minsize);
+      totfree += bf;
+      maxfree = (bf > maxfree ? bf : maxfree);
+      minfree = (bf < minfree ? bf : minfree);
 
-          totfree += bf;
-          maxfree = (bf > maxfree ? bf : maxfree);
-          minfree = (bf < minfree ? bf : minfree);
-        }
+      ++numbuffs;
+      ++fullbuffs;
     }
 
-  avgsize = numbuffs ? (int)(totsize / numbuffs) : 0;
-  avgfree = numbuffs ? (int)(totfree / numbuffs) : 0;
+  /* Make sure we didn't lose any buffers.  */
+  assert (total_buffers == numbuffs + 1);
+
+  printf (_("\n%s strcache buffers: %lu (%lu) / strings = %lu / storage = %lu B / avg = %lu B\n"),
+          prefix, numbuffs + 1, fullbuffs, total_strings, total_size,
+          (total_size / total_strings));
 
-  printf (_("\n%s # of strings in strcache: %d / lookups = %lu / hits = %lu\n"),
-          prefix, numstrs, total_adds, (total_adds - numstrs));
-  printf (_("%s # of strcache buffers: %d (* %d B/buffer = %d B)\n"),
-          prefix, (numbuffs + 1), bufsize, ((numbuffs + 1) * bufsize));
-  printf (_("%s strcache used: total = %d (%d) / max = %d / min = %d / avg = %d\n"),
-          prefix, totsize, lastused, maxsize, minsize, avgsize);
-  printf (_("%s strcache free: total = %d (%d) / max = %d / min = %d / avg = %d\n"),
-          prefix, totfree, lastfree, maxfree, minfree, avgfree);
+  printf (_("%s current buf: size = %hu B / used = %hu B / count = %hu / avg = %hu B\n"),
+          prefix, bufsize, strcache->end, strcache->count,
+          (strcache->end / strcache->count));
+
+  if (numbuffs)
+    {
+      unsigned long sz = total_size - bufsize;
+      unsigned long cnt = total_strings - strcache->count;
+      sc_buflen_t avgfree = totfree / numbuffs;
+
+      printf (_("%s other used: total = %lu B / count = %lu / avg = %lu B\n"),
+              prefix, sz, cnt, sz / cnt);
+
+      printf (_("%s other free: total = %lu B / max = %lu B / min = %lu B / avg = %hu B\n"),
+              prefix, totfree, maxfree, minfree, avgfree);
+    }
 
-  fputs (_("\n# strcache hash-table stats:\n# "), stdout);
+  printf (_("\n%s strcache performance: lookups = %lu / hit rate = %lu%%\n"),
+          prefix, total_adds, (long unsigned)(100.0 * (total_adds - total_strings) / total_adds));
+  fputs (_("# hash-table stats:\n# "), stdout);
   hash_print_stats (&strings, stdout);
 }
